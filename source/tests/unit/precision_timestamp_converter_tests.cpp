#include <gtest/gtest.h>
#include <cstdint>
#include <limits>
#include <server/converters.h>

namespace ni {
namespace tests {
namespace unit {
namespace {

using nidevice_grpc::converters::TicksPerSecond;
using nidevice_grpc::converters::convert_ticks_to_btf_precision_timestamp;
using ::ni::protobuf::types::PrecisionTimestamp;

const int64_t SecondsFromYear0001ToJan2004 = 63240134400LL;  // Seconds from Jan 1, 0001 to Jan 1, 2004
const int64_t SecondsFromYear1904ToJan2004 = 3199342400LL;   // Seconds from Jan 1, 1904 to Jan 1, 2004
const int64_t TicksForJan2004 = SecondsFromYear0001ToJan2004 * TicksPerSecond;  // Ticks from 0001 to Jan 1, 2004
const double TestTolerance = 1e-5 * UINT64_MAX;  // Tolerance for fractional seconds comparisons

TEST(PrecisionTimestampConverterTests, ConvertZeroTicks_ReturnsZeroTimestamp)
{
  PrecisionTimestamp timestamp;  
  convert_ticks_to_btf_precision_timestamp(0, &timestamp);
  
  EXPECT_LT(timestamp.seconds(), 0);  // Should be negative (before 1904)
  EXPECT_EQ(timestamp.fractional_seconds(), 0);
}

TEST(PrecisionTimestampConverterTests, ConvertJan2004_ReturnsCorrectTimestamp)
{
  PrecisionTimestamp timestamp;  
  convert_ticks_to_btf_precision_timestamp(TicksForJan2004, &timestamp);
  
  EXPECT_EQ(timestamp.seconds(), SecondsFromYear1904ToJan2004);
  EXPECT_EQ(timestamp.fractional_seconds(), 0);
}

TEST(PrecisionTimestampConverterTests, ConvertOneSecond_ReturnsOneSecondZeroFractional)
{
  PrecisionTimestamp timestamp;  
  convert_ticks_to_btf_precision_timestamp(TicksForJan2004 + TicksPerSecond, &timestamp);
  
  EXPECT_EQ(timestamp.seconds(), SecondsFromYear1904ToJan2004 + 1);
  EXPECT_EQ(timestamp.fractional_seconds(), 0);
}

TEST(PrecisionTimestampConverterTests, ConvertHalfSecond_ReturnsCorrectFractionalSeconds)
{
  PrecisionTimestamp timestamp; 
  convert_ticks_to_btf_precision_timestamp(TicksForJan2004 + 0.5 * TicksPerSecond, &timestamp);
  
  EXPECT_EQ(timestamp.seconds(), SecondsFromYear1904ToJan2004);
  EXPECT_NEAR(timestamp.fractional_seconds(), 0.5 * UINT64_MAX, TestTolerance);
}

TEST(PrecisionTimestampConverterTests, ConvertQuarterSecond_ReturnsCorrectFractionalSeconds)
{
  PrecisionTimestamp timestamp;  
  convert_ticks_to_btf_precision_timestamp(TicksForJan2004 + 0.25 * TicksPerSecond, &timestamp);
  
  EXPECT_EQ(timestamp.seconds(), SecondsFromYear1904ToJan2004);
  EXPECT_NEAR(timestamp.fractional_seconds(), 0.25 * UINT64_MAX, TestTolerance);
}

TEST(PrecisionTimestampConverterTests, ConvertThreeQuartersSecond_ReturnsCorrectFractionalSeconds)
{
  PrecisionTimestamp timestamp;  
  convert_ticks_to_btf_precision_timestamp(TicksForJan2004 + 0.75 * TicksPerSecond, &timestamp);
  
  EXPECT_EQ(timestamp.seconds(), SecondsFromYear1904ToJan2004);
  EXPECT_NEAR(timestamp.fractional_seconds(), 0.75 * UINT64_MAX, TestTolerance);
}

TEST(PrecisionTimestampConverterTests, ConvertOneAndHalfSeconds_ReturnsCorrectSecondsAndFractional)
{
  PrecisionTimestamp timestamp;  
  convert_ticks_to_btf_precision_timestamp(TicksForJan2004 + 1.5 * TicksPerSecond, &timestamp);
  
  EXPECT_EQ(timestamp.seconds(), SecondsFromYear1904ToJan2004 + 1);
  EXPECT_NEAR(timestamp.fractional_seconds(), 0.5 * UINT64_MAX, TestTolerance);
}

}  // namespace
}  // namespace unit
}  // namespace tests
}  // namespace ni