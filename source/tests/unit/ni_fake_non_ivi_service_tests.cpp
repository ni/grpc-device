#include <google/protobuf/util/time_util.h>
#include <grpcpp/impl/grpc_library.h>
#include <gtest/gtest.h>
#include <nifake_non_ivi/nifake_non_ivi_mock_library.h>
#include <nifake_non_ivi/nifake_non_ivi_service.h>
#include <server/session_resource_repository.h>

#include <iostream>
#include <numeric>
#include <string>

using namespace nifake_non_ivi_grpc;
using namespace ::testing;

bool operator==(const StructWithCoercion_struct& left, const StructWithCoercion& right)
{
  return left.first == right.first() && left.second == right.second() && left.third == right.third();
}
bool operator==(const StructWithCoercion_struct& left, const StructWithCoercion_struct& right)
{
  return left.first == right.first && left.second == right.second && left.third == right.third;
}

namespace ni {
namespace tests {
namespace unit {

MATCHER(CustomU16Data, "")
{
  myUInt16 const* write_data_array = std::get<0>(arg);
  return write_data_array[0] == 0 && write_data_array[1] == UINT16_MAX && write_data_array[2] == 16;
}

MATCHER(CustomI16Data, "")
{
  myInt16 const* write_data_array = std::get<1>(arg);
  return write_data_array[0] == 0 && write_data_array[1] == INT16_MAX && write_data_array[2] == INT16_MIN;
}

MATCHER(CustomI8Data, "")
{
  myInt8 const* write_data_array = std::get<2>(arg);
  return write_data_array[0] == 0 && write_data_array[1] == INT8_MAX && write_data_array[2] == INT8_MIN;
}

MATCHER(CustomU8Data, "")
{
  myUInt8 const* write_data_array = std::get<0>(arg);
  return write_data_array[0] == 0 && write_data_array[1] == UINT8_MAX && write_data_array[2] == 16;
}

void SetU16Data(Unused, myUInt16* u16_data, Unused, Unused, Unused, Unused)
{
  u16_data[0] = 0;
  u16_data[1] = UINT16_MAX;
  u16_data[2] = 16;
};

void SetI16Data(Unused, Unused, Unused, myInt16* i16_data, Unused, Unused)
{
  i16_data[0] = 0;
  i16_data[1] = INT16_MAX;
  i16_data[2] = INT16_MIN;
};

void SetI8Data(Unused, Unused, Unused, Unused, Unused, myInt8* i8_data)
{
  i8_data[0] = 0;
  i8_data[1] = INT8_MAX;
  i8_data[2] = INT8_MIN;
};

void SetU8Data(Unused, myUInt8* u8_data)
{
  u8_data[0] = 0;
  u8_data[1] = UINT8_MAX;
  u8_data[2] = 16;
}

void SetArraysByPtrData(int32* int32_data, myUInt16* u16_data, int32* size)
{
  int32_data[0] = -1;
  int32_data[1] = 1;
  int32_data[2] = 128;
  u16_data[0] = 0;
  u16_data[1] = UINT16_MAX;
  u16_data[2] = 16;
  *size = 3;
}

void SetSingleStructWithCoercionData(StructWithCoercion_struct* data, int index)
{
  switch (index) {
    case 0:
      data->first = 0;
      data->second = 0;
      data->third = 0;
      break;
    case 1:
      data->first = INT16_MAX;
      data->second = UINT16_MAX;
      data->third = INT8_MAX;
      break;
    case 2:
      data->first = INT16_MIN;
      data->second = 16;
      data->third = INT8_MIN;
      break;
    default:
      EXPECT_TRUE(false);
  }
}

void SetSingleStructWithCoercionData(StructWithCoercion* data, int index)
{
  switch (index) {
    case 0:
      data->set_first(0);
      data->set_second(0);
      data->set_third(0);
      break;
    case 1:
      data->set_first(INT16_MAX);
      data->set_second(UINT16_MAX);
      data->set_third(INT8_MAX);
      break;
    case 2:
      data->set_first(INT16_MIN);
      data->set_second(16);
      data->set_third(INT8_MIN);
      break;
    default:
      EXPECT_TRUE(false);
  }
}

void SetStructWithCoercionData(Unused, StructWithCoercion_struct* data)
{
  SetSingleStructWithCoercionData(&data[0], 0);
  SetSingleStructWithCoercionData(&data[1], 1);
  SetSingleStructWithCoercionData(&data[2], 2);
}

MATCHER(CustomStructWithCoercionData, "")
{
  StructWithCoercion_struct const* data_array = std::get<0>(arg);
  StructWithCoercion_struct expected_data[3];
  SetSingleStructWithCoercionData(&expected_data[0], 0);
  SetSingleStructWithCoercionData(&expected_data[1], 1);
  SetSingleStructWithCoercionData(&expected_data[2], 2);

  return expected_data[0] == data_array[0] && expected_data[1] == data_array[1] && expected_data[2] == data_array[2];
}

MATCHER_P(CVIAbsoluteTimeEq, lhs, "")
{
  return lhs.cviTime.msb == arg.cviTime.msb &&
      lhs.cviTime.lsb == arg.cviTime.lsb;
}

class NiFakeNonIviServiceTests : public ::testing::Test {
 public:
  using FakeResourceRepository = nidevice_grpc::SessionResourceRepository<FakeHandle>;
  nidevice_grpc::SessionRepository session_repository_;
  std::shared_ptr<FakeResourceRepository> resource_repository_;
  NiFakeNonIviMockLibrary library_;
  NiFakeNonIviService service_;

  NiFakeNonIviServiceTests(const nidevice_grpc::FeatureToggles& feature_toggles = {})
      : session_repository_(),
        resource_repository_(std::make_shared<FakeResourceRepository>(&session_repository_)),
        library_(),
        service_(&library_, resource_repository_, feature_toggles)
  {
  }

  virtual ~NiFakeNonIviServiceTests() {}

  uint32_t init(const std::string& session_name, FakeHandle handle)
  {
    EXPECT_CALL(library_, Init(StrEq(session_name.c_str()), _))
        .WillOnce(DoAll(SetArgPointee<1>(handle), Return(kDriverSuccess)));

    ::grpc::ServerContext context;
    InitRequest request;
    request.set_session_name(session_name.c_str());
    InitResponse response;

    service_.Init(&context, &request, &response);

    return response.handle().id();
  }

  uint32_t init_with_handle_name_as_session_name(const std::string& handle_name, FakeHandle handle)
  {
    EXPECT_CALL(library_, InitWithHandleNameAsSessionName(StrEq(handle_name.c_str()), _))
        .WillOnce(DoAll(SetArgPointee<1>(handle), Return(kDriverSuccess)));

    ::grpc::ServerContext context;
    InitWithHandleNameAsSessionNameRequest request;
    request.set_handle_name(handle_name.c_str());
    InitWithHandleNameAsSessionNameResponse response;

    service_.InitWithHandleNameAsSessionName(&context, &request, &response);

    return response.handle().id();
  }

  int32 close_with_expected_handle(uint32_t session_id, FakeHandle expected_closed_handle)
  {
    EXPECT_CALL(library_, Close(expected_closed_handle))
        .WillOnce(Return(kDriverSuccess));
    ::grpc::ServerContext context;
    CloseRequest request;
    request.mutable_handle()->set_id(session_id);
    CloseResponse response;
    service_.Close(&context, &request, &response);

    return response.status();
  }

