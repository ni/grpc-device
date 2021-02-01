// This file was generated
//---------------------------------------------------------------------
//---------------------------------------------------------------------
#include <thread>
#include <sstream>
#include <fstream>
#include <iostream>
#include <ni_fake.h>
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

using AbortPtr = int (*)(ViSession);
using AcceptListOfDurationsInSecondsPtr = int (*)(ViSession, int32, double[]);
using BoolArrayOutputFunctionPtr = int (*)(ViSession, int32, bool[]*);
using DoubleAllTheNumsPtr = int (*)(ViSession, int32, double[]);
using EnumArrayOutputFunctionPtr = int (*)(ViSession, int32, bytes[]*);
using EnumInputFunctionWithDefaultsPtr = int (*)(ViSession, bytes);
using ExportAttributeConfigurationBufferPtr = int (*)(ViSession, int32, bytes[]*);
using FetchWaveformPtr = int (*)(ViSession, int32, double[]*, int32*);
using GetABooleanPtr = int (*)(ViSession, bool*);
using GetANumberPtr = int (*)(ViSession, bytes*);
using GetAStringOfFixedMaximumSizePtr = int (*)(ViSession, string[256]*);
using GetAStringUsingPythonCodePtr = int (*)(ViSession, bytes, string[]*);
using GetAnIviDanceStringPtr = int (*)(ViSession, int32, string[]*);
using GetAnIviDanceWithATwistStringPtr = int (*)(ViSession, int32, string[]*, int32*);
using GetArrayForPythonCodeCustomTypePtr = int (*)(ViSession, int32, struct CustomStruct[][]*);
using GetArrayForPythonCodeDoublePtr = int (*)(ViSession, int32, double[]*);
using GetArraySizeForPythonCodePtr = int (*)(ViSession, int32*);
using GetArrayUsingIviDancePtr = int (*)(ViSession, int32, double[]*);
using GetAttributeViBooleanPtr = int (*)(ViSession, string, ScopePropertyId, bool*);
using GetAttributeViInt32Ptr = int (*)(ViSession, string, ScopePropertyId, int32*);
using GetAttributeViInt64Ptr = int (*)(ViSession, string, ScopePropertyId, int64*);
using GetAttributeViReal64Ptr = int (*)(ViSession, string, ScopePropertyId, double*);
using GetAttributeViStringPtr = int (*)(ViSession, string, ScopePropertyId, int32, string[]*);
using GetCalDateAndTimePtr = int (*)(ViSession, int32, int32*, int32*, int32*, int32*, int32*);
using GetCalIntervalPtr = int (*)(ViSession, int32*);
using GetCustomTypePtr = int (*)(ViSession, struct CustomStruct*);
using GetCustomTypeArrayPtr = int (*)(ViSession, int32, struct CustomStruct[][]*);
using GetEnumValuePtr = int (*)(ViSession, int32*, bytes*);
using GetErrorPtr = int (*)(ViSession, int32*, int32, string[]*);
using GetLastCalDateAndTimePtr = int (*)(ViSession, int32, hightime.datetime*);
using ImportAttributeConfigurationBufferPtr = int (*)(ViSession, int32, bytes[]);
using InitWithOptionsPtr = int (*)(string, bool, bool, string, ViSession*);
using InitiatePtr = int (*)(ViSession);
using LockSessionPtr = int (*)(ViSession, bool*);
using MultipleArrayTypesPtr = int (*)(ViSession, int32, double[]*, double[3]*, int32, double[], bytes[]);
using MultipleArraysSameSizePtr = int (*)(ViSession, double[], double[], double[], double[], int32);
using OneInputFunctionPtr = int (*)(ViSession, int32);
using ParametersAreMultipleTypesPtr = int (*)(ViSession, bool, int32, int64, bytes, double, double, int32, string);
using PoorlyNamedSimpleFunctionPtr = int (*)(ViSession);
using ReadPtr = int (*)(ViSession, double, double*);
using ReadFromChannelPtr = int (*)(ViSession, string, int32, double*);
using ReturnANumberAndAStringPtr = int (*)(ViSession, bytes*, string[256]*);
using ReturnDurationInSecondsPtr = int (*)(ViSession, double*);
using ReturnListOfDurationsInSecondsPtr = int (*)(ViSession, int32, double[]*);
using ReturnMultipleTypesPtr = int (*)(ViSession, bool*, int32*, int64*, bytes*, double*, double*, int32, double[]*, int32, string[]*);
using SetAttributeViBooleanPtr = int (*)(ViSession, string, ScopePropertyId, bool);
using SetAttributeViInt32Ptr = int (*)(ViSession, string, ScopePropertyId, int32);
using SetAttributeViInt64Ptr = int (*)(ViSession, string, ScopePropertyId, int64);
using SetAttributeViReal64Ptr = int (*)(ViSession, string, ScopePropertyId, double);
using SetAttributeViStringPtr = int (*)(ViSession, string, ScopePropertyId, string);
using SetCustomTypePtr = int (*)(ViSession, struct CustomStruct);
using SetCustomTypeArrayPtr = int (*)(ViSession, int32, struct CustomStruct[][]);
using StringValuedEnumInputFunctionWithDefaultsPtr = int (*)(ViSession, string);
using TwoInputFunctionPtr = int (*)(ViSession, double, string);
using UnlockSessionPtr = int (*)(ViSession, bool*);
using Use64BitNumberPtr = int (*)(ViSession, int64, int64*);
using WriteWaveformPtr = int (*)(ViSession, int32, double[]);
using closePtr = int (*)(ViSession);
using error_messagePtr = int (*)(ViSession, int32, string[256]*);
using fancy_self_testPtr = int (*)(ViSession);
using self_testPtr = int (*)(ViSession, bytes*, string[256]*);

