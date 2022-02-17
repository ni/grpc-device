#ifndef NIDEVICE_GRPC_TESTS_RFMX_EXPECT_MACROS
#define NIDEVICE_GRPC_TESTS_RFMX_EXPECT_MACROS

#define CHECK_ERROR(session)                                          \
  if (1) {                                                            \
    auto response = client::get_error(stub(), session);               \
    EXPECT_EQ("", std::string(response.error_description().c_str())); \
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

#define EXPECT_SUCCESS(session, response) \
  if (1) {                                \
    EXPECT_RESPONSE_SUCCESS(response)     \
    CHECK_ERROR(session);                 \
  }

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

#endif  // NIDEVICE_GRPC_TESTS_RFMX_EXPECT_MACROS
