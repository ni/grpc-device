#ifndef NIDEVICE_GRPC_SESSION_REPOSITORY
#define NIDEVICE_GRPC_SESSION_REPOSITORY

#include <session.pb.h>

#include <atomic>
#include <functional>
#include <map>
#include <shared_mutex>
#include <vector>

#include "semaphore.h"

namespace grpc {
class ServerContext;
class Status;
}  // namespace grpc

namespace nidevice_grpc {

class SessionRepository {
 public:
  SessionRepository();
  ~SessionRepository();

  typedef std::function<int32_t()> InitFunc;
  typedef std::function<void(const std::string&)> CleanupSessionFunc;

  int add_session(
      std::string& session_name,
      InitFunc init_func,
      CleanupSessionFunc cleanup_func,
      SessionInitializationBehavior initialization_behavior = SESSION_INITIALIZATION_BEHAVIOR_UNSPECIFIED,
      bool* initialized_new_session = nullptr);
  std::string access_session(const std::string& session_name);
  void remove_session(const std::string& name);

  void register_dependent_session(const std::string& name, const std::string& dependent_session_name, std::function<void()> cleanup);

  bool reserve(
      const ::grpc::ServerContext* context,
      const std::string& reservation_id,
      const std::string& client_id,
      ::grpc::Status& status);
  bool is_reserved_by_client(const std::string& reservation_id, const std::string& client_id);
  bool unreserve(const std::string& reservation_id, const std::string& client_id);
  bool reset_server(bool cleanup = true);

 private:
  struct ReservationInfo {
    std::string client_id;
    std::unique_ptr<Semaphore> lock;
    std::chrono::steady_clock::time_point creation_time;
    // The number of clients that have asked to reserve this reservation, but have not yet acquired the lock.
    int client_count;
  };

  // Action that is executed on remove from the map.
  // Unlike cleanup_action this is called for both explicit cleanup (close) and
  // implicit cleanup (reset_server).
  class RemoveAction {
   public:
    RemoveAction(std::function<void()> on_remove) : on_remove_(on_remove) {}
    ~RemoveAction()
    {
      on_remove_();
    }

   private:
    std::function<void()> on_remove_;
  };

  struct SessionInfo {
    std::string name;
    std::chrono::steady_clock::time_point last_access_time;
    SessionRepository::CleanupSessionFunc cleanup_func;
    std::vector<std::unique_ptr<RemoveAction>> dependent_sessions;
  };

  using NamedSessionMap = std::map<std::string, std::shared_ptr<SessionInfo>>;
  using ReservationMap = std::map<std::string, std::shared_ptr<ReservationInfo>>;

  std::shared_ptr<ReservationInfo> find_or_create_reservation(const std::string& reservation_id, const std::string& client_id);
  void clear_reservations();
  bool close_sessions(bool cleanup);
  void cleanup_session(const std::shared_ptr<SessionInfo>& session_info);
  bool release_reservation(const ReservationInfo* reservation_info);
  std::string next_id() { return "ni:generated:" + std::to_string(++_next_id); }

  std::shared_mutex repository_lock_;
  // These entries point at SessionInfo objects that are also contained in sessions_.
  NamedSessionMap named_sessions_;
  ReservationMap reservations_;
  std::atomic<uint32_t> _next_id{0};
};
}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_SESSION_REPOSITORY
