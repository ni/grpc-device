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

    ASSERT_TRUE(status.ok());
    ASSERT_EQ(VI_SUCCESS, response.status());
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

class VisaMessageBasedLoopbackTest : public VisaDriverApiTest {
  public:
  VisaMessageBasedLoopbackTest()
  {
  }
  virtual ~VisaMessageBasedLoopbackTest()
  {
  }

  void SetUp() override
  {
    EXPECT_EQ(0, echoserver_.start());

    std::string portNumber(std::to_string(echoserver_.get_server_port()));
    std::string instrument_descriptor("TCPIP0::localhost::" + portNumber + "::SOCKET");
    initialize_driver_session(instrument_descriptor);
    auto response = client::enable_event(GetStub(), GetNamedSession(), VI_EVENT_IO_COMPLETION, VI_QUEUE, VI_NULL);
    EXPECT_EQ(VI_SUCCESS, response.status());
  }

  void TearDown() override
  {
    close_driver_session();
    echoserver_.stop();
  }

  const uint32_t kWaitTimeoutMsec = 2000;
  const uint32_t kFastTimeoutMsec = 500;

  void write(const std::string& data)
  {
    auto response = client::write(GetStub(), GetNamedSession(), data);
    EXPECT_EQ(VI_SUCCESS, response.status());
    EXPECT_EQ(data.size(), response.return_count());
  }

  void write_async(const std::string& data)
  {
    auto asyncResponse = client::write_async(GetStub(), GetNamedSession(), data);
    EXPECT_THAT((std::array<ViStatus, 2>{ VI_SUCCESS, VI_SUCCESS_SYNC }), testing::Contains(asyncResponse.status()));
    auto waitResponse = client::wait_on_event(GetStub(), GetNamedSession(), VI_EVENT_IO_COMPLETION, kWaitTimeoutMsec);
    EXPECT_EQ(VI_SUCCESS, waitResponse.status());
    auto eventResponse = client::get_attribute_event(GetStub(), waitResponse.event_handle(), visa::VisaAttribute::VISA_ATTRIBUTE_STATUS);
    EXPECT_EQ(VI_SUCCESS, eventResponse.status());
    EXPECT_EQ(VI_SUCCESS, eventResponse.attribute_value().value_i32());
    eventResponse = client::get_attribute_event(GetStub(), waitResponse.event_handle(), visa::VisaAttribute::VISA_ATTRIBUTE_RET_COUNT);
    EXPECT_EQ(VI_SUCCESS, eventResponse.status());
    EXPECT_EQ(data.size(), eventResponse.attribute_value().value_u32());
    auto closeResponse = client::close_event(GetStub(), waitResponse.event_handle());
    EXPECT_EQ(VI_SUCCESS, closeResponse.status());
  }

  void read(size_t count, const std::string& expectedData, ViStatus expectedStatus)
  {
    auto response = client::read(GetStub(), GetNamedSession(), static_cast<uint32_t>(count));
    EXPECT_EQ(expectedStatus, response.status());
    EXPECT_EQ(expectedData.size(), response.return_count());
    EXPECT_EQ(expectedData, response.buffer());
  }

  void read_async(size_t count, const std::string& expectedData, ViStatus expectedStatus, bool requiresTerminate = false)
  {
    auto asyncResponse = client::read_async(GetStub(), GetNamedSession(), static_cast<uint32_t>(count));
    EXPECT_THAT((std::array<ViStatus, 2>{ VI_SUCCESS, VI_SUCCESS_SYNC }), testing::Contains(asyncResponse.status()));
    if (requiresTerminate) {
      std::this_thread::sleep_for(std::chrono::milliseconds(kFastTimeoutMsec));
      auto terminateResponse = client::terminate(GetStub(), GetNamedSession(), 0, asyncResponse.job_identifier());
      EXPECT_EQ(VI_SUCCESS, terminateResponse.status());
    }
    auto waitResponse = client::wait_on_event(GetStub(), GetNamedSession(), VI_EVENT_IO_COMPLETION, kWaitTimeoutMsec);
    EXPECT_EQ(VI_SUCCESS, waitResponse.status());
    auto eventResponse = client::get_attribute_event(GetStub(), waitResponse.event_handle(), visa::VisaAttribute::VISA_ATTRIBUTE_STATUS);
    EXPECT_EQ(VI_SUCCESS, eventResponse.status());
    EXPECT_EQ(expectedStatus, eventResponse.attribute_value().value_i32());
    eventResponse = client::get_attribute_event(GetStub(), waitResponse.event_handle(), visa::VisaAttribute::VISA_ATTRIBUTE_RET_COUNT);
    EXPECT_EQ(VI_SUCCESS, eventResponse.status());
    EXPECT_EQ(expectedData.size(), eventResponse.attribute_value().value_u32());
    eventResponse = client::get_attribute_event(GetStub(), waitResponse.event_handle(), visa::VisaAttribute::VISA_ATTRIBUTE_BUFFER);
    EXPECT_EQ(VI_SUCCESS, eventResponse.status());
    EXPECT_EQ(expectedData, eventResponse.attribute_value().value_bytes());
    auto closeResponse = client::close_event(GetStub(), waitResponse.event_handle());
    EXPECT_EQ(VI_SUCCESS, closeResponse.status());
  }

