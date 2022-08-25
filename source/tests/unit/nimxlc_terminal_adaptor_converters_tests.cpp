#define NOMINMAX

#include <custom/nimxlcTerminalAdaptor_restricted_converters.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <nimxlcTerminalAdaptor_restricted/nimxlcTerminalAdaptor_restricted_mock_library.h>

#include <algorithm>
#include <numeric>
#include <string>

using namespace nimxlcterminaladaptor_restricted_grpc;
using nidevice_grpc::converters::convert_from_grpc;
using nidevice_grpc::converters::convert_to_grpc;
namespace pb = ::google::protobuf;

namespace ni {
namespace tests {
namespace unit {
namespace {

void assert_nierr_statuses_are_equal(nierr_Status* error1, nimxlcterminaladaptor_restricted_grpc::NIErrStatus error2)
{
  EXPECT_EQ(error1->code, error2.code());
  EXPECT_EQ(error1->capacity, error2.capacity());
  EXPECT_EQ(error1->json, error2.json());
}

TEST(nimxlcTerminalAdaptor_restricted_tests, nierr_Status_ConvertToGrpc_StatusValuesAreEqual)
{
  std::string description = "test_string";
  nierr_Status input;
  input.code = 1234;
  input.json = const_cast<char*>(description.c_str());
  input.capacity = description.length();

  nimxlcterminaladaptor_restricted_grpc::NIErrStatus output;
  nidevice_grpc::converters::convert_to_grpc(input, &output);

  assert_nierr_statuses_are_equal(&input, output);
}
}  // namespace
}  // namespace unit
}  // namespace tests
}  // namespace ni