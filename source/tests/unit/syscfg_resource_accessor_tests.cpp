#include <grpcpp/test/server_context_test_spouse.h>
#include <gtest/gtest.h>
#include <server/syscfg_library.h>
#include <server/syscfg_resource_accessor.h>
#include <tests/utilities/syscfg_mock_library.h>

namespace ni {
namespace tests {
namespace unit {

using ::ni::tests::utilities::CastAndSetArgPointee;
using ::testing::_;
using ::testing::DoAll;
using ::testing::Invoke;
using ::testing::NiceMock;
using ::testing::Return;
using ::testing::SetArgPointee;
using ::testing::Throw;
using ::testing::WithArg;

static const char* kTestFailureMessage = "SysCfg access has failed.";

class SysCfgResourceAccessorTestImpl final :
  public ::nidevice_restricted_grpc::SysCfgResourceAccessor {
 public:
  SysCfgResourceAccessorTestImpl(::nidevice_grpc::SysCfgLibraryInterface* library) : SysCfgResourceAccessor(library) { }

  ::grpc::Status get_tcp_polling_interval(
    ::grpc::ServerContext* context,
    const nidevice_restricted_grpc::DeviceId& device_id,
    unsigned int* value)
  {
    auto get_tcp_polling_interval_lambda = [&] (nidevice_grpc::SysCfgLibraryInterface* library, NISysCfgResourceHandle resource, bool* save_changes) {
      return library->GetResourceProperty(resource, NISysCfgResourcePropertyTcpPollingInterval, value);
    };
    return access_syscfg_resource_by_device_id_filter(context, device_id, kTestFailureMessage, get_tcp_polling_interval_lambda);
  }

  ::grpc::Status set_tcp_polling_interval(
    ::grpc::ServerContext* context,
    const nidevice_restricted_grpc::DeviceId& device_id,
    unsigned int value)
  {
    auto set_tcp_polling_interval_lambda = [&] (nidevice_grpc::SysCfgLibraryInterface* library, NISysCfgResourceHandle resource, bool* save_changes) {
      *save_changes = true;
      return library->SetResourceProperty(resource, NISysCfgResourcePropertyTcpPollingInterval, value);
    };
    return access_syscfg_resource_by_device_id_filter(context, device_id, kTestFailureMessage, set_tcp_polling_interval_lambda);
  }
};

static const unsigned int kTcpPollingIntervalDefault = 10;

class SysCfgResourceAccessorSysCfgMockLibrary : public NiceMock<ni::tests::utilities::SysCfgMockLibrary> {
 public:
  SysCfgResourceAccessorSysCfgMockLibrary()
  {
    is_device_set_ = false;
    is_device_ = NISysCfgBoolFalse;
    user_alias_set_ = false;
    user_alias_ = "";
    serial_number_set_ = false;
    serial_number_ = "";
    product_id_set_ = false;
    product_id_ = 0;
    expect_tcp_polling_interval_ = false;
    tcp_polling_interval_set_ = false;
    tcp_polling_interval_ = kTcpPollingIntervalDefault;
  }
  ~SysCfgResourceAccessorSysCfgMockLibrary() {}

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
        is_device_ = (NISysCfgBool)va_arg(args, int);
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
      case NISysCfgResourcePropertyTcpPollingInterval: {
        if (expect_tcp_polling_interval_)
        {
          tcp_polling_interval_set_ = true;
          tcp_polling_interval_ = va_arg(args, unsigned int);
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
  void set_expect_tcp_polling_interval() { expect_tcp_polling_interval_ = true; }
  bool tcp_polling_interval_set() const { return tcp_polling_interval_set_; }
  unsigned int tcp_polling_interval() const { return tcp_polling_interval_; }

 private:
  bool is_device_set_;
  NISysCfgBool is_device_;
  bool user_alias_set_;
  std::string user_alias_;
  bool serial_number_set_;
  std::string serial_number_;
  bool product_id_set_;
  unsigned int product_id_;
  bool expect_tcp_polling_interval_;
  bool tcp_polling_interval_set_;
  unsigned int tcp_polling_interval_;
};

TEST(SysCfgResourceAccessorTests, SysCfgApiNotInstalled_QueryTcpPollingInterval_ReturnsNotFoundGrpcStatusCode)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  SysCfgResourceAccessorTestImpl testImpl(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::DeviceId device_id;
  unsigned int tcp_polling_interval;
  EXPECT_CALL(mock_library, InitializeSession)
      .WillOnce(Throw(nidevice_grpc::LibraryLoadException(nidevice_grpc::kSysCfgApiNotInstalledMessage)));
  EXPECT_CALL(mock_library, CloseHandle)
      .Times(0);

  ::grpc::Status status = testImpl.get_tcp_polling_interval(&context, device_id, &tcp_polling_interval);

  EXPECT_EQ(::grpc::StatusCode::NOT_FOUND, status.error_code());
  EXPECT_EQ(nidevice_grpc::kSysCfgApiNotInstalledMessage, status.error_message());
}

TEST(SysCfgResourceAccessorTests, InitializeSessionReturnsError_QueryTcpPollingInterval_ReturnsUnknownGrpcStatusCode)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  SysCfgResourceAccessorTestImpl testImpl(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::DeviceId device_id;
  unsigned int tcp_polling_interval;
  EXPECT_CALL(mock_library, InitializeSession)
      .WillOnce(Return(NISysCfg_InvalidLoginCredentials));
  EXPECT_CALL(mock_library, CloseHandle)
      .Times(0);

  ::grpc::Status status = testImpl.get_tcp_polling_interval(&context, device_id, &tcp_polling_interval);

  EXPECT_EQ(::grpc::StatusCode::UNKNOWN, status.error_code());
  EXPECT_EQ(kTestFailureMessage, status.error_message());
}

TEST(SysCfgResourceAccessorTests, InitializeSessionSucceeds_QueryTcpPollingInterval_CallsInitializeButNotClose)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  SysCfgResourceAccessorTestImpl testImpl(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::DeviceId device_id;
  unsigned int tcp_polling_interval;
  EXPECT_CALL(mock_library, InitializeSession)
      .WillOnce(DoAll(SetArgPointee<7>((NISysCfgSessionHandle)1), Return(NISysCfg_OK)));
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, CloseHandle(_))
      .WillRepeatedly(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, CloseHandle((void*)1))
      .Times(0);

  ::grpc::Status status = testImpl.get_tcp_polling_interval(&context, device_id, &tcp_polling_interval);

  EXPECT_EQ(::grpc::StatusCode::OK, status.error_code());
}

TEST(SysCfgResourceAccessorTests, CreateFilterReturnsError_QueryTcpPollingInterval_ReturnsUnknownErrorSysCfgErrorInMetadata)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  SysCfgResourceAccessorTestImpl testImpl(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::DeviceId device_id;
  unsigned int tcp_polling_interval;
  EXPECT_CALL(mock_library, CreateFilter)
      .WillOnce(Return(NISysCfg_InvalidArg));
  EXPECT_CALL(mock_library, FindHardware)
      .Times(0);

  ::grpc::Status status = testImpl.get_tcp_polling_interval(&context, device_id, &tcp_polling_interval);

  EXPECT_EQ(::grpc::StatusCode::UNKNOWN, status.error_code());
  EXPECT_EQ(kTestFailureMessage, status.error_message());
  ::grpc::testing::ServerContextTestSpouse spouse(&context);
  auto trailing_metadata = spouse.GetTrailingMetadata();
  auto error_iterator = trailing_metadata.find("ni-error");
  EXPECT_NE(trailing_metadata.end(), error_iterator);
  if (error_iterator != trailing_metadata.end())
  {
    EXPECT_EQ(NISysCfg_InvalidArg, std::stoi(error_iterator->second));
  }
}

TEST(SysCfgResourceAccessorTests, CreateFilterSetsFilterHandle_QueryTcpPollingInterval_FilterHandleIsPassedToCloseHandle)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  SysCfgResourceAccessorTestImpl testImpl(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::DeviceId device_id;
  unsigned int tcp_polling_interval;
  EXPECT_CALL(mock_library, CreateFilter)
      .WillOnce(DoAll(SetArgPointee<1>((NISysCfgFilterHandle)1), Return(NISysCfg_OK)));
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, CloseHandle)
      .WillRepeatedly(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, CloseHandle((void*)1))
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = testImpl.get_tcp_polling_interval(&context, device_id, &tcp_polling_interval);

