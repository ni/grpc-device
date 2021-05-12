#include <gtest/gtest.h>

#include "nisync/nisync_library.h"
#include "nisync/nisync_service.h"

namespace ni {
namespace tests {
namespace system {

namespace nisync = nisync_grpc;

static const ViStatus kSyncInvalidSrcTerminal = 0xBFFA4032;
// Update the value of 'kTestRsrcName' to the name of your NI-Sync device.
static const char* kTestRsrcName = "Dev1";
static const char* kTestSessionName = "TestSession";
static const char* kEmptySessionName = "";
static const char* kInvalidRsrcName = "InvalidName";
static const char* kInvalidTerminal = "Invalid";

class NiSyncDriverApiTest : public ::testing::Test {
 protected:
  NiSyncDriverApiTest()
  {
    ::grpc::ServerBuilder builder;
    session_repository_ = std::make_unique<nidevice_grpc::SessionRepository>();
    nisync_library_ = std::make_unique<nisync::NiSyncLibrary>();
    nisync_service_ = std::make_unique<nisync::NiSyncService>(nisync_library_.get(), session_repository_.get());
    builder.RegisterService(nisync_service_.get());

    server_ = builder.BuildAndStart();
    ResetStubs();
  }

  virtual ~NiSyncDriverApiTest() {}

  void SetUp() override
  {
    initialize_driver_session();
  }

  void TearDown() override
  {
    close_driver_session();
  }

  void ResetStubs()
  {
    channel_ = server_->InProcessChannel(::grpc::ChannelArguments());
    nisync_stub_ = nisync::NiSync::NewStub(channel_);
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
    request.set_resource_name(kTestRsrcName);
    request.set_session_name(kTestSessionName);
    request.set_reset_device(false);

    ::grpc::Status status = GetStub()->Init(&context, request, &response);
    driver_session_ = std::make_unique<nidevice_grpc::Session>(response.vi());

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(VI_SUCCESS, response.status());
  }

