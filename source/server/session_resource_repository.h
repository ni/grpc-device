#ifndef NIDEVICE_GRPC_SESSION_RESOURCE_REPOSITORY_H
#define NIDEVICE_GRPC_SESSION_RESOURCE_REPOSITORY_H

#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>

#include "session_repository.h"
#include "shared_library.h"

namespace nidevice_grpc {

// Wraps SessionRepository to store a service-specific TResourceHandle associated with
// each session.
template <typename TResourceHandle>
class SessionResourceRepository {
 public:
  typedef std::function<std::tuple<int, TResourceHandle>()> InitFunc;
  typedef std::function<void(TResourceHandle)> CleanupSessionFunc;

  explicit SessionResourceRepository(const std::shared_ptr<SessionRepository>& session_repository)
      : session_repository_(session_repository),
        resource_map_(std::make_shared<ResourceMap>())
  {
  }

  int add_session(
      std::string& session_name,
      InitFunc init_func,
      CleanupSessionFunc cleanup_func,
      SessionInitializationBehavior initialization_behavior = SESSION_INITIALIZATION_BEHAVIOR_UNSPECIFIED,
      bool* initialized_new_session = nullptr,
      bool include_in_reverse_lookup = true);

  TResourceHandle access_session(const std::string& session_name) const;
  std::string resolve_session_name(TResourceHandle handle) const;
  int add_dependent_session(std::string& session_name, InitFunc init_func, std::string& initiating_session);
  void remove_session(const std::string& session_name);

 private:
  // Wraps init_func_ and caches the result as handle_.
  // For passing into SessionRepository.add_session.
  struct SessionResourceCreator {
    const InitFunc& init_func_;
    TResourceHandle handle_;
    bool added_new_handle_;

    SessionResourceCreator(const InitFunc& init_func)
        : init_func_(init_func),
          added_new_handle_(false),
          handle_()
    {
    }

    uint32_t init_resource_handle();
  };

  // A thread-safe bi-directional map of session_id to TResourceHandle.
  class ResourceMap {
   public:
    void add(const std::string& session_name, TResourceHandle handle, bool include_in_reverse_lookup);

    bool contains(const std::string& session_name) const;
    TResourceHandle get_handle(const std::string& session_name) const;
    std::string get_session_name(TResourceHandle handle) const;

    TResourceHandle remove_session_name(const std::string& session_name);

   private:
    using SessionToResourceMap = std::map<std::string, TResourceHandle>;
    using ResourceToSessionMap = std::map<TResourceHandle, std::string>;
    using MapLock = std::lock_guard<std::recursive_mutex>;

    SessionToResourceMap map_;
    ResourceToSessionMap reverse_map_;
    mutable std::recursive_mutex map_mutex_;
  };

  // Services share ownership of session resource repositories, which share ownership of the session repository.
  std::shared_ptr<SessionRepository> session_repository_;

