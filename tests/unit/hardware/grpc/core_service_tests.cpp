#include "../source/hardware/grpc/core_service.h"
#include <gtest/gtest.h>
#include <grpcpp/impl/grpc_library.h>

// fixes seg faults caused by https://github.com/grpc/grpc/issues/14633
static grpc::internal::GrpcLibraryInitializer g_gli_initializer;

TEST(ManageSessionTests, ReserveWithNewName_Reserves)
{
    ni::hardware::grpc::impl::CoreService* service = new ni::hardware::grpc::impl::CoreService();
    auto session = service->AddSession(ni::hardware::grpc::ViSession(), "userId", NULL);

    auto request = new ni::hardware::grpc::ReserveRequest;
    request->set_allocated_session(session);

    ::grpc::ServerContext context;
    auto response = new ni::hardware::grpc::ReserveResponse;
    service->Reserve(&context, request, response);

    EXPECT_EQ(response->status(), ni::hardware::grpc::ReserveResponse_ReserveStatus_Reserved);
}
