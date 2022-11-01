#include <gtest/gtest.h>
#include <server/debug_session_properties_restricted_service.h>
#include <server/syscfg_library.h>
#include <tests/utilities/syscfg_mock_library.h>

namespace ni {
namespace tests {
namespace unit {

using ::testing::_;
using ::testing::Invoke;
using ::testing::NiceMock;
using ::testing::Return;
using ::testing::Throw;
using ::testing::WithArg;

class DebugSessionPropertiesSysCfgMockLibrary : public NiceMock<ni::tests::utilities::SysCfgMockLibrary> {
 public:
  DebugSessionPropertiesSysCfgMockLibrary()
  {
    is_device_set_ = false;
    is_device_ = NISysCfgBoolFalse;
    user_alias_set_ = false;
    user_alias_ = "";
    serial_number_set_ = false;
    serial_number_ = "";
    product_id_set_ = false;
    product_id_ = 0;
    expect_debug_enabled_ = false;
    debug_enabled_set_ = false;
    debug_enabled_ = 0;
    expect_out_of_process_ = false;
    out_of_process_set_ = false;
    out_of_process_ = NISysCfgBoolFalse;
  }
  ~DebugSessionPropertiesSysCfgMockLibrary() {}

  NISysCfgStatus SetFilterProperty(
      NISysCfgFilterHandle filter_handle,
      NISysCfgFilterProperty property_ID,
      ...)
  {
    NISysCfgStatus status = NISysCfg_InvalidArg;
    va_list args;
    va_start(args, property_ID);
    switch(property_ID) {
      case NISysCfgFilterPropertyIsDevice: {
        is_device_set_ = true;
        is_device_ = va_arg(args, NISysCfgBool);
        status = NISysCfg_OK;
        break;
      }
      case NISysCfgFilterPropertyUserAlias: {
        user_alias_set_ = true;
        user_alias_ = std::string(va_arg(args, const char*));
        status = NISysCfg_OK;
        break;
      }
      case NISysCfgFilterPropertySerialNumber: {
        serial_number_set_ = true;
        serial_number_ = std::string(va_arg(args, const char*));
        status = NISysCfg_OK;
        break;
      }
      case NISysCfgFilterPropertyProductId: {
        product_id_set_ = true;
        product_id_ = va_arg(args, unsigned int);
        status = NISysCfg_OK;
        break;
      }
      default:
        break;
    }
    va_end(args);

    return status;
  }

  NISysCfgStatus SetResourceProperty(
      NISysCfgResourceHandle resource_handle,
      NISysCfgResourceProperty property_ID,
      ...)
  {
    NISysCfgStatus status = NISysCfg_InvalidArg;
    va_list args;
    va_start(args, property_ID);
    switch(property_ID) {
      case nidevice_restricted_grpc::kDebugSessionEnabledPropertyId: {
        if (expect_debug_enabled_)
        {
          debug_enabled_set_ = true;
          debug_enabled_ = va_arg(args, unsigned int);
          status = NISysCfg_OK;
        }
        break;
      }
      case nidevice_restricted_grpc::kDebugSessionServerOutOfProcessPropertyId: {
        if (expect_out_of_process_)
        {
          out_of_process_set_ = true;
          out_of_process_ = va_arg(args, NISysCfgBool);
          status = NISysCfg_OK;
        }
        break;
      }
      default:
        break;
    }
    va_end(args);

    return status;
  }

  bool is_device_set() const { return is_device_set_; }
  NISysCfgBool is_device() const { return is_device_; }
  bool user_alias_set() const { return user_alias_set_; }
  const std::string& user_alias() const { return user_alias_; }
  bool serial_number_set() const { return serial_number_set_; }
  const std::string& serial_number() const { return serial_number_; }
  bool product_id_set() const { return product_id_set_; }
  unsigned int product_id() const { return product_id_; }
  void set_expect_debug_enabled() { expect_debug_enabled_ = true; }
  bool debug_enabled_set() const { return debug_enabled_set_; }
  unsigned int debug_enabled() const { return debug_enabled_; }
  void set_expect_out_of_process() { expect_out_of_process_ = true; }
  bool out_of_process_set() const { return out_of_process_set_; }
  bool out_of_process() const { return out_of_process_; }

