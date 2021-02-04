#include <gtest/gtest.h>
#include "hardware/grpc/internal/semaphore.h"
#include "hardware/grpc/internal/session_repository.h"

namespace ni
{
namespace tests
{
namespace unit
{
namespace hardware
{
namespace grpc
{
namespace internal
{
   TEST(SessionRepositoryTests, AddSessionWithNonZeroStatus_ReturnsStatusAndDoesNotStoreSession)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      uint64_t session_id = 42;
      int status = session_repository.add_session(
         "",
         [session_id]() { return std::make_tuple(1, session_id); },
         NULL,
         session_id);

      EXPECT_EQ(status, 1);
      EXPECT_FALSE(session_repository.access_session(session_id, ""));
   }

   TEST(SessionRepositoryTests, AddSession_StoresSessionWithGivenId)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      uint64_t session_id;
      int status = session_repository.add_session(
         "",
         []() { return std::make_tuple(0, 42); },
         NULL,
         session_id);

      EXPECT_EQ(status, 0);
      EXPECT_EQ(session_id, 42);
      EXPECT_EQ(session_repository.access_session(session_id, ""), session_id);
   }

   TEST(SessionRepositoryTests, AddNamedSession_StoresSessionWithGivenIdAndName)
   {
      std::string session_name = "session_name";
      ni::hardware::grpc::internal::SessionRepository session_repository;
      uint64_t session_id;
      int status = session_repository.add_session(
         session_name,
         []() { return std::make_tuple(0, 42); },
         NULL,
         session_id);

      EXPECT_EQ(status, 0);
      EXPECT_EQ(session_id, 42);
      EXPECT_EQ(session_repository.access_session(session_id, ""), session_id);
      EXPECT_EQ(session_repository.access_session(0, session_name), session_id);
   }

   TEST(SessionRepositoryTests, UnnamedSessionAdded_RemoveSession_RemovesSession)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      uint64_t session_id;
      session_repository.add_session(
         "",
         []() { return std::make_tuple(0, 42); },
         NULL,
         session_id);

      session_repository.remove_session(session_id);

      EXPECT_FALSE(session_repository.access_session(session_id, ""));
   }

   TEST(SessionRepositoryTests, NamedSessionAdded_RemoveSession_RemovesSession)
   {
      std::string session_name = "session_name";
      ni::hardware::grpc::internal::SessionRepository session_repository;
      uint64_t session_id;
      int status = session_repository.add_session(
         session_name,
         []() { return std::make_tuple(0, 42); },
         NULL,
         session_id);

      session_repository.remove_session(session_id);

      EXPECT_FALSE(session_repository.access_session(session_id, ""));
      EXPECT_FALSE(session_repository.access_session(0, session_name));
   }

   TEST(SessionRepositoryTests, NamedSessionAdded_AddSessionWithSameName_ReturnsFirstSessionIdAndDoesNotCallInit)
   {
      std::string session_name = "session_name";
      ni::hardware::grpc::internal::SessionRepository session_repository;
      uint64_t session_id;
      session_repository.add_session(
         session_name,
         []() { return std::make_tuple(0, 42); },
         NULL,
         session_id);

      session_id = 0;
      bool init_called = false;
      session_repository.add_session(
         session_name,
         [init_called]() mutable {
            init_called = true;
            return std::make_tuple(0, 52);
         },
         NULL,
         session_id);

      EXPECT_FALSE(init_called);
      EXPECT_EQ(session_id, 42);
   }
   
   TEST(SessionRepositoryTests, UnnamedSessionAdded_ResetServer_RemovesSession)
   {
      ni::hardware::grpc::internal::SessionRepository session_repository;
      uint64_t session_id;
      session_repository.add_session(
         "",
         []() { return std::make_tuple(0, 42); },
         NULL,
         session_id);

      bool all_closed = session_repository.reset_server();

      EXPECT_FALSE(session_repository.access_session(session_id, ""));
      EXPECT_TRUE(all_closed);
   }

   TEST(SessionRepositoryTests, NamedAndUnnamedSessionsAdded_ResetServer_RemovesBothSessions)
   {
      std::string session_name = "session_name";
      ni::hardware::grpc::internal::SessionRepository session_repository;
      uint64_t named_session_id;
      int status = session_repository.add_session(
         session_name,
         []() { return std::make_tuple(0, 42); },
         NULL,
         named_session_id);
      uint64_t unnamed_session_id;
      session_repository.add_session(
         "",
         []() { return std::make_tuple(0, 42); },
         NULL,
         unnamed_session_id);
         
      bool all_closed = session_repository.reset_server();

      EXPECT_FALSE(session_repository.access_session(named_session_id, ""));
      EXPECT_FALSE(session_repository.access_session(0, session_name));
      EXPECT_FALSE(session_repository.access_session(unnamed_session_id, ""));
      EXPECT_TRUE(all_closed);
   }
} // namespace internal
} // namespace grpc
} // namespace hardware
} // namespace unit
} // namespace tests
} // namespace ni
