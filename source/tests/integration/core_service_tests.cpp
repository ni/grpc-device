#include <gtest/gtest.h>

#include <thread>

#include "hardware/grpc/core_service.h"
#include "hardware/grpc/internal/semaphore.h"

namespace ni {
namespace tests {
namespace integration {

class InProcessServerClientTest : public ::testing::Test {
 public:
  virtual ~InProcessServerClientTest() {}

  void SetUp() override
  {
    ::grpc::ServerBuilder builder;
    session_repository_ = std::make_unique<ni::hardware::grpc::internal::SessionRepository>();
    device_enumerator_ = std::make_unique<ni::hardware::grpc::internal::DeviceEnumerator>();
    service_ = std::make_unique<ni::hardware::grpc::CoreService>(session_repository_.get(), device_enumerator_.get());
    builder.RegisterService(service_.get());
    server_ = builder.BuildAndStart();
    ResetStub();
  }

  void TearDown() override
  {
    server_->Shutdown();
  }

  void ResetStub()
  {
    channel_ = server_->InProcessChannel(::grpc::ChannelArguments());
    stub_ = ni::hardware::grpc::ServerUtilities::NewStub(channel_);
  }

  std::unique_ptr<ni::hardware::grpc::ServerUtilities::Stub>& GetStub()
  {
    return stub_;
  }

  ::grpc::Status call_reserve(
      std::string reservation_id,
      std::string client_id,
      const std::chrono::system_clock::time_point& deadline =
          std::chrono::system_clock::now() + std::chrono::seconds(1))
  {
    ni::hardware::grpc::ReserveRequest request;
    ni::hardware::grpc::ReserveResponse response;
    request.set_reservation_id(reservation_id);
    request.set_client_id(client_id);
    ::grpc::ClientContext context;
    context.set_deadline(deadline);
    return GetStub()->Reserve(&context, request, &response);
  }

  bool call_is_reserved(std::string reservation_id, std::string client_id)
  {
    ni::hardware::grpc::IsReservedByClientRequest request;
    ni::hardware::grpc::IsReservedByClientResponse response;
    request.set_reservation_id(reservation_id);
    request.set_client_id(client_id);
    ::grpc::ClientContext context;
    GetStub()->IsReservedByClient(&context, request, &response);
    return response.is_reserved();
  }

  bool call_unreserve(std::string reservation_id, std::string client_id)
  {
    ni::hardware::grpc::UnreserveRequest request;
    ni::hardware::grpc::UnreserveResponse response;
    request.set_reservation_id(reservation_id);
    request.set_client_id(client_id);
    ::grpc::ClientContext context;
    GetStub()->Unreserve(&context, request, &response);
    return response.is_unreserved();
  }

 protected:
  InProcessServerClientTest() {}

 private:
  std::shared_ptr<::grpc::Channel> channel_;
  std::unique_ptr<::ni::hardware::grpc::ServerUtilities::Stub> stub_;
  std::unique_ptr<ni::hardware::grpc::internal::SessionRepository> session_repository_;
  std::unique_ptr<ni::hardware::grpc::internal::DeviceEnumerator> device_enumerator_;
  std::unique_ptr<ni::hardware::grpc::CoreService> service_;
  std::unique_ptr<::grpc::Server> server_;
};

TEST_F(InProcessServerClientTest, CoreServiceClient_RequestIsServerRunning_ResponseIsTrue)
{
  ni::hardware::grpc::IsReservedByClientRequest request;
  ni::hardware::grpc::IsReservedByClientResponse response;

  ::grpc::ClientContext context;
  ::grpc::Status s = GetStub()->IsReservedByClient(&context, request, &response);

  EXPECT_FALSE(response.is_reserved());
  EXPECT_TRUE(s.ok());
}

TEST_F(InProcessServerClientTest, ClientTimesOutWaitingForReservation_FreeReservation_DoesNotReserve)
{
  auto status_a = call_reserve("foo", "a");
  auto status_b = call_reserve("foo", "b", std::chrono::system_clock::now() + std::chrono::milliseconds(5));

  call_unreserve("foo", "a");

  EXPECT_FALSE(call_is_reserved("foo", "b"));
  EXPECT_TRUE(status_a.ok());
  EXPECT_FALSE(status_b.ok());
  EXPECT_EQ(status_b.error_code(), ::grpc::DEADLINE_EXCEEDED);
}

TEST_F(InProcessServerClientTest, MultipleClientsTimeOutWaitingForReservation_FreeReservation_DoNotReserve)
{
  call_reserve("foo", "a");
  call_reserve("foo", "b", std::chrono::system_clock::now() + std::chrono::milliseconds(5));
  call_reserve("foo", "c", std::chrono::system_clock::now() + std::chrono::milliseconds(5));

  call_unreserve("foo", "a");

  EXPECT_FALSE(call_is_reserved("foo", "b"));
  EXPECT_FALSE(call_is_reserved("foo", "c"));
}

TEST_F(InProcessServerClientTest, ClientTimesOutWaitingForReservationWithOtherClientWaitingBehind_FreeReservation_ReservesLastClient)
{
  call_reserve("foo", "a");
  call_reserve("foo", "b", std::chrono::system_clock::now() + std::chrono::milliseconds(5));
  std::thread reserve_c([this] { call_reserve("foo", "c"); });
  std::this_thread::sleep_for(std::chrono::milliseconds(5));

  call_unreserve("foo", "a");
  reserve_c.join();

  EXPECT_FALSE(call_is_reserved("foo", "b"));
  EXPECT_TRUE(call_is_reserved("foo", "c"));
}

TEST_F(InProcessServerClientTest, SysCfgLibraryNotPresent_ClientCallsEnumerateDevices_ReturnsNotFoundGrpcStatusError)
{
  ni::hardware::grpc::EnumerateDevicesRequest request;
  ni::hardware::grpc::EnumerateDevicesResponse response;
  ::grpc::ClientContext context;

  ::grpc::Status status = GetStub()->EnumerateDevices(&context, request, &response);

  // Since the syscfg library will not be present in github repo, we expect a NOT_FOUND status in response.
  EXPECT_EQ(::grpc::StatusCode::NOT_FOUND, status.error_code());
}

}  // namespace integration
}  // namespace tests
}  // namespace ni
