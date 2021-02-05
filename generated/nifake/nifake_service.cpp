// This file was generated
//---------------------------------------------------------------------
//---------------------------------------------------------------------
#include <thread>
#include <sstream>
#include <fstream>
#include <iostream>
#include <nifake_service.h>
#include <atomic>

namespace ni
{
namespace fake
{
namespace grpc
{
  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  using internal = ni::hardware::grpc::internal;
  using niFake_AbortPtr = int (*)(std::uint64_t);
  using niFake_EnumInputFunctionWithDefaultsPtr = int (*)(std::uint64_t, std::uint32_t);
  using niFake_GetABooleanPtr = int (*)(std::uint64_t, bool*);
  using niFake_GetANumberPtr = int (*)(std::uint64_t, std::uint32_t*);
  using niFake_GetArraySizeForPythonCodePtr = int (*)(std::uint64_t, std::int32_t*);
  using niFake_GetAttributeViBooleanPtr = int (*)(std::uint64_t, std::string, niFakeAttributes, bool*);
  using niFake_GetAttributeViInt32Ptr = int (*)(std::uint64_t, std::string, niFakeAttributes, std::int32_t*);
  using niFake_GetAttributeViInt64Ptr = int (*)(std::uint64_t, std::string, niFakeAttributes, std::int64_t*);
  using niFake_GetAttributeViReal64Ptr = int (*)(std::uint64_t, std::string, niFakeAttributes, double*);
  using niFake_GetCalDateAndTimePtr = int (*)(std::uint64_t, std::int32_t, std::int32_t*, std::int32_t*, std::int32_t*, std::int32_t*, std::int32_t*);
  using niFake_GetCalIntervalPtr = int (*)(std::uint64_t, std::int32_t*);
  using niFake_GetCustomTypePtr = int (*)(std::uint64_t, std::uint64_t*);
  using niFake_GetEnumValuePtr = int (*)(std::uint64_t, std::int32_t*, std::uint32_t*);
  using niFake_GetLastCalDateAndTimePtr = int (*)(std::uint64_t, std::int32_t, google.protobuf.Timestamp*);
  using niFake_InitWithOptionsPtr = int (*)(std::string, bool, bool, std::string, std::uint64_t*);
  using niFake_InitiatePtr = int (*)(std::uint64_t);
  using niFake_LockSessionPtr = int (*)(std::uint64_t, bool*);
  using niFake_OneInputFunctionPtr = int (*)(std::uint64_t, std::int32_t);
  using niFake_ParametersAreMultipleTypesPtr = int (*)(std::uint64_t, bool, std::int32_t, std::int64_t, std::uint32_t, double, double, std::int32_t, std::string);
  using niFake_PoorlyNamedSimpleFunctionPtr = int (*)(std::uint64_t);
  using niFake_ReadPtr = int (*)(std::uint64_t, double, double*);
  using niFake_ReadFromChannelPtr = int (*)(std::uint64_t, std::string, std::int32_t, double*);
  using niFake_ReturnDurationInSecondsPtr = int (*)(std::uint64_t, double*);
  using niFake_SetAttributeViBooleanPtr = int (*)(std::uint64_t, std::string, niFakeAttributes, bool);
  using niFake_SetAttributeViInt32Ptr = int (*)(std::uint64_t, std::string, niFakeAttributes, std::int32_t);
  using niFake_SetAttributeViInt64Ptr = int (*)(std::uint64_t, std::string, niFakeAttributes, std::int64_t);
  using niFake_SetAttributeViReal64Ptr = int (*)(std::uint64_t, std::string, niFakeAttributes, double);
  using niFake_SetAttributeViStringPtr = int (*)(std::uint64_t, std::string, niFakeAttributes, std::string);
  using niFake_SetCustomTypePtr = int (*)(std::uint64_t, std::uint64_t);
  using niFake_StringValuedEnumInputFunctionWithDefaultsPtr = int (*)(std::uint64_t, std::string);
  using niFake_TwoInputFunctionPtr = int (*)(std::uint64_t, double, std::string);
  using niFake_UnlockSessionPtr = int (*)(std::uint64_t, bool*);
  using niFake_Use64BitNumberPtr = int (*)(std::uint64_t, std::int64_t, std::int64_t*);
  using niFake_closePtr = int (*)(std::uint64_t);
  using niFake_fancy_self_testPtr = int (*)(std::uint64_t);

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
  grpc::Status NiFakeService::Abort(grpc::ServerContext* context, const nifake::AbortRequest* request, nifake::AbortResponse* response)
  {
    shared_library_ -> load();
    if (!shared_library_ -> is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto AbortFunctionPointer = reinterpret_cast<niFake_AbortPtr>(shared_library_ -> get_function_pointer("niFake_Abort"));
    if (AbortFunctionPointer == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_Abort");
    }

    std::uint64_t vi = request->vi());
    auto status = AbortFunctionPointer(vi);
    response->set_status(status);
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::AcceptListOfDurationsInSeconds(grpc::ServerContext* context, const nifake::AcceptListOfDurationsInSecondsRequest* request, nifake::AcceptListOfDurationsInSecondsResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::BoolArrayOutputFunction(grpc::ServerContext* context, const nifake::BoolArrayOutputFunctionRequest* request, nifake::BoolArrayOutputFunctionResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::DoubleAllTheNums(grpc::ServerContext* context, const nifake::DoubleAllTheNumsRequest* request, nifake::DoubleAllTheNumsResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::EnumArrayOutputFunction(grpc::ServerContext* context, const nifake::EnumArrayOutputFunctionRequest* request, nifake::EnumArrayOutputFunctionResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::EnumInputFunctionWithDefaults(grpc::ServerContext* context, const nifake::EnumInputFunctionWithDefaultsRequest* request, nifake::EnumInputFunctionWithDefaultsResponse* response)
  {
    shared_library_ -> load();
    if (!shared_library_ -> is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto EnumInputFunctionWithDefaultsFunctionPointer = reinterpret_cast<niFake_EnumInputFunctionWithDefaultsPtr>(shared_library_ -> get_function_pointer("niFake_EnumInputFunctionWithDefaults"));
    if (EnumInputFunctionWithDefaultsFunctionPointer == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_EnumInputFunctionWithDefaults");
    }

    std::uint64_t vi = request->vi());
    std::uint32_t a_turtle = request->a_turtle();
    auto status = EnumInputFunctionWithDefaultsFunctionPointer(vi, a_turtle);
    response->set_status(status);
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::ExportAttributeConfigurationBuffer(grpc::ServerContext* context, const nifake::ExportAttributeConfigurationBufferRequest* request, nifake::ExportAttributeConfigurationBufferResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::FetchWaveform(grpc::ServerContext* context, const nifake::FetchWaveformRequest* request, nifake::FetchWaveformResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetABoolean(grpc::ServerContext* context, const nifake::GetABooleanRequest* request, nifake::GetABooleanResponse* response)
  {
    shared_library_ -> load();
    if (!shared_library_ -> is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto GetABooleanFunctionPointer = reinterpret_cast<niFake_GetABooleanPtr>(shared_library_ -> get_function_pointer("niFake_GetABoolean"));
    if (GetABooleanFunctionPointer == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_GetABoolean");
    }

    std::uint64_t vi = request->vi());
    bool a_boolean;
    auto status = GetABooleanFunctionPointer(vi, &a_boolean);
    response->set_status(status);
    if (status == 0) {
      response->set_a_boolean(a_boolean);
    }
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetANumber(grpc::ServerContext* context, const nifake::GetANumberRequest* request, nifake::GetANumberResponse* response)
  {
    shared_library_ -> load();
    if (!shared_library_ -> is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto GetANumberFunctionPointer = reinterpret_cast<niFake_GetANumberPtr>(shared_library_ -> get_function_pointer("niFake_GetANumber"));
    if (GetANumberFunctionPointer == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_GetANumber");
    }

    std::uint64_t vi = request->vi());
    std::uint32_t a_number;
    auto status = GetANumberFunctionPointer(vi, &a_number);
    response->set_status(status);
    if (status == 0) {
      response->set_a_number(a_number);
    }
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetAStringOfFixedMaximumSize(grpc::ServerContext* context, const nifake::GetAStringOfFixedMaximumSizeRequest* request, nifake::GetAStringOfFixedMaximumSizeResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetAStringUsingPythonCode(grpc::ServerContext* context, const nifake::GetAStringUsingPythonCodeRequest* request, nifake::GetAStringUsingPythonCodeResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetAnIviDanceString(grpc::ServerContext* context, const nifake::GetAnIviDanceStringRequest* request, nifake::GetAnIviDanceStringResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetAnIviDanceWithATwistString(grpc::ServerContext* context, const nifake::GetAnIviDanceWithATwistStringRequest* request, nifake::GetAnIviDanceWithATwistStringResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetArrayForPythonCodeCustomType(grpc::ServerContext* context, const nifake::GetArrayForPythonCodeCustomTypeRequest* request, nifake::GetArrayForPythonCodeCustomTypeResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetArrayForPythonCodeDouble(grpc::ServerContext* context, const nifake::GetArrayForPythonCodeDoubleRequest* request, nifake::GetArrayForPythonCodeDoubleResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetArraySizeForPythonCode(grpc::ServerContext* context, const nifake::GetArraySizeForPythonCodeRequest* request, nifake::GetArraySizeForPythonCodeResponse* response)
  {
    shared_library_ -> load();
    if (!shared_library_ -> is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto GetArraySizeForPythonCodeFunctionPointer = reinterpret_cast<niFake_GetArraySizeForPythonCodePtr>(shared_library_ -> get_function_pointer("niFake_GetArraySizeForPythonCode"));
    if (GetArraySizeForPythonCodeFunctionPointer == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_GetArraySizeForPythonCode");
    }

    std::uint64_t vi = request->vi());
    std::int32_t size_out;
    auto status = GetArraySizeForPythonCodeFunctionPointer(vi, &size_out);
    response->set_status(status);
    if (status == 0) {
      response->set_size_out(size_out);
    }
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetArrayUsingIviDance(grpc::ServerContext* context, const nifake::GetArrayUsingIviDanceRequest* request, nifake::GetArrayUsingIviDanceResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetCalInterval(grpc::ServerContext* context, const nifake::GetCalIntervalRequest* request, nifake::GetCalIntervalResponse* response)
  {
    shared_library_ -> load();
    if (!shared_library_ -> is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto GetCalIntervalFunctionPointer = reinterpret_cast<niFake_GetCalIntervalPtr>(shared_library_ -> get_function_pointer("niFake_GetCalInterval"));
    if (GetCalIntervalFunctionPointer == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_GetCalInterval");
    }

    std::uint64_t vi = request->vi());
    std::int32_t months;
    auto status = GetCalIntervalFunctionPointer(vi, &months);
    response->set_status(status);
    if (status == 0) {
      response->set_months(months);
    }
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetCustomType(grpc::ServerContext* context, const nifake::GetCustomTypeRequest* request, nifake::GetCustomTypeResponse* response)
  {
    shared_library_ -> load();
    if (!shared_library_ -> is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto GetCustomTypeFunctionPointer = reinterpret_cast<niFake_GetCustomTypePtr>(shared_library_ -> get_function_pointer("niFake_GetCustomType"));
    if (GetCustomTypeFunctionPointer == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_GetCustomType");
    }

    std::uint64_t vi = request->vi());
    std::uint64_t cs;
    auto status = GetCustomTypeFunctionPointer(vi, &cs);
    response->set_status(status);
    if (status == 0) {
      response->set_cs(cs);
    }
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetCustomTypeArray(grpc::ServerContext* context, const nifake::GetCustomTypeArrayRequest* request, nifake::GetCustomTypeArrayResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::GetEnumValue(grpc::ServerContext* context, const nifake::GetEnumValueRequest* request, nifake::GetEnumValueResponse* response)
  {
    shared_library_ -> load();
    if (!shared_library_ -> is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto GetEnumValueFunctionPointer = reinterpret_cast<niFake_GetEnumValuePtr>(shared_library_ -> get_function_pointer("niFake_GetEnumValue"));
    if (GetEnumValueFunctionPointer == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_GetEnumValue");
    }

    std::uint64_t vi = request->vi());
    std::int32_t a_quantity;
    std::uint32_t a_turtle;
    auto status = GetEnumValueFunctionPointer(vi, &a_quantity, &a_turtle);
    response->set_status(status);
    if (status == 0) {
      response->set_a_quantity(a_quantity);
      response->set_a_turtle(a_turtle);
    }
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::ImportAttributeConfigurationBuffer(grpc::ServerContext* context, const nifake::ImportAttributeConfigurationBufferRequest* request, nifake::ImportAttributeConfigurationBufferResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::LockSession(grpc::ServerContext* context, const nifake::LockSessionRequest* request, nifake::LockSessionResponse* response)
  {
    shared_library_ -> load();
    if (!shared_library_ -> is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto LockSessionFunctionPointer = reinterpret_cast<niFake_LockSessionPtr>(shared_library_ -> get_function_pointer("niFake_LockSession"));
    if (LockSessionFunctionPointer == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_LockSession");
    }

    std::uint64_t vi = request->vi());
    bool caller_has_lock;
    auto status = LockSessionFunctionPointer(vi, &caller_has_lock);
    response->set_status(status);
    if (status == 0) {
      response->set_caller_has_lock(caller_has_lock);
    }
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::MultipleArrayTypes(grpc::ServerContext* context, const nifake::MultipleArrayTypesRequest* request, nifake::MultipleArrayTypesResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::MultipleArraysSameSize(grpc::ServerContext* context, const nifake::MultipleArraysSameSizeRequest* request, nifake::MultipleArraysSameSizeResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::OneInputFunction(grpc::ServerContext* context, const nifake::OneInputFunctionRequest* request, nifake::OneInputFunctionResponse* response)
  {
    shared_library_ -> load();
    if (!shared_library_ -> is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto OneInputFunctionFunctionPointer = reinterpret_cast<niFake_OneInputFunctionPtr>(shared_library_ -> get_function_pointer("niFake_OneInputFunction"));
    if (OneInputFunctionFunctionPointer == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_OneInputFunction");
    }

    std::uint64_t vi = request->vi());
    std::int32_t a_number = request->a_number();
    auto status = OneInputFunctionFunctionPointer(vi, a_number);
    response->set_status(status);
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::ParametersAreMultipleTypes(grpc::ServerContext* context, const nifake::ParametersAreMultipleTypesRequest* request, nifake::ParametersAreMultipleTypesResponse* response)
  {
    shared_library_ -> load();
    if (!shared_library_ -> is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto ParametersAreMultipleTypesFunctionPointer = reinterpret_cast<niFake_ParametersAreMultipleTypesPtr>(shared_library_ -> get_function_pointer("niFake_ParametersAreMultipleTypes"));
    if (ParametersAreMultipleTypesFunctionPointer == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_ParametersAreMultipleTypes");
    }

    std::uint64_t vi = request->vi());
    bool a_boolean = request->a_boolean();
    std::int32_t an_int32 = request->an_int32();
    std::int64_t an_int64 = request->an_int64();
    std::uint32_t an_int_enum = request->an_int_enum();
    double a_float = request->a_float();
    double a_float_enum = request->a_float_enum();
    std::int32_t string_size = request->string_size();
    std::string a_string = request->a_string().c_str();
    auto status = ParametersAreMultipleTypesFunctionPointer(vi, a_boolean, an_int32, an_int64, an_int_enum, a_float, a_float_enum, string_size, a_string);
    response->set_status(status);
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::PoorlyNamedSimpleFunction(grpc::ServerContext* context, const nifake::PoorlyNamedSimpleFunctionRequest* request, nifake::PoorlyNamedSimpleFunctionResponse* response)
  {
    shared_library_ -> load();
    if (!shared_library_ -> is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto PoorlyNamedSimpleFunctionFunctionPointer = reinterpret_cast<niFake_PoorlyNamedSimpleFunctionPtr>(shared_library_ -> get_function_pointer("niFake_PoorlyNamedSimpleFunction"));
    if (PoorlyNamedSimpleFunctionFunctionPointer == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_PoorlyNamedSimpleFunction");
    }

    std::uint64_t vi = request->vi());
    auto status = PoorlyNamedSimpleFunctionFunctionPointer(vi);
    response->set_status(status);
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::Read(grpc::ServerContext* context, const nifake::ReadRequest* request, nifake::ReadResponse* response)
  {
    shared_library_ -> load();
    if (!shared_library_ -> is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto ReadFunctionPointer = reinterpret_cast<niFake_ReadPtr>(shared_library_ -> get_function_pointer("niFake_Read"));
    if (ReadFunctionPointer == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_Read");
    }

    std::uint64_t vi = request->vi());
    double maximum_time = request->maximum_time();
    double reading;
    auto status = ReadFunctionPointer(vi, maximum_time, &reading);
    response->set_status(status);
    if (status == 0) {
      response->set_reading(reading);
    }
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::ReadFromChannel(grpc::ServerContext* context, const nifake::ReadFromChannelRequest* request, nifake::ReadFromChannelResponse* response)
  {
    shared_library_ -> load();
    if (!shared_library_ -> is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto ReadFromChannelFunctionPointer = reinterpret_cast<niFake_ReadFromChannelPtr>(shared_library_ -> get_function_pointer("niFake_ReadFromChannel"));
    if (ReadFromChannelFunctionPointer == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_ReadFromChannel");
    }

    std::uint64_t vi = request->vi());
    std::string channel_name = request->channel_name().c_str();
    std::int32_t maximum_time = request->maximum_time();
    double reading;
    auto status = ReadFromChannelFunctionPointer(vi, channel_name, maximum_time, &reading);
    response->set_status(status);
    if (status == 0) {
      response->set_reading(reading);
    }
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::ReturnANumberAndAString(grpc::ServerContext* context, const nifake::ReturnANumberAndAStringRequest* request, nifake::ReturnANumberAndAStringResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::ReturnDurationInSeconds(grpc::ServerContext* context, const nifake::ReturnDurationInSecondsRequest* request, nifake::ReturnDurationInSecondsResponse* response)
  {
    shared_library_ -> load();
    if (!shared_library_ -> is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto ReturnDurationInSecondsFunctionPointer = reinterpret_cast<niFake_ReturnDurationInSecondsPtr>(shared_library_ -> get_function_pointer("niFake_ReturnDurationInSeconds"));
    if (ReturnDurationInSecondsFunctionPointer == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_ReturnDurationInSeconds");
    }

    std::uint64_t vi = request->vi());
    double timedelta;
    auto status = ReturnDurationInSecondsFunctionPointer(vi, &timedelta);
    response->set_status(status);
    if (status == 0) {
      response->set_timedelta(timedelta);
    }
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::ReturnListOfDurationsInSeconds(grpc::ServerContext* context, const nifake::ReturnListOfDurationsInSecondsRequest* request, nifake::ReturnListOfDurationsInSecondsResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::ReturnMultipleTypes(grpc::ServerContext* context, const nifake::ReturnMultipleTypesRequest* request, nifake::ReturnMultipleTypesResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::SetCustomType(grpc::ServerContext* context, const nifake::SetCustomTypeRequest* request, nifake::SetCustomTypeResponse* response)
  {
    shared_library_ -> load();
    if (!shared_library_ -> is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto SetCustomTypeFunctionPointer = reinterpret_cast<niFake_SetCustomTypePtr>(shared_library_ -> get_function_pointer("niFake_SetCustomType"));
    if (SetCustomTypeFunctionPointer == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_SetCustomType");
    }

    std::uint64_t vi = request->vi());
    std::uint64_t cs = request->cs();
    auto status = SetCustomTypeFunctionPointer(vi, cs);
    response->set_status(status);
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::SetCustomTypeArray(grpc::ServerContext* context, const nifake::SetCustomTypeArrayRequest* request, nifake::SetCustomTypeArrayResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::StringValuedEnumInputFunctionWithDefaults(grpc::ServerContext* context, const nifake::StringValuedEnumInputFunctionWithDefaultsRequest* request, nifake::StringValuedEnumInputFunctionWithDefaultsResponse* response)
  {
    shared_library_ -> load();
    if (!shared_library_ -> is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto StringValuedEnumInputFunctionWithDefaultsFunctionPointer = reinterpret_cast<niFake_StringValuedEnumInputFunctionWithDefaultsPtr>(shared_library_ -> get_function_pointer("niFake_StringValuedEnumInputFunctionWithDefaults"));
    if (StringValuedEnumInputFunctionWithDefaultsFunctionPointer == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_StringValuedEnumInputFunctionWithDefaults");
    }

    std::uint64_t vi = request->vi());
    std::string a_mobile_o_s_name = request->a_mobile_o_s_name().c_str();
    auto status = StringValuedEnumInputFunctionWithDefaultsFunctionPointer(vi, a_mobile_o_s_name);
    response->set_status(status);
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::TwoInputFunction(grpc::ServerContext* context, const nifake::TwoInputFunctionRequest* request, nifake::TwoInputFunctionResponse* response)
  {
    shared_library_ -> load();
    if (!shared_library_ -> is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto TwoInputFunctionFunctionPointer = reinterpret_cast<niFake_TwoInputFunctionPtr>(shared_library_ -> get_function_pointer("niFake_TwoInputFunction"));
    if (TwoInputFunctionFunctionPointer == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_TwoInputFunction");
    }

    std::uint64_t vi = request->vi());
    double a_number = request->a_number();
    std::string a_string = request->a_string();
    auto status = TwoInputFunctionFunctionPointer(vi, a_number, a_string);
    response->set_status(status);
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::UnlockSession(grpc::ServerContext* context, const nifake::UnlockSessionRequest* request, nifake::UnlockSessionResponse* response)
  {
    shared_library_ -> load();
    if (!shared_library_ -> is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto UnlockSessionFunctionPointer = reinterpret_cast<niFake_UnlockSessionPtr>(shared_library_ -> get_function_pointer("niFake_UnlockSession"));
    if (UnlockSessionFunctionPointer == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_UnlockSession");
    }

    std::uint64_t vi = request->vi());
    bool caller_has_lock;
    auto status = UnlockSessionFunctionPointer(vi, &caller_has_lock);
    response->set_status(status);
    if (status == 0) {
      response->set_caller_has_lock(caller_has_lock);
    }
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::Use64BitNumber(grpc::ServerContext* context, const nifake::Use64BitNumberRequest* request, nifake::Use64BitNumberResponse* response)
  {
    shared_library_ -> load();
    if (!shared_library_ -> is_loaded()) {
      std::string message("The library could not be loaded: ");
      message += driver_api_library_name;
      return grpc::Status(grpc::StatusCode::NOT_FOUND, message.c_str());
    }
    auto Use64BitNumberFunctionPointer = reinterpret_cast<niFake_Use64BitNumberPtr>(shared_library_ -> get_function_pointer("niFake_Use64BitNumber"));
    if (Use64BitNumberFunctionPointer == nullptr) {
      return grpc::Status(grpc::StatusCode::NOT_FOUND, "The requested function was not found: niFake_Use64BitNumber");
    }

    std::uint64_t vi = request->vi());
    std::int64_t input = request->input();
    std::int64_t output;
    auto status = Use64BitNumberFunctionPointer(vi, input, &output);
    response->set_status(status);
    if (status == 0) {
      response->set_output(output);
    }
    return grpc::Status::OK;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  grpc::Status NiFakeService::WriteWaveform(grpc::ServerContext* context, const nifake::WriteWaveformRequest* request, nifake::WriteWaveformResponse* response)
  {
    return grpc::Status(grpc::StatusCode::NOT_IMPLEMENTED, "TODO: This server handler has not been implemented.");
  }

} // namespace grpc
} // namespace fake
} // namespace ni
