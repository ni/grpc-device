/*********************************************************************
* Acquire data continuously from an analog input channel using moniker based streaming
*
* The gRPC API is built from the C API. NI-DAQmx documentation is installed with the driver at:
*   C:\Program Files (x86)\National Instruments\NI-DAQ\docs\cdaqmx.chm
*
* Getting Started:
*
* To run this example, install "NI-DAQmx Driver" on the server machine:
*   https://www.ni.com/en-us/support/downloads/drivers/download.ni-daqmx.html
*
* For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
* Client" wiki page:
*   https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client
*
* Refer to the NI DAQmx gRPC Wiki for the latest C Function Reference:
*   https://github.com/ni/grpc-device/wiki/NI-DAQMX-C-Function-Reference
*
* To run this example without hardware: create a simulated device in NI MAX on the server (Windows
* only).
*
* Build:
*
*   > mkdir build
*   > cd build
*   > cmake ..
*   > cmake --build .
*
* Running from command line:
*
* Server machine's IP address, port number, and physical channel name can be passed as separate
* command line arguments.
*   > MonikerStreamingClient <server_address> <port_number> <physical_channel_name>
* If they are not passed in as command line arguments, then by default the server address will be
* "localhost:31763", with "Dev1/ai0" as the physical channel name..
*********************************************************************/

#include <iostream>
#include <sstream>
#include <grpcpp/grpcpp.h>

#include "nidaqmx.grpc.pb.h"
#include "data_moniker.grpc.pb.h"

using namespace nidaqmx_grpc;
using StubPtr = std::unique_ptr<NiDAQmx::Stub>;

std::string SERVER_ADDRESS = "localhost";
std::string SERVER_PORT = "31763";
std::string PHYSICAL_CHANNEL = "Dev1/ai0";
int NUM_ITERATIONS = 5;

class grpc_driver_error : public std::runtime_error {
 private:
  ::grpc::StatusCode code_;
  std::multimap<std::string, std::string> trailers_;

 public:
  grpc_driver_error(const std::string& message, ::grpc::StatusCode code, const std::multimap<grpc::string_ref, grpc::string_ref>& trailers)
    : std::runtime_error(message), code_(code)
  {
    for (const auto& trailer : trailers) {
      trailers_.emplace(
        std::string(trailer.first.data(), trailer.first.length()),
        std::string(trailer.second.data(), trailer.second.length()));
    }
  }

  ::grpc::StatusCode StatusCode() const
  {
    return code_;
  }

  const std::multimap<std::string, std::string>& Trailers() const
  {
    return trailers_;
  }
};

inline void raise_if_error(const ::grpc::Status& status, const ::grpc::ClientContext& context)
{
  if (!status.ok()) {
    throw grpc_driver_error(status.error_message(), status.error_code(), context.GetServerTrailingMetadata());
  }
}

void print_array(const MonikerReadAnalogF64Response& data)
{
  std::cout << "[";
  for (int i = 0; i < data.read_array().size(); i++) {
    std::cout << data.read_array().Get(i) << " ";
  }
  std::cout << "]" << std::endl;
}

::nidevice_grpc::Session create_and_configure_read_task(NiDAQmx::Stub &client, const std::string &PHYSICAL_CHANNEL)
{
  ::grpc::ClientContext create_task_context;
  auto create_task_request = CreateTaskRequest{};
  create_task_request.set_session_name("my task");
  auto create_task_response = CreateTaskResponse{};
  raise_if_error(
    client.CreateTask(&create_task_context, create_task_request, &create_task_response),
    create_task_context);
  auto daqmx_read_task = create_task_response.task();

  ::grpc::ClientContext create_channel_context;
  auto create_channel_request = CreateAIVoltageChanRequest{};
  create_channel_request.mutable_task()->CopyFrom(daqmx_read_task);
  create_channel_request.set_physical_channel(PHYSICAL_CHANNEL);
  create_channel_request.set_terminal_config(InputTermCfgWithDefault::INPUT_TERM_CFG_WITH_DEFAULT_CFG_DEFAULT);
  create_channel_request.set_min_val(-10.0);
  create_channel_request.set_max_val(10.0);
  create_channel_request.set_units(VoltageUnits2::VOLTAGE_UNITS2_VOLTS);
  auto create_channel_response = CreateAIVoltageChanResponse{};
  raise_if_error(
    client.CreateAIVoltageChan(&create_channel_context, create_channel_request, &create_channel_response),
    create_channel_context);

  ::grpc::ClientContext cfg_clk_context;
  auto cfg_clk_request = CfgSampClkTimingRequest{};
  cfg_clk_request.mutable_task()->CopyFrom(daqmx_read_task);
  cfg_clk_request.set_rate(100.0);
  cfg_clk_request.set_active_edge(Edge1::EDGE1_RISING);
  cfg_clk_request.set_sample_mode(AcquisitionType::ACQUISITION_TYPE_HW_TIMED_SINGLE_POINT);
  cfg_clk_request.set_samps_per_chan(10);
  auto cfg_clk_response = CfgSampClkTimingResponse{};
  raise_if_error(
    client.CfgSampClkTiming(&cfg_clk_context, cfg_clk_request, &cfg_clk_response),
    cfg_clk_context);

  ::grpc::ClientContext set_read_attribute_context;
  auto set_read_attribute_request = SetReadAttributeInt32Request{};
  set_read_attribute_request.mutable_task()->CopyFrom(daqmx_read_task);
  set_read_attribute_request.set_attribute(ReadInt32Attribute::READ_ATTRIBUTE_WAIT_MODE);
  set_read_attribute_request.set_value(ReadInt32AttributeValues::READ_INT32_WAIT_MODE_POLL);
  auto set_read_attribute_response = SetReadAttributeInt32Response{};
  raise_if_error(
    client.SetReadAttributeInt32(&set_read_attribute_context, set_read_attribute_request, &set_read_attribute_response),
    set_read_attribute_context);

  ::grpc::ClientContext start_task_context;
  StartTaskRequest start_task_request;
  start_task_request.mutable_task()->CopyFrom(daqmx_read_task);
  StartTaskResponse start_task_response;
  raise_if_error(
    client.StartTask(&start_task_context, start_task_request, &start_task_response),
    start_task_context);

  return daqmx_read_task;
}