  void assert_trigger(visa::TriggerProtocol protocol)
  {
    auto response = client::assert_trigger(GetStub(), GetNamedSession(), protocol);
    EXPECT_EQ(VI_SUCCESS, response.status());
  }

  void flush(visa::BufferMask mask)
  {
    auto response = client::flush(GetStub(), GetNamedSession(), mask);
    EXPECT_EQ(VI_SUCCESS, response.status());
  }

  private:
    TcpEchoServer echoserver_;
};

TEST_F(VisaMessageBasedLoopbackTest, WriteAndRead_Matches)
{
  std::string writeData = "Visa gRPC read/write test";
  write(writeData);
  read(writeData.size(), writeData, VI_SUCCESS_MAX_CNT);
}

TEST_F(VisaMessageBasedLoopbackTest, WriteAsyncAndReadAsync_Matches)
{
  std::string writeData = "Visa gRPC read/write test";
  write_async(writeData);
  read_async(writeData.size(), writeData, VI_SUCCESS_MAX_CNT);
}

TEST_F(VisaMessageBasedLoopbackTest, WriteTwice_ReadOnce_Matches)
{
  std::string writeData = "Visa gRPC read/write test";
  write(writeData + "1 ");
  write(writeData + "2");
  std::string expectedReadData = writeData + "1 " + writeData + "2";
  read(expectedReadData.size(), expectedReadData, VI_SUCCESS_MAX_CNT);
}

TEST_F(VisaMessageBasedLoopbackTest, ReadMoreThanWritten_ReturnTimeoutErrorWithDataInResponsePacket)
{
  std::string writeData = "Visa gRPC read/write test";
  set_uint32_attribute(visa::VisaAttribute::VISA_ATTRIBUTE_TMO_VALUE, kFastTimeoutMsec);
  write(writeData);
  read(writeData.size() + 1, writeData, VI_ERROR_TMO);
}

TEST_F(VisaMessageBasedLoopbackTest, ReadAsyncMoreThanWritten_ReturnTimeoutErrorWithDataInResponsePacket)
{
  std::string writeData = "Visa gRPC read/write test";
  set_uint32_attribute(visa::VisaAttribute::VISA_ATTRIBUTE_TMO_VALUE, kFastTimeoutMsec);
  write(writeData);
  read_async(writeData.size() + 1, writeData, VI_ERROR_ABORT, true);
}

TEST_F(VisaMessageBasedLoopbackTest, ReadLessThanWritten_ReturnSuccess)
{
  std::string writeData = "Visa gRPC read/write test";
  write(writeData);
  read(writeData.size() - 1, writeData.substr(0, writeData.size() - 1), VI_SUCCESS_MAX_CNT);
}

TEST_F(VisaMessageBasedLoopbackTest, ReadAsyncLessThanWritten_ReturnSuccess)
{
  std::string writeData = "Visa gRPC read/write test";
  write(writeData);
  read_async(writeData.size() - 1, writeData.substr(0, writeData.size() - 1), VI_SUCCESS_MAX_CNT);
}

TEST_F(VisaMessageBasedLoopbackTest, ReadZeroBytes_ReturnSuccess)
{
  std::string writeData = "Visa gRPC read/write test";
  write(writeData);
  read(0, "", VI_SUCCESS_MAX_CNT);
}

TEST_F(VisaMessageBasedLoopbackTest, ReadAsyncZeroBytes_ReturnSuccess)
{
  std::string writeData = "Visa gRPC read/write test";
  write_async(writeData);
  read_async(0, "", VI_SUCCESS_MAX_CNT);
}

