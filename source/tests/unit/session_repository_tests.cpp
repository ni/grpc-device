#include <gtest/gtest.h>
#include <server/exceptions.h>
#include <server/semaphore.h>
#include <server/session_repository.h>

namespace ni {
namespace tests {
namespace unit {

// Starting with session_id 1 isn't functionally important, but we want to start with
// something intentional. NOT an uninitialized uint.
constexpr auto EXPECTED_FIRST_SESSION_ID = 1;

TEST(SessionRepositoryTests, AddSessionWithNonZeroStatus_ReturnsStatusAndDoesNotStoreSession)
{
  nidevice_grpc::SessionRepository session_repository;
  uint32_t session_id = 42;
  int status = session_repository.add_session(
      "",
      [session_id]() { return 1; },
      NULL,
      session_id);

  EXPECT_EQ(status, 1);
  EXPECT_FALSE(session_repository.access_session(session_id, ""));
}

TEST(SessionRepositoryTests, AddSessionWithNonZeroStatus_InitializedNewSessionIsFalse)
{
  nidevice_grpc::SessionRepository session_repository;
  uint32_t session_id = 42;
  bool initialized_new_session;
  int status = session_repository.add_session(
      "",
      [session_id]() { return 1; },
      NULL,
      session_id,
      nidevice_grpc::SESSION_INITIALIZATION_BEHAVIOR_UNSPECIFIED,
      &initialized_new_session);

  EXPECT_FALSE(initialized_new_session);
}

TEST(SessionRepositoryTests, AddSession_StoresSessionWithGivenId)
{
  nidevice_grpc::SessionRepository session_repository;
  uint32_t session_id;
  bool initialized_new_session;
  int status = session_repository.add_session(
      "",
      []() { return 0; },
      NULL,
      session_id,
      nidevice_grpc::SESSION_INITIALIZATION_BEHAVIOR_UNSPECIFIED,
      &initialized_new_session);

  EXPECT_EQ(status, 0);
  EXPECT_EQ(session_id, EXPECTED_FIRST_SESSION_ID);
  EXPECT_EQ(session_repository.access_session(session_id, ""), session_id);
  EXPECT_TRUE(initialized_new_session);
}

TEST(SessionRepositoryTests, NoSessions_AddSessionWithAttachToExistingBehavior_ExceptionThrown)
{
  std::string session_name = "session_name";
  nidevice_grpc::SessionRepository session_repository;
  uint32_t first_session_id;

  EXPECT_THROW(
      {
        try {
          session_repository.add_session(
              session_name,
              []() { return 0; },
              NULL,
              first_session_id,
              nidevice_grpc::SESSION_INITIALIZATION_BEHAVIOR_ATTACH_TO_EXISTING);
        }
        catch (const nidevice_grpc::NonDriverException& e) {
          auto exception_status = e.GetStatus();
          EXPECT_EQ(::grpc::StatusCode::FAILED_PRECONDITION, exception_status.error_code());
          throw e;
        }
      },
      nidevice_grpc::NonDriverException);
}

TEST(SessionRepositoryTests, AddNamedSession_StoresSessionWithGivenIdAndName)
{
  std::string session_name = "session_name";
  nidevice_grpc::SessionRepository session_repository;
  uint32_t session_id;
  bool initialized_new_session;
  int status = session_repository.add_session(
      session_name,
      []() { return 0; },
      NULL,
      session_id,
      nidevice_grpc::SESSION_INITIALIZATION_BEHAVIOR_UNSPECIFIED,
      &initialized_new_session);

  EXPECT_EQ(status, 0);
  EXPECT_EQ(session_id, EXPECTED_FIRST_SESSION_ID);
  EXPECT_EQ(session_repository.access_session(session_id, ""), session_id);
  EXPECT_EQ(session_repository.access_session(0, session_name), session_id);
  EXPECT_TRUE(initialized_new_session);
}

TEST(SessionRepositoryTests, UnnamedSessionAdded_RemoveSession_RemovesSession)
{
  nidevice_grpc::SessionRepository session_repository;
  uint32_t session_id;
  session_repository.add_session(
      "",
      []() { return 0; },
      NULL,
      session_id);

  session_repository.remove_session(session_id);

  EXPECT_FALSE(session_repository.access_session(session_id, ""));
}

TEST(SessionRepositoryTests, NamedSessionAdded_RemoveSession_RemovesSession)
{
  std::string session_name = "session_name";
  nidevice_grpc::SessionRepository session_repository;
  uint32_t session_id;
  int status = session_repository.add_session(
      session_name,
      []() { return 0; },
      NULL,
      session_id);

  session_repository.remove_session(session_id);

  EXPECT_FALSE(session_repository.access_session(session_id, ""));
  EXPECT_FALSE(session_repository.access_session(0, session_name));
}

TEST(SessionRepositoryTests, NamedSessionAdded_AddSessionWithSameName_ReturnsFirstSessionIdAndDoesNotCallInit)
{
  std::string session_name = "session_name";
  nidevice_grpc::SessionRepository session_repository;
  uint32_t first_session_id;
  session_repository.add_session(
      session_name,
      []() { return 0; },
      NULL,
      first_session_id);

  uint32_t second_session_id;
  bool init_called = false;
  bool initialized_new_session;
  session_repository.add_session(
      session_name,
      [init_called]() mutable {
        init_called = true;
        return 0;
      },
      NULL,
      second_session_id,
      nidevice_grpc::SESSION_INITIALIZATION_BEHAVIOR_UNSPECIFIED,
      &initialized_new_session);

  EXPECT_FALSE(init_called);
  EXPECT_FALSE(initialized_new_session);
  EXPECT_EQ(first_session_id, second_session_id);
}

TEST(SessionRepositoryTests, NamedSessionAdded_AddSessionWithSameNameWithInitializeNewBehavior_ExceptionThrown)
{
  std::string session_name = "session_name";
  nidevice_grpc::SessionRepository session_repository;
  uint32_t first_session_id;
  session_repository.add_session(
      session_name,
      []() { return 0; },
      NULL,
      first_session_id);

  uint32_t second_session_id;
  bool init_called = false;
  EXPECT_THROW(
      {
        try {
          session_repository.add_session(
              session_name,
              [init_called]() mutable {
                init_called = true;
                return 0;
              },
              NULL,
              second_session_id,
              nidevice_grpc::SESSION_INITIALIZATION_BEHAVIOR_INITIALIZE_NEW);
        }
        catch (const nidevice_grpc::NonDriverException& e) {
          auto exception_status = e.GetStatus();
          EXPECT_EQ(::grpc::StatusCode::ALREADY_EXISTS, exception_status.error_code());
          throw e;
        }
      },
      nidevice_grpc::NonDriverException);
}

TEST(SessionRepositoryTests, NamedSessionAdded_ResetServer_RemovesSession)
{
  std::string session_name = "session_name";
  nidevice_grpc::SessionRepository session_repository;
  uint32_t session_id;
  int status = session_repository.add_session(
      session_name,
      []() { return 0; },
      NULL,
      session_id);

  bool is_server_reset = session_repository.reset_server();

  EXPECT_FALSE(session_repository.access_session(session_id, ""));
  EXPECT_FALSE(session_repository.access_session(0, session_name));
  EXPECT_TRUE(is_server_reset);
}

TEST(SessionRepositoryTests, UnnamedSessionAdded_ResetServer_RemovesSession)
{
  nidevice_grpc::SessionRepository session_repository;
  uint32_t session_id;
  session_repository.add_session(
      "",
      []() { return 0; },
      NULL,
      session_id);

  bool is_server_reset = session_repository.reset_server();

  EXPECT_FALSE(session_repository.access_session(session_id, ""));
  EXPECT_TRUE(is_server_reset);
}

TEST(SessionRepositoryTests, NamedAndUnnamedSessionsAdded_ResetServer_RemovesBothSessions)
{
  std::string session_name = "session_name";
  nidevice_grpc::SessionRepository session_repository;
  uint32_t named_session_id;
  int status = session_repository.add_session(
      session_name,
      []() { return 0; },
      NULL,
      named_session_id);
  uint32_t unnamed_session_id;
  session_repository.add_session(
      "",
      []() { return 0; },
      NULL,
      unnamed_session_id);

  bool is_server_reset = session_repository.reset_server();

  EXPECT_FALSE(session_repository.access_session(named_session_id, ""));
  EXPECT_FALSE(session_repository.access_session(0, session_name));
  EXPECT_FALSE(session_repository.access_session(unnamed_session_id, ""));
  EXPECT_TRUE(is_server_reset);
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
