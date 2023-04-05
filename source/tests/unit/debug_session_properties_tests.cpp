#include <grpcpp/test/server_context_test_spouse.h>
#include <gtest/gtest.h>
#include <server/debug_session_properties_restricted_service.h>
#include <server/syscfg_library.h>
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
using ::testing::Throw;
using ::testing::WithArg;

class DebugSessionPropertiesSysCfgMockLibrary : public NiceMock<ni::tests::utilities::SysCfgMockLibrary> {
 public:
  DebugSessionPropertiesSysCfgMockLibrary()
  {
    expect_debug_enabled_ = false;
    debug_enabled_set_ = false;
    debug_enabled_ = 0;
    expect_out_of_process_ = false;
    out_of_process_set_ = false;
    out_of_process_ = NISysCfgBoolFalse;
  }
  ~DebugSessionPropertiesSysCfgMockLibrary() {}

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
          out_of_process_ = (NISysCfgBool)va_arg(args, int);
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

  void set_expect_debug_enabled() { expect_debug_enabled_ = true; }
  bool debug_enabled_set() const { return debug_enabled_set_; }
  unsigned int debug_enabled() const { return debug_enabled_; }
  void set_expect_out_of_process() { expect_out_of_process_ = true; }
  bool out_of_process_set() const { return out_of_process_set_; }
  NISysCfgBool out_of_process() const { return out_of_process_; }

 private:
  bool expect_debug_enabled_;
  bool debug_enabled_set_;
  unsigned int debug_enabled_;
  bool expect_out_of_process_;
  bool out_of_process_set_;
  NISysCfgBool out_of_process_;
};

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
      .WillOnce(DoAll(CastAndSetArgPointee<2>(NISysCfgBoolTrue), Return(NISysCfg_OK)));

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
      .WillOnce(DoAll(CastAndSetArgPointee<2>((unsigned int)1), Return(NISysCfg_OK)));

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
      .WillOnce(DoAll(CastAndSetArgPointee<2>(NISysCfgBoolTrue), Return(NISysCfg_OK)));

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

}  // namespace unit
}  // namespace tests
}  // namespace ni