TEST_F(VisaMessageBasedLoopbackTest, ReadWithoutWrite_ThrowsError)
{
  set_uint32_attribute(visa::VisaAttribute::VISA_ATTRIBUTE_TMO_VALUE, kFastTimeoutMsec);
  EXPECT_THROW_DRIVER_ERROR(
    read(10, "", -1),
    VI_ERROR_TMO);
}

TEST_F(VisaMessageBasedLoopbackTest, WriteSpecialData_ReadMatches)
{
  const char buffer[] = {'A', '\0', 'B', '\0', 'C'};
  std::string writeData(buffer, sizeof(buffer));
  write(writeData);
  read(writeData.size(), writeData, VI_SUCCESS_MAX_CNT);
}

TEST_F(VisaMessageBasedLoopbackTest, WriteAsyncSpecialData_ReadAsyncMatches)
{
  const char buffer[] = {'A', '\0', 'B', '\0', 'C'};
  std::string writeData(buffer, sizeof(buffer));
  write_async(writeData);
  read_async(writeData.size(), writeData, VI_SUCCESS_MAX_CNT);
}

TEST_F(VisaMessageBasedLoopbackTest, WriteWithTermChar_ReadMatches)
{
  std::string writeData = "Hello\nWorld\n";

  write(writeData);
  set_bool_attribute(visa::VisaAttribute::VISA_ATTRIBUTE_TERMCHAR_EN, true);
  read(255, "Hello\n", VI_SUCCESS_TERM_CHAR);
  read(255, "World\n", VI_SUCCESS_TERM_CHAR);
}

TEST_F(VisaMessageBasedLoopbackTest, AssertTrigger_SendsCommand)
{
  set_bool_attribute(visa::VisaAttribute::VISA_ATTRIBUTE_TERMCHAR_EN, true);
  set_uint32_attribute(visa::VisaAttribute::VISA_ATTRIBUTE_IO_PROT, 4); // VI_PROT_4882_STRS 
  assert_trigger(visa::TRIGGER_PROTOCOL_PROT_DEFAULT);
  read(255, "*TRG\n", VI_SUCCESS_TERM_CHAR);
}

TEST_F(VisaMessageBasedLoopbackTest, Flush_ClearsBuffer)
{
  set_uint32_attribute(visa::VisaAttribute::VISA_ATTRIBUTE_TMO_VALUE, kFastTimeoutMsec);
  write("Some data in the pipe\n");
  flush(visa::BUFFER_MASK_IO_IN_BUF_DISCARD);
  EXPECT_THROW_DRIVER_ERROR(
    read(10, "", -1),
    VI_ERROR_TMO);
}

class VisaRegisterBasedLoopbackTest : public VisaDriverApiTest {
  public:
  VisaRegisterBasedLoopbackTest() : allocatedBase_(0), mappedBase_(0)
  {
  }
  virtual ~VisaRegisterBasedLoopbackTest()
  {
  }

  void SetUp() override
  {
    initialize_driver_session("PXI::MEMACC");
    auto response = client::mem_alloc_ex(GetStub(), GetNamedSession(), 4096);
    ASSERT_EQ(VI_SUCCESS, response.status());
    allocatedBase_ = response.offset();
  }

  void TearDown() override
  {
    free(allocatedBase_);
    close_driver_session();
  }

  void free(uint64_t offset)
  {
    auto response = client::mem_free(GetStub(), GetNamedSession(), offset);
    EXPECT_EQ(VI_SUCCESS, response.status());
  }

  ViUInt8 in8(uint64_t offset)
  {
    auto response = client::in8(GetStub(), GetNamedSession(), visa::ADDRESS_SPACE_PXI_ALLOC_SPACE, allocatedBase_ + offset);
    EXPECT_EQ(VI_SUCCESS, response.status());
    return response.value();
  }

  ViUInt16 in16(uint64_t offset)
  {
    auto response = client::in16(GetStub(), GetNamedSession(), visa::ADDRESS_SPACE_PXI_ALLOC_SPACE, allocatedBase_ + offset);
    EXPECT_EQ(VI_SUCCESS, response.status());
    return response.value();
  }

