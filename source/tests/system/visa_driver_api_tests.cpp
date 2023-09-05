#include "device_server.h"
#include "tests/utilities/test_helpers.h"
#include "visa/visa_client.h"

namespace ni {
namespace tests {
namespace system {

namespace visa = visa_grpc;
namespace client = visa_grpc::experimental::client;

class VisaDriverApiTest : public ::testing::Test {
 protected:
  VisaDriverApiTest()
      : device_server_(DeviceServerInterface::Singleton()),
        visa_stub_(visa::Visa::NewStub(device_server_->InProcessChannel()))
  {
    device_server_->ResetServer();
  }

  virtual ~VisaDriverApiTest() {}

  void SetUp() override
  {
#ifndef WIN32
    GTEST_SKIP() << "Digital pattern is not supported on Linux.";
#endif
    initialize_driver_session();
  }

  void TearDown() override
  {
    close_driver_session();
  }

  std::unique_ptr<visa::Visa::Stub>& GetStub()
  {
    return visa_stub_;
  }

  nidevice_grpc::Session GetNamedSession()
  {
    nidevice_grpc::Session vi;
    vi.set_name(driver_session_->name());
    return vi;
  }


  void initialize_driver_session()
  {
    ::grpc::ClientContext context;
    visa::OpenRequest request;
    visa::OpenResponse response;
    request.set_instrument_descriptor("TCPIP::www.ni.com::80::SOCKET");
    request.set_access_mode(visa::LOCK_STATE_NO_LOCK);
    request.set_session_name("SessionName");
    request.set_open_timeout(VI_TMO_IMMEDIATE);
    ::grpc::Status status = GetStub()->Open(&context, request, &response);
    client::raise_if_error(status, context);
    driver_session_ = std::make_unique<nidevice_grpc::Session>(response.vi());

    EXPECT_TRUE(status.ok());
    EXPECT_EQ(VI_SUCCESS, response.status());
  }

  void close_driver_session()
  {
    if (!driver_session_) {
      return;
    }
    auto response = client::close(GetStub(), GetNamedSession());
    EXPECT_EQ(VI_SUCCESS, response.status());
  }

  void set_bool_attribute(visa::VisaAttribute attribute, bool value)
  {
    visa_grpc::AttributeValueData data;
    data.set_value_bool(value);
    auto response = client::set_attribute(GetStub(), GetNamedSession(), attribute, data);
    EXPECT_EQ(VI_SUCCESS, response.status());
  }

  void set_uint32_attribute(visa::VisaAttribute attribute, uint32_t value)
  {
    visa_grpc::AttributeValueData data;
    data.set_value_u32(value);
    auto response = client::set_attribute(GetStub(), GetNamedSession(), attribute, data);
    EXPECT_EQ(VI_SUCCESS, response.status());
  }

  bool get_bool_attribute(visa::VisaAttribute attribute)
  {
    auto response = client::get_attribute(GetStub(), GetNamedSession(), attribute);
    EXPECT_EQ(VI_SUCCESS, response.status());
    EXPECT_TRUE(response.has_attribute_value());
    EXPECT_TRUE(response.attribute_value().has_value_bool());
    return response.attribute_value().value_bool();
  }

  int32 get_uint32_attribute(visa::VisaAttribute attribute)
  {
    auto response = client::get_attribute(GetStub(), GetNamedSession(), attribute);
    EXPECT_EQ(VI_SUCCESS, response.status());
    EXPECT_TRUE(response.has_attribute_value());
    EXPECT_TRUE(response.attribute_value().has_value_u32());
    return response.attribute_value().value_u32();
  }

  std::string get_string_attribute(visa::VisaAttribute attribute)
  {
    auto response = client::get_attribute(GetStub(), GetNamedSession(), attribute);
    EXPECT_EQ(VI_SUCCESS, response.status());
    EXPECT_TRUE(response.has_attribute_value());
    EXPECT_TRUE(response.attribute_value().has_value_string());
    return response.attribute_value().value_string();
  }

 private:
  DeviceServerInterface* device_server_;
  std::unique_ptr<visa::Visa::Stub> visa_stub_;
  std::unique_ptr<::nidevice_grpc::Session> driver_session_;
};

TEST_F(VisaDriverApiTest, GetOriginalTimeout_TwoSeconds)
{
  uint32_t originalTimeout = get_uint32_attribute(visa::VisaAttribute::VISA_ATTRIBUTE_TMO_VALUE);

  EXPECT_EQ(2000, originalTimeout);
}

TEST_F(VisaDriverApiTest, SetTimeout_GetTimeout_MeetsSpecRequirement)
{
  uint32_t specifiedTimeout = 7500;
  set_uint32_attribute(visa::VisaAttribute::VISA_ATTRIBUTE_TMO_VALUE, specifiedTimeout);

  uint32_t newTimeout = get_uint32_attribute(visa::VisaAttribute::VISA_ATTRIBUTE_TMO_VALUE);

  EXPECT_TRUE(newTimeout >= specifiedTimeout);
}

TEST_F(VisaDriverApiTest, GetHostname_Matches)
{
  std::string hostname = get_string_attribute(visa::VisaAttribute::VISA_ATTRIBUTE_TCPIP_HOSTNAME);

  EXPECT_EQ("www.ni.com", hostname);
}

TEST_F(VisaDriverApiTest, SetNonTcpipAttribute_ReturnsAttributeError)
{
  EXPECT_THROW_DRIVER_ERROR(
    set_bool_attribute(visa::VisaAttribute::VISA_ATTRIBUTE_ASRL_ALLOW_TRANSMIT, true),
    VI_ERROR_NSUP_ATTR
  );
}

}  // namespace system
}  // namespace tests
}  // namespace ni
