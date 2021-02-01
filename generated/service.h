// This file was generated
#include <niFake.grpc.pb.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <condition_variable>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc::ServerWriter;
using namespace std;

namespace ni
{
namespace hardware
{
namespace grpc
{
  class niFakeService final : public niFake::Service
  {
  public:
    Status Abort(ServerContext* context, const niFake::AbortRequest* request, niFake::AbortResponse* response) override;
    Status AcceptListOfDurationsInSeconds(ServerContext* context, const niFake::AcceptListOfDurationsInSecondsRequest* request, niFake::AcceptListOfDurationsInSecondsResponse* response) override;
    Status BoolArrayOutputFunction(ServerContext* context, const niFake::BoolArrayOutputFunctionRequest* request, niFake::BoolArrayOutputFunctionResponse* response) override;
    Status DoubleAllTheNums(ServerContext* context, const niFake::DoubleAllTheNumsRequest* request, niFake::DoubleAllTheNumsResponse* response) override;
    Status EnumArrayOutputFunction(ServerContext* context, const niFake::EnumArrayOutputFunctionRequest* request, niFake::EnumArrayOutputFunctionResponse* response) override;
    Status EnumInputFunctionWithDefaults(ServerContext* context, const niFake::EnumInputFunctionWithDefaultsRequest* request, niFake::EnumInputFunctionWithDefaultsResponse* response) override;
    Status ExportAttributeConfigurationBuffer(ServerContext* context, const niFake::ExportAttributeConfigurationBufferRequest* request, niFake::ExportAttributeConfigurationBufferResponse* response) override;
    Status FetchWaveform(ServerContext* context, const niFake::FetchWaveformRequest* request, niFake::FetchWaveformResponse* response) override;
    Status GetABoolean(ServerContext* context, const niFake::GetABooleanRequest* request, niFake::GetABooleanResponse* response) override;
    Status GetANumber(ServerContext* context, const niFake::GetANumberRequest* request, niFake::GetANumberResponse* response) override;
    Status GetAStringOfFixedMaximumSize(ServerContext* context, const niFake::GetAStringOfFixedMaximumSizeRequest* request, niFake::GetAStringOfFixedMaximumSizeResponse* response) override;
    Status GetAStringUsingPythonCode(ServerContext* context, const niFake::GetAStringUsingPythonCodeRequest* request, niFake::GetAStringUsingPythonCodeResponse* response) override;
    Status GetAnIviDanceString(ServerContext* context, const niFake::GetAnIviDanceStringRequest* request, niFake::GetAnIviDanceStringResponse* response) override;
    Status GetAnIviDanceWithATwistString(ServerContext* context, const niFake::GetAnIviDanceWithATwistStringRequest* request, niFake::GetAnIviDanceWithATwistStringResponse* response) override;
    Status GetArrayForPythonCodeCustomType(ServerContext* context, const niFake::GetArrayForPythonCodeCustomTypeRequest* request, niFake::GetArrayForPythonCodeCustomTypeResponse* response) override;
    Status GetArrayForPythonCodeDouble(ServerContext* context, const niFake::GetArrayForPythonCodeDoubleRequest* request, niFake::GetArrayForPythonCodeDoubleResponse* response) override;
    Status GetArraySizeForPythonCode(ServerContext* context, const niFake::GetArraySizeForPythonCodeRequest* request, niFake::GetArraySizeForPythonCodeResponse* response) override;
    Status GetArrayUsingIviDance(ServerContext* context, const niFake::GetArrayUsingIviDanceRequest* request, niFake::GetArrayUsingIviDanceResponse* response) override;
    Status GetAttributeViBoolean(ServerContext* context, const niFake::GetAttributeViBooleanRequest* request, niFake::GetAttributeViBooleanResponse* response) override;
    Status GetAttributeViInt32(ServerContext* context, const niFake::GetAttributeViInt32Request* request, niFake::GetAttributeViInt32Response* response) override;
    Status GetAttributeViInt64(ServerContext* context, const niFake::GetAttributeViInt64Request* request, niFake::GetAttributeViInt64Response* response) override;
    Status GetAttributeViReal64(ServerContext* context, const niFake::GetAttributeViReal64Request* request, niFake::GetAttributeViReal64Response* response) override;
    Status GetAttributeViString(ServerContext* context, const niFake::GetAttributeViStringRequest* request, niFake::GetAttributeViStringResponse* response) override;
    Status GetCalDateAndTime(ServerContext* context, const niFake::GetCalDateAndTimeRequest* request, niFake::GetCalDateAndTimeResponse* response) override;
    Status GetCalInterval(ServerContext* context, const niFake::GetCalIntervalRequest* request, niFake::GetCalIntervalResponse* response) override;
    Status GetCustomType(ServerContext* context, const niFake::GetCustomTypeRequest* request, niFake::GetCustomTypeResponse* response) override;
    Status GetCustomTypeArray(ServerContext* context, const niFake::GetCustomTypeArrayRequest* request, niFake::GetCustomTypeArrayResponse* response) override;
    Status GetEnumValue(ServerContext* context, const niFake::GetEnumValueRequest* request, niFake::GetEnumValueResponse* response) override;
    Status GetError(ServerContext* context, const niFake::GetErrorRequest* request, niFake::GetErrorResponse* response) override;
    Status GetLastCalDateAndTime(ServerContext* context, const niFake::GetLastCalDateAndTimeRequest* request, niFake::GetLastCalDateAndTimeResponse* response) override;
    Status ImportAttributeConfigurationBuffer(ServerContext* context, const niFake::ImportAttributeConfigurationBufferRequest* request, niFake::ImportAttributeConfigurationBufferResponse* response) override;
    Status InitWithOptions(ServerContext* context, const niFake::InitWithOptionsRequest* request, niFake::InitWithOptionsResponse* response) override;
    Status Initiate(ServerContext* context, const niFake::InitiateRequest* request, niFake::InitiateResponse* response) override;
    Status LockSession(ServerContext* context, const niFake::LockSessionRequest* request, niFake::LockSessionResponse* response) override;
    Status MultipleArrayTypes(ServerContext* context, const niFake::MultipleArrayTypesRequest* request, niFake::MultipleArrayTypesResponse* response) override;
    Status MultipleArraysSameSize(ServerContext* context, const niFake::MultipleArraysSameSizeRequest* request, niFake::MultipleArraysSameSizeResponse* response) override;
    Status OneInputFunction(ServerContext* context, const niFake::OneInputFunctionRequest* request, niFake::OneInputFunctionResponse* response) override;
    Status ParametersAreMultipleTypes(ServerContext* context, const niFake::ParametersAreMultipleTypesRequest* request, niFake::ParametersAreMultipleTypesResponse* response) override;
    Status PoorlyNamedSimpleFunction(ServerContext* context, const niFake::PoorlyNamedSimpleFunctionRequest* request, niFake::PoorlyNamedSimpleFunctionResponse* response) override;
    Status Read(ServerContext* context, const niFake::ReadRequest* request, niFake::ReadResponse* response) override;
    Status ReadFromChannel(ServerContext* context, const niFake::ReadFromChannelRequest* request, niFake::ReadFromChannelResponse* response) override;
    Status ReturnANumberAndAString(ServerContext* context, const niFake::ReturnANumberAndAStringRequest* request, niFake::ReturnANumberAndAStringResponse* response) override;
    Status ReturnDurationInSeconds(ServerContext* context, const niFake::ReturnDurationInSecondsRequest* request, niFake::ReturnDurationInSecondsResponse* response) override;
    Status ReturnListOfDurationsInSeconds(ServerContext* context, const niFake::ReturnListOfDurationsInSecondsRequest* request, niFake::ReturnListOfDurationsInSecondsResponse* response) override;
    Status ReturnMultipleTypes(ServerContext* context, const niFake::ReturnMultipleTypesRequest* request, niFake::ReturnMultipleTypesResponse* response) override;
    Status SetAttributeViBoolean(ServerContext* context, const niFake::SetAttributeViBooleanRequest* request, niFake::SetAttributeViBooleanResponse* response) override;
    Status SetAttributeViInt32(ServerContext* context, const niFake::SetAttributeViInt32Request* request, niFake::SetAttributeViInt32Response* response) override;
    Status SetAttributeViInt64(ServerContext* context, const niFake::SetAttributeViInt64Request* request, niFake::SetAttributeViInt64Response* response) override;
    Status SetAttributeViReal64(ServerContext* context, const niFake::SetAttributeViReal64Request* request, niFake::SetAttributeViReal64Response* response) override;
    Status SetAttributeViString(ServerContext* context, const niFake::SetAttributeViStringRequest* request, niFake::SetAttributeViStringResponse* response) override;
    Status SetCustomType(ServerContext* context, const niFake::SetCustomTypeRequest* request, niFake::SetCustomTypeResponse* response) override;
    Status SetCustomTypeArray(ServerContext* context, const niFake::SetCustomTypeArrayRequest* request, niFake::SetCustomTypeArrayResponse* response) override;
    Status StringValuedEnumInputFunctionWithDefaults(ServerContext* context, const niFake::StringValuedEnumInputFunctionWithDefaultsRequest* request, niFake::StringValuedEnumInputFunctionWithDefaultsResponse* response) override;
    Status TwoInputFunction(ServerContext* context, const niFake::TwoInputFunctionRequest* request, niFake::TwoInputFunctionResponse* response) override;
    Status UnlockSession(ServerContext* context, const niFake::UnlockSessionRequest* request, niFake::UnlockSessionResponse* response) override;
    Status Use64BitNumber(ServerContext* context, const niFake::Use64BitNumberRequest* request, niFake::Use64BitNumberResponse* response) override;
    Status WriteWaveform(ServerContext* context, const niFake::WriteWaveformRequest* request, niFake::WriteWaveformResponse* response) override;
    Status close(ServerContext* context, const niFake::closeRequest* request, niFake::closeResponse* response) override;
    Status error_message(ServerContext* context, const niFake::error_messageRequest* request, niFake::error_messageResponse* response) override;
    Status fancy_self_test(ServerContext* context, const niFake::fancy_self_testRequest* request, niFake::fancy_self_testResponse* response) override;
    Status self_test(ServerContext* context, const niFake::self_testRequest* request, niFake::self_testResponse* response) override;
  };
} // namespace grpc
} // namespace hardware
} // namespace ni