#include <gtest/gtest.h>
#include <server/software_enumerator.h>
#include <server/syscfg_library.h>
#include <tests/utilities/syscfg_mock_library.h>
#include <tests/utilities/syscfg_test_helpers.h>

namespace ni {
namespace tests {
namespace unit {

using ::testing::_;
using ::testing::NiceMock;
using ::testing::Return;
using ::testing::Throw;
using ::testing::WithArg;
using ::testing::WithArgs;

static const char* kPackageId = "ni-iotrace";
static const char* kProductName = "NI I/O Trace";
static const char* kVersion = "22.5.0.49215-0+f63";

TEST(SoftwareEnumeratorTests, SysCfgApiNotInstalled_EnumerateSoftware_ReturnsNotFoundGrpcStatusCode)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_grpc::SoftwareEnumerator software_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<nidevice_grpc::SoftwareProperties> software;
  EXPECT_CALL(mock_library, InitializeSession)
      .WillOnce(Throw(nidevice_grpc::LibraryLoadException(nidevice_grpc::kSysCfgApiNotInstalledMessage)));
  EXPECT_CALL(mock_library, CloseHandle)
      .Times(0);

  ::grpc::Status status = software_enumerator.enumerate_software(&software);

  EXPECT_EQ(::grpc::StatusCode::NOT_FOUND, status.error_code());
  EXPECT_EQ(nidevice_grpc::kSysCfgApiNotInstalledMessage, status.error_message());
}

TEST(SoftwareEnumeratorTests, SysCfgApiNotInstalled_EnumerateSoftware_SoftwareListIsEmpty)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_grpc::SoftwareEnumerator software_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<nidevice_grpc::SoftwareProperties> software;
  EXPECT_CALL(mock_library, InitializeSession)
      .WillOnce(Throw(nidevice_grpc::LibraryLoadException(nidevice_grpc::kSysCfgApiNotInstalledMessage)));

  ::grpc::Status status = software_enumerator.enumerate_software(&software);

  EXPECT_EQ(0, software.size());
}

TEST(SoftwareEnumeratorTests, InitializeSessionReturnsError_EnumerateSoftware_ReturnsInternalGrpcStatusCode)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_grpc::SoftwareEnumerator software_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<nidevice_grpc::SoftwareProperties> software;
  EXPECT_CALL(mock_library, InitializeSession)
      .WillOnce(Return(NISysCfg_InvalidLoginCredentials));
  EXPECT_CALL(mock_library, CloseHandle)
      .Times(0);

  ::grpc::Status status = software_enumerator.enumerate_software(&software);

  EXPECT_EQ(::grpc::StatusCode::INTERNAL, status.error_code());
  EXPECT_EQ(nidevice_grpc::kSoftwareEnumerationFailedMessage, status.error_message());
}

TEST(SoftwareEnumeratorTests, InitializeSessionReturnsError_EnumerateSoftware_SoftwareListIsEmpty)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_grpc::SoftwareEnumerator software_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<nidevice_grpc::SoftwareProperties> software;
  EXPECT_CALL(mock_library, InitializeSession)
      .WillOnce(Return(NISysCfg_InvalidLoginCredentials));

  ::grpc::Status status = software_enumerator.enumerate_software(&software);

  EXPECT_EQ(0, software.size());
}

TEST(SoftwareEnumeratorTests, InitializeSessionSucceeds_EnumerateSoftware_CallsInitializeButNotClose)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_grpc::SoftwareEnumerator software_enumerator(&mock_library);
  EXPECT_CALL(mock_library, InitializeSession)
      .WillOnce(WithArg<7>(SetSessionHandleToOne));
  EXPECT_CALL(mock_library, CloseHandle(_))
      .WillRepeatedly(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, CloseHandle((void*)1))
      .Times(0);

  google::protobuf::RepeatedPtrField<nidevice_grpc::SoftwareProperties> software;
  ::grpc::Status status = software_enumerator.enumerate_software(&software);

  EXPECT_EQ(::grpc::StatusCode::OK, status.error_code());
}