static bool s_HasSession;
static std::atomic<unsigned int> s_IdleCount;

//---------------------------------------------------------------------
//---------------------------------------------------------------------
using namespace std;

#if defined(_MSC_VER)
   static const char* driver_api_library_name = "NiFake.dll";
#else
   static const char* driver_api_library_name = "./libNiFake.so";
#endif

NiFakeService::NiFakeService()
    : shared_library_(driver_api_library_name)
{
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::Abort(ServerContext* context, const niFake::AbortRequest* request, niFake::AbortResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto AbortFunctionPointer = reinterpret_cast<AbortPtr>(shared_library_.get_function_pointer("Abort"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto AcceptListOfDurationsInSecondsFunctionPointer = reinterpret_cast<AcceptListOfDurationsInSecondsPtr>(shared_library_.get_function_pointer("AcceptListOfDurationsInSeconds"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 count = request->count();
  ViReal64[] delays = request->delays();

  auto status = AcceptListOfDurationsInSecondsFunctionPointer(vi, count, delays);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::BoolArrayOutputFunction(ServerContext* context, const niFake::BoolArrayOutputFunctionRequest* request, niFake::BoolArrayOutputFunctionResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto BoolArrayOutputFunctionFunctionPointer = reinterpret_cast<BoolArrayOutputFunctionPtr>(shared_library_.get_function_pointer("BoolArrayOutputFunction"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 number_of_elements = request->number_of_elements();
  ViBoolean[] an_array;

  auto status = BoolArrayOutputFunctionFunctionPointer(vi, number_of_elements, &an_array);
  response->set_status(status);
  if (status == 0) {
    response->set_an_array(an_array);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::DoubleAllTheNums(ServerContext* context, const niFake::DoubleAllTheNumsRequest* request, niFake::DoubleAllTheNumsResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto DoubleAllTheNumsFunctionPointer = reinterpret_cast<DoubleAllTheNumsPtr>(shared_library_.get_function_pointer("DoubleAllTheNums"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 number_count = request->number_count();
  ViReal64[] numbers = request->numbers();

  auto status = DoubleAllTheNumsFunctionPointer(vi, number_count, numbers);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::EnumArrayOutputFunction(ServerContext* context, const niFake::EnumArrayOutputFunctionRequest* request, niFake::EnumArrayOutputFunctionResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto EnumArrayOutputFunctionFunctionPointer = reinterpret_cast<EnumArrayOutputFunctionPtr>(shared_library_.get_function_pointer("EnumArrayOutputFunction"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 number_of_elements = request->number_of_elements();
  ViInt16[] an_array;

  auto status = EnumArrayOutputFunctionFunctionPointer(vi, number_of_elements, &an_array);
  response->set_status(status);
  if (status == 0) {
    response->set_an_array(an_array);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::EnumInputFunctionWithDefaults(ServerContext* context, const niFake::EnumInputFunctionWithDefaultsRequest* request, niFake::EnumInputFunctionWithDefaultsResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto EnumInputFunctionWithDefaultsFunctionPointer = reinterpret_cast<EnumInputFunctionWithDefaultsPtr>(shared_library_.get_function_pointer("EnumInputFunctionWithDefaults"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt16 a_turtle = request->a_turtle();

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto ExportAttributeConfigurationBufferFunctionPointer = reinterpret_cast<ExportAttributeConfigurationBufferPtr>(shared_library_.get_function_pointer("ExportAttributeConfigurationBuffer"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 size_in_bytes = request->size_in_bytes();
  ViInt8[] configuration;

  auto status = ExportAttributeConfigurationBufferFunctionPointer(vi, size_in_bytes, &configuration);
  response->set_status(status);
  if (status == 0) {
    response->set_configuration(configuration);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::FetchWaveform(ServerContext* context, const niFake::FetchWaveformRequest* request, niFake::FetchWaveformResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto FetchWaveformFunctionPointer = reinterpret_cast<FetchWaveformPtr>(shared_library_.get_function_pointer("FetchWaveform"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 number_of_samples = request->number_of_samples();
  ViReal64[] waveform_data;
  ViInt32 actual_number_of_samples;

  auto status = FetchWaveformFunctionPointer(vi, number_of_samples, &waveform_data, &actual_number_of_samples);
  response->set_status(status);
  if (status == 0) {
    response->set_waveform_data(waveform_data);
    response->set_actual_number_of_samples(actual_number_of_samples);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetABoolean(ServerContext* context, const niFake::GetABooleanRequest* request, niFake::GetABooleanResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetABooleanFunctionPointer = reinterpret_cast<GetABooleanPtr>(shared_library_.get_function_pointer("GetABoolean"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViBoolean a_boolean;

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetANumberFunctionPointer = reinterpret_cast<GetANumberPtr>(shared_library_.get_function_pointer("GetANumber"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt16 a_number;

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetAStringOfFixedMaximumSizeFunctionPointer = reinterpret_cast<GetAStringOfFixedMaximumSizePtr>(shared_library_.get_function_pointer("GetAStringOfFixedMaximumSize"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViChar[] a_string;

  auto status = GetAStringOfFixedMaximumSizeFunctionPointer(vi, &a_string);
  response->set_status(status);
  if (status == 0) {
    response->set_a_string(a_string);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetAStringUsingPythonCode(ServerContext* context, const niFake::GetAStringUsingPythonCodeRequest* request, niFake::GetAStringUsingPythonCodeResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetAStringUsingPythonCodeFunctionPointer = reinterpret_cast<GetAStringUsingPythonCodePtr>(shared_library_.get_function_pointer("GetAStringUsingPythonCode"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt16 a_number = request->a_number();
  ViChar[] a_string;

  auto status = GetAStringUsingPythonCodeFunctionPointer(vi, a_number, &a_string);
  response->set_status(status);
  if (status == 0) {
    response->set_a_string(a_string);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetAnIviDanceString(ServerContext* context, const niFake::GetAnIviDanceStringRequest* request, niFake::GetAnIviDanceStringResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetAnIviDanceStringFunctionPointer = reinterpret_cast<GetAnIviDanceStringPtr>(shared_library_.get_function_pointer("GetAnIviDanceString"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 buffer_size = request->buffer_size();
  ViChar[] a_string;

  auto status = GetAnIviDanceStringFunctionPointer(vi, buffer_size, &a_string);
  response->set_status(status);
  if (status == 0) {
    response->set_a_string(a_string);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetAnIviDanceWithATwistString(ServerContext* context, const niFake::GetAnIviDanceWithATwistStringRequest* request, niFake::GetAnIviDanceWithATwistStringResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetAnIviDanceWithATwistStringFunctionPointer = reinterpret_cast<GetAnIviDanceWithATwistStringPtr>(shared_library_.get_function_pointer("GetAnIviDanceWithATwistString"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 buffer_size = request->buffer_size();
  ViChar[] a_string;
  ViInt32 actual_size;

  auto status = GetAnIviDanceWithATwistStringFunctionPointer(vi, buffer_size, &a_string, &actual_size);
  response->set_status(status);
  if (status == 0) {
    response->set_a_string(a_string);
    response->set_actual_size(actual_size);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetArrayForPythonCodeCustomType(ServerContext* context, const niFake::GetArrayForPythonCodeCustomTypeRequest* request, niFake::GetArrayForPythonCodeCustomTypeResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetArrayForPythonCodeCustomTypeFunctionPointer = reinterpret_cast<GetArrayForPythonCodeCustomTypePtr>(shared_library_.get_function_pointer("GetArrayForPythonCodeCustomType"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 number_of_elements = request->number_of_elements();
  struct CustomStruct[] array_out;

  auto status = GetArrayForPythonCodeCustomTypeFunctionPointer(vi, number_of_elements, &array_out);
  response->set_status(status);
  if (status == 0) {
    response->set_array_out(array_out);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetArrayForPythonCodeDouble(ServerContext* context, const niFake::GetArrayForPythonCodeDoubleRequest* request, niFake::GetArrayForPythonCodeDoubleResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetArrayForPythonCodeDoubleFunctionPointer = reinterpret_cast<GetArrayForPythonCodeDoublePtr>(shared_library_.get_function_pointer("GetArrayForPythonCodeDouble"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 number_of_elements = request->number_of_elements();
  ViReal64[] array_out;

  auto status = GetArrayForPythonCodeDoubleFunctionPointer(vi, number_of_elements, &array_out);
  response->set_status(status);
  if (status == 0) {
    response->set_array_out(array_out);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetArraySizeForPythonCode(ServerContext* context, const niFake::GetArraySizeForPythonCodeRequest* request, niFake::GetArraySizeForPythonCodeResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetArraySizeForPythonCodeFunctionPointer = reinterpret_cast<GetArraySizeForPythonCodePtr>(shared_library_.get_function_pointer("GetArraySizeForPythonCode"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 size_out;

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetArrayUsingIviDanceFunctionPointer = reinterpret_cast<GetArrayUsingIviDancePtr>(shared_library_.get_function_pointer("GetArrayUsingIviDance"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 array_size = request->array_size();
  ViReal64[] array_out;

  auto status = GetArrayUsingIviDanceFunctionPointer(vi, array_size, &array_out);
  response->set_status(status);
  if (status == 0) {
    response->set_array_out(array_out);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetAttributeViBoolean(ServerContext* context, const niFake::GetAttributeViBooleanRequest* request, niFake::GetAttributeViBooleanResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetAttributeViBooleanFunctionPointer = reinterpret_cast<GetAttributeViBooleanPtr>(shared_library_.get_function_pointer("GetAttributeViBoolean"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViConstString channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  ViBoolean attribute_value;

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetAttributeViInt32FunctionPointer = reinterpret_cast<GetAttributeViInt32Ptr>(shared_library_.get_function_pointer("GetAttributeViInt32"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViConstString channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  ViInt32 attribute_value;

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetAttributeViInt64FunctionPointer = reinterpret_cast<GetAttributeViInt64Ptr>(shared_library_.get_function_pointer("GetAttributeViInt64"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViConstString channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  ViInt64 attribute_value;

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetAttributeViReal64FunctionPointer = reinterpret_cast<GetAttributeViReal64Ptr>(shared_library_.get_function_pointer("GetAttributeViReal64"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViConstString channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  ViReal64 attribute_value;

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetAttributeViStringFunctionPointer = reinterpret_cast<GetAttributeViStringPtr>(shared_library_.get_function_pointer("GetAttributeViString"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViConstString channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  ViInt32 buffer_size = request->buffer_size();
  ViChar[] attribute_value;

  auto status = GetAttributeViStringFunctionPointer(vi, channel_name, attribute_id, buffer_size, &attribute_value);
  response->set_status(status);
  if (status == 0) {
    response->set_attribute_value(attribute_value);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetCalDateAndTime(ServerContext* context, const niFake::GetCalDateAndTimeRequest* request, niFake::GetCalDateAndTimeResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetCalDateAndTimeFunctionPointer = reinterpret_cast<GetCalDateAndTimePtr>(shared_library_.get_function_pointer("GetCalDateAndTime"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 cal_type = request->cal_type();
  ViInt32 month;
  ViInt32 day;
  ViInt32 year;
  ViInt32 hour;
  ViInt32 minute;

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetCalIntervalFunctionPointer = reinterpret_cast<GetCalIntervalPtr>(shared_library_.get_function_pointer("GetCalInterval"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 months;

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetCustomTypeFunctionPointer = reinterpret_cast<GetCustomTypePtr>(shared_library_.get_function_pointer("GetCustomType"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetCustomTypeArrayFunctionPointer = reinterpret_cast<GetCustomTypeArrayPtr>(shared_library_.get_function_pointer("GetCustomTypeArray"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 number_of_elements = request->number_of_elements();
  struct CustomStruct[] cs;

  auto status = GetCustomTypeArrayFunctionPointer(vi, number_of_elements, &cs);
  response->set_status(status);
  if (status == 0) {
    response->set_cs(cs);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetEnumValue(ServerContext* context, const niFake::GetEnumValueRequest* request, niFake::GetEnumValueResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetEnumValueFunctionPointer = reinterpret_cast<GetEnumValuePtr>(shared_library_.get_function_pointer("GetEnumValue"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 a_quantity;
  ViInt16 a_turtle;

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetErrorFunctionPointer = reinterpret_cast<GetErrorPtr>(shared_library_.get_function_pointer("GetError"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 buffer_size = request->buffer_size();
  ViStatus error_code;
  ViChar[] description;

  auto status = GetErrorFunctionPointer(vi, &error_code, buffer_size, &description);
  response->set_status(status);
  if (status == 0) {
    response->set_error_code(error_code);
    response->set_description(description);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::GetLastCalDateAndTime(ServerContext* context, const niFake::GetLastCalDateAndTimeRequest* request, niFake::GetLastCalDateAndTimeResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto GetLastCalDateAndTimeFunctionPointer = reinterpret_cast<GetLastCalDateAndTimePtr>(shared_library_.get_function_pointer("GetLastCalDateAndTime"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 cal_type = request->cal_type();
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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto ImportAttributeConfigurationBufferFunctionPointer = reinterpret_cast<ImportAttributeConfigurationBufferPtr>(shared_library_.get_function_pointer("ImportAttributeConfigurationBuffer"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 size_in_bytes = request->size_in_bytes();
  ViInt8[] configuration = request->configuration();

  auto status = ImportAttributeConfigurationBufferFunctionPointer(vi, size_in_bytes, configuration);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::InitWithOptions(ServerContext* context, const niFake::InitWithOptionsRequest* request, niFake::InitWithOptionsResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto InitWithOptionsFunctionPointer = reinterpret_cast<InitWithOptionsPtr>(shared_library_.get_function_pointer("InitWithOptions"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViString resource_name = request->resource_name();
  ViBoolean id_query = request->id_query();
  ViBoolean reset_device = request->reset_device();
  ViConstString option_string = request->option_string().c_str();
  ViSession vi;

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto InitiateFunctionPointer = reinterpret_cast<InitiatePtr>(shared_library_.get_function_pointer("Initiate"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto LockSessionFunctionPointer = reinterpret_cast<LockSessionPtr>(shared_library_.get_function_pointer("LockSession"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViBoolean caller_has_lock;

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto MultipleArrayTypesFunctionPointer = reinterpret_cast<MultipleArrayTypesPtr>(shared_library_.get_function_pointer("MultipleArrayTypes"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 output_array_size = request->output_array_size();
  ViInt32 input_array_sizes = request->input_array_sizes();
  ViReal64[] input_array_of_floats = request->input_array_of_floats();
  ViInt16[] input_array_of_integers = request->input_array_of_integers();
  ViReal64[] output_array;
  ViReal64[] output_array_of_fixed_length;

  auto status = MultipleArrayTypesFunctionPointer(vi, output_array_size, &output_array, &output_array_of_fixed_length, input_array_sizes, input_array_of_floats, input_array_of_integers);
  response->set_status(status);
  if (status == 0) {
    response->set_output_array(output_array);
    response->set_output_array_of_fixed_length(output_array_of_fixed_length);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::MultipleArraysSameSize(ServerContext* context, const niFake::MultipleArraysSameSizeRequest* request, niFake::MultipleArraysSameSizeResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto MultipleArraysSameSizeFunctionPointer = reinterpret_cast<MultipleArraysSameSizePtr>(shared_library_.get_function_pointer("MultipleArraysSameSize"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViReal64[] values1 = request->values1();
  ViReal64[] values2 = request->values2();
  ViReal64[] values3 = request->values3();
  ViReal64[] values4 = request->values4();
  ViInt32 size = request->size();

  auto status = MultipleArraysSameSizeFunctionPointer(vi, values1, values2, values3, values4, size);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::OneInputFunction(ServerContext* context, const niFake::OneInputFunctionRequest* request, niFake::OneInputFunctionResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto OneInputFunctionFunctionPointer = reinterpret_cast<OneInputFunctionPtr>(shared_library_.get_function_pointer("OneInputFunction"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 a_number = request->a_number();

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto ParametersAreMultipleTypesFunctionPointer = reinterpret_cast<ParametersAreMultipleTypesPtr>(shared_library_.get_function_pointer("ParametersAreMultipleTypes"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViBoolean a_boolean = request->a_boolean();
  ViInt32 an_int32 = request->an_int32();
  ViInt64 an_int64 = request->an_int64();
  ViInt16 an_int_enum = request->an_int_enum();
  ViReal64 a_float = request->a_float();
  ViReal64 a_float_enum = request->a_float_enum();
  ViInt32 string_size = request->string_size();
  ViConstString a_string = request->a_string().c_str();

  auto status = ParametersAreMultipleTypesFunctionPointer(vi, a_boolean, an_int32, an_int64, an_int_enum, a_float, a_float_enum, string_size, a_string);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::PoorlyNamedSimpleFunction(ServerContext* context, const niFake::PoorlyNamedSimpleFunctionRequest* request, niFake::PoorlyNamedSimpleFunctionResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto PoorlyNamedSimpleFunctionFunctionPointer = reinterpret_cast<PoorlyNamedSimpleFunctionPtr>(shared_library_.get_function_pointer("PoorlyNamedSimpleFunction"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto ReadFunctionPointer = reinterpret_cast<ReadPtr>(shared_library_.get_function_pointer("Read"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViReal64 maximum_time = request->maximum_time();
  ViReal64 reading;

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto ReadFromChannelFunctionPointer = reinterpret_cast<ReadFromChannelPtr>(shared_library_.get_function_pointer("ReadFromChannel"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViConstString channel_name = request->channel_name().c_str();
  ViInt32 maximum_time = request->maximum_time();
  ViReal64 reading;

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto ReturnANumberAndAStringFunctionPointer = reinterpret_cast<ReturnANumberAndAStringPtr>(shared_library_.get_function_pointer("ReturnANumberAndAString"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt16 a_number;
  ViChar[] a_string;

  auto status = ReturnANumberAndAStringFunctionPointer(vi, &a_number, &a_string);
  response->set_status(status);
  if (status == 0) {
    response->set_a_number(a_number);
    response->set_a_string(a_string);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::ReturnDurationInSeconds(ServerContext* context, const niFake::ReturnDurationInSecondsRequest* request, niFake::ReturnDurationInSecondsResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto ReturnDurationInSecondsFunctionPointer = reinterpret_cast<ReturnDurationInSecondsPtr>(shared_library_.get_function_pointer("ReturnDurationInSeconds"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViReal64 timedelta;

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto ReturnListOfDurationsInSecondsFunctionPointer = reinterpret_cast<ReturnListOfDurationsInSecondsPtr>(shared_library_.get_function_pointer("ReturnListOfDurationsInSeconds"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 number_of_elements = request->number_of_elements();
  ViReal64[] timedeltas;

  auto status = ReturnListOfDurationsInSecondsFunctionPointer(vi, number_of_elements, &timedeltas);
  response->set_status(status);
  if (status == 0) {
    response->set_timedeltas(timedeltas);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::ReturnMultipleTypes(ServerContext* context, const niFake::ReturnMultipleTypesRequest* request, niFake::ReturnMultipleTypesResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto ReturnMultipleTypesFunctionPointer = reinterpret_cast<ReturnMultipleTypesPtr>(shared_library_.get_function_pointer("ReturnMultipleTypes"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 array_size = request->array_size();
  ViInt32 string_size = request->string_size();
  ViBoolean a_boolean;
  ViInt32 an_int32;
  ViInt64 an_int64;
  ViInt16 an_int_enum;
  ViReal64 a_float;
  ViReal64 a_float_enum;
  ViReal64[] an_array;
  ViChar[] a_string;

  auto status = ReturnMultipleTypesFunctionPointer(vi, &a_boolean, &an_int32, &an_int64, &an_int_enum, &a_float, &a_float_enum, array_size, &an_array, string_size, &a_string);
  response->set_status(status);
  if (status == 0) {
    response->set_a_boolean(a_boolean);
    response->set_an_int32(an_int32);
    response->set_an_int64(an_int64);
    response->set_an_int_enum(an_int_enum);
    response->set_a_float(a_float);
    response->set_a_float_enum(a_float_enum);
    response->set_an_array(an_array);
    response->set_a_string(a_string);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::SetAttributeViBoolean(ServerContext* context, const niFake::SetAttributeViBooleanRequest* request, niFake::SetAttributeViBooleanResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto SetAttributeViBooleanFunctionPointer = reinterpret_cast<SetAttributeViBooleanPtr>(shared_library_.get_function_pointer("SetAttributeViBoolean"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViConstString channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  ViBoolean attribute_value = request->attribute_value();

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto SetAttributeViInt32FunctionPointer = reinterpret_cast<SetAttributeViInt32Ptr>(shared_library_.get_function_pointer("SetAttributeViInt32"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViConstString channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  ViInt32 attribute_value = request->attribute_value();

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto SetAttributeViInt64FunctionPointer = reinterpret_cast<SetAttributeViInt64Ptr>(shared_library_.get_function_pointer("SetAttributeViInt64"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViConstString channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  ViInt64 attribute_value = request->attribute_value();

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto SetAttributeViReal64FunctionPointer = reinterpret_cast<SetAttributeViReal64Ptr>(shared_library_.get_function_pointer("SetAttributeViReal64"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViConstString channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  ViReal64 attribute_value = request->attribute_value();

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto SetAttributeViStringFunctionPointer = reinterpret_cast<SetAttributeViStringPtr>(shared_library_.get_function_pointer("SetAttributeViString"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViConstString channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  ViConstString attribute_value = request->attribute_value().c_str();

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto SetCustomTypeFunctionPointer = reinterpret_cast<SetCustomTypePtr>(shared_library_.get_function_pointer("SetCustomType"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto SetCustomTypeArrayFunctionPointer = reinterpret_cast<SetCustomTypeArrayPtr>(shared_library_.get_function_pointer("SetCustomTypeArray"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 number_of_elements = request->number_of_elements();
  struct CustomStruct[] cs = request->cs();

  auto status = SetCustomTypeArrayFunctionPointer(vi, number_of_elements, cs);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::StringValuedEnumInputFunctionWithDefaults(ServerContext* context, const niFake::StringValuedEnumInputFunctionWithDefaultsRequest* request, niFake::StringValuedEnumInputFunctionWithDefaultsResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto StringValuedEnumInputFunctionWithDefaultsFunctionPointer = reinterpret_cast<StringValuedEnumInputFunctionWithDefaultsPtr>(shared_library_.get_function_pointer("StringValuedEnumInputFunctionWithDefaults"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViConstString a_mobile_o_s_name = request->a_mobile_o_s_name().c_str();

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto TwoInputFunctionFunctionPointer = reinterpret_cast<TwoInputFunctionPtr>(shared_library_.get_function_pointer("TwoInputFunction"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViReal64 a_number = request->a_number();
  ViString a_string = request->a_string();

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto UnlockSessionFunctionPointer = reinterpret_cast<UnlockSessionPtr>(shared_library_.get_function_pointer("UnlockSession"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViBoolean caller_has_lock;

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto Use64BitNumberFunctionPointer = reinterpret_cast<Use64BitNumberPtr>(shared_library_.get_function_pointer("Use64BitNumber"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt64 input = request->input();
  ViInt64 output;

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto WriteWaveformFunctionPointer = reinterpret_cast<WriteWaveformPtr>(shared_library_.get_function_pointer("WriteWaveform"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 number_of_samples = request->number_of_samples();
  ViReal64[] waveform = request->waveform();

  auto status = WriteWaveformFunctionPointer(vi, number_of_samples, waveform);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::close(ServerContext* context, const niFake::closeRequest* request, niFake::closeResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto closeFunctionPointer = reinterpret_cast<closePtr>(shared_library_.get_function_pointer("close"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto error_messageFunctionPointer = reinterpret_cast<error_messagePtr>(shared_library_.get_function_pointer("error_message"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViStatus error_code = request->error_code();
  ViChar[] error_message;

  auto status = error_messageFunctionPointer(vi, error_code, &error_message);
  response->set_status(status);
  if (status == 0) {
    response->set_error_message(error_message);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status NiFakeService::fancy_self_test(ServerContext* context, const niFake::fancy_self_testRequest* request, niFake::fancy_self_testResponse* response)
{
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto fancy_self_testFunctionPointer = reinterpret_cast<fancy_self_testPtr>(shared_library_.get_function_pointer("fancy_self_test"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());

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
  shared_library_.load();
  if (!shared_library_.is_loaded()) {
    return Status(StatusCode::NOT_FOUND, "Driver DLL was not found.");
  }
  auto self_testFunctionPointer = reinterpret_cast<self_testPtr>(shared_library_.get_function_pointer("self_test"));
  if (method_name == nullptr) {
    return Status(StatusCode::NOT_FOUND, "The requested driver method wasn't found in the library.");
  }

  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt16 self_test_result;
  ViChar[] self_test_message;

  auto status = self_testFunctionPointer(vi, &self_test_result, &self_test_message);
  response->set_status(status);
  if (status == 0) {
    response->set_self_test_result(self_test_result);
    response->set_self_test_message(self_test_message);
  }

  return Status::OK;
}

