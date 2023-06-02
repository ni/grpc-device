#ifndef NIDEVICE_GRPC_TESTS_RFMX_EXPECT_MACROS
#define NIDEVICE_GRPC_TESTS_RFMX_EXPECT_MACROS

#include <gmock/gmock.h>

#include <nlohmann/json.hpp>

#include "tests/utilities/test_helpers.h"

#define EXPECT_NO_ERROR_MESSAGE(session, response)                                                  \
  if (1) {                                                                                          \
    if ((response).status() != 0) {                                                                 \
      auto error_message_response = client::get_error_string(stub(), session, (response).status()); \
      EXPECT_EQ("", std::string(error_message_response.error_description().c_str()));               \
    }                                                                                               \
    auto error_response = client::get_error(stub(), session);                                       \
    EXPECT_EQ("", std::string(error_response.error_description().c_str()));                         \
  }

#define EXPECT_ERROR_SUBSTRING(message_substring, session)                \
  if (1) {                                                                \
    const auto error = client::get_error(stub(), (session));              \
    EXPECT_THAT(error.error_description(), HasSubstr(message_substring)); \
  }

#define EXPECT_RESPONSE_SUCCESS(response) \
  if (1) {                                \
    EXPECT_EQ(0, (response).status());    \
  }

#define EXPECT_RESPONSE_WARNING(expected_warning, response) \
  if (1) {                                                  \
    EXPECT_GT(expected_warning, 0);                         \
    EXPECT_EQ(expected_warning, (response).status());       \
  }

#define EXPECT_SUCCESS(session_, response_)     \
  ([this](auto& session, auto& response) {      \
    EXPECT_RESPONSE_SUCCESS(response);          \
    EXPECT_NO_ERROR_MESSAGE(session, response); \
    return response;                            \
  })((session_), (response_))

#define EXPECT_ERROR(expected_error_, message_substring_, session_, response_call_) \
  EXPECT_THROW_DRIVER_ERROR_WITH_SUBSTR(response_call_, expected_error_, message_substring_)

#define EXPECT_WARNING(expected_warning_, message_substring_, session_, response_)               \
  ([this](auto expected_warning, const auto& message_substring, auto& session, auto& response) { \
    EXPECT_RESPONSE_WARNING(expected_warning, response)                                          \
    EXPECT_ERROR_SUBSTRING(message_substring, session);                                          \
    return response;                                                                             \
  })(expected_warning_, message_substring_, session_, response_)

#define GET_ATTR_(get_attr_fn, session_, selector_string_, attribute_id_)                \
  ([this](auto& session, auto& selector_string, auto attribute_id) {                     \
    auto response = client::get_attr_fn(stub(), session, selector_string, attribute_id); \
    EXPECT_SUCCESS(session, response);                                                   \
    return response.attr_val();                                                          \
  })(session_, selector_string_, attribute_id_)

#define GET_ATTR_I32(session_, selector_string_, attribute_id_) \
  GET_ATTR_(get_attribute_i32, session_, selector_string_, attribute_id_)

#define GET_ATTR_F64(session_, selector_string_, attribute_id_) \
  GET_ATTR_(get_attribute_f64, session_, selector_string_, attribute_id_)

#define GET_ATTR_STR(session_, selector_string_, attribute_id_) \
  GET_ATTR_(get_attribute_string, session_, selector_string_, attribute_id_)

#endif  // NIDEVICE_GRPC_TESTS_RFMX_EXPECT_MACROS