  void setup_iota_with_custom_size()
  {
    auto set_iota_data = [](int32 size_one, int32 size_two, int32* data) {
      auto out_size = (size_one == -1) ? size_two : size_one + 1;
      std::iota(data, data + out_size, 0);
    };

    EXPECT_CALL(library_, IotaWithCustomSize(_, _, _))
        .WillOnce(DoAll(
            Invoke(set_iota_data),
            Return(kDriverSuccess)));
  }

  static void EXPECT_IOTA_OF_SIZE(IotaWithCustomSizeResponse response, size_t size)
  {
    std::vector<int32> expected(size);
    std::iota(expected.begin(), expected.end(), 0);
    std::vector<int32> actual{response.data().cbegin(), response.data().cend()};
    EXPECT_THAT(actual, ContainerEq(expected));
  }
};

TEST_F(NiFakeNonIviServiceTests, InitSession_CloseSession_ClosesHandleAndSucceeds)
{
  const FakeHandle kHandle = 1234UL;
  auto session = init("test", kHandle);
  EXPECT_NE(0, session);

  auto status = close_with_expected_handle(session, kHandle);

  EXPECT_EQ(kDriverSuccess, status);
}

TEST_F(NiFakeNonIviServiceTests, InitWithHandleNameAsSessionName_CloseSession_ClosesHandleAndSucceeds)
{
  const FakeHandle kHandle = 99999UL;
  auto session = init_with_handle_name_as_session_name("test", kHandle);
  EXPECT_NE(0, session);

  auto status = close_with_expected_handle(session, kHandle);

  EXPECT_EQ(kDriverSuccess, status);
}

TEST_F(NiFakeNonIviServiceTests, InputArraysWithNarrowIntegerTypes_U16DataGetsCoerced)
{
  EXPECT_CALL(library_, InputArraysWithNarrowIntegerTypes(_, _, _))
      .With(CustomU16Data())
      .Times(1);
  ::grpc::ServerContext context;
  InputArraysWithNarrowIntegerTypesRequest request;
  request.add_u16_array(0);
  request.add_u16_array(UINT16_MAX);
  request.add_u16_array(16);
  InputArraysWithNarrowIntegerTypesResponse response;

  service_.InputArraysWithNarrowIntegerTypes(&context, &request, &response);

  auto status = response.status();
  EXPECT_EQ(kDriverSuccess, status);
}

TEST_F(NiFakeNonIviServiceTests, InputArraysWithNarrowIntegerTypes_U16DataOutOfRange_ReturnsError)
{
  EXPECT_CALL(library_, InputArraysWithNarrowIntegerTypes(_, _, _))
      .Times(0);
  ::grpc::ServerContext context;
  InputArraysWithNarrowIntegerTypesRequest request;
  request.add_u16_array(UINT16_MAX + 1);
  InputArraysWithNarrowIntegerTypesResponse response;

  auto status = service_.InputArraysWithNarrowIntegerTypes(&context, &request, &response);

  EXPECT_EQ(grpc::StatusCode::OUT_OF_RANGE, status.error_code());
  EXPECT_THAT(status.error_message(), HasSubstr(std::to_string(UINT16_MAX + 1)));
}

TEST_F(NiFakeNonIviServiceTests, InputArraysWithNarrowIntegerTypes_I16DataGetsCoerced)
{
  EXPECT_CALL(library_, InputArraysWithNarrowIntegerTypes(_, _, _))
      .With(CustomI16Data())
      .Times(1);
  ::grpc::ServerContext context;
  InputArraysWithNarrowIntegerTypesRequest request;
  request.add_i16_array(0);
  request.add_i16_array(INT16_MAX);
  request.add_i16_array(INT16_MIN);
  InputArraysWithNarrowIntegerTypesResponse response;

  service_.InputArraysWithNarrowIntegerTypes(&context, &request, &response);

  auto status = response.status();
  EXPECT_EQ(kDriverSuccess, status);
}

TEST_F(NiFakeNonIviServiceTests, InputArraysWithNarrowIntegerTypes_I16DataOutOfRangeTooHigh_ReturnsError)
{
  EXPECT_CALL(library_, InputArraysWithNarrowIntegerTypes(_, _, _))
      .Times(0);

  ::grpc::ServerContext context;
  InputArraysWithNarrowIntegerTypesRequest request;
  request.add_i16_array(INT16_MAX + 1);
  InputArraysWithNarrowIntegerTypesResponse response;

  auto status = service_.InputArraysWithNarrowIntegerTypes(&context, &request, &response);
  EXPECT_EQ(grpc::StatusCode::OUT_OF_RANGE, status.error_code());
  EXPECT_THAT(status.error_message(), HasSubstr(std::to_string(INT16_MAX + 1)));
}

TEST_F(NiFakeNonIviServiceTests, InputArraysWithNarrowIntegerTypes_I16DataOutOfRangeTooLow_ReturnsError)
{
  EXPECT_CALL(library_, InputArraysWithNarrowIntegerTypes(_, _, _))
      .Times(0);

  ::grpc::ServerContext context;
  InputArraysWithNarrowIntegerTypesRequest request;
  request.add_i16_array(INT16_MIN - 1);
  InputArraysWithNarrowIntegerTypesResponse response;

  auto status = service_.InputArraysWithNarrowIntegerTypes(&context, &request, &response);
  EXPECT_EQ(grpc::StatusCode::OUT_OF_RANGE, status.error_code());
  EXPECT_THAT(status.error_message(), HasSubstr(std::to_string(INT16_MIN - 1)));
}

TEST_F(NiFakeNonIviServiceTests, InputArraysWithNarrowIntegerTypes_I8DataGetsCoerced)
{
  EXPECT_CALL(library_, InputArraysWithNarrowIntegerTypes(_, _, _))
      .With(CustomI8Data())
      .Times(1);
  ::grpc::ServerContext context;
  InputArraysWithNarrowIntegerTypesRequest request;
  request.add_i8_array(0);
  request.add_i8_array(INT8_MAX);
  request.add_i8_array(INT8_MIN);
  InputArraysWithNarrowIntegerTypesResponse response;

  service_.InputArraysWithNarrowIntegerTypes(&context, &request, &response);

  auto status = response.status();
  EXPECT_EQ(kDriverSuccess, status);
}

TEST_F(NiFakeNonIviServiceTests, InputArraysWithNarrowIntegerTypes_I8DataOutOfRangeTooHigh_ReturnsError)
{
  EXPECT_CALL(library_, InputArraysWithNarrowIntegerTypes(_, _, _))
      .Times(0);
  ::grpc::ServerContext context;
  InputArraysWithNarrowIntegerTypesRequest request;
  request.add_i8_array(INT8_MAX + 1);
  InputArraysWithNarrowIntegerTypesResponse response;

  auto status = service_.InputArraysWithNarrowIntegerTypes(&context, &request, &response);

  EXPECT_EQ(grpc::StatusCode::OUT_OF_RANGE, status.error_code());
  EXPECT_THAT(status.error_message(), HasSubstr(std::to_string(INT8_MAX + 1)));
}

TEST_F(NiFakeNonIviServiceTests, InputArraysWithNarrowIntegerTypes_I8DataOutOfRangeTooLow_ReturnsError)
{
  EXPECT_CALL(library_, InputArraysWithNarrowIntegerTypes(_, _, _))
      .Times(0);
  ::grpc::ServerContext context;
  InputArraysWithNarrowIntegerTypesRequest request;
  request.add_i8_array(INT8_MIN - 1);
  InputArraysWithNarrowIntegerTypesResponse response;

  auto status = service_.InputArraysWithNarrowIntegerTypes(&context, &request, &response);

  EXPECT_EQ(grpc::StatusCode::OUT_OF_RANGE, status.error_code());
  EXPECT_THAT(status.error_message(), HasSubstr(std::to_string(INT8_MIN - 1)));
}

TEST_F(NiFakeNonIviServiceTests, OutputArraysWithNarrowIntegerTypes_U16)
{
  ::grpc::ServerContext context;
  OutputArraysWithNarrowIntegerTypesRequest request;
  request.set_number_of_u16_samples(3);
  OutputArraysWithNarrowIntegerTypesResponse response;
  EXPECT_CALL(library_, OutputArraysWithNarrowIntegerTypes(_, _, _, _, _, _))
      .WillOnce(DoAll(
          Invoke(SetU16Data),
          Return(kDriverSuccess)));

  service_.OutputArraysWithNarrowIntegerTypes(&context, &request, &response);

  EXPECT_EQ(3, response.u16_data_size());
  EXPECT_EQ(0, response.u16_data().Get(0));
  EXPECT_EQ(UINT16_MAX, response.u16_data().Get(1));
  EXPECT_EQ(16, response.u16_data().Get(2));
  auto status = response.status();
  EXPECT_EQ(kDriverSuccess, status);
}

TEST_F(NiFakeNonIviServiceTests, OutputArraysWithNarrowIntegerTypes_I16)
{
  ::grpc::ServerContext context;
  OutputArraysWithNarrowIntegerTypesRequest request;
  request.set_number_of_i16_samples(3);
  OutputArraysWithNarrowIntegerTypesResponse response;
  EXPECT_CALL(library_, OutputArraysWithNarrowIntegerTypes(_, _, _, _, _, _))
      .WillOnce(DoAll(
          Invoke(SetI16Data),
          Return(kDriverSuccess)));

  service_.OutputArraysWithNarrowIntegerTypes(&context, &request, &response);

  EXPECT_EQ(3, response.i16_data_size());
  EXPECT_EQ(0, response.i16_data().Get(0));
  EXPECT_EQ(INT16_MAX, response.i16_data().Get(1));
  EXPECT_EQ(INT16_MIN, response.i16_data().Get(2));
  auto status = response.status();
  EXPECT_EQ(kDriverSuccess, status);
}

TEST_F(NiFakeNonIviServiceTests, OutputArraysWithNarrowIntegerTypes_I8)
{
  ::grpc::ServerContext context;
  OutputArraysWithNarrowIntegerTypesRequest request;
  request.set_number_of_i8_samples(3);
  OutputArraysWithNarrowIntegerTypesResponse response;
  EXPECT_CALL(library_, OutputArraysWithNarrowIntegerTypes(_, _, _, _, _, _))
      .WillOnce(DoAll(
          Invoke(SetI8Data),
          Return(kDriverSuccess)));

  service_.OutputArraysWithNarrowIntegerTypes(&context, &request, &response);

  EXPECT_EQ(3, response.i8_data_size());
  EXPECT_EQ(0, response.i8_data().Get(0));
  EXPECT_EQ(INT8_MAX, response.i8_data().Get(1));
  EXPECT_EQ(INT8_MIN, response.i8_data().Get(2));
  auto status = response.status();
  EXPECT_EQ(kDriverSuccess, status);
}

TEST_F(NiFakeNonIviServiceTests, InputArrayOfBytes)
{
  EXPECT_CALL(library_, InputArrayOfBytes(_))
      .With(CustomU8Data())
      .Times(1);
  ::grpc::ServerContext context;
  InputArrayOfBytesRequest request;
  request.mutable_u8_array()->push_back(0);
  request.mutable_u8_array()->push_back(UINT8_MAX);
  request.mutable_u8_array()->push_back(16);
  InputArrayOfBytesResponse response;

  service_.InputArrayOfBytes(&context, &request, &response);

  auto status = response.status();
  EXPECT_EQ(kDriverSuccess, status);
}

TEST_F(NiFakeNonIviServiceTests, OutputArrayOfBytes)
{
  EXPECT_CALL(library_, OutputArrayOfBytes(_, _))
      .WillOnce(DoAll(
          Invoke(SetU8Data),
          Return(kDriverSuccess)));
  ::grpc::ServerContext context;
  OutputArrayOfBytesRequest request;
  request.set_number_of_u8_samples(3);
  OutputArrayOfBytesResponse response;

  service_.OutputArrayOfBytes(&context, &request, &response);

  EXPECT_EQ(3, response.u8_data().size());
  EXPECT_EQ(0, (myUInt8)response.u8_data()[0]);
  EXPECT_EQ(UINT8_MAX, (myUInt8)response.u8_data()[1]);
  EXPECT_EQ(16, (myUInt8)response.u8_data()[2]);
  auto status = response.status();
  EXPECT_EQ(kDriverSuccess, status);
}

TEST_F(NiFakeNonIviServiceTests, IotaWithCustomSizeUsingFirstSizeOption_ReturnsIotaDataOfFirstSizePlusOne)
{
  const auto SIZE_ONE = 10;
  setup_iota_with_custom_size();
  ::grpc::ServerContext context;
  IotaWithCustomSizeRequest request;
  request.set_size_one(SIZE_ONE);
  request.set_size_two(100000);
  IotaWithCustomSizeResponse response;
  service_.IotaWithCustomSize(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_IOTA_OF_SIZE(response, SIZE_ONE + 1);
}

TEST_F(NiFakeNonIviServiceTests, IotaWithCustomSizeUsingSecondSizeOption_ReturnsIotaDataOfSecondSize)
{
  const auto SIZE_TWO = 20;
  setup_iota_with_custom_size();
  ::grpc::ServerContext context;
  IotaWithCustomSizeRequest request;
  request.set_size_one(-1);
  request.set_size_two(SIZE_TWO);
  IotaWithCustomSizeResponse response;

  service_.IotaWithCustomSize(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_IOTA_OF_SIZE(response, SIZE_TWO);
}

TEST_F(NiFakeNonIviServiceTests, InputVarArgs_OneArgumentPair)
{
  EXPECT_CALL(library_, InputVarArgs(StrEq("inputName"), StrEq("channel"), BEAUTIFUL_COLOR_PINK, 1.0, nullptr, BEAUTIFUL_COLOR_UNSPECIFIED, 0.0, nullptr, BEAUTIFUL_COLOR_UNSPECIFIED, 0.0, nullptr, BEAUTIFUL_COLOR_UNSPECIFIED, 0.0))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  InputVarArgsRequest request;
  request.set_input_name("inputName");
  auto arg = request.add_string_and_enums();
  arg->set_channel_name("channel");
  arg->set_color(BEAUTIFUL_COLOR_PINK);
  arg->set_power_up_state(1.0);
  InputVarArgsResponse response;

  service_.InputVarArgs(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceTests, InputVarArgs_TwoArgumentPairs)
{
  EXPECT_CALL(library_, InputVarArgs(StrEq("inputName"), StrEq("channel0"), BEAUTIFUL_COLOR_PINK, 1.0, StrEq("channel1"), BEAUTIFUL_COLOR_AQUA, 2.0, nullptr, BEAUTIFUL_COLOR_UNSPECIFIED, 0.0, nullptr, BEAUTIFUL_COLOR_UNSPECIFIED, 0.0))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  InputVarArgsRequest request;
  request.set_input_name("inputName");
  auto arg = request.add_string_and_enums();
  arg->set_channel_name("channel0");
  arg->set_color(BEAUTIFUL_COLOR_PINK);
  arg->set_power_up_state(1.0);
  arg = request.add_string_and_enums();
  arg->set_channel_name("channel1");
  arg->set_color(BEAUTIFUL_COLOR_AQUA);
  arg->set_power_up_state(2.0);
  InputVarArgsResponse response;

  service_.InputVarArgs(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceTests, InputVarArgs_ThreeArgumentPairs)
{
  EXPECT_CALL(library_, InputVarArgs(StrEq("inputName"), StrEq("channel0"), BEAUTIFUL_COLOR_PINK, 1.0, StrEq("channel1"), BEAUTIFUL_COLOR_AQUA, 2.0, StrEq("channel2"), BEAUTIFUL_COLOR_GREEN, 3.0, nullptr, BEAUTIFUL_COLOR_UNSPECIFIED, 0.0))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  InputVarArgsRequest request;
  request.set_input_name("inputName");
  auto arg = request.add_string_and_enums();
  arg->set_channel_name("channel0");
  arg->set_color(BEAUTIFUL_COLOR_PINK);
  arg->set_power_up_state(1.0);
  arg = request.add_string_and_enums();
  arg->set_channel_name("channel1");
  arg->set_color(BEAUTIFUL_COLOR_AQUA);
  arg->set_power_up_state(2.0);
  arg = request.add_string_and_enums();
  arg->set_channel_name("channel2");
  arg->set_color(BEAUTIFUL_COLOR_GREEN);
  arg->set_power_up_state(3.0);
  InputVarArgsResponse response;

  service_.InputVarArgs(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceTests, InputVarArgs_NoArgumentPairs)
{
  EXPECT_CALL(library_, InputVarArgs(_, _, _, _, _, _, _, _, _, _, _, _, _))
      .Times(0);
  ::grpc::ServerContext context;
  InputVarArgsRequest request;
  request.set_input_name("inputName");
  InputVarArgsResponse response;

  auto status = service_.InputVarArgs(&context, &request, &response);

  EXPECT_EQ(grpc::StatusCode::INVALID_ARGUMENT, status.error_code());
}

TEST_F(NiFakeNonIviServiceTests, InputVarArgs_FourArgumentPairs)
{
  EXPECT_CALL(library_, InputVarArgs(_, _, _, _, _, _, _, _, _, _, _, _, _))
      .Times(0);
  ::grpc::ServerContext context;
  InputVarArgsRequest request;
  request.set_input_name("inputName");
  for (auto i = 0; i < 4; i++) {
    request.add_string_and_enums();
  }
  InputVarArgsResponse response;

  auto status = service_.InputVarArgs(&context, &request, &response);

  EXPECT_EQ(grpc::StatusCode::INVALID_ARGUMENT, status.error_code());
}

TEST_F(NiFakeNonIviServiceTests, OutputVarArgs_OneArgumentPair)
{
  EXPECT_CALL(library_, OutputVarArgs(StrEq("inputName"), StrEq("channel"), _, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr))
      .WillOnce(DoAll(
          SetArgPointee<2>(BEAUTIFUL_COLOR_PINK),
          Return(kDriverSuccess)));
  ::grpc::ServerContext context;
  OutputVarArgsRequest request;
  request.set_input_name("inputName");
  request.add_channel_names("channel");
  OutputVarArgsResponse response;

  service_.OutputVarArgs(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(1, response.colors_size());
  EXPECT_EQ(BEAUTIFUL_COLOR_PINK, response.colors(0));
}

TEST_F(NiFakeNonIviServiceTests, OutputVarArgs_TwoArgumentPairs)
{
  EXPECT_CALL(library_, OutputVarArgs(StrEq("inputName"), StrEq("channel1"), _, StrEq("channel2"), _, nullptr, nullptr, nullptr, nullptr))
      .WillOnce(DoAll(
          SetArgPointee<2>(BEAUTIFUL_COLOR_PINK),
          SetArgPointee<4>(BEAUTIFUL_COLOR_AQUA),
          Return(kDriverSuccess)));
  ::grpc::ServerContext context;
  OutputVarArgsRequest request;
  request.set_input_name("inputName");
  request.add_channel_names("channel1");
  request.add_channel_names("channel2");
  OutputVarArgsResponse response;

  service_.OutputVarArgs(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(2, response.colors_size());
  EXPECT_EQ(BEAUTIFUL_COLOR_PINK, response.colors(0));
  EXPECT_EQ(BEAUTIFUL_COLOR_AQUA, response.colors(1));
}

TEST_F(NiFakeNonIviServiceTests, OutputVarArgs_ThreeArgumentPairs)
{
  EXPECT_CALL(library_, OutputVarArgs(StrEq("inputName"), StrEq("channel1"), _, StrEq("channel2"), _, StrEq("channel3"), _, nullptr, nullptr))
      .WillOnce(DoAll(
          SetArgPointee<2>(BEAUTIFUL_COLOR_PINK),
          SetArgPointee<4>(BEAUTIFUL_COLOR_AQUA),
          SetArgPointee<6>(BEAUTIFUL_COLOR_GREEN),
          Return(kDriverSuccess)));
  ::grpc::ServerContext context;
  OutputVarArgsRequest request;
  request.set_input_name("inputName");
  request.add_channel_names("channel1");
  request.add_channel_names("channel2");
  request.add_channel_names("channel3");
  OutputVarArgsResponse response;

  service_.OutputVarArgs(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(3, response.colors_size());
  EXPECT_EQ(BEAUTIFUL_COLOR_PINK, response.colors(0));
  EXPECT_EQ(BEAUTIFUL_COLOR_AQUA, response.colors(1));
  EXPECT_EQ(BEAUTIFUL_COLOR_GREEN, response.colors(2));
}

TEST_F(NiFakeNonIviServiceTests, OutputVarArgs_NoArgumentPairs)
{
  EXPECT_CALL(library_, OutputVarArgs(_, _, _, _, _, _, _, _, _))
      .Times(0);
  ::grpc::ServerContext context;
  OutputVarArgsRequest request;
  request.set_input_name("inputName");
  OutputVarArgsResponse response;

  auto status = service_.OutputVarArgs(&context, &request, &response);

  EXPECT_EQ(grpc::StatusCode::INVALID_ARGUMENT, status.error_code());
}

TEST_F(NiFakeNonIviServiceTests, OutputVarArgs_FourArgumentPairs)
{
  EXPECT_CALL(library_, OutputVarArgs(_, _, _, _, _, _, _, _, _))
      .Times(0);
  ::grpc::ServerContext context;
  OutputVarArgsRequest request;
  request.set_input_name("inputName");
  for (auto i = 0; i < 4; i++) {
    request.add_channel_names("channel");
  }
  OutputVarArgsResponse response;

  auto status = service_.OutputVarArgs(&context, &request, &response);

  EXPECT_EQ(grpc::StatusCode::INVALID_ARGUMENT, status.error_code());
}

const int64 SecondsFromCVI1904EpochTo1970Epoch = 2082844800LL;
TEST_F(NiFakeNonIviServiceTests, InputTimestamp_UnixEpoch)
{
  CVIAbsoluteTime timestamp;
  timestamp.cviTime.msb = SecondsFromCVI1904EpochTo1970Epoch;
  timestamp.cviTime.lsb = 0;
  EXPECT_CALL(library_, InputTimestamp(CVIAbsoluteTimeEq(timestamp)))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  InputTimestampRequest request;
  google::protobuf::Timestamp* timestamp_pb = request.mutable_when();
  timestamp_pb->set_seconds(0);
  timestamp_pb->set_nanos(0);
  InputTimestampResponse response;

  service_.InputTimestamp(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceTests, InputTimestamp_UnixEpochWithFractionalSeconds)
{
  CVIAbsoluteTime timestamp;
  timestamp.cviTime.msb = SecondsFromCVI1904EpochTo1970Epoch;
  timestamp.cviTime.lsb = 0x8000000000000000LL;
  EXPECT_CALL(library_, InputTimestamp(CVIAbsoluteTimeEq(timestamp)))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  InputTimestampRequest request;
  google::protobuf::Timestamp* timestamp_pb = request.mutable_when();
  timestamp_pb->set_seconds(0);
  // exactly .5 seconds
  timestamp_pb->set_nanos(500 * 1000 * 1000);
  InputTimestampResponse response;

  service_.InputTimestamp(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

// Determined from CVI:
// CVIAbsoluteTime msb: 3709898694
// UTC time string: "2021-07-23T15:24:54.00Z
CVIAbsoluteTime cviKnownTimestamp = {0, 3709898694LL};
const std::string cviKnownTimestampString = "2021-07-23T15:24:54.00Z";

TEST_F(NiFakeNonIviServiceTests, InputTimestamp_KnownValue)
{
  EXPECT_CALL(library_, InputTimestamp(CVIAbsoluteTimeEq(cviKnownTimestamp)))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  InputTimestampRequest request;
  google::protobuf::util::TimeUtil::FromString(cviKnownTimestampString, request.mutable_when());
  InputTimestampResponse response;

  service_.InputTimestamp(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceTests, OutputTimestamp_UnixEpoch)
{
  CVIAbsoluteTime timestamp;
  timestamp.cviTime.msb = SecondsFromCVI1904EpochTo1970Epoch;
  timestamp.cviTime.lsb = 0;
  EXPECT_CALL(library_, OutputTimestamp(_))
      .WillOnce(DoAll(SetArgPointee<0>(timestamp), Return(kDriverSuccess)));
  ::grpc::ServerContext context;
  OutputTimestampRequest request;
  OutputTimestampResponse response;

  service_.OutputTimestamp(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(0, response.when().seconds());
  EXPECT_EQ(0, response.when().nanos());
}

TEST_F(NiFakeNonIviServiceTests, OutputTimestamp_UnixEpochWithFractionalSeconds)
{
  CVIAbsoluteTime timestamp;
  timestamp.cviTime.msb = SecondsFromCVI1904EpochTo1970Epoch;
  timestamp.cviTime.lsb = 0x8000000000000000LL;
  EXPECT_CALL(library_, OutputTimestamp(_))
      .WillOnce(DoAll(SetArgPointee<0>(timestamp), Return(kDriverSuccess)));
  ::grpc::ServerContext context;
  OutputTimestampRequest request;
  OutputTimestampResponse response;

  service_.OutputTimestamp(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(0, response.when().seconds());
  EXPECT_EQ(500 * 1000 * 1000, response.when().nanos());
}

TEST_F(NiFakeNonIviServiceTests, OutputTimestamp_KnownValue)
{
  EXPECT_CALL(library_, OutputTimestamp(_))
      .WillOnce(DoAll(SetArgPointee<0>(cviKnownTimestamp), Return(kDriverSuccess)));
  ::grpc::ServerContext context;
  OutputTimestampRequest request;
  OutputTimestampResponse response;

  service_.OutputTimestamp(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
  google::protobuf::Timestamp timestamp;
  google::protobuf::util::TimeUtil::FromString(cviKnownTimestampString, &timestamp);
  EXPECT_EQ(timestamp, response.when());
}

TEST_F(NiFakeNonIviServiceTests, SetMarbleAttributeDouble_Succeeds)
{
  const auto ATTRIBUTE = MarbleDoubleAttributes::MARBLE_ATTRIBUTE_WEIGHT;
  const auto VALUE = 1.2345;
  EXPECT_CALL(library_, SetMarbleAttributeDouble(_, ATTRIBUTE, VALUE))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  SetMarbleAttributeDoubleRequest request;
  request.set_attribute(ATTRIBUTE);
  request.set_value(VALUE);
  SetMarbleAttributeDoubleResponse response;
  service_.SetMarbleAttributeDouble(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceTests, SetMarbleAttributeInt32_Succeeds)
{
  const auto ATTRIBUTE = MarbleInt32Attributes::MARBLE_ATTRIBUTE_COLOR;
  const auto VALUE = MarbleInt32AttributeValues::MARBLE_INT32_BEAUTIFUL_COLOR_GREEN;
  EXPECT_CALL(library_, SetMarbleAttributeInt32(_, ATTRIBUTE, VALUE))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  SetMarbleAttributeInt32Request request;
  request.set_attribute(ATTRIBUTE);
  request.set_value(VALUE);
  SetMarbleAttributeInt32Response response;
  service_.SetMarbleAttributeInt32(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceTests, SetMarbleAttributeInt32Raw_Succeeds)
{
  const auto ATTRIBUTE = MarbleInt32Attributes::MARBLE_ATTRIBUTE_COLOR;
  const auto VALUE = 9999;
  EXPECT_CALL(library_, SetMarbleAttributeInt32(_, ATTRIBUTE, VALUE))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  SetMarbleAttributeInt32Request request;
  request.set_attribute(ATTRIBUTE);
  request.set_value_raw(VALUE);
  SetMarbleAttributeInt32Response response;
  service_.SetMarbleAttributeInt32(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceTests, GetMarbleAttributeInt32Enum_ReturnsValueAndValueRaw)
{
  const auto ATTRIBUTE = MarbleInt32Attributes::MARBLE_ATTRIBUTE_COLOR;
  const auto VALUE = MarbleInt32AttributeValues::MARBLE_INT32_BEAUTIFUL_COLOR_AQUA;
  EXPECT_CALL(library_, GetMarbleAttributeInt32(_, ATTRIBUTE, _))
      .WillOnce(DoAll(SetArgPointee<2>(VALUE), Return(kDriverSuccess)));
  ::grpc::ServerContext context;
  GetMarbleAttributeInt32Request request;
  request.set_attribute(ATTRIBUTE);
  GetMarbleAttributeInt32Response response;
  service_.GetMarbleAttributeInt32(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(VALUE, response.value());
  EXPECT_EQ(VALUE, response.value_raw());
}

template <typename TValueEnum, typename TIterator>
auto convert_to_enum_vector(TIterator begin, TIterator end)
{
  auto vec = std::vector<TValueEnum>{};
  std::transform(
      begin,
      end,
      std::back_inserter(vec),
      [](auto x) { return static_cast<TValueEnum>(x); });
  return vec;
}

template <typename TValueEnum, typename TResponse>
auto get_value_enum_vector(const TResponse& response)
{
  // Repeated enums are just ints in the c++ generated code: cast/convert them.
  return convert_to_enum_vector<TValueEnum>(
      response.value().cbegin(),
      response.value().cend());
}

template <typename TRaw = int32, typename TResponse>
auto get_value_raw_vector(const TResponse& response)
{
  return std::vector<TRaw>{response.value_raw().cbegin(), response.value_raw().cend()};
}

TEST_F(NiFakeNonIviServiceTests, GetMarbleAttributeInt32ArrayNonEnum_ReturnsValueRawAndUnspecifiedValue)
{
  const auto ATTRIBUTE = MarbleInt32ArrayAttributes::MARBLE_ATTRIBUTE_TEN_RANDOM_NUMBERS;
  int VALUE[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
  EXPECT_CALL(library_, GetMarbleAttributeInt32Array(_, ATTRIBUTE, _))
      .WillOnce(DoAll(SetArrayArgument<2>(VALUE, VALUE + 10), Return(kDriverSuccess)));
  ::grpc::ServerContext context;
  GetMarbleAttributeInt32ArrayRequest request;
  request.set_attribute(ATTRIBUTE);
  GetMarbleAttributeInt32ArrayResponse response;
  service_.GetMarbleAttributeInt32Array(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
  auto expected_raw = std::vector<int32>(VALUE, VALUE + 10);
  auto raw_result = get_value_raw_vector(response);
  EXPECT_THAT(raw_result, ContainerEq(expected_raw));
  auto expected = std::vector<MarbleInt32AttributeValues>(10, MarbleInt32AttributeValues::MARBLE_INT32_UNSPECIFIED);
  auto result = get_value_enum_vector<MarbleInt32AttributeValues>(response);
  EXPECT_THAT(result, ContainerEq(expected));
}

TEST_F(NiFakeNonIviServiceTests, GetMarbleAttributeInt32NonEnum_ReturnsValueRawAndUnspecifiedValue)
{
  const auto ATTRIBUTE = MarbleInt32Attributes::MARBLE_ATTRIBUTE_NUMBER_OF_FAILED_ATTEMPTS;
  const auto VALUE = 1000;
  EXPECT_CALL(library_, GetMarbleAttributeInt32(_, ATTRIBUTE, _))
      .WillOnce(DoAll(SetArgPointee<2>(VALUE), Return(kDriverSuccess)));
  ::grpc::ServerContext context;
  GetMarbleAttributeInt32Request request;
  request.set_attribute(ATTRIBUTE);
  GetMarbleAttributeInt32Response response;
  service_.GetMarbleAttributeInt32(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(MarbleInt32AttributeValues::MARBLE_INT32_UNSPECIFIED, response.value());
  EXPECT_EQ(VALUE, response.value_raw());
}

TEST_F(NiFakeNonIviServiceTests, GetMarbleAttributeInt32ArrayEnum_ReturnsValueAndValueRaw)
{
  const auto ATTRIBUTE = MarbleInt32ArrayAttributes::MARBLE_ATTRIBUTE_TEN_FAVORITE_COLORS;
  int VALUE[] = {
      MarbleInt32AttributeValues::MARBLE_INT32_BEAUTIFUL_COLOR_BLACK,
      MarbleInt32AttributeValues::MARBLE_INT32_BEAUTIFUL_COLOR_BLACK,
      MarbleInt32AttributeValues::MARBLE_INT32_BEAUTIFUL_COLOR_BLACK,
      MarbleInt32AttributeValues::MARBLE_INT32_BEAUTIFUL_COLOR_BLACK,
      MarbleInt32AttributeValues::MARBLE_INT32_BEAUTIFUL_COLOR_AQUA,
      MarbleInt32AttributeValues::MARBLE_INT32_BEAUTIFUL_COLOR_BLACK,
      MarbleInt32AttributeValues::MARBLE_INT32_BEAUTIFUL_COLOR_BLACK,
      MarbleInt32AttributeValues::MARBLE_INT32_BEAUTIFUL_COLOR_BLACK,
      MarbleInt32AttributeValues::MARBLE_INT32_BEAUTIFUL_COLOR_BLACK,
      MarbleInt32AttributeValues::MARBLE_INT32_BEAUTIFUL_COLOR_PINK,
  };
  EXPECT_CALL(library_, GetMarbleAttributeInt32Array(_, ATTRIBUTE, _))
      .WillOnce(DoAll(SetArrayArgument<2>(VALUE, VALUE + 10), Return(kDriverSuccess)));
  ::grpc::ServerContext context;
  GetMarbleAttributeInt32ArrayRequest request;
  request.set_attribute(ATTRIBUTE);
  GetMarbleAttributeInt32ArrayResponse response;
  service_.GetMarbleAttributeInt32Array(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
  auto expected_raw = std::vector<int32>(VALUE, VALUE + 10);
  auto raw_result = get_value_raw_vector(response);
  EXPECT_THAT(raw_result, ContainerEq(expected_raw));
  auto expected = convert_to_enum_vector<MarbleInt32AttributeValues>(VALUE, VALUE + 10);
  auto result = get_value_enum_vector<MarbleInt32AttributeValues>(response);
  EXPECT_THAT(result, ContainerEq(expected));
}

TEST_F(NiFakeNonIviServiceTests, ResetMarbleAttribute_Succeeds)
{
  const auto ATTRIBUTE = MarbleResetAttributes::MARBLE_RESET_ATTRIBUTE_WEIGHT;
  EXPECT_CALL(library_, ResetMarbleAttribute(_, ATTRIBUTE))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  ResetMarbleAttributeRequest request;
  request.set_attribute(ATTRIBUTE);
  ResetMarbleAttributeResponse response;
  service_.ResetMarbleAttribute(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceTests, SetMarbleAttributeRaw_PassesAttributeAndValueToLibrary)
{
  const auto RAW_ATTRIBUTE = static_cast<int32>(MarbleDoubleAttributes::MARBLE_ATTRIBUTE_WEIGHT);
  const auto DOUBLE_VALUE = 1.234;
  EXPECT_CALL(library_, SetMarbleAttributeDouble(_, RAW_ATTRIBUTE, DOUBLE_VALUE))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  SetMarbleAttributeDoubleRequest request;
  request.set_attribute_raw(RAW_ATTRIBUTE);
  request.set_value(DOUBLE_VALUE);
  SetMarbleAttributeDoubleResponse response;
  service_.SetMarbleAttributeDouble(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceTests, SetMarbleAttributeRawWithInvalidAttribute_PassesZeroAttributeToLibrary)
{
  const auto RAW_ATTRIBUTE = 9999;
  const auto DOUBLE_VALUE = 1.234;
  EXPECT_CALL(library_, SetMarbleAttributeDouble(_, 0, DOUBLE_VALUE))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  SetMarbleAttributeDoubleRequest request;
  request.set_attribute_raw(RAW_ATTRIBUTE);
  request.set_value(DOUBLE_VALUE);
  SetMarbleAttributeDoubleResponse response;
  service_.SetMarbleAttributeDouble(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

struct NiFakeNonIviServiceAllowUndefinedAttributesTests : public NiFakeNonIviServiceTests {
  NiFakeNonIviServiceAllowUndefinedAttributesTests()
      : NiFakeNonIviServiceTests(
            nidevice_grpc::FeatureToggles({{"nifake_non_ivi.allow_undefined_attributes", true}}))
  {
  }
};

TEST_F(NiFakeNonIviServiceAllowUndefinedAttributesTests, SetMarbleAttributeRawWithInvalidAttribute_PassesRawAttributeToLibrary)
{
  const auto RAW_ATTRIBUTE = 9999;
  const auto DOUBLE_VALUE = 1.234;
  EXPECT_CALL(library_, SetMarbleAttributeDouble(_, RAW_ATTRIBUTE, DOUBLE_VALUE))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  SetMarbleAttributeDoubleRequest request;
  request.set_attribute_raw(RAW_ATTRIBUTE);
  request.set_value(DOUBLE_VALUE);
  SetMarbleAttributeDoubleResponse response;
  service_.SetMarbleAttributeDouble(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceAllowUndefinedAttributesTests, SetMarbleAttributeWithTypeCastedInvalidAttribute_PassesZeroAttributeToLibrary)
{
  const auto CASTED_INVALID_ATTRIBUTE = static_cast<MarbleDoubleAttributes>(9999);
  const auto DOUBLE_VALUE = 1.234;
  EXPECT_CALL(library_, SetMarbleAttributeDouble(_, 0, DOUBLE_VALUE))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  SetMarbleAttributeDoubleRequest request;
  request.set_attribute(CASTED_INVALID_ATTRIBUTE);
  request.set_value(DOUBLE_VALUE);
  SetMarbleAttributeDoubleResponse response;
  service_.SetMarbleAttributeDouble(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceAllowUndefinedAttributesTests, GetMarbleAttributeRawWithInvalidAttribute_PassesRawAttributeToLibrary)
{
  const auto RAW_ATTRIBUTE = 9999;
  EXPECT_CALL(library_, GetMarbleAttributeDouble(_, RAW_ATTRIBUTE, _))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  GetMarbleAttributeDoubleRequest request;
  request.set_attribute_raw(RAW_ATTRIBUTE);
  GetMarbleAttributeDoubleResponse response;
  service_.GetMarbleAttributeDouble(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceAllowUndefinedAttributesTests, GetMarbleAttributeWithTypeCastedInvalidAttribute_PassesZeroAttributeToLibrary)
{
  const auto CASTED_INVALID_ATTRIBUTE = static_cast<MarbleDoubleAttributes>(9999);
  EXPECT_CALL(library_, GetMarbleAttributeDouble(_, 0, _))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  GetMarbleAttributeDoubleRequest request;
  request.set_attribute(CASTED_INVALID_ATTRIBUTE);
  GetMarbleAttributeDoubleResponse response;
  service_.GetMarbleAttributeDouble(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceAllowUndefinedAttributesTests, ResetMarbleAttributeRawWithInvalidAttribute_PassesRawAttributeToLibrary)
{
  const auto RAW_ATTRIBUTE = 9999;
  EXPECT_CALL(library_, ResetMarbleAttribute(_, RAW_ATTRIBUTE))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  ResetMarbleAttributeRequest request;
  request.set_attribute_raw(RAW_ATTRIBUTE);
  ResetMarbleAttributeResponse response;
  service_.ResetMarbleAttribute(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceAllowUndefinedAttributesTests, ResetMarbleAttributeWithTypeCastedInvalidAttribute_PassesZeroAttributeToLibrary)
{
  const auto CASTED_INVALID_ATTRIBUTE = static_cast<MarbleResetAttributes>(9999);
  EXPECT_CALL(library_, ResetMarbleAttribute(_, 0))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  ResetMarbleAttributeRequest request;
  request.set_attribute(CASTED_INVALID_ATTRIBUTE);
  ResetMarbleAttributeResponse response;
  service_.ResetMarbleAttribute(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceTests, SetColors_PassesColorsArrayToLibrary)
{
  const auto COLORS = std::vector<BeautifulColor>{
      BeautifulColor::BEAUTIFUL_COLOR_AQUA,
      BeautifulColor::BEAUTIFUL_COLOR_GREEN,
      BeautifulColor::BEAUTIFUL_COLOR_PINK};
  EXPECT_CALL(library_, SetColors(_, _))
      .With(Args<0, 1>(ElementsAreArray(COLORS.data(), COLORS.size())))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  SetColorsRequest request;
  request.mutable_colors()->CopyFrom({COLORS.begin(), COLORS.end()});
  request.set_size(static_cast<int32>(COLORS.size()));
  SetColorsResponse response;
  service_.SetColors(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

struct NiFakeNonIviServiceEnabledToggleTests : public NiFakeNonIviServiceTests {
  NiFakeNonIviServiceEnabledToggleTests()
      : NiFakeNonIviServiceTests(
            nidevice_grpc::FeatureToggles({{"nifake_non_ivi", true}}))
  {
  }
};

TEST_F(NiFakeNonIviServiceEnabledToggleTests, UnreleasedServiceWithToggleEnabled_IsEnabled_ReturnsTrue)
{
  EXPECT_TRUE(service_.is_enabled());
}

TEST_F(NiFakeNonIviServiceTests, UnreleasedServiceWithNoToggles_IsEnabled_ReturnsFalse)
{
  EXPECT_FALSE(service_.is_enabled());
}

TEST_F(NiFakeNonIviServiceTests, GetStructsWithCoercion_ReturnsInRangeData)
{
  ::grpc::ServerContext context;
  GetStructsWithCoercionRequest request;
  request.set_number_of_structs(3);
  GetStructsWithCoercionResponse response;
  EXPECT_CALL(library_, GetStructsWithCoercion(_, _))
      .WillOnce(DoAll(
          Invoke(SetStructWithCoercionData),
          Return(kDriverSuccess)));

  service_.GetStructsWithCoercion(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(3, response.structs().size());
  EXPECT_EQ(3, response.structs_size());
  StructWithCoercion_struct expected_struct;
  SetSingleStructWithCoercionData(&expected_struct, 0);
  EXPECT_EQ(expected_struct, response.structs(0));
  EXPECT_EQ(expected_struct, response.structs()[0]);
  SetSingleStructWithCoercionData(&expected_struct, 1);
  EXPECT_EQ(expected_struct, response.structs(1));
  EXPECT_EQ(expected_struct, response.structs()[1]);
  SetSingleStructWithCoercionData(&expected_struct, 2);
  EXPECT_EQ(expected_struct, response.structs(2));
  EXPECT_EQ(expected_struct, response.structs()[2]);
}

TEST_F(NiFakeNonIviServiceTests, SetStructsWithCoercion_DataGetsCoerced)
{
  EXPECT_CALL(library_, SetStructsWithCoercion(_))
      .With(CustomStructWithCoercionData())
      .Times(1);
  ::grpc::ServerContext context;
  SetStructsWithCoercionRequest request;
  SetSingleStructWithCoercionData(request.add_structs(), 0);
  SetSingleStructWithCoercionData(request.add_structs(), 1);
  SetSingleStructWithCoercionData(request.add_structs(), 2);
  SetStructsWithCoercionResponse response;

  service_.SetStructsWithCoercion(&context, &request, &response);

  auto status = response.status();
  EXPECT_EQ(kDriverSuccess, status);
}

TEST_F(NiFakeNonIviServiceTests, SetStructsWithCoercion_TooLargeInt16_Error)
{
  EXPECT_CALL(library_, SetStructsWithCoercion(_))
      .Times(0);
  ::grpc::ServerContext context;
  SetStructsWithCoercionRequest request;
  SetSingleStructWithCoercionData(request.add_structs(), 0);
  SetSingleStructWithCoercionData(request.add_structs(), 1);
  SetSingleStructWithCoercionData(request.add_structs(), 2);
  request.mutable_structs(1)->set_first(INT16_MAX + 1);
  SetStructsWithCoercionResponse response;

  auto status = service_.SetStructsWithCoercion(&context, &request, &response);

  EXPECT_EQ(grpc::StatusCode::OUT_OF_RANGE, status.error_code());
  EXPECT_THAT(status.error_message(), HasSubstr(std::to_string(INT16_MAX + 1)));
}

TEST_F(NiFakeNonIviServiceTests, SetStructsWithCoercion_TooSmallInt16_Error)
{
  EXPECT_CALL(library_, SetStructsWithCoercion(_))
      .Times(0);
  ::grpc::ServerContext context;
  SetStructsWithCoercionRequest request;
  SetSingleStructWithCoercionData(request.add_structs(), 0);
  SetSingleStructWithCoercionData(request.add_structs(), 1);
  SetSingleStructWithCoercionData(request.add_structs(), 2);
  request.mutable_structs(1)->set_first(INT16_MIN - 1);
  SetStructsWithCoercionResponse response;

  auto status = service_.SetStructsWithCoercion(&context, &request, &response);

  EXPECT_EQ(grpc::StatusCode::OUT_OF_RANGE, status.error_code());
  EXPECT_THAT(status.error_message(), HasSubstr(std::to_string(INT16_MIN - 1)));
}

TEST_F(NiFakeNonIviServiceTests, SetStructsWithCoercion_TooLargeUInt16_Error)
{
  EXPECT_CALL(library_, SetStructsWithCoercion(_))
      .Times(0);
  ::grpc::ServerContext context;
  SetStructsWithCoercionRequest request;
  SetSingleStructWithCoercionData(request.add_structs(), 0);
  SetSingleStructWithCoercionData(request.add_structs(), 1);
  SetSingleStructWithCoercionData(request.add_structs(), 2);
  request.mutable_structs(1)->set_second(UINT16_MAX + 1);
  SetStructsWithCoercionResponse response;

  auto status = service_.SetStructsWithCoercion(&context, &request, &response);

  EXPECT_EQ(grpc::StatusCode::OUT_OF_RANGE, status.error_code());
  EXPECT_THAT(status.error_message(), HasSubstr(std::to_string(UINT16_MAX + 1)));
}

TEST_F(NiFakeNonIviServiceTests, SetStructsWithCoercion_TooLargeInt8_Error)
{
  EXPECT_CALL(library_, SetStructsWithCoercion(_))
      .Times(0);
  ::grpc::ServerContext context;
  SetStructsWithCoercionRequest request;
  SetSingleStructWithCoercionData(request.add_structs(), 0);
  SetSingleStructWithCoercionData(request.add_structs(), 1);
  SetSingleStructWithCoercionData(request.add_structs(), 2);
  request.mutable_structs(1)->set_third(INT8_MAX + 1);
  SetStructsWithCoercionResponse response;

  auto status = service_.SetStructsWithCoercion(&context, &request, &response);

  EXPECT_EQ(grpc::StatusCode::OUT_OF_RANGE, status.error_code());
  EXPECT_THAT(status.error_message(), HasSubstr(std::to_string(INT8_MAX + 1)));
}

TEST_F(NiFakeNonIviServiceTests, SetStructsWithCoercion_TooSmallInt8_Error)
{
  EXPECT_CALL(library_, SetStructsWithCoercion(_))
      .Times(0);
  ::grpc::ServerContext context;
  SetStructsWithCoercionRequest request;
  SetSingleStructWithCoercionData(request.add_structs(), 0);
  SetSingleStructWithCoercionData(request.add_structs(), 1);
  SetSingleStructWithCoercionData(request.add_structs(), 2);
  request.mutable_structs(1)->set_third(INT8_MIN - 1);
  SetStructsWithCoercionResponse response;

  auto status = service_.SetStructsWithCoercion(&context, &request, &response);

  EXPECT_EQ(grpc::StatusCode::OUT_OF_RANGE, status.error_code());
  EXPECT_THAT(status.error_message(), HasSubstr(std::to_string(INT8_MIN - 1)));
}

void ExpectOutputArraysWithPassedInByPtrMechanismResponseData(const OutputArraysWithPassedInByPtrMechanismResponse& response)
{
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(3, response.i32_data_size());
  EXPECT_EQ(3, response.i32_data().size());
  EXPECT_EQ(-1, response.i32_data(0));
  EXPECT_EQ(1, response.i32_data(1));
  EXPECT_EQ(128, response.i32_data(2));
  EXPECT_EQ(3, response.u16_data_size());
  EXPECT_EQ(3, response.u16_data().size());
  EXPECT_EQ(0, response.u16_data(0));
  EXPECT_EQ(UINT16_MAX, response.u16_data(1));
  EXPECT_EQ(16, response.u16_data(2));
}

TEST_F(NiFakeNonIviServiceTests, OutputArraysWithPassedInByPtrMechanism_SizeMatches_ArraysReturnedAreThatSize)
{
  EXPECT_CALL(library_, OutputArraysWithPassedInByPtrMechanism(_, _, Pointee(3)))
      .WillOnce(DoAll(
          Invoke(SetArraysByPtrData),
          Return(kDriverSuccess)));
  ::grpc::ServerContext context;
  OutputArraysWithPassedInByPtrMechanismRequest request;
  request.set_array_size(3);
  OutputArraysWithPassedInByPtrMechanismResponse response;

  service_.OutputArraysWithPassedInByPtrMechanism(&context, &request, &response);

  ExpectOutputArraysWithPassedInByPtrMechanismResponseData(response);
}

TEST_F(NiFakeNonIviServiceTests, OutputArraysWithPassedInByPtrMechanism_SizeIsTooBig_ArraysReturnedAreShrunkToCorrectSize)
{
  EXPECT_CALL(library_, OutputArraysWithPassedInByPtrMechanism(_, _, Pointee(5)))
      .WillOnce(DoAll(
          Invoke(SetArraysByPtrData),
          Return(kDriverSuccess)));
  ::grpc::ServerContext context;
  OutputArraysWithPassedInByPtrMechanismRequest request;
  request.set_array_size(5);
  OutputArraysWithPassedInByPtrMechanismResponse response;

  service_.OutputArraysWithPassedInByPtrMechanism(&context, &request, &response);

  ExpectOutputArraysWithPassedInByPtrMechanismResponseData(response);
}

TEST_F(NiFakeNonIviServiceTests, OutputArraysWithPassedInByPtrMechanism_SizeIsTooSmall_ReturnsError)
{
  const int32 SOME_ERROR = 10;
  EXPECT_CALL(library_, OutputArraysWithPassedInByPtrMechanism(_, _, Pointee(5)))
      .WillOnce(
          Return(SOME_ERROR));
  ::grpc::ServerContext context;
  OutputArraysWithPassedInByPtrMechanismRequest request;
  request.set_array_size(5);
  OutputArraysWithPassedInByPtrMechanismResponse response;

  service_.OutputArraysWithPassedInByPtrMechanism(&context, &request, &response);

  EXPECT_EQ(SOME_ERROR, response.status());
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