  void close_driver_session()
  {
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
    request.set_value(value);
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
    request.set_value(value);
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
    request.set_value(value);
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
     ViConstString terminalName,
     ViInt32 outputLevel,
     ViUInt32 timeSeconds,
     ViUInt32 timeNanoseconds,
     ViUInt16 timeFractionalNanoseconds,
     ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::CreateFutureTimeEventRequest request;
    nisync::CreateFutureTimeEventResponse response;
    request.set_terminal_name(terminalName);
    request.set_output_level(outputLevel);
    request.set_time_seconds(timeSeconds);
    request.set_time_nanoseconds(timeNanoseconds);
    request.set_time_fractional_nanoseconds(timeFractionalNanoseconds);
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->CreateFutureTimeEvent(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }
 
  ::grpc::Status call_ClearFutureTimeEvents(
     ViConstString terminalName,
     ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::ClearFutureTimeEventsRequest request;
    nisync::ClearFutureTimeEventsResponse response;
    request.set_terminal_name(terminalName);
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->ClearFutureTimeEvents(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_CreateClock(
     ViConstString terminalName,
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
    request.set_terminal_name(terminalName);
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
     ViConstString terminalName,
     ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::ClearClockRequest request;
    nisync::ClearClockResponse response;
    request.set_terminal_name(terminalName);
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->ClearClock(&clientContext, request, &response);
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
    return timeSeconds;
  }

private:
  std::shared_ptr<::grpc::Channel> channel_;
  std::unique_ptr<::nidevice_grpc::Session> driver_session_;
  std::unique_ptr<nisync::NiSync::Stub> nisync_stub_;
  std::unique_ptr<nidevice_grpc::SessionRepository> session_repository_;
  std::unique_ptr<nisync::NiSyncLibrary> nisync_library_;
  std::unique_ptr<nisync::NiSyncService> nisync_service_;
  std::unique_ptr<::grpc::Server> server_;
};

TEST_F(NiSyncDriverApiTest, RevisionQuery_ReturnsNonEmptyRevisions)
{
  ViStatus viStatus;
  std::string driverRevision, firmwareRevision;
  auto grpcStatus = call_RevisionQuery(&driverRevision, &firmwareRevision, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_FALSE(driverRevision.empty());
  EXPECT_FALSE(firmwareRevision.empty());
}

TEST_F(NiSyncDriverApiTest, ConnectClkTerminals_ReturnsSuccess)
{
  ViStatus viStatus;
  auto srcTerminal = NISYNC_VAL_OSCILLATOR, destTerminal = NISYNC_VAL_CLKOUT;
  auto grpcStatus = call_ConnectClkTerminals(srcTerminal, destTerminal, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
  call_DisconnectClkTerminals(srcTerminal, destTerminal, &viStatus);
}

TEST_F(NiSyncDriverApiTest, ConnectInvalidClkTerminals_ReturnsInvalidSrcTerminal)
{
  ViStatus viStatus;
  auto srcTerminal = kInvalidTerminal, destTerminal = NISYNC_VAL_CLKOUT;
  auto grpcStatus = call_ConnectClkTerminals(srcTerminal, destTerminal, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(kSyncInvalidSrcTerminal, viStatus);
}

TEST_F(NiSyncDriverApiTest, ConnectedClkTerminals_DisconnectClkTerminals_ReturnsSuccess)
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

TEST_F(NiSyncDriverApiTest, ConnectedClkTerminals_DisconnectNotConnectedClkTerminals_ReturnsSuccess)
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

TEST_F(NiSyncDriverApiTest, ConnectSWTrigToTerminal_ReturnsSuccess)
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

TEST_F(NiSyncDriverApiTest, ConnectInvalidSWTrigToTerminal_ReturnsInvalidSrcTerminal)
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

TEST_F(NiSyncDriverApiTest, ConnectedSWTrigToTerminal_DisconnectSWTrigFromTerminal_ReturnsSuccess)
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

TEST_F(NiSyncDriverApiTest, SWTrigConnectedToTerminal_DisconnectSWTrigFromNotConnectedTerminal_ReturnsSuccess)
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

TEST_F(NiSyncDriverApiTest, SendSoftwareTrigger_ReturnsSuccess)
{
  ViStatus viStatus;
  auto srcTerminal = NISYNC_VAL_SWTRIG_GLOBAL;
  auto grpcStatus = call_SendSoftwareTrigger(srcTerminal, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
}

TEST_F(NiSyncDriverApiTest, SendSoftwareTriggerOnInvalidTerminal_ReturnsInvalidSrcTerminal)
{
  ViStatus viStatus;
  auto srcTerminal = kInvalidTerminal;
  auto grpcStatus = call_SendSoftwareTrigger(srcTerminal, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(kSyncInvalidSrcTerminal, viStatus);
}

TEST_F(NiSyncDriverApiTest, ConnectTrigTerminals_ReturnsSuccess)
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

TEST_F(NiSyncDriverApiTest, ConnectInvalidTrigTerminals_ReturnsInvalidSrcTerminal)
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

TEST_F(NiSyncDriverApiTest, ConnectedTrigTerminals_DisconnectTrigTerminals_ReturnsSuccess)
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

TEST_F(NiSyncDriverApiTest, NotConnectedTrigTerminals_DisconnectSWTrigFromTerminal_ReturnsSuccess)
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

TEST_F(NiSyncDriverApiTest, AttributeSet_GetAttributeViInt32_ReturnsValue)
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

TEST_F(NiSyncDriverApiTest, AttributeSet_GetAttributeViString_ReturnsValue)
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

TEST_F(NiSyncDriverApiTest, AttributeSet_GetAttributeViBoolean_ReturnsValue)
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

TEST_F(NiSyncDriverApiTest, AttributeSet_GetAttributeViReal64_ReturnsValue)
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

TEST_F(NiSyncDriverApiTest, MeasureFrequencyExOnTerminalWithNoFrequency_ReturnsNoFrequency)
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

TEST_F(NiSyncDriverApiTest, MeasureFrequencyExOnOscillatorWithFrequency_ReturnsFrequency)
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

TEST_F(NiSyncDriverApiTest, DISABLED_SetTimeWithValidTimeSource_ReturnsSuccess)
{
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

TEST_F(NiSyncDriverApiTest, DISABLED_SetTimeWithInvalidTimeSource_ReturnsError)
{
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

TEST_F(NiSyncDriverApiTest, DISABLED_GetTime_ReturnsTime)
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

TEST_F(NiSyncDriverApiTest, DISABLED_SetTimeReferenceFreeRunning_ReturnsSuccess)
{
  ViStatus viStatus;
  auto grpcStatus = call_SetTimeReferenceFreeRunning(&viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
}

TEST_F(NiSyncDriverApiTest, DISABLED_SetTimeReferenceGPS_ReturnsSuccess)
{
  ViStatus viStatus;
  auto grpcStatus = call_SetTimeReferenceGPS(&viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
}

TEST_F(NiSyncDriverApiTest, DISABLED_SetTimeReferenceIRIG_ReturnsSuccess)
{
  ViStatus viStatus;
  auto grpcStatus = call_SetTimeReferenceIRIG(
     NISYNC_VAL_IRIG_TYPE_IRIGB_DC, // irigType
     NISYNC_VAL_PFI0, // terminalName
     &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
}

TEST_F(NiSyncDriverApiTest, DISABLED_SetTimeReferenceIRIGWithInvalidTerminal_ReturnsError)
{
  ViStatus viStatus;
  auto grpcStatus = call_SetTimeReferenceIRIG(
     NISYNC_VAL_IRIG_TYPE_IRIGB_DC, // irigType
     NISYNC_VAL_GND, // terminalName
     &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(NISYNC_ERROR_TERMINAL_INVALID, viStatus);
}

TEST_F(NiSyncDriverApiTest, DISABLED_SetTimeReferencePPS_ReturnsSuccess)
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

TEST_F(NiSyncDriverApiTest, DISABLED_SetTimeReferencePPSWithInvalidTerminal_ReturnsError)
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

TEST_F(NiSyncDriverApiTest, DISABLED_SetTimeReference1588OrdinaryClock_ReturnsSuccess)
{
  ViStatus viStatus;
  auto grpcStatus = call_SetTimeReference1588OrdinaryClock(&viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
}

TEST_F(NiSyncDriverApiTest, DISABLED_SetTimeReference8021AS_ReturnsSuccess)
{
  // SetTimeReference8021AS is only supported in LinuxRT targets.
  ViStatus viStatus;
  auto grpcStatus = call_SetTimeReference8021AS(&viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
}

TEST_F(NiSyncDriverApiTest, DISABLED_CreateClearFutureTimeEvent_ReturnsSuccess)
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

TEST_F(NiSyncDriverApiTest, DISABLED_CreateFutureTimeEventWithInvalidTerminal_ReturnsError)
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
  EXPECT_EQ(NISYNC_ERROR_DEST_TERMINAL_INVALID, viStatus);
}

TEST_F(NiSyncDriverApiTest, DISABLED_ClearFutureTimeEventsNotReserved_ReturnsError)
{
  ViStatus viStatus;
  auto grpcStatus = call_ClearFutureTimeEvents(
     NISYNC_VAL_PFI1, // terminalName
     &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(NISYNC_ERROR_RSRC_NOT_RESERVED, viStatus);
}

TEST_F(NiSyncDriverApiTest, DISABLED_CreateClearClock_ReturnsSuccess)
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

TEST_F(NiSyncDriverApiTest, DISABLED_CreateClockWithInvalidTerminal_ReturnsError)
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
  EXPECT_EQ(NISYNC_ERROR_DEST_TERMINAL_INVALID, viStatus);
}

TEST_F(NiSyncDriverApiTest, DISABLED_ClearClockNotReserved_ReturnsError)
{
  ViStatus viStatus;
  auto grpcStatus = call_ClearClock(
     NISYNC_VAL_PFI1, // terminalName
     &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(NISYNC_ERROR_RSRC_NOT_RESERVED, viStatus);
}

}  // namespace system
}  // namespace tests
}  // namespace ni
