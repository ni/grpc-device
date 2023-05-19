#ifndef TEST_HELPERS
#define TEST_HELPERS

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <optional>

#include "client_helpers.h"

#define EXPECT_THROW_DRIVER_ERROR(statement_, expected_error_)                 \
  EXPECT_THROW({                                                               \
    try {                                                                      \
      statement_;                                                              \
    }                                                                          \
    catch (const nidevice_grpc::experimental::client::grpc_driver_error& ex) { \
      EXPECT_DRIVER_ERROR(ex, expected_error_);                                \
      throw;                                                                   \
    }                                                                          \
  }, nidevice_grpc::experimental::client::grpc_driver_error)

#define EXPECT_THROW_DRIVER_ERROR_WITH_SUBSTR(statement_, expected_error_, message_substring_) \
  EXPECT_THROW({                                                                               \
    try {                                                                                      \
      statement_;                                                                              \
    }                                                                                          \
    catch (const nidevice_grpc::experimental::client::grpc_driver_error& ex) {                 \
      EXPECT_DRIVER_ERROR_WITH_SUBSTR(ex, expected_error_, message_substring_);                \
      throw;                                                                                   \
    }                                                                                          \
  }, nidevice_grpc::experimental::client::grpc_driver_error)

#define EXPECT_DRIVER_ERROR(exception_, expected_error_)             \
  do {                                                               \
    EXPECT_EQ(::grpc::StatusCode::UNKNOWN, exception_.StatusCode()); \
    EXPECT_LT(expected_error_, 0);                                   \
    auto driver_error = get_driver_error(exception_);                \
    EXPECT_THAT(driver_error, ::testing::Optional(expected_error_)); \
  } while(false)

#define EXPECT_DRIVER_ERROR_WITH_SUBSTR(exception_, expected_error_, message_substring_) \
  do {                                                                                   \
    EXPECT_DRIVER_ERROR(exception_, expected_error_);                                    \
    EXPECT_THAT(exception_.what(), ::testing::HasSubstr(message_substring_));            \
  } while(false)

inline std::optional<int> get_driver_error(const std::multimap<std::string, std::string>& metadata)
{
  auto iterator = metadata.find("ni-error");
  if (iterator != metadata.end())
  {
    return std::stoi(iterator->second);
  }
  return std::nullopt;
}

inline std::optional<int> get_driver_error(const std::multimap<grpc::string_ref, grpc::string_ref>& metadata)
{
  auto iterator = metadata.find("ni-error");
  if (iterator != metadata.end())
  {
    // grpc::string_ref is not NUL-terminated, so make a copy.
    std::string value(iterator->second.begin(), iterator->second.end());
    return std::stoi(value);
  }
  return std::nullopt;
}

inline std::optional<int> get_driver_error(const nidevice_grpc::experimental::client::grpc_driver_error& ex)
{
  return get_driver_error(ex.Trailers());
}

#endif
