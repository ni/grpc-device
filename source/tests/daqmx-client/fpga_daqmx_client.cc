//---------------------------------------------------------------------
//---------------------------------------------------------------------
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <src/core/lib/iomgr/timer_manager.h>
#include <src/core/lib/iomgr/executor.h>
#include <data_moniker.grpc.pb.h>
#include <nidaqmx_client.h>
#include <sideband_data.h>
#include <sideband_grpc.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <chrono>
#include <thread>
#ifndef _WIN32
#include <sched.h>
#include <sys/syscall.h>
#endif
#include <sys/types.h>

#include <NiFpga.h>
#include <NIDAQmx.h>

//---------------------------------------------------------------------
//---------------------------------------------------------------------
using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using namespace std;
using namespace nidaqmx_grpc;
using namespace nidaqmx_grpc::experimental::client;

//---------------------------------------------------------------------
//---------------------------------------------------------------------
enum DaqTestToRun
{
    // There are some unused cases here. But that is just to match test case numbers for fpga_client
    DAQ_INVALID = 0,
    DAQ_READ,
    DAQ_LOOP_READ_WRITE,
    DAQ_STREAM_READ,
    DAQ_STREAM_READ_WRITE,
    DAQ_STREAM_READ_WRITE_ARRAY,
    DAQ_STREAM_INDEPENDENT_READ_WRITE_ARRAY,
    DAQ_STREAM_SIDEBAND_READ_WRITE_ARRAY
};

enum DaqDataTypesToTest
{
    DAQ_U64,
    DAQ_U64_Array
};

string DataTypes[] = {"U64", "U64_Array"};

//---------------------------------------------------------------------
//---------------------------------------------------------------------
string GetOption(int argc, char** argv, string option)
{
    for(int i=0; i<argc; ++i)
    {
        string argval = argv[i];
        size_t start_pos = argval.find(option);
        if (start_pos != string::npos)
        {
            start_pos += option.size();
            if (argval[start_pos] == '=')
            {
                return argval.substr(start_pos + 1);
            }
            else
            {
                cout << "Incorrect syntax " << argval << ". Correct syntax is --" << option << "=<value>" << endl;
                return "";
            }
        }
    }
    return "";
}


//---------------------------------------------------------------------
//---------------------------------------------------------------------
std::string read_keycert( const std::string& filename)
{
	std::string data;
	std::ifstream file(filename.c_str(), std::ios::in);
	if (file.is_open())
	{
		std::stringstream ss;
		ss << file.rdbuf();
		file.close();
		data = ss.str();
	}
	return data;
}

