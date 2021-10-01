#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <server/converters.h>

using namespace nidevice_grpc::converters;
using namespace ::testing;

namespace ni {
namespace tests {
namespace unit {
namespace {
TEST(ConvertersTests, StringWithNoTrailingNulls_TrimTrailingNulls_StringIsTheSame)
{
  const auto INITIAL = std::string("regular_string");
  auto copy = INITIAL;

  trim_trailing_nulls(copy);

  EXPECT_EQ(copy, INITIAL);
}

TEST(ConvertersTests, StringResizedToAddTrailingNulls_TrimTrailingNulls_StringNoLongerHasTrailingNulls)
{
  const auto DATA = std::string("actual_string");
  auto big_string = DATA;
  big_string.resize(100, 0);
  auto copy = big_string;

  trim_trailing_nulls(copy);

  EXPECT_NE(DATA, big_string);
  EXPECT_EQ(DATA, copy);
}

}  // namespace
}  // namespace unit
}  // namespace tests
}  // namespace ni