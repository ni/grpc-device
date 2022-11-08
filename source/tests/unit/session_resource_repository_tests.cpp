#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <server/session_repository.h>
#include <server/session_resource_repository.h>

using namespace nidevice_grpc;

namespace ni {
namespace tests {
namespace unit {

const uint32_t kNoSession = 0;
std::string kNoSessionName;
const int32_t kNoError = 0;

template <typename TResourceHandle>
std::string add_session_resource(
    SessionResourceRepository<TResourceHandle>& resource_repository,
    const TResourceHandle& resource)
{
  std::string session_name;
  auto result = resource_repository.add_session(
     session_name,
      [=]() { return std::make_tuple(kNoError, resource); },
      [](TResourceHandle handle) {});
  EXPECT_EQ(kNoError, result);
  return session_name;
}

TEST(SessionResourceRepositoryTests, AddSessionResource_ResourceIsAdded)
{
  SessionRepository repository;
  SessionResourceRepository<uint64_t> resource_repository(
      &repository);

  const uint64_t kResourceHandle = 0x1111222233334444;
  std::string session_id("session");
  auto result = resource_repository.add_session(
      session_id,
      [=]() { return std::make_tuple(kNoError, kResourceHandle); },
      [](uint64_t handle) {});

  EXPECT_EQ(kNoError, result);
  EXPECT_NE(kNoSessionName, session_id);
  EXPECT_EQ(
      kResourceHandle,
      resource_repository.access_session(session_id));
  EXPECT_EQ(
      kResourceHandle,
      resource_repository.access_session(session_id));
  EXPECT_EQ(
      session_id,
      repository.access_session(session_id));
}

TEST(SessionResourceRepositoryTests, AddTwoSessionsWithSameResourceHandle_RemoveOneSession_ResourceStillAccessible)
{
  SessionRepository repository;
  SessionResourceRepository<uint64_t> resource_repository(
      &repository);
  const uint64_t kResourceHandle = 0x1234;
  auto session_id_one = add_session_resource(resource_repository, kResourceHandle);
  auto session_id_two = add_session_resource(resource_repository, kResourceHandle);
  EXPECT_NE(session_id_one, session_id_two);
  EXPECT_EQ(
      kResourceHandle,
      resource_repository.access_session(session_id_one));
  EXPECT_EQ(
      kResourceHandle,
      resource_repository.access_session(session_id_two));

  resource_repository.remove_session(session_id_one);

  EXPECT_EQ(
      kNoSession,
      resource_repository.access_session(session_id_one));
  EXPECT_EQ(
      kResourceHandle,
      resource_repository.access_session(session_id_two));
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
      resource_repository.access_session(session_id));
  EXPECT_EQ(
      kNoSessionName,
      repository.access_session(session_id));
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
  resource_repository.remove_session(session_id);

  EXPECT_EQ(
      kNoSessionName,
      repository.access_session(session_id));
  EXPECT_EQ(
      0,
      resource_repository.access_session(session_id));
  EXPECT_EQ(
      kNoSessionName,
      resource_repository.resolve_session_name(kResourceHandle));
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
      resource_repository.access_session(session_id));
}

TEST(SessionResourceRepositoryTests, SessionResource_ResetServer_CleanupIsCalled)
{
  SessionRepository repository;
  SessionResourceRepository<int64_t> resource_repository(
      &repository);
  bool cleanup_called = false;
  std::string session_name;
  resource_repository.add_session(
      session_name,
      [=]() { return std::make_tuple(kNoError, 12345678); },
      [&](int64_t) { cleanup_called = true; });
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
  std::string session_name;
  auto result = resource_repository.add_session(
      session_name,
      [=]() { return std::make_tuple(kErrorCode, 5555); },
      [](uint64_t handle) {});

  EXPECT_EQ(kErrorCode, result);
  EXPECT_EQ(kNoSessionName, session_name);
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
      int_resource_repository.access_session(int_session_id));
  EXPECT_EQ(
      kStringResourceHandle,
      string_resource_repository.access_session(string_session_id));
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
      resource_repository.access_session(session_id_1));
  EXPECT_EQ(
      kResourceHandle2,
      resource_repository.access_session(session_id_2));
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
      other_resource_repository.access_session(session_id);

  EXPECT_EQ(kNoSession, session_from_other_repository);
}

TEST(SessionResourceRepositoryTests, AddSessionResource_AddSessionWithSameNameFromDifferentRepository_ThrowsSessionException)
{
  SessionRepository repository;
  SessionResourceRepository<int32_t> resource_repository(
      &repository);
  SessionResourceRepository<int32_t> other_resource_repository(
      &repository);
  const int32_t kResourceHandle1 = -123456;
  std::string kTestResource("test_resource");
  auto result = resource_repository.add_session(
      kTestResource,
      []() { return std::make_tuple(0, 5555); },
      [](int32_t handle) {});

  const int32_t kErrorCode = 9999;
  using MockInitDelegate = ::testing::MockFunction<std::tuple<int32_t, int32_t>(void)>;
  MockInitDelegate mock_init;
  EXPECT_THROW(
      {
        try {
          result = other_resource_repository.add_session(
              kTestResource,
              mock_init.AsStdFunction(),
              [](int32_t handle) { FAIL() << "Unexpected Cleanup"; });
        }
        catch (const nidevice_grpc::SessionException& ex) {
          const std::string expected_message("The session name \"" + kTestResource + "\" is being used by a different driver.");
          EXPECT_STREQ(expected_message.c_str(), ex.what());
          throw;
        }
      },
      nidevice_grpc::SessionException);
}

