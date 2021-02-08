#include <grpcpp/impl/grpc_library.h>
#include <gtest/gtest.h>
#include <thread>
#include "hardware/grpc/core_service.h"
#include "hardware/grpc/internal/semaphore.h"
#include "hardware/grpc/internal/session_repository.h"

// fixes seg faults caused by https://github.com/grpc/grpc/issues/14633
static grpc::internal::GrpcLibraryInitializer g_gli_initializer;

namespace ni
{
namespace tests
{
namespace unit
{
namespace hardware
{
namespace grpc
{
   TEST(CoreServiceTests, EmptyReserveId_Reserve_ReturnsInvalidId)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      ni::hardware::grpc::ReserveRequest request;

      ::grpc::ServerContext context;
      ni::hardware::grpc::ReserveResponse response;
      ::grpc::Status status = service.Reserve(&context, &request, &response);

      EXPECT_FALSE(response.is_reserved());
      EXPECT_EQ(status.error_code(), ::grpc::INVALID_ARGUMENT);
   }

   TEST(CoreServiceTests, EmptyClientId_Reserve_ReturnsInvalidId)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      ni::hardware::grpc::ReserveRequest request;
      request.set_reservation_id("foo");

      ::grpc::ServerContext context;
      ni::hardware::grpc::ReserveResponse response;
      ::grpc::Status status = service.Reserve(&context, &request, &response);

      EXPECT_FALSE(response.is_reserved());
      EXPECT_EQ(status.error_code(), ::grpc::INVALID_ARGUMENT);
   }

   TEST(CoreServiceTests, NewReserveIdAndClientId_Reserve_ReservesSession)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      ni::hardware::grpc::ReserveRequest request;
      request.set_reservation_id("foo");
      request.set_client_id("a");

      ::grpc::ServerContext context;
      ni::hardware::grpc::ReserveResponse response;
      service.Reserve(&context, &request, &response);

      EXPECT_TRUE(response.is_reserved());
   }

   void call_reserve_task(ni::hardware::grpc::CoreService* service, ni::hardware::grpc::ReserveRequest* request, ni::hardware::grpc::ReserveResponse* response)
   {
      ::grpc::ServerContext context;
      service->Reserve(&context, request, response);
   }

   bool call_unreserve(ni::hardware::grpc::CoreService* service, std::string reservation_id, std::string client_id)
   {
      ni::hardware::grpc::UnreserveRequest unreserve_request;
      unreserve_request.set_reservation_id(reservation_id);
      unreserve_request.set_client_id(client_id);
      ni::hardware::grpc::UnreserveResponse unreserve_response;
      ::grpc::ServerContext context;
      service->Unreserve(&context, &unreserve_request, &unreserve_response);
      return unreserve_response.is_unreserved();
   }

   bool call_is_reserved(ni::hardware::grpc::CoreService* service, std::string reservation_id, std::string client_id)
   {
      ni::hardware::grpc::IsReservedByClientRequest is_reserved_request;
      is_reserved_request.set_reservation_id(reservation_id);
      is_reserved_request.set_client_id(client_id);
      ni::hardware::grpc::IsReservedByClientResponse is_reserved_response;
      ::grpc::ServerContext context;
      service->IsReservedByClient(&context, &is_reserved_request, &is_reserved_response);
      return is_reserved_response.is_reserved();
   }

   bool call_reserve(ni::hardware::grpc::CoreService* service, std::string reservation_id, std::string client_id)
   {
      ni::hardware::grpc::ReserveRequest reserve_request;
      reserve_request.set_reservation_id("foo");
      reserve_request.set_client_id("a");
      ::grpc::ServerContext context;
      ni::hardware::grpc::ReserveResponse reserve_response;
      service->Reserve(&context, &reserve_request, &reserve_response);
      return reserve_response.is_reserved();
   }
   