int main(int argc, char **argv)
{
  if (argc >= 2) {
    SERVER_ADDRESS = argv[1];
  }
  if (argc >= 3) {
    SERVER_PORT = argv[2];
  }
  if (argc >= 4) {
    PHYSICAL_CHANNEL = argv[3];
  }
  auto target_str = SERVER_ADDRESS + ":" + SERVER_PORT;
  auto channel = grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials());
  NiDAQmx::Stub client(channel);
  ni::data_monikers::DataMoniker::Stub moniker_service(channel);

  try {
    auto daqmx_read_task = create_and_configure_read_task(client, PHYSICAL_CHANNEL);

    // Setup the read stream
    ::grpc::ClientContext begin_read_context;
    auto begin_read_request = BeginReadAnalogF64Request{};
    begin_read_request.mutable_task()->CopyFrom(daqmx_read_task);
    begin_read_request.set_num_samps_per_chan(10);
    begin_read_request.set_timeout(10.0);
    begin_read_request.set_fill_mode(GroupBy::GROUP_BY_GROUP_BY_CHANNEL);
    begin_read_request.set_array_size_in_samps(10);
    auto begin_read_response = BeginReadAnalogF64Response{};
    raise_if_error(
      client.BeginReadAnalogF64(&begin_read_context, begin_read_request, &begin_read_response),
      begin_read_context);
    auto daqmx_read_moniker = new ni::data_monikers::Moniker(begin_read_response.moniker());

    ::grpc::ClientContext stream_read_context;
    ni::data_monikers::MonikerList read_request;
    read_request.mutable_read_monikers()->AddAllocated(daqmx_read_moniker);
    auto read_stream = moniker_service.StreamRead(&stream_read_context, read_request);

    // Read data
    for (int i = 0; i < NUM_ITERATIONS; i++) {
      ni::data_monikers::MonikerReadResponse read_data_result;
      if (read_stream->Read(&read_data_result)) {
        google::protobuf::Any read_message = read_data_result.data().values(0);

        MonikerReadAnalogF64Response read_analog_f64_response;
        read_message.UnpackTo(&read_analog_f64_response);
        std::cout << "Read data..." << std::endl;
        print_array(read_analog_f64_response);
      }
      else {
          std::cout << "No data available." << std::endl;
      }
    }

    stream_read_context.TryCancel();

    std::cout << "Cleaning up." << std::endl;

    ::grpc::ClientContext stop_task_context;
    StopTaskRequest stop_task_request;
    stop_task_request.mutable_task()->CopyFrom(daqmx_read_task);
    StopTaskResponse stop_task_response;
    raise_if_error(
      client.StopTask(&stop_task_context, stop_task_request, &stop_task_response),
      stop_task_context);

    ::grpc::ClientContext clear_task_context;
    ClearTaskRequest clear_task_request;
    clear_task_request.mutable_task()->CopyFrom(daqmx_read_task);
    ClearTaskResponse clear_task_response;
    raise_if_error(
      client.ClearTask(&clear_task_context, clear_task_request, &clear_task_response),
      clear_task_context);
  }
  catch (const grpc_driver_error& e) {
    std::string error_message = e.what();

    for (const auto& entry : e.Trailers()) {
      if (entry.first == "ni-error") {
        error_message += "\nError status: " + entry.second;
      }
    }

    if (e.StatusCode() == grpc::StatusCode::UNAVAILABLE) {
      error_message = "Failed to connect to server on " + SERVER_ADDRESS + ":" + SERVER_PORT;
    }
    else if (e.StatusCode() == grpc::StatusCode::UNIMPLEMENTED) {
      error_message = "The operation is not implemented or is not supported/enabled in this service";
    }

    std::cout << "Exception: " << error_message << std::endl;
  }
}