TEST(SoftwareEnumeratorTests, GetInstalledSoftwareComponentsReturnsError_EnumerateSoftware_SoftwareListIsEmptyAndReturnsInternalError)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_grpc::SoftwareEnumerator software_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<nidevice_grpc::SoftwareProperties> software;
  EXPECT_CALL(mock_library, GetInstalledSoftwareComponents)
      .WillOnce(Return(NISysCfg_InvalidArg));
  EXPECT_CALL(mock_library, ResetEnumeratorGetCount)
      .Times(0);
  EXPECT_CALL(mock_library, NextComponentInfo)
      .Times(0);

  ::grpc::Status status = software_enumerator.enumerate_software(&software);

  EXPECT_EQ(::grpc::StatusCode::INTERNAL, status.error_code());
  EXPECT_EQ(nidevice_grpc::kSoftwareEnumerationFailedMessage, status.error_message());
  EXPECT_EQ(0, software.size());
}

NISysCfgStatus SetEnumSoftwareComponentHandleToOne(NISysCfgEnumSoftwareComponentHandle* enum_software_component_handle)
{
  *enum_software_component_handle = (NISysCfgEnumSoftwareComponentHandle)1;
  return NISysCfg_OK;
}

TEST(SoftwareEnumeratorTests, GetInstalledSoftwareComponentsSetsEnumSoftwareComponentHandle_EnumerateSoftware_SoftwareComponentHandleIsPassedToCloseHandle)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_grpc::SoftwareEnumerator software_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<nidevice_grpc::SoftwareProperties> software;
  EXPECT_CALL(mock_library, GetInstalledSoftwareComponents)
      .WillOnce(WithArg<3>(SetEnumSoftwareComponentHandleToOne));
  EXPECT_CALL(mock_library, CloseHandle)
      .WillRepeatedly(Return(NISysCfg_OK));
  EXPECT_CALL(mock_library, CloseHandle((void*)1))
      .WillOnce(Return(NISysCfg_OK));

  ::grpc::Status status = software_enumerator.enumerate_software(&software);

  EXPECT_TRUE(status.ok());
}

NISysCfgStatus SetEnumeratorCountToOne(unsigned int* numInstalledComps)
{
  *numInstalledComps = 1;
  return NISysCfg_OK;
}

TEST(SoftwareEnumeratorTests, GetInstalledSoftwareComponentsSetsEnumSoftwareComponentHandle_EnumerateDevices_ComponentHandleIsPassedToNextComponentInfo)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_grpc::SoftwareEnumerator software_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<nidevice_grpc::SoftwareProperties> software;
  EXPECT_CALL(mock_library, GetInstalledSoftwareComponents)
      .WillOnce(WithArg<3>(SetEnumSoftwareComponentHandleToOne));
  EXPECT_CALL(mock_library, ResetEnumeratorGetCount)
      .WillOnce(WithArg<1>(SetEnumeratorCountToOne));
  EXPECT_CALL(mock_library, NextComponentInfo((void*)1, _, _, _, _, _))
      .WillOnce(Return(NISysCfg_EndOfEnum));

  ::grpc::Status status = software_enumerator.enumerate_software(&software);

  EXPECT_TRUE(status.ok());
}

TEST(SoftwareEnumeratorTests, ResetEnumeratorGetCountReturnsError_EnumerateSoftware_SoftwareListIsEmptyAndReturnsInternalError)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_grpc::SoftwareEnumerator software_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<nidevice_grpc::SoftwareProperties> software;
  EXPECT_CALL(mock_library, ResetEnumeratorGetCount)
      .WillOnce(Return(NISysCfg_InvalidArg));
  EXPECT_CALL(mock_library, NextComponentInfo)
      .Times(0);

  ::grpc::Status status = software_enumerator.enumerate_software(&software);

  EXPECT_EQ(::grpc::StatusCode::INTERNAL, status.error_code());
  EXPECT_EQ(nidevice_grpc::kSoftwareEnumerationFailedMessage, status.error_message());
  EXPECT_EQ(0, software.size());
}