  EXPECT_TRUE(status.ok());
}

TEST(SysCfgResourceAccessorTests, FindHardwareReturnsError_QueryTcpPollingInterval_ReturnsUnknownError)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  SysCfgResourceAccessorTestImpl testImpl(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::DeviceId device_id;
  unsigned int tcp_polling_interval;
  EXPECT_CALL(mock_library, FindHardware)
      .WillOnce(Return(NISysCfg_InvalidArg));
  EXPECT_CALL(mock_library, NextResource)
      .Times(0);

  ::grpc::Status status = testImpl.get_tcp_polling_interval(&context, device_id, &tcp_polling_interval);

  EXPECT_EQ(::grpc::StatusCode::UNKNOWN, status.error_code());
  EXPECT_EQ(kTestFailureMessage, status.error_message());
}

TEST(SysCfgResourceAccessorTests, FindHardwareSetsResourceEnumHandle_QueryTcpPollingInterval_ResourceEnumHandleIsPassedToNextResource)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  SysCfgResourceAccessorTestImpl testImpl(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::DeviceId device_id;
  unsigned int tcp_polling_interval;
  EXPECT_CALL(mock_library, FindHardware)
      .WillOnce(DoAll(SetArgPointee<4>((NISysCfgEnumResourceHandle)1), Return(NISysCfg_OK)));
  EXPECT_CALL(mock_library, NextResource(_, (void*)1, _))
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = testImpl.get_tcp_polling_interval(&context, device_id, &tcp_polling_interval);

  EXPECT_TRUE(status.ok());
}

TEST(SysCfgResourceAccessorTests, FindHardwareSetsResourceEnumHandle_QueryTcpPollingInterval_ResourceEnumHandleIsPassedToCloseHandle)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  SysCfgResourceAccessorTestImpl testImpl(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::DeviceId device_id;
  unsigned int tcp_polling_interval;
  EXPECT_CALL(mock_library, FindHardware)
      .WillOnce(DoAll(SetArgPointee<4>((NISysCfgEnumResourceHandle)1), Return(NISysCfg_OK)));
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, CloseHandle)
      .WillRepeatedly(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, CloseHandle((void*)1))
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = testImpl.get_tcp_polling_interval(&context, device_id, &tcp_polling_interval);