 private:
  bool is_device_set_;
  NISysCfgBool is_device_;
  bool user_alias_set_;
  std::string user_alias_;
  bool serial_number_set_;
  std::string serial_number_;
  bool product_id_set_;
  unsigned int product_id_;
  bool expect_debug_enabled_;
  bool debug_enabled_set_;
  unsigned int debug_enabled_;
  bool expect_out_of_process_;
  bool out_of_process_set_;
  NISysCfgBool out_of_process_;
};

TEST(DebugSessionPropertiesTests, SysCfgApiNotInstalled_QueryDebugSessionSupported_ReturnsNotFoundGrpcStatusCode)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::DebugSessionPropertiesRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::IsDebugSessionSupportedRequest request;
  nidevice_restricted_grpc::IsDebugSessionSupportedResponse response;
  EXPECT_CALL(mock_library, InitializeSession)
      .WillOnce(Throw(nidevice_grpc::LibraryLoadException(nidevice_grpc::kSysCfgApiNotInstalledMessage)));
  EXPECT_CALL(mock_library, CloseHandle)
      .Times(0);

  ::grpc::Status status = service.IsDebugSessionSupported(&context, &request, &response);

  EXPECT_EQ(::grpc::StatusCode::NOT_FOUND, status.error_code());
  EXPECT_EQ(nidevice_grpc::kSysCfgApiNotInstalledMessage, status.error_message());
}

TEST(DebugSessionPropertiesTests, InitializeSessionReturnsError_QueryDebugSessionSupported_ReturnsInternalGrpcStatusCode)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::DebugSessionPropertiesRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::IsDebugSessionSupportedRequest request;
  nidevice_restricted_grpc::IsDebugSessionSupportedResponse response;
  EXPECT_CALL(mock_library, InitializeSession)
      .WillOnce(Return(NISysCfg_InvalidLoginCredentials));
  EXPECT_CALL(mock_library, CloseHandle)
      .Times(0);

  ::grpc::Status status = service.IsDebugSessionSupported(&context, &request, &response);

  EXPECT_EQ(::grpc::StatusCode::INTERNAL, status.error_code());
  EXPECT_EQ(nidevice_restricted_grpc::kDebugSessionPropertyAccessFailedMessage, status.error_message());
}

static NISysCfgStatus SetSessionHandleToOne(NISysCfgSessionHandle* session_handle)
{
  *session_handle = (NISysCfgSessionHandle)1;
  return NISysCfg_OK;
}

TEST(DebugSessionPropertiesTests, InitializeSessionSucceeds_QueryDebugSessionSupported_CallsInitializeButNotClose)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::DebugSessionPropertiesRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::IsDebugSessionSupportedRequest request;
  nidevice_restricted_grpc::IsDebugSessionSupportedResponse response;
  EXPECT_CALL(mock_library, InitializeSession)
      .WillOnce(WithArg<7>(Invoke(SetSessionHandleToOne)));
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, CloseHandle(_))
      .WillRepeatedly(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, CloseHandle((void*)1))
      .Times(0);

  ::grpc::Status status = service.IsDebugSessionSupported(&context, &request, &response);

  EXPECT_EQ(::grpc::StatusCode::OK, status.error_code());
}

TEST(DebugSessionPropertiesTests, CreateFilterReturnsError_QueryDebugSessionSupported_ReturnsInternalError)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::DebugSessionPropertiesRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::IsDebugSessionSupportedRequest request;
  nidevice_restricted_grpc::IsDebugSessionSupportedResponse response;
  EXPECT_CALL(mock_library, CreateFilter)
      .WillOnce(Return(NISysCfg_InvalidArg));
  EXPECT_CALL(mock_library, FindHardware)
      .Times(0);

  ::grpc::Status status = service.IsDebugSessionSupported(&context, &request, &response);

  EXPECT_EQ(::grpc::StatusCode::INTERNAL, status.error_code());
  EXPECT_EQ(nidevice_restricted_grpc::kDebugSessionPropertyAccessFailedMessage, status.error_message());
}