   TEST(CoreServiceTests, IdReserved_ReserveWithNewClientId_WaitsForUnreserveThenReserves)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      ni::hardware::grpc::ReserveRequest request;
      request.set_reservation_id("foo");
      request.set_client_id("a");
      ::grpc::ServerContext context;
      ni::hardware::grpc::ReserveResponse response;
      service.Reserve(&context, &request, &response);

      request.set_client_id("b");
      response.set_is_reserved(false);
      std::thread reserve_b(call_reserve_task, &service, &request, &response);
      std::this_thread::sleep_for(std::chrono::milliseconds(1));

      EXPECT_FALSE(response.is_reserved());
      call_unreserve(&service, "foo", "a");
      reserve_b.join();
      EXPECT_TRUE(response.is_reserved());
      bool is_reserved = call_is_reserved(&service, "foo", "b");
      EXPECT_TRUE(is_reserved);
   }

   TEST(CoreServiceTests, IdReserved_ReserveWithNewClientIdTwice_WaitsForTwoUnreservesThenReservesLastClient)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      ni::hardware::grpc::ReserveRequest request;
      request.set_reservation_id("foo");
      request.set_client_id("a");
      ::grpc::ServerContext context;
      ni::hardware::grpc::ReserveResponse response;
      service.Reserve(&context, &request, &response);

      ni::hardware::grpc::ReserveRequest request_b;
      request_b.set_reservation_id("foo");
      request_b.set_client_id("b");
      std::thread reserve_b(call_reserve_task, &service, &request_b, &response);
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
      ni::hardware::grpc::ReserveRequest request_c;
      request_c.set_reservation_id("foo");
      request_c.set_client_id("c");
      ni::hardware::grpc::ReserveResponse response_c;
      std::thread reserve_c(call_reserve_task, &service, &request_c, &response_c);
      std::this_thread::sleep_for(std::chrono::milliseconds(1));