  ViUInt32 in32(uint64_t offset)
  {
    auto response = client::in32(GetStub(), GetNamedSession(), visa::ADDRESS_SPACE_PXI_ALLOC_SPACE, allocatedBase_ + offset);
    EXPECT_EQ(VI_SUCCESS, response.status());
    return response.value();
  }

  ViUInt64 in64(uint64_t offset)
  {
    auto response = client::in64(GetStub(), GetNamedSession(), visa::ADDRESS_SPACE_PXI_ALLOC_SPACE, allocatedBase_ + offset);
    EXPECT_EQ(VI_SUCCESS, response.status());
    return response.value();
  }

  void out8(uint64_t offset, ViUInt8 value)
  {
    auto response = client::out8(GetStub(), GetNamedSession(), visa::ADDRESS_SPACE_PXI_ALLOC_SPACE, allocatedBase_ + offset, value);
    EXPECT_EQ(VI_SUCCESS, response.status());
  }

  void out16(uint64_t offset, ViUInt16 value)
  {
    auto response = client::out16(GetStub(), GetNamedSession(), visa::ADDRESS_SPACE_PXI_ALLOC_SPACE, allocatedBase_ + offset, value);
    EXPECT_EQ(VI_SUCCESS, response.status());
  }

  void out32(uint64_t offset, ViUInt32 value)
  {
    auto response = client::out32(GetStub(), GetNamedSession(), visa::ADDRESS_SPACE_PXI_ALLOC_SPACE, allocatedBase_ + offset, value);
    EXPECT_EQ(VI_SUCCESS, response.status());
  }

  void out64(uint64_t offset, ViUInt64 value)
  {
    auto response = client::out64(GetStub(), GetNamedSession(), visa::ADDRESS_SPACE_PXI_ALLOC_SPACE, allocatedBase_ + offset, value);
    EXPECT_EQ(VI_SUCCESS, response.status());
  }

  std::vector<ViUInt8> moveIn8(uint64_t offset, int length)
  {
    auto response = client::move_in8(GetStub(), GetNamedSession(), visa::ADDRESS_SPACE_PXI_ALLOC_SPACE, allocatedBase_ + offset, length);
    EXPECT_EQ(VI_SUCCESS, response.status());
    std::vector<ViUInt8> retval;
    const std::string& responseBuffer = response.buffer();
    for (int i = 0; i < responseBuffer.length(); i++) {
      retval.push_back(responseBuffer[i]);
    }
    return retval;
  }

  google::protobuf::RepeatedField<uint32_t> moveIn16(uint64_t offset, int length)
  {
    auto response = client::move_in16(GetStub(), GetNamedSession(), visa::ADDRESS_SPACE_PXI_ALLOC_SPACE, allocatedBase_ + offset, length);
    EXPECT_EQ(VI_SUCCESS, response.status());
    return response.buffer();
  }

  google::protobuf::RepeatedField<uint32_t> moveIn32(uint64_t offset, int length)
  {
    auto response = client::move_in32(GetStub(), GetNamedSession(), visa::ADDRESS_SPACE_PXI_ALLOC_SPACE, allocatedBase_ + offset, length);
    EXPECT_EQ(VI_SUCCESS, response.status());
    return response.buffer();
  }

  google::protobuf::RepeatedField<uint64_t> moveIn64(uint64_t offset, int length)
  {
    auto response = client::move_in64(GetStub(), GetNamedSession(), visa::ADDRESS_SPACE_PXI_ALLOC_SPACE, allocatedBase_ + offset, length);
    EXPECT_EQ(VI_SUCCESS, response.status());
    return response.buffer();
  }

  void moveOut8(uint64_t offset, ViUInt8 data[], int length)
  {
    std::string buffer(reinterpret_cast<char*>(data), length);
    auto response = client::move_out8(GetStub(), GetNamedSession(), visa::ADDRESS_SPACE_PXI_ALLOC_SPACE, allocatedBase_ + offset, buffer);
    EXPECT_EQ(VI_SUCCESS, response.status());
  }

  void moveOut16(uint64_t offset, ViUInt16 data[], int length)
  {
    std::vector<uint32_t> buffer;
    for (int i = 0; i < length; i++) {
      buffer.push_back(data[i]);
    }
    auto response = client::move_out16(GetStub(), GetNamedSession(), visa::ADDRESS_SPACE_PXI_ALLOC_SPACE, allocatedBase_ + offset, buffer);
    EXPECT_EQ(VI_SUCCESS, response.status());
  }

