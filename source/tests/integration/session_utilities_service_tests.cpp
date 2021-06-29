#include <grpcpp/impl/grpc_library.h>
#include <gtest/gtest.h>
#include <server/device_enumerator.h>
#include <server/semaphore.h>
#include <server/session_repository.h>
#include <server/session_utilities_service.h>
#include <server/syscfg_library.h>
#include <tests/utilities/syscfg_mock_library.h>

#include <thread>

// fixes seg faults caused by https://github.com/grpc/grpc/issues/14633
static grpc::internal::GrpcLibraryInitializer g_gli_initializer;

namespace ni {
namespace tests {
namespace integration {

using ::testing::Throw;

TEST(SessionUtilitiesServiceTests, SysCfgLibraryNotPresent_EnumerateDevices_ReturnsNotFoundGrpcStatusError)
{
  nidevice_grpc::SessionRepository session_repository;
  ni::tests::utilities::SysCfgMockLibrary syscfg_mock_library;
  nidevice_grpc::DeviceEnumerator device_enumerator(&syscfg_mock_library);
  nidevice_grpc::SessionUtilitiesService service(&session_repository, &device_enumerator);
  EXPECT_CALL(syscfg_mock_library, InitializeSession)
      .WillOnce(Throw(nidevice_grpc::LibraryLoadException(nidevice_grpc::kSysCfgApiNotInstalledMessage)));

  ::grpc::ServerContext context;
  nidevice_grpc::EnumerateDevicesRequest request;
  nidevice_grpc::EnumerateDevicesResponse response;
  ::grpc::Status status = service.EnumerateDevices(&context, &request, &response);

  EXPECT_EQ(::grpc::StatusCode::NOT_FOUND, status.error_code());
  EXPECT_EQ(nidevice_grpc::kSysCfgApiNotInstalledMessage, status.error_message());
}

TEST(SessionUtilitiesServiceTests, EmptyReserveId_Reserve_ReturnsInvalidId)
{
  nidevice_grpc::SessionRepository session_repository;
  ni::tests::utilities::SysCfgMockLibrary syscfg_mock_library;
  nidevice_grpc::DeviceEnumerator device_enumerator(&syscfg_mock_library);
  nidevice_grpc::SessionUtilitiesService service(&session_repository, &device_enumerator);
  nidevice_grpc::ReserveRequest request;

  ::grpc::ServerContext context;
  nidevice_grpc::ReserveResponse response;
  ::grpc::Status status = service.Reserve(&context, &request, &response);

  EXPECT_FALSE(response.is_reserved());
  EXPECT_EQ(status.error_code(), ::grpc::INVALID_ARGUMENT);
}

TEST(SessionUtilitiesServiceTests, EmptyClientId_Reserve_ReturnsInvalidId)
{
  nidevice_grpc::SessionRepository session_repository;
  ni::tests::utilities::SysCfgMockLibrary syscfg_mock_library;
  nidevice_grpc::DeviceEnumerator device_enumerator(&syscfg_mock_library);
  nidevice_grpc::SessionUtilitiesService service(&session_repository, &device_enumerator);
  nidevice_grpc::ReserveRequest request;
  request.set_reservation_id("foo");

  ::grpc::ServerContext context;
  nidevice_grpc::ReserveResponse response;
  ::grpc::Status status = service.Reserve(&context, &request, &response);

  EXPECT_FALSE(response.is_reserved());
  EXPECT_EQ(status.error_code(), ::grpc::INVALID_ARGUMENT);
}

TEST(SessionUtilitiesServiceTests, NewReserveIdAndClientId_Reserve_ReservesSession)
{
  nidevice_grpc::SessionRepository session_repository;
  ni::tests::utilities::SysCfgMockLibrary syscfg_mock_library;
  nidevice_grpc::DeviceEnumerator device_enumerator(&syscfg_mock_library);
  nidevice_grpc::SessionUtilitiesService service(&session_repository, &device_enumerator);
  nidevice_grpc::ReserveRequest request;
  request.set_reservation_id("foo");
  request.set_client_id("a");

  ::grpc::ServerContext context;
  nidevice_grpc::ReserveResponse response;
  auto status = service.Reserve(&context, &request, &response);

  EXPECT_TRUE(response.is_reserved());
  EXPECT_EQ(status.error_code(), ::grpc::OK);
}

void call_reserve_task(
    nidevice_grpc::SessionUtilitiesService* service,
    nidevice_grpc::ReserveRequest* request,
    nidevice_grpc::ReserveResponse* response,
    ::grpc::Status* status,
    std::atomic<bool>* is_thread_started)
{
  ::grpc::ServerContext context;
  *is_thread_started = true;
  *status = service->Reserve(&context, request, response);
}

bool call_unreserve(nidevice_grpc::SessionUtilitiesService* service, std::string reservation_id, std::string client_id, ::grpc::Status& status)
{
  nidevice_grpc::UnreserveRequest unreserve_request;
  unreserve_request.set_reservation_id(reservation_id);
  unreserve_request.set_client_id(client_id);
  nidevice_grpc::UnreserveResponse unreserve_response;
  ::grpc::ServerContext context;
  status = service->Unreserve(&context, &unreserve_request, &unreserve_response);
  return unreserve_response.is_unreserved();
}

bool call_unreserve(nidevice_grpc::SessionUtilitiesService* service, std::string reservation_id, std::string client_id)
{
  ::grpc::Status status;
  return call_unreserve(service, reservation_id, client_id, status);
}

bool call_is_reserved(nidevice_grpc::SessionUtilitiesService* service, std::string reservation_id, std::string client_id, ::grpc::Status& status)
{
  nidevice_grpc::IsReservedByClientRequest is_reserved_request;
  is_reserved_request.set_reservation_id(reservation_id);
  is_reserved_request.set_client_id(client_id);
  nidevice_grpc::IsReservedByClientResponse is_reserved_response;
  ::grpc::ServerContext context;
  status = service->IsReservedByClient(&context, &is_reserved_request, &is_reserved_response);
  return is_reserved_response.is_reserved();
}

bool call_is_reserved(nidevice_grpc::SessionUtilitiesService* service, std::string reservation_id, std::string client_id)
{
  ::grpc::Status status;
  return call_is_reserved(service, reservation_id, client_id, status);
}

bool call_reserve(nidevice_grpc::SessionUtilitiesService* service, std::string reservation_id, std::string client_id, ::grpc::Status& status)
{
  nidevice_grpc::ReserveRequest reserve_request;
  reserve_request.set_reservation_id("foo");
  reserve_request.set_client_id("a");
  ::grpc::ServerContext context;
  nidevice_grpc::ReserveResponse reserve_response;
  status = service->Reserve(&context, &reserve_request, &reserve_response);
  return reserve_response.is_reserved();
}

bool call_reserve(nidevice_grpc::SessionUtilitiesService* service, std::string reservation_id, std::string client_id)
{
  ::grpc::Status status;
  return call_reserve(service, reservation_id, client_id, status);
}

void set_reserve_request(nidevice_grpc::ReserveRequest& request, const char* reservation_id, const char* client_id)
{
  request.set_reservation_id(reservation_id);
  request.set_client_id(client_id);
}

void wait_until_true(
    const std::atomic<bool>& client_one_started,
    const std::atomic<bool>& client_two_started)
{
  while (!client_one_started || !client_two_started) {
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
  }
  std::this_thread::sleep_for(std::chrono::milliseconds(5));
}

void wait_until_true(const std::atomic<bool>& client_started)
{
  const std::atomic<bool> true_atomic(true);
  wait_until_true(client_started, true_atomic);
}

TEST(SessionUtilitiesServiceTests, IdReserved_ReserveWithNewClientId_WaitsForUnreserveThenReserves)
{
  nidevice_grpc::SessionRepository session_repository;
  ni::tests::utilities::SysCfgMockLibrary syscfg_mock_library;
  nidevice_grpc::DeviceEnumerator device_enumerator(&syscfg_mock_library);
  nidevice_grpc::SessionUtilitiesService service(&session_repository, &device_enumerator);
  call_reserve(&service, "foo", "a");

  nidevice_grpc::ReserveRequest clientb_request;
  nidevice_grpc::ReserveResponse clientb_response;
  ::grpc::Status clientb_status;
  std::atomic<bool> clientb_started(false);
  set_reserve_request(clientb_request, "foo", "b");
  std::thread reserve_b(call_reserve_task, &service, &clientb_request, &clientb_response, &clientb_status, &clientb_started);
  wait_until_true(clientb_started);

  bool is_reserved = call_is_reserved(&service, "foo", "b");
  EXPECT_FALSE(clientb_response.is_reserved());
  EXPECT_FALSE(is_reserved);
  call_unreserve(&service, "foo", "a");
  reserve_b.join();
  EXPECT_TRUE(clientb_response.is_reserved());
  is_reserved = call_is_reserved(&service, "foo", "b");
  EXPECT_TRUE(is_reserved);
}

TEST(SessionUtilitiesServiceTests, IdReserved_ReserveWithNewClientIdTwice_WaitsForTwoUnreservesThenReservesLastClient)
{
  nidevice_grpc::SessionRepository session_repository;
  ni::tests::utilities::SysCfgMockLibrary syscfg_mock_library;
  nidevice_grpc::DeviceEnumerator device_enumerator(&syscfg_mock_library);
  nidevice_grpc::SessionUtilitiesService service(&session_repository, &device_enumerator);
  nidevice_grpc::ReserveRequest request;
  call_reserve(&service, "foo", "a");

  nidevice_grpc::ReserveRequest clientb_request, clientc_request;
  nidevice_grpc::ReserveResponse clientb_response, clientc_response;
  ::grpc::Status clientb_status, clientc_status;
  std::atomic<bool> clientb_started(false), clientc_started(false);
  set_reserve_request(clientb_request, "foo", "b");
  std::thread reserve_b(call_reserve_task, &service, &clientb_request, &clientb_response, &clientb_status, &clientb_started);
  wait_until_true(clientb_started);
  set_reserve_request(clientc_request, "foo", "c");
  std::thread reserve_c(call_reserve_task, &service, &clientc_request, &clientc_response, &clientc_status, &clientc_started);
  wait_until_true(clientc_started);

  EXPECT_FALSE(clientc_response.is_reserved());
  call_unreserve(&service, "foo", "a");
  reserve_b.join();
  EXPECT_FALSE(clientc_response.is_reserved());
  call_unreserve(&service, "foo", "b");
  reserve_c.join();
  EXPECT_TRUE(clientc_response.is_reserved());
  EXPECT_TRUE(call_is_reserved(&service, "foo", "c"));
}

TEST(SessionUtilitiesServiceTests, IdReserved_ReserveWithSameClientId_ReturnsReserved)
{
  nidevice_grpc::SessionRepository session_repository;
  ni::tests::utilities::SysCfgMockLibrary syscfg_mock_library;
  nidevice_grpc::DeviceEnumerator device_enumerator(&syscfg_mock_library);
  nidevice_grpc::SessionUtilitiesService service(&session_repository, &device_enumerator);
  nidevice_grpc::ReserveRequest request;
  request.set_reservation_id("foo");
  request.set_client_id("a");
  ::grpc::ServerContext context;
  nidevice_grpc::ReserveResponse response;
  service.Reserve(&context, &request, &response);

  response.set_is_reserved(false);
  service.Reserve(&context, &request, &response);

  EXPECT_TRUE(response.is_reserved());
}

TEST(SessionUtilitiesServiceTests, IdReserved_ReserveWithSameClientId_ReturnsFailedPrecondition)
{
  nidevice_grpc::SessionRepository session_repository;
  ni::tests::utilities::SysCfgMockLibrary syscfg_mock_library;
  nidevice_grpc::DeviceEnumerator device_enumerator(&syscfg_mock_library);
  nidevice_grpc::SessionUtilitiesService service(&session_repository, &device_enumerator);
  call_reserve(&service, "foo", "a");

  ::grpc::Status status;
  call_reserve(&service, "foo", "a", status);

  EXPECT_EQ(status.error_code(), ::grpc::FAILED_PRECONDITION);
}

TEST(SessionUtilitiesServiceTests, NoReservations_IsReserved_ReturnsFalse)
{
  nidevice_grpc::SessionRepository session_repository;
  ni::tests::utilities::SysCfgMockLibrary syscfg_mock_library;
  nidevice_grpc::DeviceEnumerator device_enumerator(&syscfg_mock_library);
  nidevice_grpc::SessionUtilitiesService service(&session_repository, &device_enumerator);

  bool is_reserved = call_is_reserved(&service, "foo", "a");

  EXPECT_FALSE(is_reserved);
}

TEST(SessionUtilitiesServiceTests, Reservation_IsReservedWithDifferentReservationId_ReturnsFalse)
{
  nidevice_grpc::SessionRepository session_repository;
  ni::tests::utilities::SysCfgMockLibrary syscfg_mock_library;
  nidevice_grpc::DeviceEnumerator device_enumerator(&syscfg_mock_library);
  nidevice_grpc::SessionUtilitiesService service(&session_repository, &device_enumerator);
  call_reserve(&service, "foo", "a");

  bool is_reserved = call_is_reserved(&service, "bar", "a");

  EXPECT_FALSE(is_reserved);
}

TEST(SessionUtilitiesServiceTests, Reservation_IsReservedWithDifferentClientId_ReturnsFalse)
{
  nidevice_grpc::SessionRepository session_repository;
  ni::tests::utilities::SysCfgMockLibrary syscfg_mock_library;
  nidevice_grpc::DeviceEnumerator device_enumerator(&syscfg_mock_library);
  nidevice_grpc::SessionUtilitiesService service(&session_repository, &device_enumerator);
  call_reserve(&service, "foo", "a");

  bool is_reserved = call_is_reserved(&service, "foo", "b");

  EXPECT_FALSE(is_reserved);
}

TEST(SessionUtilitiesServiceTests, Reservation_IsReservedWithSameClientId_ReturnsTrue)
{
  nidevice_grpc::SessionRepository session_repository;
  ni::tests::utilities::SysCfgMockLibrary syscfg_mock_library;
  nidevice_grpc::DeviceEnumerator device_enumerator(&syscfg_mock_library);
  nidevice_grpc::SessionUtilitiesService service(&session_repository, &device_enumerator);
  call_reserve(&service, "foo", "a");

  ::grpc::Status status;
  bool is_reserved = call_is_reserved(&service, "foo", "a", status);

  EXPECT_EQ(status.error_code(), ::grpc::OK);
  EXPECT_TRUE(is_reserved);
}

TEST(SessionUtilitiesServiceTests, NoReservations_Unreserve_ReturnsFalse)
{
  nidevice_grpc::SessionRepository session_repository;
  ni::tests::utilities::SysCfgMockLibrary syscfg_mock_library;
  nidevice_grpc::DeviceEnumerator device_enumerator(&syscfg_mock_library);
  nidevice_grpc::SessionUtilitiesService service(&session_repository, &device_enumerator);

  bool is_unreserved = call_unreserve(&service, "foo", "a");

  EXPECT_FALSE(is_unreserved);
}

TEST(SessionUtilitiesServiceTests, Reservation_UnreserveWithDifferentReservationId_ReturnsFalseAndKeepsReservation)
{
  nidevice_grpc::SessionRepository session_repository;
  ni::tests::utilities::SysCfgMockLibrary syscfg_mock_library;
  nidevice_grpc::DeviceEnumerator device_enumerator(&syscfg_mock_library);
  nidevice_grpc::SessionUtilitiesService service(&session_repository, &device_enumerator);
  nidevice_grpc::ReserveRequest reserve_request;
  call_reserve(&service, "foo", "a");

  bool is_unreserved = call_unreserve(&service, "bar", "a");

  EXPECT_FALSE(is_unreserved);
  bool is_reserved = call_is_reserved(&service, "foo", "a");
  EXPECT_TRUE(is_reserved);
}

TEST(SessionUtilitiesServiceTests, Reservation_UnreserveWithDifferentClientId_ReturnsFalseAndKeepsReservation)
{
  nidevice_grpc::SessionRepository session_repository;
  ni::tests::utilities::SysCfgMockLibrary syscfg_mock_library;
  nidevice_grpc::DeviceEnumerator device_enumerator(&syscfg_mock_library);
  nidevice_grpc::SessionUtilitiesService service(&session_repository, &device_enumerator);
  call_reserve(&service, "foo", "a");

  bool is_unreserved = call_unreserve(&service, "foo", "b");

  EXPECT_FALSE(is_unreserved);
  bool is_reserved = call_is_reserved(&service, "foo", "a");
  EXPECT_TRUE(is_reserved);
}

TEST(SessionUtilitiesServiceTests, Reservation_Unreserve_Unreserves)
{
  nidevice_grpc::SessionRepository session_repository;
  ni::tests::utilities::SysCfgMockLibrary syscfg_mock_library;
  nidevice_grpc::DeviceEnumerator device_enumerator(&syscfg_mock_library);
  nidevice_grpc::SessionUtilitiesService service(&session_repository, &device_enumerator);
  call_reserve(&service, "foo", "a");

  ::grpc::Status status;
  bool is_unreserved = call_unreserve(&service, "foo", "a", status);

  EXPECT_TRUE(is_unreserved);
  bool is_reserved = call_is_reserved(&service, "foo", "a");
  EXPECT_FALSE(is_reserved);
  EXPECT_EQ(status.error_code(), ::grpc::OK);
}

TEST(SessionUtilitiesServiceTests, Reservation_ResetServer_Unreserves)
{
  nidevice_grpc::SessionRepository session_repository;
  ni::tests::utilities::SysCfgMockLibrary syscfg_mock_library;
  nidevice_grpc::DeviceEnumerator device_enumerator(&syscfg_mock_library);
  nidevice_grpc::SessionUtilitiesService service(&session_repository, &device_enumerator);
  call_reserve(&service, "foo", "a");

  ::grpc::ServerContext context;
  nidevice_grpc::ResetServerResponse reset_response;
  auto status = service.ResetServer(&context, NULL, &reset_response);

  EXPECT_TRUE(reset_response.is_server_reset());
  EXPECT_EQ(status.error_code(), ::grpc::OK);
  bool is_reserved = call_is_reserved(&service, "foo", "a");
  EXPECT_FALSE(is_reserved);
}

TEST(SessionUtilitiesServiceTests, ReservationAndSession_ResetServer_UnreservesAndRemovesSession)
{
  nidevice_grpc::SessionRepository session_repository;
  ni::tests::utilities::SysCfgMockLibrary syscfg_mock_library;
  nidevice_grpc::DeviceEnumerator device_enumerator(&syscfg_mock_library);
  nidevice_grpc::SessionUtilitiesService service(&session_repository, &device_enumerator);
  std::string session_name = "session_name";
  uint32_t named_session_id;
  int status = session_repository.add_session(
      session_name,
      []() { return 0; },
      NULL,
      named_session_id);
  call_reserve(&service, session_name, "a");

  ::grpc::ServerContext context;
  nidevice_grpc::ResetServerResponse reset_response;
  service.ResetServer(&context, NULL, &reset_response);

  EXPECT_TRUE(reset_response.is_server_reset());
  bool is_reserved = call_is_reserved(&service, session_name, "a");
  EXPECT_FALSE(is_reserved);
  EXPECT_FALSE(session_repository.access_session(named_session_id, ""));
  EXPECT_FALSE(session_repository.access_session(0, session_name));
}

TEST(SessionUtilitiesServiceTests, TwoReservations_ResetServer_Unreserves)
{
  nidevice_grpc::SessionRepository session_repository;
  ni::tests::utilities::SysCfgMockLibrary syscfg_mock_library;
  nidevice_grpc::DeviceEnumerator device_enumerator(&syscfg_mock_library);
  nidevice_grpc::SessionUtilitiesService service(&session_repository, &device_enumerator);
  call_reserve(&service, "foo", "a");
  call_reserve(&service, "bar", "b");

  ::grpc::ServerContext context;
  nidevice_grpc::ResetServerResponse reset_response;
  service.ResetServer(&context, NULL, &reset_response);

  EXPECT_TRUE(reset_response.is_server_reset());
  bool is_a_reserved = call_is_reserved(&service, "foo", "a");
  EXPECT_FALSE(is_a_reserved);
  bool is_b_reserved = call_is_reserved(&service, "bar", "b");
  EXPECT_FALSE(is_b_reserved);
}

TEST(SessionUtilitiesServiceTests, ReservationWithClientWaiting_ResetServer_ClientReturnsAndDoesNotReserve)
{
  nidevice_grpc::SessionRepository session_repository;
  ni::tests::utilities::SysCfgMockLibrary syscfg_mock_library;
  nidevice_grpc::DeviceEnumerator device_enumerator(&syscfg_mock_library);
  nidevice_grpc::SessionUtilitiesService service(&session_repository, &device_enumerator);
  call_reserve(&service, "foo", "a");
  nidevice_grpc::ReserveRequest clientb_request;
  nidevice_grpc::ReserveResponse clientb_response;
  ::grpc::Status clientb_status;
  std::atomic<bool> clientb_started(false);
  set_reserve_request(clientb_request, "foo", "b");
  clientb_response.set_is_reserved(true);
  std::thread reserve_b(call_reserve_task, &service, &clientb_request, &clientb_response, &clientb_status, &clientb_started);
  wait_until_true(clientb_started);

  ::grpc::ServerContext context;
  nidevice_grpc::ResetServerResponse reset_response;
  service.ResetServer(&context, NULL, &reset_response);

  EXPECT_TRUE(reset_response.is_server_reset());
  reserve_b.join();
  EXPECT_FALSE(clientb_response.is_reserved());
  bool is_reserved = call_is_reserved(&service, "foo", "b");
  EXPECT_FALSE(is_reserved);
}

TEST(SessionUtilitiesServiceTests, ReservationWithMultipleClientsWaiting_ResetServer_AllClientsReturnAndDoNotReserve)
{
  nidevice_grpc::SessionRepository session_repository;
  ni::tests::utilities::SysCfgMockLibrary syscfg_mock_library;
  nidevice_grpc::DeviceEnumerator device_enumerator(&syscfg_mock_library);
  nidevice_grpc::SessionUtilitiesService service(&session_repository, &device_enumerator);
  nidevice_grpc::ReserveRequest clientb_request, clientc_request;
  nidevice_grpc::ReserveResponse clientb_response, clientc_response;
  ::grpc::Status clientb_status, clientc_status;
  std::atomic<bool> clientb_started(false), clientc_started(false);
  call_reserve(&service, "foo", "a");
  set_reserve_request(clientb_request, "foo", "b");
  clientb_response.set_is_reserved(true);
  std::thread reserve_b(call_reserve_task, &service, &clientb_request, &clientb_response, &clientb_status, &clientb_started);
  set_reserve_request(clientc_request, "foo", "c");
  clientc_response.set_is_reserved(true);
  std::thread reserve_c(call_reserve_task, &service, &clientc_request, &clientc_response, &clientc_status, &clientc_started);
  wait_until_true(clientb_started, clientc_started);

  ::grpc::ServerContext context;
  nidevice_grpc::ResetServerResponse reset_response;
  service.ResetServer(&context, NULL, &reset_response);

  EXPECT_TRUE(reset_response.is_server_reset());
  reserve_b.join();
  EXPECT_FALSE(clientb_response.is_reserved());
  reserve_c.join();
  EXPECT_FALSE(clientc_response.is_reserved());
  bool is_reserved = call_is_reserved(&service, "foo", "b");
  EXPECT_FALSE(is_reserved);
  is_reserved = call_is_reserved(&service, "foo", "c");
  EXPECT_FALSE(is_reserved);
}

TEST(SessionUtilitiesServiceTests, ReservationWithClientWaiting_ResetServer_WaitingClientReturnsAborted)
{
  nidevice_grpc::SessionRepository session_repository;
  ni::tests::utilities::SysCfgMockLibrary syscfg_mock_library;
  nidevice_grpc::DeviceEnumerator device_enumerator(&syscfg_mock_library);
  nidevice_grpc::SessionUtilitiesService service(&session_repository, &device_enumerator);
  call_reserve(&service, "foo", "a");
  nidevice_grpc::ReserveRequest clientb_request;
  nidevice_grpc::ReserveResponse clientb_response;
  ::grpc::Status clientb_status;
  std::atomic<bool> clientb_started(false);
  set_reserve_request(clientb_request, "foo", "b");
  clientb_response.set_is_reserved(true);
  std::thread reserve_b(call_reserve_task, &service, &clientb_request, &clientb_response, &clientb_status, &clientb_started);
  wait_until_true(clientb_started);

  ::grpc::ServerContext context;
  nidevice_grpc::ResetServerResponse reset_response;
  service.ResetServer(&context, NULL, &reset_response);

  reserve_b.join();
  EXPECT_FALSE(clientb_response.is_reserved());
  EXPECT_EQ(::grpc::ABORTED, clientb_status.error_code());
}

TEST(SessionUtilitiesServiceTests, ReservationWithMultipleClientsWaiting_ResetServer_AllClientsReturnAborted)
{
  nidevice_grpc::SessionRepository session_repository;
  ni::tests::utilities::SysCfgMockLibrary syscfg_mock_library;
  nidevice_grpc::DeviceEnumerator device_enumerator(&syscfg_mock_library);
  nidevice_grpc::SessionUtilitiesService service(&session_repository, &device_enumerator);
  nidevice_grpc::ReserveRequest clientb_request, clientc_request;
  nidevice_grpc::ReserveResponse clientb_response, clientc_response;
  ::grpc::Status clientb_status, clientc_status;
  std::atomic<bool> clientb_started(false), clientc_started(false);
  call_reserve(&service, "foo", "a");
  set_reserve_request(clientb_request, "foo", "b");
  clientb_response.set_is_reserved(true);
  std::thread reserve_b(call_reserve_task, &service, &clientb_request, &clientb_response, &clientb_status, &clientb_started);
  set_reserve_request(clientc_request, "foo", "c");
  clientc_response.set_is_reserved(true);
  std::thread reserve_c(call_reserve_task, &service, &clientc_request, &clientc_response, &clientc_status, &clientc_started);
  wait_until_true(clientb_started, clientc_started);

  ::grpc::ServerContext context;
  nidevice_grpc::ResetServerResponse reset_response;
  service.ResetServer(&context, NULL, &reset_response);

  reserve_b.join();
  EXPECT_FALSE(clientb_response.is_reserved());
  EXPECT_EQ(clientb_status.error_code(), ::grpc::ABORTED);
  reserve_c.join();
  EXPECT_FALSE(clientc_response.is_reserved());
  EXPECT_EQ(clientc_status.error_code(), ::grpc::ABORTED);
}

TEST(SessionUtilitiesServiceTests, SysCfgLibraryPresent_ClearSysCfgSession_IsSessionOpenReturnsFalse)
{
  nidevice_grpc::SessionRepository session_repository;
  ni::tests::utilities::SysCfgMockLibrary syscfg_mock_library;
  nidevice_grpc::DeviceEnumerator device_enumerator(&syscfg_mock_library);
  nidevice_grpc::SessionUtilitiesService service(&session_repository, &device_enumerator);
  ::grpc::ServerContext context;
  nidevice_grpc::EnumerateDevicesRequest request;
  nidevice_grpc::EnumerateDevicesResponse response;
  ::grpc::Status status = service.EnumerateDevices(&context, &request, &response);

  device_enumerator.clear_syscfg_session();

  EXPECT_FALSE(device_enumerator.is_session_open());
}

}  // namespace integration
}  // namespace tests
}  // namespace ni
