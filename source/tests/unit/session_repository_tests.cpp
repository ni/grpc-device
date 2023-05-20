#include <gtest/gtest.h>
#include <server/exceptions.h>
#include <server/semaphore.h>
#include <server/session_repository.h>

namespace ni {
namespace tests {
namespace unit {

// Starting with session_name 1 isn't functionally important, but we want to start with
// something intentional. NOT an uninitialized uint.
constexpr auto EXPECTED_FIRST_SESSION_ID = 1;

TEST(SessionRepositoryTests, AddSessionWithNonZeroStatus_ReturnsStatusAndDoesNotStoreSession)
{
  nidevice_grpc::SessionRepository session_repository;
  std::string session_name = "42";
  int status = session_repository.add_session(
      session_name,
      [session_name]() { return 1; },
      NULL);

  EXPECT_EQ(status, 1);
  EXPECT_EQ("" , session_repository.access_session(session_name));
}

TEST(SessionRepositoryTests, AddSessionWithNonZeroStatus_InitializedNewSessionIsFalse)
{
  nidevice_grpc::SessionRepository session_repository;
  std::string session_name = "42";
  bool initialized_new_session;
  int status = session_repository.add_session(
      session_name,
      [session_name]() { return 1; },
      NULL,
      nidevice_grpc::SESSION_INITIALIZATION_BEHAVIOR_UNSPECIFIED,
      &initialized_new_session);

  EXPECT_FALSE(initialized_new_session);
}

TEST(SessionRepositoryTests, AddSession_StoresSessionWithGivenId)
{
  nidevice_grpc::SessionRepository session_repository;
  std::string session_name;
  bool initialized_new_session;
  int status = session_repository.add_session(
      session_name,
      []() { return 0; },
      NULL,
      nidevice_grpc::SESSION_INITIALIZATION_BEHAVIOR_UNSPECIFIED,
      &initialized_new_session);

  EXPECT_EQ(status, 0);
  EXPECT_EQ(session_repository.access_session(session_name), session_name);
  EXPECT_TRUE(initialized_new_session);
}

TEST(SessionRepositoryTests, NoSessions_AddSessionWithAttachToExistingBehavior_ExceptionThrown)
{
  std::string session_name = "session_name";
  nidevice_grpc::SessionRepository session_repository;

  EXPECT_THROW({
    try {
      session_repository.add_session(
          session_name,
          []() { return 0; },
          NULL,
          nidevice_grpc::SESSION_INITIALIZATION_BEHAVIOR_ATTACH_TO_EXISTING);
    }
    catch (const nidevice_grpc::NonDriverException& e) {
      auto exception_status = e.GetStatus();
      EXPECT_EQ(::grpc::StatusCode::FAILED_PRECONDITION, exception_status.error_code());
      throw;
    }
  }, nidevice_grpc::NonDriverException);
}

TEST(SessionRepositoryTests, AddNamedSession_StoresSessionWithGivenIdAndName)
{
  std::string session_name = "session_name";
  nidevice_grpc::SessionRepository session_repository;
  bool initialized_new_session;
  int status = session_repository.add_session(
      session_name,
      []() { return 0; },
      NULL,
      nidevice_grpc::SESSION_INITIALIZATION_BEHAVIOR_UNSPECIFIED,
      &initialized_new_session);

  EXPECT_EQ(status, 0);
  EXPECT_EQ(session_repository.access_session(session_name), session_name);
  EXPECT_TRUE(initialized_new_session);
}

TEST(SessionRepositoryTests, UnnamedSessionAdded_RemoveSession_RemovesSession)
{
  nidevice_grpc::SessionRepository session_repository;
  std::string session_name;
  session_repository.add_session(
      session_name,
      []() { return 0; },
      NULL);

  session_repository.remove_session(session_name);

  EXPECT_EQ("",  session_repository.access_session(session_name));
}

TEST(SessionRepositoryTests, NamedSessionAdded_RemoveSession_RemovesSession)
{
  std::string session_name = "session_name";
  nidevice_grpc::SessionRepository session_repository;
  int status = session_repository.add_session(
      session_name,
      []() { return 0; },
      NULL);

  session_repository.remove_session(session_name);

  EXPECT_EQ("", session_repository.access_session(session_name));
}

TEST(SessionRepositoryTests, NamedSessionAdded_AddSessionWithSameName_ReturnsFirstSessionIdAndDoesNotCallInit)
{
  std::string session_name = "session_name";
  nidevice_grpc::SessionRepository session_repository;
  session_repository.add_session(
      session_name,
      []() { return 0; },
      NULL);

  bool init_called = false;
  bool initialized_new_session;
  session_repository.add_session(
      session_name,
      [init_called]() mutable {
        init_called = true;
        return 0;
      },
      NULL,
      nidevice_grpc::SESSION_INITIALIZATION_BEHAVIOR_UNSPECIFIED,
      &initialized_new_session);

  EXPECT_FALSE(init_called);
  EXPECT_FALSE(initialized_new_session);
}

TEST(SessionRepositoryTests, NamedSessionAdded_AddSessionWithSameNameWithInitializeNewBehavior_ExceptionThrown)
{
  std::string session_name = "session_name";
  nidevice_grpc::SessionRepository session_repository;
  session_repository.add_session(
      session_name,
      []() { return 0; },
      NULL);

  bool init_called = false;
  EXPECT_THROW({
    try {
      session_repository.add_session(
          session_name,
          [init_called]() mutable {
            init_called = true;
            return 0;
          },
          NULL,
          nidevice_grpc::SESSION_INITIALIZATION_BEHAVIOR_INITIALIZE_NEW);
    }
    catch (const nidevice_grpc::NonDriverException& e) {
      auto exception_status = e.GetStatus();
      EXPECT_EQ(::grpc::StatusCode::ALREADY_EXISTS, exception_status.error_code());
      throw;
    }
  }, nidevice_grpc::NonDriverException);
}

TEST(SessionRepositoryTests, NamedSessionAdded_ResetServer_RemovesSession)
{
  std::string session_name = "session_name";
  nidevice_grpc::SessionRepository session_repository;
  int status = session_repository.add_session(
      session_name,
      []() { return 0; },
      NULL);

  bool is_server_reset = session_repository.reset_server();

  EXPECT_EQ("", session_repository.access_session(session_name));
  EXPECT_TRUE(is_server_reset);
}

TEST(SessionRepositoryTests, UnnamedSessionAdded_ResetServer_RemovesSession)
{
  nidevice_grpc::SessionRepository session_repository;
  std::string session_name;
  session_repository.add_session(
      session_name,
      []() { return 0; },
      NULL);

  bool is_server_reset = session_repository.reset_server();

  EXPECT_EQ("", session_repository.access_session(session_name));
  EXPECT_TRUE(is_server_reset);
}

TEST(SessionRepositoryTests, NamedAndUnnamedSessionsAdded_ResetServer_RemovesBothSessions)
{
  std::string session_name = "session_name";
  nidevice_grpc::SessionRepository session_repository;
  int status = session_repository.add_session(
      session_name,
      []() { return 0; },
      NULL);
  std::string unnamed_session_name;
  session_repository.add_session(
      unnamed_session_name,
      []() { return 0; },
      NULL);

  bool is_server_reset = session_repository.reset_server();

  EXPECT_EQ("", session_repository.access_session(session_name));
  EXPECT_EQ("", session_repository.access_session(unnamed_session_name));
  EXPECT_TRUE(is_server_reset);
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