  void moveOut32(uint64_t offset, ViUInt32 data[], int length)
  {
    std::vector<uint32_t> buffer;
    for (int i = 0; i < length; i++) {
      buffer.push_back(data[i]);
    }
    auto response = client::move_out32(GetStub(), GetNamedSession(), visa::ADDRESS_SPACE_PXI_ALLOC_SPACE, allocatedBase_ + offset, buffer);
    EXPECT_EQ(VI_SUCCESS, response.status());
  }

  void moveOut64(uint64_t offset, ViUInt64 data[], int length)
  {
    std::vector<uint64_t> buffer;
    for (int i = 0; i < length; i++) {
      buffer.push_back(data[i]);
    }
    auto response = client::move_out64(GetStub(), GetNamedSession(), visa::ADDRESS_SPACE_PXI_ALLOC_SPACE, allocatedBase_ + offset, buffer);
    EXPECT_EQ(VI_SUCCESS, response.status());
  }

  void map()
  {
    auto response = client::map_address(GetStub(), GetNamedSession(), visa::ADDRESS_SPACE_PXI_ALLOC_SPACE, allocatedBase_, 4096, false, 0);
    EXPECT_EQ(VI_SUCCESS, response.status());
    mappedBase_ = response.address();
  }

  void unmap()
  {
    auto response = client::unmap_address(GetStub(), GetNamedSession());
    EXPECT_EQ(VI_SUCCESS, response.status());
  }

  ViUInt8 peek8(uint64_t offset)
  {
    auto response = client::peek8(GetStub(), GetNamedSession(), mappedBase_ + offset);
    EXPECT_EQ(VI_SUCCESS, response.status());
    return response.value();
  }

  ViUInt16 peek16(uint64_t offset)
  {
    auto response = client::peek16(GetStub(), GetNamedSession(), mappedBase_ + offset);
    EXPECT_EQ(VI_SUCCESS, response.status());
    return response.value();
  }

  ViUInt32 peek32(uint64_t offset)
  {
    auto response = client::peek32(GetStub(), GetNamedSession(), mappedBase_ + offset);
    EXPECT_EQ(VI_SUCCESS, response.status());
    return response.value();
  }

  ViUInt64 peek64(uint64_t offset)
  {
    auto response = client::peek64(GetStub(), GetNamedSession(), mappedBase_ + offset);
    EXPECT_EQ(VI_SUCCESS, response.status());
    return response.value();
  }

  void poke8(uint64_t offset, ViUInt8 value)
  {
    auto response = client::poke8(GetStub(), GetNamedSession(), mappedBase_ + offset, value);
    EXPECT_EQ(VI_SUCCESS, response.status());
  }

  void poke16(uint64_t offset, ViUInt16 value)
  {
    auto response = client::poke16(GetStub(), GetNamedSession(), mappedBase_ + offset, value);
    EXPECT_EQ(VI_SUCCESS, response.status());
  }

  void poke32(uint64_t offset, ViUInt32 value)
  {
    auto response = client::poke32(GetStub(), GetNamedSession(), mappedBase_ + offset, value);
    EXPECT_EQ(VI_SUCCESS, response.status());
  }

  void poke64(uint64_t offset, ViUInt64 value)
  {
    auto response = client::poke64(GetStub(), GetNamedSession(), mappedBase_ + offset, value);
    EXPECT_EQ(VI_SUCCESS, response.status());
  }

  private:
    uint64_t allocatedBase_;
    uint64_t mappedBase_;
};

TEST_F(VisaRegisterBasedLoopbackTest, DataWrittenWithMoveOut8_In8_ReadsData)
{
  const int testLength = 5;
  const int startingOffset = 11;
  ViUInt8 buffer[testLength] = { 0x01, 0x02, 0x00, 0x03, 0xFE };
  moveOut8(startingOffset, buffer, testLength);
  for (int i = 0; i < testLength; ++i) {
    EXPECT_EQ(buffer[i], in8(startingOffset + i));
  }
}

TEST_F(VisaRegisterBasedLoopbackTest, DataWrittenWithMoveOut16_In16_ReadsData)
{
  const int testLength = 5;
  const int startingOffset = 14;
  ViUInt16 buffer[testLength] = { 0x0123, 0x0234, 0x00, 0x8675, 0xFEDC };
  moveOut16(startingOffset, buffer, testLength);
  for (int i = 0; i < testLength; ++i) {
    EXPECT_EQ(buffer[i], in16(startingOffset + i * 2));
  }
}

