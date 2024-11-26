#include <gtest/gtest.h>
#include "../generated/nifpga/nifpga_client.h"
#include <nifpga.grpc.pb.h>
#include <google/protobuf/stubs/port.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/client_context.h>
#include <register_all_services.h>
#include <NiFpga.h>
#include <server/session_resource_repository.h>
#include <../generated/nifpga/nifpga_mock_library.h>
#include <nifpga/nifpga_service.h>
#include <server/data_moniker_service.h>
#include <sideband_grpc.h>
#include <nifpga.pb.h>
#include <nifpga.grpc.pb.h>
#include <gmock/gmock-spec-builders.h>
#include <thread>

namespace ni {
namespace tests {
namespace integration {

using namespace ::testing;
using namespace nidevice_grpc;
namespace pb = ::google::protobuf;
using CodeReadiness = nidevice_grpc::FeatureToggles::CodeReadiness;

// This test class is used to test the NiFpgaService using a using a mocked fpga library(NiFpgaMockLibrary)
// We intend to use this class to test streaming apis in NiFpgaService
class NiFakeFpgaStreamingTests : public ::testing::Test {
 private:
  grpc::ServerBuilder builder_;
  std::shared_ptr<nidevice_grpc::SessionRepository> session_repository_;
  std::shared_ptr<ni::tests::unit::NiFpgaMockLibrary> library_;
  std::shared_ptr<std::vector<std::shared_ptr<void>>> services_;
  std::shared_ptr<nifpga_grpc::NiFpgaService> fpgaService_;
  std::shared_ptr<ni::data_monikers::DataMonikerService> moniker_service_;
  std::unique_ptr<::grpc::Server> server_;
  std::unique_ptr<nifpga_grpc::NiFpga::Stub> stub_;
  std::unique_ptr<ni::data_monikers::DataMoniker::Stub> moniker_service_stub_;
  std::thread* sideband_socket_thread_;
  std::atomic<bool> shutdown_{false};

 public:
    NiFakeFpgaStreamingTests()
    {
        session_repository_ = std::make_shared<nidevice_grpc::SessionRepository>();
        library_ = std::make_shared<ni::tests::unit::NiFpgaMockLibrary>();
        auto ni_fpga_session_repository = std::make_shared<nidevice_grpc::SessionResourceRepository<NiFpga_Session>>(session_repository_);
        fpgaService_ = std::make_shared<nifpga_grpc::NiFpgaService>(library_, ni_fpga_session_repository, FeatureToggles({}, CodeReadiness::kNextRelease));
        moniker_service_ = std::make_shared<ni::data_monikers::DataMonikerService>();
        server_ = start_server();
        nifpga_grpc::RegisterMonikerEndpoints();
        stub_ = nifpga_grpc::NiFpga::NewStub(server_->InProcessChannel(::grpc::ChannelArguments()));
        moniker_service_stub_ = ni::data_monikers::DataMoniker::NewStub(server_->InProcessChannel(::grpc::ChannelArguments()));
        Mock::AllowLeak(library_.get());

        // TODO: Implement sideband socket thread when we could support testing sideband streaming inprocess
        // sideband_socket_thread_ = new std::thread(RunSidebandSocketsAccept, "localhost", 50055);
    }

  virtual ~NiFakeFpgaStreamingTests()
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

  std::unique_ptr<nifpga_grpc::NiFpga::Stub>& stub()
  {
    return stub_;
  }

  std::unique_ptr<ni::data_monikers::DataMoniker::Stub>& moniker_stub()
  {
    return moniker_service_stub_;
  }

  std::shared_ptr<ni::tests::unit::NiFpgaMockLibrary> library()
  {
    return library_;
  }


