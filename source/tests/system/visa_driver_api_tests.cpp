#include "device_server.h"
#include "tests/utilities/tcp_echo_server.h"
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
        visa_stub_(visa::Visa::NewStub(device_server_->InProcessChannel())),
        instrument_descriptor_ni_com_("TCPIP::www.ni.com::80::SOCKET")
  {
    device_server_->ResetServer();
  }

  virtual ~VisaDriverApiTest() {}

  void SetUp() override
  {
    initialize_driver_session(instrument_descriptor_ni_com_);
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


  void initialize_driver_session(const std::string& instrument_descriptor)
  {
    ::grpc::ClientContext context;
    visa::OpenRequest request;
    visa::OpenResponse response;
    request.set_instrument_descriptor(instrument_descriptor);
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
  std::string instrument_descriptor_ni_com_;
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

class VisaDriverLoopbackTest : public VisaDriverApiTest {
  public:
  VisaDriverLoopbackTest()
  : portNumber_("1234")
  , instrument_descriptor_("TCPIP0::localhost::" + portNumber_ + "::SOCKET")
  , echoserver_(portNumber_)
  {
  }
  virtual ~VisaDriverLoopbackTest()
  {
  }

  void SetUp() override
  {
    EXPECT_EQ(0, echoserver_.start());
    initialize_driver_session(instrument_descriptor_);
  }

  void TearDown() override
  {
    close_driver_session();
    echoserver_.stop();
  }

  void write(const std::string& data)
  {
    auto response = client::write(GetStub(), GetNamedSession(), data);
    EXPECT_EQ(VI_SUCCESS, response.status());
    EXPECT_EQ(data.size(), response.return_count());
  }

  void read(uint32_t count, const std::string& expectedData, ViStatus expectedStatus)
  {
    auto response = client::read(GetStub(), GetNamedSession(), count);
    EXPECT_EQ(expectedStatus, response.status());
    EXPECT_EQ(expectedData.size(), response.return_count());
    EXPECT_EQ(expectedData, response.buffer());
  }

  private:
    std::string portNumber_;
    std::string instrument_descriptor_;
    TcpEchoServer echoserver_;
};

TEST_F(VisaDriverLoopbackTest, WriteAndRead_Matches)
{
  std::string writeData = "Visa gRPC read/write test";
  write(writeData);
  read(writeData.size(), writeData, VI_SUCCESS_MAX_CNT);
}

TEST_F(VisaDriverLoopbackTest, WriteTwice_ReadOnce_Matches)
{
  std::string writeData = "Visa gRPC read/write test";
  write(writeData + "1 ");
  write(writeData + "2");
  std::string expectedReadData = writeData + "1 " + writeData + "2";
  read(expectedReadData.size(), expectedReadData, VI_SUCCESS_MAX_CNT);
}

TEST_F(VisaDriverLoopbackTest, ReadMoreThanWritten_ReturnTimeout)
{
  std::string writeData = "Visa gRPC read/write test";
  write(writeData);
  read(writeData.size() + 1, writeData, VI_ERROR_TMO);
}

TEST_F(VisaDriverLoopbackTest, ReadLessThanWritten_ReturnSuccess)
{
  std::string writeData = "Visa gRPC read/write test";
  write(writeData);
  read(writeData.size() - 1, writeData.substr(0, writeData.size() - 1), VI_SUCCESS_MAX_CNT);
}

TEST_F(VisaDriverLoopbackTest, ReadZeroBytes_ReturnSuccess)
{
  std::string writeData = "Visa gRPC read/write test";
  write(writeData);
  read(0, "", VI_SUCCESS_MAX_CNT);
}

TEST_F(VisaDriverLoopbackTest, WriteOnce_ReadTwice_Matches)
{
  std::string writeData = "Visa gRPC read/write test";
  write(writeData);
  read(10, writeData.substr(0, 10), VI_SUCCESS_MAX_CNT);
  read(writeData.size() - 10, writeData.substr(10, writeData.size()), VI_SUCCESS_MAX_CNT);
}

TEST_F(VisaDriverLoopbackTest, ReadWithoutWrite_ThrowsError)
{
  EXPECT_THROW_DRIVER_ERROR(
    read(10, "", -1),
    VI_ERROR_TMO);
}


}  // namespace system
}  // namespace tests
}  // namespace ni
