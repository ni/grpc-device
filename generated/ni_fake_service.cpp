// This file was generated
//---------------------------------------------------------------------
//---------------------------------------------------------------------
#include <thread>
#include <sstream>
#include <fstream>
#include <iostream>
#include <ni_fake_service.h>
#include <ni_fake.grpc.h>
#include <atomic>

//---------------------------------------------------------------------
//---------------------------------------------------------------------
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc::StatusCode
using grpc::ServerWriter;
using ni::hardware::grpc::internal::ViSession;

using niFake_AbortPtr = int (*)(uint32);
using niFake_EnumInputFunctionWithDefaultsPtr = int (*)(uint32, string);
using niFake_GetABooleanPtr = int (*)(uint32, bool*);
using niFake_GetANumberPtr = int (*)(uint32, string*);
using niFake_GetArraySizeForPythonCodePtr = int (*)(uint32, int32*);
using niFake_GetAttributeViBooleanPtr = int (*)(uint32, string, ViAttr, bool*);
using niFake_GetAttributeViInt32Ptr = int (*)(uint32, string, ViAttr, int32*);
using niFake_GetAttributeViInt64Ptr = int (*)(uint32, string, ViAttr, int64*);
using niFake_GetAttributeViReal64Ptr = int (*)(uint32, string, ViAttr, double*);
using niFake_GetCalDateAndTimePtr = int (*)(uint32, int32, int32*, int32*, int32*, int32*, int32*);
using niFake_GetCalIntervalPtr = int (*)(uint32, int32*);
using niFake_GetCustomTypePtr = int (*)(uint32, struct CustomStruct*);
using niFake_GetEnumValuePtr = int (*)(uint32, int32*, string*);
using niFake_GetLastCalDateAndTimePtr = int (*)(uint32, int32, hightime.datetime*);
using niFake_InitWithOptionsPtr = int (*)(string, bool, bool, string, uint32*);
using niFake_InitiatePtr = int (*)(uint32);
using niFake_LockSessionPtr = int (*)(uint32, bool*);
using niFake_OneInputFunctionPtr = int (*)(uint32, int32);
using niFake_PoorlyNamedSimpleFunctionPtr = int (*)(uint32);
using niFake_ReadPtr = int (*)(uint32, double, double*);
using niFake_ReadFromChannelPtr = int (*)(uint32, string, int32, double*);
using niFake_ReturnDurationInSecondsPtr = int (*)(uint32, double*);
using niFake_SetAttributeViBooleanPtr = int (*)(uint32, string, ViAttr, bool);
using niFake_SetAttributeViInt32Ptr = int (*)(uint32, string, ViAttr, int32);
using niFake_SetAttributeViInt64Ptr = int (*)(uint32, string, ViAttr, int64);
using niFake_SetAttributeViReal64Ptr = int (*)(uint32, string, ViAttr, double);
using niFake_SetAttributeViStringPtr = int (*)(uint32, string, ViAttr, string);
using niFake_SetCustomTypePtr = int (*)(uint32, struct CustomStruct);
using niFake_StringValuedEnumInputFunctionWithDefaultsPtr = int (*)(uint32, string);
using niFake_TwoInputFunctionPtr = int (*)(uint32, double, string);
using niFake_UnlockSessionPtr = int (*)(uint32, bool*);
using niFake_Use64BitNumberPtr = int (*)(uint32, int64, int64*);
using niFake_closePtr = int (*)(uint32);
using niFake_fancy_self_testPtr = int (*)(uint32);

static bool s_HasSession;
static std::atomic<unsigned int> s_IdleCount;

//---------------------------------------------------------------------
//---------------------------------------------------------------------
using namespace std;

#if defined(_MSC_VER)
   static const char* driver_api_library_name = "nifake_64.dll";
#else
   static const char* driver_api_library_name = "./nifake.so";
#endif