static NISysCfgStatus SetFilterHandleToOne(NISysCfgFilterHandle* filter_handle)
{
  *filter_handle = (NISysCfgFilterHandle)1;
  return NISysCfg_OK;
}

TEST(DebugSessionPropertiesTests, CreateFilterSetsFilterHandle_QueryDebugSessionSupported_FilterHandleIsPassedToCloseHandle)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::DebugSessionPropertiesRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::IsDebugSessionSupportedRequest request;
  nidevice_restricted_grpc::IsDebugSessionSupportedResponse response;
  EXPECT_CALL(mock_library, CreateFilter)
      .WillOnce(WithArg<1>(Invoke(SetFilterHandleToOne)));
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, CloseHandle)
      .WillRepeatedly(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, CloseHandle((void*)1))
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = service.IsDebugSessionSupported(&context, &request, &response);

  EXPECT_TRUE(status.ok());
}

TEST(DebugSessionPropertiesTests, FindHardwareReturnsError_QueryDebugSessionSupported_ReturnsInternalError)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::DebugSessionPropertiesRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::IsDebugSessionSupportedRequest request;
  nidevice_restricted_grpc::IsDebugSessionSupportedResponse response;
  EXPECT_CALL(mock_library, FindHardware)
      .WillOnce(Return(NISysCfg_InvalidArg));
  EXPECT_CALL(mock_library, NextResource)
      .Times(0);

  ::grpc::Status status = service.IsDebugSessionSupported(&context, &request, &response);

  EXPECT_EQ(::grpc::StatusCode::INTERNAL, status.error_code());
  EXPECT_EQ(nidevice_restricted_grpc::kDebugSessionPropertyAccessFailedMessage, status.error_message());
}

static NISysCfgStatus SetResourceEnumHandleToOne(NISysCfgEnumResourceHandle* resource_enum_handle)
{
  *resource_enum_handle = (NISysCfgEnumResourceHandle)1;
  return NISysCfg_OK;
}

TEST(DebugSessionPropertiesTests, FindHardwareSetsResourceEnumHandle_QueryDebugSessionSupported_ResourceEnumHandleIsPassedToNextResource)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::DebugSessionPropertiesRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::IsDebugSessionSupportedRequest request;
  nidevice_restricted_grpc::IsDebugSessionSupportedResponse response;
  EXPECT_CALL(mock_library, FindHardware)
      .WillOnce(WithArg<4>(Invoke(SetResourceEnumHandleToOne)));
  EXPECT_CALL(mock_library, NextResource(_, (void*)1, _))
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = service.IsDebugSessionSupported(&context, &request, &response);

  EXPECT_TRUE(status.ok());
}

TEST(DebugSessionPropertiesTests, FindHardwareSetsResourceEnumHandle_QueryDebugSessionSupported_ResourceEnumHandleIsPassedToCloseHandle)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::DebugSessionPropertiesRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::IsDebugSessionSupportedRequest request;
  nidevice_restricted_grpc::IsDebugSessionSupportedResponse response;
  EXPECT_CALL(mock_library, FindHardware)
      .WillOnce(WithArg<4>(Invoke(SetResourceEnumHandleToOne)));
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, CloseHandle)
      .WillRepeatedly(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, CloseHandle((void*)1))
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = service.IsDebugSessionSupported(&context, &request, &response);

  EXPECT_TRUE(status.ok());
}

TEST(DebugSessionPropertiesTests, NextResourceReturnsError_QueryDebugSessionSupported_ReturnsInternalError)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::DebugSessionPropertiesRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::IsDebugSessionSupportedRequest request;
  nidevice_restricted_grpc::IsDebugSessionSupportedResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_InvalidArg));
  EXPECT_CALL(mock_library, GetResourceIndexedProperty)
      .Times(0);

  ::grpc::Status status = service.IsDebugSessionSupported(&context, &request, &response);

  EXPECT_EQ(::grpc::StatusCode::INTERNAL, status.error_code());
  EXPECT_EQ(nidevice_restricted_grpc::kDebugSessionPropertyAccessFailedMessage, status.error_message());
}