  EXPECT_TRUE(status.ok());
}

TEST(SysCfgResourceAccessorTests, NextResourceReturnsError_QueryTcpPollingInterval_ReturnsUnknownError)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  SysCfgResourceAccessorTestImpl testImpl(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::DeviceId device_id;
  unsigned int tcp_polling_interval;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_InvalidArg));
  EXPECT_CALL(mock_library, GetResourceIndexedProperty)
      .Times(0);

  ::grpc::Status status = testImpl.get_tcp_polling_interval(&context, device_id, &tcp_polling_interval);

  EXPECT_EQ(::grpc::StatusCode::UNKNOWN, status.error_code());
  EXPECT_EQ(kTestFailureMessage, status.error_message());
}

TEST(SysCfgResourceAccessorTests, NextResourceSetsResourceHandle_QueryTcpPollingInterval_ResourceHandleIsPassedToGetPropertyApis)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  SysCfgResourceAccessorTestImpl testImpl(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::DeviceId device_id;
  unsigned int tcp_polling_interval;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(DoAll(SetArgPointee<2>((NISysCfgResourceHandle)1), Return(NISysCfg_OK)));
  EXPECT_CALL(mock_library, GetResourceProperty((void*)1, _, _))
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = testImpl.get_tcp_polling_interval(&context, device_id, &tcp_polling_interval);

  EXPECT_TRUE(status.ok());
}

TEST(SysCfgResourceAccessorTests, NextResourceSetsResourceHandle_QueryTcpPollingInterval_ResourceHandleIsPassedToCloseHandle)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  SysCfgResourceAccessorTestImpl testImpl(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::DeviceId device_id;
  unsigned int tcp_polling_interval;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(DoAll(SetArgPointee<2>((NISysCfgResourceHandle)1), Return(NISysCfg_OK)));
  EXPECT_CALL(mock_library, CloseHandle)
      .WillRepeatedly(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, CloseHandle((void*)1))
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = testImpl.get_tcp_polling_interval(&context, device_id, &tcp_polling_interval);

  EXPECT_TRUE(status.ok());
}

TEST(SysCfgResourceAccessorTests, NoMatchForFilter_QueryTcpPollingInterval_ReturnsNotFoundError)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  SysCfgResourceAccessorTestImpl testImpl(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::DeviceId device_id;
  unsigned int tcp_polling_interval;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_EndOfEnum));

  ::grpc::Status status = testImpl.get_tcp_polling_interval(&context, device_id, &tcp_polling_interval);

  EXPECT_EQ(::grpc::StatusCode::NOT_FOUND, status.error_code());
  EXPECT_EQ(kTestFailureMessage, status.error_message());
}

static const char* kDeviceName = "MyVST";
static const char* kSerialNumber = "FEDCBA98";
static const uint32_t kProductId = 0x7991;