NiFakeService::NiFakeService(internal::SharedLibrary* shared_library, internal::SessionRepository* session_repository)
    : shared_library_(shared_library), session_repository_(session_repository) 
{
  shared_library_ -> set_library_name(driver_api_library_name);
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::Abort(ServerContext* context, const niFake::AbortRequest* request, niFake::AbortResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto AbortFunctionPointer = reinterpret_cast<niFake_AbortPtr>(shared_library_ -> get_function_pointer("niFake_Abort"));
  if (AbortFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());

  auto status = AbortFunctionPointer(vi);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::AcceptListOfDurationsInSeconds(ServerContext* context, const niFake::AcceptListOfDurationsInSecondsRequest* request, niFake::AcceptListOfDurationsInSecondsResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::BoolArrayOutputFunction(ServerContext* context, const niFake::BoolArrayOutputFunctionRequest* request, niFake::BoolArrayOutputFunctionResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::DoubleAllTheNums(ServerContext* context, const niFake::DoubleAllTheNumsRequest* request, niFake::DoubleAllTheNumsResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::EnumArrayOutputFunction(ServerContext* context, const niFake::EnumArrayOutputFunctionRequest* request, niFake::EnumArrayOutputFunctionResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::EnumInputFunctionWithDefaults(ServerContext* context, const niFake::EnumInputFunctionWithDefaultsRequest* request, niFake::EnumInputFunctionWithDefaultsResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto EnumInputFunctionWithDefaultsFunctionPointer = reinterpret_cast<niFake_EnumInputFunctionWithDefaultsPtr>(shared_library_ -> get_function_pointer("niFake_EnumInputFunctionWithDefaults"));
  if (EnumInputFunctionWithDefaultsFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  string a_turtle = request->a_turtle();

  auto status = EnumInputFunctionWithDefaultsFunctionPointer(vi, a_turtle);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::ExportAttributeConfigurationBuffer(ServerContext* context, const niFake::ExportAttributeConfigurationBufferRequest* request, niFake::ExportAttributeConfigurationBufferResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::FetchWaveform(ServerContext* context, const niFake::FetchWaveformRequest* request, niFake::FetchWaveformResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetABoolean(ServerContext* context, const niFake::GetABooleanRequest* request, niFake::GetABooleanResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetABooleanFunctionPointer = reinterpret_cast<niFake_GetABooleanPtr>(shared_library_ -> get_function_pointer("niFake_GetABoolean"));
  if (GetABooleanFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  bool a_boolean;

  auto status = GetABooleanFunctionPointer(vi, &a_boolean);
  response->set_status(status);
  if (status == 0) {
    response->set_a_boolean(a_boolean);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetANumber(ServerContext* context, const niFake::GetANumberRequest* request, niFake::GetANumberResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetANumberFunctionPointer = reinterpret_cast<niFake_GetANumberPtr>(shared_library_ -> get_function_pointer("niFake_GetANumber"));
  if (GetANumberFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  string a_number;

  auto status = GetANumberFunctionPointer(vi, &a_number);
  response->set_status(status);
  if (status == 0) {
    response->set_a_number(a_number);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetAStringOfFixedMaximumSize(ServerContext* context, const niFake::GetAStringOfFixedMaximumSizeRequest* request, niFake::GetAStringOfFixedMaximumSizeResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetAStringUsingPythonCode(ServerContext* context, const niFake::GetAStringUsingPythonCodeRequest* request, niFake::GetAStringUsingPythonCodeResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetAnIviDanceString(ServerContext* context, const niFake::GetAnIviDanceStringRequest* request, niFake::GetAnIviDanceStringResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetAnIviDanceWithATwistString(ServerContext* context, const niFake::GetAnIviDanceWithATwistStringRequest* request, niFake::GetAnIviDanceWithATwistStringResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetArrayForPythonCodeCustomType(ServerContext* context, const niFake::GetArrayForPythonCodeCustomTypeRequest* request, niFake::GetArrayForPythonCodeCustomTypeResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetArrayForPythonCodeDouble(ServerContext* context, const niFake::GetArrayForPythonCodeDoubleRequest* request, niFake::GetArrayForPythonCodeDoubleResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetArraySizeForPythonCode(ServerContext* context, const niFake::GetArraySizeForPythonCodeRequest* request, niFake::GetArraySizeForPythonCodeResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetArraySizeForPythonCodeFunctionPointer = reinterpret_cast<niFake_GetArraySizeForPythonCodePtr>(shared_library_ -> get_function_pointer("niFake_GetArraySizeForPythonCode"));
  if (GetArraySizeForPythonCodeFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  int32 size_out;

  auto status = GetArraySizeForPythonCodeFunctionPointer(vi, &size_out);
  response->set_status(status);
  if (status == 0) {
    response->set_size_out(size_out);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetArrayUsingIviDance(ServerContext* context, const niFake::GetArrayUsingIviDanceRequest* request, niFake::GetArrayUsingIviDanceResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetAttributeViBoolean(ServerContext* context, const niFake::GetAttributeViBooleanRequest* request, niFake::GetAttributeViBooleanResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetAttributeViBooleanFunctionPointer = reinterpret_cast<niFake_GetAttributeViBooleanPtr>(shared_library_ -> get_function_pointer("niFake_GetAttributeViBoolean"));
  if (GetAttributeViBooleanFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  string channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  bool attribute_value;

  auto status = GetAttributeViBooleanFunctionPointer(vi, channel_name, attribute_id, &attribute_value);
  response->set_status(status);
  if (status == 0) {
    response->set_attribute_value(attribute_value);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetAttributeViInt32(ServerContext* context, const niFake::GetAttributeViInt32Request* request, niFake::GetAttributeViInt32Response* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetAttributeViInt32FunctionPointer = reinterpret_cast<niFake_GetAttributeViInt32Ptr>(shared_library_ -> get_function_pointer("niFake_GetAttributeViInt32"));
  if (GetAttributeViInt32FunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  string channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  int32 attribute_value;

  auto status = GetAttributeViInt32FunctionPointer(vi, channel_name, attribute_id, &attribute_value);
  response->set_status(status);
  if (status == 0) {
    response->set_attribute_value(attribute_value);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetAttributeViInt64(ServerContext* context, const niFake::GetAttributeViInt64Request* request, niFake::GetAttributeViInt64Response* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetAttributeViInt64FunctionPointer = reinterpret_cast<niFake_GetAttributeViInt64Ptr>(shared_library_ -> get_function_pointer("niFake_GetAttributeViInt64"));
  if (GetAttributeViInt64FunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  string channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  int64 attribute_value;

  auto status = GetAttributeViInt64FunctionPointer(vi, channel_name, attribute_id, &attribute_value);
  response->set_status(status);
  if (status == 0) {
    response->set_attribute_value(attribute_value);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetAttributeViReal64(ServerContext* context, const niFake::GetAttributeViReal64Request* request, niFake::GetAttributeViReal64Response* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetAttributeViReal64FunctionPointer = reinterpret_cast<niFake_GetAttributeViReal64Ptr>(shared_library_ -> get_function_pointer("niFake_GetAttributeViReal64"));
  if (GetAttributeViReal64FunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  string channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  double attribute_value;

  auto status = GetAttributeViReal64FunctionPointer(vi, channel_name, attribute_id, &attribute_value);
  response->set_status(status);
  if (status == 0) {
    response->set_attribute_value(attribute_value);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetAttributeViString(ServerContext* context, const niFake::GetAttributeViStringRequest* request, niFake::GetAttributeViStringResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetCalDateAndTime(ServerContext* context, const niFake::GetCalDateAndTimeRequest* request, niFake::GetCalDateAndTimeResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetCalDateAndTimeFunctionPointer = reinterpret_cast<niFake_GetCalDateAndTimePtr>(shared_library_ -> get_function_pointer("niFake_GetCalDateAndTime"));
  if (GetCalDateAndTimeFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  int32 cal_type = request->cal_type();
  int32 month;
  int32 day;
  int32 year;
  int32 hour;
  int32 minute;

  auto status = GetCalDateAndTimeFunctionPointer(vi, cal_type, &month, &day, &year, &hour, &minute);
  response->set_status(status);
  if (status == 0) {
    response->set_month(month);
    response->set_day(day);
    response->set_year(year);
    response->set_hour(hour);
    response->set_minute(minute);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetCalInterval(ServerContext* context, const niFake::GetCalIntervalRequest* request, niFake::GetCalIntervalResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetCalIntervalFunctionPointer = reinterpret_cast<niFake_GetCalIntervalPtr>(shared_library_ -> get_function_pointer("niFake_GetCalInterval"));
  if (GetCalIntervalFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  int32 months;

  auto status = GetCalIntervalFunctionPointer(vi, &months);
  response->set_status(status);
  if (status == 0) {
    response->set_months(months);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetCustomType(ServerContext* context, const niFake::GetCustomTypeRequest* request, niFake::GetCustomTypeResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetCustomTypeFunctionPointer = reinterpret_cast<niFake_GetCustomTypePtr>(shared_library_ -> get_function_pointer("niFake_GetCustomType"));
  if (GetCustomTypeFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  struct CustomStruct cs;

  auto status = GetCustomTypeFunctionPointer(vi, &cs);
  response->set_status(status);
  if (status == 0) {
    response->set_cs(cs);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetCustomTypeArray(ServerContext* context, const niFake::GetCustomTypeArrayRequest* request, niFake::GetCustomTypeArrayResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetEnumValue(ServerContext* context, const niFake::GetEnumValueRequest* request, niFake::GetEnumValueResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetEnumValueFunctionPointer = reinterpret_cast<niFake_GetEnumValuePtr>(shared_library_ -> get_function_pointer("niFake_GetEnumValue"));
  if (GetEnumValueFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  int32 a_quantity;
  string a_turtle;

  auto status = GetEnumValueFunctionPointer(vi, &a_quantity, &a_turtle);
  response->set_status(status);
  if (status == 0) {
    response->set_a_quantity(a_quantity);
    response->set_a_turtle(a_turtle);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetError(ServerContext* context, const niFake::GetErrorRequest* request, niFake::GetErrorResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetLastCalDateAndTime(ServerContext* context, const niFake::GetLastCalDateAndTimeRequest* request, niFake::GetLastCalDateAndTimeResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetLastCalDateAndTimeFunctionPointer = reinterpret_cast<niFake_GetLastCalDateAndTimePtr>(shared_library_ -> get_function_pointer("niFake_GetLastCalDateAndTime"));
  if (GetLastCalDateAndTimeFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  int32 cal_type = request->cal_type();
  hightime.datetime month;

  auto status = GetLastCalDateAndTimeFunctionPointer(vi, cal_type, &month);
  response->set_status(status);
  if (status == 0) {
    response->set_month(month);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::ImportAttributeConfigurationBuffer(ServerContext* context, const niFake::ImportAttributeConfigurationBufferRequest* request, niFake::ImportAttributeConfigurationBufferResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::InitWithOptions(ServerContext* context, const niFake::InitWithOptionsRequest* request, niFake::InitWithOptionsResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto InitWithOptionsFunctionPointer = reinterpret_cast<niFake_InitWithOptionsPtr>(shared_library_ -> get_function_pointer("niFake_InitWithOptions"));
  if (InitWithOptionsFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  string resource_name = request->resource_name();
  bool id_query = request->id_query();
  bool reset_device = request->reset_device();
  string option_string = request->option_string().c_str();
  uint32 vi;

  auto status = InitWithOptionsFunctionPointer(resource_name, id_query, reset_device, option_string, &vi);
  response->set_status(status);
  if (status == 0) {
    response->set_vi(vi);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::Initiate(ServerContext* context, const niFake::InitiateRequest* request, niFake::InitiateResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto InitiateFunctionPointer = reinterpret_cast<niFake_InitiatePtr>(shared_library_ -> get_function_pointer("niFake_Initiate"));
  if (InitiateFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());

  auto status = InitiateFunctionPointer(vi);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::LockSession(ServerContext* context, const niFake::LockSessionRequest* request, niFake::LockSessionResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto LockSessionFunctionPointer = reinterpret_cast<niFake_LockSessionPtr>(shared_library_ -> get_function_pointer("niFake_LockSession"));
  if (LockSessionFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  bool caller_has_lock;

  auto status = LockSessionFunctionPointer(vi, &caller_has_lock);
  response->set_status(status);
  if (status == 0) {
    response->set_caller_has_lock(caller_has_lock);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::MultipleArrayTypes(ServerContext* context, const niFake::MultipleArrayTypesRequest* request, niFake::MultipleArrayTypesResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::MultipleArraysSameSize(ServerContext* context, const niFake::MultipleArraysSameSizeRequest* request, niFake::MultipleArraysSameSizeResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::OneInputFunction(ServerContext* context, const niFake::OneInputFunctionRequest* request, niFake::OneInputFunctionResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto OneInputFunctionFunctionPointer = reinterpret_cast<niFake_OneInputFunctionPtr>(shared_library_ -> get_function_pointer("niFake_OneInputFunction"));
  if (OneInputFunctionFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  int32 a_number = request->a_number();

  auto status = OneInputFunctionFunctionPointer(vi, a_number);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::ParametersAreMultipleTypes(ServerContext* context, const niFake::ParametersAreMultipleTypesRequest* request, niFake::ParametersAreMultipleTypesResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::PoorlyNamedSimpleFunction(ServerContext* context, const niFake::PoorlyNamedSimpleFunctionRequest* request, niFake::PoorlyNamedSimpleFunctionResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto PoorlyNamedSimpleFunctionFunctionPointer = reinterpret_cast<niFake_PoorlyNamedSimpleFunctionPtr>(shared_library_ -> get_function_pointer("niFake_PoorlyNamedSimpleFunction"));
  if (PoorlyNamedSimpleFunctionFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());

  auto status = PoorlyNamedSimpleFunctionFunctionPointer(vi);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::Read(ServerContext* context, const niFake::ReadRequest* request, niFake::ReadResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto ReadFunctionPointer = reinterpret_cast<niFake_ReadPtr>(shared_library_ -> get_function_pointer("niFake_Read"));
  if (ReadFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  double maximum_time = request->maximum_time();
  double reading;

  auto status = ReadFunctionPointer(vi, maximum_time, &reading);
  response->set_status(status);
  if (status == 0) {
    response->set_reading(reading);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::ReadFromChannel(ServerContext* context, const niFake::ReadFromChannelRequest* request, niFake::ReadFromChannelResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto ReadFromChannelFunctionPointer = reinterpret_cast<niFake_ReadFromChannelPtr>(shared_library_ -> get_function_pointer("niFake_ReadFromChannel"));
  if (ReadFromChannelFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  string channel_name = request->channel_name().c_str();
  int32 maximum_time = request->maximum_time();
  double reading;

  auto status = ReadFromChannelFunctionPointer(vi, channel_name, maximum_time, &reading);
  response->set_status(status);
  if (status == 0) {
    response->set_reading(reading);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::ReturnANumberAndAString(ServerContext* context, const niFake::ReturnANumberAndAStringRequest* request, niFake::ReturnANumberAndAStringResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::ReturnDurationInSeconds(ServerContext* context, const niFake::ReturnDurationInSecondsRequest* request, niFake::ReturnDurationInSecondsResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto ReturnDurationInSecondsFunctionPointer = reinterpret_cast<niFake_ReturnDurationInSecondsPtr>(shared_library_ -> get_function_pointer("niFake_ReturnDurationInSeconds"));
  if (ReturnDurationInSecondsFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  double timedelta;

  auto status = ReturnDurationInSecondsFunctionPointer(vi, &timedelta);
  response->set_status(status);
  if (status == 0) {
    response->set_timedelta(timedelta);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::ReturnListOfDurationsInSeconds(ServerContext* context, const niFake::ReturnListOfDurationsInSecondsRequest* request, niFake::ReturnListOfDurationsInSecondsResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::ReturnMultipleTypes(ServerContext* context, const niFake::ReturnMultipleTypesRequest* request, niFake::ReturnMultipleTypesResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::SetAttributeViBoolean(ServerContext* context, const niFake::SetAttributeViBooleanRequest* request, niFake::SetAttributeViBooleanResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto SetAttributeViBooleanFunctionPointer = reinterpret_cast<niFake_SetAttributeViBooleanPtr>(shared_library_ -> get_function_pointer("niFake_SetAttributeViBoolean"));
  if (SetAttributeViBooleanFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  string channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  bool attribute_value = request->attribute_value();

  auto status = SetAttributeViBooleanFunctionPointer(vi, channel_name, attribute_id, attribute_value);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::SetAttributeViInt32(ServerContext* context, const niFake::SetAttributeViInt32Request* request, niFake::SetAttributeViInt32Response* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto SetAttributeViInt32FunctionPointer = reinterpret_cast<niFake_SetAttributeViInt32Ptr>(shared_library_ -> get_function_pointer("niFake_SetAttributeViInt32"));
  if (SetAttributeViInt32FunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  string channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  int32 attribute_value = request->attribute_value();

  auto status = SetAttributeViInt32FunctionPointer(vi, channel_name, attribute_id, attribute_value);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::SetAttributeViInt64(ServerContext* context, const niFake::SetAttributeViInt64Request* request, niFake::SetAttributeViInt64Response* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto SetAttributeViInt64FunctionPointer = reinterpret_cast<niFake_SetAttributeViInt64Ptr>(shared_library_ -> get_function_pointer("niFake_SetAttributeViInt64"));
  if (SetAttributeViInt64FunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  string channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  int64 attribute_value = request->attribute_value();

  auto status = SetAttributeViInt64FunctionPointer(vi, channel_name, attribute_id, attribute_value);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::SetAttributeViReal64(ServerContext* context, const niFake::SetAttributeViReal64Request* request, niFake::SetAttributeViReal64Response* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto SetAttributeViReal64FunctionPointer = reinterpret_cast<niFake_SetAttributeViReal64Ptr>(shared_library_ -> get_function_pointer("niFake_SetAttributeViReal64"));
  if (SetAttributeViReal64FunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  string channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  double attribute_value = request->attribute_value();

  auto status = SetAttributeViReal64FunctionPointer(vi, channel_name, attribute_id, attribute_value);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::SetAttributeViString(ServerContext* context, const niFake::SetAttributeViStringRequest* request, niFake::SetAttributeViStringResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto SetAttributeViStringFunctionPointer = reinterpret_cast<niFake_SetAttributeViStringPtr>(shared_library_ -> get_function_pointer("niFake_SetAttributeViString"));
  if (SetAttributeViStringFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  string channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  string attribute_value = request->attribute_value().c_str();

  auto status = SetAttributeViStringFunctionPointer(vi, channel_name, attribute_id, attribute_value);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::SetCustomType(ServerContext* context, const niFake::SetCustomTypeRequest* request, niFake::SetCustomTypeResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto SetCustomTypeFunctionPointer = reinterpret_cast<niFake_SetCustomTypePtr>(shared_library_ -> get_function_pointer("niFake_SetCustomType"));
  if (SetCustomTypeFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  struct CustomStruct cs = request->cs();

  auto status = SetCustomTypeFunctionPointer(vi, cs);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::SetCustomTypeArray(ServerContext* context, const niFake::SetCustomTypeArrayRequest* request, niFake::SetCustomTypeArrayResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::StringValuedEnumInputFunctionWithDefaults(ServerContext* context, const niFake::StringValuedEnumInputFunctionWithDefaultsRequest* request, niFake::StringValuedEnumInputFunctionWithDefaultsResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto StringValuedEnumInputFunctionWithDefaultsFunctionPointer = reinterpret_cast<niFake_StringValuedEnumInputFunctionWithDefaultsPtr>(shared_library_ -> get_function_pointer("niFake_StringValuedEnumInputFunctionWithDefaults"));
  if (StringValuedEnumInputFunctionWithDefaultsFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  string a_mobile_o_s_name = request->a_mobile_o_s_name().c_str();

  auto status = StringValuedEnumInputFunctionWithDefaultsFunctionPointer(vi, a_mobile_o_s_name);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::TwoInputFunction(ServerContext* context, const niFake::TwoInputFunctionRequest* request, niFake::TwoInputFunctionResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto TwoInputFunctionFunctionPointer = reinterpret_cast<niFake_TwoInputFunctionPtr>(shared_library_ -> get_function_pointer("niFake_TwoInputFunction"));
  if (TwoInputFunctionFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  double a_number = request->a_number();
  string a_string = request->a_string();

  auto status = TwoInputFunctionFunctionPointer(vi, a_number, a_string);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::UnlockSession(ServerContext* context, const niFake::UnlockSessionRequest* request, niFake::UnlockSessionResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto UnlockSessionFunctionPointer = reinterpret_cast<niFake_UnlockSessionPtr>(shared_library_ -> get_function_pointer("niFake_UnlockSession"));
  if (UnlockSessionFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  bool caller_has_lock;

  auto status = UnlockSessionFunctionPointer(vi, &caller_has_lock);
  response->set_status(status);
  if (status == 0) {
    response->set_caller_has_lock(caller_has_lock);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::Use64BitNumber(ServerContext* context, const niFake::Use64BitNumberRequest* request, niFake::Use64BitNumberResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto Use64BitNumberFunctionPointer = reinterpret_cast<niFake_Use64BitNumberPtr>(shared_library_ -> get_function_pointer("niFake_Use64BitNumber"));
  if (Use64BitNumberFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());
  int64 input = request->input();
  int64 output;

  auto status = Use64BitNumberFunctionPointer(vi, input, &output);
  response->set_status(status);
  if (status == 0) {
    response->set_output(output);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::WriteWaveform(ServerContext* context, const niFake::WriteWaveformRequest* request, niFake::WriteWaveformResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::close(ServerContext* context, const niFake::closeRequest* request, niFake::closeResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto closeFunctionPointer = reinterpret_cast<niFake_closePtr>(shared_library_ -> get_function_pointer("niFake_close"));
  if (closeFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());

  auto status = closeFunctionPointer(vi);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::error_message(ServerContext* context, const niFake::error_messageRequest* request, niFake::error_messageResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::fancy_self_test(ServerContext* context, const niFake::fancy_self_testRequest* request, niFake::fancy_self_testResponse* response)
{
  shared_library_ -> load();
  if (!shared_library_ -> is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto fancy_self_testFunctionPointer = reinterpret_cast<niFake_fancy_self_testPtr>(shared_library_ -> get_function_pointer("niFake_fancy_self_test"));
  if (fancy_self_testFunctionPointer == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  uint32 vi = request->vi());

  auto status = fancy_self_testFunctionPointer(vi);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::self_test(ServerContext* context, const niFake::self_testRequest* request, niFake::self_testResponse* response)
{
  return Status(StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
}

