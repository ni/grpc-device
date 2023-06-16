#include <google/protobuf/util/time_util.h>
#include <grpcpp/impl/grpc_library.h>
#include <gtest/gtest.h>
#include <nifake_non_ivi/nifake_non_ivi_mock_library.h>
#include <nifake_non_ivi/nifake_non_ivi_service.h>
#include <server/feature_toggles.h>
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
  using SecondaryResourceRepository = nidevice_grpc::SessionResourceRepository<SecondarySessionHandle>;
  using FakeCrossDriverResourceRepository = nidevice_grpc::SessionResourceRepository<FakeCrossDriverHandle>;
  std::shared_ptr<nidevice_grpc::SessionRepository> session_repository_;
  std::shared_ptr<nidevice_grpc::SessionRepository> secondary_session_repository_;
  std::shared_ptr<FakeCrossDriverResourceRepository> cross_driver_resource_repository_;
  std::shared_ptr<FakeResourceRepository> resource_repository_;
  std::shared_ptr<SecondaryResourceRepository> secondary_resource_repository_;
  std::shared_ptr<NiFakeNonIviMockLibrary> library_;
  NiFakeNonIviService service_;

  NiFakeNonIviServiceTests(const nidevice_grpc::FeatureToggles& feature_toggles = {})
      : session_repository_(std::make_shared<nidevice_grpc::SessionRepository>()),
        secondary_session_repository_(std::make_shared<nidevice_grpc::SessionRepository>()),
        cross_driver_resource_repository_(std::make_shared<FakeCrossDriverResourceRepository>(session_repository_)),
        resource_repository_(std::make_shared<FakeResourceRepository>(session_repository_)),
        secondary_resource_repository_(std::make_shared<SecondaryResourceRepository>(secondary_session_repository_)),
        library_(std::make_shared<NiFakeNonIviMockLibrary>()),
        service_(
            library_,
            resource_repository_,
            secondary_resource_repository_,
            cross_driver_resource_repository_,
            feature_toggles)
  {
  }

  virtual ~NiFakeNonIviServiceTests() {}

  std::string init(const std::string& session_name, FakeHandle handle)
  {
    EXPECT_CALL(*library_, Init(StrEq(session_name.c_str()), _))
        .WillOnce(DoAll(SetArgPointee<1>(handle), Return(kDriverSuccess)));

    ::grpc::ServerContext context;
    InitRequest request;
    request.set_session_name(session_name);
    InitResponse response;

    service_.Init(&context, &request, &response);

    return response.handle().name();
  }

  std::string init_secondary_session(const std::string& session_name, SecondarySessionHandle handle)
  {
    EXPECT_CALL(*library_, InitSecondarySession(_))
        .WillOnce(DoAll(SetArgPointee<0>(handle), Return(kDriverSuccess)));

    ::grpc::ServerContext context;
    InitSecondarySessionRequest request;
    request.set_session_name(session_name.c_str());
    InitSecondarySessionResponse response;

    service_.InitSecondarySession(&context, &request, &response);

    return response.secondary_session_handle().name();
  }

  std::string init_with_handle_name_as_session_name(const std::string& handle_name, FakeHandle handle)
  {
    EXPECT_CALL(*library_, InitWithHandleNameAsSessionName(StrEq(handle_name.c_str()), _))
        .WillOnce(DoAll(SetArgPointee<1>(handle), Return(kDriverSuccess)));

    ::grpc::ServerContext context;
    InitWithHandleNameAsSessionNameRequest request;
    request.set_handle_name(handle_name.c_str());
    InitWithHandleNameAsSessionNameResponse response;

    service_.InitWithHandleNameAsSessionName(&context, &request, &response);

    return response.handle().name();
  }

  int32 close_secondary_session_with_expected_handle(std::string session_name, SecondarySessionHandle expected_closed_handle)
  {
    EXPECT_CALL(*library_, CloseSecondarySession(expected_closed_handle))
        .WillOnce(Return(kDriverSuccess));
    ::grpc::ServerContext context;
    CloseSecondarySessionRequest request;
    request.mutable_secondary_session_handle()->set_name(session_name);
    CloseSecondarySessionResponse response;
    service_.CloseSecondarySession(&context, &request, &response);

    return response.status();
  }

  int32 close_with_expected_handle(std::string session_name, FakeHandle expected_closed_handle)
  {
    EXPECT_CALL(*library_, Close(expected_closed_handle))
        .WillOnce(Return(kDriverSuccess));
    ::grpc::ServerContext context;
    CloseRequest request;
    request.mutable_handle()->set_name(session_name);
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

    EXPECT_CALL(*library_, IotaWithCustomSize(_, _, _))
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

TEST_F(NiFakeNonIviServiceTests, InitSecondarySession_AddsSessionHandleToSecondaryRepository)
{
  const SecondarySessionHandle kHandle = 1234UL;
  auto session = init_secondary_session("test", kHandle);

  EXPECT_NE("", session);
  EXPECT_EQ(kHandle, secondary_resource_repository_->access_session(session));
}

TEST_F(NiFakeNonIviServiceTests, InitSecondarySession_CloseSecondarySession_ClosesSecondarySession)
{
  const SecondarySessionHandle kHandle = 1234UL;
  auto session = init_secondary_session("test", kHandle);

  EXPECT_NE("", session);
  EXPECT_EQ(kDriverSuccess, close_secondary_session_with_expected_handle(session, kHandle));
}

TEST_F(NiFakeNonIviServiceTests, InitSession_CloseSession_ClosesHandleAndSucceeds)
{
  const FakeHandle kHandle = 1234UL;
  auto session = init("test", kHandle);
  EXPECT_NE("", session);

  auto status = close_with_expected_handle(session, kHandle);

  EXPECT_EQ(kDriverSuccess, status);
}

TEST_F(NiFakeNonIviServiceTests, InitWithHandleNameAsSessionName_CloseSession_ClosesHandleAndSucceeds)
{
  const FakeHandle kHandle = 99999UL;
  auto session = init_with_handle_name_as_session_name("test", kHandle);
  EXPECT_NE("", session);

  auto status = close_with_expected_handle(session, kHandle);

  EXPECT_EQ(kDriverSuccess, status);
}

TEST_F(NiFakeNonIviServiceTests, InputArraysWithNarrowIntegerTypes_U16DataGetsCoerced)
{
  EXPECT_CALL(*library_, InputArraysWithNarrowIntegerTypes(_, _, _))
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
  EXPECT_CALL(*library_, InputArraysWithNarrowIntegerTypes(_, _, _))
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
  EXPECT_CALL(*library_, InputArraysWithNarrowIntegerTypes(_, _, _))
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
  EXPECT_CALL(*library_, InputArraysWithNarrowIntegerTypes(_, _, _))
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
  EXPECT_CALL(*library_, InputArraysWithNarrowIntegerTypes(_, _, _))
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
  EXPECT_CALL(*library_, InputArraysWithNarrowIntegerTypes(_, _, _))
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
  EXPECT_CALL(*library_, InputArraysWithNarrowIntegerTypes(_, _, _))
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
  EXPECT_CALL(*library_, InputArraysWithNarrowIntegerTypes(_, _, _))
      .Times(0);
  ::grpc::ServerContext context;
  InputArraysWithNarrowIntegerTypesRequest request;
  request.add_i8_array(INT8_MIN - 1);
  InputArraysWithNarrowIntegerTypesResponse response;

  auto status = service_.InputArraysWithNarrowIntegerTypes(&context, &request, &response);

  EXPECT_EQ(grpc::StatusCode::OUT_OF_RANGE, status.error_code());
  EXPECT_THAT(status.error_message(), HasSubstr(std::to_string(INT8_MIN - 1)));
}

TEST_F(NiFakeNonIviServiceTests, ScalarsWithNarrowIntegerTypes_I8DataOutOfRangeTooLow_ReturnsError)
{
  EXPECT_CALL(*library_, InputArraysWithNarrowIntegerTypes(_, _, _))
      .Times(0);
  ::grpc::ServerContext context;
  ScalarsWithNarrowIntegerTypesRequest request;
  request.set_i8(INT8_MIN - 1);
  ScalarsWithNarrowIntegerTypesResponse response;
  auto status = service_.ScalarsWithNarrowIntegerTypes(&context, &request, &response);

  EXPECT_EQ(grpc::StatusCode::OUT_OF_RANGE, status.error_code());
  EXPECT_THAT(status.error_message(), HasSubstr(std::to_string(INT8_MIN - 1)));
}

TEST_F(NiFakeNonIviServiceTests, ScalarsWithNarrowIntegerTypes_I16DataOutOfRangeTooHigh_ReturnsError)
{
  EXPECT_CALL(*library_, InputArraysWithNarrowIntegerTypes(_, _, _))
      .Times(0);
  ::grpc::ServerContext context;
  ScalarsWithNarrowIntegerTypesRequest request;
  request.set_i16(INT16_MAX + 1);
  ScalarsWithNarrowIntegerTypesResponse response;
  auto status = service_.ScalarsWithNarrowIntegerTypes(&context, &request, &response);

  EXPECT_EQ(grpc::StatusCode::OUT_OF_RANGE, status.error_code());
  EXPECT_THAT(status.error_message(), HasSubstr(std::to_string(INT16_MAX + 1)));
}

TEST_F(NiFakeNonIviServiceTests, ScalarsWithNarrowIntegerTypes_U16DataOutOfRangeTooHigh_ReturnsError)
{
  EXPECT_CALL(*library_, InputArraysWithNarrowIntegerTypes(_, _, _))
      .Times(0);
  ::grpc::ServerContext context;
  ScalarsWithNarrowIntegerTypesRequest request;
  request.set_u16(UINT16_MAX + 1);
  ScalarsWithNarrowIntegerTypesResponse response;
  auto status = service_.ScalarsWithNarrowIntegerTypes(&context, &request, &response);

  EXPECT_EQ(grpc::StatusCode::OUT_OF_RANGE, status.error_code());
  EXPECT_THAT(status.error_message(), HasSubstr(std::to_string(UINT16_MAX + 1)));
}

TEST_F(NiFakeNonIviServiceTests, ScalarsWithNarrowIntegerTypes_AllFieldsInRange_PassesThroughData)
{
  constexpr myUInt16 u16_val = UINT16_MAX;
  constexpr myInt16 i16_val = INT16_MAX;
  constexpr myInt8 i8_val = INT8_MAX;
  EXPECT_CALL(*library_, ScalarsWithNarrowIntegerTypes(u16_val, i16_val, i8_val))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  ScalarsWithNarrowIntegerTypesRequest request;
  request.set_u16(u16_val);
  request.set_i16(i16_val);
  request.set_i8(i8_val);
  ScalarsWithNarrowIntegerTypesResponse response;
  auto status = service_.ScalarsWithNarrowIntegerTypes(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceTests, OutputArraysWithNarrowIntegerTypes_U16)
{
  ::grpc::ServerContext context;
  OutputArraysWithNarrowIntegerTypesRequest request;
  request.set_number_of_u16_samples(3);
  OutputArraysWithNarrowIntegerTypesResponse response;
  EXPECT_CALL(*library_, OutputArraysWithNarrowIntegerTypes(_, _, _, _, _, _))
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
  EXPECT_CALL(*library_, OutputArraysWithNarrowIntegerTypes(_, _, _, _, _, _))
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
  EXPECT_CALL(*library_, OutputArraysWithNarrowIntegerTypes(_, _, _, _, _, _))
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
  EXPECT_CALL(*library_, InputArrayOfBytes(_))
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
  EXPECT_CALL(*library_, OutputArrayOfBytes(_, _))
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
  EXPECT_CALL(*library_, InputVarArgs(StrEq("inputName"), StrEq("channel"), BEAUTIFUL_COLOR_PINK, 1.0, nullptr, BEAUTIFUL_COLOR_UNSPECIFIED, 0.0, nullptr, BEAUTIFUL_COLOR_UNSPECIFIED, 0.0, nullptr, BEAUTIFUL_COLOR_UNSPECIFIED, 0.0))
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
  EXPECT_CALL(*library_, InputVarArgs(StrEq("inputName"), StrEq("channel0"), BEAUTIFUL_COLOR_PINK, 1.0, StrEq("channel1"), BEAUTIFUL_COLOR_AQUA, 2.0, nullptr, BEAUTIFUL_COLOR_UNSPECIFIED, 0.0, nullptr, BEAUTIFUL_COLOR_UNSPECIFIED, 0.0))
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
  EXPECT_CALL(*library_, InputVarArgs(StrEq("inputName"), StrEq("channel0"), BEAUTIFUL_COLOR_PINK, 1.0, StrEq("channel1"), BEAUTIFUL_COLOR_AQUA, 2.0, StrEq("channel2"), BEAUTIFUL_COLOR_GREEN, 3.0, nullptr, BEAUTIFUL_COLOR_UNSPECIFIED, 0.0))
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
  EXPECT_CALL(*library_, InputVarArgs(_, _, _, _, _, _, _, _, _, _, _, _, _))
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
  EXPECT_CALL(*library_, InputVarArgs(_, _, _, _, _, _, _, _, _, _, _, _, _))
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
  EXPECT_CALL(*library_, OutputVarArgs(StrEq("inputName"), StrEq("channel"), _, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr))
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
  EXPECT_CALL(*library_, OutputVarArgs(StrEq("inputName"), StrEq("channel1"), _, StrEq("channel2"), _, nullptr, nullptr, nullptr, nullptr))
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
  EXPECT_CALL(*library_, OutputVarArgs(StrEq("inputName"), StrEq("channel1"), _, StrEq("channel2"), _, StrEq("channel3"), _, nullptr, nullptr))
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
  EXPECT_CALL(*library_, OutputVarArgs(_, _, _, _, _, _, _, _, _))
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
  EXPECT_CALL(*library_, OutputVarArgs(_, _, _, _, _, _, _, _, _))
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
  EXPECT_CALL(*library_, InputTimestamp(CVIAbsoluteTimeEq(timestamp)))
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
  EXPECT_CALL(*library_, InputTimestamp(CVIAbsoluteTimeEq(timestamp)))
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
  EXPECT_CALL(*library_, InputTimestamp(CVIAbsoluteTimeEq(cviKnownTimestamp)))
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
  EXPECT_CALL(*library_, OutputTimestamp(_))
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
  EXPECT_CALL(*library_, OutputTimestamp(_))
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
  EXPECT_CALL(*library_, OutputTimestamp(_))
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
  const auto ATTRIBUTE = MarbleDoubleAttribute::MARBLE_ATTRIBUTE_WEIGHT;
  const auto VALUE = 1.2345;
  EXPECT_CALL(*library_, SetMarbleAttributeDouble(_, ATTRIBUTE, VALUE))
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
  const auto ATTRIBUTE = MarbleInt32Attribute::MARBLE_ATTRIBUTE_COLOR;
  const auto VALUE = MarbleInt32AttributeValues::MARBLE_INT32_BEAUTIFUL_COLOR_GREEN;
  EXPECT_CALL(*library_, SetMarbleAttributeInt32(_, ATTRIBUTE, VALUE))
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
  const auto ATTRIBUTE = MarbleInt32Attribute::MARBLE_ATTRIBUTE_COLOR;
  const auto VALUE = 9999;
  EXPECT_CALL(*library_, SetMarbleAttributeInt32(_, ATTRIBUTE, VALUE))
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
  const auto ATTRIBUTE = MarbleInt32Attribute::MARBLE_ATTRIBUTE_COLOR;
  const auto VALUE = MarbleInt32AttributeValues::MARBLE_INT32_BEAUTIFUL_COLOR_AQUA;
  EXPECT_CALL(*library_, GetMarbleAttributeInt32(_, ATTRIBUTE, _))
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
  const auto ATTRIBUTE = MarbleInt32ArrayAttribute::MARBLE_ATTRIBUTE_TEN_RANDOM_NUMBERS;
  int VALUE[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
  EXPECT_CALL(*library_, GetMarbleAttributeInt32Array(_, ATTRIBUTE, _))
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
  const auto ATTRIBUTE = MarbleInt32Attribute::MARBLE_ATTRIBUTE_NUMBER_OF_FAILED_ATTEMPTS;
  const auto VALUE = 1000;
  EXPECT_CALL(*library_, GetMarbleAttributeInt32(_, ATTRIBUTE, _))
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
  const auto ATTRIBUTE = MarbleInt32ArrayAttribute::MARBLE_ATTRIBUTE_TEN_FAVORITE_COLORS;
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
  EXPECT_CALL(*library_, GetMarbleAttributeInt32Array(_, ATTRIBUTE, _))
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
  const auto ATTRIBUTE = MarbleResetAttribute::MARBLE_RESET_ATTRIBUTE_WEIGHT;
  EXPECT_CALL(*library_, ResetMarbleAttribute(_, ATTRIBUTE))
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
  const auto RAW_ATTRIBUTE = static_cast<int32>(MarbleDoubleAttribute::MARBLE_ATTRIBUTE_WEIGHT);
  const auto DOUBLE_VALUE = 1.234;
  EXPECT_CALL(*library_, SetMarbleAttributeDouble(_, RAW_ATTRIBUTE, DOUBLE_VALUE))
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
  EXPECT_CALL(*library_, SetMarbleAttributeDouble(_, 0, DOUBLE_VALUE))
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
  EXPECT_CALL(*library_, SetMarbleAttributeDouble(_, RAW_ATTRIBUTE, DOUBLE_VALUE))
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
  const auto CASTED_INVALID_ATTRIBUTE = static_cast<MarbleDoubleAttribute>(9999);
  const auto DOUBLE_VALUE = 1.234;
  EXPECT_CALL(*library_, SetMarbleAttributeDouble(_, 0, DOUBLE_VALUE))
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
  EXPECT_CALL(*library_, GetMarbleAttributeDouble(_, RAW_ATTRIBUTE, _))
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
  const auto CASTED_INVALID_ATTRIBUTE = static_cast<MarbleDoubleAttribute>(9999);
  EXPECT_CALL(*library_, GetMarbleAttributeDouble(_, 0, _))
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
  EXPECT_CALL(*library_, ResetMarbleAttribute(_, RAW_ATTRIBUTE))
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
  const auto CASTED_INVALID_ATTRIBUTE = static_cast<MarbleResetAttribute>(9999);
  EXPECT_CALL(*library_, ResetMarbleAttribute(_, 0))
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
  EXPECT_CALL(*library_, SetColors(_, _))
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

TEST_F(NiFakeNonIviServiceTests, UnreleasedServiceWithToggleEnabled_IsEnabled_ReturnsTrue)
{
  const auto feature_toggles = nidevice_grpc::FeatureToggles({{"nifake_non_ivi", true}});
  const auto fake_toggles = NiFakeNonIviFeatureToggles{feature_toggles};

  EXPECT_TRUE(fake_toggles.is_enabled);
}

TEST_F(NiFakeNonIviServiceTests, UnreleasedServiceWithNoToggles_IsEnabled_ReturnsFalse)
{
  const auto feature_toggles = nidevice_grpc::FeatureToggles();
  const auto fake_toggles = NiFakeNonIviFeatureToggles{feature_toggles};

  EXPECT_FALSE(fake_toggles.is_enabled);
}

TEST_F(NiFakeNonIviServiceTests, GetStructsWithCoercion_ReturnsInRangeData)
{
  ::grpc::ServerContext context;
  GetStructsWithCoercionRequest request;
  request.set_number_of_structs(3);
  GetStructsWithCoercionResponse response;
  EXPECT_CALL(*library_, GetStructsWithCoercion(_, _))
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
  EXPECT_CALL(*library_, SetStructsWithCoercion(_))
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
  EXPECT_CALL(*library_, SetStructsWithCoercion(_))
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
  EXPECT_CALL(*library_, SetStructsWithCoercion(_))
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
  EXPECT_CALL(*library_, SetStructsWithCoercion(_))
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
  EXPECT_CALL(*library_, SetStructsWithCoercion(_))
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
  EXPECT_CALL(*library_, SetStructsWithCoercion(_))
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
  EXPECT_CALL(*library_, OutputArraysWithPassedInByPtrMechanism(_, _, Pointee(3)))
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
  EXPECT_CALL(*library_, OutputArraysWithPassedInByPtrMechanism(_, _, Pointee(5)))
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
  EXPECT_CALL(*library_, OutputArraysWithPassedInByPtrMechanism(_, _, Pointee(5)))
      .WillOnce(
          Return(SOME_ERROR));
  ::grpc::ServerContext context;
  OutputArraysWithPassedInByPtrMechanismRequest request;
  request.set_array_size(5);
  OutputArraysWithPassedInByPtrMechanismResponse response;

  service_.OutputArraysWithPassedInByPtrMechanism(&context, &request, &response);

  EXPECT_EQ(SOME_ERROR, response.status());
}

TEST_F(NiFakeNonIviServiceTests, InputStringValuedEnum_PassMappedEnum_CorrectStringPassedToFunction)
{
  EXPECT_CALL(*library_, InputStringValuedEnum(StrEq("iOS")))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  InputStringValuedEnumRequest request;
  request.set_a_name_mapped(MobileOSNames::MOBILE_OS_NAMES_IOS);
  InputStringValuedEnumResponse response;

  service_.InputStringValuedEnum(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceTests, InputStringValuedEnum_PassNonMappedValue_CorrectStringPassedToFunction)
{
  EXPECT_CALL(*library_, InputStringValuedEnum(StrEq("Windows Phone")))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  InputStringValuedEnumRequest request;
  request.set_a_name_raw("Windows Phone");
  InputStringValuedEnumResponse response;

  service_.InputStringValuedEnum(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceTests, WriteBooleanArray_PassesBooleansAsInt32s)
{
  const auto BOOLS = std::vector<bool>{true, false, true, true, false, false, true, true, true, false, false, false};
  const auto BOOLS_AS_INT32S = std::vector<int32>{1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0};
  EXPECT_CALL(*library_, WriteBooleanArray(_, _))
      .With(Args<0, 1>(ElementsAreArray(BOOLS_AS_INT32S.data(), BOOLS_AS_INT32S.size())))
      .WillOnce(Return(kDriverSuccess));

  ::grpc::ServerContext context;
  WriteBooleanArrayRequest request;
  request.mutable_bools()->CopyFrom({BOOLS.begin(), BOOLS.end()});
  WriteBooleanArrayResponse response;

  service_.WriteBooleanArray(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

template <typename TSessionRepository, typename TResource>
void add_session(TSessionRepository& repository, TResource resource_handle, const std::string name)
{
  std::string session_name = name;
  repository->add_session(
      session_name,
      [resource_handle]() { return std::make_tuple(0, resource_handle); },
      [](TResource handle) {});
}

TEST_F(NiFakeNonIviServiceTests, InitFromCrossDriverSession_PassesSessionResourcesAndSucceeds)
{
  constexpr FakeCrossDriverHandle CROSS_DRIVER_HANDLE = 1234;
  constexpr auto CROSS_DRIVER_SESSION_NAME = "cross_driver_session";
  constexpr auto DRIVER_SESSION = 9876;
  add_session(cross_driver_resource_repository_, CROSS_DRIVER_HANDLE, CROSS_DRIVER_SESSION_NAME);
  EXPECT_CALL(*library_, InitFromCrossDriverSession(CROSS_DRIVER_HANDLE, _))
      .WillOnce(DoAll(
          SetArgPointee<1, FakeHandle>(DRIVER_SESSION), Return(kDriverSuccess)));
  ::grpc::ServerContext context;
  InitFromCrossDriverSessionRequest request;
  InitFromCrossDriverSessionResponse response;
  request.set_session_name("fake_session");
  request.mutable_cross_driver_session()->set_name(CROSS_DRIVER_SESSION_NAME);
  service_.InitFromCrossDriverSession(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(DRIVER_SESSION, resource_repository_->access_session(response.handle().name()));
}

template <size_t N>
InitFromCrossDriverSessionArrayRequest create_init_from_cross_driver_session_array_request(const std::array<std::string, N>& session_names)
{
  InitFromCrossDriverSessionArrayRequest request;
  request.set_session_name("fake_session");
  for (const auto& session_name : session_names) {
    auto session_in = request.add_cross_driver_session_array();
    session_in->set_name(session_name);
  }
  return request;
}

TEST_F(NiFakeNonIviServiceTests, InitFromCrossDriverSessionArray_PassesSessionResourcesAndSucceeds)
{
  constexpr auto CROSS_DRIVER_HANDLES = std::array<FakeCrossDriverHandle, 2>{1234, 5678};
  const auto CROSS_DRIVER_SESSION_NAMES = std::array<std::string, 2>{"cross_driver_session", "cross_driver_session_2"};
  constexpr auto DRIVER_SESSION = 9876;
  add_session(cross_driver_resource_repository_, CROSS_DRIVER_HANDLES[0], CROSS_DRIVER_SESSION_NAMES[0]);
  add_session(cross_driver_resource_repository_, CROSS_DRIVER_HANDLES[1], CROSS_DRIVER_SESSION_NAMES[1]);
  EXPECT_CALL(*library_, InitFromCrossDriverSessionArray(_, _, _))
      .With(Args<0, 1>(ElementsAreArray(CROSS_DRIVER_HANDLES.data(), CROSS_DRIVER_HANDLES.size())))
      .WillOnce(DoAll(
          SetArgPointee<2, FakeHandle>(DRIVER_SESSION), Return(kDriverSuccess)));
  ::grpc::ServerContext context;
  auto request = create_init_from_cross_driver_session_array_request(CROSS_DRIVER_SESSION_NAMES);
  InitFromCrossDriverSessionArrayResponse response;
  service_.InitFromCrossDriverSessionArray(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(DRIVER_SESSION, resource_repository_->access_session(response.handle().name()));
}

TEST_F(NiFakeNonIviServiceTests, GetCrossDriverSession_CloseInitiatingSession_RemovesBothSessions)
{
  constexpr auto INITIATING_DRIVER_HANDLE = 5678;
  constexpr auto CROSS_DRIVER_HANDLE = 1234;
  constexpr auto INITIATING_SESSION_NAME = "initiating_session";
  constexpr auto CROSS_DRIVER_SESSION_NAME = "cross_driver_session";
  const auto initiating_session_name = init(INITIATING_SESSION_NAME, INITIATING_DRIVER_HANDLE);
  EXPECT_CALL(*library_, GetCrossDriverSession(INITIATING_DRIVER_HANDLE, _))
      .WillOnce(DoAll(
          SetArgPointee<1, FakeCrossDriverHandle>(CROSS_DRIVER_HANDLE), Return(kDriverSuccess)));
  ::grpc::ServerContext context;
  GetCrossDriverSessionRequest request;
  GetCrossDriverSessionResponse response;
  request.mutable_handle()->set_name(INITIATING_SESSION_NAME);
  request.set_session_name(CROSS_DRIVER_SESSION_NAME);
  service_.GetCrossDriverSession(&context, &request, &response);
  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(cross_driver_resource_repository_->access_session(CROSS_DRIVER_SESSION_NAME), CROSS_DRIVER_HANDLE);

  close_with_expected_handle(initiating_session_name, INITIATING_DRIVER_HANDLE);

  EXPECT_EQ(cross_driver_resource_repository_->access_session(CROSS_DRIVER_SESSION_NAME), 0);
}

TEST_F(NiFakeNonIviServiceTests, GetCrossDriverSession_ResetServer_RemovesBothSessions)
{
  constexpr auto INITIATING_DRIVER_HANDLE = 5678;
  constexpr auto CROSS_DRIVER_HANDLE = 1234;
  constexpr auto INITIATING_SESSION_NAME = "initiating_session";
  constexpr auto CROSS_DRIVER_SESSION_NAME = "cross_driver_session";
  const auto initiating_session_name = init(INITIATING_SESSION_NAME, INITIATING_DRIVER_HANDLE);
  EXPECT_CALL(*library_, GetCrossDriverSession(INITIATING_DRIVER_HANDLE, _))
      .WillOnce(DoAll(
          SetArgPointee<1, FakeCrossDriverHandle>(CROSS_DRIVER_HANDLE), Return(kDriverSuccess)));
  ::grpc::ServerContext context;
  GetCrossDriverSessionRequest request;
  GetCrossDriverSessionResponse response;
  request.mutable_handle()->set_name(INITIATING_SESSION_NAME);
  request.set_session_name(CROSS_DRIVER_SESSION_NAME);
  service_.GetCrossDriverSession(&context, &request, &response);

  session_repository_->reset_server();

  EXPECT_EQ(cross_driver_resource_repository_->access_session(CROSS_DRIVER_SESSION_NAME), 0);
  EXPECT_EQ(resource_repository_->access_session(INITIATING_SESSION_NAME), 0);
}

TEST_F(NiFakeNonIviServiceTests, SessionAlreadyInCrossDriverSessionRepository_GetCrossDriverSessionForSameResourceHandle_ReverseLookupStillReturnsOriginalSession)
{
  constexpr auto INITIATING_DRIVER_HANDLE = 5678;
  constexpr auto CROSS_DRIVER_HANDLE = 1234;
  constexpr auto INITIATING_SESSION_NAME = "initiating_session";
  constexpr auto CROSS_DRIVER_SESSION_NAME = "cross_driver_session";
  constexpr auto ORIGINAL_NAME_FOR_CROSS_DRIVER_RESOURCE = "original_cross_driver_resource_name";

  std::string session_name = ORIGINAL_NAME_FOR_CROSS_DRIVER_RESOURCE;
  cross_driver_resource_repository_->add_session(
      session_name,
      [&]() { return std::make_tuple(0, CROSS_DRIVER_HANDLE); },
      [](FakeCrossDriverHandle handle) {});

  const auto initiating_session_name = init(INITIATING_SESSION_NAME, INITIATING_DRIVER_HANDLE);
  EXPECT_CALL(*library_, GetCrossDriverSession(INITIATING_DRIVER_HANDLE, _))
      .WillOnce(DoAll(
          SetArgPointee<1, FakeCrossDriverHandle>(CROSS_DRIVER_HANDLE), Return(kDriverSuccess)));
  ::grpc::ServerContext context;
  GetCrossDriverSessionRequest request;
  GetCrossDriverSessionResponse response;
  request.mutable_handle()->set_name(INITIATING_SESSION_NAME);
  request.set_session_name(CROSS_DRIVER_SESSION_NAME);
  service_.GetCrossDriverSession(&context, &request, &response);

  EXPECT_EQ(session_name, cross_driver_resource_repository_->resolve_session_name(CROSS_DRIVER_HANDLE));
}

TEST_F(NiFakeNonIviServiceTests, InitWithReturnedSession_AccessSession_ReturnsInitializeSessionHandle)
{
  constexpr auto SESSION_NAME = "session";
  constexpr auto SESSION_HANDLE = 0x1234UL;
  EXPECT_CALL(*library_, InitWithReturnedSession(StrEq(SESSION_NAME)))
      .WillOnce(Return(SESSION_HANDLE));
  ::grpc::ServerContext context;
  InitWithReturnedSessionRequest request;
  InitWithReturnedSessionResponse response;
  request.set_handle_name(SESSION_NAME);
  service_.InitWithReturnedSession(&context, &request, &response);

  const auto accessed_handle = resource_repository_->access_session(response.handle().name());

  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(SESSION_HANDLE, accessed_handle);
}

TEST_F(NiFakeNonIviServiceTests, InitWithReturnedSessionFailsInit_AccessSession_SessionIsNotInMap)
{
  constexpr auto SESSION_NAME = "session";
  constexpr auto BAD_SESSION_HANDLE = 0xDEADBEEF;  // Fake non-ivi uses 0xDEADBEEF as failed/null session (See functions.py).
  constexpr auto FAILED_INIT = -1;
  EXPECT_CALL(*library_, InitWithReturnedSession(StrEq(SESSION_NAME)))
      .WillOnce(Return(BAD_SESSION_HANDLE));
  ::grpc::ServerContext context;
  InitWithReturnedSessionRequest request;
  InitWithReturnedSessionResponse response;
  request.set_handle_name(SESSION_NAME);
  auto status = service_.InitWithReturnedSession(&context, &request, &response);

  const auto accessed_handle = resource_repository_->access_session(response.handle().name());

  EXPECT_FALSE(status.ok());
  EXPECT_EQ(::grpc::StatusCode::UNKNOWN, status.error_code());
  EXPECT_NE(FAILED_INIT, response.status());
  EXPECT_EQ(0, accessed_handle);
}

TEST_F(NiFakeNonIviServiceTests, GetStringAsReturnedValue_ReturnsString)
{
  constexpr auto STRING_VAL = "Hello Returned World!";
  EXPECT_CALL(*library_, GetStringAsReturnedValue(_))
      .WillOnce(Return(STRING_VAL));
  ::grpc::ServerContext context;
  GetStringAsReturnedValueRequest request;
  GetStringAsReturnedValueResponse response;
  service_.GetStringAsReturnedValue(&context, &request, &response);

  EXPECT_EQ(std::string(STRING_VAL), response.string_out());
  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceTests, GetStringAsReturnedValueReturnsNull_ReturnsError)
{
  constexpr auto FAILED_GET = -1;
  EXPECT_CALL(*library_, GetStringAsReturnedValue(_))
      .WillOnce(Return(nullptr));
  ::grpc::ServerContext context;
  GetStringAsReturnedValueRequest request;
  GetStringAsReturnedValueResponse response;
  auto status = service_.GetStringAsReturnedValue(&context, &request, &response);

  EXPECT_FALSE(status.ok());
  EXPECT_EQ(::grpc::StatusCode::UNKNOWN, status.error_code());
  EXPECT_NE(FAILED_GET, response.status());
}

TEST_F(NiFakeNonIviServiceTests, InitWithError_CallsGetLatestErrorAndReturnsMessage)
{
  constexpr auto SOME_ERROR = -1;
  const auto ERROR_MESSAGE = std::string("Some error occurred!");
  const auto ERROR_MESSAGE_BUFFER_SIZE = static_cast<int32>(ERROR_MESSAGE.size() + 1);
  EXPECT_CALL(*library_, Init(_, _))
      .WillOnce(Return(SOME_ERROR));
  EXPECT_CALL(*library_, GetLatestErrorMessage(_, 2048))
      .WillOnce(
          DoAll(
              SetArrayArgument<0>(ERROR_MESSAGE.c_str(), ERROR_MESSAGE.c_str() + ERROR_MESSAGE_BUFFER_SIZE),
              Return(0)));
  ::grpc::ServerContext context;
  InitRequest request;
  InitResponse response;
  auto status = service_.Init(&context, &request, &response);

  EXPECT_FALSE(status.ok());
  EXPECT_EQ(::grpc::StatusCode::UNKNOWN, status.error_code());
  EXPECT_EQ(ERROR_MESSAGE, status.error_message());
  EXPECT_NE(SOME_ERROR, response.status());
}

TEST_F(NiFakeNonIviServiceTests, InitWithNoError_DoesNotCallGetLatestError)
{
  EXPECT_CALL(*library_, Init(_, _))
      .WillOnce(Return(kDriverSuccess));
  EXPECT_CALL(*library_, GetLatestErrorMessage(_, _))
      .Times(0);
  ::grpc::ServerContext context;
  InitRequest request;
  InitResponse response;
  service_.Init(&context, &request, &response);

  EXPECT_THAT(response.error_message(), IsEmpty());
  EXPECT_EQ(kDriverSuccess, response.status());
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