TEST(SysCfgResourceAccessorTests, DeviceIdPopulated_QueryTcpPollingInterval_FilterConfigured)
{
  SysCfgResourceAccessorSysCfgMockLibrary mock_library;
  SysCfgResourceAccessorTestImpl testImpl(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::DeviceId device_id;
  device_id.set_name(kDeviceName);
  device_id.set_serial_number(kSerialNumber);
  device_id.set_product_id(kProductId);
  unsigned int tcp_polling_interval;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = testImpl.get_tcp_polling_interval(&context, device_id, &tcp_polling_interval);

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

TEST(SysCfgResourceAccessorTests, DeviceIsPresent_QueryTcpPollingInterval_FilterModeMatchIsAll)
{
  SysCfgResourceAccessorSysCfgMockLibrary mock_library;
  SysCfgResourceAccessorTestImpl testImpl(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::DeviceId device_id;
  unsigned int tcp_polling_interval;
  EXPECT_CALL(mock_library, FindHardware(_, NISysCfgFilterModeMatchValuesAll, _, _, _))
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = testImpl.get_tcp_polling_interval(&context, device_id, &tcp_polling_interval);

  EXPECT_TRUE(status.ok());
}

TEST(SysCfgResourceAccessorTests, DeviceIsPresent_QueryTcpPollingInterval_ValueIsWritten)
{
  SysCfgResourceAccessorSysCfgMockLibrary mock_library;
  SysCfgResourceAccessorTestImpl testImpl(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::DeviceId device_id;
  unsigned int tcp_polling_interval;
  unsigned int expected_tcp_polling_interval = 125;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, GetResourceProperty(_, NISysCfgResourcePropertyTcpPollingInterval, _))
      .WillOnce(DoAll(CastAndSetArgPointee<2>(expected_tcp_polling_interval), Return(NISysCfg_OK)));

  ::grpc::Status status = testImpl.get_tcp_polling_interval(&context, device_id, &tcp_polling_interval);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(expected_tcp_polling_interval, tcp_polling_interval);
}

TEST(SysCfgResourceAccessorTests, DeviceIsPresent_QueryTcpPollingInterval_SaveNotCalled)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  SysCfgResourceAccessorTestImpl testImpl(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::DeviceId device_id;
  unsigned int tcp_polling_interval;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, SaveResourceChanges)
      .Times(0);

  ::grpc::Status status = testImpl.get_tcp_polling_interval(&context, device_id, &tcp_polling_interval);

  EXPECT_TRUE(status.ok());
}

TEST(SysCfgResourceAccessorTests, DeviceIsPresent_SetTcpPollingInterval_TcpPollingIntervalIsSet)
{
  SysCfgResourceAccessorSysCfgMockLibrary mock_library;
  mock_library.set_expect_tcp_polling_interval();
  SysCfgResourceAccessorTestImpl testImpl(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::DeviceId device_id;
  unsigned int expected_tcp_polling_interval = 250;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = testImpl.set_tcp_polling_interval(&context, device_id, expected_tcp_polling_interval);

  EXPECT_TRUE(status.ok());
  EXPECT_TRUE(mock_library.tcp_polling_interval_set());
  EXPECT_EQ(expected_tcp_polling_interval, mock_library.tcp_polling_interval());
}

TEST(SysCfgResourceAccessorTests, DeviceIsPresent_SetTcpPollingInterval_SaveIsCalled)
{
  SysCfgResourceAccessorSysCfgMockLibrary mock_library;
  mock_library.set_expect_tcp_polling_interval();
  SysCfgResourceAccessorTestImpl testImpl(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::DeviceId device_id;
  unsigned int expected_tcp_polling_interval = 500;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, SaveResourceChanges)
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = testImpl.set_tcp_polling_interval(&context, device_id, expected_tcp_polling_interval);

  EXPECT_TRUE(status.ok());
}

TEST(SysCfgResourceAccessorTests, SaveDetailedResultStringIsNotNull_SetTcpPollingInterval_StringPassedToFreeDetailedString)
{
  SysCfgResourceAccessorSysCfgMockLibrary mock_library;
  mock_library.set_expect_tcp_polling_interval();
  SysCfgResourceAccessorTestImpl testImpl(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::DeviceId device_id;
  unsigned int expected_tcp_polling_interval = 500;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, SaveResourceChanges)
      .WillOnce(DoAll(SetArgPointee<2>((char*)1), Return(NISysCfg_OK)));
  EXPECT_CALL(mock_library, FreeDetailedString((char*)1))
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = testImpl.set_tcp_polling_interval(&context, device_id, expected_tcp_polling_interval);

  EXPECT_TRUE(status.ok());
}

TEST(SysCfgResourceAccessorTests, SaveDetailedResultStringIsNull_SetTcpPollingInterval_NullPassedToFreeDetailedString)
{
  SysCfgResourceAccessorSysCfgMockLibrary mock_library;
  mock_library.set_expect_tcp_polling_interval();
  SysCfgResourceAccessorTestImpl testImpl(&mock_library);
  ::grpc::ServerContext context;
  nidevice_restricted_grpc::DeviceId device_id;
  unsigned int expected_tcp_polling_interval = 500;
  EXPECT_CALL(mock_library, NextResource)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, SaveResourceChanges)
      .WillOnce(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, FreeDetailedString(NULL))
      .WillOnce(Return(NISysCfg_EndOfEnum));  // Function returns S_FALSE casted to NISysCfgStatus when str is NULL

  ::grpc::Status status = testImpl.set_tcp_polling_interval(&context, device_id, expected_tcp_polling_interval);

  EXPECT_TRUE(status.ok());
}

}  // namespace unit
}  // namespace tests
}  // namespace ni