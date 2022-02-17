#ifndef NIDEVICE_GRPC_TESTS_RFMX_EXPECT_MACROS
#define NIDEVICE_GRPC_TESTS_RFMX_EXPECT_MACROS

#define EXPECT_NO_ERROR_MESSAGE(session, response)                                                \
  if (1) {                                                                                        \
    if (response.status() != 0) {                                                                 \
      auto error_message_response = client::get_error_string(stub(), session, response.status()); \
      EXPECT_EQ("", std::string(error_message_response.error_description().c_str()));             \
    }                                                                                             \
    auto error_response = client::get_error(stub(), session);                                     \
    EXPECT_EQ("", std::string(error_response.error_description().c_str()));                       \
  }

#define EXPECT_RESPONSE_SUCCESS(response) \
  if (1) {                                \
    EXPECT_EQ(0, (response).status());    \
  }

#define EXPECT_RESPONSE_WARNING(expected_warning, response) \
  if (1) {                                                  \
    EXPECT_GT(expected_warning, 0);                         \
    EXPECT_EQ(expected_warning, response.status());         \
  }

#define EXPECT_RESPONSE_ERROR(expected_error, response) \
  if (1) {                                              \
    EXPECT_LT(expected_error, 0);                       \
    EXPECT_EQ(expected_error, response.status());       \
  }

#define EXPECT_SUCCESS(session_, response_)     \
  ([this](auto& session, auto& response) {      \
    EXPECT_RESPONSE_SUCCESS(response);          \
    EXPECT_NO_ERROR_MESSAGE(session, response); \
    return response;                            \
  })((session_), (response_))

#define EXPECT_ERROR(expected_error, message_substring, session, response) \
  if (1) {                                                                 \
    EXPECT_RESPONSE_ERROR(expected_error, response)                        \
    const auto error = client::get_error(stub(), session);                 \
    EXPECT_THAT(error.error_description(), HasSubstr(message_substring));  \
  }

#define EXPECT_WARNING(expected_warning, message_substring, session, response) \
  if (1) {                                                                     \
    EXPECT_RESPONSE_WARNING(expected_warning, response)                        \
    const auto error = client::get_error(stub(), session);                     \
    EXPECT_THAT(error.error_description(), HasSubstr(message_substring));      \
  }

#define GET_ATTR_(get_attr_fn, session_, selector_string_, attribute_id_)                \
  ([this](auto& session, auto& selector_string, auto attribute_id) {                     \
    auto response = client::get_attr_fn(stub(), session, selector_string, attribute_id); \
    EXPECT_SUCCESS(session, response);                                                   \
    return response.attr_val();                                                          \
  })((session_), (selector_string_), (attribute_id_))

#define GET_ATTR_I32(session_, selector_string_, attribute_id_) \
  GET_ATTR_(get_attribute_i32, session_, selector_string_, attribute_id_)

#define GET_ATTR_F64(session_, selector_string_, attribute_id_) \
  GET_ATTR_(get_attribute_f64, session_, selector_string_, attribute_id_)

#define GET_ATTR_STR(session_, selector_string_, attribute_id_) \
  GET_ATTR_(get_attribute_string, session_, selector_string_, attribute_id_)

#endif  // NIDEVICE_GRPC_TESTS_RFMX_EXPECT_MACROS
