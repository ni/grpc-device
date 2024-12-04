#include <NIDAQmx.h>
#include <nidaqmx/nidaqmx_mock_library.h>
#include <nidaqmx/nidaqmx_client.h>

#include <gmock/gmock-spec-builders.h>
#include <google/protobuf/stubs/port.h>
#include <grpcpp/client_context.h>
#include <grpcpp/server_builder.h>
#include <gtest/gtest.h>
#include <nidaqmx.grpc.pb.h>
#include <nidaqmx.pb.h>
#include <nidaqmx/nidaqmx_service.h>
#include <register_all_services.h>
#include <server/data_moniker_service.h>
#include <server/session_resource_repository.h>
#include <sideband_grpc.h>
#include <thread>

namespace ni {
namespace tests {
namespace integration {

using namespace ::testing;
using namespace nidevice_grpc;
namespace pb = ::google::protobuf;
using CodeReadiness = nidevice_grpc::FeatureToggles::CodeReadiness;

// This test class is used to test the NiDAQmxService using a mocked daqmx library(NiDAQmxMockLibrary)
// We intend to use this class to test streaming apis in NiDAQmxService
class NiFakeDAQmxStreamingTests : public ::testing::Test {
 private:
  std::shared_ptr<nidevice_grpc::SessionRepository> session_repository_;
  std::shared_ptr<ni::tests::unit::NiDAQmxMockLibrary> library_;
  std::shared_ptr<nidaqmx_grpc::NiDAQmxService> daqmxService_;
  std::shared_ptr<ni::data_monikers::DataMonikerService> moniker_service_;
  std::unique_ptr<::grpc::Server> server_;
  std::unique_ptr<nidaqmx_grpc::NiDAQmx::Stub> stub_;
  std::unique_ptr<ni::data_monikers::DataMoniker::Stub> moniker_service_stub_;
  std::atomic<bool> shutdown_{false};

 public:
  NiFakeDAQmxStreamingTests()
  {
    session_repository_ = std::make_shared<nidevice_grpc::SessionRepository>();
    library_ = std::make_shared<ni::tests::unit::NiDAQmxMockLibrary>();
    auto ni_daqmx_session_repository = std::make_shared<nidevice_grpc::SessionResourceRepository<TaskHandle>>(session_repository_);
    daqmxService_ = std::make_shared<nidaqmx_grpc::NiDAQmxService>(library_, ni_daqmx_session_repository, FeatureToggles({}, CodeReadiness::kNextRelease));
    moniker_service_ = std::make_shared<ni::data_monikers::DataMonikerService>();
    server_ = start_server();
    nidaqmx_grpc::RegisterMonikerEndpoints();
    stub_ = nidaqmx_grpc::NiDAQmx::NewStub(server_->InProcessChannel(::grpc::ChannelArguments()));
    moniker_service_stub_ = ni::data_monikers::DataMoniker::NewStub(server_->InProcessChannel(::grpc::ChannelArguments()));
    Mock::AllowLeak(library_.get());
  }

  virtual ~NiFakeDAQmxStreamingTests()
  {
    shutdown();
  }

  void shutdown()
  {
    if (!shutdown_) {
      shutdown_ = true;
      server_->Shutdown();
    }
  }

  std::unique_ptr<nidaqmx_grpc::NiDAQmx::Stub>& stub()
  {
    return stub_;
  }

  std::unique_ptr<ni::data_monikers::DataMoniker::Stub>& moniker_stub()
  {
    return moniker_service_stub_;
  }

  std::shared_ptr<ni::tests::unit::NiDAQmxMockLibrary> library()
  {
    return library_;
  }

