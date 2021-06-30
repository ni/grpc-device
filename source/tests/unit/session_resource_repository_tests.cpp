#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <server/session_repository.h>
#include <server/session_resource_repository.h>

using namespace nidevice_grpc;

namespace ni {
namespace tests {
namespace unit {

const uint32_t kNoSession = 0;
const int32_t kNoError = 0;

template <typename TResourceHandle>
uint32_t add_session_resource(
    SessionResourceRepository<TResourceHandle>& resource_repository,
    const TResourceHandle& resource)
{
  uint32_t session_id;
  auto result = resource_repository.add_session(
      "",
      [=]() { return std::make_tuple(kNoError, resource); },
      [](TResourceHandle handle) {},
      session_id);
  EXPECT_EQ(kNoError, result);
  return session_id;
}

TEST(SessionResourceRepositoryTests, AddSessionResource_ResourceIsAdded)
{
  SessionRepository repository;
  SessionResourceRepository<uint64_t> resource_repository(
      &repository);

  const uint64_t kResourceHandle = 0x1111222233334444;
  const std::string kSessionName("session");
  uint32_t session_id;
  auto result = resource_repository.add_session(
      kSessionName,
      [=]() { return std::make_tuple(kNoError, kResourceHandle); },
      [](uint64_t handle) {},
      session_id);

  EXPECT_EQ(kNoError, result);
  EXPECT_NE(kNoSession, session_id);
  EXPECT_EQ(
      kResourceHandle,
      resource_repository.access_session(session_id, ""));
  EXPECT_EQ(
      kResourceHandle,
      resource_repository.access_session(0, kSessionName));
  EXPECT_EQ(
      session_id,
      repository.access_session(0, kSessionName));
  EXPECT_EQ(
      session_id,
      repository.access_session(session_id, ""));
}

TEST(SessionResourceRepositoryTests, SessionResource_RemoveSession_ResourceIsRemoved)
{
  SessionRepository repository;
  SessionResourceRepository<uint16_t> resource_repository(
      &repository);
  const uint16_t kResourceHandle = 0x1234;
  auto session_id = add_session_resource(resource_repository, kResourceHandle);

  repository.remove_session(session_id);

  EXPECT_EQ(
      kNoSession,
      resource_repository.access_session(session_id, ""));
  EXPECT_EQ(
      kNoSession,
      repository.access_session(session_id, ""));
}

TEST(SessionResourceRepositoryTests, SessionResource_RemoveFromResourceRepository_ResourceIsRemoved)
{
  SessionRepository repository;
  SessionResourceRepository<int64_t> resource_repository(
      &repository);
  const int64_t kResourceHandle = 68686868;
  auto session_id = add_session_resource(resource_repository, kResourceHandle);

  // Remove from the SessionResourceRepository and ensure that it removes from the
  // SessionRepository and SessionResourceRepository.
  resource_repository.remove_session(kResourceHandle);

  EXPECT_EQ(
      kNoSession,
      repository.access_session(session_id, ""));
  EXPECT_EQ(
      0L,
      resource_repository.access_session(session_id, ""));
  EXPECT_EQ(
      kNoSession,
      resource_repository.resolve_session_id(kResourceHandle));
}

TEST(SessionResourceRepositoryTests, SessionResource_ResetServer_ResourceIsRemoved)
{
  SessionRepository repository;
  SessionResourceRepository<int64_t> resource_repository(
      &repository);
  const int64_t kResourceHandle = -9847465247263584;
  auto session_id = add_session_resource(resource_repository, kResourceHandle);

  repository.reset_server();

  EXPECT_EQ(
      kNoSession,
      resource_repository.access_session(session_id, ""));
  EXPECT_EQ(
      kNoSession,
      resource_repository.resolve_session_id(kResourceHandle));
}

TEST(SessionResourceRepositoryTests, SessionResource_ResetServer_CleanupIsCalled)
{
  SessionRepository repository;
  SessionResourceRepository<int64_t> resource_repository(
      &repository);
  bool cleanup_called = false;
  uint32_t session_id;
  resource_repository.add_session(
      "",
      [=]() { return std::make_tuple(kNoError, 12345678); },
      [&](int64_t) { cleanup_called = true; },
      session_id);
  EXPECT_FALSE(cleanup_called);

  repository.reset_server();

  EXPECT_TRUE(cleanup_called);
}

TEST(SessionResourceRepositoryTests, AddSessionResourceWithErrrOnInit_ResourceIsNotAdded)
{
  SessionRepository repository;
  SessionResourceRepository<int32_t> resource_repository(
      &repository);

  const int32_t kErrorCode = 9999;
  uint32_t session_id;
  auto result = resource_repository.add_session(
      "",
      [=]() { return std::make_tuple(kErrorCode, 5555); },
      [](uint64_t handle) {},
      session_id);

  EXPECT_EQ(kErrorCode, result);
  EXPECT_EQ(kNoSession, session_id);
}

TEST(SessionResourceRepositoryTests, MultipleResourceRepositories_AddResourceToEach_ResourcesAreAded)
{
  SessionRepository repository;
  SessionResourceRepository<int32_t> int_resource_repository(
      &repository);
  SessionResourceRepository<std::string> string_resource_repository(
      &repository);

  const int32_t kIntResourceHandle = -123456;
  auto int_session_id = add_session_resource(
      int_resource_repository,
      kIntResourceHandle);
  const std::string kStringResourceHandle("RESOURCE_HANDLE");
  auto string_session_id = add_session_resource(
      string_resource_repository,
      kStringResourceHandle);

  EXPECT_EQ(
      kIntResourceHandle,
      int_resource_repository.access_session(int_session_id, ""));
  EXPECT_EQ(
      kStringResourceHandle,
      string_resource_repository.access_session(string_session_id, ""));
}

TEST(SessionResourceRepositoryTests, AddMultipleResources_ResourcesAreAdded)
{
  SessionRepository repository;
  SessionResourceRepository<int32_t> resource_repository(
      &repository);

  const int32_t kResourceHandle1 = -123456;
  auto session_id_1 = add_session_resource(
      resource_repository,
      kResourceHandle1);
  const int32_t kResourceHandle2 = 654321;
  auto session_id_2 = add_session_resource(
      resource_repository,
      kResourceHandle2);

  EXPECT_EQ(
      kResourceHandle1,
      resource_repository.access_session(session_id_1, ""));
  EXPECT_EQ(
      kResourceHandle2,
      resource_repository.access_session(session_id_2, ""));
}

TEST(SessionResourceRepositoryTests, AddSessionResource_AccessFromDifferentRepository_DoesNotReturnSession)
{
  SessionRepository repository;
  SessionResourceRepository<int32_t> resource_repository(
      &repository);
  SessionResourceRepository<int32_t> other_resource_repository(
      &repository);
  const int32_t kResourceHandle1 = -123456;
  auto session_id = add_session_resource(
      resource_repository,
      kResourceHandle1);

  auto session_from_other_repository =
      other_resource_repository.access_session(session_id, "");

  EXPECT_EQ(kNoSession, session_from_other_repository);
}

TEST(SessionResourceRepositoryTests, AddSessionResource_AddSessionWithSameNameFromDifferentRepository_FailsWithoutCallingInit)
{
  SessionRepository repository;
  SessionResourceRepository<int32_t> resource_repository(
      &repository);
  SessionResourceRepository<int32_t> other_resource_repository(
      &repository);
  const int32_t kResourceHandle1 = -123456;
  uint32_t session_id;
  const std::string kTestResource("test_resource");
  auto result = resource_repository.add_session(
      kTestResource,
      []() { return std::make_tuple(0, 5555); },
      [](int32_t handle) {},
      session_id);

  const int32_t kErrorCode = 9999;
  using MockInitDelegate = ::testing::MockFunction<std::tuple<int32_t, int32_t>(void)>;
  MockInitDelegate mock_init;
  uint32_t second_session_id;
  result = other_resource_repository.add_session(
      kTestResource,
      mock_init.AsStdFunction(),
      [](int32_t handle) { FAIL() << "Unexpected Cleanup"; },
      second_session_id);

  EXPECT_EQ(kNoSession, second_session_id);
  EXPECT_NE(kNoError, result);
}
}  // namespace unit
}  // namespace tests
}  // namespace ni