template <typename TResource>
std::string simple_add_session(SessionResourceRepository<TResource> resource_repository, const std::string& session_name, TResource new_resource_handle)
{
  std::string session_id = session_name;
  const auto status = resource_repository.add_session(
      session_id,
      [new_resource_handle]() { return std::make_tuple(0, new_resource_handle); },
      [](TResource handle) {});
  EXPECT_EQ(0, status);
  return session_id;
}

template <typename TResource>
std::string simple_add_dependent_session(
    SessionResourceRepository<TResource> resource_repository,
    const std::string& session_name,
    const std::string& initiating_session_id,
    TResource new_resource_handle)
{
  std::string session_id = session_name;
  std::string initiating_session_name = initiating_session_id;
  const auto status = resource_repository.add_dependent_session(
      session_id,
      [new_resource_handle]() { return std::make_tuple(0, new_resource_handle); },
      initiating_session_name);
  EXPECT_EQ(0, status);
  return session_id;
}

// Note: this is the key functional criteria. Make sure that dependent sessions can't "overwrite" primary sessions in the reverse lookup.
// This ensures that any reverse lookups are consistently scoped to the owning service's lifetime management/etc.
TEST(SessionResourceRepositoryTests, SessionAlreadyInResourceRepository_AddDependentSessionWithSameHandle_ResolveSessionByHandleGivesOriginalSession)
{
  constexpr auto DUPE_SESSION_HANDLE = 1234U;
  constexpr auto INITIATING_SESSION_HANDLE = 5678U;
  SessionRepository repository;
  SessionResourceRepository<uint32_t> resource_repository(&repository);
  const auto initiating_session_id = simple_add_session(resource_repository, "initiating_session", INITIATING_SESSION_HANDLE);
  const auto primary_with_dupe_session_id = simple_add_session(resource_repository, "primary_session_with_dupe_handle", DUPE_SESSION_HANDLE);

  const auto dupe_dependent_session_id = simple_add_dependent_session(resource_repository, "dependent_session", initiating_session_id, DUPE_SESSION_HANDLE);

  EXPECT_EQ(primary_with_dupe_session_id, resource_repository.resolve_session_name(DUPE_SESSION_HANDLE));
}

// Note: This is how the above criteria (SessionAlreadyInResourceRepository_AddDependentSessionWithSameHandle_ResolveSessionByHandleGivesOriginalSession)
// is implemented.
// If there is no dupe primary session, it's probably OK to include the dependent session in the reverse lookup. But it's simpler to leave it out
// completely. This also gives us more wiggle room to change behavior in the future because we are exposing less functionality.
TEST(SessionResourceRepositoryTests, AddDependentSession_DependentSessionIsNotResolvableByHandle)
{
  constexpr auto DEPENDENT_SESSION_HANDLE = 1234U;
  constexpr auto INITIATING_SESSION_HANDLE = 5678U;
  SessionRepository repository;
  SessionResourceRepository<uint32_t> resource_repository(&repository);
  const auto initiating_session_id = simple_add_session(resource_repository, "initiating_session", INITIATING_SESSION_HANDLE);
  const auto dupe_dependent_session_id = simple_add_dependent_session(resource_repository, "dependent_session", initiating_session_id, DEPENDENT_SESSION_HANDLE);

  EXPECT_EQ("", resource_repository.resolve_session_name(DEPENDENT_SESSION_HANDLE));
}

TEST(SessionResourceRepositoryTests, AddDependentSession_RemoveDependentSession_SessionIsRemoved)
{
  constexpr auto DEPENDENT_SESSION_HANDLE = 1234U;
  constexpr auto INITIATING_SESSION_HANDLE = 5678U;
  SessionRepository repository;
  SessionResourceRepository<uint32_t> resource_repository(&repository);
  const auto initiating_session_id = simple_add_session(resource_repository, "initiating_session", INITIATING_SESSION_HANDLE);
  const auto dependent_session_id = simple_add_dependent_session(resource_repository, "dependent_session", initiating_session_id, DEPENDENT_SESSION_HANDLE);

  resource_repository.remove_session(dependent_session_id);

  EXPECT_EQ(0, resource_repository.access_session(dependent_session_id));
}

TEST(SessionResourceRepositoryTests, AddDependentSession_RemoveInitiatingSession_BothSessionsAreRemoved)
{
  constexpr auto DEPENDENT_SESSION_HANDLE = 1234U;
  constexpr auto INITIATING_SESSION_HANDLE = 5678U;
  SessionRepository repository;
  SessionResourceRepository<uint32_t> resource_repository(&repository);
  const auto initiating_session_id = simple_add_session(resource_repository, "initiating_session", INITIATING_SESSION_HANDLE);
  const auto dependent_session_id = simple_add_dependent_session(resource_repository, "dependent_session", initiating_session_id, DEPENDENT_SESSION_HANDLE);

  resource_repository.remove_session(initiating_session_id);

  EXPECT_EQ(0, resource_repository.access_session(initiating_session_id));
  EXPECT_EQ(0, resource_repository.access_session(dependent_session_id));
}

}  // namespace unit
}  // namespace tests
}  // namespace ni
