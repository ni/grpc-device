#include <grpcpp/impl/grpc_library.h>
#include <gtest/gtest.h>
#include <nifake_non_ivi/nifake_non_ivi_mock_library.h>
#include <nifake_non_ivi/nifake_non_ivi_service.h>
#include <server/session_resource_repository.h>

#include <iostream>
#include <string>

using namespace nifake_non_ivi_grpc;
using namespace ::testing;

const int32 kDriverSuccess = 0;
const int32 kDriverFailure = 1;

namespace ni {
namespace tests {
namespace unit {

MATCHER(CustomU16Data, "")
{
  uInt16 const* write_data_array = std::get<0>(arg);
  return write_data_array[0] == 0 && write_data_array[1] == UINT16_MAX && write_data_array[2] == 16;
}

MATCHER(CustomI16Data, "")
{
  int16 const* write_data_array = std::get<1>(arg);
  return write_data_array[0] == 0 && write_data_array[1] == INT16_MAX && write_data_array[2] == INT16_MIN;
}

MATCHER(CustomI8Data, "")
{
  int8 const* write_data_array = std::get<2>(arg);
  return write_data_array[0] == 0 && write_data_array[1] == INT8_MAX && write_data_array[2] == INT8_MIN;
}

MATCHER(CustomU8Data, "")
{
  uInt8 const* write_data_array = std::get<0>(arg);
  return write_data_array[0] == 0 && write_data_array[1] == UINT8_MAX && write_data_array[2] == 16;
}

void SetU16Data(Unused, uInt16* u16_data, Unused, Unused, Unused, Unused)
{
  u16_data[0] = 0;
  u16_data[1] = UINT16_MAX;
  u16_data[2] = 16;
};

void SetI16Data(Unused, Unused, Unused, int16* i16_data, Unused, Unused)
{
  i16_data[0] = 0;
  i16_data[1] = INT16_MAX;
  i16_data[2] = INT16_MIN;
};

void SetI8Data(Unused, Unused, Unused, Unused, Unused, int8* i8_data)
{
  i8_data[0] = 0;
  i8_data[1] = INT8_MAX;
  i8_data[2] = INT8_MIN;
};

void SetU8Data(Unused, uInt8* u8_data)
{
  u8_data[0] = 0;
  u8_data[1] = UINT8_MAX;
  u8_data[2] = 16;
}

class NiFakeNonIviServiceTests : public ::testing::Test {
 protected:
  using FakeResourceRepository = nidevice_grpc::SessionResourceRepository<FakeHandle>;
  nidevice_grpc::SessionRepository session_repository_;
  std::shared_ptr<FakeResourceRepository> resource_repository_;
  NiFakeNonIviMockLibrary library_;
  NiFakeNonIviService service_;

  NiFakeNonIviServiceTests()
      : session_repository_(),
        resource_repository_(std::make_shared<FakeResourceRepository>(&session_repository_)),
        library_(),
        service_(&library_, resource_repository_)
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
  EXPECT_EQ(0, (uInt8)response.u8_data()[0]);
  EXPECT_EQ(UINT8_MAX, (uInt8)response.u8_data()[1]);
  EXPECT_EQ(16, (uInt8)response.u8_data()[2]);
  auto status = response.status();
  EXPECT_EQ(kDriverSuccess, status);
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