TEST_F(VisaRegisterBasedLoopbackTest, DataWrittenWithMoveOut32_In32_ReadsData)
{
  const int testLength = 5;
  const int startingOffset = 16;
  ViUInt32 buffer[testLength] = { 0x01234567, 0x02340234, 0x00, 0x86754321, 0xC0FFEE };
  moveOut32(startingOffset, buffer, testLength);
  for (int i = 0; i < testLength; ++i) {
    EXPECT_EQ(buffer[i], in32(startingOffset + i * 4));
  }
}

TEST_F(VisaRegisterBasedLoopbackTest, DataWrittenWithMoveOut64_In64_ReadsData)
{
  const int testLength = 5;
  const int startingOffset = 16;
  ViUInt64 buffer[testLength] = { 0x01234567DEADBEEF, 0x02340234, 0x00, 0x867543210ABCDEF, 0xC0FFEE };
  moveOut64(startingOffset, buffer, testLength);
  for (int i = 0; i < testLength; ++i) {
    EXPECT_EQ(buffer[i], in64(startingOffset + i * 8));
  }
}

TEST_F(VisaRegisterBasedLoopbackTest, DataWrittenWithOut8_MoveIn8_ReadsData)
{
  const int testLength = 5;
  const int startingOffset = 11;
  ViUInt8 buffer[testLength] = { 0x01, 0x02, 0x00, 0x03, 0xFE };
  for (int i = 0; i < testLength; ++i) {
    out8(startingOffset + i, buffer[i]);
  }
  auto readBuffer = moveIn8(startingOffset, testLength);
  for (int i = 0; i < testLength; ++i) {
    EXPECT_EQ(readBuffer[i], buffer[i]);
  }
}

TEST_F(VisaRegisterBasedLoopbackTest, DataWrittenWithOut16_MoveIn16_ReadsData)
{
  const int testLength = 5;
  const int startingOffset = 14;
  ViUInt16 buffer[testLength] = { 0x0123, 0x0234, 0x00, 0x8675, 0xFEDC };
  for (int i = 0; i < testLength; ++i) {
    out16(startingOffset + i * 2, buffer[i]);
  }
  auto readBuffer = moveIn16(startingOffset, testLength);
  for (int i = 0; i < testLength; ++i) {
    EXPECT_EQ(readBuffer[i], buffer[i]);
  }
}

TEST_F(VisaRegisterBasedLoopbackTest, DataWrittenWithOut32_MoveIn32_ReadsData)
{
  const int testLength = 5;
  const int startingOffset = 16;
  ViUInt32 buffer[testLength] = { 0x01234567, 0x02340234, 0x00, 0x86754321, 0xC0FFEE };
  for (int i = 0; i < testLength; ++i) {
    out32(startingOffset + i * 4, buffer[i]);
  }
  auto readBuffer = moveIn32(startingOffset, testLength);
  for (int i = 0; i < testLength; ++i) {
    EXPECT_EQ(readBuffer[i], buffer[i]);
  }
}

TEST_F(VisaRegisterBasedLoopbackTest, DataWrittenWithOut64_MoveIn64_ReadsData)
{
  const int testLength = 5;
  const int startingOffset = 16;
  ViUInt64 buffer[testLength] = { 0x01234567DEADBEEF, 0x02340234, 0x00, 0x867543210ABCDEF, 0xC0FFEE };
  for (int i = 0; i < testLength; ++i) {
    out64(startingOffset + i * 8, buffer[i]);
  }
  auto readBuffer = moveIn64(startingOffset, testLength);
  for (int i = 0; i < testLength; ++i) {
    EXPECT_EQ(readBuffer[i], buffer[i]);
  }
}

TEST_F(VisaRegisterBasedLoopbackTest, DataWrittenWithMoveOut8_Peek8_ReadsData)
{
  map();
  const int testLength = 5;
  const int startingOffset = 11;
  ViUInt8 buffer[testLength] = { 0x01, 0x02, 0x00, 0x03, 0xFE };
  moveOut8(startingOffset, buffer, testLength);
  for (int i = 0; i < testLength; ++i) {
    EXPECT_EQ(buffer[i], peek8(startingOffset + i));
  }
  unmap();
}

