#include <gtest/gtest.h>

#include "niscope/niscope_library.h"
#include "niscope/niscope_service.h"
#include "nitclk/nitclk_library.h"
#include "nitclk/nitclk_service.h"

namespace ni {
namespace tests {
namespace system {

namespace scope = niscope_grpc;
namespace tclk = nitclk_grpc;

const int kScopeDriverApiSuccess = 0;
const int kTClkDriverApiSuccess = 0;

class NiTClkDriverApiTest : public ::testing::Test {
 protected:
  NiTClkDriverApiTest()
  {
    ::grpc::ServerBuilder builder;
    session_repository_ = std::make_unique<nidevice_grpc::SessionRepository>();
    niscope_library_ = std::make_unique<scope::NiScopeLibrary>();
    niscope_service_ = std::make_unique<scope::NiScopeService>(niscope_library_.get(), session_repository_.get());
    nitclk_library_ = std::make_unique<tclk::NiTClkLibrary>();
    nitclk_service_ = std::make_unique<tclk::NiTClkService>(nitclk_library_.get(), session_repository_.get());
    builder.RegisterService(niscope_service_.get());
    builder.RegisterService(nitclk_service_.get());

    server_ = builder.BuildAndStart();
    ResetStubs();
  }

  virtual ~NiTClkDriverApiTest() {}

  void SetUp() override
  {
    initialize_scope_session();
  }

  void TearDown() override
  {
    close_scope_session();
  }

  void ResetStubs()
  {
    channel_ = server_->InProcessChannel(::grpc::ChannelArguments());
    niscope_stub_ = scope::NiScope::NewStub(channel_);
    nitclk_stub_ = tclk::NiTClk::NewStub(channel_);
  }

  std::unique_ptr<scope::NiScope::Stub>& GetScopeStub()
  {
    return niscope_stub_;
  }

  std::unique_ptr<tclk::NiTClk::Stub>& GetTClkStub()
  {
      return nitclk_stub_;
  }

  int GetScopeSessionId()
  {
    return scope_session_->id();
  }

  void initialize_scope_session()
  {
    ::grpc::ClientContext context;
    scope::InitWithOptionsRequest request;
    request.set_resource_name("FakeDevice");
    request.set_option_string("Simulate=1, DriverSetup=Model:5164; BoardType:PXIe");
    request.set_session_name("");
    request.set_reset_device(false);
    request.set_id_query(false);
    scope::InitWithOptionsResponse response;

    ::grpc::Status status = GetScopeStub()->InitWithOptions(&context, request, &response);
    scope_session_ = std::make_unique<nidevice_grpc::Session>(response.vi());

    ASSERT_TRUE(status.ok());
    ASSERT_EQ(kScopeDriverApiSuccess, response.status());
  }

  void close_scope_session()
  {
    ::grpc::ClientContext context;
    scope::CloseRequest request;
    request.mutable_vi()->set_id(scope_session_->id());
    scope::CloseResponse response;

    ::grpc::Status status = GetScopeStub()->Close(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kScopeDriverApiSuccess, response.status());
  }

  ViReal64 get_real64_attribute(const char* channel_name, tclk::NiTClkAttributes attribute_id)
  {
    ::grpc::ClientContext context;
    tclk::GetAttributeViReal64Request request;
    request.mutable_session()->set_id(GetScopeSessionId());
    request.set_channel_name(channel_name);
    request.set_attribute_id(attribute_id);
    tclk::GetAttributeViReal64Response response;

    ::grpc::Status status = GetTClkStub()->GetAttributeViReal64(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kTClkDriverApiSuccess, response.status());
    return response.value();
  }

  int get_session_id_from_attribute(const char* channel_name, tclk::NiTClkAttributes attribute_id)
  {
    ::grpc::ClientContext context;
    tclk::GetAttributeViSessionRequest request;
    request.mutable_session()->set_id(GetScopeSessionId());
    request.set_channel_name(channel_name);
    request.set_attribute_id(attribute_id);
    tclk::GetAttributeViSessionResponse response;

    ::grpc::Status status = GetTClkStub()->GetAttributeViSession(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kTClkDriverApiSuccess, response.status());
    return response.value().id();
  }

  std::string get_string_attribute(const char* channel_name, tclk::NiTClkAttributes attribute_id)
  {
    ::grpc::ClientContext context;
    tclk::GetAttributeViStringRequest request;
    request.mutable_session()->set_id(GetScopeSessionId());
    request.set_channel_name(channel_name);
    request.set_attribute_id(attribute_id);
    tclk::GetAttributeViStringResponse response;

    ::grpc::Status status = GetTClkStub()->GetAttributeViString(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kTClkDriverApiSuccess, response.status());
    return response.value();
  }
  
  void set_real64_attribute(const char* channel_name, tclk::NiTClkAttributes attribute_id, const ViReal64 attribute_value)
  {
    ::grpc::ClientContext context;
    tclk::SetAttributeViReal64Request request;
    request.mutable_session()->set_id(GetScopeSessionId());
    request.set_channel_name(channel_name);
    request.set_attribute_id(attribute_id);
    request.set_value_raw(attribute_value);
    tclk::SetAttributeViReal64Response response;

    ::grpc::Status status = GetTClkStub()->SetAttributeViReal64(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kTClkDriverApiSuccess, response.status());
  }

