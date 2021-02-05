// This file was generated
#ifndef NI_HARDWARE_GRPC_NIFAKE_SERVICE_H
#define NI_HARDWARE_GRPC_NIFAKE_SERVICE_H

#include <niFake.grpc.pb.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <condition_variable>
#include "core_server/hardware/grpc/internal/shared_library.h"
#include "core_server/hardware/grpc/internal/session_repository.h"

namespace ni
{
namespace fake
{
namespace grpc
{
  class NiFakeService final : public niFake::Service
  {
  public:
    NiFakeService(SharedLibrary* shared_library, SessionRepository* session_repository);
    grpc::Status Abort(grpc::ServerContext* context, const niFake::AbortRequest* request, niFake::AbortResponse* response) override;
    grpc::Status AcceptListOfDurationsInSeconds(grpc::ServerContext* context, const niFake::AcceptListOfDurationsInSecondsRequest* request, niFake::AcceptListOfDurationsInSecondsResponse* response) override;
    grpc::Status BoolArrayOutputFunction(grpc::ServerContext* context, const niFake::BoolArrayOutputFunctionRequest* request, niFake::BoolArrayOutputFunctionResponse* response) override;
    grpc::Status DoubleAllTheNums(grpc::ServerContext* context, const niFake::DoubleAllTheNumsRequest* request, niFake::DoubleAllTheNumsResponse* response) override;
    grpc::Status EnumArrayOutputFunction(grpc::ServerContext* context, const niFake::EnumArrayOutputFunctionRequest* request, niFake::EnumArrayOutputFunctionResponse* response) override;
    grpc::Status EnumInputFunctionWithDefaults(grpc::ServerContext* context, const niFake::EnumInputFunctionWithDefaultsRequest* request, niFake::EnumInputFunctionWithDefaultsResponse* response) override;
    grpc::Status ExportAttributeConfigurationBuffer(grpc::ServerContext* context, const niFake::ExportAttributeConfigurationBufferRequest* request, niFake::ExportAttributeConfigurationBufferResponse* response) override;
    grpc::Status FetchWaveform(grpc::ServerContext* context, const niFake::FetchWaveformRequest* request, niFake::FetchWaveformResponse* response) override;
    grpc::Status GetABoolean(grpc::ServerContext* context, const niFake::GetABooleanRequest* request, niFake::GetABooleanResponse* response) override;
    grpc::Status GetANumber(grpc::ServerContext* context, const niFake::GetANumberRequest* request, niFake::GetANumberResponse* response) override;
    grpc::Status GetAStringOfFixedMaximumSize(grpc::ServerContext* context, const niFake::GetAStringOfFixedMaximumSizeRequest* request, niFake::GetAStringOfFixedMaximumSizeResponse* response) override;
    grpc::Status GetAStringUsingPythonCode(grpc::ServerContext* context, const niFake::GetAStringUsingPythonCodeRequest* request, niFake::GetAStringUsingPythonCodeResponse* response) override;
    grpc::Status GetAnIviDanceString(grpc::ServerContext* context, const niFake::GetAnIviDanceStringRequest* request, niFake::GetAnIviDanceStringResponse* response) override;
    grpc::Status GetAnIviDanceWithATwistString(grpc::ServerContext* context, const niFake::GetAnIviDanceWithATwistStringRequest* request, niFake::GetAnIviDanceWithATwistStringResponse* response) override;
    grpc::Status GetArrayForPythonCodeCustomType(grpc::ServerContext* context, const niFake::GetArrayForPythonCodeCustomTypeRequest* request, niFake::GetArrayForPythonCodeCustomTypeResponse* response) override;
    grpc::Status GetArrayForPythonCodeDouble(grpc::ServerContext* context, const niFake::GetArrayForPythonCodeDoubleRequest* request, niFake::GetArrayForPythonCodeDoubleResponse* response) override;
    grpc::Status GetArraySizeForPythonCode(grpc::ServerContext* context, const niFake::GetArraySizeForPythonCodeRequest* request, niFake::GetArraySizeForPythonCodeResponse* response) override;
    grpc::Status GetArrayUsingIviDance(grpc::ServerContext* context, const niFake::GetArrayUsingIviDanceRequest* request, niFake::GetArrayUsingIviDanceResponse* response) override;
    grpc::Status GetCalInterval(grpc::ServerContext* context, const niFake::GetCalIntervalRequest* request, niFake::GetCalIntervalResponse* response) override;
    grpc::Status GetCustomType(grpc::ServerContext* context, const niFake::GetCustomTypeRequest* request, niFake::GetCustomTypeResponse* response) override;
    grpc::Status GetCustomTypeArray(grpc::ServerContext* context, const niFake::GetCustomTypeArrayRequest* request, niFake::GetCustomTypeArrayResponse* response) override;
    grpc::Status GetEnumValue(grpc::ServerContext* context, const niFake::GetEnumValueRequest* request, niFake::GetEnumValueResponse* response) override;
    grpc::Status ImportAttributeConfigurationBuffer(grpc::ServerContext* context, const niFake::ImportAttributeConfigurationBufferRequest* request, niFake::ImportAttributeConfigurationBufferResponse* response) override;
    grpc::Status LockSession(grpc::ServerContext* context, const niFake::LockSessionRequest* request, niFake::LockSessionResponse* response) override;
    grpc::Status MultipleArrayTypes(grpc::ServerContext* context, const niFake::MultipleArrayTypesRequest* request, niFake::MultipleArrayTypesResponse* response) override;
    grpc::Status MultipleArraysSameSize(grpc::ServerContext* context, const niFake::MultipleArraysSameSizeRequest* request, niFake::MultipleArraysSameSizeResponse* response) override;
    grpc::Status OneInputFunction(grpc::ServerContext* context, const niFake::OneInputFunctionRequest* request, niFake::OneInputFunctionResponse* response) override;
    grpc::Status ParametersAreMultipleTypes(grpc::ServerContext* context, const niFake::ParametersAreMultipleTypesRequest* request, niFake::ParametersAreMultipleTypesResponse* response) override;
    grpc::Status PoorlyNamedSimpleFunction(grpc::ServerContext* context, const niFake::PoorlyNamedSimpleFunctionRequest* request, niFake::PoorlyNamedSimpleFunctionResponse* response) override;
    grpc::Status Read(grpc::ServerContext* context, const niFake::ReadRequest* request, niFake::ReadResponse* response) override;
    grpc::Status ReadFromChannel(grpc::ServerContext* context, const niFake::ReadFromChannelRequest* request, niFake::ReadFromChannelResponse* response) override;
    grpc::Status ReturnANumberAndAString(grpc::ServerContext* context, const niFake::ReturnANumberAndAStringRequest* request, niFake::ReturnANumberAndAStringResponse* response) override;
    grpc::Status ReturnDurationInSeconds(grpc::ServerContext* context, const niFake::ReturnDurationInSecondsRequest* request, niFake::ReturnDurationInSecondsResponse* response) override;
    grpc::Status ReturnListOfDurationsInSeconds(grpc::ServerContext* context, const niFake::ReturnListOfDurationsInSecondsRequest* request, niFake::ReturnListOfDurationsInSecondsResponse* response) override;
    grpc::Status ReturnMultipleTypes(grpc::ServerContext* context, const niFake::ReturnMultipleTypesRequest* request, niFake::ReturnMultipleTypesResponse* response) override;
    grpc::Status SetCustomType(grpc::ServerContext* context, const niFake::SetCustomTypeRequest* request, niFake::SetCustomTypeResponse* response) override;
    grpc::Status SetCustomTypeArray(grpc::ServerContext* context, const niFake::SetCustomTypeArrayRequest* request, niFake::SetCustomTypeArrayResponse* response) override;
    grpc::Status StringValuedEnumInputFunctionWithDefaults(grpc::ServerContext* context, const niFake::StringValuedEnumInputFunctionWithDefaultsRequest* request, niFake::StringValuedEnumInputFunctionWithDefaultsResponse* response) override;
    grpc::Status TwoInputFunction(grpc::ServerContext* context, const niFake::TwoInputFunctionRequest* request, niFake::TwoInputFunctionResponse* response) override;
    grpc::Status UnlockSession(grpc::ServerContext* context, const niFake::UnlockSessionRequest* request, niFake::UnlockSessionResponse* response) override;
    grpc::Status Use64BitNumber(grpc::ServerContext* context, const niFake::Use64BitNumberRequest* request, niFake::Use64BitNumberResponse* response) override;
    grpc::Status WriteWaveform(grpc::ServerContext* context, const niFake::WriteWaveformRequest* request, niFake::WriteWaveformResponse* response) override;
  private:
    internal::SharedLibrary* shared_library_;
    internal::SessionRepository* session_repository_;
  };
} // namespace grpc
} // namespace fake
} // namespace ni
#endif NI_HARDWARE_GRPC_NIFAKE_SERVICE_H
