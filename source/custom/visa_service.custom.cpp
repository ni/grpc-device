#include <visa/visa_attributes.h>
#include <visa/visa_service.h>

// Copied from NiVisaImpl.h
#define VI_ATTR_RSRC_USER_ALIAS        (0x3FFF018EUL) /* ViString  */
#define VI_ATTR_NUM_SUP_EVENTS         (0x3FFF019CUL) /* ViUInt16  */
#define VI_ATTR_SUP_EVENTS             (0x3FFF019DUL) /* ViAEventType */

namespace visa_grpc {
using nidevice_grpc::converters::convert_from_grpc;
using nidevice_grpc::converters::convert_to_grpc;

struct VisaAsyncOperation {
  ViSession vi;
  ViEvent event;
  std::vector<ViByte> buffer;

  VisaAsyncOperation(ViSession vi_):
    vi(vi_), event(VI_NULL)
  {
  }
};

static ViSession s_defaultRM = VI_NULL;
static std::shared_mutex s_server_object_lock;
static std::list<VisaAsyncOperation> s_async_operations;

// Returns true if it's safe to use outputs of a method with the given status.
inline bool status_ok(int32 status)
{
  return status >= VI_SUCCESS;
}

template <typename T>
inline ViByte* get_sized_buffer_data_pointer(T* buffer, ViUInt32 requestedCount)
{
  buffer->resize(requestedCount);
  auto buffer_ptr = requestedCount ? &buffer->front() : nullptr;
  return reinterpret_cast<ViByte*>(buffer_ptr);
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

static void ServerObjectCleanup(visa_grpc::VisaService::LibrarySharedPtr library)
{
  std::unique_lock<std::shared_mutex> lock(s_server_object_lock);
  library->Close(s_defaultRM);
  s_defaultRM = VI_NULL;
  s_async_operations.clear();
}

static ViSession GetResourceManagerSession(visa_grpc::VisaService::ResourceRepositorySharedPtr repository, visa_grpc::VisaService::LibrarySharedPtr library)
{
  auto cleanup_lambda = [library](ViSession id) { ServerObjectCleanup(library); };

  std::unique_lock<std::shared_mutex> lock(s_server_object_lock);
  if (!s_defaultRM) {
    ViStatus status = library->OpenDefaultRM(&s_defaultRM);
    if (!status_ok(status)) {
      throw DriverErrorException(status);
    }
    // This should be cleaned up only when the user explicitly resets the server to close all sessions.
    std::string manager_name = "INTERNAL::VISA::RESOURCE_MANAGER";
    auto init_lambda = [&] () { return std::make_tuple(0, s_defaultRM); };
    repository->add_session(manager_name, init_lambda, cleanup_lambda, nidevice_grpc::SESSION_INITIALIZATION_BEHAVIOR_UNSPECIFIED, NULL);
  }
  return s_defaultRM;
}

static ViStatus GetAttributeValue(ViObject vi, ViAttr attributeID, VisaService::LibrarySharedPtr library, visa_grpc::AttributeValueData* mutableValue)
{
  ViStatus status;
  switch (GetAttributeType(attributeID))
  {
    case AttributeValueData::kValueString: {
      ViChar attrValue[256] = {0};
      status = library->GetAttribute(vi, attributeID, attrValue);
      mutableValue->mutable_value_string()->assign(attrValue);
      break;
    }
    case AttributeValueData::kValueU64: {
      ViUInt64 val64;
      status = library->GetAttribute(vi, attributeID, &val64);
      mutableValue->set_value_u64(val64);
      break;
    }
    case AttributeValueData::kValueU32: {
      ViUInt32 val32;
      status = library->GetAttribute(vi, attributeID, &val32);
      mutableValue->set_value_u32(val32);
      break;
    }
    case AttributeValueData::kValueU16: {
      ViUInt16 val16;
      status = library->GetAttribute(vi, attributeID, &val16);
      // Special case logic for a specific property.
      // If the mapped address is a pointer, the remote client cannot use it as such
      if (attributeID == VI_ATTR_WIN_ACCESS && (val16 == VI_DEREF_ADDR || val16 == VI_DEREF_ADDR_BYTE_SWAP)) {
          val16 = VI_USE_OPERS;
      }
      mutableValue->set_value_u16(val16);
      break;
    }
    case AttributeValueData::kValueBool: {
      ViBoolean valBool;
      status = library->GetAttribute(vi, attributeID, &valBool);
      mutableValue->set_value_bool(valBool == VI_TRUE);
      break;
    }
    case AttributeValueData::kValueU8: {
      ViUInt8 val8;
      status = library->GetAttribute(vi, attributeID, &val8);
      mutableValue->set_value_u8(val8);
      break;
    }
    case AttributeValueData::kValueI32: {
      ViInt32 val32;
      status = library->GetAttribute(vi, attributeID, &val32);
      mutableValue->set_value_i32(val32);
      break;
    }
    case AttributeValueData::kValueI16: {
      ViInt16 val16;
      status = library->GetAttribute(vi, attributeID, &val16);
      mutableValue->set_value_i16(val16);
      break;
    }
    case AttributeValueData::kValueBytes: {
      if (attributeID == VI_ATTR_USB_RECV_INTR_DATA) {
        ViUInt16 byteCount;
        status = library->GetAttribute(vi, VI_ATTR_USB_RECV_INTR_SIZE, &byteCount);
        if (status >= VI_SUCCESS) {
          std::string* bytesAsString = mutableValue->mutable_value_bytes();
          auto buffer_pointer = get_sized_buffer_data_pointer(bytesAsString, byteCount);
          status = library->GetAttribute(vi, attributeID, buffer_pointer);
        }
      }
      else if (attributeID == VI_ATTR_TCPIP_SERVER_CERT) {
        ViUInt32 byteCount;
        status = library->GetAttribute(vi, VI_ATTR_TCPIP_SERVER_CERT_SIZE, &byteCount);
        if (status >= VI_SUCCESS) {
          std::string* bytesAsString = mutableValue->mutable_value_bytes();
          auto buffer_pointer = get_sized_buffer_data_pointer(bytesAsString, byteCount);
          status = library->GetAttribute(vi, attributeID, buffer_pointer);
        }
      }
      else if (attributeID == VI_ATTR_BUFFER) {
        ViUInt32 byteCount;
        status = library->GetAttribute(vi, VI_ATTR_RET_COUNT_32, &byteCount);
        auto matching_event_lambda = [&](const VisaAsyncOperation& v) { return v.event == vi; };
        std::unique_lock<std::shared_mutex> lock(s_server_object_lock);
        auto iter = std::find_if(s_async_operations.begin(), s_async_operations.end(), matching_event_lambda);
        if (status >= VI_SUCCESS && iter != s_async_operations.end()) {
          std::string* bytesAsString = mutableValue->mutable_value_bytes();
          bytesAsString->assign(reinterpret_cast<char*>((*iter).buffer.data()), byteCount);
        }
      }
      else {
        status = VI_ERROR_NSUP_ATTR;
      }
      break;
    }
    default:
      status = VI_ERROR_NSUP_ATTR;
      break;
  }
  return status;
}

::grpc::Status ConvertVisaApiErrorStatus(::grpc::ServerContextBase* context, ViStatus status, ViObject vi, VisaService::LibrarySharedPtr library, const char* extraInfo = nullptr)
{
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  library->StatusDesc(vi, status, &description[0]);
  // Although NI-VISA messages don't currently include context, we shouldn't assume it.
  if (extraInfo != nullptr && description.find(extraInfo) == description.npos) {
    nidevice_grpc::converters::trim_trailing_nulls(description);
    description.append("\n");
    description.append(extraInfo);
  }
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

::grpc::Status VisaService::ConvertApiErrorStatusForViSession(::grpc::ServerContextBase* context, int32_t status, ViSession vi)
{
  return ConvertVisaApiErrorStatus(context, status, vi, library_);
}

::grpc::Status VisaService::ConvertApiErrorStatusForViObject(::grpc::ServerContextBase* context, int32_t status, ViObject vi)
{
  return ConvertVisaApiErrorStatus(context, status, vi, library_);
}


//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status VisaService::CloseEvent(::grpc::ServerContext* context, const CloseEventRequest* request, CloseEventResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    ViEvent event_handle = request->event_handle();
    auto status = library_->CloseEvent(event_handle);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForViSession(context, status, 0);
    }
    auto matching_event_lambda = [&](const VisaAsyncOperation& v) { return v.event == event_handle; };
    std::unique_lock<std::shared_mutex> lock(s_server_object_lock);
    s_async_operations.remove_if(matching_event_lambda);
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
    ViSession rsrc_manager_handle = GetResourceManagerSession(session_repository_, library_);
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
        library_->Close(find_handle);
        return ConvertApiErrorStatusForViSession(context, status, rsrc_manager_handle);
      }
      response->add_instrument_descriptor(descriptor);
    }
    library_->Close(find_handle);
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (const nidevice_grpc::NonDriverException& ex) {
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
  try {
    auto vi_grpc_session = request->vi();
    ViSession vi = session_repository_->access_session(vi_grpc_session.name());
    ViAttr attributeID = request->attribute_name();
    ViStatus status = GetAttributeValue(vi, attributeID, library_, response->mutable_attribute_value());
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForViSession(context, status, vi);
    }
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (const nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status VisaService::GetAttributeEvent(::grpc::ServerContext* context, const GetAttributeEventRequest* request, GetAttributeEventResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    ViEvent vi = request->event_handle();
    ViAttr attributeID = request->attribute_name();
    ViStatus status = GetAttributeValue(vi, attributeID, library_, response->mutable_attribute_value());
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForViObject(context, status, vi);
    }
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (const nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status VisaService::Open(::grpc::ServerContext* context, const OpenRequest* request, OpenResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    ViSession rsrc_manager_handle = GetResourceManagerSession(session_repository_, library_);
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
        default: {
          access_mode = VI_NO_LOCK;
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
      return ConvertVisaApiErrorStatus(context, status, rsrc_manager_handle, library_, instrument_descriptor);
    }

    ViUInt16 numEvents = 0;
    ViSession vi = session_repository_->access_session(grpc_device_session_name);
    if (library->GetAttribute(vi, VI_ATTR_NUM_SUP_EVENTS, &numEvents) == VI_SUCCESS && numEvents > 0) {
      // NI-VISA writes the events followed by an extra "-1" value that we don't need.
      std::vector<EventType> events(numEvents+1);
      library->GetAttribute(vi, VI_ATTR_SUP_EVENTS, events.data());
      for (ViUInt16 index = 0; index < numEvents; ++index) {
        response->add_supported_events(events[index]);
      }
    }

    response->set_status(status);
    response->mutable_vi()->set_name(grpc_device_session_name);
    response->set_new_session_initialized(new_session_initialized);
    return ::grpc::Status::OK;
  }
  catch (const nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
  catch (const DriverErrorException& ex) {
    return ConvertApiErrorStatusForViSession(context, ex.status(), VI_NULL);
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status VisaService::MoveIn16(::grpc::ServerContext* context, const MoveIn16Request* request, MoveIn16Response* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  ViSession vi = VI_NULL;
  try {
    auto vi_grpc_session = request->vi();
    vi = session_repository_->access_session(vi_grpc_session.name());
    ViUInt16 address_space;
    switch (request->address_space_enum_case()) {
      case visa_grpc::MoveIn16Request::AddressSpaceEnumCase::kAddressSpace: {
        address_space = static_cast<ViUInt16>(request->address_space());
        break;
      }
      case visa_grpc::MoveIn16Request::AddressSpaceEnumCase::kAddressSpaceRaw: {
        address_space = static_cast<ViUInt16>(request->address_space_raw());
        break;
      }
      case visa_grpc::MoveIn16Request::AddressSpaceEnumCase::ADDRESS_SPACE_ENUM_NOT_SET: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for address_space was not specified or out of range");
        break;
      }
    }

    ViBusAddress64 offset = request->offset();
    ViBusSize count = request->count();
    std::vector<ViUInt16> driver_buffer(count);
    ViUInt16* buffer_pointer = driver_buffer.data();
    auto status = library_->MoveIn16(vi, address_space, offset, count, buffer_pointer);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForViSession(context, status, vi);
    }
    auto response_buffer = response->mutable_buffer();
    response_buffer->Resize(static_cast<int>(count), 0);
    for (ViUInt32 index = 0; index < count; ++index) {
      response_buffer->Set(index, *buffer_pointer++);
    }
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (const std::bad_alloc&) {
    return ConvertApiErrorStatusForViSession(context, VI_ERROR_ALLOC, vi);
  }
  catch (const nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
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
    ViSession rsrc_manager_handle = GetResourceManagerSession(session_repository_, library_);
    auto resource_name_mbcs = convert_from_grpc<std::string>(request->resource_name());
    ViConstRsrc resource_name = (ViConstRsrc)resource_name_mbcs.c_str();
    ViUInt16 interface_type{};
    ViUInt16 interface_number{};
    std::string resource_class(256 - 1, '\0');
    std::string expanded_unaliased_name(256 - 1, '\0');
    std::string alias_if_exists(256 - 1, '\0');
    auto status = library_->ParseRsrc(rsrc_manager_handle, resource_name, &interface_type, &interface_number, (ViChar*)resource_class.data(), (ViChar*)expanded_unaliased_name.data(), (ViChar*)alias_if_exists.data());
    if (!status_ok(status)) {
      return ConvertVisaApiErrorStatus(context, status, rsrc_manager_handle, library_, resource_name);
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
  catch (const nidevice_grpc::NonDriverException& ex) {
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
  ViSession vi = VI_NULL;
  try {
    auto vi_grpc_session = request->vi();
    vi = session_repository_->access_session(vi_grpc_session.name());
    ViUInt32 count = request->count();
    std::string* buffer = response->mutable_buffer();
    auto buffer_pointer = get_sized_buffer_data_pointer(buffer, count);
    ViUInt32 return_count{};
    auto status = library_->Read(vi, buffer_pointer, count, &return_count);
    if (!status_ok(status) && return_count == 0) {
      return ConvertApiErrorStatusForViSession(context, status, vi);
    }
    response->set_status(status);
    buffer->resize(return_count);
    response->set_return_count(return_count);
    return ::grpc::Status::OK;
  }
  catch (const std::bad_alloc&) {
    return ConvertApiErrorStatusForViSession(context, VI_ERROR_ALLOC, vi);
  }
  catch (const nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status VisaService::ReadAsync(::grpc::ServerContext* context, const ReadAsyncRequest* request, ReadAsyncResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  ViSession vi = VI_NULL;
  try {
    auto vi_grpc_session = request->vi();
    vi = session_repository_->access_session(vi_grpc_session.name());
    ViUInt32 count = request->count();

    auto outstanding_job_lambda = [&](const VisaAsyncOperation& v) { return v.vi == vi && v.event == VI_NULL; };
    std::unique_lock<std::shared_mutex> lock(s_server_object_lock);
    // Allow only 1 outstanding job per session
    if (std::find_if(s_async_operations.begin(), s_async_operations.end(), outstanding_job_lambda) != s_async_operations.end()) {
      return ConvertApiErrorStatusForViSession(context, VI_ERROR_IN_PROGRESS, vi);
    }
    auto operation_data_iter = s_async_operations.emplace(s_async_operations.end(), vi);
    auto buffer_pointer = get_sized_buffer_data_pointer(&operation_data_iter->buffer, count);
    // We release the lock while starting the actual I/O.
    lock.unlock();

    ViJobId job_identifier{};
    auto status = library_->ReadAsync(vi, buffer_pointer, count, &job_identifier);
    if (!status_ok(status)) {
      lock.lock();
      s_async_operations.erase(operation_data_iter);
      return ConvertApiErrorStatusForViSession(context, status, vi);
    }
    response->set_status(status);
    response->set_job_identifier(job_identifier);
    return ::grpc::Status::OK;
  }
  catch (const std::bad_alloc&) {
    return ConvertApiErrorStatusForViSession(context, VI_ERROR_ALLOC, vi);
  }
  catch (const nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status VisaService::SetAttribute(::grpc::ServerContext* context, const SetAttributeRequest* request, SetAttributeResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto vi_grpc_session = request->vi();
    ViSession vi = session_repository_->access_session(vi_grpc_session.name());
    ViAttr attributeID = request->attribute_name();
    ViAttrState attribute_value = 0;
    if (request->attribute_value().has_value_bool()) {
      attribute_value = static_cast<ViAttrState>(request->attribute_value().value_bool() ? VI_TRUE : VI_FALSE);
    }
#if defined(_VISA_ENV_IS_64_BIT)
    else if (request->attribute_value().has_value_u64()) {
      attribute_value = static_cast<ViAttrState>(request->attribute_value().value_u64());
    }
#endif
    else if (request->attribute_value().has_value_i32()) {
      attribute_value = static_cast<ViAttrState>(request->attribute_value().value_i32());
    }
    else if (request->attribute_value().has_value_u32()) {
      attribute_value = static_cast<ViAttrState>(request->attribute_value().value_u32());
    }
    else if (request->attribute_value().has_value_i16()) {
      attribute_value = static_cast<ViAttrState>(request->attribute_value().value_i16());
    }
    else if (request->attribute_value().has_value_u16()) {
      attribute_value = static_cast<ViAttrState>(request->attribute_value().value_u16());
    }
    else if (request->attribute_value().has_value_u8()) {
      attribute_value = static_cast<ViAttrState>(request->attribute_value().value_u8());
    }
    else {
      throw nidevice_grpc::NonDriverException(::grpc::INVALID_ARGUMENT, "The value for attribute_value was not specified or out of range");
    }
    auto status = library_->SetAttribute(vi, attributeID, attribute_value);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForViObject(context, status, vi);
    }
    response->set_status(status);
    return ::grpc::Status::OK;
  }
  catch (const nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status VisaService::UsbControlIn(::grpc::ServerContext* context, const UsbControlInRequest* request, UsbControlInResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  ViSession vi = VI_NULL;

  try {
    auto vi_grpc_session = request->vi();
    vi = session_repository_->access_session(vi_grpc_session.name());
    ViInt16 bm_request_type = (ViInt16)request->bm_request_type();
    ViInt16 b_request = (ViInt16)request->b_request();
    ViUInt16 w_value = request->w_value();
    ViUInt16 w_index = request->w_index();
    ViUInt16 w_length = request->w_length();
    std::string* buffer = response->mutable_buffer();
    auto buffer_pointer = get_sized_buffer_data_pointer(buffer, w_length);
    ViUInt16 return_count{};
    auto status = library_->UsbControlIn(vi, bm_request_type, b_request, w_value, w_index, w_length, buffer_pointer, &return_count);
    if (!status_ok(status) && return_count == 0) {
      return ConvertApiErrorStatusForViSession(context, status, vi);
    }
    response->set_status(status);
    buffer->resize(return_count);
    response->set_return_count(return_count);
    return ::grpc::Status::OK;
  }
  catch (const std::bad_alloc&) {
    return ConvertApiErrorStatusForViSession(context, VI_ERROR_ALLOC, vi);
  }
  catch (const nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status VisaService::WaitOnEvent(::grpc::ServerContext* context, const WaitOnEventRequest* request, WaitOnEventResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  try {
    auto vi_grpc_session = request->vi();
    ViSession vi = session_repository_->access_session(vi_grpc_session.name());
    ViEventType in_event_type;
    switch (request->in_event_type_enum_case()) {
      case visa_grpc::WaitOnEventRequest::InEventTypeEnumCase::kInEventType: {
        in_event_type = static_cast<ViEventType>(request->in_event_type());
        break;
      }
      case visa_grpc::WaitOnEventRequest::InEventTypeEnumCase::kInEventTypeRaw: {
        in_event_type = static_cast<ViEventType>(request->in_event_type_raw());
        break;
      }
      case visa_grpc::WaitOnEventRequest::InEventTypeEnumCase::IN_EVENT_TYPE_ENUM_NOT_SET: {
        return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for in_event_type was not specified or out of range");
        break;
      }
    }

    ViUInt32 timeout = request->timeout();
    ViEventType out_event_type {};
    ViEvent event_handle {};
    auto status = library_->WaitOnEvent(vi, in_event_type, timeout, &out_event_type, &event_handle);
    if (!status_ok(status)) {
      return ConvertApiErrorStatusForViSession(context, status, vi);
    }

    if (out_event_type == VI_EVENT_IO_COMPLETION) {
      auto outstanding_job_lambda = [&](const VisaAsyncOperation& v) { return v.vi == vi && v.event == VI_NULL; };
      std::unique_lock<std::shared_mutex> lock(s_server_object_lock);
      auto iter = std::find_if(s_async_operations.begin(), s_async_operations.end(), outstanding_job_lambda);
      if (iter != s_async_operations.end()) {
        (*iter).event = event_handle;
      }
    }

    response->set_status(status);
    response->set_out_event_type(static_cast<visa_grpc::EventType>(out_event_type));
    response->set_out_event_type_raw(out_event_type);
    response->set_event_handle(event_handle);
    return ::grpc::Status::OK;
  }
  catch (nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status VisaService::WriteAsync(::grpc::ServerContext* context, const WriteAsyncRequest* request, WriteAsyncResponse* response)
{
  if (context->IsCancelled()) {
    return ::grpc::Status::CANCELLED;
  }
  ViSession vi = VI_NULL;
  try {
    auto vi_grpc_session = request->vi();
    vi = session_repository_->access_session(vi_grpc_session.name());
    ViUInt32 count = static_cast<ViUInt32>(request->buffer().size());

    auto outstanding_job_lambda = [&](const VisaAsyncOperation& v) { return v.vi == vi && v.event == VI_NULL; };
    std::unique_lock<std::shared_mutex> lock(s_server_object_lock);
    // Allow only 1 outstanding job per session
    if (std::find_if(s_async_operations.begin(), s_async_operations.end(), outstanding_job_lambda) != s_async_operations.end()) {
      return ConvertApiErrorStatusForViSession(context, VI_ERROR_IN_PROGRESS, vi);
    }
    auto operation_data_iter = s_async_operations.emplace(s_async_operations.end(), vi);
    auto buffer_pointer = get_sized_buffer_data_pointer(&operation_data_iter->buffer, count);
    memcpy(buffer_pointer, reinterpret_cast<const ViByte*>(&request->buffer().front()), count);
    // We release the lock while starting the actual I/O.
    lock.unlock();

    ViJobId job_identifier{};
    auto status = library_->WriteAsync(vi, buffer_pointer, count, &job_identifier);
    if (!status_ok(status)) {
      lock.lock();
      s_async_operations.erase(operation_data_iter);
      return ConvertApiErrorStatusForViSession(context, status, vi);
    }
    response->set_status(status);
    response->set_job_identifier(job_identifier);
    return ::grpc::Status::OK;
  }
  catch (const std::bad_alloc&) {
    return ConvertApiErrorStatusForViSession(context, VI_ERROR_ALLOC, vi);
  }
  catch (const nidevice_grpc::NonDriverException& ex) {
    return ex.GetStatus();
  }
}

}  // namespace visa_grpc
