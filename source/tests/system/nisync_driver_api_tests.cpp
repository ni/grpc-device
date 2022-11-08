#include <gtest/gtest.h>

#include "device_server.h"
#include "enumerate_devices.h"
#include "nisync/nisync_client.h"

namespace ni {
namespace tests {
namespace system {

namespace nisync = nisync_grpc;
namespace pb = ::google::protobuf;

typedef pb::int32 int32;
typedef pb::uint32 uint32;
typedef pb::uint16 uint16;

constexpr auto INVALID_SOURCE_TERMINAL = 0xBFFA4032;
constexpr auto SESSION_NAME = "TestSession";
constexpr auto EMPTY_SESSION_NAME = "";
constexpr auto INVALID_RESOURCE_NAME = "InvalidName";
constexpr auto INVALID_TERMINAL = "Invalid";
constexpr auto NISYNC_VAL_OSCILLATOR = "Oscillator";
constexpr auto NISYNC_VAL_CLKOUT = "ClkOut";
constexpr auto NISYNC_ERROR_SRC_TERMINAL_INVALID = 0xBFFA4032;
constexpr auto NISYNC_VAL_CLKIN = "ClkIn";
constexpr auto NISYNC_VAL_SWTRIG_GLOBAL = "GlobalSorftwareTrigger";
constexpr auto NISYNC_VAL_PXIEDSTARC = "PXIe_DStarC";
constexpr auto NISYNC_VAL_SYNC_CLK_FULLSPEED = "SyncClkFullSpeed";
constexpr auto NISYNC_VAL_CLK100 = "PXIe_Clk100";
constexpr auto NISYNC_VAL_PFI0 = "PFI0";
constexpr auto NISYNC_VAL_PFI1 = "PFI1";
constexpr auto NISYNC_VAL_SYNC_CLK_ASYNC = "SyncClkAsync";
constexpr auto NISYNC_VAL_1588_CLK_ACCURACY_WITHIN_1_USEC = 4;
constexpr auto NISYNC_VAL_CLK10 = "PXI_Clk10";
constexpr auto NISYNC_VAL_IRIG_TYPE_IRIGB_DC = 0;
constexpr auto NISYNC_VAL_GND = "Ground";
constexpr auto NISYNC_ERROR_TERMINAL_INVALID = 0xBFFA4036;
constexpr auto NISYNC_ERROR_RSRC_NOT_RESERVED = 0xBFFA4048;
constexpr auto NISYNC_VAL_EDGE_RISING = 0;
constexpr auto NISYNC_ERROR_DRIVER_TIMEOUT = 0xBFFA400B;
constexpr auto NISYNC_VAL_LEVEL_LOW = 0;
constexpr auto NISYNC_VAL_LEVEL_HIGH = 1;
constexpr auto NISYNC_ERROR_FEATURE_NOT_SUPPORTED = 0xBFFA4003;
constexpr auto NISYNC_ERROR_DEST_TERMINAL_INVALID = 0xBFFA4033;

class NiSyncDriverApiTest : public ::testing::Test {
 protected:
  std::string test_resource_name;