  std::unique_ptr<::grpc::Server> start_server()
  {
    ::grpc::ServerBuilder builder;
    builder.RegisterService(daqmxService_.get());
    builder.RegisterService(moniker_service_.get());
    return builder.BuildAndStart();
  }
};

TEST_F(NiFakeDAQmxStreamingTests, StreamRead_Scalar)
{
  auto session = std::make_unique<nidevice_grpc::Session>();

  // Set expectation on the mocked daqmx lib method.
  EXPECT_CALL(*library(), ReadDigitalScalarU32(_, 0, ::testing::_, _))
      .WillOnce(::testing::DoAll(::testing::SetArgPointee<2>(1), ::testing::Return(0)))
      .WillOnce(::testing::DoAll(::testing::SetArgPointee<2>(2), ::testing::Return(0)))
      .WillOnce(::testing::DoAll(::testing::SetArgPointee<2>(3), ::testing::Return(0)))
      .WillOnce(::testing::DoAll(::testing::SetArgPointee<2>(4), ::testing::Return(0)))
      .WillOnce(::testing::DoAll(::testing::SetArgPointee<2>(5), ::testing::Return(0)))
      .WillRepeatedly(::testing::DoAll(::testing::SetArgPointee<2>(999), ::testing::Return(0)));

  // Dont worry about deleting read_moniker_u32 since AddAllocated takes ownership of the ptr being passed in ensuring its destruction.
  auto begin_read_u32_response = nidaqmx_grpc::experimental::client::begin_read_digital_scalar_u32(stub(), *session, 0);
  ni::data_monikers::Moniker* read_moniker_u32 = new ni::data_monikers::Moniker(begin_read_u32_response.moniker());

  grpc::ClientContext moniker_context;
  ni::data_monikers::MonikerList read_requests;
  read_requests.mutable_read_monikers()->AddAllocated(read_moniker_u32);
  auto stream = moniker_stub().get()->StreamRead(&moniker_context, read_requests);

  for (int i = 0; i < 5; i++) {
    // Read data
    nidaqmx_grpc::MonikerReadDigitalScalarU32Response read_value_u32;
    ni::data_monikers::MonikerReadResponse read_result;
    stream->Read(&read_result);
    read_result.data().values(0).UnpackTo(&read_value_u32);
    EXPECT_EQ(read_value_u32.value(), i + 1);
  }

  moniker_context.TryCancel();
}

TEST_F(NiFakeDAQmxStreamingTests, StreamRead_Array)
{
  auto session = std::make_unique<nidevice_grpc::Session>();

  // create some data for the array
  std::vector<pb::uint32> data_u32 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size = data_u32.size();

  // Set expectation on the mocked daqmx lib method.
  EXPECT_CALL(*library(), ReadDigitalU32(_, 1, 0, DAQmx_Val_GroupByChannel, ::testing::_, 10, _, _))
      .WillRepeatedly(::testing::DoAll(::testing::SetArrayArgument<4>(data_u32.begin(), data_u32.begin() + size), ::testing::Return(0)));

  // Dont worry about deleting read_moniker_u32 since AddAllocated takes ownership of the ptr being passed in ensuring its destruction.
  auto begin_read_digital_u32_response = nidaqmx_grpc::experimental::client::begin_read_digital_u32(stub(), *session, 1, 0, DAQmx_Val_GroupByChannel, 10);
  auto read_moniker_u32 = new ni::data_monikers::Moniker(begin_read_digital_u32_response.moniker());

  grpc::ClientContext moniker_context;
  ni::data_monikers::MonikerList read_requests;
  read_requests.mutable_read_monikers()->AddAllocated(read_moniker_u32);

  auto stream = moniker_stub().get()->StreamRead(&moniker_context, read_requests);

  for (int i = 0; i < 5; i++) {
    // Read data
    nidaqmx_grpc::MonikerReadDigitalU32Response read_values_u32;
    ni::data_monikers::MonikerReadResponse read_result;
    stream->Read(&read_result);
    read_result.data().values(0).UnpackTo(&read_values_u32);
    ASSERT_THAT(read_values_u32.read_array(), ElementsAreArray(data_u32));
  }

  moniker_context.TryCancel();
}

TEST_F(NiFakeDAQmxStreamingTests, StreamWrite_Array)
{
  // create some setup for writing
  auto session = std::make_unique<nidevice_grpc::Session>();
  std::vector<pb::uint32> data_int_u32 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size = data_int_u32.size();

  // Set expectation on the mocked fpga lib method.
  EXPECT_CALL(*library(), WriteDigitalU32(_, 10, TRUE, 0, DAQmx_Val_GroupByChannel, ::testing::_, _, _))
      .With(Args<5, 1>(ElementsAreArray(data_int_u32)))
      .WillRepeatedly(::testing::Return(0));

  // Dont worry about deleting write_moniker_u32 since AddAllocated takes ownership of the ptr being passed in ensuring its destruction.
  auto begin_write_digital_u32_response = nidaqmx_grpc::experimental::client::begin_write_digital_u32(stub(), *session, 10, TRUE, 0, DAQmx_Val_GroupByChannel);
  auto write_moniker_u32 = new ni::data_monikers::Moniker(begin_write_digital_u32_response.moniker());

  grpc::ClientContext moniker_context;
  ni::data_monikers::MonikerWriteRequest write_request;
  write_request.mutable_monikers()->mutable_write_monikers()->AddAllocated(write_moniker_u32);

  auto write_stream = moniker_stub().get()->StreamWrite(&moniker_context);
  write_stream->Write(write_request);

  for (int i = 0; i < 5; i++) {
    // Write data
    nidaqmx_grpc::MonikerWriteDigitalU32Request write_digital_u32_request;
    write_digital_u32_request.mutable_write_array()->Add(data_int_u32.begin(), data_int_u32.end());
    ni::data_monikers::MonikerWriteRequest write_data_request;
    write_data_request.mutable_data()->add_values()->PackFrom(write_digital_u32_request);
    write_stream->Write(write_data_request);
  }

  write_stream->WritesDone();
  moniker_context.TryCancel();
}

TEST_F(NiFakeDAQmxStreamingTests, StreamReadWrite_Array)
{
  auto session = std::make_unique<nidevice_grpc::Session>();

  // create some data for the array
  std::vector<pb::uint32> data_int_u32 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // Set expectation on the mocked fpga lib method.
  EXPECT_CALL(*library(), WriteDigitalU32(_, 10, TRUE, 0, DAQmx_Val_GroupByChannel, ::testing::_, _, _))
      .With(Args<5, 1>(ElementsAreArray(data_int_u32)))
      .WillRepeatedly(::testing::Return(0));

  // create some setup for reading
  std::vector<pb::uint32> data_u32 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int read_size = data_u32.size();

  // Set expectation on the mocked fpga lib method.
  EXPECT_CALL(*library(), ReadDigitalU32(_, 1, 0, DAQmx_Val_GroupByChannel, ::testing::_, 10, _, _))
      .WillRepeatedly(::testing::DoAll(::testing::SetArrayArgument<4>(data_u32.begin(), data_u32.begin() + read_size), ::testing::Return(0)));

  // Dont worry about deleting write_moniker_u32 since AddAllocated takes ownership of the ptr being passed in ensuring its destruction.
  auto begin_write_digital_u32_response = nidaqmx_grpc::experimental::client::begin_write_digital_u32(stub(), *session, 10, TRUE, 0, DAQmx_Val_GroupByChannel);
  auto write_moniker_u32 = new ni::data_monikers::Moniker(begin_write_digital_u32_response.moniker());

  // Dont worry about deleting read_moniker_u32 and read_moniker_i64 since AddAllocated takes ownership of the ptr being passed in ensuring its destruction.
  auto begin_read_digital_u32_response = nidaqmx_grpc::experimental::client::begin_read_digital_u32(stub(), *session, 1, 0, DAQmx_Val_GroupByChannel, 10);
  auto read_moniker_u32 = new ni::data_monikers::Moniker(begin_read_digital_u32_response.moniker());

  grpc::ClientContext moniker_context;
  ni::data_monikers::MonikerWriteRequest write_request;
  write_request.mutable_monikers()->mutable_read_monikers()->AddAllocated(read_moniker_u32);
  write_request.mutable_monikers()->mutable_write_monikers()->AddAllocated(write_moniker_u32);

  auto write_stream = moniker_stub().get()->StreamReadWrite(&moniker_context);
  write_stream->Write(write_request);

  for (int i = 0; i < 5; i++) {
    // Write data
    nidaqmx_grpc::MonikerWriteDigitalU32Request write_digital_u32_request;
    write_digital_u32_request.mutable_write_array()->Add(data_int_u32.begin(), data_int_u32.end());
    ni::data_monikers::MonikerWriteRequest write_data_request;
    write_data_request.mutable_data()->add_values()->PackFrom(write_digital_u32_request);
    write_stream->Write(write_data_request);

    // Read data
    nidaqmx_grpc::MonikerReadDigitalU32Response read_values_u32;
    ni::data_monikers::MonikerReadResponse read_result;
    write_stream->Read(&read_result);
    read_result.data().values(0).UnpackTo(&read_values_u32);
    ASSERT_THAT(read_values_u32.read_array(), SizeIs(read_size));
    ASSERT_THAT(read_values_u32.read_array(), ElementsAreArray(data_u32));
  }

  write_stream->WritesDone();
  moniker_context.TryCancel();
}
}  // namespace integration
}  // namespace tests
}  // namespace ni