#define NIVISA_USB
#include <visa/visa_service.h>

// Copied from NiVisaImpl.h
#define VI_ATTR_RSRC_USER_ALIAS        (0x3FFF018EUL) /* ViString  */

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

static AttributeValueData::DataCase GetAttributeType(ViAttr attributeID)
{
  switch (attributeID)
  {
    case VI_ATTR_RSRC_NAME:
    case VI_ATTR_RSRC_USER_ALIAS:
    case VI_ATTR_INTF_INST_NAME:
    case VI_ATTR_RSRC_MANF_NAME:
    case VI_ATTR_RSRC_CLASS:
    case VI_ATTR_MANF_NAME:
    case VI_ATTR_MODEL_NAME:
    case VI_ATTR_TCPIP_ADDR:
    case VI_ATTR_TCPIP_HOSTNAME:
    case VI_ATTR_TCPIP_DEVICE_NAME:
    case VI_ATTR_USB_SERIAL_NUM:
    case VI_ATTR_PXI_SLOTPATH:
      return AttributeValueData::kValueString;

    case VI_ATTR_WIN_BASE_ADDR_64:
    case VI_ATTR_WIN_SIZE_64:
    case VI_ATTR_MEM_BASE_64:
    case VI_ATTR_MEM_SIZE_64:
    case VI_ATTR_PXI_MEM_BASE_BAR0_64:
    case VI_ATTR_PXI_MEM_BASE_BAR1_64:
    case VI_ATTR_PXI_MEM_BASE_BAR2_64:
    case VI_ATTR_PXI_MEM_BASE_BAR3_64:
    case VI_ATTR_PXI_MEM_BASE_BAR4_64:
    case VI_ATTR_PXI_MEM_BASE_BAR5_64:
    case VI_ATTR_PXI_MEM_SIZE_BAR0_64:
    case VI_ATTR_PXI_MEM_SIZE_BAR1_64:
    case VI_ATTR_PXI_MEM_SIZE_BAR2_64:
    case VI_ATTR_PXI_MEM_SIZE_BAR3_64:
    case VI_ATTR_PXI_MEM_SIZE_BAR4_64:
    case VI_ATTR_PXI_MEM_SIZE_BAR5_64:
      return AttributeValueData::kValueU64;

    case VI_ATTR_RSRC_SPEC_VERSION:
    case VI_ATTR_RSRC_IMPL_VERSION:
    case VI_ATTR_TCPIP_HISLIP_VERSION:
    case VI_ATTR_RSRC_LOCK_STATE:
    case VI_ATTR_MAX_QUEUE_LENGTH:
    case VI_ATTR_TMO_VALUE:
    case VI_ATTR_WIN_BASE_ADDR_32:
    case VI_ATTR_WIN_SIZE_32:
    case VI_ATTR_MEM_BASE_32:
    case VI_ATTR_MEM_SIZE_32:
    case VI_ATTR_INTR_STATUS_ID:
    case VI_ATTR_ASRL_AVAIL_NUM:
    case VI_ATTR_ASRL_BAUD:
    case VI_ATTR_VXI_TRIG_STATUS:
    case VI_ATTR_VXI_TRIG_SUPPORT:
    case VI_ATTR_TCPIP_HISLIP_MAX_MESSAGE_KB:
    case VI_ATTR_PXI_MEM_BASE_BAR0_32:
    case VI_ATTR_PXI_MEM_BASE_BAR1_32:
    case VI_ATTR_PXI_MEM_BASE_BAR2_32:
    case VI_ATTR_PXI_MEM_BASE_BAR3_32:
    case VI_ATTR_PXI_MEM_BASE_BAR4_32:
    case VI_ATTR_PXI_MEM_BASE_BAR5_32:
    case VI_ATTR_PXI_MEM_SIZE_BAR0_32:
    case VI_ATTR_PXI_MEM_SIZE_BAR1_32:
    case VI_ATTR_PXI_MEM_SIZE_BAR2_32:
    case VI_ATTR_PXI_MEM_SIZE_BAR3_32:
    case VI_ATTR_PXI_MEM_SIZE_BAR4_32:
    case VI_ATTR_PXI_MEM_SIZE_BAR5_32:
    case VI_ATTR_FIREWIRE_VENDOR_ID:
    case VI_ATTR_FIREWIRE_LOWER_CHIP_ID:
      return AttributeValueData::kValueU32;

    case VI_ATTR_RSRC_MANF_ID:
    case VI_ATTR_FDC_CHNL:
    case VI_ATTR_FDC_MODE:
    case VI_ATTR_IO_PROT:
    case VI_ATTR_MANF_ID:
    case VI_ATTR_MEM_SPACE:
    case VI_ATTR_MODEL_CODE:
    case VI_ATTR_DEST_ACCESS_PRIV:
    case VI_ATTR_DEST_BYTE_ORDER:
    case VI_ATTR_SRC_ACCESS_PRIV:
    case VI_ATTR_SRC_BYTE_ORDER:
    case VI_ATTR_WIN_ACCESS_PRIV:
    case VI_ATTR_WIN_BYTE_ORDER:
    case VI_ATTR_INTF_PARENT_NUM:
    case VI_ATTR_GPIB_PRIMARY_ADDR:
    case VI_ATTR_GPIB_SECONDARY_ADDR:
    case VI_ATTR_ASRL_DATA_BITS:
    case VI_ATTR_ASRL_PARITY:
    case VI_ATTR_ASRL_STOP_BITS:
    case VI_ATTR_ASRL_FLOW_CNTRL:
    case VI_ATTR_ASRL_END_IN:
    case VI_ATTR_ASRL_END_OUT:
    case VI_ATTR_SIGP_STATUS_ID:
    case VI_ATTR_VXI_DEV_CLASS:
    case VI_ATTR_VXI_VME_INTR_STATUS:
    case VI_ATTR_TCPIP_PORT:
    case VI_ATTR_GPIB_ADDR_STATE:
    case VI_ATTR_USB_MAX_INTR_SIZE:
    case VI_ATTR_USB_END_IN:
    case VI_ATTR_PXI_DEV_NUM:
    case VI_ATTR_PXI_FUNC_NUM:
    case VI_ATTR_PXI_MEM_TYPE_BAR0:
    case VI_ATTR_PXI_MEM_TYPE_BAR1:
    case VI_ATTR_PXI_MEM_TYPE_BAR2:
    case VI_ATTR_PXI_MEM_TYPE_BAR3:
    case VI_ATTR_PXI_MEM_TYPE_BAR4:
    case VI_ATTR_PXI_MEM_TYPE_BAR5:
    case VI_ATTR_PXI_BUS_NUM:
    case VI_ATTR_VXI_TRIG_LINES_EN:
    case VI_ATTR_VXI_TRIG_DIR:
    case VI_ATTR_FIREWIRE_DEST_UPPER_OFFSET:
    case VI_ATTR_FIREWIRE_SRC_UPPER_OFFSET:
    case VI_ATTR_FIREWIRE_WIN_UPPER_OFFSET:
    case VI_ATTR_WIN_ACCESS:
      return AttributeValueData::kValueU16;

    case VI_ATTR_FDC_GEN_SIGNAL_EN:
    case VI_ATTR_FDC_USE_PAIR:
    case VI_ATTR_SEND_END_EN:
    case VI_ATTR_SUPPRESS_END_EN:
    case VI_ATTR_TERMCHAR_EN:
    case VI_ATTR_IMMEDIATE_SERV:
    case VI_ATTR_GPIB_READDR_EN:
    case VI_ATTR_GPIB_UNADDR_EN:
    case VI_ATTR_ASRL_DISCARD_NULL:
    case VI_ATTR_ASRL_ALLOW_TRANSMIT:
    case VI_ATTR_GPIB_CIC_STATE:
    case VI_ATTR_GPIB_SYS_CNTRL_STATE:
    case VI_ATTR_FILE_APPEND_EN:
    case VI_ATTR_DMA_ALLOW_EN:
    case VI_ATTR_TCPIP_NODELAY:
    case VI_ATTR_TCPIP_KEEPALIVE:
    case VI_ATTR_TCPIP_HISLIP_OVERLAP_EN:
    case VI_ATTR_TCPIP_IS_HISLIP:
    case VI_ATTR_4882_COMPLIANT:
    case VI_ATTR_SYNC_MXI_ALLOW_EN:
    case VI_ATTR_ASRL_CONNECTED:
    case VI_ATTR_PXI_IS_EXPRESS:
    case VI_ATTR_PXI_ALLOW_WRITE_COMBINE:
      return AttributeValueData::kValueBool;

    case VI_ATTR_ASRL_REPLACE_CHAR:
    case VI_ATTR_ASRL_XON_CHAR:
    case VI_ATTR_ASRL_XOFF_CHAR:
    case VI_ATTR_TERMCHAR:
    case VI_ATTR_DEV_STATUS_BYTE:
    case VI_ATTR_FIREWIRE_UPPER_CHIP_ID:
      return AttributeValueData::kValueU8;

    case VI_ATTR_SRC_INCREMENT:
    case VI_ATTR_DEST_INCREMENT:
      return AttributeValueData::kValueI32;

    case VI_ATTR_VXI_LA:
    case VI_ATTR_CMDR_LA:
    case VI_ATTR_MAINFRAME_LA:
    case VI_ATTR_SLOT:
    case VI_ATTR_ASRL_CTS_STATE:
    case VI_ATTR_ASRL_DCD_STATE:
    case VI_ATTR_ASRL_DSR_STATE:
    case VI_ATTR_ASRL_DTR_STATE:
    case VI_ATTR_ASRL_RI_STATE:
    case VI_ATTR_ASRL_RTS_STATE:
    case VI_ATTR_TRIG_ID:
    case VI_ATTR_GPIB_REN_STATE:
    case VI_ATTR_GPIB_ATN_STATE:
    case VI_ATTR_GPIB_SRQ_STATE:
    case VI_ATTR_VXI_VME_SYSFAIL_STATE:
    case VI_ATTR_GPIB_HS488_CBL_LEN:
    case VI_ATTR_GPIB_NDAC_STATE:
    case VI_ATTR_ASRL_BREAK_STATE:
    case VI_ATTR_ASRL_BREAK_LEN:
    case VI_ATTR_ASRL_WIRE_MODE:
    case VI_ATTR_USB_INTFC_NUM:
    case VI_ATTR_USB_PROTOCOL:
    case VI_ATTR_USB_BULK_OUT_PIPE:
    case VI_ATTR_USB_BULK_IN_PIPE:
    case VI_ATTR_USB_INTR_IN_PIPE:
    case VI_ATTR_USB_BULK_OUT_STATUS:
    case VI_ATTR_USB_BULK_IN_STATUS:
    case VI_ATTR_USB_INTR_IN_STATUS:
    case VI_ATTR_USB_CLASS:
    case VI_ATTR_USB_SUBCLASS:
    case VI_ATTR_USB_ALT_SETTING:
    case VI_ATTR_USB_NUM_INTFCS:
    case VI_ATTR_USB_NUM_PIPES:
    case VI_ATTR_PXI_CHASSIS:
    case VI_ATTR_PXI_SLOT_LBUS_LEFT:
    case VI_ATTR_PXI_SLOT_LBUS_RIGHT:
    case VI_ATTR_PXI_TRIG_BUS:
    case VI_ATTR_PXI_STAR_TRIG_BUS:
    case VI_ATTR_PXI_STAR_TRIG_LINE:
    case VI_ATTR_PXI_SRC_TRIG_BUS:
    case VI_ATTR_PXI_DEST_TRIG_BUS:
    case VI_ATTR_PXI_SLOT_LWIDTH:
    case VI_ATTR_PXI_MAX_LWIDTH:
    case VI_ATTR_PXI_ACTUAL_LWIDTH:
    case VI_ATTR_PXI_DSTAR_BUS:
    case VI_ATTR_PXI_DSTAR_SET:
      return AttributeValueData::kValueI16;

    default:
      return AttributeValueData::DATA_NOT_SET;
  }
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
    default:
      status = VI_ERROR_NSUP_ATTR;
      break;
  }
  return status;
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
  catch (nidevice_grpc::NonDriverException& ex) {
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
  catch (nidevice_grpc::NonDriverException& ex) {
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
  catch (nidevice_grpc::NonDriverException& ex) {
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
