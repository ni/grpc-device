#include "../source/hardware/grpc/core_service.h"
#include <gtest/gtest.h>

TEST(ManageSessionTests, ReserveWithNewName_Reserves)
{
    ni::hardware::grpc::impl::CoreService* service = new ni::hardware::grpc::impl::CoreService();
    auto session = new ni::hardware::grpc::ViSession;
    session->set_sessionname("session_name");

    auto request = new ni::hardware::grpc::ReserveRequest;
    request->set_allocated_session(session);

    ::grpc::ServerContext context;
    ni::hardware::grpc::ReserveResponse response;
    service->Reserve(&context, request, &response);

    EXPECT_EQ(response.status, ReserveResponse_ReserveStatus_Reserved);
}
