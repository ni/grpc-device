#ifndef NIDEVICE_GRPC_SESSION_RESOURCE_REPOSITORY_H
#define NIDEVICE_GRPC_SESSION_RESOURCE_REPOSITORY_H

#include <mutex>
#include <string>
#include <unordered_map>

#include "session_repository.h"

namespace nidevice_grpc {

// Wraps SessionRepository to store a service-specific TResourceHandle associated with
// each session.
template <typename TResourceHandle>
class SessionResourceRepository {
 public:
  typedef std::function<std::tuple<int, TResourceHandle>()> InitFunc;
  typedef std::function<void(TResourceHandle)> CleanupSessionFunc;

  SessionResourceRepository(SessionRepository* session_repository)
      : session_repository_(session_repository)
  {
  }

  int add_session(
      const std::string& session_name,
      InitFunc init_func,
      CleanupSessionFunc cleanup_func,
      uint32_t& session_id);

  TResourceHandle access_session(uint32_t session_id, const std::string& session_name) const;
  uint32_t resolve_session_id(TResourceHandle handle) const;

  void remove_session(TResourceHandle handle);

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
    void add(uint32_t session_id, TResourceHandle handle);

    bool contains(uint32_t session_id) const;
    TResourceHandle get_handle(uint32_t session_id) const;
    uint32_t get_session_id(TResourceHandle handle) const;

    uint32_t remove_handle(TResourceHandle handle);
    TResourceHandle remove_session_id(uint32_t session_id);

   private:
    using SessionToResourceMap = std::map<uint32_t, TResourceHandle>;
    using ResourceToSessionMap = std::map<TResourceHandle, uint32_t>;
    using MapLock = std::lock_guard<std::recursive_mutex>;

    SessionToResourceMap map_;
    ResourceToSessionMap reverse_map_;
    mutable std::recursive_mutex map_mutex_;
  };

  SessionRepository* session_repository_;
  ResourceMap resource_map_;
};

template <typename TResourceHandle>
int SessionResourceRepository<TResourceHandle>::add_session(
    const std::string& session_name,
    InitFunc init_func,
    CleanupSessionFunc cleanup_func,
    uint32_t& session_id)
{
  uint32_t session_from_repository = 0;

  auto session_creator = SessionResourceCreator(init_func);
  auto status = session_repository_->add_session(
      session_name,
      [&]() { return session_creator.init_resource_handle(); },
      // By val capture to keep cleanup_func in memory.
      [=](uint32_t id) {
        auto handle = resource_map_.remove_session_id(id);
        return cleanup_func(handle);
      },
      session_from_repository);

  if (status) {
    session_id = 0;
    return status;
  }

  if (session_creator.added_new_handle_) {
    resource_map_.add(session_from_repository, session_creator.handle_);
  }

  // session_name resolves to a session in a different resource repository.
  // Report error.
  if (!resource_map_.contains(session_from_repository)) {
    session_id = 0;
    const int kError_InvalidArg = 1;
    return kError_InvalidArg;
  }

  session_id = session_from_repository;
  return 0;
}

template <typename TResourceHandle>
TResourceHandle SessionResourceRepository<TResourceHandle>::access_session(uint32_t session_id, const std::string& session_name) const
{
  auto id = session_repository_->access_session(session_id, session_name);
  return resource_map_.get_handle(id);
}

template <typename TResourceHandle>
uint32_t SessionResourceRepository<TResourceHandle>::resolve_session_id(TResourceHandle handle) const
{
  return resource_map_.get_session_id(handle);
}

template <typename TResourceHandle>
void SessionResourceRepository<TResourceHandle>::remove_session(TResourceHandle handle)
{
  auto id = resource_map_.remove_handle(handle);
  if (id) {
    session_repository_->remove_session(id);
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
void SessionResourceRepository<TResourceHandle>::ResourceMap::add(uint32_t session_id, TResourceHandle handle)
{
  MapLock lock(map_mutex_);
  map_[session_id] = handle;
  reverse_map_[handle] = session_id;
}

template <typename TResourceHandle>
bool SessionResourceRepository<TResourceHandle>::ResourceMap::contains(uint32_t session_id) const
{
  MapLock lock(map_mutex_);
  auto found = map_.find(session_id);
  return found != map_.end();
}

template <typename TResourceHandle>
TResourceHandle SessionResourceRepository<TResourceHandle>::ResourceMap::get_handle(uint32_t session_id) const
{
  MapLock lock(map_mutex_);
  auto resource_it = map_.find(session_id);
  if (resource_it != map_.end()) {
    return resource_it->second;
  }
  // Note: failed resolve will ultimately be reported as a bad resource by the driver
  // on use.
  return TResourceHandle();
}

template <typename TResourceHandle>
uint32_t SessionResourceRepository<TResourceHandle>::ResourceMap::get_session_id(TResourceHandle handle) const
{
  MapLock lock(map_mutex_);
  auto session_it = reverse_map_.find(handle);
  if (session_it != reverse_map_.end()) {
    return session_it->second;
  }
  // Note: failed resolve will ultimately be reported as a bad resource by the driver
  // on use.
  return 0;
}

template <typename TResourceHandle>
uint32_t SessionResourceRepository<TResourceHandle>::ResourceMap::remove_handle(TResourceHandle handle)
{
  MapLock lock(map_mutex_);
  auto session_id = get_session_id(handle);
  if (session_id) {
    map_.erase(session_id);
    reverse_map_.erase(handle);
  }
  return session_id;
}

template <typename TResourceHandle>
TResourceHandle SessionResourceRepository<TResourceHandle>::ResourceMap::remove_session_id(uint32_t session_id)
{
  MapLock lock(map_mutex_);
  auto handle = get_handle(session_id);
  if (handle != TResourceHandle()) {
    map_.erase(session_id);
    reverse_map_.erase(handle);
  }
  return handle;
}

}  // namespace nidevice_grpc

#endif /* NIDEVICE_GRPC_SESSION_RESOURCE_REPOSITORY_H */