  std::unique_ptr<::grpc::Server> start_server()
  {
    ::grpc::ServerBuilder builder;
    builder.RegisterService(fpgaService_.get());
    builder.RegisterService(moniker_service_.get());
    return builder.BuildAndStart();
  }
};

TEST_F(NiFakeFpgaStreamingTests, StreamRead_scalar)
{
  auto session = std::make_unique<nidevice_grpc::Session>();

  // Set expectation on the mocked fpga lib method.
  EXPECT_CALL(*library(), ReadI32(_, 0, ::testing::_))
      .WillOnce(::testing::DoAll(::testing::SetArgPointee<2>(1), ::testing::Return(0)))
      .WillOnce(::testing::DoAll(::testing::SetArgPointee<2>(2), ::testing::Return(0)))
      .WillOnce(::testing::DoAll(::testing::SetArgPointee<2>(3), ::testing::Return(0)))
      .WillOnce(::testing::DoAll(::testing::SetArgPointee<2>(4), ::testing::Return(0)))
      .WillOnce(::testing::DoAll(::testing::SetArgPointee<2>(5), ::testing::Return(0)))
      .WillRepeatedly(::testing::DoAll(::testing::SetArgPointee<2>(999), ::testing::Return(0)));
  EXPECT_CALL(*library(), ReadI64(_, 0, ::testing::_))
      .WillOnce(::testing::DoAll(::testing::SetArgPointee<2>(11), ::testing::Return(0)))
      .WillOnce(::testing::DoAll(::testing::SetArgPointee<2>(12), ::testing::Return(0)))
      .WillOnce(::testing::DoAll(::testing::SetArgPointee<2>(13), ::testing::Return(0)))
      .WillOnce(::testing::DoAll(::testing::SetArgPointee<2>(14), ::testing::Return(0)))
      .WillOnce(::testing::DoAll(::testing::SetArgPointee<2>(15), ::testing::Return(0)))
      .WillRepeatedly(::testing::DoAll(::testing::SetArgPointee<2>(999), ::testing::Return(0)));

  // Dont worry about deleting read_moniker_i32 and read_moniker_i64 since AddAllocated takes ownership of the ptr being passed in ensuring its destruction.
  auto begin_read_i32_response = nifpga_grpc::experimental::client::begin_read_i32(stub(), *session, 0);
  ni::data_monikers::Moniker* read_moniker_i32 = new ni::data_monikers::Moniker(begin_read_i32_response.moniker());
  auto begin_read_i64_response = nifpga_grpc::experimental::client::begin_read_i64(stub(), *session, 0);
  ni::data_monikers::Moniker* read_moniker_i64 = new ni::data_monikers::Moniker(begin_read_i64_response.moniker());

  grpc::ClientContext moniker_context;
  ni::data_monikers::MonikerList read_requests;
  read_requests.mutable_read_monikers()->AddAllocated(read_moniker_i32);
  read_requests.mutable_read_monikers()->AddAllocated(read_moniker_i64);

  auto stream = moniker_stub().get()->StreamRead(&moniker_context, read_requests);

  for (int i = 0; i < 5; i++)
  {
    // Read data
    nifpga_grpc::ReadI32StreamingResponse read_value_i32;
    nifpga_grpc::ReadI64StreamingResponse read_value_i64;

    ni::data_monikers::MonikerReadResponse read_result;
    stream->Read(&read_result);

    read_result.data().values(0).UnpackTo(&read_value_i32);
    EXPECT_EQ(read_value_i32.value(), i + 1);
    read_result.data().values(1).UnpackTo(&read_value_i64);
    EXPECT_EQ(read_value_i64.value(), i + 11);
  }

  moniker_context.TryCancel();
}

TEST_F(NiFakeFpgaStreamingTests, StreamRead_Array)
{
  auto session = std::make_unique<nidevice_grpc::Session>();

  // create some data for the array
  std::vector<pb::int32> data_int_i32 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<pb::int64> data_int_i64 = {11, 22, 33, 44, 55, 66, 77, 88, 99};
  int size_i32 = data_int_i32.size();
  int size_i64 = data_int_i64.size();

  // Set expectation on the mocked fpga lib method.
  EXPECT_CALL(*library(), ReadArrayI32(_, 0, ::testing::_, size_i32))
      .WillRepeatedly(::testing::DoAll(::testing::SetArrayArgument<2>(data_int_i32.begin(), data_int_i32.begin() + size_i32), ::testing::Return(0)));
  EXPECT_CALL(*library(), ReadArrayI64(_, 0, ::testing::_, 9))
      .WillRepeatedly(::testing::DoAll(::testing::SetArrayArgument<2>(data_int_i64.begin(), data_int_i64.begin() + size_i64), ::testing::Return(0)));

  // Dont worry about deleting read_moniker_i32 and read_moniker_i64 since AddAllocated takes ownership of the ptr being passed in ensuring its destruction.
  auto begin_read_i32_array_response = nifpga_grpc::experimental::client::begin_read_array_i32(stub(), *session, 0, 10);
  auto read_moniker_i32 = new ni::data_monikers::Moniker(begin_read_i32_array_response.moniker());

  auto begin_read_i64_response = nifpga_grpc::experimental::client::begin_read_array_i64(stub(), *session, 0, 9);
  auto read_moniker_i64 = new ni::data_monikers::Moniker(begin_read_i64_response.moniker());


  grpc::ClientContext moniker_context;
  ni::data_monikers::MonikerList read_requests;
  read_requests.mutable_read_monikers()->AddAllocated(read_moniker_i32);
  read_requests.mutable_read_monikers()->AddAllocated(read_moniker_i64);

  auto stream = moniker_stub().get()->StreamRead(&moniker_context, read_requests);

  for (int i = 0; i < 5; i++) {
    // Read data
    nifpga_grpc::ReadArrayI32StreamingResponse read_values_i32;
    nifpga_grpc::ReadArrayI64StreamingResponse read_values_i64;

    ni::data_monikers::MonikerReadResponse read_result;
    stream->Read(&read_result);

    read_result.data().values(0).UnpackTo(&read_values_i32);
    read_result.data().values(1).UnpackTo(&read_values_i64);
    ASSERT_THAT(read_values_i32.array(), SizeIs(10));
    ASSERT_THAT(read_values_i32.array(), ElementsAreArray(data_int_i32));
    ASSERT_THAT(read_values_i64.array(), SizeIs(9));
    ASSERT_THAT(read_values_i64.array(), ElementsAreArray(data_int_i64));
  }

  moniker_context.TryCancel();
}

TEST_F(NiFakeFpgaStreamingTests, StreamWrite_Array)
{   
  // create some setup for writing
  auto session = std::make_unique<nidevice_grpc::Session>();
  std::vector<pb::int32> data_int_i32 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<pb::int64> data_int_i64 = {11, 22, 33, 44, 55, 66, 77, 88, 99};
  int control = 1;
  int size_i32 = data_int_i32.size();
  int size_i64 = data_int_i64.size();

  // Set expectation on the mocked fpga lib method.
  EXPECT_CALL(*library(), WriteArrayI32(_, control, _, size_i32))
      .With(Args<2, 3>(ElementsAreArray(data_int_i32)))
      .WillRepeatedly(::testing::Return(0));
  EXPECT_CALL(*library(), WriteArrayI64(_, control, _, size_i64))
      .With(Args<2, 3>(ElementsAreArray(data_int_i64)))
      .WillRepeatedly(::testing::Return(0));

  // Dont worry about deleting write_moniker_i32 and write_moniker_i64 since AddAllocated takes ownership of the ptr being passed in ensuring its destruction.
  auto begin_write_i32_array_response = nifpga_grpc::experimental::client::begin_write_array_i32(stub(), *session, control);
  auto write_moniker_i32 = new ni::data_monikers::Moniker(begin_write_i32_array_response.moniker());
  auto begin_write_i64_response = nifpga_grpc::experimental::client::begin_write_array_i64(stub(), *session, control);
  auto write_moniker_i64 = new ni::data_monikers::Moniker(begin_write_i64_response.moniker());

  grpc::ClientContext moniker_context;
  ni::data_monikers::MonikerWriteRequest write_request;
  write_request.mutable_monikers()->mutable_write_monikers()->AddAllocated(write_moniker_i32);
  write_request.mutable_monikers()->mutable_write_monikers()->AddAllocated(write_moniker_i64);


  auto write_stream = moniker_stub().get()->StreamWrite(&moniker_context);
  write_stream->Write(write_request);

  for (int i = 0; i < 5; i++) {
    // Write data
    nifpga_grpc::ArrayI32Data write_values_array_i32;
    nifpga_grpc::ArrayI64Data write_values_array_i64;

    write_values_array_i32.mutable_value()->Add(data_int_i32.begin(), data_int_i32.end());
    write_values_array_i64.mutable_value()->Add(data_int_i64.begin(), data_int_i64.end());

    ni::data_monikers::MonikerWriteRequest write_data_request;
    write_data_request.mutable_data()->add_values()->PackFrom(write_values_array_i32);
    write_data_request.mutable_data()->add_values()->PackFrom(write_values_array_i64);

    write_stream->Write(write_data_request);
 
  }

  write_stream->WritesDone();
  moniker_context.TryCancel();
}

TEST_F(NiFakeFpgaStreamingTests, StreamReadWrite_Array)
{
  auto session = std::make_unique<nidevice_grpc::Session>();

  // create some data for the array
  std::vector<pb::int32> write_data_int32 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<pb::int64> write_data_int64 = {11, 22, 33, 44, 55, 66, 77, 88, 99};
  int control = 1;
  int write_size_i32 = write_data_int32.size();
  int write_size_i64 = write_data_int64.size();

  // Set expectation on the mocked fpga lib method.
  EXPECT_CALL(*library(), WriteArrayI32(_, control, _, write_size_i32))
      .With(Args<2,3>(ElementsAreArray(write_data_int32)))
      .WillRepeatedly(::testing::Return(0));
  EXPECT_CALL(*library(), WriteArrayI64(_, control, _, write_size_i64))
      .With(Args<2, 3>(ElementsAreArray(write_data_int64)))
      .WillRepeatedly(::testing::Return(0));

  // create some setup for reading
  std::vector<pb::int32> read_data_int32 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<pb::int64> read_data_int64 = {11, 22, 33, 44, 55, 66, 77, 88, 99};
  int read_size_i32 = read_data_int32.size();
  int read_size_i64 = read_data_int64.size();

  // Set expectation on the mocked fpga lib method.
  EXPECT_CALL(*library(), ReadArrayI32(_, 0, ::testing::_, 10))
      .WillRepeatedly(::testing::DoAll(::testing::SetArrayArgument<2>(read_data_int32.begin(), read_data_int32.begin() + read_size_i32), ::testing::Return(0)));
  EXPECT_CALL(*library(), ReadArrayI64(_, 0, ::testing::_, 9))
      .WillRepeatedly(::testing::DoAll(::testing::SetArrayArgument<2>(read_data_int64.begin(), read_data_int64.begin() + read_size_i64), ::testing::Return(0)));

  // Dont worry about deleting write_moniker_i32 and write_moniker_i64 since AddAllocated takes ownership of the ptr being passed in ensuring its destruction.
  auto begin_write_i32_array_response = nifpga_grpc::experimental::client::begin_write_array_i32(stub(), *session, control);
  auto write_moniker_i32 = new ni::data_monikers::Moniker(begin_write_i32_array_response.moniker());
  auto begin_write_i64_response = nifpga_grpc::experimental::client::begin_write_array_i64(stub(), *session, control);
  auto write_moniker_i64 = new ni::data_monikers::Moniker(begin_write_i64_response.moniker());

    // Dont worry about deleting read_moniker_i32 and read_moniker_i64 since AddAllocated takes ownership of the ptr being passed in ensuring its destruction.
  auto begin_read_i32_array__response = nifpga_grpc::experimental::client::begin_read_array_i32(stub(), *session, 0, read_data_int32.size());
  auto read_moniker_i32 = new ni::data_monikers::Moniker(begin_read_i32_array__response.moniker());
  auto begin_read_i64_response = nifpga_grpc::experimental::client::begin_read_array_i64(stub(), *session, 0, read_data_int64.size());
  auto read_moniker_i64 = new ni::data_monikers::Moniker(begin_read_i64_response.moniker());

  grpc::ClientContext moniker_context;
  ni::data_monikers::MonikerWriteRequest write_request;
  write_request.mutable_monikers()->mutable_read_monikers()->AddAllocated(read_moniker_i32);
  write_request.mutable_monikers()->mutable_read_monikers()->AddAllocated(read_moniker_i64);
  write_request.mutable_monikers()->mutable_write_monikers()->AddAllocated(write_moniker_i32);
  write_request.mutable_monikers()->mutable_write_monikers()->AddAllocated(write_moniker_i64);


  auto write_stream = moniker_stub().get()->StreamReadWrite(&moniker_context);
  write_stream->Write(write_request);

  for (int i = 0; i < 5; i++) {
    // Write data
    nifpga_grpc::ArrayI32Data write_values_array_i32;
    nifpga_grpc::ArrayI64Data write_values_array_i64;

    write_values_array_i32.mutable_value()->Add(write_data_int32.begin(), write_data_int32.end());
    write_values_array_i64.mutable_value()->Add(write_data_int64.begin(), write_data_int64.end());

    ni::data_monikers::MonikerWriteRequest write_data_request;
    write_data_request.mutable_data()->add_values()->PackFrom(write_values_array_i32);
    write_data_request.mutable_data()->add_values()->PackFrom(write_values_array_i64);

    write_stream->Write(write_data_request);

    nifpga_grpc::ReadArrayI32StreamingResponse read_values_i32;
    nifpga_grpc::ReadArrayI64StreamingResponse read_values_i64;

    ni::data_monikers::MonikerReadResponse read_result;
    write_stream->Read(&read_result);

    read_result.data().values(0).UnpackTo(&read_values_i32);
    read_result.data().values(1).UnpackTo(&read_values_i64);
    ASSERT_THAT(read_values_i32.array(), SizeIs(read_size_i32));
    ASSERT_THAT(read_values_i32.array(), ElementsAreArray(read_data_int32));
    ASSERT_THAT(read_values_i64.array(), SizeIs(read_size_i64));
    ASSERT_THAT(read_values_i64.array(), ElementsAreArray(read_data_int64));
  }

  write_stream->WritesDone();
  moniker_context.TryCancel();
}

// disable this test since we are not supporting sideband streaming inprocess

TEST_F(NiFakeFpgaStreamingTests, DISABLED_SidebandStreamReadWrite_Array)
{
  auto session = std::make_unique<nidevice_grpc::Session>();
  // create some data for the array
  std::vector<pb::int32> write_data_int32 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<pb::int64> write_data_int64 = {11, 22, 33, 44, 55, 66, 77, 88, 99};
  int control = 1;
  int size_i32 = write_data_int32.size();
  int size_i64 = write_data_int64.size();

  // Set expectation on the mocked fpga lib method.
  EXPECT_CALL(*library(), WriteArrayI32(_, control, _, size_i32))
      .With(Args<2, 3>(ElementsAreArray(write_data_int32)))
      .WillRepeatedly(::testing::Return(0));
  EXPECT_CALL(*library(), WriteArrayI64(_, control, _, size_i64))
      .With(Args<2, 3>(ElementsAreArray(write_data_int64)))
      .WillRepeatedly(::testing::Return(0));

  // create some setup for reading
  std::vector<pb::int32> data_int32 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<pb::int64> data_int64 = {11, 22, 33, 44, 55, 66, 77, 88, 99};

  // Set expectation on the mocked fpga lib method.
  EXPECT_CALL(*library(), ReadArrayI32(_, 0, ::testing::_, 10))
      .WillRepeatedly(::testing::DoAll(::testing::SetArrayArgument<2>(data_int32.begin(), data_int32.begin() + 10), ::testing::Return(0)));
  EXPECT_CALL(*library(), ReadArrayI64(_, 0, ::testing::_, 9))
      .WillRepeatedly(::testing::DoAll(::testing::SetArrayArgument<2>(data_int64.begin(), data_int64.begin() + 9), ::testing::Return(0)));

  // Dont worry about deleting read_moniker32 and read_moniker64 since AddAllocated takes ownership of the ptr being passed in ensuring its destruction.
  auto begin_write_i32_array_response = nifpga_grpc::experimental::client::begin_write_array_i32(stub(), *session, control);
  auto write_moniker_i32 = new ni::data_monikers::Moniker(begin_write_i32_array_response.moniker());
  auto begin_write_i64_response = nifpga_grpc::experimental::client::begin_write_array_i64(stub(), *session, control);
  auto write_moniker_i64 = new ni::data_monikers::Moniker(begin_write_i64_response.moniker());

  // Dont worry about deleting read_moniker32 and read_moniker64 since AddAllocated takes ownership of the ptr being passed in ensuring its destruction.
  auto begin_read_i32_array__response = nifpga_grpc::experimental::client::begin_read_array_i32(stub(), *session, 0, data_int32.size());
  auto read_moniker_i32 = new ni::data_monikers::Moniker(begin_read_i32_array__response.moniker());
  auto begin_read_i64_response = nifpga_grpc::experimental::client::begin_read_array_i64(stub(), *session, 0, data_int64.size());
  auto read_moniker_i64 = new ni::data_monikers::Moniker(begin_read_i64_response.moniker());

  grpc::ClientContext moniker_context;
  ni::data_monikers::BeginMonikerSidebandStreamRequest sideband_request;
  ni::data_monikers::BeginMonikerSidebandStreamResponse sideband_response;
  sideband_request.set_strategy(ni::data_monikers::SidebandStrategy::SOCKETS);
  sideband_request.mutable_monikers()->mutable_read_monikers()->AddAllocated(read_moniker_i32);
  sideband_request.mutable_monikers()->mutable_read_monikers()->AddAllocated(read_moniker_i64);
  sideband_request.mutable_monikers()->mutable_write_monikers()->AddAllocated(write_moniker_i32);
  sideband_request.mutable_monikers()->mutable_write_monikers()->AddAllocated(write_moniker_i64);

  auto write_stream = moniker_stub().get()->BeginSidebandStream(&moniker_context, sideband_request, &sideband_response);
  auto sideband_token = InitClientSidebandData(sideband_response);

  for (int i = 0; i < 5; i++) {
    // Write data
    nifpga_grpc::ArrayI32Data write_values_array_i32;
    nifpga_grpc::ArrayI64Data write_values_array_i64;

    write_values_array_i32.mutable_value()->Add(write_data_int32.begin(), write_data_int32.end());
    write_values_array_i64.mutable_value()->Add(write_data_int64.begin(), write_data_int64.end());

    ni::data_monikers::SidebandWriteRequest write_data_request;
    write_data_request.mutable_values()->add_values()->PackFrom(write_values_array_i32);
    write_data_request.mutable_values()->add_values()->PackFrom(write_values_array_i64);

    WriteSidebandMessage(sideband_token, write_data_request);

    nifpga_grpc::ReadArrayI32StreamingResponse read_values_i32;
    nifpga_grpc::ReadArrayI64StreamingResponse read_values_i64;

    ni::data_monikers::SidebandReadResponse read_result;
    ReadSidebandMessage(sideband_token, &read_result);

    read_result.values().values(0).UnpackTo(&read_values_i32);
    read_result.values().values(1).UnpackTo(&read_values_i64);
    ASSERT_THAT(read_values_i32.array(), SizeIs(10));
    ASSERT_THAT(read_values_i32.array(), ElementsAreArray(data_int32));
    ASSERT_THAT(read_values_i64.array(), SizeIs(9));
    ASSERT_THAT(read_values_i64.array(), ElementsAreArray(data_int64));
  }

  ni::data_monikers::SidebandWriteRequest cancel_request;
  cancel_request.set_cancel(true);
  WriteSidebandMessage(sideband_token, cancel_request);
  CloseSidebandData(sideband_token);
}

}  // namespace integration
}  // namespace tests
}  // namespace ni