TEST(SoftwareEnumeratorTests, NextComponentInfoReturnsError_EnumerateSoftware_SoftwareListIsEmptyAndReturnsInternalError)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_grpc::SoftwareEnumerator software_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<nidevice_grpc::SoftwareProperties> software;
  EXPECT_CALL(mock_library, GetInstalledSoftwareComponents)
      .WillOnce(WithArg<3>(SetEnumSoftwareComponentHandleToOne));
  EXPECT_CALL(mock_library, ResetEnumeratorGetCount)
      .WillOnce(WithArg<1>(SetEnumeratorCountToOne));
  EXPECT_CALL(mock_library, NextComponentInfo((void*)1, _, _, _, _, _))
      .WillOnce(Return(NISysCfg_InvalidArg));

  ::grpc::Status status = software_enumerator.enumerate_software(&software);

  EXPECT_EQ(::grpc::StatusCode::INTERNAL, status.error_code());
  EXPECT_EQ(nidevice_grpc::kSoftwareEnumerationFailedMessage, status.error_message());
  EXPECT_EQ(0, software.size());
}

NISysCfgStatus SetEnumeratorCountToZero(unsigned int* numInstalledComps)
{
  *numInstalledComps = 0;
  return NISysCfg_OK;
}

TEST(SoftwareEnumeratorTests, SysCfgApiInstalledAndNoNISoftwarePresent_EnumerateSoftware_SoftwareListIsEmpty)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_grpc::SoftwareEnumerator software_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<nidevice_grpc::SoftwareProperties> software;
  EXPECT_CALL(mock_library, GetInstalledSoftwareComponents)
      .WillOnce(WithArg<3>(SetEnumSoftwareComponentHandleToOne));
  EXPECT_CALL(mock_library, ResetEnumeratorGetCount((void*)1, _))
      .WillOnce(WithArg<1>(SetEnumeratorCountToZero));

  ::grpc::Status status = software_enumerator.enumerate_software(&software);

  EXPECT_EQ(::grpc::StatusCode::OK, status.error_code());
  EXPECT_EQ(0, software.size());
}

TEST(SoftwareEnumeratorTests, NISysCfgLibraryIsLoaded_GetSysCfgSession_CallsInitializeSessionOnceAndReturnsOK)
{
  ni::tests::utilities::SysCfgMockLibrary mock_library;
  nidevice_grpc::SoftwareEnumerator software_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<nidevice_grpc::SoftwareProperties> software;
  EXPECT_CALL(mock_library, InitializeSession)
      .WillOnce(WithArg<7>(SetSessionHandleToOne));
  NISysCfgSessionHandle session1 = nullptr;
  NISysCfgStatus status = software_enumerator.open_or_get_localhost_syscfg_session(&session1);

  NISysCfgSessionHandle session2 = nullptr;
  status = software_enumerator.open_or_get_localhost_syscfg_session(&session2);

  EXPECT_EQ(session1, session2);
  EXPECT_EQ(NISysCfg_OK, status);
}

TEST(SoftwareEnumeratorTests, NISysCfgLibraryIsLoaded_ClearSysCfgSession_CalledCloseHandleOnce)
{
  ni::tests::utilities::SysCfgMockLibrary mock_library;
  nidevice_grpc::SoftwareEnumerator software_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<nidevice_grpc::SoftwareProperties> software;
  EXPECT_CALL(mock_library, InitializeSession)
      .WillRepeatedly(WithArg<7>(SetSessionHandleToOne));
  EXPECT_CALL(mock_library, CloseHandle)
      .Times(1);
  NISysCfgSessionHandle session = nullptr;
  NISysCfgStatus status = software_enumerator.open_or_get_localhost_syscfg_session(&session);

  software_enumerator.clear_syscfg_session();
  software_enumerator.clear_syscfg_session();

  status = software_enumerator.open_or_get_localhost_syscfg_session(&session);
}