static NISysCfgStatus SetResourceHandleToOne(NISysCfgResourceHandle* resource_handle)
{
  *resource_handle = (NISysCfgResourceHandle)1;
  return NISysCfg_OK;
}

TEST(DebugSessionPropertiesTests, NextResourceSetsResourceHandle_QueryDebugSessionSupported_ResourceHandleIsPassedToGetPropertyApis)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::DebugSessionPropertiesRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::IsDebugSessionSupportedRequest request;
  nidevice_restricted_grpc::IsDebugSessionSupportedResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(WithArg<2>(Invoke(SetResourceHandleToOne)));
  EXPECT_CALL(mock_library, GetResourceProperty((void*)1, _, _))
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = service.IsDebugSessionSupported(&context, &request, &response);

  EXPECT_TRUE(status.ok());
}

TEST(DebugSessionPropertiesTests, NextResourceSetsResourceHandle_QueryDebugSessionSupported_ResourceHandleIsPassedToCloseHandle)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::DebugSessionPropertiesRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::IsDebugSessionSupportedRequest request;
  nidevice_restricted_grpc::IsDebugSessionSupportedResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(WithArg<2>(Invoke(SetResourceHandleToOne)));
  EXPECT_CALL(mock_library, CloseHandle)
      .WillRepeatedly(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, CloseHandle((void*)1))
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = service.IsDebugSessionSupported(&context, &request, &response);

  EXPECT_TRUE(status.ok());
}

TEST(DebugSessionPropertiesTests, NoMatchForFilter_QueryDebugSessionSupported_ReturnsInternalError)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_restricted_grpc::DebugSessionPropertiesRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::IsDebugSessionSupportedRequest request;
  nidevice_restricted_grpc::IsDebugSessionSupportedResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_EndOfEnum));

  ::grpc::Status status = service.IsDebugSessionSupported(&context, &request, &response);

  EXPECT_EQ(::grpc::StatusCode::INTERNAL, status.error_code());
  EXPECT_EQ(nidevice_restricted_grpc::kDebugSessionPropertyAccessFailedMessage, status.error_message());
}

static const char* kDeviceName = "MyVST";
static const char* kSerialNumber = "FEDCBA98";
static const uint32_t kProductId = 0x7991;