      EXPECT_FALSE(response_c.is_reserved());
      call_unreserve(&service, "foo", "a");
      reserve_b.join();
      EXPECT_FALSE(response_c.is_reserved());
      call_unreserve(&service, "foo", "b");
      reserve_c.join();
      EXPECT_TRUE(response_c.is_reserved());
      EXPECT_TRUE(call_is_reserved(&service, "foo", "c"));
   }

   TEST(CoreServiceTests, IdReserved_ReserveWithSameClientId_ReturnsReserved)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      ni::hardware::grpc::ReserveRequest request;
      request.set_reservation_id("foo");
      request.set_client_id("a");
      ::grpc::ServerContext context;
      ni::hardware::grpc::ReserveResponse response;
      service.Reserve(&context, &request, &response);

      response.set_is_reserved(false);
      service.Reserve(&context, &request, &response);

      EXPECT_TRUE(response.is_reserved());
   }

   TEST(CoreServiceTests, NoReservations_IsReserved_ReturnsFalse)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);

      bool is_reserved = call_is_reserved(&service, "foo", "a");

      EXPECT_FALSE(is_reserved);
   }

   TEST(CoreServiceTests, Reservation_IsReservedWithDifferentReservationId_ReturnsFalse)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      call_reserve(&service, "foo", "a");

      bool is_reserved = call_is_reserved(&service, "bar", "a");

      EXPECT_FALSE(is_reserved);
   }

   TEST(CoreServiceTests, Reservation_IsReservedWithDifferentClientId_ReturnsFalse)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      call_reserve(&service, "foo", "a");

      bool is_reserved = call_is_reserved(&service, "foo", "b");

      EXPECT_FALSE(is_reserved);
   }

   TEST(CoreServiceTests, Reservation_IsReservedWithSameClientId_ReturnsTrue)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      call_reserve(&service, "foo", "a");

      bool is_reserved = call_is_reserved(&service, "foo", "a");

      EXPECT_TRUE(is_reserved);
   }

   TEST(CoreServiceTests, NoReservations_Unreserve_ReturnsFalse)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);

      bool is_unreserved = call_unreserve(&service, "foo", "a");

      EXPECT_FALSE(is_unreserved);
   }

   TEST(CoreServiceTests, Reservation_UnreserveWithDifferentReservationId_ReturnsFalseAndKeepsReservation)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      ni::hardware::grpc::ReserveRequest reserve_request;
      call_reserve(&service, "foo", "a");

      bool is_unreserved = call_unreserve(&service, "bar", "a");

      EXPECT_FALSE(is_unreserved);
      bool is_reserved = call_is_reserved(&service, "foo", "a");
      EXPECT_TRUE(is_reserved);
   }

   TEST(CoreServiceTests, Reservation_UnreserveWithDifferentClientId_ReturnsFalseAndKeepsReservation)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      call_reserve(&service, "foo", "a");

      bool is_unreserved = call_unreserve(&service, "foo", "b");

      EXPECT_FALSE(is_unreserved);
      bool is_reserved = call_is_reserved(&service, "foo", "a");
      EXPECT_TRUE(is_reserved);
   }

   TEST(CoreServiceTests, Reservation_Unreserve_Unreserves)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      call_reserve(&service, "foo", "a");

      bool is_unreserved = call_unreserve(&service, "foo", "a");

      EXPECT_TRUE(is_unreserved);
      bool is_reserved = call_is_reserved(&service, "foo", "a");
      EXPECT_FALSE(is_reserved);
   }
   
   TEST(CoreServiceTests, Reservation_ResetServer_Unreserves)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      call_reserve(&service, "foo", "a");

      ::grpc::ServerContext context;
      ni::hardware::grpc::ResetServerResponse reset_response;
      service.ResetServer(&context, NULL, &reset_response);

      EXPECT_TRUE(reset_response.is_server_reset());
      bool is_reserved = call_is_reserved(&service, "foo", "a");
      EXPECT_FALSE(is_reserved);
   }
   
   TEST(CoreServiceTests, TwoReservations_ResetServer_Unreserves)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      call_reserve(&service, "foo", "a");
      call_reserve(&service, "bar", "b");

      ::grpc::ServerContext context;
      ni::hardware::grpc::ResetServerResponse reset_response;
      service.ResetServer(&context, NULL, &reset_response);

      EXPECT_TRUE(reset_response.is_server_reset());
      bool is_a_reserved = call_is_reserved(&service, "foo", "a");
      EXPECT_FALSE(is_a_reserved);
      bool is_b_reserved = call_is_reserved(&service, "bar", "b");
      EXPECT_FALSE(is_b_reserved);
   }
   
   TEST(CoreServiceTests, IdReserved_ReserveWithNewClientIdAndResetServer_WaitsForResetAndDoesNotReserve)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      ni::hardware::grpc::ReserveRequest request;
      request.set_reservation_id("foo");
      request.set_client_id("a");
      ::grpc::ServerContext context;
      ni::hardware::grpc::ReserveResponse response;
      service.Reserve(&context, &request, &response);

      bool is_reserved = call_is_reserved(&service, "foo", "a");
      EXPECT_TRUE(is_reserved);
      request.set_client_id("b");
      response.set_is_reserved(false);
      std::thread reserve_b(call_reserve_task, &service, &request, &response);
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
      EXPECT_FALSE(response.is_reserved());
      is_reserved = call_is_reserved(&service, "foo", "b");
      EXPECT_FALSE(is_reserved);

      ni::hardware::grpc::ResetServerResponse reset_response;
      service.ResetServer(&context, NULL, &reset_response);
      
      EXPECT_TRUE(reset_response.is_server_reset());
      reserve_b.join();
      EXPECT_FALSE(response.is_reserved());
      is_reserved = call_is_reserved(&service, "foo", "b");
      EXPECT_FALSE(is_reserved);
   }
} // namespace grpc
} // namespace hardware
} // namespace unit
} // namespace tests
} // namespace ni
