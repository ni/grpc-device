#ifndef TEST_HELPERS
#define TEST_HELPERS

#include <gmock/gmock.h>
#include <gtest/gtest.h>

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

#define EXPECT_THROW_GRPC_CANCELLED(statement_)                                \
  EXPECT_THROW({                                                               \
    try {                                                                      \
      statement_;                                                              \
    }                                                                          \
    catch (const nidevice_grpc::experimental::client::grpc_driver_error& ex) { \
      EXPECT_EQ(::grpc::CANCELLED, ex.StatusCode());                           \
      throw;                                                                   \
    }                                                                          \
  }, nidevice_grpc::experimental::client::grpc_driver_error)

#define EXPECT_DRIVER_ERROR(exception_, expected_error_)             \
  do {                                                               \
    EXPECT_EQ(::grpc::StatusCode::UNKNOWN, exception_.StatusCode()); \
    EXPECT_LT(expected_error_, 0);                                   \
    EXPECT_EQ(expected_error_, get_driver_error(exception_));        \
  } while(false)

#define EXPECT_DRIVER_ERROR_WITH_SUBSTR(exception_, expected_error_, message_substring_) \
  do {                                                                                   \
    EXPECT_DRIVER_ERROR(exception_, expected_error_);                                    \
    EXPECT_THAT(exception_.what(), ::testing::HasSubstr(message_substring_));            \
  } while(false)

inline int get_driver_error(const std::multimap<std::string, std::string>& metadata)
{
  auto iterator = metadata.find("ni-error");
  if (iterator != metadata.end())
  {
    return std::stoi(iterator->second);
  }
  ADD_FAILURE() << "ni-error key not found in metadata.";
  return 0;
}

inline int get_driver_error(const std::multimap<grpc::string_ref, grpc::string_ref>& metadata)
{
  auto iterator = metadata.find("ni-error");
  if (iterator != metadata.end())
  {
    // grpc::string_ref is not NUL-terminated, so make a copy.
    std::string value(iterator->second.begin(), iterator->second.end());
    return std::stoi(value);
  }
  ADD_FAILURE() << "ni-error key not found in metadata.";
  return 0;
}

inline int get_driver_error(const nidevice_grpc::experimental::client::grpc_driver_error& ex)
{
  return get_driver_error(ex.Trailers());
}

#endif
