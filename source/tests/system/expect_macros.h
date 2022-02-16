#ifndef NIDEVICE_GRPC_TESTS_EXPECT_MACROS
#define NIDEVICE_GRPC_TESTS_EXPECT_MACROS

namespace ni {
namespace tests {
namespace system {

#define CHECK_ERROR(session)                                          \
  if (1) {                                                            \
    auto response = client::get_error(stub(), session);               \
    EXPECT_EQ("", std::string(response.error_description().c_str())); \
  }

#define EXPECT_RESPONSE_SUCCESS(response) \
  if (1) {                                \
    EXPECT_EQ(0, (response).status());    \
  }

#define EXPECT_WARNING(expected_warning, response)  \
  if (1) {                                          \
    EXPECT_EQ(expected_warning, response.status()); \
  }

#define EXPECT_SUCCESS(session, response) \
  if (1) {                                \
    EXPECT_RESPONSE_SUCCESS(response)     \
    CHECK_ERROR(session);                 \
  }

#define EXPECT_ERROR(expected_error, message_substring, session, response_) \
  if (1) {                                                                  \
    auto response = (response_);                                            \
    EXPECT_EQ(expected_error, response.status());                           \
    const auto error = client::get_error(stub(), session);                  \
    EXPECT_THAT(error.error_description(), HasSubstr(message_substring));   \
  }

}  // namespace system
}  // namespace tests
}  // namespace ni

#endif  // NIDEVICE_GRPC_TESTS_EXPECT_MACROS
