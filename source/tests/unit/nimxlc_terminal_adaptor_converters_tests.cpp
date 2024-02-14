#define NOMINMAX

#include <custom/nimxlcterminaladaptor_restricted_converters.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <nimxlcterminaladaptor_restricted/nimxlcterminaladaptor_restricted_mock_library.h>

#include <algorithm>
#include <numeric>
#include <string>
#include <iostream>

using namespace nimxlcterminaladaptor_restricted_grpc;
using nidevice_grpc::converters::convert_from_grpc;
using nidevice_grpc::converters::convert_to_grpc;
namespace pb = ::google::protobuf;

namespace ni {
namespace tests {
namespace unit {
namespace {

const std::string description = "test&%_string[";
const std::string encoded_description = "test%26%25_string%5b";

class MockServerContext {
 public:
  MOCK_METHOD2(AddTrailingMetadata, void(const std::string& key, const std::string& value));
};

void initialize_status(nierr_Status *status, int32_t code, std::string description)
{
  status->code = code;
  status->reallocJson(status, static_cast<uint32_t>(description.length() + JSONZ_TERMINATOR_SIZE));
  strcpy(status->json, description.c_str());
}

TEST(nimxlcterminaladaptor_restricted_tests, nierr_StatusFatal_ConvertToGrpc_TrailingMetadataIsAdded)
{
  int32_t errorCode = -12345;
  MockServerContext serverContext;
  NIErrStatusOutputConverter<MockServerContext> status(&serverContext);
  initialize_status(&status, errorCode, description);

  nimxlcterminaladaptor_restricted_grpc::NIErrStatus output;
  EXPECT_CALL(serverContext, AddTrailingMetadata("ni-error", std::to_string(errorCode)));
  EXPECT_CALL(serverContext, AddTrailingMetadata("ni-error-json", encoded_description));
  status.to_grpc(output);

  EXPECT_EQ(errorCode, output.code());
  EXPECT_EQ(std::string(), output.json());
}

TEST(nimxlcterminaladaptor_restricted_tests, nierr_StatusNotFatal_ConvertToGrpc_JsonAddedToStatus)
{
  int32_t errorCode = 12345;
  MockServerContext serverContext;
  NIErrStatusOutputConverter<MockServerContext> status(&serverContext);
  initialize_status(&status, errorCode, description);

  nimxlcterminaladaptor_restricted_grpc::NIErrStatus output;
  status.to_grpc(output);

  EXPECT_EQ(errorCode, output.code());
  EXPECT_EQ(encoded_description, output.json());
}

}  // namespace
}  // namespace unit
}  // namespace tests
}  // namespace ni