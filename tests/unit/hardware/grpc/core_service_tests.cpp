#include <grpcpp/impl/grpc_library.h>
#include <gtest/gtest.h>
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
   TEST(CoreServiceTests, SessionAdded_ReserveWithNewClientName_ReservesSession)
   {
      auto session_repository = ni::hardware::grpc::internal::SessionRepository();
      ni::hardware::grpc::CoreService service = ni::hardware::grpc::CoreService(&session_repository);
      auto session = session_repository.add_session(ni::hardware::grpc::ViSession(), "session_name", NULL);
      auto request = new ni::hardware::grpc::ReserveRequest;
      request->set_allocated_session(session);
      request->set_client_reserve_id("new_client_name");

      ::grpc::ServerContext context;
      auto response = new ni::hardware::grpc::ReserveResponse;
      service.Reserve(&context, request, response);

      EXPECT_EQ(response->status(), ni::hardware::grpc::ReserveResponse_ReserveStatus_RESERVED);
      session_repository.remove_session(*session);
   }

   TEST(CoreServiceTests, NoSession_ReserveWithNewClientName_InvalidSession)
   {
      ni::hardware::grpc::CoreService service = ni::hardware::grpc::CoreService();
      auto request = new ni::hardware::grpc::ReserveRequest;
      request->set_client_reserve_id("new_client_name");

      ::grpc::ServerContext context;
      auto response = new ni::hardware::grpc::ReserveResponse;
      service.Reserve(&context, request, response);

      EXPECT_EQ(response->status(), ni::hardware::grpc::ReserveResponse_ReserveStatus_INVALID_SESSION);
   }

   TEST(CoreServiceTests, AddSession_ReserveWithSameClientName_ReservesSession)
   {
      auto session_name = std::string("session_name");
      auto session_repository = ni::hardware::grpc::internal::SessionRepository();
      ni::hardware::grpc::CoreService service = ni::hardware::grpc::CoreService(&session_repository);
      auto session = session_repository.add_session(ni::hardware::grpc::ViSession(), session_name, NULL);
      auto request = new ni::hardware::grpc::ReserveRequest;
      request->set_allocated_client_reserve_id(&session_name);
      request->set_client_reserve_id(session_name);

      ::grpc::ServerContext context;
      auto response = new ni::hardware::grpc::ReserveResponse;
      service.Reserve(&context, request, response);

      EXPECT_EQ(response->status(), ni::hardware::grpc::ReserveResponse_ReserveStatus_INVALID_SESSION);
      session_repository.remove_session(*session);
   }

   TEST(CoreServiceTests, UnusedSessionName_IsReserved_ReturnsFalse)
   {
      ni::hardware::grpc::CoreService service = ni::hardware::grpc::CoreService();
      auto request = new ni::hardware::grpc::IsReservedByClientRequest;
      request->set_client_reserve_id("unused id");

      ::grpc::ServerContext context;
      auto response = new ni::hardware::grpc::IsReservedByClientResponse;
      service.IsReservedByClient(&context, request, response);

      EXPECT_FALSE(response->is_reserved());
   }

   TEST(CoreServiceTests, ReserveSession_IsReserved_ReturnsTrue)
   {
      auto reserve_id = std::string("session_name");
      auto session_repository = ni::hardware::grpc::internal::SessionRepository();
      ni::hardware::grpc::CoreService service = ni::hardware::grpc::CoreService(&session_repository);
      auto session = session_repository.add_session(ni::hardware::grpc::ViSession(), "session_name", NULL);
      auto reserveRequest = new ni::hardware::grpc::ReserveRequest;
      reserveRequest->set_allocated_session(session);
      reserveRequest->set_client_reserve_id(reserve_id);
      ::grpc::ServerContext context;
      service.Reserve(&context, reserveRequest, new ni::hardware::grpc::ReserveResponse);

      auto request = new ni::hardware::grpc::IsReservedByClientRequest;
      request->set_client_reserve_id(reserve_id);
      auto response = new ni::hardware::grpc::IsReservedByClientResponse;
      service.IsReservedByClient(&context, request, response);

      EXPECT_TRUE(response->is_reserved());
      session_repository.remove_session(*session);
   }

   TEST(CoreServiceTests, ReserveAndUnreserveSession_IsReserved_ReturnsFalse)
   {
      auto reserve_id = std::string("session_name");
      auto session_repository = ni::hardware::grpc::internal::SessionRepository();
      ni::hardware::grpc::CoreService service = ni::hardware::grpc::CoreService(&session_repository);
      auto session = session_repository.add_session(ni::hardware::grpc::ViSession(), "session_name", NULL);
      auto reserveRequest = new ni::hardware::grpc::ReserveRequest;
      reserveRequest->set_allocated_session(session);
      reserveRequest->set_client_reserve_id(reserve_id);
      ::grpc::ServerContext context;
      service.Reserve(&context, reserveRequest, new ni::hardware::grpc::ReserveResponse);
      auto unreserveRequest = new ni::hardware::grpc::UnreserveRequest;
      unreserveRequest->set_client_reserve_id(reserve_id);
      service.Unreserve(&context, unreserveRequest, new ni::hardware::grpc::UnreserveResponse);

      auto request = new ni::hardware::grpc::IsReservedByClientRequest;
      request->set_client_reserve_id(reserve_id);
      auto response = new ni::hardware::grpc::IsReservedByClientResponse;
      service.IsReservedByClient(&context, request, response);

      EXPECT_FALSE(response->is_reserved());
      session_repository.remove_session(*session);
   }

   TEST(CoreServiceTests, NoSession_Unreserve_DoesNotUnreserve)
   {
      ni::hardware::grpc::CoreService service = ni::hardware::grpc::CoreService();

      ::grpc::ServerContext context;
      auto request = new ni::hardware::grpc::UnreserveRequest;
      request->set_client_reserve_id("userId");
      auto response = new ni::hardware::grpc::UnreserveResponse;
      service.Unreserve(&context, request, response);

      EXPECT_FALSE(response->is_unreserved());
   }

   TEST(CoreServiceTests, ReserveSession_Unreserve_UnreservesSession)
   {
      auto reserve_id = std::string("session_name");
      auto session_repository = ni::hardware::grpc::internal::SessionRepository();
      ni::hardware::grpc::CoreService service = ni::hardware::grpc::CoreService(&session_repository);
      auto session = session_repository.add_session(ni::hardware::grpc::ViSession(), "session_name", NULL);
      auto reserveRequest = new ni::hardware::grpc::ReserveRequest;
      reserveRequest->set_allocated_session(session);
      reserveRequest->set_client_reserve_id(reserve_id);
      ::grpc::ServerContext context;
      service.Reserve(&context, reserveRequest, new ni::hardware::grpc::ReserveResponse);

      auto request = new ni::hardware::grpc::UnreserveRequest;
      request->set_client_reserve_id(reserve_id);
      auto response = new ni::hardware::grpc::UnreserveResponse;
      service.Unreserve(&context, request, response);

      EXPECT_TRUE(response->is_unreserved());
      session_repository.remove_session(*session);
   }
} // namespace grpc
} // namespace hardware
} // namespace unit
} // namespace tests
} // namespace ni