TEST(DebugSessionPropertiesTests, DeviceIdPopulated_QueryDebugSessionSupported_FilterConfigured)
{
  DebugSessionPropertiesSysCfgMockLibrary mock_library;
  nidevice_restricted_grpc::DebugSessionPropertiesRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::IsDebugSessionSupportedRequest request;
  request.mutable_device_id()->set_name(kDeviceName);
  request.mutable_device_id()->set_serial_number(kSerialNumber);
  request.mutable_device_id()->set_product_id(kProductId);
  nidevice_restricted_grpc::IsDebugSessionSupportedResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = service.IsDebugSessionSupported(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(mock_library.is_device_set());
  EXPECT_EQ(NISysCfgBoolTrue, mock_library.is_device());
  EXPECT_TRUE(mock_library.user_alias_set());
  EXPECT_EQ(kDeviceName, mock_library.user_alias());
  EXPECT_TRUE(mock_library.serial_number_set());
  EXPECT_EQ(kSerialNumber, mock_library.serial_number());
  EXPECT_TRUE(mock_library.product_id_set());
  EXPECT_EQ(kProductId, mock_library.product_id());
}

TEST(DebugSessionPropertiesTests, DeviceIsPresent_QueryDebugSessionSupported_FilterModeMatchIsAll)
{
  DebugSessionPropertiesSysCfgMockLibrary mock_library;
  nidevice_restricted_grpc::DebugSessionPropertiesRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::IsDebugSessionSupportedRequest request;
  nidevice_restricted_grpc::IsDebugSessionSupportedResponse response;
  EXPECT_CALL(mock_library, FindHardware(_, NISysCfgFilterModeMatchValuesAll, _, _, _))
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = service.IsDebugSessionSupported(&context, &request, &response);

  EXPECT_TRUE(status.ok());
}

static NISysCfgStatus SetUintToOne(void* value)
{
  *static_cast<unsigned int*>(value) = 1;
  return NISysCfg_OK;
}

TEST(DebugSessionPropertiesTests, DeviceIsPresent_QueryDebugSessionSupported_ResponseIsWritten)
{
  DebugSessionPropertiesSysCfgMockLibrary mock_library;
  nidevice_restricted_grpc::DebugSessionPropertiesRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::IsDebugSessionSupportedRequest request;
  nidevice_restricted_grpc::IsDebugSessionSupportedResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty(_, nidevice_restricted_grpc::kDebugSessionSupportedPropertyId, _))
      .WillOnce(WithArg<2>(SetUintToOne));

  ::grpc::Status status = service.IsDebugSessionSupported(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(response.supported());
}

TEST(DebugSessionPropertiesTests, DeviceIsPresent_QueryDebugSessionEnabled_ResponseIsWritten)
{
  DebugSessionPropertiesSysCfgMockLibrary mock_library;
  nidevice_restricted_grpc::DebugSessionPropertiesRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::IsDebugSessionEnabledRequest request;
  nidevice_restricted_grpc::IsDebugSessionEnabledResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty(_, nidevice_restricted_grpc::kDebugSessionEnabledPropertyId, _))
      .WillOnce(WithArg<2>(SetUintToOne));

  ::grpc::Status status = service.IsDebugSessionEnabled(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(response.enabled());
}

TEST(DebugSessionPropertiesTests, DeviceIsPresent_QueryDebugSessionServerOutOfProcess_ResponseIsWritten)
{
  DebugSessionPropertiesSysCfgMockLibrary mock_library;
  nidevice_restricted_grpc::DebugSessionPropertiesRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::IsDebugSessionServerOutOfProcessRequest request;
  nidevice_restricted_grpc::IsDebugSessionServerOutOfProcessResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty(_, nidevice_restricted_grpc::kDebugSessionServerOutOfProcessPropertyId, _))
      .WillOnce(WithArg<2>(SetUintToOne));

  ::grpc::Status status = service.IsDebugSessionServerOutOfProcess(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(response.out_of_process());
}

TEST(DebugSessionPropertiesTests, DeviceIsPresent_SetDebugSessionEnabled_EnabledIsSet)
{
  DebugSessionPropertiesSysCfgMockLibrary mock_library;
  mock_library.set_expect_debug_enabled();
  nidevice_restricted_grpc::DebugSessionPropertiesRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::SetDebugSessionEnabledRequest request;
  request.set_enabled(true);
  nidevice_restricted_grpc::SetDebugSessionEnabledResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = service.SetDebugSessionEnabled(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(mock_library.debug_enabled_set());
  EXPECT_EQ(1, mock_library.debug_enabled());
}

TEST(DebugSessionPropertiesTests, DeviceIsPresent_SetDebugSessionServerOutOfProcess_OutOfProcessIsSet)
{
  DebugSessionPropertiesSysCfgMockLibrary mock_library;
  mock_library.set_expect_out_of_process();
  nidevice_restricted_grpc::DebugSessionPropertiesRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::SetDebugSessionServerOutOfProcessRequest request;
  request.set_out_of_process(true);
  nidevice_restricted_grpc::SetDebugSessionServerOutOfProcessResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = service.SetDebugSessionServerOutOfProcess(&context, &request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(mock_library.out_of_process_set());
  EXPECT_EQ(NISysCfgBoolTrue, mock_library.out_of_process());
}

TEST(DebugSessionPropertiesTests, DeviceIsPresent_QueryDebugSessionSupported_SaveNotCalled)
{
  DebugSessionPropertiesSysCfgMockLibrary mock_library;
  nidevice_restricted_grpc::DebugSessionPropertiesRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::IsDebugSessionSupportedRequest request;
  nidevice_restricted_grpc::IsDebugSessionSupportedResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, SaveResourceChanges)
      .Times(0);

  ::grpc::Status status = service.IsDebugSessionSupported(&context, &request, &response);

  EXPECT_TRUE(status.ok());
}

TEST(DebugSessionPropertiesTests, DeviceIsPresent_QueryDebugSessionEnabled_SaveNotCalled)
{
  DebugSessionPropertiesSysCfgMockLibrary mock_library;
  nidevice_restricted_grpc::DebugSessionPropertiesRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::IsDebugSessionEnabledRequest request;
  nidevice_restricted_grpc::IsDebugSessionEnabledResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, SaveResourceChanges)
      .Times(0);

  ::grpc::Status status = service.IsDebugSessionEnabled(&context, &request, &response);

  EXPECT_TRUE(status.ok());
}

TEST(DebugSessionPropertiesTests, DeviceIsPresent_QueryDebugSessionServerOutOfProcess_SaveNotCalled)
{
  DebugSessionPropertiesSysCfgMockLibrary mock_library;
  nidevice_restricted_grpc::DebugSessionPropertiesRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::IsDebugSessionServerOutOfProcessRequest request;
  nidevice_restricted_grpc::IsDebugSessionServerOutOfProcessResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, SaveResourceChanges)
      .Times(0);

  ::grpc::Status status = service.IsDebugSessionServerOutOfProcess(&context, &request, &response);

  EXPECT_TRUE(status.ok());
}

