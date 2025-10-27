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

// Parameterized test for fractional seconds
struct FractionalSecondsTestParam {
  double fraction;
  int64_t ticks_offset;
  uint64_t expected_fractional_seconds;
  std::string description;
};

class PrecisionTimestampConverterFractionalSecondsTests : public ::testing::TestWithParam<FractionalSecondsTestParam> {};

TEST_P(PrecisionTimestampConverterFractionalSecondsTests, ConvertFractionalSeconds_ReturnsCorrectFractionalSeconds)
{
  const auto& param = GetParam();
  PrecisionTimestamp timestamp;
  convert_dot_net_daqmx_ticks_to_btf_precision_timestamp(EpochTicks + param.ticks_offset, &timestamp);

  EXPECT_EQ(timestamp.seconds(), 0) << "Failed for " << param.description;
  EXPECT_EQ(timestamp.fractional_seconds(), param.expected_fractional_seconds) << "Failed for " << param.description;
}

INSTANTIATE_TEST_SUITE_P(
  FractionalSecondsTests,
  PrecisionTimestampConverterFractionalSecondsTests,
  ::testing::Values(
    FractionalSecondsTestParam{0.25, DotNetTicksPerSecond / 4, static_cast<uint64_t>(0.25 * TwoToSixtyFour), "quarter second"},
    FractionalSecondsTestParam{0.5, DotNetTicksPerSecond / 2, static_cast<uint64_t>(0.5 * TwoToSixtyFour), "half second"},
    FractionalSecondsTestParam{0.75, DotNetTicksPerSecond / 2 + DotNetTicksPerSecond / 4, static_cast<uint64_t>(0.75 * TwoToSixtyFour), "three quarters second"},
    FractionalSecondsTestParam{0.25, 2500000, 0x4000000000000000ULL, "quarter second (literal)"},
    FractionalSecondsTestParam{0.5, 5000000, 0x8000000000000000ULL, "half second (literal)"},
    FractionalSecondsTestParam{0.75, 7500000, 0xC000000000000000ULL, "three quarters second (literal)"}
  )
);

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
    SecondsAndFractionalTestParam{1, 0.5, 1 * DotNetTicksPerSecond + DotNetTicksPerSecond / 2, "one and half seconds"}
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