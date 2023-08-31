#include <visa/visa_service.h>

namespace visa_grpc {
using nidevice_grpc::converters::convert_from_grpc;
using nidevice_grpc::converters::convert_to_grpc;

static ViSession s_defaultRM = VI_NULL;
static std::shared_mutex s_resource_manager_lock;

// Returns true if it's safe to use outputs of a method with the given status.
inline bool status_ok(int32 status)
{
  return status >= VI_SUCCESS;
}

class DriverErrorException : public std::runtime_error {
 private:
  int status_ = 0;

 public:
  DriverErrorException(int status) : std::runtime_error(""), status_(status)
  {
  }
  int status() const
  {
    return status_;
  }
};

static ViSession GetResourceManagerSession(visa_grpc::VisaService::LibrarySharedPtr library)
{
  std::unique_lock<std::shared_mutex> lock(s_resource_manager_lock);
  if (!s_defaultRM) {
    ViStatus status = library->OpenDefaultRM(&s_defaultRM);
    if (!status_ok(status)) {
      throw DriverErrorException(status);
    }
  }
  return s_defaultRM;
}

::grpc::Status VisaService::ConvertApiErrorStatusForViSession(::grpc::ServerContextBase* context, int32_t status, ViSession vi)
{
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  library_->StatusDesc(vi, status, &description[0]);
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

::grpc::Status VisaService::ConvertApiErrorStatusForViObject(::grpc::ServerContextBase* context, int32_t status, ViObject vi)
{
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  library_->StatusDesc(vi, status, &description[0]);
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status VisaService::Close(::grpc::ServerContext* context, const CloseRequest* request, CloseResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    ViStatus status;
    if (request->object_handle().has_vi()) {
      auto vi_grpc_session = request->object_handle().vi();
      ViSession vi = session_repository_->access_session(vi_grpc_session.name());
      session_repository_->remove_session(vi_grpc_session.name());
      status = library_->Close(vi);
      if (!status_ok(status)) {
        return ConvertApiErrorStatusForViSession(context, status, vi);
      }
    }
    else if (request->object_handle().has_object_handle()) {
      auto object_handle = request->object_handle().object_handle();
      status = library_->Close(object_handle);
      if (!status_ok(status)) {
        return ConvertApiErrorStatusForViObject(context, status, object_handle);
      }
    }
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status VisaService::FindRsrc(::grpc::ServerContext* context, const FindRsrcRequest* request, FindRsrcResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    ViSession rsrc_manager_handle = GetResourceManagerSession(library_);
    auto expression_mbcs = convert_from_grpc<std::string>(request->expression());
    auto expression = expression_mbcs.c_str();
    ViFindList find_handle{};
    ViUInt32 return_count{};
    ViChar descriptor[256];
    auto status = library_->FindRsrc(rsrc_manager_handle, expression, &find_handle, &return_count, descriptor);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForViSession(context, status, rsrc_manager_handle);
    }
    response->add_instrument_descriptor(descriptor);
    for (ViUInt32 index = 1; index < return_count; ++index) {
      status = library_->FindNext(find_handle, descriptor);
      if (!status_ok(status)) {
        return ConvertApiErrorStatusForViSession(context, status, rsrc_manager_handle);
      }
      response->add_instrument_descriptor(descriptor);
    }
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
  catch (const DriverErrorException& ex) {
    return ConvertApiErrorStatusForViSession(context, ex.status(), VI_NULL);
  }
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status VisaService::GetAttribute(::grpc::ServerContext* context, const GetAttributeRequest* request, GetAttributeResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
#if 1
  return ::grpc::Status(grpc::StatusCode::DO_NOT_USE, "Custom code not implemented yet");
#else
  try {
    ViObject object_handle = request->object_handle();
    ViAttr attribute_name = request->attribute_name();
    void attribute_value{};
    auto status = library_->GetAttribute(object_handle, attribute_name, &attribute_value);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForViObject(context, status, object_handle);
    }
    response->set_status(status);
    response->set_attribute_value(attribute_value);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
#endif
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status VisaService::Open(::grpc::ServerContext* context, const OpenRequest* request, OpenResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    ViSession rsrc_manager_handle = GetResourceManagerSession(library_);
    auto instrument_descriptor_mbcs = convert_from_grpc<std::string>(request->instrument_descriptor());
    ViConstRsrc instrument_descriptor = (ViConstRsrc)instrument_descriptor_mbcs.c_str();
    ViAccessMode access_mode;
    switch (request->access_mode_enum_case()) {
      case visa_grpc::OpenRequest::AccessModeEnumCase::kAccessMode: {
        access_mode = static_cast<ViAccessMode>(request->access_mode());
        break;
      }
      case visa_grpc::OpenRequest::AccessModeEnumCase::kAccessModeRaw: {
        access_mode = static_cast<ViAccessMode>(request->access_mode_raw());
        break;
      }
      case visa_grpc::OpenRequest::AccessModeEnumCase::ACCESS_MODE_ENUM_NOT_SET: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for access_mode was not specified or out of range");
        break;
      }
    }

    ViUInt32 open_timeout = request->open_timeout();
    auto initialization_behavior = request->initialization_behavior();

    bool new_session_initialized{};
    auto init_lambda = [&]() {
      ViSession vi;
      auto status = library_->Open(rsrc_manager_handle, instrument_descriptor, access_mode, open_timeout, &vi);
      return std::make_tuple(status, vi);
    };
    std::string grpc_device_session_name = request->session_name();
    // Capture the library shared_ptr by value. Do not capture `this` or any references.
    LibrarySharedPtr library = library_;
    auto cleanup_lambda = [library](ViSession id) { library->Close(id); };
    int status = session_repository_->add_session(grpc_device_session_name, init_lambda, cleanup_lambda, initialization_behavior, &new_session_initialized);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForViSession(context, status, rsrc_manager_handle);
    }
    response->set_status(status);
    response->mutable_vi()->set_name(grpc_device_session_name);
    response->set_new_session_initialized(new_session_initialized);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
  catch (const DriverErrorException& ex) {
    return ConvertApiErrorStatusForViSession(context, ex.status(), VI_NULL);
  }
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status VisaService::ParseRsrc(::grpc::ServerContext* context, const ParseRsrcRequest* request, ParseRsrcResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    ViSession rsrc_manager_handle = GetResourceManagerSession(library_);
    auto resource_name_mbcs = convert_from_grpc<std::string>(request->resource_name());
    ViConstRsrc resource_name = (ViConstRsrc)resource_name_mbcs.c_str();
    ViUInt16 interface_type{};
    ViUInt16 interface_number{};
    std::string resource_class(256 - 1, '\0');
    std::string expanded_unaliased_name(256 - 1, '\0');
    std::string alias_if_exists(256 - 1, '\0');
    auto status = library_->ParseRsrc(rsrc_manager_handle, resource_name, &interface_type, &interface_number, (ViChar*)resource_class.data(), (ViChar*)expanded_unaliased_name.data(), (ViChar*)alias_if_exists.data());
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForViSession(context, status, rsrc_manager_handle);
    }
    response->set_status(status);
    response->set_interface_type(interface_type);
    response->set_interface_number(interface_number);
    std::string resource_class_utf8;
    convert_to_grpc(resource_class, &resource_class_utf8);
    response->set_resource_class(resource_class_utf8);
    nidevice_grpc::converters::trim_trailing_nulls(*(response->mutable_resource_class()));
    std::string expanded_unaliased_name_utf8;
    convert_to_grpc(expanded_unaliased_name, &expanded_unaliased_name_utf8);
    response->set_expanded_unaliased_name(expanded_unaliased_name_utf8);
    nidevice_grpc::converters::trim_trailing_nulls(*(response->mutable_expanded_unaliased_name()));
    std::string alias_if_exists_utf8;
    convert_to_grpc(alias_if_exists, &alias_if_exists_utf8);
    response->set_alias_if_exists(alias_if_exists_utf8);
    nidevice_grpc::converters::trim_trailing_nulls(*(response->mutable_alias_if_exists()));
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
  catch (const DriverErrorException& ex) {
    return ConvertApiErrorStatusForViSession(context, ex.status(), VI_NULL);
  }
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status VisaService::Read(::grpc::ServerContext* context, const ReadRequest* request, ReadResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
#if 1
  return ::grpc::Status(grpc::StatusCode::DO_NOT_USE, "Custom code not implemented yet");
#else
  try {
    auto vi_grpc_session = request->vi();
    ViSession vi = session_repository_->access_session(vi_grpc_session.name());
    ViUInt32 count = request->count();
    std::string buffer(return_count, '\0');
    ViUInt32 return_count{};
    auto status = library_->Read(vi, (ViByte*)buffer.data(), count, &return_count);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForViSession(context, status, vi);
    }
    response->set_status(status);
    response->set_buffer(buffer);
    response->set_return_count(return_count);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
#endif
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status VisaService::ReadAsync(::grpc::ServerContext* context, const ReadAsyncRequest* request, ReadAsyncResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
#if 1
  return ::grpc::Status(grpc::StatusCode::DO_NOT_USE, "Custom code not implemented yet");
#else
  try {
    auto vi_grpc_session = request->vi();
    ViSession vi = session_repository_->access_session(vi_grpc_session.name());
    ViUInt32 count = request->count();
    void read_buffer{};
    ViJobId job_identifier{};
    auto status = library_->ReadAsync(vi, &read_buffer, count, &job_identifier);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForViSession(context, status, vi);
    }
    response->set_status(status);
    response->set_job_identifier(job_identifier);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
#endif
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status VisaService::SetAttribute(::grpc::ServerContext* context, const SetAttributeRequest* request, SetAttributeResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
#if 1
  return ::grpc::Status(grpc::StatusCode::DO_NOT_USE, "Custom code not implemented yet");
#else
  try {
    ViObject object_handle = request->object_handle();
    ViAttr attribute_name = request->attribute_name();
    ViAttrState attribute_value = request->attribute_value();
    auto status = library_->SetAttribute(object_handle, attribute_name, attribute_value);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForViObject(context, status, object_handle);
    }
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
#endif
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status VisaService::StatusDesc(::grpc::ServerContext* context, const StatusDescRequest* request, StatusDescResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
#if 1
  return ::grpc::Status(grpc::StatusCode::DO_NOT_USE, "Custom code not implemented yet");
#else
  try {
    ViObject object_handle = request->object_handle();
    ViStatus status_value = request->status_value();
    std::string status_description(256 - 1, '\0');
    auto status = library_->StatusDesc(object_handle, status_value, (ViChar*)status_description.data());
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForViObject(context, status, object_handle);
    }
    response->set_status(status);
    std::string status_description_utf8;
    convert_to_grpc(status_description, &status_description_utf8);
    response->set_status_description(status_description_utf8);
    nidevice_grpc::converters::trim_trailing_nulls(*(response->mutable_status_description()));
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
#endif
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status VisaService::UsbControlIn(::grpc::ServerContext* context, const UsbControlInRequest* request, UsbControlInResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
#if 1
  return ::grpc::Status(grpc::StatusCode::DO_NOT_USE, "Custom code not implemented yet");
#else
  try {
    auto vi_grpc_session = request->vi();
    ViSession vi = session_repository_->access_session(vi_grpc_session.name());
    ViInt16 bm_request_type = (ViInt16)request->bm_request_type();
    ViInt16 b_request = (ViInt16)request->b_request();
    ViUInt16 w_value = request->w_value();
    ViUInt16 w_index = request->w_index();
    ViUInt16 w_length = request->w_length();
    std::string buffer(return_count, '\0');
    ViUInt16 return_count{};
    auto status = library_->UsbControlIn(vi, bm_request_type, b_request, w_value, w_index, w_length, (ViByte*)buffer.data(), &return_count);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForViSession(context, status, vi);
    }
    response->set_status(status);
    response->set_buffer(buffer);
    response->set_return_count(return_count);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
#endif
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status VisaService::WriteAsync(::grpc::ServerContext* context, const WriteAsyncRequest* request, WriteAsyncResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
#if 1
  return ::grpc::Status(grpc::StatusCode::DO_NOT_USE, "Custom code not implemented yet");
#else
  try {
    auto vi_grpc_session = request->vi();
    ViSession vi = session_repository_->access_session(vi_grpc_session.name());
    ViByte* buffer = (ViByte*)request->buffer().c_str();
    ViUInt32 count = static_cast<ViUInt32>(request->buffer().size());
    ViJobId job_identifier{};
    auto status = library_->WriteAsync(vi, buffer, count, &job_identifier);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForViSession(context, status, vi);
    }
    response->set_status(status);
    response->set_job_identifier(job_identifier);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
#endif
}

}  // namespace visa_grpc