TEST(DebugSessionPropertiesTests, DeviceIsPresent_SetDebugSessionEnabled_SaveIsCalled)
{
  DebugSessionPropertiesSysCfgMockLibrary mock_library;
  mock_library.set_expect_debug_enabled();
  nidevice_restricted_grpc::DebugSessionPropertiesRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::SetDebugSessionEnabledRequest request;
  nidevice_restricted_grpc::SetDebugSessionEnabledResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, SaveResourceChanges)
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = service.SetDebugSessionEnabled(&context, &request, &response);

  EXPECT_TRUE(status.ok());
}

TEST(DebugSessionPropertiesTests, DeviceIsPresent_SetDebugSessionServerOutOfProcess_SaveIsCalled)
{
  DebugSessionPropertiesSysCfgMockLibrary mock_library;
  mock_library.set_expect_out_of_process();
  nidevice_restricted_grpc::DebugSessionPropertiesRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::SetDebugSessionServerOutOfProcessRequest request;
  nidevice_restricted_grpc::SetDebugSessionServerOutOfProcessResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, SaveResourceChanges)
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = service.SetDebugSessionServerOutOfProcess(&context, &request, &response);

  EXPECT_TRUE(status.ok());
}

static NISysCfgStatus SetDetailedResultStringPointerToOne(char** detailedChanges)
{
  *detailedChanges = (char*)1;
  return NISysCfg_OK;
}

TEST(DebugSessionPropertiesTests, SaveDetailedResultStringIsNotNull_SetDebugSessionEnabled_StringPassedToFreeDetailedString)
{
  DebugSessionPropertiesSysCfgMockLibrary mock_library;
  mock_library.set_expect_debug_enabled();
  nidevice_restricted_grpc::DebugSessionPropertiesRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::SetDebugSessionEnabledRequest request;
  nidevice_restricted_grpc::SetDebugSessionEnabledResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, SaveResourceChanges)
      .WillOnce(WithArg<2>(SetDetailedResultStringPointerToOne));
  EXPECT_CALL(mock_library, FreeDetailedString((char*)1))
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = service.SetDebugSessionEnabled(&context, &request, &response);

  EXPECT_TRUE(status.ok());
}

TEST(DebugSessionPropertiesTests, SaveDetailedResultStringIsNull_SetDebugSessionEnabled_NullPassedToFreeDetailedString)
{
  DebugSessionPropertiesSysCfgMockLibrary mock_library;
  mock_library.set_expect_debug_enabled();
  nidevice_restricted_grpc::DebugSessionPropertiesRestrictedService service(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::SetDebugSessionEnabledRequest request;
  nidevice_restricted_grpc::SetDebugSessionEnabledResponse response;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, SaveResourceChanges)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, FreeDetailedString(NULL))
      .WillOnce(Return(NISysCfg_EndOfEnum));  // Function returns S_FALSE casted to NISysCfgStatus when str is NULL

  ::grpc::Status status = service.SetDebugSessionEnabled(&context, &request, &response);

  EXPECT_TRUE(status.ok());
}

}  // namespace unit
}  // namespace tests
}  // namespace ni