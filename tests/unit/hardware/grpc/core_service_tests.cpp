#include <grpcpp/impl/grpc_library.h>
#include <gtest/gtest.h>
#include "hardware/grpc/core_service.h"
#include "hardware/grpc/internal/semaphore.h"
#include "hardware/grpc/internal/session_repository.h"

// fixes seg faults caused by https://github.com/grpc/grpc/issues/14633
static grpc::internal::GrpcLibraryInitializer g_gli_initializer;

TEST(CoreServiceTests, SessionAdded_ReserveWithNewClientName_ReservesSession)
{
    ni::hardware::grpc::CoreService service = ni::hardware::grpc::CoreService();
    ni::hardware::grpc::internal::SessionRepository* session_repository = session_repository->instance();
    auto session = session_repository->add_session(ni::hardware::grpc::ViSession(), "session_name", NULL);
    auto request = new ni::hardware::grpc::ReserveRequest;
    request->set_allocated_session(session);
    request->set_clientreserveid("new_client_name");

    ::grpc::ServerContext context;
    auto response = new ni::hardware::grpc::ReserveResponse;
    service.Reserve(&context, request, response);

    EXPECT_EQ(response->status(), ni::hardware::grpc::ReserveResponse_ReserveStatus_Reserved);
    session_repository->remove_session(*session);
}

TEST(CoreServiceTests, NoSession_ReserveWithNewClientName_InvalidSession)
{
    ni::hardware::grpc::CoreService service = ni::hardware::grpc::CoreService();
    auto request = new ni::hardware::grpc::ReserveRequest;
    request->set_clientreserveid("new_client_name");

    ::grpc::ServerContext context;
    auto response = new ni::hardware::grpc::ReserveResponse;
    service.Reserve(&context, request, response);

    EXPECT_EQ(response->status(), ni::hardware::grpc::ReserveResponse_ReserveStatus_InvalidSession);
}

TEST(CoreServiceTests, AddSession_ReserveWithSameClientName_ReservesSession)
{
    auto session_name = std::string("session_name");
    ni::hardware::grpc::CoreService service = ni::hardware::grpc::CoreService();
    ni::hardware::grpc::internal::SessionRepository* session_repository = session_repository->instance();
    auto session = session_repository->add_session(ni::hardware::grpc::ViSession(), session_name, NULL);
    auto request = new ni::hardware::grpc::ReserveRequest;
    request->set_allocated_clientreserveid(&session_name);
    request->set_clientreserveid(session_name);

    ::grpc::ServerContext context;
    auto response = new ni::hardware::grpc::ReserveResponse;
    service.Reserve(&context, request, response);

    EXPECT_EQ(response->status(), ni::hardware::grpc::ReserveResponse_ReserveStatus_InvalidSession);
    session_repository->remove_session(*session);
}

TEST(CoreServiceTests, UnusedSessionName_IsReserved_ReturnsFalse)
{
    ni::hardware::grpc::CoreService service = ni::hardware::grpc::CoreService();
    auto request = new ni::hardware::grpc::IsReservedByClientRequest;
    request->set_clientreserveid("unused id");

    ::grpc::ServerContext context;
    auto response = new ni::hardware::grpc::IsReservedByClientResponse;
    service.IsReservedByClient(&context, request, response);

    EXPECT_FALSE(response->isreserved());
}

TEST(CoreServiceTests, ReserveSession_IsReserved_ReturnsTrue)
{
    auto reserve_id = std::string("session_name");
    ni::hardware::grpc::CoreService service = ni::hardware::grpc::CoreService();
    ni::hardware::grpc::internal::SessionRepository* session_repository = session_repository->instance();
    auto session = session_repository->add_session(ni::hardware::grpc::ViSession(), "session_name", NULL);
    auto reserveRequest = new ni::hardware::grpc::ReserveRequest;
    reserveRequest->set_allocated_session(session);
    reserveRequest->set_clientreserveid(reserve_id);
    ::grpc::ServerContext context;
    service.Reserve(&context, reserveRequest, new ni::hardware::grpc::ReserveResponse);

    auto request = new ni::hardware::grpc::IsReservedByClientRequest;
    request->set_clientreserveid(reserve_id);
    auto response = new ni::hardware::grpc::IsReservedByClientResponse;
    service.IsReservedByClient(&context, request, response);

    EXPECT_TRUE(response->isreserved());
    session_repository->remove_session(*session);
}

TEST(CoreServiceTests, ReserveAndUnreserveSession_IsReserved_ReturnsFalse)
{
    auto reserve_id = std::string("session_name");
    ni::hardware::grpc::CoreService service = ni::hardware::grpc::CoreService();
    ni::hardware::grpc::internal::SessionRepository* session_repository = session_repository->instance();
    auto session = session_repository->add_session(ni::hardware::grpc::ViSession(), "session_name", NULL);
    auto reserveRequest = new ni::hardware::grpc::ReserveRequest;
    reserveRequest->set_allocated_session(session);
    reserveRequest->set_clientreserveid(reserve_id);
    ::grpc::ServerContext context;
    service.Reserve(&context, reserveRequest, new ni::hardware::grpc::ReserveResponse);
    auto unreserveRequest = new ni::hardware::grpc::UnreserveRequest;
    unreserveRequest->set_clientreserveid(reserve_id);
    service.Unreserve(&context, unreserveRequest, new ni::hardware::grpc::UnreserveResponse);

    auto request = new ni::hardware::grpc::IsReservedByClientRequest;
    request->set_clientreserveid(reserve_id);
    auto response = new ni::hardware::grpc::IsReservedByClientResponse;
    service.IsReservedByClient(&context, request, response);

    EXPECT_FALSE(response->isreserved());
    session_repository->remove_session(*session);
}

TEST(CoreServiceTests, NoSession_Unreserve_DoesNotUnreserve)
{
    ni::hardware::grpc::CoreService service = ni::hardware::grpc::CoreService();

    ::grpc::ServerContext context;
    auto request = new ni::hardware::grpc::UnreserveRequest;
    request->set_clientreserveid("userId");
    auto response = new ni::hardware::grpc::UnreserveResponse;
    service.Unreserve(&context, request, response);

    EXPECT_FALSE(response->isunreserved());
}

TEST(CoreServiceTests, ReserveSession_Unreserve_UnreservesSession)
{
    auto reserve_id = std::string("session_name");
    ni::hardware::grpc::CoreService service = ni::hardware::grpc::CoreService();
    ni::hardware::grpc::internal::SessionRepository* session_repository = session_repository->instance();
    auto session = session_repository->add_session(ni::hardware::grpc::ViSession(), "session_name", NULL);
    auto reserveRequest = new ni::hardware::grpc::ReserveRequest;
    reserveRequest->set_allocated_session(session);
    reserveRequest->set_clientreserveid(reserve_id);
    ::grpc::ServerContext context;
    service.Reserve(&context, reserveRequest, new ni::hardware::grpc::ReserveResponse);

    auto request = new ni::hardware::grpc::UnreserveRequest;
    request->set_clientreserveid(reserve_id);
    auto response = new ni::hardware::grpc::UnreserveResponse;
    service.Unreserve(&context, request, response);

    EXPECT_TRUE(response->isunreserved());
    session_repository->remove_session(*session);
}
