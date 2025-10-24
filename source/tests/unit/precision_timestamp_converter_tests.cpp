#include <gtest/gtest.h>
#include <cstdint>
#include <limits>
#include <server/converters.h>

namespace ni {
namespace tests {
namespace unit {
namespace {

using nidevice_grpc::converters::TicksPerSecond;
using nidevice_grpc::converters::convert_ticks_to_precision_timestamp;
using ::ni::protobuf::types::PrecisionTimestamp;

TEST(PrecisionTimestampConverterTests, ConvertZeroTicks_ReturnsZeroTimestamp)
{
  PrecisionTimestamp timestamp;  
  convert_ticks_to_precision_timestamp(0, &timestamp);
  
  EXPECT_EQ(timestamp.seconds(), 0);
  EXPECT_EQ(timestamp.fractional_seconds(), 0);
}

TEST(PrecisionTimestampConverterTests, ConvertOneSecond_ReturnsOneSecondZeroFractional)
{
  PrecisionTimestamp timestamp;  
  convert_ticks_to_precision_timestamp(TicksPerSecond, &timestamp);
  
  EXPECT_EQ(timestamp.seconds(), 1);
  EXPECT_EQ(timestamp.fractional_seconds(), 0);
}

TEST(PrecisionTimestampConverterTests, ConvertHalfSecond_ReturnsCorrectFractionalSeconds)
{
  PrecisionTimestamp timestamp; 
  convert_ticks_to_precision_timestamp(0.5 * TicksPerSecond, &timestamp);
  
  EXPECT_EQ(timestamp.seconds(), 0);
  EXPECT_NEAR(timestamp.fractional_seconds(), 0.5 * UINT64_MAX, 1);
}

TEST(PrecisionTimestampConverterTests, ConvertQuarterSecond_ReturnsCorrectFractionalSeconds)
{
  PrecisionTimestamp timestamp;  
  convert_ticks_to_precision_timestamp(0.25 * TicksPerSecond, &timestamp);
  
  EXPECT_EQ(timestamp.seconds(), 0);
  EXPECT_NEAR(timestamp.fractional_seconds(), 0.25 * UINT64_MAX, 1);
}

TEST(PrecisionTimestampConverterTests, ConvertThreeQuartersSecond_ReturnsCorrectFractionalSeconds)
{
  PrecisionTimestamp timestamp;  
  convert_ticks_to_precision_timestamp(0.75 * TicksPerSecond, &timestamp);
  
  EXPECT_EQ(timestamp.seconds(), 0);
  EXPECT_NEAR(timestamp.fractional_seconds(), 0.75 * UINT64_MAX, 1);
}

TEST(PrecisionTimestampConverterTests, ConvertOneAndHalfSeconds_ReturnsCorrectSecondsAndFractional)
{
  PrecisionTimestamp timestamp;  
  convert_ticks_to_precision_timestamp(1.5 * TicksPerSecond, &timestamp);
  
  EXPECT_EQ(timestamp.seconds(), 1);
  EXPECT_NEAR(timestamp.fractional_seconds(), 0.5 * UINT64_MAX, 1);
}

TEST(PrecisionTimestampConverterTests, ConvertSingleTick_ReturnsCorrectFractionalSeconds)
{
  PrecisionTimestamp timestamp;  
  convert_ticks_to_precision_timestamp(1, &timestamp);
  
  EXPECT_EQ(timestamp.seconds(), 0);
  // Single tick (1e-7 seconds) should equal this specific fractional value
  EXPECT_NEAR(timestamp.fractional_seconds(), 1844674407371, 1);
}

TEST(PrecisionTimestampConverterTests, ConvertLargeTimestamp_HandlesCorrectly)
{
  PrecisionTimestamp timestamp;
  // Year 2024 approximately: many seconds since year 1 AD plus some fractional part  
  convert_ticks_to_precision_timestamp(63861753600.25 * TicksPerSecond, &timestamp);
  
  EXPECT_EQ(timestamp.seconds(), 63861753600LL);
  EXPECT_NEAR(timestamp.fractional_seconds(), 0.25 * UINT64_MAX, 1e-5 * UINT64_MAX);
}

}  // namespace
}  // namespace unit
}  // namespace tests
}  // namespace ni