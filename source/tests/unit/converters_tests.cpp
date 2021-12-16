#define NOMINMAX

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <server/converters.h>

#include <array>

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

TEST(ConvertersTests, AllEqualSizesAllowOptional_Match)
{
  constexpr auto SIZES = std ::array<int, 3>{3, 3, 3};
  const auto calculation = calculate_linked_array_size(SIZES, true);

  EXPECT_EQ(3, calculation.size);
  EXPECT_EQ(MatchState::MATCH, calculation.match_state);
}

TEST(ConvertersTests, AllEqualSizesDisallowOptional_Match)
{
  constexpr auto SIZES = std ::array<int, 3>{3, 3, 3};
  const auto calculation = calculate_linked_array_size(SIZES, false);

  EXPECT_EQ(3, calculation.size);
  EXPECT_EQ(MatchState::MATCH, calculation.match_state);
}

TEST(ConvertersTests, DifferentSizesAllowOptional_Mismatch)
{
  constexpr auto SIZES = std ::array<int, 5>{4, 3, 0, 3, 3};
  const auto calculation = calculate_linked_array_size(SIZES, true);

  EXPECT_EQ(MatchState::MISMATCH, calculation.match_state);
}

TEST(ConvertersTests, DifferentSizesDisallowOptional_Mismatch)
{
  constexpr auto SIZES = std ::array<int, 5>{3, 3, 4};
  const auto calculation = calculate_linked_array_size(SIZES, false);

  EXPECT_EQ(MatchState::MISMATCH, calculation.match_state);
}

TEST(ConvertersTests, ZeroSizesAllowOptional_MatchOrZero)
{
  constexpr auto SIZES = std ::array<int, 5>{3, 0, 3, 0, 0};
  const auto calculation = calculate_linked_array_size(SIZES, true);

  EXPECT_EQ(MatchState::MATCH_OR_ZERO, calculation.match_state);
}

TEST(ConvertersTests, ZeroSizesDisallowOptional_Mismatch)
{
  constexpr auto SIZES = std ::array<int, 5>{3, 0, 3, 3, 3};
  const auto calculation = calculate_linked_array_size(SIZES, false);

  EXPECT_EQ(MatchState::MISMATCH, calculation.match_state);
}

}  // namespace
}  // namespace unit
}  // namespace tests
}  // namespace ni