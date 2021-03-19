#include <gtest/gtest.h>

#include "niswitch/niswitch_library.h"
#include "niswitch/niswitch_service.h"

namespace ni {
namespace tests {
namespace system {

namespace niswitch = grpc::niswitch;

const int kSwitchDriverApiSuccess = 0;
const int kWaitForDebounceMaxTime = 5000;
const char* kRelayName = "b0r0c0";

class NiSwitchDriverApiTest : public ::testing::Test {
 protected:
  NiSwitchDriverApiTest()
  {
    ::grpc::ServerBuilder builder;
    session_repository_ = std::make_unique<grpc::nidevice::SessionRepository>();
    niswitch_library_ = std::make_unique<niswitch::NiSwitchLibrary>();
    niswitch_service_ = std::make_unique<niswitch::NiSwitchService>(niswitch_library_.get(), session_repository_.get());
    builder.RegisterService(niswitch_service_.get());

    server_ = builder.BuildAndStart();
    ResetStub();
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

  void ResetStub()
  {
    channel_ = server_->InProcessChannel(::grpc::ChannelArguments());
    niswitch_stub_ = niswitch::NiSwitch::NewStub(channel_);
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
    request.set_resource_name("Switch1");
    request.set_topology("2529/2-Wire Dual 4x16 Matrix");
    request.set_session_name("");
    request.set_reset_device(false);
    request.set_simulate(true);
    niswitch::InitWithTopologyResponse response;

    ::grpc::Status status = GetStub()->InitWithTopology(&context, request, &response);
    driver_session_ = std::make_unique<grpc::nidevice::Session>(response.vi());

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
  std::shared_ptr<::grpc::Channel> channel_;
  std::unique_ptr<::grpc::nidevice::Session> driver_session_;
  std::unique_ptr<niswitch::NiSwitch::Stub> niswitch_stub_;
  std::unique_ptr<grpc::nidevice::SessionRepository> session_repository_;
  std::unique_ptr<niswitch::NiSwitchLibrary> niswitch_library_;
  std::unique_ptr<niswitch::NiSwitchService> niswitch_service_;
  std::unique_ptr<::grpc::Server> server_;
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
  request.set_attribute_value(expected_value);
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
  request.set_attribute_value(expected_value);
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

}  // namespace system
}  // namespace tests
}  // namespace ni