NISysCfgStatus SetPackageId(void* value)
{
  char* id = (char*)value;
  strcpy(id, kPackageId);
  return NISysCfg_OK;
}

TEST(SoftwareEnumeratorTests, NextComponentInfoSetsPackageId_EnumerateSoftware_ResponseContainsThatPackageId)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_grpc::SoftwareEnumerator software_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<nidevice_grpc::SoftwareProperties> software;
  EXPECT_CALL(mock_library, GetInstalledSoftwareComponents)
      .WillOnce(WithArg<3>(SetEnumSoftwareComponentHandleToOne));
  EXPECT_CALL(mock_library, ResetEnumeratorGetCount)
      .WillOnce(WithArg<1>(SetEnumeratorCountToOne));
  EXPECT_CALL(mock_library, NextComponentInfo((void*)1, _, _, _, _, _))
      .WillOnce(WithArg<1>(SetPackageId))
      .WillOnce(Return(NISysCfg_EndOfEnum));

  ::grpc::Status status = software_enumerator.enumerate_software(&software);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(1, software.size());
  EXPECT_EQ(kPackageId, software.Get(0).package_id());
}

NISysCfgStatus SetVersion(void* value)
{
  char* version = (char*)value;
  strcpy(version, kVersion);
  return NISysCfg_OK;
}

TEST(SoftwareEnumeratorTests, NextComponentInfoSetsVersion_EnumerateSoftware_ResponseContainsThatVersion)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_grpc::SoftwareEnumerator software_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<nidevice_grpc::SoftwareProperties> software;
  EXPECT_CALL(mock_library, GetInstalledSoftwareComponents)
      .WillOnce(WithArg<3>(SetEnumSoftwareComponentHandleToOne));
  EXPECT_CALL(mock_library, ResetEnumeratorGetCount)
      .WillOnce(WithArg<1>(SetEnumeratorCountToOne));
  EXPECT_CALL(mock_library, NextComponentInfo((void*)1, _, _, _, _, _))
      .WillOnce(WithArg<2>(SetVersion))
      .WillOnce(Return(NISysCfg_EndOfEnum));

  ::grpc::Status status = software_enumerator.enumerate_software(&software);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(1, software.size());
  EXPECT_EQ(kVersion, software.Get(0).version());
}

NISysCfgStatus SetProductName(void* value)
{
  char* name = (char*)value;
  strcpy(name, kProductName);
  return NISysCfg_OK;
}

TEST(SoftwareEnumeratorTests, NextComponentInfoSetsProductName_EnumerateSoftware_ResponseContainsThatProductName)
{
  NiceMock<ni::tests::utilities::SysCfgMockLibrary> mock_library;
  nidevice_grpc::SoftwareEnumerator software_enumerator(&mock_library);
  google::protobuf::RepeatedPtrField<nidevice_grpc::SoftwareProperties> software;
  EXPECT_CALL(mock_library, GetInstalledSoftwareComponents)
      .WillOnce(WithArg<3>(SetEnumSoftwareComponentHandleToOne));
  EXPECT_CALL(mock_library, ResetEnumeratorGetCount)
      .WillOnce(WithArg<1>(SetEnumeratorCountToOne));
  EXPECT_CALL(mock_library, NextComponentInfo((void*)1, _, _, _, _, _))
      .WillOnce(WithArg<3>(SetProductName))
      .WillOnce(Return(NISysCfg_EndOfEnum));

  ::grpc::Status status = software_enumerator.enumerate_software(&software);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(1, software.size());
  EXPECT_EQ(kProductName, software.Get(0).product_name());
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