shared_ptr<grpc::ChannelCredentials> CreateCredentials(int argc, char **argv)
{
    shared_ptr<grpc::ChannelCredentials> creds;
    auto certificatePath = GetOption(argc, argv, "--cert");
    if (!certificatePath.empty())
    {
        std::string cacert = read_keycert(certificatePath);
        grpc::SslCredentialsOptions ssl_opts;
        ssl_opts.pem_root_certs=cacert;
        creds = grpc::SslCredentials(ssl_opts);
    }
    else
    {
        creds = grpc::InsecureChannelCredentials();
    }
    return creds;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
DaqTestToRun GetTestToRun(int argc, char **argv)
{
    shared_ptr<grpc::ChannelCredentials> creds;
    auto test_to_run = GetOption(argc, argv, "--test");
    if (test_to_run.empty())
    {
        return DaqTestToRun::DAQ_STREAM_INDEPENDENT_READ_WRITE_ARRAY;
    }
    else
    {
        std::stringstream ss;
        int test;
        ss << test_to_run;
        ss >> test;
        return static_cast<DaqTestToRun>(test);
    }
}

void check_status(NiFpga_Status status, const std::string& func)
{
    if(status < 0)
    {
        throw std::runtime_error("ERROR " + std::to_string(status) + " calling " + func);
    }
}

constexpr auto NUM_ITERATIONS = 100; //0 * 60 * 60; // Compile time constant
using TimeVector = std::array<std::chrono::microseconds, NUM_ITERATIONS>;

void WriteLatencyData(const std::string& dataName, TimeVector::iterator begin, TimeVector::iterator end)
{
    std::sort(begin, end);
    
    double average = (*begin).count();
    auto iterations = 0;
    for (auto it = begin; it != end; ++it)
    {
        iterations += 1;
        average += (double)(*it).count();
    }
    average = average / iterations;
    auto min = *begin;
    auto max = *(--end);
    auto median = *(begin + iterations / 2);

    cout << dataName << ": " << endl;
    cout << "Min: " << min.count() << endl;
    cout << "Max: " << max.count() << endl;
    cout << "Median: " << median.count() << endl;
    cout << "Average: " << average << endl;
    cout << endl;
}

void ThreadRunSidebandLoop(uint64_t sideband_token, NiDAQmx::Stub* stub, nidevice_grpc::Session* daqmx_read_task)
{   
    try
    {
#ifndef _WIN32
        cpu_set_t cpuSet;
        CPU_ZERO(&cpuSet);
        CPU_SET(10, &cpuSet);
        CPU_SET(11, &cpuSet);
        pid_t threadId = syscall(SYS_gettid);
        auto result = sched_setaffinity(threadId, sizeof(cpu_set_t), &cpuSet);
#endif

        std::unique_ptr<NiDAQmx::Stub> daqmx_client(stub);
        ArrayDoubleData daqmx_write_values;
        BoolData daqmx_is_late;
        std::cout << "Start sideband thread" << std::endl;

        daqmx_write_values.mutable_value()->Reserve(1);
        daqmx_write_values.mutable_value()->Resize(1, 0);

        auto io_times = new TimeVector{};

        char* initialBlock = new char[1024 * 1024];
        google::protobuf::Arena arena(initialBlock, 1024 * 1024);
        nidaqmx_grpc::experimental::client::start_task(daqmx_client, *daqmx_read_task);
        for (int x = 0; x < NUM_ITERATIONS; ++x)
        {
            std::cout << "Starting iteration " << x << " of " << NUM_ITERATIONS << std::endl;
            auto start = std::chrono::steady_clock::now();
        
            // Write data
            auto write_data_request = google::protobuf::Arena::CreateMessage<ni::data_monikers::SidebandWriteRequest>(&arena);
            if (write_data_request->GetArena() != &arena)
            {
                std::cout << "No Arena" << std::endl;
            }
            auto moniker_values = write_data_request->mutable_values();
            moniker_values->add_values()->PackFrom(daqmx_write_values);     
            if (!WriteSidebandMessage(sideband_token, *write_data_request))
            {
                break;
            }
            std::cout << "Wrote some data" << std::endl;
    
            // Read data      
            auto read_result = google::protobuf::Arena::CreateMessage<ni::data_monikers::SidebandReadResponse>(&arena);
            auto daqmx_read_values = google::protobuf::Arena::CreateMessage<ArrayDoubleData>(&arena);
            if (!ReadSidebandMessage(sideband_token, read_result))
            {
                break;
            }
            std::cout << "Read sideband message " << std::endl;
            read_result->values().values(0).UnpackTo(daqmx_read_values); //1 will be channeldata
            arena.Reset();
            auto end = std::chrono::steady_clock::now();        
            (*io_times)[x] = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            
            std::this_thread::sleep_for(std::chrono::microseconds(950));
        }

        std::cout << "Teardown" << std::endl;
        ni::data_monikers::SidebandWriteRequest cancel_request;
        cancel_request.set_cancel(true);
        WriteSidebandMessage(sideband_token, cancel_request);
        CloseSidebandData(sideband_token);

        auto firstLoop = (*io_times).begin() + 1;
        WriteLatencyData("IO Times", firstLoop, (*io_times).end());
        // I think we need to release here since the client api requires a unique_tr to be passed in but unique_ptr is not copyable so we can't pass it in
        // a thread proc. So I am passing a rw pointer to this, creating a unique_ptr in here and releasing the ownership so that the pointer is not deleted
        // in this thread proc as the pointer is still needed to make function calls later from the main thread. 
        daqmx_client.release();
    }
    catch (grpc_driver_error e)
    {
        std::cout << "Driver error: " << e.StatusCode() << std::endl << "Message: " << e.what() << std::endl;
    }
}

void SetupDaqmxReadWriteTasks(const StubPtr& daqmx_client,
    nidevice_grpc::Session* daqmx_read_task,
    nidevice_grpc::Session* daqmx_write_task,
    ni::data_monikers::Moniker** daqmx_read_moniker,
    ni::data_monikers::Moniker** daqmx_write_moniker)
{
    // TODO: Check status for fpga/daqmx calls
    double DAQ_FREQUENCY = 1000.0;

    // daqmx_client.ResetDevice("PXI1Slot3"); // TODO: sagrahar 10O Oct commented out, verify later if we need it
    // Create the AI task and get the read moniker
    auto read_task_response = create_task(daqmx_client, "", nidevice_grpc::SessionInitializationBehavior::SESSION_INITIALIZATION_BEHAVIOR_UNSPECIFIED);
    daqmx_read_task->CopyFrom(read_task_response.task());
    create_ai_voltage_chan(daqmx_client, *daqmx_read_task, "PXI1Slot6/ai0", "", DAQmx_Val_Cfg_Default, -10.0, 10.0, DAQmx_Val_Volts, "");
    cfg_samp_clk_timing(daqmx_client, *daqmx_read_task, "", DAQ_FREQUENCY, DAQmx_Val_Rising, DAQmx_Val_HWTimedSinglePoint, 1000); // Changing rate to 1000 for HW_TimedSinglePoint
    set_read_attribute_int32(daqmx_client, *daqmx_read_task, READ_ATTRIBUTE_WAIT_MODE, READ_INT32_WAIT_MODE_POLL);

    // daqmx_client.BeginWaitForNextSampleClock(*daqmx_read_task, 10.0, daqmx_wait_moniker);
    auto begin_read_analog_f64_response = begin_read_analog_f64(daqmx_client, *daqmx_read_task, 1, 10.0, DAQmx_Val_GroupByChannel, 1); // Changing 1000 to 1 for the HW timed single point
    *daqmx_read_moniker = new ni::data_monikers::Moniker(begin_read_analog_f64_response.moniker());

    // Create the AO task and get the write moniker
    auto write_task_response = create_task(daqmx_client, "", nidevice_grpc::SessionInitializationBehavior::SESSION_INITIALIZATION_BEHAVIOR_UNSPECIFIED);
    daqmx_write_task->CopyFrom(write_task_response.task());
    create_ao_voltage_chan(daqmx_client, *daqmx_write_task, "PXI1Slot8/ao0", "", -10.0, 10.0, DAQmx_Val_Volts, "");
    cfg_samp_clk_timing(daqmx_client, *daqmx_write_task, "/PXI1Slot6/ai/SampleClock", DAQ_FREQUENCY, DAQmx_Val_Rising, DAQmx_Val_HWTimedSinglePoint, 1); //changed 10000 to 1000

    auto begin_write_analog_f64_response = begin_write_analog_f64(daqmx_client, *daqmx_write_task, 1, true, -1, true); // Changing 1000 to 1 for the HW timed single point
    *daqmx_write_moniker = new ni::data_monikers::Moniker(begin_write_analog_f64_response.moniker());
    std::cout << "DAQmx setup complete" << std::endl;
}

void CleanupDaqmxTasks(const StubPtr& daqmx_client,
    const nidevice_grpc::Session& daqmx_read_task,
    const nidevice_grpc::Session& daqmx_write_task)
{
    std::cout << "Cleaning up." << std::endl;
    stop_task(daqmx_client, daqmx_read_task);
    clear_task(daqmx_client, daqmx_read_task);
    stop_task(daqmx_client, daqmx_write_task);
    clear_task(daqmx_client, daqmx_write_task);
}

void PrintArray(const ArrayDoubleData& data)
{
    std::cout << "[";
    for(auto it=data.value().begin();
        it != data.value().end();
        ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "]" << std::endl;
}

void CopyDataToWrite(ni::data_monikers::MonikerValues *moniker_values, DaqDataTypesToTest dataType)
{
    switch(dataType)
    {
        case DaqDataTypesToTest::DAQ_U64:
            throw std::logic_error("Function not yet implemented");
        case DaqDataTypesToTest::DAQ_U64_Array:
            {
                ArrayDoubleData daqmx_write_values;
                int array_size = 1;
                daqmx_write_values.mutable_value()->Reserve(array_size);
                daqmx_write_values.mutable_value()->Resize(array_size, 0);

                double* data_to_write = daqmx_write_values.mutable_value()->mutable_data();
                for(int i=0; i<array_size; i++)
                {
                    *(data_to_write + i) = i*100;
                }
                std::cout << "Writing data..." << std::endl;
                PrintArray(daqmx_write_values);
                moniker_values->add_values()->PackFrom(daqmx_write_values);
            }
            break;
        default:
            throw std::logic_error("Data type \"" + DataTypes[dataType] + "\" not supported.");
            break;
    }
}

void HandleReadResponse(const google::protobuf::Any& read_message, DaqDataTypesToTest dataType)
{
    switch(dataType)
    {
        case DaqDataTypesToTest::DAQ_U64:
            throw std::logic_error("Function not yet implemented");
        case DaqDataTypesToTest::DAQ_U64_Array:
            {
                ArrayDoubleData daqmx_read_values;
                read_message.UnpackTo(&daqmx_read_values);
                std::cout << "Read data..." << std::endl;
                PrintArray(daqmx_read_values);
            }
            break;
        default:
            throw std::logic_error("Data type \"" + DataTypes[dataType] + "\" not supported.");
            break;
    }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
void DoDaqStreamReadWriteArray(const StubPtr& daqmx_client, ni::data_monikers::DataMoniker::Stub& moniker_service)
{
    try {
        auto start = std::chrono::steady_clock::now();

        NiFpga_Status fpga_status = 0;
        nidevice_grpc::Session daqmx_read_task;
        nidevice_grpc::Session daqmx_write_task;
        ni::data_monikers::Moniker* daqmx_read_moniker;
        ni::data_monikers::Moniker* daqmx_write_moniker;

        SetupDaqmxReadWriteTasks(daqmx_client, &daqmx_read_task, &daqmx_write_task, &daqmx_read_moniker, &daqmx_write_moniker);

        // Setup the read/write stream
        ClientContext stream_context;
        auto stream = moniker_service.StreamReadWrite(&stream_context);

        // First write to the stream with the monikers
        ni::data_monikers::MonikerWriteRequest write_request;
        auto moniker_list = write_request.mutable_monikers();
        moniker_list->mutable_read_monikers()->AddAllocated(daqmx_write_moniker);
        moniker_list->mutable_write_monikers()->AddAllocated(daqmx_read_moniker);
        // Tell the stream that we are going to write then read
        // moniker_list->set_is_initial_write(true);
        stream->Write(write_request);

        // Write data
        ni::data_monikers::MonikerWriteRequest write_data_request;
        auto moniker_values = write_data_request.mutable_data();
        CopyDataToWrite(moniker_values, DaqDataTypesToTest::DAQ_U64_Array);

        stream->Write(write_data_request);

        std::this_thread::sleep_for(10us);

        // Read data
        ni::data_monikers::MonikerReadResponse read_data_result;
        stream->Read(&read_data_result);
        google::protobuf::Any read_message = read_data_result.data().values(0);
        HandleReadResponse(read_message, DaqDataTypesToTest::DAQ_U64_Array);

        stream->WritesDone();

        CleanupDaqmxTasks(daqmx_client, daqmx_read_task, daqmx_write_task);

        auto end = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "NiDaqmx calls took " << elapsed.count() / 100 << " microseconds." << std::endl;
    }
    catch (grpc_driver_error e)
    {
        std::cout << "Driver error: " << e.StatusCode() << std::endl << "Message: " << e.what() << std::endl;
    }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
void DoIndependentStreamReadWriteArray(const StubPtr& daqmx_client, ni::data_monikers::DataMoniker::Stub& moniker_service)
{
    try {
        auto start = std::chrono::steady_clock::now();

        NiFpga_Status fpga_status = 0;
        nidevice_grpc::Session daqmx_read_task;
        nidevice_grpc::Session daqmx_write_task;
        ni::data_monikers::Moniker* daqmx_read_moniker;
        ni::data_monikers::Moniker* daqmx_write_moniker;

        SetupDaqmxReadWriteTasks(daqmx_client, &daqmx_read_task, &daqmx_write_task, &daqmx_read_moniker, &daqmx_write_moniker);

        // Setup the write stream
        ClientContext write_stream_context;
        auto write_stream = moniker_service.StreamWrite(&write_stream_context);
        ni::data_monikers::MonikerWriteRequest write_request;
        auto moniker_list = write_request.mutable_monikers();
        moniker_list->mutable_write_monikers()->AddAllocated(daqmx_write_moniker);
        write_stream->Write(write_request);

        // Setup the read stream
        ClientContext read_stream_context;
        ni::data_monikers::MonikerList read_request;
        read_request.mutable_read_monikers()->AddAllocated(daqmx_read_moniker);
        auto read_stream = moniker_service.StreamRead(&read_stream_context, read_request);

        // Write data
        ni::data_monikers::MonikerWriteRequest write_data_request;
        auto moniker_values = write_data_request.mutable_data();
        CopyDataToWrite(moniker_values, DaqDataTypesToTest::DAQ_U64_Array);

        write_stream->Write(write_data_request);

        std::this_thread::sleep_for(10us);

        // Read data
        ni::data_monikers::MonikerReadResponse read_data_result;
        read_stream->Read(&read_data_result);
        google::protobuf::Any read_message = read_data_result.data().values(0);
        HandleReadResponse(read_message, DAQ_U64_Array);

        write_stream->WritesDone();
        read_stream_context.TryCancel();

        CleanupDaqmxTasks(daqmx_client, daqmx_read_task, daqmx_write_task);

        auto end = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "NiDaqmx calls took " << elapsed.count() / 100 << " microseconds." << std::endl;
    }
    catch (grpc_driver_error e)
    {
        std::cout << "Driver error: " << e.StatusCode() << std::endl << "Message: " << e.what() << std::endl;
    }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
void DoSidebandStreamTest(const StubPtr& daqmx_client, ni::data_monikers::DataMoniker::Stub& moniker_service)
{
    try {
        auto start = std::chrono::steady_clock::now();

        NiFpga_Status fpga_status = 0;
        nidevice_grpc::Session daqmx_read_task;
        nidevice_grpc::Session daqmx_write_task;
        ni::data_monikers::Moniker* daqmx_read_moniker;
        ni::data_monikers::Moniker* daqmx_write_moniker;

        SetupDaqmxReadWriteTasks(daqmx_client, &daqmx_read_task, &daqmx_write_task, &daqmx_read_moniker, &daqmx_write_moniker);

        // Setup the read / write stream
        ClientContext moniker_context;
        ni::data_monikers::BeginMonikerSidebandStreamRequest sideband_request;
        ni::data_monikers::BeginMonikerSidebandStreamResponse sideband_response;
        
        sideband_request.set_strategy(ni::data_monikers::SidebandStrategy::SOCKETS_LOW_LATENCY);
        sideband_request.mutable_monikers()->mutable_read_monikers()->AddAllocated(daqmx_read_moniker);
        sideband_request.mutable_monikers()->mutable_write_monikers()->AddAllocated(daqmx_write_moniker);

        std::cout << "Setup monikers complete" << std::endl;
        auto status = moniker_service.BeginSidebandStream(&moniker_context, sideband_request, &sideband_response);
        if(!status.ok()) {
            std::cout << "ERROR BeginSidebandStream: (" << status.error_code() << ") " << status.error_message() << std::endl;
        }

        auto sideband_token = InitClientSidebandData(sideband_response);
        std::cout << "InitClientSidebandData complete with token " << sideband_token << std::endl;

        // Now steam writes and reads
        std::thread* thread = new std::thread(ThreadRunSidebandLoop, sideband_token, daqmx_client.get(), &daqmx_read_task);
        thread->join();

        CleanupDaqmxTasks(daqmx_client, daqmx_read_task, daqmx_write_task);

        auto end = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "NiDaqmx calls took " << elapsed.count() / 100 << " microseconds." << std::endl;
    }
    catch (grpc_driver_error e)
    {
        std::cout << "Driver error: " << e.StatusCode() << std::endl << "Message: " << e.what() << std::endl;
    }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
int main(int argc, char **argv)
{
    grpc_init();
    grpc_timer_manager_set_threading(false);
    ::grpc_core::Executor::SetThreadingDefault(false);
    ::grpc_core::Executor::SetThreadingAll(false);

#ifndef _WIN32
    sched_param schedParam;
    schedParam.sched_priority = 95;
    sched_setscheduler(0, SCHED_FIFO, &schedParam);

    cpu_set_t cpuSet;
    CPU_ZERO(&cpuSet);
    //CPU_SET(9, &cpuSet);
    CPU_SET(9, &cpuSet);
    sched_setaffinity(0, sizeof(cpu_set_t), &cpuSet);
#endif

    auto target_str = GetOption(argc, argv, "--target");
    auto target_str_sideband = GetOption(argc, argv, "--target");
    if(target_str.empty())
    {
        cout << "Connecting to localhost" << endl;
        //target_str = "localhost:31763";
        target_str = "10.1.128.143:31763";
        target_str_sideband = "10.1.128.143:7000";
    }

    auto creds = CreateCredentials(argc, argv);
    auto test_run = GetTestToRun(argc, argv);
    std::cout << "Starting..." << std::endl;

    StubPtr stub = std::make_unique<NiDAQmx::Stub>(grpc::CreateChannel(target_str, creds));
    ni::data_monikers::DataMoniker::Stub moniker_service(grpc::CreateChannel(target_str, creds));

    std::cout << "Established client connections" << std::endl;
    switch(test_run)
    {
        // case DaqTestToRun::DAQ_READ:
        //     // example which reads from indicators of different datatypes
        //     cout << endl << ">> " << "1: Simple read from DAQmx <<" << endl;
        //     cout << "--------------------------------------" << endl << endl;
        //     DoDaqRead(stub);
        //     break;

        // case DaqTestToRun::DAQ_LOOP_READ_WRITE:
        //     // example which reads from indicators in a loop
        //     cout << endl << ">> " << "2: Simple read loop from DAQmx <<" << endl;
        //     cout << "--------------------------------------" << endl << endl;
        //     DoDaqReadWriteInLoop(stub);
        //     break;

        // case DaqTestToRun::DAQ_STREAM_READ:
        //     cout << endl << ">> " << "3: Stream read from DAQmx <<" << endl;
        //     cout << "--------------------------------------" << endl << endl;
        //     DoDaqStreamRead(stub, moniker_service);
        //     break;

        // case DaqTestToRun::DAQ_STREAM_READ_WRITE:
        //     cout << endl << ">> " << "4: Stream read/write from DAQmx <<" << endl;
        //     cout << "--------------------------------------" << endl << endl;
        //     DoDaqStreamReadWrite(stub, moniker_service);
        //     break;

        case DaqTestToRun::DAQ_STREAM_READ_WRITE_ARRAY:
            cout << endl << ">> " << "5: Stream read/write array from DAQmx <<" << endl;
            cout << "--------------------------------------" << endl << endl;
            DoDaqStreamReadWriteArray(stub, moniker_service);
            break;

        case DaqTestToRun::DAQ_STREAM_INDEPENDENT_READ_WRITE_ARRAY:
            cout << endl << ">> " << "6: Independent Stream read/write array from DAQmx <<" << endl;
            cout << "--------------------------------------" << endl << endl;
            DoIndependentStreamReadWriteArray(stub, moniker_service);
            break;

        case DaqTestToRun::DAQ_STREAM_SIDEBAND_READ_WRITE_ARRAY:
            cout << endl << ">> " << "7: Sideband Stream read/write array from DAQmx <<" << endl;
            cout << "--------------------------------------" << endl << endl;
            DoSidebandStreamTest(stub, moniker_service);
            break;

        case DaqTestToRun::DAQ_INVALID:
        default:
            cout << endl << ">> Invalid test option <<" << endl << endl;
            break;
    }
    return 0;
}
