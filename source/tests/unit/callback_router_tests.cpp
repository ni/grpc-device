#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <server/callback_router.h>

#include <cstdint>
#include <string>

using namespace nidevice_grpc;
using namespace ::testing;

namespace ni {
namespace tests {
namespace unit {

const int TEST_SUCCESS = 0;
static void* BOGUS_TOKEN = reinterpret_cast<void*>(123456);

using TestStatus = int32_t;
using IntCallbackRouter = CallbackRouter<TestStatus, int32_t>;
using BoolAndStringCallbackRouter = CallbackRouter<TestStatus, bool, std::string>;

using MockIntHandler = MockFunction<TestStatus(int32_t)>;
using MockBoolAndStringHandler = MockFunction<TestStatus(bool, std::string)>;

template <typename THandler, typename... TArgs>
void EXPECT_CALLBACK(THandler& handler, TArgs... args)
{
  EXPECT_CALL(handler, Call(args...))
      .WillOnce(Return(TEST_SUCCESS));
}

// FAIL is a returning macro so it cannot be used in non-void functions.
void fail(const std::string& message)
{
  FAIL() << message;
}

TestStatus fail_on_callback(...)
{
  fail("unexpected callback");
  return 0;
}

TEST(CallbackRouterTests, IntCallbackHandlerRegistered_HandleCallback_CallsHandler)
{
  MockIntHandler handler;
  const int32_t CALLBACK_VAL = 0x1234;
  auto registration = IntCallbackRouter::register_handler(handler.AsStdFunction());

  EXPECT_CALLBACK(handler, CALLBACK_VAL);
  auto result = IntCallbackRouter::handle_callback(CALLBACK_VAL, registration->token());

  EXPECT_EQ(TEST_SUCCESS, result);
}

TEST(CallbackRouterTests, IntCallbackHandlerRegistered_HandleCallbackMultipleTimes_CallsHandlerMultipleTimes)
{
  MockIntHandler handler;
  auto registration = IntCallbackRouter::register_handler(handler.AsStdFunction());

  const int32_t FIRST_CALLBACK_VAL = 0x1234;
  EXPECT_CALLBACK(handler, FIRST_CALLBACK_VAL);
  auto first_result = IntCallbackRouter::handle_callback(FIRST_CALLBACK_VAL, registration->token());
  const int32_t SECOND_CALLBACK_VAL = 0xABAB;
  EXPECT_CALLBACK(handler, SECOND_CALLBACK_VAL);
  auto second_result = IntCallbackRouter::handle_callback(SECOND_CALLBACK_VAL, registration->token());

  EXPECT_EQ(TEST_SUCCESS, first_result);
  EXPECT_EQ(TEST_SUCCESS, second_result);
}

TEST(CallbackRouterTests, BoolAndStringCallbackHandlerRegistered_HandleCallback_CallsHandler)
{
  MockBoolAndStringHandler handler;
  auto registration = BoolAndStringCallbackRouter::register_handler(handler.AsStdFunction());

  const bool CALLBACK_BOOL = true;
  const std::string CALLBACK_STRING = "HelloCallback";
  EXPECT_CALLBACK(handler, CALLBACK_BOOL, CALLBACK_STRING);
  auto result = BoolAndStringCallbackRouter::handle_callback(CALLBACK_BOOL, CALLBACK_STRING, registration->token());

  EXPECT_EQ(TEST_SUCCESS, result);
}

TEST(CallbackRouterTests, BoolAndStringCallbackHandlerRegistered_HandleCallbackWithBogusAsyncOperationToken_DoesNotCallHandler)
{
  auto registration = BoolAndStringCallbackRouter::register_handler(
      fail_on_callback);

  auto result = BoolAndStringCallbackRouter::handle_callback(false, "MessageToNoOne", BOGUS_TOKEN);

  EXPECT_EQ(TEST_SUCCESS, result);
}

TEST(CallbackRouterTests, MultipleHandlersRegistered_HandleOneCallback_SignalsCorrectHandler)
{
  MockBoolAndStringHandler handler;
  auto first_registration = BoolAndStringCallbackRouter::register_handler(
      fail_on_callback);
  auto second_registration = BoolAndStringCallbackRouter::register_handler(
      handler.AsStdFunction());

  const bool CALLBACK_BOOL = true;
  const std::string CALLBACK_STRING = "HelloSecondHandler";
  EXPECT_CALLBACK(handler, CALLBACK_BOOL, CALLBACK_STRING);
  auto result = BoolAndStringCallbackRouter::handle_callback(CALLBACK_BOOL, CALLBACK_STRING, second_registration->token());

  EXPECT_EQ(TEST_SUCCESS, result);
}

TEST(CallbackRouterTests, MultipleHandlersRegistered_HandleBothCallbacks_SignalsBothHandler)
{
  MockBoolAndStringHandler first_handler;
  MockBoolAndStringHandler second_handler;
  auto first_registration = BoolAndStringCallbackRouter::register_handler(
      first_handler.AsStdFunction());
  auto second_registration = BoolAndStringCallbackRouter::register_handler(
      second_handler.AsStdFunction());

  const bool FIRST_CALLBACK_BOOL = false;
  const std::string FIRST_CALLBACK_STRING = "HelloFirstHandler";
  EXPECT_CALLBACK(first_handler, FIRST_CALLBACK_BOOL, FIRST_CALLBACK_STRING);
  auto first_result = BoolAndStringCallbackRouter::handle_callback(FIRST_CALLBACK_BOOL, FIRST_CALLBACK_STRING, first_registration->token());
  const bool SECOND_CALLBACK_BOOL = true;
  const std::string SECOND_CALLBACK_STRING = "HelloSecondHandler";
  EXPECT_CALLBACK(second_handler, SECOND_CALLBACK_BOOL, SECOND_CALLBACK_STRING);
  auto second_result = BoolAndStringCallbackRouter::handle_callback(SECOND_CALLBACK_BOOL, SECOND_CALLBACK_STRING, second_registration->token());

  EXPECT_EQ(TEST_SUCCESS, first_result);
  EXPECT_EQ(TEST_SUCCESS, second_result);
}

TEST(CallbackRouterTests, CallbackRegisteredAndUnregistered_HandleCallback_DoesNotCallHandler)
{
  CallbackRegistration::Token token;
  {
    auto registration = BoolAndStringCallbackRouter::register_handler(
        fail_on_callback);
    token = registration->token();
  }

  auto result = BoolAndStringCallbackRouter::handle_callback(false, "MessageToNoOne", token);

  EXPECT_EQ(TEST_SUCCESS, result);
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
