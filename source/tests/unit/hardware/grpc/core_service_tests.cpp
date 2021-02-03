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
      service.Reserve(&context, &request, &response);

      EXPECT_EQ(response.status(), ni::hardware::grpc::ReserveResponse_ReserveStatus_INVALID_ID);
   }

   TEST(CoreServiceTests, EmptyClientId_Reserve_ReturnsInvalidId)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      ni::hardware::grpc::ReserveRequest request;
      request.set_reservation_id("foo");

      ::grpc::ServerContext context;
      ni::hardware::grpc::ReserveResponse response;
      service.Reserve(&context, &request, &response);

      EXPECT_EQ(response.status(), ni::hardware::grpc::ReserveResponse_ReserveStatus_INVALID_ID);
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

      EXPECT_EQ(response.status(), ni::hardware::grpc::ReserveResponse_ReserveStatus_RESERVED);
   }

   void task(ni::hardware::grpc::CoreService* service, ni::hardware::grpc::ReserveRequest* request, ni::hardware::grpc::ReserveResponse* response)
   {
      ::grpc::ServerContext context;
      service->Reserve(&context, request, response);
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
      response.set_status(ni::hardware::grpc::ReserveResponse_ReserveStatus_NONE);
      std::thread res(task, &service, &request, &response);

      EXPECT_EQ(response.status(), ni::hardware::grpc::ReserveResponse_ReserveStatus_NONE);
      ni::hardware::grpc::UnreserveRequest unreserve_request;
      unreserve_request.set_reservation_id("foo");
      unreserve_request.set_client_id("a");
      ni::hardware::grpc::UnreserveResponse unreserve_response;
      service.Unreserve(&context, &unreserve_request, &unreserve_response);
      res.join();
      EXPECT_EQ(response.status(), ni::hardware::grpc::ReserveResponse_ReserveStatus_RESERVED);
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

      response.set_status(ni::hardware::grpc::ReserveResponse_ReserveStatus_NONE);
      service.Reserve(&context, &request, &response);

      EXPECT_EQ(response.status(), ni::hardware::grpc::ReserveResponse_ReserveStatus_RESERVED);
   }

   TEST(CoreServiceTests, NoReservations_IsReserved_ReturnsFalse)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      ni::hardware::grpc::IsReservedByClientRequest request;
      request.set_reservation_id("foo");
      request.set_client_id("a");

      ::grpc::ServerContext context;
      ni::hardware::grpc::IsReservedByClientResponse response;
      service.IsReservedByClient(&context, &request, &response);

      EXPECT_FALSE(response.is_reserved());
   }

   TEST(CoreServiceTests, Reservation_IsReservedWithDifferentReservationId_ReturnsFalse)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      ni::hardware::grpc::ReserveRequest reserve_request;
      reserve_request.set_reservation_id("foo");
      reserve_request.set_client_id("a");
      ::grpc::ServerContext context;
      ni::hardware::grpc::ReserveResponse reserve_response;
      service.Reserve(&context, &reserve_request, &reserve_response);

      ni::hardware::grpc::IsReservedByClientRequest request;
      request.set_reservation_id("bar");
      request.set_client_id("a");
      ni::hardware::grpc::IsReservedByClientResponse response;
      service.IsReservedByClient(&context, &request, &response);

      EXPECT_FALSE(response.is_reserved());
   }

   TEST(CoreServiceTests, Reservation_IsReservedWithDifferentClientId_ReturnsFalse)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      ni::hardware::grpc::ReserveRequest reserve_request;
      reserve_request.set_reservation_id("foo");
      reserve_request.set_client_id("a");
      ::grpc::ServerContext context;
      ni::hardware::grpc::ReserveResponse reserve_response;
      service.Reserve(&context, &reserve_request, &reserve_response);

      ni::hardware::grpc::IsReservedByClientRequest request;
      request.set_reservation_id("foo");
      request.set_client_id("b");
      ni::hardware::grpc::IsReservedByClientResponse response;
      service.IsReservedByClient(&context, &request, &response);

      EXPECT_FALSE(response.is_reserved());
   }

   TEST(CoreServiceTests, Reservation_IsReservedWithSameClientId_ReturnsTrue)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      ni::hardware::grpc::ReserveRequest reserve_request;
      reserve_request.set_reservation_id("foo");
      reserve_request.set_client_id("a");
      ::grpc::ServerContext context;
      ni::hardware::grpc::ReserveResponse reserve_response;
      service.Reserve(&context, &reserve_request, &reserve_response);

      ni::hardware::grpc::IsReservedByClientRequest request;
      request.set_reservation_id("foo");
      request.set_client_id("a");
      ni::hardware::grpc::IsReservedByClientResponse response;
      service.IsReservedByClient(&context, &request, &response);

      EXPECT_TRUE(response.is_reserved());
   }

   TEST(CoreServiceTests, NoReservations_Unreserve_ReturnsFalse)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      ni::hardware::grpc::UnreserveRequest request;
      request.set_reservation_id("foo");
      request.set_client_id("a");

      ::grpc::ServerContext context;
      ni::hardware::grpc::UnreserveResponse response;
      service.Unreserve(&context, &request, &response);

      EXPECT_FALSE(response.is_unreserved());
   }

   TEST(CoreServiceTests, Reservation_UnreserveWithDifferentReservationId_ReturnsFalseAndKeepsReservation)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      ni::hardware::grpc::ReserveRequest reserve_request;
      reserve_request.set_reservation_id("foo");
      reserve_request.set_client_id("a");
      ::grpc::ServerContext context;
      ni::hardware::grpc::ReserveResponse reserve_response;
      service.Reserve(&context, &reserve_request, &reserve_response);

      ni::hardware::grpc::UnreserveRequest request;
      request.set_reservation_id("bar");
      request.set_client_id("a");
      ni::hardware::grpc::UnreserveResponse response;
      service.Unreserve(&context, &request, &response);

      EXPECT_FALSE(response.is_unreserved());
      ni::hardware::grpc::IsReservedByClientRequest is_reserved_request;
      is_reserved_request.set_reservation_id("foo");
      is_reserved_request.set_client_id("a");
      ni::hardware::grpc::IsReservedByClientResponse is_reserved_response;
      service.IsReservedByClient(&context, &is_reserved_request, &is_reserved_response);
      EXPECT_TRUE(is_reserved_response.is_reserved());
   }

   TEST(CoreServiceTests, Reservation_UnreserveWithDifferentClientId_ReturnsFalseAndKeepsReservation)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      ni::hardware::grpc::ReserveRequest reserve_request;
      reserve_request.set_reservation_id("foo");
      reserve_request.set_client_id("a");
      ::grpc::ServerContext context;
      ni::hardware::grpc::ReserveResponse reserve_response;
      service.Reserve(&context, &reserve_request, &reserve_response);

      ni::hardware::grpc::UnreserveRequest request;
      request.set_reservation_id("foo");
      request.set_client_id("b");
      ni::hardware::grpc::UnreserveResponse response;
      service.Unreserve(&context, &request, &response);

      EXPECT_FALSE(response.is_unreserved());
      ni::hardware::grpc::IsReservedByClientRequest is_reserved_request;
      is_reserved_request.set_reservation_id("foo");
      is_reserved_request.set_client_id("a");
      ni::hardware::grpc::IsReservedByClientResponse is_reserved_response;
      service.IsReservedByClient(&context, &is_reserved_request, &is_reserved_response);
      EXPECT_TRUE(is_reserved_response.is_reserved());
   }

   TEST(CoreServiceTests, Reservation_Unreserve_Unreserves)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      ni::hardware::grpc::ReserveRequest reserve_request;
      reserve_request.set_reservation_id("foo");
      reserve_request.set_client_id("a");
      ::grpc::ServerContext context;
      ni::hardware::grpc::ReserveResponse reserve_response;
      service.Reserve(&context, &reserve_request, &reserve_response);

      ni::hardware::grpc::UnreserveRequest request;
      request.set_reservation_id("foo");
      request.set_client_id("a");
      ni::hardware::grpc::UnreserveResponse response;
      service.Unreserve(&context, &request, &response);

      EXPECT_TRUE(response.is_unreserved());
      ni::hardware::grpc::IsReservedByClientRequest is_reserved_request;
      is_reserved_request.set_reservation_id("foo");
      is_reserved_request.set_client_id("a");
      ni::hardware::grpc::IsReservedByClientResponse is_reserved_response;
      service.IsReservedByClient(&context, &is_reserved_request, &is_reserved_response);
      EXPECT_FALSE(is_reserved_response.is_reserved());
   }
} // namespace grpc
} // namespace hardware
} // namespace unit
} // namespace tests
} // namespace ni