  void set_session_attribute(const char* channel_name, tclk::NiTClkAttributes attribute_id, const int session_id)
  {
    ::grpc::ClientContext context;
    tclk::SetAttributeViSessionRequest request;
    request.mutable_session()->set_id(GetScopeSessionId());
    request.set_channel_name(channel_name);
    request.set_attribute_id(attribute_id);
    request.mutable_value()->set_id(session_id);
    tclk::SetAttributeViSessionResponse response;

    ::grpc::Status status = GetTClkStub()->SetAttributeViSession(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kTClkDriverApiSuccess, response.status());
  }

  void set_string_attribute(const char* channel_name, tclk::NiTClkAttributes attribute_id, const ViString attribute_value)
  {
    ::grpc::ClientContext context;
    tclk::SetAttributeViStringRequest request;
    request.mutable_session()->set_id(GetScopeSessionId());
    request.set_channel_name(channel_name);
    request.set_attribute_id(attribute_id);
    request.set_value_raw(attribute_value);
    tclk::SetAttributeViStringResponse response;

    ::grpc::Status status = GetTClkStub()->SetAttributeViString(&context, request, &response);

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(kTClkDriverApiSuccess, response.status());
  }

 private:
  std::shared_ptr<::grpc::Channel> channel_;
  std::unique_ptr<::nidevice_grpc::Session> scope_session_;
  std::unique_ptr<scope::NiScope::Stub> niscope_stub_;
  std::unique_ptr<tclk::NiTClk::Stub> nitclk_stub_;
  std::unique_ptr<nidevice_grpc::SessionRepository> session_repository_;
  std::unique_ptr<scope::NiScopeLibrary> niscope_library_;
  std::unique_ptr<scope::NiScopeService> niscope_service_;
  std::unique_ptr<tclk::NiTClkLibrary> nitclk_library_;
  std::unique_ptr<tclk::NiTClkService> nitclk_service_;
  std::unique_ptr<::grpc::Server> server_;
};

TEST_F(NiTClkDriverApiTest, ConfigureForHomogeneousTriggers_ReturnsStatusAsSuccessful)
{
  ::grpc::ClientContext context;
  tclk::ConfigureForHomogeneousTriggersRequest request;
  request.add_sessions()->set_id(GetScopeSessionId());
  tclk::ConfigureForHomogeneousTriggersResponse response;
  ::grpc::Status status = GetTClkStub()->ConfigureForHomogeneousTriggers(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kTClkDriverApiSuccess, response.status());
}

TEST_F(NiTClkDriverApiTest, SetupForSyncPulseSenderSynchronize_ReturnsStatusAsSuccessful)
{
  ::grpc::ClientContext context;
  tclk::SetupForSyncPulseSenderSynchronizeRequest request;
  request.add_sessions()->set_id(GetScopeSessionId());
  tclk::SetupForSyncPulseSenderSynchronizeResponse response;
  ::grpc::Status status = GetTClkStub()->SetupForSyncPulseSenderSynchronize(&context, request, &response);

  EXPECT_TRUE(status.ok());
  EXPECT_EQ(kTClkDriverApiSuccess, response.status());
}

TEST_F(NiTClkDriverApiTest, SetAttributeViReal64_CallGetAttributeViReal64_ValuesMatch)
{
  const char* channel_name = "";
  const tclk::NiTClkAttributes attribute_to_set = tclk::NiTClkAttributes::NITCLK_ATTRIBUTE_SAMPLE_CLOCK_DELAY;
  const ViReal64 expected_value = 4.24;
  set_real64_attribute(channel_name, attribute_to_set, expected_value);

  ViReal64 get_attribute_value = get_real64_attribute(channel_name, attribute_to_set);

  EXPECT_EQ(expected_value, get_attribute_value);
}

TEST_F(NiTClkDriverApiTest, SetAttributeViSession_CallGetAttributeViSession_ValuesMatch)
{
  const char* channel_name = "";
  const tclk::NiTClkAttributes attribute_to_set = tclk::NiTClkAttributes::NITCLK_ATTRIBUTE_START_TRIGGER_MASTER_SESSION;
  int expected_value = GetScopeSessionId();
  set_session_attribute(channel_name, attribute_to_set, expected_value);

  int get_attribute_value = get_session_id_from_attribute(channel_name, attribute_to_set);

  EXPECT_EQ(expected_value, get_attribute_value);
}

TEST_F(NiTClkDriverApiTest, SetAttributeViString_CallGetAttributeViString_ValuesMatch)
{
  const char* channel_name = "";
  const tclk::NiTClkAttributes attribute_to_set = tclk::NiTClkAttributes::NITCLK_ATTRIBUTE_SYNC_PULSE_SOURCE;
  const ViString expected_value = "Hello world!";
  set_string_attribute(channel_name, attribute_to_set, expected_value);

  std::string get_attribute_value = get_string_attribute(channel_name, attribute_to_set);

  EXPECT_STREQ(expected_value, get_attribute_value.c_str());
}

}  // namespace system
}  // namespace tests
}  // namespace ni