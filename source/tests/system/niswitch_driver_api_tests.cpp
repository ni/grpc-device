#include <gtest/gtest.h>

#include "device_server.h"
#include "niswitch/niswitch_service.h"

namespace ni {
namespace tests {
namespace system {

namespace niswitch = niswitch_grpc;

const int kSwitchDriverApiSuccess = 0;
const int kWaitForDebounceMaxTime = 5000;
const char* kRelayName = "b0r0c0";
const char* firstChannelName = "b0r1";
const char* secondChannelName = "b0c1";
const char* thirdChannelName = "b0r2";
const char* fourthChannelName = "b0c6";

class NiSwitchDriverApiTest : public ::testing::Test {
 protected:
  NiSwitchDriverApiTest()
      : device_server_(DeviceServerInterface::Singleton()),
        niswitch_stub_(niswitch::NiSwitch::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~NiSwitchDriverApiTest() {}

  void SetUp() override
  {
    initialize_driver_session();
  }

  void TearDown() override
  {
    close_driver_session();
  }

  std::unique_ptr<niswitch::NiSwitch::Stub>& GetStub()
  {
    return niswitch_stub_;
  }

  int GetSessionId()
  {
    return driver_session_->id();
  }

  void expect_api_success(int error_status)
  {
    EXPECT_EQ(kSwitchDriverApiSuccess, error_status) << get_error_message(error_status);
  }

  std::string get_error_message(int error_status)
  {
    ::grpc::ClientContext context;
    niswitch::ErrorMessageRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_error_code(error_status);
    niswitch::ErrorMessageResponse response;

    ::grpc::Status status = GetStub()->ErrorMessage(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kSwitchDriverApiSuccess, response.status());
    return response.error_message();
  }

  void initialize_driver_session()
  {
    ::grpc::ClientContext context;
    niswitch::InitWithTopologyRequest request;
    request.set_resource_name("");
    request.set_topology("2529/2-Wire Dual 4x16 Matrix");
    request.set_session_name("");
    request.set_reset_device(false);
    request.set_simulate(true);
    niswitch::InitWithTopologyResponse response;

    ::grpc::Status status = GetStub()->InitWithTopology(&context, request, &response);
    driver_session_ = std::make_unique<nidevice_grpc::Session>(response.vi());

    ASSERT_TRUE(status.ok());
    ASSERT_EQ(kSwitchDriverApiSuccess, response.status());
  }

  void close_driver_session()
  {
    ::grpc::ClientContext context;
    niswitch::CloseRequest request;
    request.mutable_vi()->set_id(driver_session_->id());
    niswitch::CloseResponse response;

    ::grpc::Status status = GetStub()->Close(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
  }

  void wait_for_debounce()
  {
    ::grpc::ClientContext context;
    niswitch::WaitForDebounceRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_maximum_time_ms(kWaitForDebounceMaxTime);
    niswitch::WaitForDebounceResponse response;

    ::grpc::Status status = GetStub()->WaitForDebounce(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
  }

  int can_connect(const char* channel1, const char* channel2)
  {
    ::grpc::ClientContext context;
    niswitch::CanConnectRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel1(channel1);
    request.set_channel2(channel2);
    niswitch::CanConnectResponse response;

    ::grpc::Status status = GetStub()->CanConnect(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
    return response.path_capability();
  }

  void connect(const char* channel1, const char* channel2)
  {
    ::grpc::ClientContext context;
    niswitch::ConnectRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel1(channel1);
    request.set_channel2(channel2);
    niswitch::ConnectResponse response;

    ::grpc::Status status = GetStub()->Connect(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
  }

  void disconnect_all()
  {
    ::grpc::ClientContext context;
    niswitch::DisconnectAllRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    niswitch::DisconnectAllResponse response;

    ::grpc::Status status = GetStub()->DisconnectAll(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
  }

  int get_relay_position(const char* relay_name)
  {
    ::grpc::ClientContext context;
    niswitch::GetRelayPositionRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_relay_name(relay_name);
    niswitch::GetRelayPositionResponse response;

    ::grpc::Status status = GetStub()->GetRelayPosition(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
    return response.relay_position();
  }

  ViReal64 get_real64_attribute(const char* channel_name, niswitch::NiSwitchAttributes attribute_id)
  {
    ::grpc::ClientContext context;
    niswitch::GetAttributeViReal64Request request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_name);
    request.set_attribute_id(attribute_id);
    niswitch::GetAttributeViReal64Response response;

    ::grpc::Status status = GetStub()->GetAttributeViReal64(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
    return response.attribute_value();
  }

  std::string get_string_attribute(const char* channel_name, niswitch::NiSwitchAttributes attribute_id)
  {
    ::grpc::ClientContext context;
    niswitch::GetAttributeViStringRequest request;
    request.mutable_vi()->set_id(GetSessionId());
    request.set_channel_name(channel_name);
    request.set_attribute_id(attribute_id);
    niswitch::GetAttributeViStringResponse response;

    ::grpc::Status status = GetStub()->GetAttributeViString(&context, request, &response);

    EXPECT_TRUE(status.ok());
    expect_api_success(response.status());
    return response.attribute_value();
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<::nidevice_grpc::Session> driver_session_;
  std::unique_ptr<niswitch::NiSwitch::Stub> niswitch_stub_;
};

TEST_F(NiSwitchDriverApiTest, NiSwitchSelfTest_SendRequest_SelfTestCompletesSuccessfully)
{
  ::grpc::ClientContext context;
  niswitch::SelfTestRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  niswitch::SelfTestResponse response;

  ::grpc::Status status = GetStub()->SelfTest(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
  EXPECT_EQ(0, response.self_test_result());
  EXPECT_LT(0, strlen(response.self_test_message().c_str()));
}

TEST_F(NiSwitchDriverApiTest, NiSwitchReset_SendRequest_ResetCompletesSuccessfully)
{
  ::grpc::ClientContext context;
  niswitch::ResetRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  niswitch::ResetResponse response;

  ::grpc::Status status = GetStub()->Reset(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
}

TEST_F(NiSwitchDriverApiTest, NiSwitchSetViReal64Attribute_SendRequest_GetViReal64AttributeMatches)
{
  const char* channel_name = "";
  const niswitch::NiSwitchAttributes attribute_to_set = niswitch::NiSwitchAttributes::NISWITCH_ATTRIBUTE_SCAN_DELAY;
  const ViReal64 expected_value = 402.24;
  ::grpc::ClientContext context;
  niswitch::SetAttributeViReal64Request request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_name(channel_name);
  request.set_attribute_id(attribute_to_set);
  request.set_attribute_value_raw(expected_value);
  niswitch::SetAttributeViReal64Response response;

  ::grpc::Status status = GetStub()->SetAttributeViReal64(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
  ViReal64 get_attribute_value = get_real64_attribute(channel_name, attribute_to_set);
  EXPECT_EQ(expected_value, get_attribute_value);
}

TEST_F(NiSwitchDriverApiTest, NiSwitchSetViStringAttribute_SendRequest_GetViStringAttributeMatches)
{
  const char* channel_name = "";
  const niswitch::NiSwitchAttributes attribute_to_set = niswitch::NiSwitchAttributes::NISWITCH_ATTRIBUTE_SCAN_LIST;
  const ViString expected_value = "b0r1->b0c1;b0r1->b0c2;b0r2->b0c3";
  ::grpc::ClientContext context;
  niswitch::SetAttributeViStringRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_channel_name(channel_name);
  request.set_attribute_id(attribute_to_set);
  request.set_attribute_value_raw(expected_value);
  niswitch::SetAttributeViStringResponse response;

  ::grpc::Status status = GetStub()->SetAttributeViString(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
  std::string get_attribute_value = get_string_attribute(channel_name, attribute_to_set);
  EXPECT_STREQ(expected_value, get_attribute_value.c_str());
}

TEST_F(NiSwitchDriverApiTest, NiSwitchRelayControl_SendRequest_RelayPositionMatches)
{
  const niswitch::RelayAction relay_action = niswitch::RelayAction::RELAY_ACTION_NISWITCH_VAL_CLOSE_RELAY;
  const niswitch::RelayPosition expected_value = niswitch::RelayPosition::RELAY_POSITION_NISWITCH_VAL_CLOSED;
  ::grpc::ClientContext context;
  niswitch::RelayControlRequest request;
  request.mutable_vi()->set_id(GetSessionId());
  request.set_relay_name(kRelayName);
  request.set_relay_action(relay_action);
  niswitch::RelayControlResponse response;

  ::grpc::Status status = GetStub()->RelayControl(&context, request, &response);

  EXPECT_TRUE(status.ok());
  expect_api_success(response.status());
  wait_for_debounce();
  int get_relay_pos = get_relay_position(kRelayName);
  EXPECT_EQ(expected_value, get_relay_pos);
}

TEST_F(NiSwitchDriverApiTest, NiSwitchChannelsAreUnconnected_CanConnectIsCalled_PathAvailableIsReturned)
{
  const niswitch::PathCapability expected_value = niswitch::PathCapability::PATH_CAPABILITY_NISWITCH_VAL_PATH_AVAILABLE;

  int get_path_capability = can_connect(firstChannelName, secondChannelName);

  EXPECT_EQ(expected_value, get_path_capability);
}

TEST_F(NiSwitchDriverApiTest, NiSwitchChannelsAreAlreadyConnected_CanConnectIsCalled_PathExistsIsReturned)
{
  const niswitch::PathCapability expected_value = niswitch::PathCapability::PATH_CAPABILITY_NISWITCH_VAL_PATH_EXISTS;
  connect(thirdChannelName, fourthChannelName);
  wait_for_debounce();

  int get_path_capability = can_connect(thirdChannelName, fourthChannelName);

  EXPECT_EQ(expected_value, get_path_capability);
  disconnect_all();
}

}  // namespace system
}  // namespace tests
}  // namespace ni