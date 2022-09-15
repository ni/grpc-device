#define NOMINMAX

#include <custom/nimxlcterminaladaptor_restricted_converters.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <nimxlcterminaladaptor_restricted/nimxlcterminaladaptor_restricted_mock_library.h>

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

class MockServerContext {
 public:
  MOCK_METHOD2(AddTrailingMetadata, void(const std::string& key, const std::string& value));
};

TEST(nimxlcterminaladaptor_restricted_tests, nierr_Status_ConvertToGrpc_StatusValuesAreEqual)
{
  std::string description = "test_string";
  int32_t errorCode = -12345;
  MockServerContext serverContext;
  NIErrStatusOutputConverter<MockServerContext> status(&serverContext);
  (&status)->code = errorCode;
  (&status)->reallocJson(&status, description.length());
  strcpy((&status)->json, description.c_str());
  (&status)->capacity = description.length();

  nimxlcterminaladaptor_restricted_grpc::NIErrStatus output;
  EXPECT_CALL(serverContext, AddTrailingMetadata("ni-error", std::to_string(errorCode)));
  EXPECT_CALL(serverContext, AddTrailingMetadata("ni-error-json", description));
  status.to_grpc(output);

  EXPECT_EQ(errorCode, output.code());
}
}  // namespace
}  // namespace unit
}  // namespace tests
}  // namespace ni