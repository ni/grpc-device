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

  ::grpc::Status call_SetAttributeViInt32(ViConstString terminalName, ViAttr attribute, ViInt32 value, ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::SetAttributeViInt32Request request;
    nisync::SetAttributeViInt32Response response;
    request.set_terminal_name(terminalName);
    request.set_attribute(static_cast<nisync::NiSyncAttributes>(attribute));
    request.set_value(value);
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->SetAttributeViInt32(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_GetAttributeViInt32(ViConstString terminalName, ViAttr attribute, ViInt32* valueOut, ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::GetAttributeViInt32Request request;
    nisync::GetAttributeViInt32Response response;
    request.set_terminal_name(terminalName);
    request.set_attribute(static_cast<nisync::NiSyncAttributes>(attribute));
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->GetAttributeViInt32(&clientContext, request, &response);
    *valueOut = response.value();
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_SetAttributeViString(ViConstString terminalName, ViAttr attribute, ViConstString value, ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::SetAttributeViStringRequest request;
    nisync::SetAttributeViStringResponse response;
    request.set_terminal_name(terminalName);
    request.set_attribute(static_cast<nisync::NiSyncAttributes>(attribute));
    request.set_value(value);
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->SetAttributeViString(&clientContext, request, &response);
    *viStatusOut = response.status();
    return grpcStatus;
  }

  ::grpc::Status call_GetAttributeViString(ViConstString terminalName, ViAttr attribute, std::string* valueOut, ViStatus* viStatusOut)
  {
    ::grpc::ClientContext clientContext;
    nisync::GetAttributeViStringRequest request;
    nisync::GetAttributeViStringResponse response;
    request.set_terminal_name(terminalName);
    request.set_attribute(static_cast<nisync::NiSyncAttributes>(attribute));
    request.mutable_vi()->set_id(driver_session_->id());
    auto grpcStatus = GetStub()->GetAttributeViString(&clientContext, request, &response);
    *valueOut = response.value();
    *viStatusOut = response.status();
    return grpcStatus;
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
  auto terminalName = "";
  ViAttr attribute = NISYNC_ATTR_SYNC_CLK_DIV1;
  ViInt32 expectedValue = NISYNC_VAL_1588_CLK_ACCURACY_WITHIN_1_USEC;
  auto grpcStatus = call_SetAttributeViInt32(terminalName, attribute, expectedValue, &viStatus);
  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);

  ViInt32 value;
  grpcStatus = call_GetAttributeViInt32(terminalName, attribute, &value, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
  EXPECT_EQ(expectedValue, value);
}

TEST_F(NiSyncDriverApiTest, AttributeSet_GetAttributeViString_ReturnsValue)
{
  ViStatus viStatus;
  auto terminalName = "";
  ViAttr attribute = NISYNC_ATTR_FRONT_SYNC_CLK_SRC;
  ViConstString expectedValue = NISYNC_VAL_CLK10;
  auto grpcStatus = call_SetAttributeViString(terminalName, attribute, expectedValue, &viStatus);
  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);

  std::string value;
  grpcStatus = call_GetAttributeViString(terminalName, attribute, &value, &viStatus);

  EXPECT_TRUE(grpcStatus.ok());
  EXPECT_EQ(VI_SUCCESS, viStatus);
  EXPECT_STREQ(expectedValue, value.c_str());
}

}  // namespace system
}  // namespace tests
}  // namespace ni