TEST_F(VisaRegisterBasedLoopbackTest, DataWrittenWithMoveOut16_Peek16_ReadsData)
{
  map();
  const int testLength = 5;
  const int startingOffset = 14;
  ViUInt16 buffer[testLength] = { 0x0123, 0x0234, 0x00, 0x8675, 0xFEDC };
  moveOut16(startingOffset, buffer, testLength);
  for (int i = 0; i < testLength; ++i) {
    EXPECT_EQ(buffer[i], peek16(startingOffset + i * 2));
  }
  unmap();
}

TEST_F(VisaRegisterBasedLoopbackTest, DataWrittenWithMoveOut32_Peek32_ReadsData)
{
  map();
  const int testLength = 5;
  const int startingOffset = 16;
  ViUInt32 buffer[testLength] = { 0x01234567, 0x02340234, 0x00, 0x86754321, 0xC0FFEE };
  moveOut32(startingOffset, buffer, testLength);
  for (int i = 0; i < testLength; ++i) {
    EXPECT_EQ(buffer[i], peek32(startingOffset + i * 4));
  }
  unmap();
}

TEST_F(VisaRegisterBasedLoopbackTest, DataWrittenWithMoveOut64_Peek64_ReadsData)
{
  map();
  const int testLength = 5;
  const int startingOffset = 16;
  ViUInt64 buffer[testLength] = { 0x01234567DEADBEEF, 0x02340234, 0x00, 0x867543210ABCDEF, 0xC0FFEE };
  moveOut64(startingOffset, buffer, testLength);
  for (int i = 0; i < testLength; ++i) {
    EXPECT_EQ(buffer[i], peek64(startingOffset + i * 8));
  }
  unmap();
}

TEST_F(VisaRegisterBasedLoopbackTest, DataWrittenWithPoke8_MoveIn8_ReadsData)
{
  map();
  const int testLength = 5;
  const int startingOffset = 11;
  ViUInt8 buffer[testLength] = { 0x01, 0x02, 0x00, 0x03, 0xFE };
  for (int i = 0; i < testLength; ++i) {
    poke8(startingOffset + i, buffer[i]);
  }
  auto readBuffer = moveIn8(startingOffset, testLength);
  for (int i = 0; i < testLength; ++i) {
    EXPECT_EQ(readBuffer[i], buffer[i]);
  }
  unmap();
}

TEST_F(VisaRegisterBasedLoopbackTest, DataWrittenWithPoke16_MoveIn16_ReadsData)
{
  map();
  const int testLength = 5;
  const int startingOffset = 14;
  ViUInt16 buffer[testLength] = { 0x0123, 0x0234, 0x00, 0x8675, 0xFEDC };
  for (int i = 0; i < testLength; ++i) {
    poke16(startingOffset + i * 2, buffer[i]);
  }
  auto readBuffer = moveIn16(startingOffset, testLength);
  for (int i = 0; i < testLength; ++i) {
    EXPECT_EQ(readBuffer[i], buffer[i]);
  }
  unmap();
}

TEST_F(VisaRegisterBasedLoopbackTest, DataWrittenWithPoke32_MoveIn32_ReadsData)
{
  map();
  const int testLength = 5;
  const int startingOffset = 16;
  ViUInt32 buffer[testLength] = { 0x01234567, 0x02340234, 0x00, 0x86754321, 0xC0FFEE };
  for (int i = 0; i < testLength; ++i) {
    poke32(startingOffset + i * 4, buffer[i]);
  }
  auto readBuffer = moveIn32(startingOffset, testLength);
  for (int i = 0; i < testLength; ++i) {
    EXPECT_EQ(readBuffer[i], buffer[i]);
  }
  unmap();
}

TEST_F(VisaRegisterBasedLoopbackTest, DataWrittenWithPoke64_MoveIn64_ReadsData)
{
  map();
  const int testLength = 5;
  const int startingOffset = 16;
  ViUInt64 buffer[testLength] = { 0x01234567DEADBEEF, 0x02340234, 0x00, 0x867543210ABCDEF, 0xC0FFEE };
  for (int i = 0; i < testLength; ++i) {
    poke64(startingOffset + i * 8, buffer[i]);
  }
  auto readBuffer = moveIn64(startingOffset, testLength);
  for (int i = 0; i < testLength; ++i) {
    EXPECT_EQ(readBuffer[i], buffer[i]);
  }
  unmap();
}

}  // namespace system
}  // namespace tests
}  // namespace ni
