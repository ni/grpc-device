#include <gtest/gtest.h>

#include "device_server.h"
#include "nisync/nisync_service.h"
#include "enumerate_devices.h"

namespace ni {
namespace tests {
namespace system {

namespace nisync = nisync_grpc;

static const ViStatus kSyncInvalidSrcTerminal = 0xBFFA4032;
static const char* kTestSessionName = "TestSession";
static const char* kEmptySessionName = "";
static const char* kInvalidRsrcName = "InvalidName";
static const char* kInvalidTerminal = "Invalid";

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
    for(const auto& device : EnumerateDevices()) {
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
    request.set_session_name(kTestSessionName);
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
    request.mutable_vi()->set_id(driver_session_->id());
    nisync::CloseResponse response;

    ::grpc::Status status = GetStub()->Close(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(VI_SUCCESS, response.status());
  }

  ::grpc::Status call_RevisionQuery(std::string* driverRevision, std::string* firmwareRevision, ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::RevisionQueryRequest request;
    nisync::RevisionQueryResponse response;
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->RevisionQuery(&clientContext, request, &response);
    *driverRevision = response.driver_revision();
    *firmwareRevision = response.firmware_revision();
    *viStatusOut = response.status();
    return grpcStatus;
  }


  ::grpc::Status call_SendSoftwareTrigger(ViConstString srcTerminal, ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::SendSoftwareTriggerRequest request;
    nisync::SendSoftwareTriggerResponse response;
    request.set_src_terminal(srcTerminal);
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->SendSoftwareTrigger(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_ConnectClkTerminals(ViConstString srcTerminal, ViConstString destTerminal, ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::ConnectClkTerminalsRequest request;
    nisync::ConnectClkTerminalsResponse response;
    request.set_src_terminal(srcTerminal);
    request.set_dest_terminal(destTerminal);
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->ConnectClkTerminals(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_DisconnectClkTerminals(ViConstString srcTerminal, ViConstString destTerminal, ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::DisconnectClkTerminalsRequest request;
    nisync::DisconnectClkTerminalsResponse response;
    request.set_src_terminal(srcTerminal);
    request.set_dest_terminal(destTerminal);
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->DisconnectClkTerminals(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_ConnectSWTrigToTerminal(
    ViConstString srcTerminal,
    ViConstString destTerminal,
    ViConstString syncClock,
    ViInt32 invert,
    ViInt32 updateEdge,
    ViReal64 delay,
    ViStatus* viStatusOut)
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
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->ConnectSWTrigToTerminal(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_DisconnectSWTrigFromTerminal(ViConstString srcTerminal, ViConstString destTerminal, ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::DisconnectSWTrigFromTerminalRequest request;
    nisync::DisconnectSWTrigFromTerminalResponse response;
    request.set_src_terminal(srcTerminal);
    request.set_dest_terminal(destTerminal);
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->DisconnectSWTrigFromTerminal(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_ConnectTrigTerminals(
    ViConstString srcTerminal,
    ViConstString destTerminal,
    ViConstString syncClock,
    ViInt32 invert,
    ViInt32 updateEdge,
    ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::ConnectTrigTerminalsRequest request;
    nisync::ConnectTrigTerminalsResponse response;
    request.set_src_terminal(srcTerminal);
    request.set_dest_terminal(destTerminal);
    request.set_sync_clock(syncClock);
    request.set_invert(invert);
    request.set_update_edge(updateEdge);
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->ConnectTrigTerminals(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_DisconnectTrigTerminals(ViConstString srcTerminal, ViConstString destTerminal, ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::DisconnectTrigTerminalsRequest request;
    nisync::DisconnectTrigTerminalsResponse response;
    request.set_src_terminal(srcTerminal);
    request.set_dest_terminal(destTerminal);
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->DisconnectTrigTerminals(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_SetAttributeViInt32(ViConstString activeItem, ViAttr attribute, ViInt32 value, ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::SetAttributeViInt32Request request;
    nisync::SetAttributeViInt32Response response;
    request.set_active_item(activeItem);
    request.set_attribute(static_cast<nisync::NiSyncAttributes>(attribute));
    request.set_value_raw(value);
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->SetAttributeViInt32(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_GetAttributeViInt32(ViConstString activeItem, ViAttr attribute, ViInt32* valueOut, ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::GetAttributeViInt32Request request;
    nisync::GetAttributeViInt32Response response;
    request.set_active_item(activeItem);
    request.set_attribute(static_cast<nisync::NiSyncAttributes>(attribute));
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->GetAttributeViInt32(&clientContext, request, &response);
    *valueOut = response.value();
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_SetAttributeViString(ViConstString activeItem, ViAttr attribute, ViConstString value, ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::SetAttributeViStringRequest request;
    nisync::SetAttributeViStringResponse response;
    request.set_active_item(activeItem);
    request.set_attribute(static_cast<nisync::NiSyncAttributes>(attribute));
    request.set_value_raw(value);
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->SetAttributeViString(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_GetAttributeViString(ViConstString activeItem, ViAttr attribute, std::string* valueOut, ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::GetAttributeViStringRequest request;
    nisync::GetAttributeViStringResponse response;
    request.set_active_item(activeItem);
    request.set_attribute(static_cast<nisync::NiSyncAttributes>(attribute));
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->GetAttributeViString(&clientContext, request, &response);
    *valueOut = response.value();
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_SetAttributeViBoolean(ViConstString activeItem, ViAttr attribute, ViBoolean value, ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::SetAttributeViBooleanRequest request;
    nisync::SetAttributeViBooleanResponse response;
    request.set_active_item(activeItem);
    request.set_attribute(static_cast<nisync::NiSyncAttributes>(attribute));
    request.set_value(value);
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->SetAttributeViBoolean(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_GetAttributeViBoolean(ViConstString activeItem, ViAttr attribute, ViBoolean* valueOut, ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::GetAttributeViBooleanRequest request;
    nisync::GetAttributeViBooleanResponse response;
    request.set_active_item(activeItem);
    request.set_attribute(static_cast<nisync::NiSyncAttributes>(attribute));
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->GetAttributeViBoolean(&clientContext, request, &response);
    *valueOut = response.value();
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_SetAttributeViReal64(ViConstString activeItem, ViAttr attribute, ViReal64 value, ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::SetAttributeViReal64Request request;
    nisync::SetAttributeViReal64Response response;
    request.set_active_item(activeItem);
    request.set_attribute(static_cast<nisync::NiSyncAttributes>(attribute));
    request.set_value_raw(value);
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->SetAttributeViReal64(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_GetAttributeViReal64(ViConstString activeItem, ViAttr attribute, ViReal64* valueOut, ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::GetAttributeViReal64Request request;
    nisync::GetAttributeViReal64Response response;
    request.set_active_item(activeItem);
    request.set_attribute(static_cast<nisync::NiSyncAttributes>(attribute));
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->GetAttributeViReal64(&clientContext, request, &response);
    *valueOut = response.value();
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_MeasureFrequencyEx(
     ViConstString srcTerminal,
     ViReal64 duration,
     ViUInt32 decimationCount,
     ViReal64* actualDurationOut,
     ViReal64* frequencyOut,
     ViReal64* frequencyErrorOut,
     ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::MeasureFrequencyExRequest request;
    nisync::MeasureFrequencyExResponse response;
    request.set_src_terminal(srcTerminal);
    request.set_duration(duration);
    request.set_decimation_count(decimationCount);
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->MeasureFrequencyEx(&clientContext, request, &response);
    *actualDurationOut = response.actual_duration();
    *frequencyOut = response.frequency();
    *frequencyErrorOut = response.frequency_error();
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_SetTime(
     ViInt32 timeSource,
     ViUInt32 timeSeconds,
     ViUInt32 timeNanoseconds,
     ViUInt16 timeFractionalNanoseconds,
     ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::SetTimeRequest request;
    nisync::SetTimeResponse response;
    request.set_time_source(timeSource);
    request.set_time_seconds(timeSeconds);
    request.set_time_nanoseconds(timeNanoseconds);
    request.set_time_fractional_nanoseconds(timeFractionalNanoseconds);
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->SetTime(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_GetTime(
     ViUInt32* timeSeconds,
     ViUInt32* timeNanoseconds,
     ViUInt16* timeFractionalNanoseconds,
     ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::GetTimeRequest request;
    nisync::GetTimeResponse response;
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->GetTime(&clientContext, request, &response);
    *timeSeconds = response.time_seconds();
    *timeNanoseconds = response.time_nanoseconds();
    *timeFractionalNanoseconds = response.time_fractional_nanoseconds();
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_SetTimeReferenceFreeRunning(ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::SetTimeReferenceFreeRunningRequest request;
    nisync::SetTimeReferenceFreeRunningResponse response;
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->SetTimeReferenceFreeRunning(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_SetTimeReferenceGPS(ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::SetTimeReferenceGPSRequest request;
    nisync::SetTimeReferenceGPSResponse response;
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->SetTimeReferenceGPS(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_SetTimeReferenceIRIG(
     ViInt32 irigType,
     ViConstString terminalName,
     ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::SetTimeReferenceIRIGRequest request;
    nisync::SetTimeReferenceIRIGResponse response;
    request.set_irig_type(irigType);
    request.set_terminal_name(terminalName);
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->SetTimeReferenceIRIG(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_SetTimeReferencePPS(
     ViConstString terminalName,
     ViBoolean useManualTime,
     ViUInt32 initialTimeSeconds,
     ViUInt32 initialTimeNanoseconds,
     ViUInt16 initialTimeFractionalNanoseconds,
     ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::SetTimeReferencePPSRequest request;
    nisync::SetTimeReferencePPSResponse response;
    request.set_terminal_name(terminalName);
    request.set_use_manual_time(useManualTime);
    request.set_initial_time_seconds(initialTimeSeconds);
    request.set_initial_time_nanoseconds(initialTimeNanoseconds);
    request.set_initial_time_fractional_nanoseconds(initialTimeFractionalNanoseconds);
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->SetTimeReferencePPS(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_SetTimeReference1588OrdinaryClock(ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::SetTimeReference1588OrdinaryClockRequest request;
    nisync::SetTimeReference1588OrdinaryClockResponse response;
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->SetTimeReference1588OrdinaryClock(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_SetTimeReference8021AS(ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::SetTimeReference8021ASRequest request;
    nisync::SetTimeReference8021ASResponse response;
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->SetTimeReference8021AS(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_CreateFutureTimeEvent(
     ViConstString terminal,
     ViInt32 outputLevel,
     ViUInt32 timeSeconds,
     ViUInt32 timeNanoseconds,
     ViUInt16 timeFractionalNanoseconds,
     ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::CreateFutureTimeEventRequest request;
    nisync::CreateFutureTimeEventResponse response;
    request.set_terminal(terminal);
    request.set_output_level(outputLevel);
    request.set_time_seconds(timeSeconds);
    request.set_time_nanoseconds(timeNanoseconds);
    request.set_time_fractional_nanoseconds(timeFractionalNanoseconds);
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->CreateFutureTimeEvent(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  void CreateFutureTimeEvent(
     ViConstString terminal,
     ViInt32 outputLevel,
     ViUInt32 timeSeconds,
     ViUInt32 timeNanoseconds,
     ViUInt16 timeFractionalNanoseconds)
  {
    ViStatus viStatus;
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
     ViConstString terminal,
     ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::ClearFutureTimeEventsRequest request;
    nisync::ClearFutureTimeEventsResponse response;
    request.set_terminal(terminal);
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->ClearFutureTimeEvents(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_CreateClock(
     ViConstString terminal,
     ViUInt32 highTicks,
     ViUInt32 lowTicks,
     ViUInt32 startTimeSeconds,
     ViUInt32 startTimeNanoseconds,
     ViUInt16 startTimeFractionalNanoseconds,
     ViUInt32 stopTimeSeconds,
     ViUInt32 stopTimeNanoseconds,
     ViUInt16 stopTimeFractionalNanoseconds,
     ViStatus* viStatusOut)
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
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->CreateClock(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_ClearClock(
     ViConstString terminal,
     ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::ClearClockRequest request;
    nisync::ClearClockResponse response;
    request.set_terminal(terminal);
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->ClearClock(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_GetTimeReferenceNames(
     std::string* valueOut,
     ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::GetTimeReferenceNamesRequest request;
    request.mutable_vi()->set_id(driver_session_->id());
    nisync::GetTimeReferenceNamesResponse response;
    auto grpcStatus = GetStub()->GetTimeReferenceNames(&clientContext, request, &response);
    *valueOut = response.time_reference_names();
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_EnableTimeStampTrigger(
     ViConstString terminal,
     ViInt32 activeEdge,
     ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::EnableTimeStampTriggerRequest request;
    nisync::EnableTimeStampTriggerResponse response;
    request.set_terminal(terminal);
    request.set_active_edge(activeEdge);
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->EnableTimeStampTrigger(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  void EnableTimeStampTrigger(
     ViConstString terminal,
     ViInt32 activeEdge)
  {
    ViStatus viStatus;
    auto grpcStatus = call_EnableTimeStampTrigger(terminal, activeEdge, &viStatus);
    ASSERT_TRUE(grpcStatus.ok());
    ASSERT_EQ(VI_SUCCESS, viStatus);
  }

  ::grpc::Status call_ReadTriggerTimeStamp(
     ViConstString terminal,
     ViReal64 timeout,
     ViUInt32* timeSeconds,
     ViUInt32* timeNanoseconds,
     ViUInt16* timeFractionalNanoseconds,
     ViInt32* detectedEdge,
     ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::ReadTriggerTimeStampRequest request;
    nisync::ReadTriggerTimeStampResponse response;
    request.set_terminal(terminal);
    request.set_timeout(timeout);
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->ReadTriggerTimeStamp(&clientContext, request, &response);
    *timeSeconds = response.time_seconds();
    *timeNanoseconds = response.time_nanoseconds();
    *timeFractionalNanoseconds = response.time_fractional_nanoseconds();
    *detectedEdge = response.detected_edge();
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_ReadMultipleTriggerTimeStamp(
     ViConstString terminal,
     ViReal64 timeout,
     ViUInt32 timestampsToRead,
     ViUInt32* timeSecondsBuffer,
     ViUInt32* timeNanosecondsBuffer,
     ViUInt16* timeFractionalNanosecondsBuffer,
     ViInt32* detectedEdgeBuffer,
     ViUInt32* timestampsRead,
     ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::ReadMultipleTriggerTimeStampRequest request;
    nisync::ReadMultipleTriggerTimeStampResponse response;
    request.set_terminal(terminal);
    request.set_timeout(timeout);
    request.set_timestamps_to_read(timestampsToRead);
    request.mutable_vi()->set_id(driver_session_->id());
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
     ViConstString terminal,
     ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::DisableTimeStampTriggerRequest request;
    nisync::DisableTimeStampTriggerResponse response;
    request.set_terminal(terminal);
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->DisableTimeStampTrigger(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ViUInt32 GetCurrentBoardTimeSeconds()
  {
    ViStatus viStatus;
    ViUInt32 timeSeconds = 0, timeNanoseconds;
    ViUInt16 timeFractionalNanoseconds;
    auto grpcStatus = call_GetTime(
      &timeSeconds,
      &timeNanoseconds, // ignored
      &timeFractionalNanoseconds, // ignored
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

class NiSyncDriver6674Test : public NiSyncDriverApiTest
{
public:
  NiSyncDriver6674Test() : NiSyncDriverApiTest() {}
  const char* get_model_name() const override { return "NI PXIe-6674T"; }
};

class NiSyncDriver6683Test : public NiSyncDriverApiTest
{
public:
  NiSyncDriver6683Test() : NiSyncDriverApiTest() {}
  const char* get_model_name() const override { return "NI PXI-6683H"; }
};

TEST_F(NiSyncDriver6674Test, RevisionQuery_ReturnsNonEmptyRevisions)
{
  ViStatus viStatus;
  std::string driverRevision, firmwareRevision;
  auto grpcStatus = call_RevisionQuery(&driverRevision, &firmwareRevision, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_FALSE(driverRevision.empty());
  EXPECT_FALSE(firmwareRevision.empty());
}

TEST_F(NiSyncDriver6674Test, ConnectClkTerminals_ReturnsSuccess)
{
  ViStatus viStatus;
  auto srcTerminal = NISYNC_VAL_OSCILLATOR, destTerminal = NISYNC_VAL_CLKOUT;
  auto grpcStatus = call_ConnectClkTerminals(srcTerminal, destTerminal, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
  call_DisconnectClkTerminals(srcTerminal, destTerminal, &viStatus);
}

TEST_F(NiSyncDriver6674Test, ConnectInvalidClkTerminals_ReturnsInvalidSrcTerminal)
{
  ViStatus viStatus;
  auto srcTerminal = kInvalidTerminal, destTerminal = NISYNC_VAL_CLKOUT;
  auto grpcStatus = call_ConnectClkTerminals(srcTerminal, destTerminal, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(NISYNC_ERROR_SRC_TERMINAL_INVALID, viStatus);
}

TEST_F(NiSyncDriver6674Test, ConnectedClkTerminals_DisconnectClkTerminals_ReturnsSuccess)
{
  ViStatus viStatus;
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
  ViStatus viStatus;
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
  ViStatus viStatus;
  auto srcTerminal = NISYNC_VAL_SWTRIG_GLOBAL, destTerminal = NISYNC_VAL_PXIEDSTARC;
  auto syncClock = NISYNC_VAL_SYNC_CLK_FULLSPEED;
  ViInt32 invert = VI_TRUE, updateEdge = VI_FALSE;
  ViReal64 delay = 0;
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
  ViStatus viStatus;
  auto srcTerminal = kInvalidTerminal, destTerminal = NISYNC_VAL_PXIEDSTARC;
  auto syncClock = NISYNC_VAL_SYNC_CLK_FULLSPEED;
  ViInt32 invert = VI_TRUE, updateEdge = VI_FALSE;
  ViReal64 delay = 0;
  auto grpcStatus = call_ConnectSWTrigToTerminal(
    srcTerminal,
    destTerminal,
    syncClock,
    invert,
    updateEdge,
    delay,
    &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(kSyncInvalidSrcTerminal, viStatus);
}

TEST_F(NiSyncDriver6674Test, ConnectedSWTrigToTerminal_DisconnectSWTrigFromTerminal_ReturnsSuccess)
{
  ViStatus viStatus;
  auto srcTerminal = NISYNC_VAL_SWTRIG_GLOBAL, destTerminal = NISYNC_VAL_PXIEDSTARC;
  auto syncClock = NISYNC_VAL_SYNC_CLK_FULLSPEED;
  ViInt32 invert = VI_TRUE, updateEdge = VI_FALSE;
  ViReal64 delay = 0;
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
  ViStatus viStatus;
  auto srcTerminal = NISYNC_VAL_SWTRIG_GLOBAL, destTerminal = NISYNC_VAL_PXIEDSTARC;
  auto syncClock = NISYNC_VAL_SYNC_CLK_FULLSPEED;
  ViInt32 invert = VI_TRUE, updateEdge = VI_FALSE;
  ViReal64 delay = 0;
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
  ViStatus viStatus;
  auto srcTerminal = NISYNC_VAL_SWTRIG_GLOBAL;
  auto grpcStatus = call_SendSoftwareTrigger(srcTerminal, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
}

TEST_F(NiSyncDriver6674Test, SendSoftwareTriggerOnInvalidTerminal_ReturnsInvalidSrcTerminal)
{
  ViStatus viStatus;
  auto srcTerminal = kInvalidTerminal;
  auto grpcStatus = call_SendSoftwareTrigger(srcTerminal, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  // Bug 1459796: 6674T SendSoftwareTrigger has different error behavior on Linux RT
  #if defined(_MSC_VER)
  EXPECT_EQ(NISYNC_ERROR_SRC_TERMINAL_INVALID, viStatus);
  #else
  EXPECT_EQ(NISYNC_ERROR_TERMINAL_INVALID, viStatus);
  #endif
}

TEST_F(NiSyncDriver6674Test, ConnectTrigTerminals_ReturnsSuccess)
{
  ViStatus viStatus;
  auto srcTerminal = NISYNC_VAL_PFI0, destTerminal = NISYNC_VAL_PFI1;
  auto syncClock = NISYNC_VAL_SYNC_CLK_ASYNC;
  ViInt32 invert = VI_FALSE, updateEdge = VI_FALSE;
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
  ViStatus viStatus;
  auto srcTerminal = kInvalidTerminal, destTerminal = NISYNC_VAL_CLKOUT;
  auto syncClock = NISYNC_VAL_SYNC_CLK_ASYNC;
  ViInt32 invert = VI_FALSE, updateEdge = VI_FALSE;
  auto grpcStatus = call_ConnectTrigTerminals(
    srcTerminal,
    destTerminal,
    syncClock,
    invert,
    updateEdge,
    &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(kSyncInvalidSrcTerminal, viStatus);
}

TEST_F(NiSyncDriver6674Test, ConnectedTrigTerminals_DisconnectTrigTerminals_ReturnsSuccess)
{
  ViStatus viStatus;
  auto srcTerminal = NISYNC_VAL_PFI0, destTerminal = NISYNC_VAL_PFI1;
  auto syncClock = NISYNC_VAL_SYNC_CLK_ASYNC;
  ViInt32 invert = VI_FALSE, updateEdge = VI_FALSE;
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
  ViStatus viStatus;
  auto srcTerminal = NISYNC_VAL_PFI0, destTerminal = NISYNC_VAL_PFI1;
  auto syncClock = NISYNC_VAL_SYNC_CLK_ASYNC;
  ViInt32 invert = VI_FALSE, updateEdge = VI_FALSE;
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
  ViStatus viStatus;
  auto activeItem = "";
  ViAttr attribute = NISYNC_ATTR_SYNC_CLK_DIV1;
  ViInt32 expectedValue = NISYNC_VAL_1588_CLK_ACCURACY_WITHIN_1_USEC;
  auto grpcStatus = call_SetAttributeViInt32(activeItem, attribute, expectedValue, &viStatus);
  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);

  ViInt32 value;
  grpcStatus = call_GetAttributeViInt32(activeItem, attribute, &value, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
  EXPECT_EQ(expectedValue, value);
}

TEST_F(NiSyncDriver6674Test, AttributeSet_GetAttributeViString_ReturnsValue)
{
  ViStatus viStatus;
  auto activeItem = "";
  ViAttr attribute = NISYNC_ATTR_FRONT_SYNC_CLK_SRC;
  ViConstString expectedValue = NISYNC_VAL_CLK10;
  auto grpcStatus = call_SetAttributeViString(activeItem, attribute, expectedValue, &viStatus);
  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);

  std::string value;
  grpcStatus = call_GetAttributeViString(activeItem, attribute, &value, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
  EXPECT_STREQ(expectedValue, value.c_str());
}

TEST_F(NiSyncDriver6674Test, AttributeSet_GetAttributeViBoolean_ReturnsValue)
{
  ViStatus viStatus;
  auto activeItem = "";
  ViAttr attribute = NISYNC_ATTR_CLKIN_ATTENUATION_DISABLE;
  ViBoolean expectedValue = VI_TRUE;
  auto grpcStatus = call_SetAttributeViBoolean(activeItem, attribute, expectedValue, &viStatus);
  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);

  ViBoolean value;
  grpcStatus = call_GetAttributeViBoolean(activeItem, attribute, &value, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
  EXPECT_EQ(expectedValue, value);
}

TEST_F(NiSyncDriver6674Test, AttributeSet_GetAttributeViReal64_ReturnsValue)
{
  ViStatus viStatus;
  auto activeItem = "";
  ViAttr attribute = NISYNC_ATTR_PFI0_THRESHOLD;
  ViReal64 expectedValue = 2.3;
  auto grpcStatus = call_SetAttributeViReal64(activeItem, attribute, expectedValue, &viStatus);
  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);

  ViReal64 value;
  grpcStatus = call_GetAttributeViReal64(activeItem, attribute, &value, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
  EXPECT_DOUBLE_EQ(expectedValue, value);
}

TEST_F(NiSyncDriver6674Test, MeasureFrequencyExOnTerminalWithNoFrequency_ReturnsNoFrequency)
{
  ViStatus viStatus;
  ViConstString srcTerminal = NISYNC_VAL_PFI0;
  ViReal64 duration = 0.1; // duration is in seconds
  ViUInt32 decimationCount = 0; // ignored for 6674
  ViReal64 actualDuration, frequency, frequencyError;
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
  ViStatus viStatus;
  ViConstString srcTerminal = NISYNC_VAL_OSCILLATOR;
  ViReal64 duration = 0.1; // duration is in seconds
  ViUInt32 decimationCount = 0; // ignored for 6674
  ViReal64 actualDuration, frequency, frequencyError;
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

TEST_F(NiSyncDriver6683Test, SetTimeWithValidTimeSource_ReturnsSuccess)
{
  // SetTime isn't implemented on Linux RT, yet.
  #if defined(__GNUC__)
  GTEST_SKIP();	
  #endif

  ViStatus viStatus;
  ViUInt32 timeSeconds = 50, timeNanoseconds = 500;
  auto grpcStatus = call_SetTime(
     NISYNC_VAL_INIT_TIME_SRC_SYSTEM_CLK,
     timeSeconds,
     timeNanoseconds,
     0, // timeFractionalNanoseconds, ignored
     &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
}

TEST_F(NiSyncDriver6683Test, SetTimeWithInvalidTimeSource_ReturnsError)
{
  // SetTime isn't implemented on Linux RT, yet.
  #if defined(__GNUC__)
  GTEST_SKIP();
  #endif

  ViStatus viStatus;
  ViUInt32 timeSeconds = 50, timeNanoseconds = 500;
  auto grpcStatus = call_SetTime(
     NISYNC_VAL_INIT_TIME_SRC_SYSTEM_CLK + 5000,
     timeSeconds,
     timeNanoseconds,
     0, // timeFractionalNanoseconds, ignored
     &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_ERROR_INV_PARAMETER, viStatus);
}

TEST_F(NiSyncDriver6683Test, GetTime_ReturnsTime)
{
  ViStatus viStatus;
  ViUInt32 timeSeconds, timeNanoseconds;
  ViUInt16 timeFractionalNanoseconds;
  auto grpcStatus = call_GetTime(
     &timeSeconds, 
     &timeNanoseconds, 
     &timeFractionalNanoseconds, // ignored
     &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
  EXPECT_GT(timeSeconds, (ViUInt32)0);  
  EXPECT_GT(timeNanoseconds, (ViUInt32)0);
}

TEST_F(NiSyncDriver6683Test, SetTimeReferenceFreeRunning_ReturnsSuccess)
{
  ViStatus viStatus;
  auto grpcStatus = call_SetTimeReferenceFreeRunning(&viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
}

TEST_F(NiSyncDriver6683Test, SetTimeReferenceGPS_ReturnsSuccess)
{
  ViStatus viStatus;
  auto grpcStatus = call_SetTimeReferenceGPS(&viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
}

TEST_F(NiSyncDriver6683Test, SetTimeReferenceIRIG_ReturnsSuccess)
{
  ViStatus viStatus;
  auto grpcStatus = call_SetTimeReferenceIRIG(
     NISYNC_VAL_IRIG_TYPE_IRIGB_DC, // irigType
     NISYNC_VAL_PFI0, // terminalName
     &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
}

TEST_F(NiSyncDriver6683Test, SetTimeReferenceIRIGWithInvalidTerminal_ReturnsError)
{
  ViStatus viStatus;
  auto grpcStatus = call_SetTimeReferenceIRIG(
     NISYNC_VAL_IRIG_TYPE_IRIGB_DC, // irigType
     NISYNC_VAL_GND, // terminalName
     &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(NISYNC_ERROR_TERMINAL_INVALID, viStatus);
}

TEST_F(NiSyncDriver6683Test, SetTimeReferencePPS_ReturnsSuccess)
{
  ViStatus viStatus;
  ViUInt32 initialTimeSeconds = 30, initialTimeNanoseconds = 500;
  auto grpcStatus = call_SetTimeReferencePPS(
     NISYNC_VAL_PFI1, // terminalName
     VI_TRUE, // useManualTime
     initialTimeSeconds,
     initialTimeNanoseconds,
     0, // initialTimeFractionalNanoseconds, ignored
     &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
}

TEST_F(NiSyncDriver6683Test, SetTimeReferencePPSWithInvalidTerminal_ReturnsError)
{
  ViStatus viStatus;
  ViUInt32 initialTimeSeconds = 30, initialTimeNanoseconds = 500;
  auto grpcStatus = call_SetTimeReferencePPS(
     NISYNC_VAL_GND, // terminalName
     VI_TRUE, // useManualTime
     initialTimeSeconds,
     initialTimeNanoseconds,
     0, // initialTimeFractionalNanoseconds, ignored
     &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(NISYNC_ERROR_TERMINAL_INVALID, viStatus);
}

TEST_F(NiSyncDriver6683Test, SetTimeReference1588OrdinaryClock_ReturnsSuccess)
{
  ViStatus viStatus;
  auto grpcStatus = call_SetTimeReference1588OrdinaryClock(&viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
}

TEST_F(NiSyncDriver6683Test, SetTimeReference8021AS_ReturnsSuccess)
{
  // SetTimeReference8021AS is only supported in LinuxRT targets.
  ViStatus viStatus;
  auto grpcStatus = call_SetTimeReference8021AS(&viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
}

TEST_F(NiSyncDriver6683Test, CreateClearFutureTimeEvent_ReturnsSuccess)
{
  ViStatus viStatusCreate;
  ViUInt32 timeSeconds = GetCurrentBoardTimeSeconds() + 30;
  auto grpcStatusCreate = call_CreateFutureTimeEvent(
     NISYNC_VAL_PFI1, // terminalName
     NISYNC_VAL_LEVEL_LOW, // outputLevel
     timeSeconds,
     0, // timeNanoseconds, ignored
     0, // timeFractionalNanoseconds, ignored
     &viStatusCreate);
  EXPECT_TRUE(grpcStatusCreate.ok());
  EXPECT_EQ(VI_SUCCESS, viStatusCreate);

  ViStatus viStatusClear;
  auto grpcStatusClear = call_ClearFutureTimeEvents(
     NISYNC_VAL_PFI1,
     &viStatusClear);
  EXPECT_TRUE(grpcStatusClear.ok());
  EXPECT_EQ(VI_SUCCESS, viStatusClear);
}

TEST_F(NiSyncDriver6683Test, CreateFutureTimeEventWithInvalidTerminal_ReturnsError)
{
  ViStatus viStatus;
  ViUInt32 timeSeconds = GetCurrentBoardTimeSeconds() + 30;
  auto grpcStatus = call_CreateFutureTimeEvent(
     NISYNC_VAL_GND, // terminalName
     NISYNC_VAL_LEVEL_LOW, // outputLevel
     timeSeconds,
     0, // timeNanoseconds, ignored
     0, // timeFractionalNanoseconds, ignored
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
  ViStatus viStatus;
  auto grpcStatus = call_ClearFutureTimeEvents(
     NISYNC_VAL_PFI1, // terminalName
     &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(NISYNC_ERROR_RSRC_NOT_RESERVED, viStatus);
}

TEST_F(NiSyncDriver6683Test, CreateClearClock_ReturnsSuccess)
{
  ViStatus viStatusCreate;
  ViUInt32 highTicks = 50, lowTicks = 50;
  ViUInt32 startTimeSeconds = GetCurrentBoardTimeSeconds() + 30;
  ViUInt32 stopTimeSeconds = startTimeSeconds + 30;
  auto grpcStatusCreate = call_CreateClock(
     NISYNC_VAL_PFI1, // terminalName
     highTicks,
     lowTicks,
     startTimeSeconds,
     0, // startTimeNanoseconds, ignored
     0, // startTimeFractionalNanoseconds, ignored
     stopTimeSeconds,
     0, // stopTimeNanoseconds, ignored
     0, // stopTimeFractionalNanoseconds, ignored
     &viStatusCreate);
  EXPECT_TRUE(grpcStatusCreate.ok());
  EXPECT_EQ(VI_SUCCESS, viStatusCreate);

  ViStatus viStatusClear;
  auto grpcStatusClear = call_ClearClock(
     NISYNC_VAL_PFI1,
     &viStatusClear);
  EXPECT_TRUE(grpcStatusClear.ok());
  EXPECT_EQ(VI_SUCCESS, viStatusClear);

}

TEST_F(NiSyncDriver6683Test, CreateClockWithInvalidTerminal_ReturnsError)
{
  ViStatus viStatus;
  ViUInt32 highTicks = 50, lowTicks = 50;
  ViUInt32 startTimeSeconds = GetCurrentBoardTimeSeconds() + 30;
  ViUInt32 stopTimeSeconds = startTimeSeconds + 30;
  auto grpcStatus = call_CreateClock(
     NISYNC_VAL_GND, // terminalName
     highTicks,
     lowTicks,
     startTimeSeconds,
     0, // startTimeNanoseconds, ignored
     0, // startTimeFractionalNanoseconds, ignored
     stopTimeSeconds,
     0, // stopTimeNanoseconds, ignored
     0, // stopTimeFractionalNanoseconds, ignored
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
  ViStatus viStatus;
  auto grpcStatus = call_ClearClock(
     NISYNC_VAL_PFI1, // terminalName
     &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(NISYNC_ERROR_RSRC_NOT_RESERVED, viStatus);
}

TEST_F(NiSyncDriver6683Test, GetTimeReferenceNames_ReturnsSuccess)
{
  ViStatus viStatus;
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
  ViStatus viStatusEnable;
  auto grpcStatusEnable = call_EnableTimeStampTrigger(
     NISYNC_VAL_PFI1, // terminalName
     NISYNC_VAL_EDGE_RISING, // activeEdge
     &viStatusEnable);
  EXPECT_TRUE(grpcStatusEnable.ok());
  EXPECT_EQ(VI_SUCCESS, viStatusEnable);

  ViStatus viStatusDisable;
  auto grpcStatusDisable = call_DisableTimeStampTrigger(
     NISYNC_VAL_PFI1,
     &viStatusDisable);
  EXPECT_TRUE(grpcStatusDisable.ok());
  EXPECT_EQ(VI_SUCCESS, viStatusDisable);
}

TEST_F(NiSyncDriver6683Test, EnableTimeStampTriggerWithInvalidTerminal_ReturnsError)
{
  ViStatus viStatus;
  auto grpcStatus = call_EnableTimeStampTrigger(
     NISYNC_VAL_GND, // terminalName
     NISYNC_VAL_EDGE_RISING, // activeEdge
     &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(NISYNC_ERROR_TERMINAL_INVALID, viStatus);
}

TEST_F(NiSyncDriver6683Test, DisableTimeStampTriggerNotReserved_ReturnsError)
{
  ViStatus viStatus;
  auto grpcStatus = call_DisableTimeStampTrigger(
     NISYNC_VAL_PFI1, // terminalName
     &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(NISYNC_ERROR_RSRC_NOT_RESERVED, viStatus);
}

TEST_F(NiSyncDriver6683Test, GivenNoTrigger_ReadTriggerTimeStamp_ReturnsTimeoutError)
{
  auto terminal = NISYNC_VAL_PFI1;
  EnableTimeStampTrigger(terminal, NISYNC_VAL_EDGE_RISING);

  ViStatus viStatusRead;
  ViReal64 timeout = 0.1;
  ViUInt32 timeSeconds, timeNanoseconds;
  ViUInt16 timeFractionalNanoseconds;
  ViInt32 detectedEdge;
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

  ViStatus viStatusRead;
  ViReal64 timeout = 0.1;
  ViUInt32 timestampsToRead = 1;
  ViUInt32 timeSeconds, timeNanoseconds;
  ViUInt16 timeFractionalNanoseconds;
  ViInt32 detectedEdge;
  ViUInt32 timestampsRead;
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

  ViStatus viStatusRead;
  ViReal64 timeout = 0.0;
  const ViUInt32 timestampsToRead = 5;
  ViUInt32 timeSeconds[timestampsToRead] = {}, timeNanoseconds[timestampsToRead] = {};
  ViUInt16 timeFractionalNanoseconds[timestampsToRead] = {};
  ViInt32 detectedEdge[timestampsToRead] = {};
  ViUInt32 timestampsRead = 0;
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

  const ViUInt32 expectedTimestampsRead = 1;
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
  ViInt32 level = NISYNC_VAL_LEVEL_HIGH;
  for (int i = 0; i < 10; ++i) {
    SCOPED_TRACE(::testing::Message("i=") << i);
    CreateFutureTimeEvent(terminal, level, 0, 0, 0);
    level = (level == NISYNC_VAL_LEVEL_LOW) ? NISYNC_VAL_LEVEL_HIGH : NISYNC_VAL_LEVEL_LOW;
  }

  ViStatus viStatusRead;
  ViReal64 timeout = 0.0;
  const ViUInt32 timestampsToRead = 5;
  ViUInt32 timeSeconds[timestampsToRead] = {}, timeNanoseconds[timestampsToRead] = {};
  ViUInt16 timeFractionalNanoseconds[timestampsToRead] = {};
  ViInt32 detectedEdge[timestampsToRead] = {};
  ViUInt32 timestampsRead = 0;
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
  for (ViUInt32 i = 0; i < timestampsRead; ++i) {
    SCOPED_TRACE(::testing::Message("i=") << i);
    EXPECT_NE(0, timeSeconds[i]);
    EXPECT_EQ(NISYNC_VAL_EDGE_RISING, detectedEdge[i]);
  }
}

}  // namespace system
}  // namespace tests
}  // namespace ni