  NiSyncDriverApiTest()
      : device_server_(DeviceServerInterface::Singleton()),
        nisync_stub_(nisync::NiSync::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiSyncDriverApiTest() {}

  virtual const char* get_model_name() const = 0;

  void SetUp() override
  {
    for (const auto& device : EnumerateDevices()) {
      if (device.model() == get_model_name()) {
        test_resource_name = device.name();
        break;
      }
    }

    if (test_resource_name.empty()) {
      GTEST_SKIP() << "No device found";
    }

    initialize_driver_session();
  }

  void TearDown() override
  {
    close_driver_session();
  }

  std::unique_ptr<nisync::NiSync::Stub>& GetStub()
  {
    return nisync_stub_;
  }

  void initialize_driver_session()
  {
    ::grpc::ClientContext context;
    nisync::InitRequest request;
    nisync::InitResponse response;
    request.set_resource_name(test_resource_name);
    request.set_session_name(SESSION_NAME);
    request.set_reset_device(false);

    ::grpc::Status status = GetStub()->Init(&context, request, &response);
    driver_session_ = std::make_unique<nidevice_grpc::Session>(response.vi());

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(VI_SUCCESS, response.status());
  }

  void close_driver_session()
  {
    if (!driver_session_) return;

    ::grpc::ClientContext context;
    nisync::CloseRequest request;
    request.mutable_vi()->set_name(driver_session_->name());
    nisync::CloseResponse response;

    ::grpc::Status status = GetStub()->Close(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(VI_SUCCESS, response.status());
  }

  ::grpc::Status call_RevisionQuery(std::string* driverRevision, std::string* firmwareRevision, int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::RevisionQueryRequest request;
    nisync::RevisionQueryResponse response;
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->RevisionQuery(&clientContext, request, &response);
    *driverRevision = response.driver_revision();
    *firmwareRevision = response.firmware_revision();
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_SendSoftwareTrigger(const std::string& srcTerminal, int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::SendSoftwareTriggerRequest request;
    nisync::SendSoftwareTriggerResponse response;
    request.set_src_terminal(srcTerminal);
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->SendSoftwareTrigger(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_ConnectClkTerminals(const std::string& srcTerminal, const std::string& destTerminal, int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::ConnectClkTerminalsRequest request;
    nisync::ConnectClkTerminalsResponse response;
    request.set_src_terminal(srcTerminal);
    request.set_dest_terminal(destTerminal);
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->ConnectClkTerminals(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_DisconnectClkTerminals(const std::string& srcTerminal, const std::string& destTerminal, int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::DisconnectClkTerminalsRequest request;
    nisync::DisconnectClkTerminalsResponse response;
    request.set_src_terminal(srcTerminal);
    request.set_dest_terminal(destTerminal);
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->DisconnectClkTerminals(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_ConnectSWTrigToTerminal(
      const std::string& srcTerminal,
      const std::string& destTerminal,
      const std::string& syncClock,
      int32 invert,
      int32 updateEdge,
      double delay,
      int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::ConnectSWTrigToTerminalRequest request;
    nisync::ConnectSWTrigToTerminalResponse response;
    request.set_src_terminal(srcTerminal);
    request.set_dest_terminal(destTerminal);
    request.set_sync_clock(syncClock);
    request.set_invert(invert);
    request.set_update_edge(updateEdge);
    request.set_delay(delay);
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->ConnectSWTrigToTerminal(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_DisconnectSWTrigFromTerminal(const std::string& srcTerminal, const std::string& destTerminal, int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::DisconnectSWTrigFromTerminalRequest request;
    nisync::DisconnectSWTrigFromTerminalResponse response;
    request.set_src_terminal(srcTerminal);
    request.set_dest_terminal(destTerminal);
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->DisconnectSWTrigFromTerminal(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_ConnectTrigTerminals(
      const std::string& srcTerminal,
      const std::string& destTerminal,
      const std::string& syncClock,
      int32 invert,
      int32 updateEdge,
      int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::ConnectTrigTerminalsRequest request;
    nisync::ConnectTrigTerminalsResponse response;
    request.set_src_terminal(srcTerminal);
    request.set_dest_terminal(destTerminal);
    request.set_sync_clock(syncClock);
    request.set_invert(invert);
    request.set_update_edge(updateEdge);
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->ConnectTrigTerminals(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_DisconnectTrigTerminals(const std::string& srcTerminal, const std::string& destTerminal, int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::DisconnectTrigTerminalsRequest request;
    nisync::DisconnectTrigTerminalsResponse response;
    request.set_src_terminal(srcTerminal);
    request.set_dest_terminal(destTerminal);
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->DisconnectTrigTerminals(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_SetAttributeViInt32(const std::string& activeItem, uint32 attribute, int32 value, int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::SetAttributeViInt32Request request;
    nisync::SetAttributeViInt32Response response;
    request.set_active_item(activeItem);
    request.set_attribute(static_cast<nisync::NiSyncAttribute>(attribute));
    request.set_value_raw(value);
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->SetAttributeViInt32(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_GetAttributeViInt32(const std::string& activeItem, uint32 attribute, int32* valueOut, int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::GetAttributeViInt32Request request;
    nisync::GetAttributeViInt32Response response;
    request.set_active_item(activeItem);
    request.set_attribute(static_cast<nisync::NiSyncAttribute>(attribute));
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->GetAttributeViInt32(&clientContext, request, &response);
    *valueOut = response.value();
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_SetAttributeViString(const std::string& activeItem, uint32 attribute, const std::string& value, int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::SetAttributeViStringRequest request;
    nisync::SetAttributeViStringResponse response;
    request.set_active_item(activeItem);
    request.set_attribute(static_cast<nisync::NiSyncAttribute>(attribute));
    request.set_value_raw(value);
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->SetAttributeViString(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_GetAttributeViString(const std::string& activeItem, uint32 attribute, std::string* valueOut, int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::GetAttributeViStringRequest request;
    nisync::GetAttributeViStringResponse response;
    request.set_active_item(activeItem);
    request.set_attribute(static_cast<nisync::NiSyncAttribute>(attribute));
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->GetAttributeViString(&clientContext, request, &response);
    *valueOut = response.value();
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_SetAttributeViBoolean(const std::string& activeItem, uint32 attribute, bool value, int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::SetAttributeViBooleanRequest request;
    nisync::SetAttributeViBooleanResponse response;
    request.set_active_item(activeItem);
    request.set_attribute(static_cast<nisync::NiSyncAttribute>(attribute));
    request.set_value(value);
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->SetAttributeViBoolean(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_GetAttributeViBoolean(const std::string& activeItem, uint32 attribute, bool* valueOut, int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::GetAttributeViBooleanRequest request;
    nisync::GetAttributeViBooleanResponse response;
    request.set_active_item(activeItem);
    request.set_attribute(static_cast<nisync::NiSyncAttribute>(attribute));
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->GetAttributeViBoolean(&clientContext, request, &response);
    *valueOut = response.value();
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_SetAttributeViReal64(const std::string& activeItem, uint32 attribute, double value, int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::SetAttributeViReal64Request request;
    nisync::SetAttributeViReal64Response response;
    request.set_active_item(activeItem);
    request.set_attribute(static_cast<nisync::NiSyncAttribute>(attribute));
    request.set_value_raw(value);
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->SetAttributeViReal64(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_GetAttributeViReal64(const std::string& activeItem, uint32 attribute, double* valueOut, int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::GetAttributeViReal64Request request;
    nisync::GetAttributeViReal64Response response;
    request.set_active_item(activeItem);
    request.set_attribute(static_cast<nisync::NiSyncAttribute>(attribute));
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->GetAttributeViReal64(&clientContext, request, &response);
    *valueOut = response.value();
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_MeasureFrequencyEx(
      const std::string& srcTerminal,
      double duration,
      uint32 decimationCount,
      double* actualDurationOut,
      double* frequencyOut,
      double* frequencyErrorOut,
      int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::MeasureFrequencyExRequest request;
    nisync::MeasureFrequencyExResponse response;
    request.set_src_terminal(srcTerminal);
    request.set_duration(duration);
    request.set_decimation_count(decimationCount);
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->MeasureFrequencyEx(&clientContext, request, &response);
    *actualDurationOut = response.actual_duration();
    *frequencyOut = response.frequency();
    *frequencyErrorOut = response.frequency_error();
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_GetTime(
      uint32* timeSeconds,
      uint32* timeNanoseconds,
      uint16* timeFractionalNanoseconds,
      int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::GetTimeRequest request;
    nisync::GetTimeResponse response;
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->GetTime(&clientContext, request, &response);
    *timeSeconds = response.time_seconds();
    *timeNanoseconds = response.time_nanoseconds();
    *timeFractionalNanoseconds = response.time_fractional_nanoseconds();
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_SetTimeReferenceFreeRunning(int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::SetTimeReferenceFreeRunningRequest request;
    nisync::SetTimeReferenceFreeRunningResponse response;
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->SetTimeReferenceFreeRunning(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_SetTimeReferenceGPS(int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::SetTimeReferenceGPSRequest request;
    nisync::SetTimeReferenceGPSResponse response;
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->SetTimeReferenceGPS(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_SetTimeReferenceIRIG(
      int32 irigType,
      const std::string& terminalName,
      int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::SetTimeReferenceIRIGRequest request;
    nisync::SetTimeReferenceIRIGResponse response;
    request.set_irig_type(irigType);
    request.set_terminal_name(terminalName);
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->SetTimeReferenceIRIG(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_SetTimeReferencePPS(
      const std::string& terminalName,
      bool useManualTime,
      uint32 initialTimeSeconds,
      uint32 initialTimeNanoseconds,
      uint16 initialTimeFractionalNanoseconds,
      int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::SetTimeReferencePPSRequest request;
    nisync::SetTimeReferencePPSResponse response;
    request.set_terminal_name(terminalName);
    request.set_use_manual_time(useManualTime);
    request.set_initial_time_seconds(initialTimeSeconds);
    request.set_initial_time_nanoseconds(initialTimeNanoseconds);
    request.set_initial_time_fractional_nanoseconds(initialTimeFractionalNanoseconds);
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->SetTimeReferencePPS(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_SetTimeReference1588OrdinaryClock(int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::SetTimeReference1588OrdinaryClockRequest request;
    nisync::SetTimeReference1588OrdinaryClockResponse response;
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->SetTimeReference1588OrdinaryClock(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_SetTimeReference8021AS(int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::SetTimeReference8021ASRequest request;
    nisync::SetTimeReference8021ASResponse response;
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->SetTimeReference8021AS(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_CreateFutureTimeEvent(
      const std::string& terminal,
      int32 outputLevel,
      uint32 timeSeconds,
      uint32 timeNanoseconds,
      uint16 timeFractionalNanoseconds,
      int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::CreateFutureTimeEventRequest request;
    nisync::CreateFutureTimeEventResponse response;
    request.set_terminal(terminal);
    request.set_output_level(outputLevel);
    request.set_time_seconds(timeSeconds);
    request.set_time_nanoseconds(timeNanoseconds);
    request.set_time_fractional_nanoseconds(timeFractionalNanoseconds);
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->CreateFutureTimeEvent(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  void CreateFutureTimeEvent(
      const std::string& terminal,
      int32 outputLevel,
      uint32 timeSeconds,
      uint32 timeNanoseconds,
      uint16 timeFractionalNanoseconds)
  {
    int32 viStatus;
    auto grpcStatus = call_CreateFutureTimeEvent(
        terminal,
        outputLevel,
        timeSeconds,
        timeNanoseconds,
        timeFractionalNanoseconds,
        &viStatus);
    ASSERT_TRUE(grpcStatus.ok());
    ASSERT_EQ(VI_SUCCESS, viStatus);
  }

  ::grpc::Status call_ClearFutureTimeEvents(
      const std::string& terminal,
      int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::ClearFutureTimeEventsRequest request;
    nisync::ClearFutureTimeEventsResponse response;
    request.set_terminal(terminal);
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->ClearFutureTimeEvents(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_CreateClock(
      const std::string& terminal,
      uint32 highTicks,
      uint32 lowTicks,
      uint32 startTimeSeconds,
      uint32 startTimeNanoseconds,
      uint16 startTimeFractionalNanoseconds,
      uint32 stopTimeSeconds,
      uint32 stopTimeNanoseconds,
      uint16 stopTimeFractionalNanoseconds,
      int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::CreateClockRequest request;
    nisync::CreateClockResponse response;
    request.set_terminal(terminal);
    request.set_high_ticks(highTicks);
    request.set_low_ticks(lowTicks);
    request.set_start_time_seconds(startTimeSeconds);
    request.set_start_time_nanoseconds(startTimeNanoseconds);
    request.set_start_time_fractional_nanoseconds(startTimeFractionalNanoseconds);
    request.set_stop_time_seconds(stopTimeSeconds);
    request.set_stop_time_nanoseconds(stopTimeNanoseconds);
    request.set_stop_time_fractional_nanoseconds(stopTimeFractionalNanoseconds);
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->CreateClock(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_ClearClock(
      const std::string& terminal,
      int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::ClearClockRequest request;
    nisync::ClearClockResponse response;
    request.set_terminal(terminal);
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->ClearClock(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_GetTimeReferenceNames(
      std::string* valueOut,
      int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::GetTimeReferenceNamesRequest request;
    request.mutable_vi()->set_name(driver_session_->name());
    nisync::GetTimeReferenceNamesResponse response;
    auto grpcStatus = GetStub()->GetTimeReferenceNames(&clientContext, request, &response);
    *valueOut = response.time_reference_names();
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_EnableTimeStampTrigger(
      const std::string& terminal,
      int32 activeEdge,
      int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::EnableTimeStampTriggerRequest request;
    nisync::EnableTimeStampTriggerResponse response;
    request.set_terminal(terminal);
    request.set_active_edge(activeEdge);
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->EnableTimeStampTrigger(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  void EnableTimeStampTrigger(
      const std::string& terminal,
      int32 activeEdge)
  {
    int32 viStatus;
    auto grpcStatus = call_EnableTimeStampTrigger(terminal, activeEdge, &viStatus);
    ASSERT_TRUE(grpcStatus.ok());
    ASSERT_EQ(VI_SUCCESS, viStatus);
  }

  ::grpc::Status call_ReadTriggerTimeStamp(
      const std::string& terminal,
      double timeout,
      uint32* timeSeconds,
      uint32* timeNanoseconds,
      uint16* timeFractionalNanoseconds,
      int32* detectedEdge,
      int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::ReadTriggerTimeStampRequest request;
    nisync::ReadTriggerTimeStampResponse response;
    request.set_terminal(terminal);
    request.set_timeout(timeout);
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->ReadTriggerTimeStamp(&clientContext, request, &response);
    *timeSeconds = response.time_seconds();
    *timeNanoseconds = response.time_nanoseconds();
    *timeFractionalNanoseconds = response.time_fractional_nanoseconds();
    *detectedEdge = response.detected_edge();
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_ReadMultipleTriggerTimeStamp(
      const std::string& terminal,
      double timeout,
      uint32 timestampsToRead,
      uint32* timeSecondsBuffer,
      uint32* timeNanosecondsBuffer,
      uint16* timeFractionalNanosecondsBuffer,
      int32* detectedEdgeBuffer,
      uint32* timestampsRead,
      int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::ReadMultipleTriggerTimeStampRequest request;
    nisync::ReadMultipleTriggerTimeStampResponse response;
    request.set_terminal(terminal);
    request.set_timeout(timeout);
    request.set_timestamps_to_read(timestampsToRead);
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->ReadMultipleTriggerTimeStamp(&clientContext, request, &response);
    *timestampsRead = response.timestamps_read();
    std::copy(response.time_seconds_buffer().begin(), response.time_seconds_buffer().end(), timeSecondsBuffer);
    std::copy(response.time_nanoseconds_buffer().begin(), response.time_nanoseconds_buffer().end(), timeNanosecondsBuffer);
    std::copy(response.time_fractional_nanoseconds_buffer().begin(), response.time_fractional_nanoseconds_buffer().end(), timeFractionalNanosecondsBuffer);
    std::copy(response.detected_edge_buffer().begin(), response.detected_edge_buffer().end(), detectedEdgeBuffer);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_DisableTimeStampTrigger(
      const std::string& terminal,
      int32* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::DisableTimeStampTriggerRequest request;
    nisync::DisableTimeStampTriggerResponse response;
    request.set_terminal(terminal);
    request.mutable_vi()->set_name(driver_session_->name());
    auto grpcStatus = GetStub()->DisableTimeStampTrigger(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  uint32 GetCurrentBoardTimeSeconds()
  {
    int32 viStatus;
    uint32 timeSeconds = 0, timeNanoseconds;
    uint16 timeFractionalNanoseconds;
    auto grpcStatus = call_GetTime(
        &timeSeconds,
        &timeNanoseconds,            // ignored
        &timeFractionalNanoseconds,  // ignored
        &viStatus);
    EXPECT_TRUE(grpcStatus.ok());
    EXPECT_EQ(VI_SUCCESS, viStatus);
    return timeSeconds;
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<::nidevice_grpc::Session> driver_session_;
  std::unique_ptr<nisync::NiSync::Stub> nisync_stub_;
};

class NiSyncDriver6674Test : public NiSyncDriverApiTest {
 public:
  NiSyncDriver6674Test() : NiSyncDriverApiTest() {}
  const char* get_model_name() const override { return "NI PXIe-6674T"; }
};

class NiSyncDriver6683Test : public NiSyncDriverApiTest {
 public:
  NiSyncDriver6683Test() : NiSyncDriverApiTest() {}
  const char* get_model_name() const override { return "NI PXI-6683H"; }
};

TEST_F(NiSyncDriver6674Test, RevisionQuery_ReturnsNonEmptyRevisions)
{
  int32 viStatus;
  std::string driverRevision, firmwareRevision;
  auto grpcStatus = call_RevisionQuery(&driverRevision, &firmwareRevision, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_FALSE(driverRevision.empty());
  EXPECT_FALSE(firmwareRevision.empty());
}

TEST_F(NiSyncDriver6674Test, ConnectClkTerminals_ReturnsSuccess)
{
  int32 viStatus;
  auto srcTerminal = NISYNC_VAL_OSCILLATOR, destTerminal = NISYNC_VAL_CLKOUT;
  auto grpcStatus = call_ConnectClkTerminals(srcTerminal, destTerminal, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
  call_DisconnectClkTerminals(srcTerminal, destTerminal, &viStatus);
}

TEST_F(NiSyncDriver6674Test, ConnectInvalidClkTerminals_ReturnsInvalidSrcTerminal)
{
  int32 viStatus;
  auto srcTerminal = INVALID_TERMINAL, destTerminal = NISYNC_VAL_CLKOUT;
  auto grpcStatus = call_ConnectClkTerminals(srcTerminal, destTerminal, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(NISYNC_ERROR_SRC_TERMINAL_INVALID, viStatus);
}

TEST_F(NiSyncDriver6674Test, ConnectedClkTerminals_DisconnectClkTerminals_ReturnsSuccess)
{
  int32 viStatus;
  auto srcTerminal = NISYNC_VAL_OSCILLATOR, destTerminal = NISYNC_VAL_CLKOUT;
  auto grpcStatus = call_ConnectClkTerminals(srcTerminal, destTerminal, &viStatus);
  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);

  grpcStatus = call_DisconnectClkTerminals(srcTerminal, destTerminal, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
}

TEST_F(NiSyncDriver6674Test, ConnectedClkTerminals_DisconnectNotConnectedClkTerminals_ReturnsSuccess)
{
  int32 viStatus;
  auto srcTerminal = NISYNC_VAL_OSCILLATOR, destTerminal = NISYNC_VAL_CLKOUT;
  auto grpcStatus = call_ConnectClkTerminals(srcTerminal, destTerminal, &viStatus);
  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);

  auto notConnectedSrcTerminal = NISYNC_VAL_CLKIN;
  grpcStatus = call_DisconnectClkTerminals(notConnectedSrcTerminal, destTerminal, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
  call_DisconnectClkTerminals(srcTerminal, destTerminal, &viStatus);
}

TEST_F(NiSyncDriver6674Test, ConnectSWTrigToTerminal_ReturnsSuccess)
{
  int32 viStatus;
  auto srcTerminal = NISYNC_VAL_SWTRIG_GLOBAL, destTerminal = NISYNC_VAL_PXIEDSTARC;
  auto syncClock = NISYNC_VAL_SYNC_CLK_FULLSPEED;
  int32 invert = true, updateEdge = false;
  double delay = 0;
  auto grpcStatus = call_ConnectSWTrigToTerminal(
      srcTerminal,
      destTerminal,
      syncClock,
      invert,
      updateEdge,
      delay,
      &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
  call_DisconnectSWTrigFromTerminal(srcTerminal, destTerminal, &viStatus);
}

TEST_F(NiSyncDriver6674Test, ConnectInvalidSWTrigToTerminal_ReturnsInvalidSrcTerminal)
{
  int32 viStatus;
  auto srcTerminal = INVALID_TERMINAL, destTerminal = NISYNC_VAL_PXIEDSTARC;
  auto syncClock = NISYNC_VAL_SYNC_CLK_FULLSPEED;
  int32 invert = true, updateEdge = false;
  double delay = 0;
  auto grpcStatus = call_ConnectSWTrigToTerminal(
      srcTerminal,
      destTerminal,
      syncClock,
      invert,
      updateEdge,
      delay,
      &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(INVALID_SOURCE_TERMINAL, viStatus);
}

TEST_F(NiSyncDriver6674Test, ConnectedSWTrigToTerminal_DisconnectSWTrigFromTerminal_ReturnsSuccess)
{
  int32 viStatus;
  auto srcTerminal = NISYNC_VAL_SWTRIG_GLOBAL, destTerminal = NISYNC_VAL_PXIEDSTARC;
  auto syncClock = NISYNC_VAL_SYNC_CLK_FULLSPEED;
  int32 invert = true, updateEdge = false;
  double delay = 0;
  auto grpcStatus = call_ConnectSWTrigToTerminal(
      srcTerminal,
      destTerminal,
      syncClock,
      invert,
      updateEdge,
      delay,
      &viStatus);
  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);

  grpcStatus = call_DisconnectSWTrigFromTerminal(srcTerminal, destTerminal, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
}

TEST_F(NiSyncDriver6674Test, SWTrigConnectedToTerminal_DisconnectSWTrigFromNotConnectedTerminal_ReturnsSuccess)
{
  int32 viStatus;
  auto srcTerminal = NISYNC_VAL_SWTRIG_GLOBAL, destTerminal = NISYNC_VAL_PXIEDSTARC;
  auto syncClock = NISYNC_VAL_SYNC_CLK_FULLSPEED;
  int32 invert = true, updateEdge = false;
  double delay = 0;
  auto grpcStatus = call_ConnectSWTrigToTerminal(
      srcTerminal,
      destTerminal,
      syncClock,
      invert,
      updateEdge,
      delay,
      &viStatus);
  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);

  auto notConnectedDestTerminal = NISYNC_VAL_CLK100;
  grpcStatus = call_DisconnectSWTrigFromTerminal(srcTerminal, notConnectedDestTerminal, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
  call_DisconnectSWTrigFromTerminal(srcTerminal, destTerminal, &viStatus);
}

TEST_F(NiSyncDriver6674Test, SendSoftwareTrigger_ReturnsSuccess)
{
  int32 viStatus;
  auto srcTerminal = NISYNC_VAL_SWTRIG_GLOBAL;
  auto grpcStatus = call_SendSoftwareTrigger(srcTerminal, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
}

TEST_F(NiSyncDriver6674Test, SendSoftwareTriggerOnInvalidTerminal_ReturnsInvalidSrcTerminal)
{
  int32 viStatus;
  auto srcTerminal = INVALID_TERMINAL;
  auto grpcStatus = call_SendSoftwareTrigger(srcTerminal, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(NISYNC_ERROR_SRC_TERMINAL_INVALID, viStatus);
}

TEST_F(NiSyncDriver6674Test, ConnectTrigTerminals_ReturnsSuccess)
{
  int32 viStatus;
  auto srcTerminal = NISYNC_VAL_PFI0, destTerminal = NISYNC_VAL_PFI1;
  auto syncClock = NISYNC_VAL_SYNC_CLK_ASYNC;
  int32 invert = false, updateEdge = false;
  auto grpcStatus = call_ConnectTrigTerminals(
      srcTerminal,
      destTerminal,
      syncClock,
      invert,
      updateEdge,
      &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
  call_DisconnectTrigTerminals(srcTerminal, destTerminal, &viStatus);
}

TEST_F(NiSyncDriver6674Test, ConnectInvalidTrigTerminals_ReturnsInvalidSrcTerminal)
{
  int32 viStatus;
  auto srcTerminal = INVALID_TERMINAL, destTerminal = NISYNC_VAL_CLKOUT;
  auto syncClock = NISYNC_VAL_SYNC_CLK_ASYNC;
  int32 invert = false, updateEdge = false;
  auto grpcStatus = call_ConnectTrigTerminals(
      srcTerminal,
      destTerminal,
      syncClock,
      invert,
      updateEdge,
      &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(INVALID_SOURCE_TERMINAL, viStatus);
}

TEST_F(NiSyncDriver6674Test, ConnectedTrigTerminals_DisconnectTrigTerminals_ReturnsSuccess)
{
  int32 viStatus;
  auto srcTerminal = NISYNC_VAL_PFI0, destTerminal = NISYNC_VAL_PFI1;
  auto syncClock = NISYNC_VAL_SYNC_CLK_ASYNC;
  int32 invert = false, updateEdge = false;
  auto grpcStatus = call_ConnectTrigTerminals(
      srcTerminal,
      destTerminal,
      syncClock,
      invert,
      updateEdge,
      &viStatus);
  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);

  grpcStatus = call_DisconnectTrigTerminals(srcTerminal, destTerminal, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
}

TEST_F(NiSyncDriver6674Test, NotConnectedTrigTerminals_DisconnectSWTrigFromTerminal_ReturnsSuccess)
{
  int32 viStatus;
  auto srcTerminal = NISYNC_VAL_PFI0, destTerminal = NISYNC_VAL_PFI1;
  auto syncClock = NISYNC_VAL_SYNC_CLK_ASYNC;
  int32 invert = false, updateEdge = false;
  auto grpcStatus = call_ConnectTrigTerminals(
      srcTerminal,
      destTerminal,
      syncClock,
      invert,
      updateEdge,
      &viStatus);
  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);

  auto notConnectedDestTerminal = NISYNC_VAL_CLK100;
  grpcStatus = call_DisconnectTrigTerminals(srcTerminal, notConnectedDestTerminal, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
  call_DisconnectTrigTerminals(srcTerminal, destTerminal, &viStatus);
}

TEST_F(NiSyncDriver6674Test, AttributeSet_GetAttributeViInt32_ReturnsValue)
{
  int32 viStatus;
  auto activeItem = "";
  uint32 attribute = nisync_grpc::NISYNC_ATTRIBUTE_SYNC_CLK_DIV1;
  int32 expectedValue = NISYNC_VAL_1588_CLK_ACCURACY_WITHIN_1_USEC;
  auto grpcStatus = call_SetAttributeViInt32(activeItem, attribute, expectedValue, &viStatus);
  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);

  int32 value;
  grpcStatus = call_GetAttributeViInt32(activeItem, attribute, &value, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
  EXPECT_EQ(expectedValue, value);
}

TEST_F(NiSyncDriver6674Test, AttributeSet_GetAttributeViString_ReturnsValue)
{
  int32 viStatus;
  auto activeItem = "";
  uint32 attribute = nisync_grpc::NISYNC_ATTRIBUTE_FRONT_SYNC_CLK_SRC;
  const std::string& expectedValue = NISYNC_VAL_CLK10;
  auto grpcStatus = call_SetAttributeViString(activeItem, attribute, expectedValue, &viStatus);
  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);

  std::string value;
  grpcStatus = call_GetAttributeViString(activeItem, attribute, &value, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
  EXPECT_STREQ(expectedValue.c_str(), value.c_str());
}

TEST_F(NiSyncDriver6674Test, AttributeSet_GetAttributeViBoolean_ReturnsValue)
{
  int32 viStatus;
  auto activeItem = "";
  uint32 attribute = nisync_grpc::NISYNC_ATTRIBUTE_CLKIN_ATTENUATION_DISABLE;
  bool expectedValue = true;
  auto grpcStatus = call_SetAttributeViBoolean(activeItem, attribute, expectedValue, &viStatus);
  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);

  bool value;
  grpcStatus = call_GetAttributeViBoolean(activeItem, attribute, &value, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
  EXPECT_EQ(expectedValue, value);
}

TEST_F(NiSyncDriver6674Test, AttributeSet_GetAttributeViReal64_ReturnsValue)
{
  int32 viStatus;
  auto activeItem = "";
  uint32 attribute = nisync_grpc::NISYNC_ATTRIBUTE_PFI0_THRESHOLD;
  double expectedValue = 2.3;
  auto grpcStatus = call_SetAttributeViReal64(activeItem, attribute, expectedValue, &viStatus);
  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);

  double value;
  grpcStatus = call_GetAttributeViReal64(activeItem, attribute, &value, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
  // 6674T has up to 16.8mV of resolution for PFI threshold. We'll loosen our
  // validation to a bit more than twice that to ensure we aren't testing
  // driver implementation details.
  EXPECT_NEAR(expectedValue, value, 50e-3);
}

TEST_F(NiSyncDriver6674Test, MeasureFrequencyExOnTerminalWithNoFrequency_ReturnsNoFrequency)
{
  int32 viStatus;
  const std::string& srcTerminal = NISYNC_VAL_PFI0;
  double duration = 0.1;       // duration is in seconds
  uint32 decimationCount = 0;  // ignored for 6674
  double actualDuration, frequency, frequencyError;
  auto grpcStatus = call_MeasureFrequencyEx(
      srcTerminal,
      duration,
      decimationCount,
      &actualDuration,
      &frequency,
      &frequencyError,
      &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
  EXPECT_EQ(0, actualDuration);
  EXPECT_EQ(0, frequency);
}

TEST_F(NiSyncDriver6674Test, MeasureFrequencyExOnOscillatorWithFrequency_ReturnsFrequency)
{
  int32 viStatus;
  const std::string& srcTerminal = NISYNC_VAL_OSCILLATOR;
  double duration = 0.1;       // duration is in seconds
  uint32 decimationCount = 0;  // ignored for 6674
  double actualDuration, frequency, frequencyError;
  auto grpcStatus = call_MeasureFrequencyEx(
      srcTerminal,
      duration,
      decimationCount,
      &actualDuration,
      &frequency,
      &frequencyError,
      &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
  EXPECT_GT(actualDuration, 0);
  EXPECT_GT(frequency, 0);
}

TEST_F(NiSyncDriver6683Test, GetTime_ReturnsTime)
{
  int32 viStatus;
  uint32 timeSeconds, timeNanoseconds;
  uint16 timeFractionalNanoseconds;
  auto grpcStatus = call_GetTime(
      &timeSeconds,
      &timeNanoseconds,
      &timeFractionalNanoseconds,  // ignored
      &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
  EXPECT_GT(timeSeconds, (uint32)0);
  EXPECT_GT(timeNanoseconds, (uint32)0);
}

TEST_F(NiSyncDriver6683Test, SetTimeReferenceFreeRunning_ReturnsSuccess)
{
  int32 viStatus;
  auto grpcStatus = call_SetTimeReferenceFreeRunning(&viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
}

TEST_F(NiSyncDriver6683Test, SetTimeReferenceGPS_ReturnsSuccess)
{
  int32 viStatus;
  auto grpcStatus = call_SetTimeReferenceGPS(&viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
}

TEST_F(NiSyncDriver6683Test, SetTimeReferenceIRIG_ReturnsSuccess)
{
  int32 viStatus;
  auto grpcStatus = call_SetTimeReferenceIRIG(
      NISYNC_VAL_IRIG_TYPE_IRIGB_DC,  // irigType
      NISYNC_VAL_PFI0,                // terminalName
      &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
}

TEST_F(NiSyncDriver6683Test, SetTimeReferenceIRIGWithInvalidTerminal_ReturnsError)
{
  int32 viStatus;
  auto grpcStatus = call_SetTimeReferenceIRIG(
      NISYNC_VAL_IRIG_TYPE_IRIGB_DC,  // irigType
      NISYNC_VAL_GND,                 // terminalName
      &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(NISYNC_ERROR_TERMINAL_INVALID, viStatus);
}

TEST_F(NiSyncDriver6683Test, SetTimeReferencePPS_ReturnsSuccess)
{
  int32 viStatus;
  uint32 initialTimeSeconds = 30, initialTimeNanoseconds = 500;
  auto grpcStatus = call_SetTimeReferencePPS(
      NISYNC_VAL_PFI1,  // terminalName
      true,             // useManualTime
      initialTimeSeconds,
      initialTimeNanoseconds,
      0,  // initialTimeFractionalNanoseconds, ignored
      &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);

  // Switch back to free-running to free up the PFI line.
  viStatus = VI_SUCCESS;
  grpcStatus = call_SetTimeReferenceFreeRunning(&viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
}

TEST_F(NiSyncDriver6683Test, SetTimeReferencePPSWithInvalidTerminal_ReturnsError)
{
  int32 viStatus;
  uint32 initialTimeSeconds = 30, initialTimeNanoseconds = 500;
  auto grpcStatus = call_SetTimeReferencePPS(
      NISYNC_VAL_GND,  // terminalName
      true,            // useManualTime
      initialTimeSeconds,
      initialTimeNanoseconds,
      0,  // initialTimeFractionalNanoseconds, ignored
      &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(NISYNC_ERROR_TERMINAL_INVALID, viStatus);
}

TEST_F(NiSyncDriver6683Test, SetTimeReference1588OrdinaryClock_ReturnsSuccess)
{
  int32 viStatus;
  auto grpcStatus = call_SetTimeReference1588OrdinaryClock(&viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
}

TEST_F(NiSyncDriver6683Test, SetTimeReference8021AS_ReturnsSuccess)
{
  // SetTimeReference8021AS is only supported in LinuxRT targets.
  int32 viStatus;
  auto grpcStatus = call_SetTimeReference8021AS(&viStatus);

  EXPECT_TRUE(grpcStatus.ok());
#if defined(_MSC_VER)
  // SetTimeReference8021AS is only supported on Linux RT targets.
  EXPECT_EQ(NISYNC_ERROR_FEATURE_NOT_SUPPORTED, viStatus);
#else
  EXPECT_EQ(VI_SUCCESS, viStatus);
#endif
}

TEST_F(NiSyncDriver6683Test, CreateClearFutureTimeEvent_ReturnsSuccess)
{
  int32 viStatusCreate;
  uint32 timeSeconds = GetCurrentBoardTimeSeconds() + 30;
  auto grpcStatusCreate = call_CreateFutureTimeEvent(
      NISYNC_VAL_PFI1,       // terminalName
      NISYNC_VAL_LEVEL_LOW,  // outputLevel
      timeSeconds,
      0,  // timeNanoseconds, ignored
      0,  // timeFractionalNanoseconds, ignored
      &viStatusCreate);
  EXPECT_TRUE(grpcStatusCreate.ok());
  EXPECT_EQ(VI_SUCCESS, viStatusCreate);

  int32 viStatusClear;
  auto grpcStatusClear = call_ClearFutureTimeEvents(
      NISYNC_VAL_PFI1,
      &viStatusClear);
  EXPECT_TRUE(grpcStatusClear.ok());
  EXPECT_EQ(VI_SUCCESS, viStatusClear);
}

TEST_F(NiSyncDriver6683Test, CreateFutureTimeEventWithInvalidTerminal_ReturnsError)
{
  int32 viStatus;
  uint32 timeSeconds = GetCurrentBoardTimeSeconds() + 30;
  auto grpcStatus = call_CreateFutureTimeEvent(
      NISYNC_VAL_GND,        // terminalName
      NISYNC_VAL_LEVEL_LOW,  // outputLevel
      timeSeconds,
      0,  // timeNanoseconds, ignored
      0,  // timeFractionalNanoseconds, ignored
      &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
// Bug 1462752: 6683 CreateFutureTimeEvent has different error behavior on Linux RT
#if defined(_MSC_VER)
  EXPECT_EQ(NISYNC_ERROR_TERMINAL_INVALID, viStatus);
#else
  EXPECT_EQ(NISYNC_ERROR_DEST_TERMINAL_INVALID, viStatus);
#endif
}

TEST_F(NiSyncDriver6683Test, ClearFutureTimeEventsNotReserved_ReturnsError)
{
  int32 viStatus;
  auto grpcStatus = call_ClearFutureTimeEvents(
      NISYNC_VAL_PFI1,  // terminalName
      &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(NISYNC_ERROR_RSRC_NOT_RESERVED, viStatus);
}

TEST_F(NiSyncDriver6683Test, CreateClearClock_ReturnsSuccess)
{
  int32 viStatusCreate;
  uint32 highTicks = 50, lowTicks = 50;
  uint32 startTimeSeconds = GetCurrentBoardTimeSeconds() + 30;
  uint32 stopTimeSeconds = startTimeSeconds + 30;
  auto grpcStatusCreate = call_CreateClock(
      NISYNC_VAL_PFI1,  // terminalName
      highTicks,
      lowTicks,
      startTimeSeconds,
      0,  // startTimeNanoseconds, ignored
      0,  // startTimeFractionalNanoseconds, ignored
      stopTimeSeconds,
      0,  // stopTimeNanoseconds, ignored
      0,  // stopTimeFractionalNanoseconds, ignored
      &viStatusCreate);
  EXPECT_TRUE(grpcStatusCreate.ok());
  EXPECT_EQ(VI_SUCCESS, viStatusCreate);

  int32 viStatusClear;
  auto grpcStatusClear = call_ClearClock(
      NISYNC_VAL_PFI1,
      &viStatusClear);
  EXPECT_TRUE(grpcStatusClear.ok());
  EXPECT_EQ(VI_SUCCESS, viStatusClear);
}

TEST_F(NiSyncDriver6683Test, CreateClockWithInvalidTerminal_ReturnsError)
{
  int32 viStatus;
  uint32 highTicks = 50, lowTicks = 50;
  uint32 startTimeSeconds = GetCurrentBoardTimeSeconds() + 30;
  uint32 stopTimeSeconds = startTimeSeconds + 30;
  auto grpcStatus = call_CreateClock(
      NISYNC_VAL_GND,  // terminalName
      highTicks,
      lowTicks,
      startTimeSeconds,
      0,  // startTimeNanoseconds, ignored
      0,  // startTimeFractionalNanoseconds, ignored
      stopTimeSeconds,
      0,  // stopTimeNanoseconds, ignored
      0,  // stopTimeFractionalNanoseconds, ignored
      &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
// Bug 1462754: 6683 CreateClock has different error behavior on Linux RT
#if defined(_MSC_VER)
  EXPECT_EQ(NISYNC_ERROR_TERMINAL_INVALID, viStatus);
#else
  EXPECT_EQ(NISYNC_ERROR_DEST_TERMINAL_INVALID, viStatus);
#endif
}

TEST_F(NiSyncDriver6683Test, ClearClockNotReserved_ReturnsError)
{
  int32 viStatus;
  auto grpcStatus = call_ClearClock(
      NISYNC_VAL_PFI1,  // terminalName
      &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(NISYNC_ERROR_RSRC_NOT_RESERVED, viStatus);
}

TEST_F(NiSyncDriver6683Test, GetTimeReferenceNames_ReturnsSuccess)
{
  int32 viStatus;
  std::string timeReferenceNames;
  auto grpcStatus = call_GetTimeReferenceNames(
      &timeReferenceNames,
      &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_GT(timeReferenceNames.length(), 0);
  EXPECT_EQ(VI_SUCCESS, viStatus);
}

TEST_F(NiSyncDriver6683Test, EnableTimeStampTrigger_ReturnsSuccess)
{
  int32 viStatusEnable;
  auto grpcStatusEnable = call_EnableTimeStampTrigger(
      NISYNC_VAL_PFI1,         // terminalName
      NISYNC_VAL_EDGE_RISING,  // activeEdge
      &viStatusEnable);
  EXPECT_TRUE(grpcStatusEnable.ok());
  EXPECT_EQ(VI_SUCCESS, viStatusEnable);

  int32 viStatusDisable;
  auto grpcStatusDisable = call_DisableTimeStampTrigger(
      NISYNC_VAL_PFI1,
      &viStatusDisable);
  EXPECT_TRUE(grpcStatusDisable.ok());
  EXPECT_EQ(VI_SUCCESS, viStatusDisable);
}

TEST_F(NiSyncDriver6683Test, EnableTimeStampTriggerWithInvalidTerminal_ReturnsError)
{
  int32 viStatus;
  auto grpcStatus = call_EnableTimeStampTrigger(
      NISYNC_VAL_GND,          // terminalName
      NISYNC_VAL_EDGE_RISING,  // activeEdge
      &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(NISYNC_ERROR_TERMINAL_INVALID, viStatus);
}

TEST_F(NiSyncDriver6683Test, DisableTimeStampTriggerNotReserved_ReturnsError)
{
  int32 viStatus;
  auto grpcStatus = call_DisableTimeStampTrigger(
      NISYNC_VAL_PFI1,  // terminalName
      &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(NISYNC_ERROR_RSRC_NOT_RESERVED, viStatus);
}

TEST_F(NiSyncDriver6683Test, GivenNoTrigger_ReadTriggerTimeStamp_ReturnsTimeoutError)
{
  auto terminal = NISYNC_VAL_PFI1;
  EnableTimeStampTrigger(terminal, NISYNC_VAL_EDGE_RISING);

  int32 viStatusRead;
  double timeout = 0.1;
  uint32 timeSeconds, timeNanoseconds;
  uint16 timeFractionalNanoseconds;
  int32 detectedEdge;
  auto grpcStatusRead = call_ReadTriggerTimeStamp(
      terminal,
      timeout,
      &timeSeconds,
      &timeNanoseconds,
      &timeFractionalNanoseconds,
      &detectedEdge,
      &viStatusRead);

  EXPECT_TRUE(grpcStatusRead.ok());
  EXPECT_EQ(NISYNC_ERROR_DRIVER_TIMEOUT, viStatusRead);
}

TEST_F(NiSyncDriver6683Test, GivenNoTrigger_ReadMultipleTriggerTimeStamp_ReturnsTimeoutError)
{
  auto terminal = NISYNC_VAL_PFI1;
  EnableTimeStampTrigger(terminal, NISYNC_VAL_EDGE_RISING);

  int32 viStatusRead;
  double timeout = 0.1;
  uint32 timestampsToRead = 1;
  uint32 timeSeconds, timeNanoseconds;
  uint16 timeFractionalNanoseconds;
  int32 detectedEdge;
  uint32 timestampsRead;
  auto grpcStatusRead = call_ReadMultipleTriggerTimeStamp(
      terminal,
      timeout,
      timestampsToRead,
      &timeSeconds,
      &timeNanoseconds,
      &timeFractionalNanoseconds,
      &detectedEdge,
      &timestampsRead,
      &viStatusRead);

  EXPECT_TRUE(grpcStatusRead.ok());
  EXPECT_EQ(NISYNC_ERROR_DRIVER_TIMEOUT, viStatusRead);
}

TEST_F(NiSyncDriver6683Test, GivenOneTrigger_ReadMultipleTriggerTimeStamp_ReturnsOneTimeStampAndTimeoutError)
{
  auto terminal = NISYNC_VAL_PFI1;
  // Ensure terminal level is low before enabling timestamping
  CreateFutureTimeEvent(terminal, NISYNC_VAL_LEVEL_LOW, 0, 0, 0);
  EnableTimeStampTrigger(terminal, NISYNC_VAL_EDGE_RISING);
  CreateFutureTimeEvent(terminal, NISYNC_VAL_LEVEL_HIGH, 0, 0, 0);
  CreateFutureTimeEvent(terminal, NISYNC_VAL_LEVEL_LOW, 0, 0, 0);

  int32 viStatusRead;
  double timeout = 1.0;
  const uint32 timestampsToRead = 5;
  uint32 timeSeconds[timestampsToRead] = {}, timeNanoseconds[timestampsToRead] = {};
  uint16 timeFractionalNanoseconds[timestampsToRead] = {};
  int32 detectedEdge[timestampsToRead] = {};
  uint32 timestampsRead = 0;
  auto grpcStatusRead = call_ReadMultipleTriggerTimeStamp(
      terminal,
      timeout,
      timestampsToRead,
      timeSeconds,
      timeNanoseconds,
      timeFractionalNanoseconds,
      detectedEdge,
      &timestampsRead,
      &viStatusRead);

  const uint32 expectedTimestampsRead = 1;
  EXPECT_TRUE(grpcStatusRead.ok());
  EXPECT_EQ(NISYNC_ERROR_DRIVER_TIMEOUT, viStatusRead);
  EXPECT_EQ(expectedTimestampsRead, timestampsRead);
  EXPECT_NE(0, timeSeconds[0]);
  EXPECT_EQ(NISYNC_VAL_EDGE_RISING, detectedEdge[0]);
}

TEST_F(NiSyncDriver6683Test, GivenFiveTriggers_ReadMultipleTriggerTimeStamp_ReturnsFiveTimeStamps)
{
  auto terminal = NISYNC_VAL_PFI1;
  // Ensure terminal level is low before enabling timestamping
  CreateFutureTimeEvent(terminal, NISYNC_VAL_LEVEL_LOW, 0, 0, 0);
  EnableTimeStampTrigger(terminal, NISYNC_VAL_EDGE_RISING);
  // Create 5 pulses
  int32 level = NISYNC_VAL_LEVEL_HIGH;
  for (int i = 0; i < 10; ++i) {
    SCOPED_TRACE(::testing::Message("i=") << i);
    CreateFutureTimeEvent(terminal, level, 0, 0, 0);
    level = (level == NISYNC_VAL_LEVEL_LOW) ? NISYNC_VAL_LEVEL_HIGH : NISYNC_VAL_LEVEL_LOW;
  }

  int32 viStatusRead;
  double timeout = 1.0;
  const uint32 timestampsToRead = 5;
  uint32 timeSeconds[timestampsToRead] = {}, timeNanoseconds[timestampsToRead] = {};
  uint16 timeFractionalNanoseconds[timestampsToRead] = {};
  int32 detectedEdge[timestampsToRead] = {};
  uint32 timestampsRead = 0;
  auto grpcStatusRead = call_ReadMultipleTriggerTimeStamp(
      terminal,
      timeout,
      timestampsToRead,
      timeSeconds,
      timeNanoseconds,
      timeFractionalNanoseconds,
      detectedEdge,
      &timestampsRead,
      &viStatusRead);

  EXPECT_TRUE(grpcStatusRead.ok());
  EXPECT_EQ(VI_SUCCESS, viStatusRead);
  EXPECT_EQ(timestampsToRead, timestampsRead);
  for (uint32 i = 0; i < timestampsRead; ++i) {
    SCOPED_TRACE(::testing::Message("i=") << i);
    EXPECT_NE(0, timeSeconds[i]);
    EXPECT_EQ(NISYNC_VAL_EDGE_RISING, detectedEdge[i]);
  }
}

}  // namespace system
}  // namespace tests
}  // namespace ni
