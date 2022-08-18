#define NOMINMAX

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <server/converters.h>

#include <array>
#include <nlohmann/json.hpp>

using namespace nidevice_grpc::converters;
using namespace ::testing;
using nlohmann::json;

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

TEST(ConvertersTests, NullableVectorInitializedNull_GetData_ReturnsNull)
{
  const auto vec = nullable_vector<int32_t>(nullptr);

  const auto data = vec.data();

  EXPECT_EQ(nullptr, data);
}

TEST(ConvertersTests, NullableVectorInitializedWithData_GetData_ReturnPointerToData)
{
  constexpr auto DATA = std::array<int32_t, 4>{1, 2, 3, 4};
  const auto vec = nullable_vector<int32_t>({DATA.cbegin(), DATA.cend()});

  const auto data = vec.data();

  EXPECT_THAT(std::vector<int32_t>(data, data + DATA.size()), ElementsAreArray(DATA));
}

TEST(ConvertersTests, NullableVectorInitializedWithData_AssignNull_DataIsNull)
{
  auto vec = nullable_vector<int32_t>({1, 2, 3, 4});

  vec = nullptr;

  EXPECT_EQ(nullptr, vec.data());
}

TEST(ConvertersTests, NullableVectorInitializedWithData_ConditionallyAssignNull_DataIsNull)
{
  constexpr auto CONDITION = false;
  auto vec = nullable_vector<int32_t>({1, 2, 3, 4});

  vec = CONDITION ? std::move(vec) : nullptr;

  EXPECT_EQ(nullptr, vec.data());
}

TEST(ConvertersTests, NullableVectorInitializedWithData_ConditionallyAssignMovedSelf_DataIsPointerToData)
{
  constexpr auto CONDITION = true;
  constexpr auto DATA = std::array<int32_t, 4>{1, 2, 3, 4};
  auto vec = nullable_vector<int32_t>({DATA.cbegin(), DATA.cend()});

  vec = CONDITION ? std::move(vec) : nullptr;

  const auto data = vec.data();
  EXPECT_THAT(std::vector<int32_t>(data, data + DATA.size()), ElementsAreArray(DATA));
}

enum TestEnum {
  ONE = 1,
  TWO = 2,
  FOUR = 4
};

TEST(ConvertersTests, EnumArray_ConvertBitfieldAsEnumArrayInput_ReturnsOrOfValues)
{
  const auto input = std::vector<TestEnum>{TestEnum::ONE, TestEnum::FOUR};

  const auto converted = convert_bitfield_as_enum_array_input(input, 0);

  EXPECT_EQ(0x1 | 0x4, converted);
}

TEST(ConvertersTests, RawValue_ConvertBitfieldAsEnumArrayInput_ReturnsRawValue)
{
  constexpr auto INPUT_RAW = 0x7;

  const auto converted = convert_bitfield_as_enum_array_input(std::vector<TestEnum>{}, INPUT_RAW);

  EXPECT_EQ(INPUT_RAW, converted);
}

TEST(ConvertersTests, ArrayAndRawValue_ConvertBitfieldAsEnumArrayInput_ReturnsOrOfValues)
{
  constexpr auto INPUT_RAW = 0x8;
  const auto input_array = std::vector<TestEnum>{TestEnum::TWO, TestEnum::FOUR};

  const auto converted = convert_bitfield_as_enum_array_input(input_array, INPUT_RAW);

  EXPECT_EQ(0x2 | 0x4 | 0x8, converted);
}

TEST(ConvertersTests, ApiErrorToStatus_Parse_IncludesCodeAndUnknownMessage)
{
  const auto TEST_STATUS = -12345;
  const auto EXPECTED_MESSAGE = std::string("Unknown");

  auto error_message = nidevice_grpc::ApiErrorToStatus(TEST_STATUS).error_message();
  auto parsed = json::parse(error_message);

  EXPECT_EQ(TEST_STATUS, parsed.value("code", 0));
  EXPECT_EQ(EXPECTED_MESSAGE, parsed.value("message", ""));
}

TEST(ConvertersTests, ApiErrorAndDescriptionToStatus_Parse_IncludesCodeAndMessage)
{
  const auto TEST_STATUS = -12345;
  const auto TEST_MESSAGE = std::string("regular_string");
  std::string description(TEST_MESSAGE);

  auto error_message = nidevice_grpc::ApiErrorAndDescriptionToStatus(TEST_STATUS, description).error_message();
  auto parsed = json::parse(error_message);

  EXPECT_EQ(TEST_STATUS, parsed.value("code", 0));
  EXPECT_EQ(TEST_MESSAGE, parsed.value("message", ""));
}

TEST(ConvertersTests, CustomField_ApiErrorAndDescriptionToStatus_IncludesCustomField)
{
  std::string empty_description;
  nlohmann::json jsonError{{"custom", 1}};

  auto error_message = nidevice_grpc::ApiErrorAndDescriptionToStatus(0, empty_description, jsonError).error_message();

  EXPECT_THAT(error_message, HasSubstr("\"custom\":1"));
}

TEST(ConvertersTests, QuotedLocalizedDescription_ApiErrorAndDescriptionToStatus_MessageIsEncoded)
{
  const auto TEST_MESSAGE = std::string("\"chaîne 😀 localisée\"");
  std::string description(TEST_MESSAGE);

  auto error_message = nidevice_grpc::ApiErrorAndDescriptionToStatus(0, description).error_message();
  auto parsed = json::parse(error_message);

  EXPECT_THAT(error_message, Not(HasSubstr(TEST_MESSAGE)));
  EXPECT_EQ(TEST_MESSAGE, parsed.value("message", ""));
}

}  // namespace
}  // namespace unit
}  // namespace tests
}  // namespace ni
