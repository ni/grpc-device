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
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      auto session = session_repository.add_session(ni::hardware::grpc::ViSession(), "session_name", nullptr);
      ni::hardware::grpc::ReserveRequest request;
      request.set_allocated_session(session);
      request.set_client_reserve_id("new_client_name");

      ::grpc::ServerContext context;
      ni::hardware::grpc::ReserveResponse response;
      service.Reserve(&context, &request, &response);

      EXPECT_EQ(response.status(), ni::hardware::grpc::ReserveResponse_ReserveStatus_RESERVED);
      session_repository.remove_session(*session);
   }

   TEST(CoreServiceTests, NoSession_ReserveWithNewClientName_InvalidSession)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      ni::hardware::grpc::ReserveRequest request;
      request.set_client_reserve_id("new_client_name");

      ::grpc::ServerContext context;
      ni::hardware::grpc::ReserveResponse response;
      service.Reserve(&context, &request, &response);

      EXPECT_EQ(response.status(), ni::hardware::grpc::ReserveResponse_ReserveStatus_INVALID_SESSION);
   }

   TEST(CoreServiceTests, AddSession_ReserveWithSameClientName_ReservesSession)
   {
      std::string session_name("session_name");
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      auto session = session_repository.add_session(ni::hardware::grpc::ViSession(), session_name, nullptr);
      ni::hardware::grpc::ReserveRequest request;
      request.set_client_reserve_id(session_name);

      ::grpc::ServerContext context;
      ni::hardware::grpc::ReserveResponse response;
      service.Reserve(&context, &request, &response);

      EXPECT_EQ(response.status(), ni::hardware::grpc::ReserveResponse_ReserveStatus_INVALID_SESSION);
      session_repository.remove_session(*session);
   }

   TEST(CoreServiceTests, UnusedSessionName_IsReserved_ReturnsFalse)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      ni::hardware::grpc::IsReservedByClientRequest request;
      request.set_client_reserve_id("unused id");

      ::grpc::ServerContext context;
      ni::hardware::grpc::IsReservedByClientResponse response;
      service.IsReservedByClient(&context, &request, &response);

      EXPECT_FALSE(response.is_reserved());
   }

   TEST(CoreServiceTests, ReserveSession_IsReserved_ReturnsTrue)
   {
      std::string reserve_id("session_name");
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      auto session = session_repository.add_session(ni::hardware::grpc::ViSession(), "session_name", nullptr);
      ni::hardware::grpc::ReserveRequest reserveRequest;
      reserveRequest.set_allocated_session(session);
      reserveRequest.set_client_reserve_id(reserve_id);
      ::grpc::ServerContext context;
      ni::hardware::grpc::ReserveResponse reserve_response;
      service.Reserve(&context, &reserveRequest, &reserve_response);

      ni::hardware::grpc::IsReservedByClientRequest request;
      request.set_client_reserve_id(reserve_id);
      ni::hardware::grpc::IsReservedByClientResponse response;
      service.IsReservedByClient(&context, &request, &response);

      EXPECT_TRUE(response.is_reserved());
      session_repository.remove_session(*session);
   }

   TEST(CoreServiceTests, ReserveAndUnreserveSession_IsReserved_ReturnsFalse)
   {
      std::string reserve_id("session_name");
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      auto session = session_repository.add_session(ni::hardware::grpc::ViSession(), "session_name", nullptr);
      ni::hardware::grpc::ReserveRequest reserveRequest;
      reserveRequest.set_allocated_session(session);
      reserveRequest.set_client_reserve_id(reserve_id);
      ::grpc::ServerContext context;
      ni::hardware::grpc::ReserveResponse reserve_response;
      service.Reserve(&context, &reserveRequest, &reserve_response);
      ni::hardware::grpc::UnreserveRequest unreserveRequest;
      unreserveRequest.set_client_reserve_id(reserve_id);
      ni::hardware::grpc::UnreserveResponse unreserve_response;
      service.Unreserve(&context, &unreserveRequest, &unreserve_response);

      ni::hardware::grpc::IsReservedByClientRequest request;
      request.set_client_reserve_id(reserve_id);
      ni::hardware::grpc::IsReservedByClientResponse response;
      service.IsReservedByClient(&context, &request, &response);

      EXPECT_FALSE(response.is_reserved());
      session_repository.remove_session(*session);
   }

   TEST(CoreServiceTests, NoSession_Unreserve_DoesNotUnreserve)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);

      ::grpc::ServerContext context;
      ni::hardware::grpc::UnreserveRequest request;
      request.set_client_reserve_id("userId");
      ni::hardware::grpc::UnreserveResponse response;
      service.Unreserve(&context, &request, &response);

      EXPECT_FALSE(response.is_unreserved());
   }

   TEST(CoreServiceTests, ReserveSession_Unreserve_UnreservesSession)
   {
      std::string reserve_id("session_name");
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      auto session = session_repository.add_session(ni::hardware::grpc::ViSession(), "session_name", nullptr);
      ni::hardware::grpc::ReserveRequest reserveRequest;
      reserveRequest.set_allocated_session(session);
      reserveRequest.set_client_reserve_id(reserve_id);
      ::grpc::ServerContext context;
      ni::hardware::grpc::ReserveResponse reserve_response;
      service.Reserve(&context, &reserveRequest, &reserve_response);

      ni::hardware::grpc::UnreserveRequest request;
      request.set_client_reserve_id(reserve_id);
      ni::hardware::grpc::UnreserveResponse response;
      service.Unreserve(&context, &request, &response);

      EXPECT_TRUE(response.is_unreserved());
      session_repository.remove_session(*session);
   }
   
   TEST(CoreServiceTests, ReservedNamedSession_ResetServer_SessionClosed)
   {
      std::string reserve_id("session_name");
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      auto session = session_repository.add_session(ni::hardware::grpc::ViSession(), "session_name", nullptr);
      ni::hardware::grpc::ReserveRequest reserveRequest;
      reserveRequest.set_allocated_session(session);
      reserveRequest.set_client_reserve_id(reserve_id);
      ::grpc::ServerContext context;
      ni::hardware::grpc::ReserveResponse reserve_response;
      service.Reserve(&context, &reserveRequest, &reserve_response);

      ni::hardware::grpc::ResetServerResponse response;
      service.ResetServer(&context, NULL, &response);
      
      EXPECT_TRUE(response.all_closed());
   }
   
   TEST(CoreServiceTests, ReservedUnnamedSession_ResetServer_SessionClosed)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      ni::hardware::grpc::CoreService service(&session_repository);
      auto session = session_repository.add_session(ni::hardware::grpc::ViSession(), "", nullptr);
      ni::hardware::grpc::ReserveRequest reserveRequest;
      reserveRequest.set_allocated_session(session);
      ::grpc::ServerContext context;
      ni::hardware::grpc::ReserveResponse reserve_response;
      service.Reserve(&context, &reserveRequest, &reserve_response);

      ni::hardware::grpc::ResetServerResponse response;
      service.ResetServer(&context, NULL, &response);
      
      EXPECT_TRUE(response.all_closed());
   }
} // namespace grpc
} // namespace hardware
} // namespace unit
} // namespace tests
} // namespace ni
