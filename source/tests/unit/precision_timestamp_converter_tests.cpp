#include <gtest/gtest.h>
#include <cstdint>
#include <limits>
#include <server/converters.h>

namespace ni {
namespace tests {
namespace unit {
namespace {

using nidevice_grpc::converters::convert_dot_net_ticks_to_precision_timestamp;
using nidevice_grpc::converters::DotNetTicksPerSecond;
using nidevice_grpc::converters::TwoToSixtyFour;
using nidevice_grpc::converters::SecondsFromDotNet0001EpochToCVI1904Epoch;
using ::ni::protobuf::types::PrecisionTimestamp;

const int64 EpochTicks = SecondsFromDotNet0001EpochToCVI1904Epoch * DotNetTicksPerSecond;

TEST(PrecisionTimestampConverterTests, ConvertZeroTicks_ReturnsNegativeEpochTimestamp)
{
  PrecisionTimestamp timestamp;  
  convert_dot_net_ticks_to_precision_timestamp(0, &timestamp);
  
  EXPECT_EQ(timestamp.seconds(), -SecondsFromDotNet0001EpochToCVI1904Epoch);
  EXPECT_EQ(timestamp.fractional_seconds(), 0);
}

TEST(PrecisionTimestampConverterTests, ConvertEpochTicks_ReturnsZeroTimestamp)
{
  PrecisionTimestamp timestamp;  
  convert_dot_net_ticks_to_precision_timestamp(EpochTicks, &timestamp);
  
  EXPECT_EQ(timestamp.seconds(), 0);
  EXPECT_EQ(timestamp.fractional_seconds(), 0);
}

TEST(PrecisionTimestampConverterTests, ConvertOneSecondOfTicks_ReturnsOneSecond)
{
  PrecisionTimestamp timestamp;  
  const int64_t one_second_ticks = EpochTicks + 1 * DotNetTicksPerSecond;
  convert_dot_net_ticks_to_precision_timestamp(one_second_ticks, &timestamp);
  
  EXPECT_EQ(timestamp.seconds(), 1);
  EXPECT_EQ(timestamp.fractional_seconds(), 0);
}

// Parameterized test for seconds and fractional combinations
struct SecondsAndFractionalTestParam {
  int64_t ticks_offset;
  int64_t seconds;
  double fraction;
  uint64_t btf_fractional_ticks;
};

class PrecisionTimestampConverterSecondsAndFractionalTests : public ::testing::TestWithParam<SecondsAndFractionalTestParam> {};

TEST_P(PrecisionTimestampConverterSecondsAndFractionalTests, ConvertSecondsAndFractional_ReturnsCorrectValues)
{
  const auto& param = GetParam();
  PrecisionTimestamp timestamp;
  convert_dot_net_ticks_to_precision_timestamp(EpochTicks + param.ticks_offset, &timestamp);

  EXPECT_EQ(timestamp.seconds(), param.seconds) << "Failed for ticks_offset: " << param.ticks_offset;
  EXPECT_EQ(timestamp.fractional_seconds(), param.btf_fractional_ticks) << "Failed for ticks_offset: " << param.ticks_offset;
}

INSTANTIATE_TEST_SUITE_P(
  SecondsAndFractionalTests,
  PrecisionTimestampConverterSecondsAndFractionalTests,
  ::testing::Values(
    SecondsAndFractionalTestParam{  0000000,  0, 0.00,      0x0000000000000000ULL},
    SecondsAndFractionalTestParam{  2500000,  0, 0.25,      0x4000000000000000ULL},
    SecondsAndFractionalTestParam{  5000000,  0, 0.50,      0x8000000000000000ULL},
    SecondsAndFractionalTestParam{  7500000,  0, 0.75,      0xC000000000000000ULL},
    SecondsAndFractionalTestParam{  9999999,  0, 0.9999999, 0xFFFFFE5280D65800ULL},
    SecondsAndFractionalTestParam{ 12500000,  1, 0.25,      0x4000000000000000ULL},
    SecondsAndFractionalTestParam{ 25000000,  2, 0.50,      0x8000000000000000ULL},
    SecondsAndFractionalTestParam{ 37500000,  3, 0.75,      0xC000000000000000ULL},
    SecondsAndFractionalTestParam{ -2500000, -0, 0.25,      0x4000000000000000ULL},
    SecondsAndFractionalTestParam{ -5000000, -0, 0.50,      0x8000000000000000ULL},
    SecondsAndFractionalTestParam{ -7500000, -0, 0.75,      0xC000000000000000ULL},
    SecondsAndFractionalTestParam{ -9999999, -0, 0.9999999, 0xFFFFFE5280D65800ULL},
    SecondsAndFractionalTestParam{-12500000, -1, 0.25,      0x4000000000000000ULL},
    SecondsAndFractionalTestParam{-25000000, -2, 0.25,      0x8000000000000000ULL},
    SecondsAndFractionalTestParam{-37500000, -3, 0.75,      0xC000000000000000ULL}
  )
);

// Parameterized test for large timestamps across different years
struct LargeTimestampTestParam {
  int year;
  int64_t days_from_1904_epoch;
  std::string description;
};

class PrecisionTimestampConverterLargeTimestampTests : public ::testing::TestWithParam<LargeTimestampTestParam> {};

TEST_P(PrecisionTimestampConverterLargeTimestampTests, ConvertLargeTimestamp_HandlesCorrectly)
{
  const auto& param = GetParam();
  PrecisionTimestamp timestamp;
  const int64 SecondsFromNiBtfEpochToYear = param.days_from_1904_epoch * 24 * 60 * 60;
  const int64 YearTicks = EpochTicks + SecondsFromNiBtfEpochToYear * DotNetTicksPerSecond;
  
  convert_dot_net_ticks_to_precision_timestamp(YearTicks + DotNetTicksPerSecond / 4, &timestamp);
  
  if (SecondsFromNiBtfEpochToYear < 0) {
    EXPECT_EQ(timestamp.seconds(), SecondsFromNiBtfEpochToYear + 1) << "Failed for " << param.description;
    EXPECT_EQ(timestamp.fractional_seconds(), static_cast<uint64_t>(0.75 * TwoToSixtyFour)) << "Failed for " << param.description;
  } else {
    EXPECT_EQ(timestamp.seconds(), SecondsFromNiBtfEpochToYear) << "Failed for " << param.description;
    EXPECT_EQ(timestamp.fractional_seconds(), static_cast<uint64_t>(0.25 * TwoToSixtyFour)) << "Failed for " << param.description;
  }
}

INSTANTIATE_TEST_SUITE_P(
  LargeTimestampTests,
  PrecisionTimestampConverterLargeTimestampTests,
  ::testing::Values(
    LargeTimestampTestParam{2025, 44196, "January 1, 2025"},  // 121 years from 1904 = 44196 days (accounting for leap years)
    LargeTimestampTestParam{2002, 35794, "January 1, 2002"},  // 98 years from 1904 = 35794 days (accounting for leap years)
    LargeTimestampTestParam{1950, 16801, "January 1, 1950"},  // 46 years from 1904 = 16801 days (accounting for leap years)
    LargeTimestampTestParam{1850, -19723, "January 1, 1850"}, // 54 years before 1904 = -19723 days (accounting for leap years)
    LargeTimestampTestParam{1066, -306022, "January 1, 1066"} // 838 years before 1904 = -306022 days (accounting for leap years)
  )
);

}  // namespace
}  // namespace unit
}  // namespace tests
}  // namespace ni