  // shared_ptr to allow sharing ownership with cleanup delegate in register_dependent_session.
  std::shared_ptr<ResourceMap> resource_map_;
};

template <typename TResourceHandle>
int SessionResourceRepository<TResourceHandle>::add_session(
    std::string& session_name,
    InitFunc init_func,
    CleanupSessionFunc cleanup_func,
    SessionInitializationBehavior initialization_behavior,
    bool* initialized_new_session,
    bool include_in_reverse_lookup)
{
  auto session_creator = SessionResourceCreator(init_func);
  auto resource_map = resource_map_;
  auto status = session_repository_->add_session(
      session_name,
      [&]() { return session_creator.init_resource_handle(); },
      // By val capture to keep cleanup_func in memory.
      [resource_map, cleanup_func](const std::string& name) {
        auto handle = resource_map->remove_session_name(name);
        return cleanup_func(handle);
      },
      initialization_behavior,
      initialized_new_session);

  if (status) {
    session_name = std::string();
    return status;
  }

  if (session_creator.added_new_handle_) {
    resource_map_->add(session_name, session_creator.handle_, include_in_reverse_lookup);
  }

  // session_name resolves to a session in a different resource repository.
  if (!resource_map_->contains(session_name)) {
    throw nidevice_grpc::SessionException("The session name \"" + session_name + "\" is being used by a different driver.");
  }

  return 0;
}

template <typename TResourceHandle>
int SessionResourceRepository<TResourceHandle>::add_dependent_session(
    std::string& session_name,
    InitFunc init_func,
    std::string& initiating_session)
{
  // Register with no cleanup function.
  // ASSUMPTION: dependent sessions are owned by the initiating driver session and appropriate
  // cleanup code will be executed when the initiating session is closed.
  // We're only responsible for cleaning up the map structures.
  auto status = add_session(
      session_name,
      init_func,
      [](TResourceHandle) {},
      /* initialization_behavior = */ SESSION_INITIALIZATION_BEHAVIOR_UNSPECIFIED,
      /* initialized_new_session = */ nullptr,
      /* include_in_reverse_lookup = */ false);
  auto resource_map = resource_map_;
  session_repository_->register_dependent_session(
      initiating_session,
      session_name,
      [session_name, resource_map]() { resource_map->remove_session_name(session_name); });
  return status;
}

template <typename TResourceHandle>
TResourceHandle SessionResourceRepository<TResourceHandle>::access_session(const std::string& session_name) const
{
  auto name = session_repository_->access_session(session_name);
  return resource_map_->get_handle(name);
}

template <typename TResourceHandle>
std::string SessionResourceRepository<TResourceHandle>::resolve_session_name(TResourceHandle handle) const
{
  return resource_map_->get_session_name(handle);
}

template <typename TResourceHandle>
void SessionResourceRepository<TResourceHandle>::remove_session(const std::string& session_name)
{
  auto name = session_repository_->access_session(session_name);
  if (name.length()) {
    resource_map_->remove_session_name(name);
    session_repository_->remove_session(name);
  }
}

template <typename TResourceHandle>
uint32_t SessionResourceRepository<TResourceHandle>::SessionResourceCreator::init_resource_handle()
{
  auto init_result = init_func_();
  auto status = std::get<0>(init_result);
  if (status) {
    return status;
  }

  handle_ = std::get<1>(init_result);
  added_new_handle_ = true;

  return 0;
}

template <typename TResourceHandle>
void SessionResourceRepository<TResourceHandle>::ResourceMap::add(const std::string& session_name, TResourceHandle handle, bool include_in_reverse_lookup)
{
  MapLock lock(map_mutex_);
  map_[session_name] = handle;
  if (include_in_reverse_lookup) {
    reverse_map_[handle] = session_name;
  }
}

template <typename TResourceHandle>
bool SessionResourceRepository<TResourceHandle>::ResourceMap::contains(const std::string& session_name) const
{
  MapLock lock(map_mutex_);
  auto found = map_.find(session_name);
  return found != map_.end();
}

template <typename TResourceHandle>
TResourceHandle SessionResourceRepository<TResourceHandle>::ResourceMap::get_handle(const std::string& session_name) const
{
  MapLock lock(map_mutex_);
  auto resource_it = map_.find(session_name);
  if (resource_it != map_.end()) {
    return resource_it->second;
  }
  // Note: failed resolve will ultimately be reported as a bad resource by the driver
  // on use.
  return TResourceHandle();
}

template <typename TResourceHandle>
std::string SessionResourceRepository<TResourceHandle>::ResourceMap::get_session_name(TResourceHandle handle) const
{
  MapLock lock(map_mutex_);
  auto session_it = reverse_map_.find(handle);
  if (session_it != reverse_map_.end()) {
    return session_it->second;
  }
  // Note: failed resolve will ultimately be reported as a bad resource by the driver
  // on use.
  return "";
}

template <typename TResourceHandle>
TResourceHandle SessionResourceRepository<TResourceHandle>::ResourceMap::remove_session_name(const std::string& session_name)
{
  MapLock lock(map_mutex_);
  auto handle = get_handle(session_name);
  if (handle != TResourceHandle()) {
    map_.erase(session_name);
    reverse_map_.erase(handle);
  }
  return handle;
}

}  // namespace nidevice_grpc

#endif /* NIDEVICE_GRPC_SESSION_RESOURCE_REPOSITORY_H */
