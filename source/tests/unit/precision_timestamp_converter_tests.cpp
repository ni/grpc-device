#include <gtest/gtest.h>
#include <cstdint>
#include <limits>
#include <server/converters.h>

namespace ni {
namespace tests {
namespace unit {
namespace {

using nidevice_grpc::converters::convert_dot_net_daqmx_ticks_to_btf_precision_timestamp;
using nidevice_grpc::converters::DotNetTicksPerSecond;
using nidevice_grpc::converters::TwoToSixtyFour;
using nidevice_grpc::converters::SecondsFromDAQmx0001EpochToCVI1904Epoch;
using ::ni::protobuf::types::PrecisionTimestamp;

const int64 EpochTicks = SecondsFromDAQmx0001EpochToCVI1904Epoch * DotNetTicksPerSecond;

TEST(PrecisionTimestampConverterTests, ConvertZeroTicks_ReturnsNegativeEpochTimestamp)
{
  PrecisionTimestamp timestamp;  
  convert_dot_net_daqmx_ticks_to_btf_precision_timestamp(0, &timestamp);
  
  EXPECT_EQ(timestamp.seconds(), -SecondsFromDAQmx0001EpochToCVI1904Epoch);
  EXPECT_EQ(timestamp.fractional_seconds(), 0);
}

TEST(PrecisionTimestampConverterTests, ConvertEpochTicks_ReturnsZeroTimestamp)
{
  PrecisionTimestamp timestamp;  
  convert_dot_net_daqmx_ticks_to_btf_precision_timestamp(EpochTicks, &timestamp);
  
  EXPECT_EQ(timestamp.seconds(), 0);
  EXPECT_EQ(timestamp.fractional_seconds(), 0);
}

TEST(PrecisionTimestampConverterTests, ConvertOneSecondOfTicks_ReturnsOneSecond)
{
  PrecisionTimestamp timestamp;  
  const int64_t one_second_ticks = EpochTicks + 1 * DotNetTicksPerSecond;
  convert_dot_net_daqmx_ticks_to_btf_precision_timestamp(one_second_ticks, &timestamp);
  
  EXPECT_EQ(timestamp.seconds(), 1);
  EXPECT_EQ(timestamp.fractional_seconds(), 0);
}

// Parameterized test for seconds and fractional combinations
struct SecondsAndFractionalTestParam {
  int64_t seconds;
  double fraction;
  int64_t ticks_offset;
  std::string description;
};

class PrecisionTimestampConverterSecondsAndFractionalTests : public ::testing::TestWithParam<SecondsAndFractionalTestParam> {};

TEST_P(PrecisionTimestampConverterSecondsAndFractionalTests, ConvertSecondsAndFractional_ReturnsCorrectValues)
{
  const auto& param = GetParam();
  PrecisionTimestamp timestamp;
  convert_dot_net_daqmx_ticks_to_btf_precision_timestamp(EpochTicks + param.ticks_offset, &timestamp);

  EXPECT_EQ(timestamp.seconds(), param.seconds) << "Failed for " << param.description;
  EXPECT_EQ(timestamp.fractional_seconds(), static_cast<uint64_t>(param.fraction * TwoToSixtyFour)) << "Failed for " << param.description;
}

INSTANTIATE_TEST_SUITE_P(
  SecondsAndFractionalTests,
  PrecisionTimestampConverterSecondsAndFractionalTests,
  ::testing::Values(
    SecondsAndFractionalTestParam{0, 0.25, DotNetTicksPerSecond / 4, "quarter second"},
    SecondsAndFractionalTestParam{0, 0.5, DotNetTicksPerSecond / 2, "half second"},
    SecondsAndFractionalTestParam{0, 0.75, DotNetTicksPerSecond / 2 + DotNetTicksPerSecond / 4, "three quarters second"},
    SecondsAndFractionalTestParam{1, 0.5, 1 * DotNetTicksPerSecond + DotNetTicksPerSecond / 2, "one and half seconds"},
    SecondsAndFractionalTestParam{2, 0.25, 2 * DotNetTicksPerSecond + DotNetTicksPerSecond / 4, "two and quarter seconds"},
    SecondsAndFractionalTestParam{3, 0.75, 3 * DotNetTicksPerSecond + DotNetTicksPerSecond / 2 + DotNetTicksPerSecond / 4, "three and three quarters seconds"}
  )
);

// Parameterized test for literal tick values
struct LiteralTestParam {
  int64_t dot_net_ticks;
  uint64_t btf_fractional_ticks;
  std::string description;
};

class PrecisionTimestampConverterLiteralTests : public ::testing::TestWithParam<LiteralTestParam> {};

TEST_P(PrecisionTimestampConverterLiteralTests, ConvertLiteralTicks_ReturnsCorrectValues)
{
  const auto& param = GetParam();
  PrecisionTimestamp timestamp;
  convert_dot_net_daqmx_ticks_to_btf_precision_timestamp(EpochTicks + param.dot_net_ticks, &timestamp);

  EXPECT_EQ(timestamp.seconds(), 0) << "Failed for " << param.description;
  EXPECT_EQ(timestamp.fractional_seconds(), param.btf_fractional_ticks) << "Failed for " << param.description;
}

INSTANTIATE_TEST_SUITE_P(
  LiteralTests,
  PrecisionTimestampConverterLiteralTests,
  ::testing::Values(
    LiteralTestParam{0000000, 0x0000000000000000ULL, "zero fractional seconds"},
    LiteralTestParam{2500000, 0x4000000000000000ULL, "quarter second"},
    LiteralTestParam{5000000, 0x8000000000000000ULL, "half second"},
    LiteralTestParam{7500000, 0xC000000000000000ULL, "three quarters second"},
    LiteralTestParam{9999999, 0xFFFFFE5280D65800ULL, "99.99999% of a second"}
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
  
  convert_dot_net_daqmx_ticks_to_btf_precision_timestamp(YearTicks + DotNetTicksPerSecond / 4, &timestamp);
  
  EXPECT_EQ(timestamp.seconds(), SecondsFromNiBtfEpochToYear) << "Failed for " << param.description;
  EXPECT_EQ(timestamp.fractional_seconds(), static_cast<uint64_t>(0.25 * TwoToSixtyFour)) << "Failed for " << param.description;
}

INSTANTIATE_TEST_SUITE_P(
  LargeTimestampTests,
  PrecisionTimestampConverterLargeTimestampTests,
  ::testing::Values(
    LargeTimestampTestParam{2025, 44196, "January 1, 2025"},  // 121 years from 1904 = 44196 days (accounting for leap years)
    LargeTimestampTestParam{2002, 35794, "January 1, 2002"},  // 98 years from 1904 = 35794 days (accounting for leap years)
    LargeTimestampTestParam{1950, 16801, "January 1, 1950"},  // 46 years from 1904 = 16801 days (accounting for leap years)
    LargeTimestampTestParam{1850, -19723, "January 1, 1850"} // 54 years before 1904 = -19723 days (accounting for leap years)
  )
);

}  // namespace
}  // namespace unit
}  // namespace tests
}  // namespace ni