// This file was generated
//---------------------------------------------------------------------
//---------------------------------------------------------------------
#include <thread>
#include <sstream>
#include <fstream>
#include <iostream>
#include <nifake.h>
#include <nifake_server.h>
#include <nifake.grpc.h>
#include <atomic>

//---------------------------------------------------------------------
//---------------------------------------------------------------------
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using grpc::ServerWriter;

static bool s_HasSession;
static std::atomic<unsigned int> s_IdleCount;

//---------------------------------------------------------------------
//---------------------------------------------------------------------
using namespace std;

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::Abort(ServerContext* context, const niFake::AbortRequest* request, niFake::AbortResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  auto status = Abort(vi);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::AcceptListOfDurationsInSeconds(ServerContext* context, const niFake::AcceptListOfDurationsInSecondsRequest* request, niFake::AcceptListOfDurationsInSecondsResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 count = request->count();
  ViReal64[] delays = request->delays();
  auto status = AcceptListOfDurationsInSeconds(vi, count, delays);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::BoolArrayOutputFunction(ServerContext* context, const niFake::BoolArrayOutputFunctionRequest* request, niFake::BoolArrayOutputFunctionResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 number_of_elements = request->number_of_elements();
  ViBoolean[] an_array;
  auto status = BoolArrayOutputFunction(vi, number_of_elements, &an_array);
  response->set_status(status);
  if (status == 0) {
    response->set_an_array(an_array);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::DoubleAllTheNums(ServerContext* context, const niFake::DoubleAllTheNumsRequest* request, niFake::DoubleAllTheNumsResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 number_count = request->number_count();
  ViReal64[] numbers = request->numbers();
  auto status = DoubleAllTheNums(vi, number_count, numbers);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::EnumArrayOutputFunction(ServerContext* context, const niFake::EnumArrayOutputFunctionRequest* request, niFake::EnumArrayOutputFunctionResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 number_of_elements = request->number_of_elements();
  ViInt16[] an_array;
  auto status = EnumArrayOutputFunction(vi, number_of_elements, &an_array);
  response->set_status(status);
  if (status == 0) {
    response->set_an_array(an_array);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::EnumInputFunctionWithDefaults(ServerContext* context, const niFake::EnumInputFunctionWithDefaultsRequest* request, niFake::EnumInputFunctionWithDefaultsResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt16 a_turtle = request->a_turtle();
  auto status = EnumInputFunctionWithDefaults(vi, a_turtle);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::ExportAttributeConfigurationBuffer(ServerContext* context, const niFake::ExportAttributeConfigurationBufferRequest* request, niFake::ExportAttributeConfigurationBufferResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 size_in_bytes = request->size_in_bytes();
  ViInt8[] configuration;
  auto status = ExportAttributeConfigurationBuffer(vi, size_in_bytes, &configuration);
  response->set_status(status);
  if (status == 0) {
    response->set_configuration(configuration);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::FetchWaveform(ServerContext* context, const niFake::FetchWaveformRequest* request, niFake::FetchWaveformResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 number_of_samples = request->number_of_samples();
  ViReal64[] waveform_data;
  ViInt32 actual_number_of_samples;
  auto status = FetchWaveform(vi, number_of_samples, &waveform_data, &actual_number_of_samples);
  response->set_status(status);
  if (status == 0) {
    response->set_waveform_data(waveform_data);
    response->set_actual_number_of_samples(actual_number_of_samples);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::GetABoolean(ServerContext* context, const niFake::GetABooleanRequest* request, niFake::GetABooleanResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViBoolean a_boolean;
  auto status = GetABoolean(vi, &a_boolean);
  response->set_status(status);
  if (status == 0) {
    response->set_a_boolean(a_boolean);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::GetANumber(ServerContext* context, const niFake::GetANumberRequest* request, niFake::GetANumberResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt16 a_number;
  auto status = GetANumber(vi, &a_number);
  response->set_status(status);
  if (status == 0) {
    response->set_a_number(a_number);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::GetAStringOfFixedMaximumSize(ServerContext* context, const niFake::GetAStringOfFixedMaximumSizeRequest* request, niFake::GetAStringOfFixedMaximumSizeResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViChar[] a_string;
  auto status = GetAStringOfFixedMaximumSize(vi, &a_string);
  response->set_status(status);
  if (status == 0) {
    response->set_a_string(a_string);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::GetAStringUsingPythonCode(ServerContext* context, const niFake::GetAStringUsingPythonCodeRequest* request, niFake::GetAStringUsingPythonCodeResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt16 a_number = request->a_number();
  ViChar[] a_string;
  auto status = GetAStringUsingPythonCode(vi, a_number, &a_string);
  response->set_status(status);
  if (status == 0) {
    response->set_a_string(a_string);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::GetAnIviDanceString(ServerContext* context, const niFake::GetAnIviDanceStringRequest* request, niFake::GetAnIviDanceStringResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 buffer_size = request->buffer_size();
  ViChar[] a_string;
  auto status = GetAnIviDanceString(vi, buffer_size, &a_string);
  response->set_status(status);
  if (status == 0) {
    response->set_a_string(a_string);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::GetAnIviDanceWithATwistString(ServerContext* context, const niFake::GetAnIviDanceWithATwistStringRequest* request, niFake::GetAnIviDanceWithATwistStringResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 buffer_size = request->buffer_size();
  ViChar[] a_string;
  ViInt32 actual_size;
  auto status = GetAnIviDanceWithATwistString(vi, buffer_size, &a_string, &actual_size);
  response->set_status(status);
  if (status == 0) {
    response->set_a_string(a_string);
    response->set_actual_size(actual_size);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::GetArrayForPythonCodeCustomType(ServerContext* context, const niFake::GetArrayForPythonCodeCustomTypeRequest* request, niFake::GetArrayForPythonCodeCustomTypeResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 number_of_elements = request->number_of_elements();
  struct CustomStruct[] array_out;
  auto status = GetArrayForPythonCodeCustomType(vi, number_of_elements, &array_out);
  response->set_status(status);
  if (status == 0) {
    response->set_array_out(array_out);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::GetArrayForPythonCodeDouble(ServerContext* context, const niFake::GetArrayForPythonCodeDoubleRequest* request, niFake::GetArrayForPythonCodeDoubleResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 number_of_elements = request->number_of_elements();
  ViReal64[] array_out;
  auto status = GetArrayForPythonCodeDouble(vi, number_of_elements, &array_out);
  response->set_status(status);
  if (status == 0) {
    response->set_array_out(array_out);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::GetArraySizeForPythonCode(ServerContext* context, const niFake::GetArraySizeForPythonCodeRequest* request, niFake::GetArraySizeForPythonCodeResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 size_out;
  auto status = GetArraySizeForPythonCode(vi, &size_out);
  response->set_status(status);
  if (status == 0) {
    response->set_size_out(size_out);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::GetArrayUsingIviDance(ServerContext* context, const niFake::GetArrayUsingIviDanceRequest* request, niFake::GetArrayUsingIviDanceResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 array_size = request->array_size();
  ViReal64[] array_out;
  auto status = GetArrayUsingIviDance(vi, array_size, &array_out);
  response->set_status(status);
  if (status == 0) {
    response->set_array_out(array_out);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::GetAttributeViBoolean(ServerContext* context, const niFake::GetAttributeViBooleanRequest* request, niFake::GetAttributeViBooleanResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViConstString channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  ViBoolean attribute_value;
  auto status = GetAttributeViBoolean(vi, channel_name, attribute_id, &attribute_value);
  response->set_status(status);
  if (status == 0) {
    response->set_attribute_value(attribute_value);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::GetAttributeViInt32(ServerContext* context, const niFake::GetAttributeViInt32Request* request, niFake::GetAttributeViInt32Response* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViConstString channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  ViInt32 attribute_value;
  auto status = GetAttributeViInt32(vi, channel_name, attribute_id, &attribute_value);
  response->set_status(status);
  if (status == 0) {
    response->set_attribute_value(attribute_value);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::GetAttributeViInt64(ServerContext* context, const niFake::GetAttributeViInt64Request* request, niFake::GetAttributeViInt64Response* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViConstString channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  ViInt64 attribute_value;
  auto status = GetAttributeViInt64(vi, channel_name, attribute_id, &attribute_value);
  response->set_status(status);
  if (status == 0) {
    response->set_attribute_value(attribute_value);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::GetAttributeViReal64(ServerContext* context, const niFake::GetAttributeViReal64Request* request, niFake::GetAttributeViReal64Response* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViConstString channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  ViReal64 attribute_value;
  auto status = GetAttributeViReal64(vi, channel_name, attribute_id, &attribute_value);
  response->set_status(status);
  if (status == 0) {
    response->set_attribute_value(attribute_value);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::GetAttributeViString(ServerContext* context, const niFake::GetAttributeViStringRequest* request, niFake::GetAttributeViStringResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViConstString channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  ViInt32 buffer_size = request->buffer_size();
  ViChar[] attribute_value;
  auto status = GetAttributeViString(vi, channel_name, attribute_id, buffer_size, &attribute_value);
  response->set_status(status);
  if (status == 0) {
    response->set_attribute_value(attribute_value);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::GetCalDateAndTime(ServerContext* context, const niFake::GetCalDateAndTimeRequest* request, niFake::GetCalDateAndTimeResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 cal_type = request->cal_type();
  ViInt32 month;
  ViInt32 day;
  ViInt32 year;
  ViInt32 hour;
  ViInt32 minute;
  auto status = GetCalDateAndTime(vi, cal_type, &month, &day, &year, &hour, &minute);
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
Status niFakeService::GetCalInterval(ServerContext* context, const niFake::GetCalIntervalRequest* request, niFake::GetCalIntervalResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 months;
  auto status = GetCalInterval(vi, &months);
  response->set_status(status);
  if (status == 0) {
    response->set_months(months);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::GetCustomType(ServerContext* context, const niFake::GetCustomTypeRequest* request, niFake::GetCustomTypeResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  struct CustomStruct cs;
  auto status = GetCustomType(vi, &cs);
  response->set_status(status);
  if (status == 0) {
    response->set_cs(cs);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::GetCustomTypeArray(ServerContext* context, const niFake::GetCustomTypeArrayRequest* request, niFake::GetCustomTypeArrayResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 number_of_elements = request->number_of_elements();
  struct CustomStruct[] cs;
  auto status = GetCustomTypeArray(vi, number_of_elements, &cs);
  response->set_status(status);
  if (status == 0) {
    response->set_cs(cs);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::GetEnumValue(ServerContext* context, const niFake::GetEnumValueRequest* request, niFake::GetEnumValueResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 a_quantity;
  ViInt16 a_turtle;
  auto status = GetEnumValue(vi, &a_quantity, &a_turtle);
  response->set_status(status);
  if (status == 0) {
    response->set_a_quantity(a_quantity);
    response->set_a_turtle(a_turtle);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::GetError(ServerContext* context, const niFake::GetErrorRequest* request, niFake::GetErrorResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 buffer_size = request->buffer_size();
  ViStatus error_code;
  ViChar[] description;
  auto status = GetError(vi, &error_code, buffer_size, &description);
  response->set_status(status);
  if (status == 0) {
    response->set_error_code(error_code);
    response->set_description(description);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::GetLastCalDateAndTime(ServerContext* context, const niFake::GetLastCalDateAndTimeRequest* request, niFake::GetLastCalDateAndTimeResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 cal_type = request->cal_type();
  hightime.datetime month;
  auto status = GetLastCalDateAndTime(vi, cal_type, &month);
  response->set_status(status);
  if (status == 0) {
    response->set_month(month);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::ImportAttributeConfigurationBuffer(ServerContext* context, const niFake::ImportAttributeConfigurationBufferRequest* request, niFake::ImportAttributeConfigurationBufferResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 size_in_bytes = request->size_in_bytes();
  ViInt8[] configuration = request->configuration();
  auto status = ImportAttributeConfigurationBuffer(vi, size_in_bytes, configuration);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::InitWithOptions(ServerContext* context, const niFake::InitWithOptionsRequest* request, niFake::InitWithOptionsResponse* response)
{
  ViString resource_name = request->resource_name();
  ViBoolean id_query = request->id_query();
  ViBoolean reset_device = request->reset_device();
  ViConstString option_string = request->option_string().c_str();
  ViSession vi;
  auto status = InitWithOptions(resource_name, id_query, reset_device, option_string, &vi);
  response->set_status(status);
  if (status == 0) {
    response->set_vi(vi);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::Initiate(ServerContext* context, const niFake::InitiateRequest* request, niFake::InitiateResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  auto status = Initiate(vi);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::LockSession(ServerContext* context, const niFake::LockSessionRequest* request, niFake::LockSessionResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViBoolean caller_has_lock;
  auto status = LockSession(vi, &caller_has_lock);
  response->set_status(status);
  if (status == 0) {
    response->set_caller_has_lock(caller_has_lock);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::MultipleArrayTypes(ServerContext* context, const niFake::MultipleArrayTypesRequest* request, niFake::MultipleArrayTypesResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 output_array_size = request->output_array_size();
  ViInt32 input_array_sizes = request->input_array_sizes();
  ViReal64[] input_array_of_floats = request->input_array_of_floats();
  ViInt16[] input_array_of_integers = request->input_array_of_integers();
  ViReal64[] output_array;
  ViReal64[] output_array_of_fixed_length;
  auto status = MultipleArrayTypes(vi, output_array_size, &output_array, &output_array_of_fixed_length, input_array_sizes, input_array_of_floats, input_array_of_integers);
  response->set_status(status);
  if (status == 0) {
    response->set_output_array(output_array);
    response->set_output_array_of_fixed_length(output_array_of_fixed_length);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::MultipleArraysSameSize(ServerContext* context, const niFake::MultipleArraysSameSizeRequest* request, niFake::MultipleArraysSameSizeResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViReal64[] values1 = request->values1();
  ViReal64[] values2 = request->values2();
  ViReal64[] values3 = request->values3();
  ViReal64[] values4 = request->values4();
  ViInt32 size = request->size();
  auto status = MultipleArraysSameSize(vi, values1, values2, values3, values4, size);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::OneInputFunction(ServerContext* context, const niFake::OneInputFunctionRequest* request, niFake::OneInputFunctionResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 a_number = request->a_number();
  auto status = OneInputFunction(vi, a_number);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::ParametersAreMultipleTypes(ServerContext* context, const niFake::ParametersAreMultipleTypesRequest* request, niFake::ParametersAreMultipleTypesResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViBoolean a_boolean = request->a_boolean();
  ViInt32 an_int32 = request->an_int32();
  ViInt64 an_int64 = request->an_int64();
  ViInt16 an_int_enum = request->an_int_enum();
  ViReal64 a_float = request->a_float();
  ViReal64 a_float_enum = request->a_float_enum();
  ViInt32 string_size = request->string_size();
  ViConstString a_string = request->a_string().c_str();
  auto status = ParametersAreMultipleTypes(vi, a_boolean, an_int32, an_int64, an_int_enum, a_float, a_float_enum, string_size, a_string);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::PoorlyNamedSimpleFunction(ServerContext* context, const niFake::PoorlyNamedSimpleFunctionRequest* request, niFake::PoorlyNamedSimpleFunctionResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  auto status = PoorlyNamedSimpleFunction(vi);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::Read(ServerContext* context, const niFake::ReadRequest* request, niFake::ReadResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViReal64 maximum_time = request->maximum_time();
  ViReal64 reading;
  auto status = Read(vi, maximum_time, &reading);
  response->set_status(status);
  if (status == 0) {
    response->set_reading(reading);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::ReadFromChannel(ServerContext* context, const niFake::ReadFromChannelRequest* request, niFake::ReadFromChannelResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViConstString channel_name = request->channel_name().c_str();
  ViInt32 maximum_time = request->maximum_time();
  ViReal64 reading;
  auto status = ReadFromChannel(vi, channel_name, maximum_time, &reading);
  response->set_status(status);
  if (status == 0) {
    response->set_reading(reading);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::ReturnANumberAndAString(ServerContext* context, const niFake::ReturnANumberAndAStringRequest* request, niFake::ReturnANumberAndAStringResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt16 a_number;
  ViChar[] a_string;
  auto status = ReturnANumberAndAString(vi, &a_number, &a_string);
  response->set_status(status);
  if (status == 0) {
    response->set_a_number(a_number);
    response->set_a_string(a_string);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::ReturnDurationInSeconds(ServerContext* context, const niFake::ReturnDurationInSecondsRequest* request, niFake::ReturnDurationInSecondsResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViReal64 timedelta;
  auto status = ReturnDurationInSeconds(vi, &timedelta);
  response->set_status(status);
  if (status == 0) {
    response->set_timedelta(timedelta);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::ReturnListOfDurationsInSeconds(ServerContext* context, const niFake::ReturnListOfDurationsInSecondsRequest* request, niFake::ReturnListOfDurationsInSecondsResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 number_of_elements = request->number_of_elements();
  ViReal64[] timedeltas;
  auto status = ReturnListOfDurationsInSeconds(vi, number_of_elements, &timedeltas);
  response->set_status(status);
  if (status == 0) {
    response->set_timedeltas(timedeltas);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::ReturnMultipleTypes(ServerContext* context, const niFake::ReturnMultipleTypesRequest* request, niFake::ReturnMultipleTypesResponse* response)
{
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
  auto status = ReturnMultipleTypes(vi, &a_boolean, &an_int32, &an_int64, &an_int_enum, &a_float, &a_float_enum, array_size, &an_array, string_size, &a_string);
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
Status niFakeService::SetAttributeViBoolean(ServerContext* context, const niFake::SetAttributeViBooleanRequest* request, niFake::SetAttributeViBooleanResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViConstString channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  ViBoolean attribute_value = request->attribute_value();
  auto status = SetAttributeViBoolean(vi, channel_name, attribute_id, attribute_value);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::SetAttributeViInt32(ServerContext* context, const niFake::SetAttributeViInt32Request* request, niFake::SetAttributeViInt32Response* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViConstString channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  ViInt32 attribute_value = request->attribute_value();
  auto status = SetAttributeViInt32(vi, channel_name, attribute_id, attribute_value);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::SetAttributeViInt64(ServerContext* context, const niFake::SetAttributeViInt64Request* request, niFake::SetAttributeViInt64Response* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViConstString channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  ViInt64 attribute_value = request->attribute_value();
  auto status = SetAttributeViInt64(vi, channel_name, attribute_id, attribute_value);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::SetAttributeViReal64(ServerContext* context, const niFake::SetAttributeViReal64Request* request, niFake::SetAttributeViReal64Response* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViConstString channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  ViReal64 attribute_value = request->attribute_value();
  auto status = SetAttributeViReal64(vi, channel_name, attribute_id, attribute_value);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::SetAttributeViString(ServerContext* context, const niFake::SetAttributeViStringRequest* request, niFake::SetAttributeViStringResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViConstString channel_name = request->channel_name().c_str();
  ViAttr attribute_id = request->attribute_id();
  ViConstString attribute_value = request->attribute_value().c_str();
  auto status = SetAttributeViString(vi, channel_name, attribute_id, attribute_value);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::SetCustomType(ServerContext* context, const niFake::SetCustomTypeRequest* request, niFake::SetCustomTypeResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  struct CustomStruct cs = request->cs();
  auto status = SetCustomType(vi, cs);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::SetCustomTypeArray(ServerContext* context, const niFake::SetCustomTypeArrayRequest* request, niFake::SetCustomTypeArrayResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 number_of_elements = request->number_of_elements();
  struct CustomStruct[] cs = request->cs();
  auto status = SetCustomTypeArray(vi, number_of_elements, cs);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::StringValuedEnumInputFunctionWithDefaults(ServerContext* context, const niFake::StringValuedEnumInputFunctionWithDefaultsRequest* request, niFake::StringValuedEnumInputFunctionWithDefaultsResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViConstString a_mobile_o_s_name = request->a_mobile_o_s_name().c_str();
  auto status = StringValuedEnumInputFunctionWithDefaults(vi, a_mobile_o_s_name);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::TwoInputFunction(ServerContext* context, const niFake::TwoInputFunctionRequest* request, niFake::TwoInputFunctionResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViReal64 a_number = request->a_number();
  ViString a_string = request->a_string();
  auto status = TwoInputFunction(vi, a_number, a_string);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::UnlockSession(ServerContext* context, const niFake::UnlockSessionRequest* request, niFake::UnlockSessionResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViBoolean caller_has_lock;
  auto status = UnlockSession(vi, &caller_has_lock);
  response->set_status(status);
  if (status == 0) {
    response->set_caller_has_lock(caller_has_lock);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::Use64BitNumber(ServerContext* context, const niFake::Use64BitNumberRequest* request, niFake::Use64BitNumberResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt64 input = request->input();
  ViInt64 output;
  auto status = Use64BitNumber(vi, input, &output);
  response->set_status(status);
  if (status == 0) {
    response->set_output(output);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::WriteWaveform(ServerContext* context, const niFake::WriteWaveformRequest* request, niFake::WriteWaveformResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt32 number_of_samples = request->number_of_samples();
  ViReal64[] waveform = request->waveform();
  auto status = WriteWaveform(vi, number_of_samples, waveform);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::close(ServerContext* context, const niFake::closeRequest* request, niFake::closeResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  auto status = close(vi);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::error_message(ServerContext* context, const niFake::error_messageRequest* request, niFake::error_messageResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViStatus error_code = request->error_code();
  ViChar[] error_message;
  auto status = error_message(vi, error_code, &error_message);
  response->set_status(status);
  if (status == 0) {
    response->set_error_message(error_message);
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::fancy_self_test(ServerContext* context, const niFake::fancy_self_testRequest* request, niFake::fancy_self_testResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  auto status = fancy_self_test(vi);
  response->set_status(status);
  if (status == 0) {
  }

  return Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
Status niFakeService::self_test(ServerContext* context, const niFake::self_testRequest* request, niFake::self_testResponse* response)
{
  ViSession vi = SessionManager::LookupSession(request->vi());
  ViInt16 self_test_result;
  ViChar[] self_test_message;
  auto status = self_test(vi, &self_test_result, &self_test_message);
  response->set_status(status);
  if (status == 0) {
    response->set_self_test_result(self_test_result);
    response->set_self_test_message(self_test_message);
  }

  return Status::OK;
}

