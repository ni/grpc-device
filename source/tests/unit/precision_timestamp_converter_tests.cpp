#include <gtest/gtest.h>
#include <cstdint>
#include <limits>
#include <server/converters.h>

namespace ni {
namespace tests {
namespace unit {
namespace {

using nidevice_grpc::converters::DotNetTicksPerSecond;
using nidevice_grpc::converters::TwoToSixtyFour;
using nidevice_grpc::converters::convert_dot_net_daqmx_ticks_to_btf_precision_timestamp;
using nidevice_grpc::converters::SecondsFromDAQmx0001EpochToCVI1904Epoch;
using ::ni::protobuf::types::PrecisionTimestamp;

// // Use the same constant as the CVIAbsoluteTime conversion
// // const double TwoToSixtyFour = (double)(1 << 31) * (double)(1 << 31) * (double)(1 << 2);

// // The epoch bias from year 1 (0001) to 1904 - extracted from NITYPES_ABSOLUTETIME_EPOCH_BIAS_FROM_0001
// // The actual computed value from our conversion function
// // const int64_t kEpochBiasSeconds = 60052752000LL;
// const int64 NiBtfEpochBiasSeconds = (static_cast<int64>(0xfffffff2) << 32) | 0x0493b980;

// // Convert ticks (100ns since Jan 1, 0001) to PrecisionTimestamp
// inline void convert_dot_net_ticks_to_btf_precision_timestamp(int64 dot_net_ticks, ::ni::protobuf::types::PrecisionTimestamp* timestamp)
// {
//   // Convert to ticks since 1904 epoch by adding the epoch bias
//   // NITYPES_ABSOLUTETIME_EPOCH_BIAS_FROM_0001 represents the offset from year 1 to 1904
//   // The FixedPointSigned64 format: high 32 bits (0xfffffff2) and low 32 bits (0x0493b980)
//   // This is a negative offset representing seconds from 0001 to 1904
//   // const int64 epoch_bias_seconds = (static_cast<int64>(0xfffffff2) << 32) | 0x0493b980;
//   // const int64 epoch_bias_ticks = NiBtfEpochBiasSeconds * DotNetTicksPerSecond;
//   const int64 ticks_since_1904 = NiBtfEpochBiasSeconds * DotNetTicksPerSecond + dot_net_ticks;
  
//   // Convert ticks to seconds and fractional seconds
//   const int64 seconds_int = ticks_since_1904 / DotNetTicksPerSecond;
//   const int64 remaining_ticks = ticks_since_1904 % DotNetTicksPerSecond;
  
//   timestamp->set_seconds(seconds_int);
//   // Convert remaining ticks to fractional seconds at 2^-64 resolution using floating point
//   // Similar to CVIAbsoluteTime conversion: fractional_seconds = (remaining_ticks / DotNetTicksPerSecond) * 2^64
//   const uint64_t fractional_seconds_uint = static_cast<uint64_t>((static_cast<double>(remaining_ticks) / DotNetTicksPerSecond) * TwoToSixtyFour);
  
//   timestamp->set_fractional_seconds(fractional_seconds_uint);
// }

//const int64 NiBtfEpochPosativeBiasSeconds = -NiBtfEpochBiasSeconds; // NiBtfEpochBiasSeconds is negative, but we need the positive version to calculate test values
const int64 EpochTicks = SecondsFromDAQmx0001EpochToCVI1904Epoch * DotNetTicksPerSecond;

// January 1, 2025 constants
// From January 1, 1904 to January 1, 2025 = 121 years = 44,165 days (including leap years)
// 121 years contains: 29 leap years (1904, 1908, ..., 2020, 2024) and 92 regular years
// Days: 29 * 366 + 92 * 365 = 10,614 + 33,580 = 44,194 days
// Wait, let me be more precise: 2025 - 1904 = 121 years
// Leap years in this period: every 4 years except century years not divisible by 400
// 1904, 1908, 1912, ..., 2020, 2024 = 31 leap years (1904 to 2024 inclusive, every 4 years)
// Regular years: 121 - 31 = 90 years
// Total days: 31 * 366 + 90 * 365 = 11,346 + 32,850 = 44,196 days

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

TEST(PrecisionTimestampConverterTests, ConvertHalfSecondOfTicks_ReturnsCorrectFractionalSeconds)
{
  PrecisionTimestamp timestamp;
  convert_dot_net_daqmx_ticks_to_btf_precision_timestamp(EpochTicks + DotNetTicksPerSecond / 2, &timestamp);

  EXPECT_EQ(timestamp.seconds(), 0);
  EXPECT_EQ(timestamp.fractional_seconds(), static_cast<uint64_t>(0.5 * TwoToSixtyFour));
}

TEST(PrecisionTimestampConverterTests, ConvertQuarterSecondOfTicks_ReturnsCorrectFractionalSeconds)
{
  PrecisionTimestamp timestamp;
  convert_dot_net_daqmx_ticks_to_btf_precision_timestamp(EpochTicks + DotNetTicksPerSecond / 4, &timestamp);

  EXPECT_EQ(timestamp.seconds(), 0);
  EXPECT_EQ(timestamp.fractional_seconds(), static_cast<uint64_t>(0.25 * TwoToSixtyFour));
}

TEST(PrecisionTimestampConverterTests, ConvertThreeQuartersSecondOfTicks_ReturnsCorrectFractionalSeconds)
{
  PrecisionTimestamp timestamp;
  convert_dot_net_daqmx_ticks_to_btf_precision_timestamp(EpochTicks + DotNetTicksPerSecond / 2 + DotNetTicksPerSecond / 4, &timestamp);
  
  EXPECT_EQ(timestamp.seconds(), 0);
  EXPECT_EQ(timestamp.fractional_seconds(), static_cast<uint64_t>(0.75 * TwoToSixtyFour));
}

TEST(PrecisionTimestampConverterTests, ConvertOneAndHalfSecondsOfTicks_ReturnsCorrectSecondsAndFractional)
{
  PrecisionTimestamp timestamp;
  convert_dot_net_daqmx_ticks_to_btf_precision_timestamp(EpochTicks + 1 * DotNetTicksPerSecond + DotNetTicksPerSecond / 2, &timestamp);
  
  EXPECT_EQ(timestamp.seconds(), 1);
  EXPECT_EQ(timestamp.fractional_seconds(), static_cast<uint64_t>(0.5 * TwoToSixtyFour));
}

TEST(PrecisionTimestampConverterTests, ConvertExact2500000Ticks_ReturnsExactFractionalSeconds)
{
  PrecisionTimestamp timestamp;
  convert_dot_net_daqmx_ticks_to_btf_precision_timestamp(EpochTicks + 2500000, &timestamp);
  
  EXPECT_EQ(timestamp.seconds(), 0);
  EXPECT_EQ(timestamp.fractional_seconds(), 0x4000000000000000ULL);
}

TEST(PrecisionTimestampConverterTests, ConvertLargeTimestamp_HandlesCorrectly)
{
  PrecisionTimestamp timestamp;
  const int64 DaysFromNiBtfEpochToJan1_2025 = 44196;
  const int64 SecondsFromNiBtfEpochToJan1_2025 = DaysFromNiBtfEpochToJan1_2025 * 24 * 60 * 60;
  const int64 Jan1_2025_Seconds = SecondsFromNiBtfEpochToJan1_2025;  // Seconds since 1904 epoch
  const int64 Jan1_2025_Ticks = EpochTicks + SecondsFromNiBtfEpochToJan1_2025 * DotNetTicksPerSecond;
  const int64_t large_timestamp_ticks = Jan1_2025_Ticks + DotNetTicksPerSecond / 4;
  
  convert_dot_net_daqmx_ticks_to_btf_precision_timestamp(large_timestamp_ticks, &timestamp);
  
  EXPECT_EQ(timestamp.seconds(), Jan1_2025_Seconds);
  EXPECT_EQ(timestamp.fractional_seconds(), static_cast<uint64_t>(0.25 * TwoToSixtyFour));
}

}  // namespace
}  // namespace unit
}  // namespace tests
}  // namespace ni