#ifndef NIDEVICE_GRPC_SESSION_REPOSITORY
#define NIDEVICE_GRPC_SESSION_REPOSITORY

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
  typedef std::function<void(uint32_t)> CleanupSessionFunc;

  int add_session(const std::string& session_name, InitFunc init_func, CleanupSessionFunc cleanup_func, uint32_t& session_id);
  uint32_t access_session(uint32_t session_id, const std::string& session_name);
  void remove_session(uint32_t id);

  void register_dependent_session(uint32_t id, uint32_t dependent_session_id, std::function<void()> cleanup);

  bool reserve(
      const ::grpc::ServerContext* context,
      const std::string& reservation_id,
      const std::string& client_id,
      ::grpc::Status& status);
  bool is_reserved_by_client(const std::string& reservation_id, const std::string& client_id);
  bool unreserve(const std::string& reservation_id, const std::string& client_id);
  bool reset_server(bool cleanup=true);

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
    uint32_t id;
    std::string name;
    std::chrono::steady_clock::time_point last_access_time;
    SessionRepository::CleanupSessionFunc cleanup_func;
    std::vector<std::unique_ptr<RemoveAction> > dependent_sessions;
  };

  using NamedSessionMap = std::map<std::string, std::shared_ptr<SessionInfo>>;
  using SessionMap = std::map<uint32_t, std::shared_ptr<SessionInfo>>;
  using ReservationMap = std::map<std::string, std::shared_ptr<ReservationInfo>>;

  std::shared_ptr<ReservationInfo> find_or_create_reservation(const std::string& reservation_id, const std::string& client_id);
  void clear_reservations();
  bool close_sessions(bool cleanup);
  void cleanup_session(const std::shared_ptr<SessionInfo>& session_info);
  bool release_reservation(const ReservationInfo* reservation_info);
  uint32_t next_id() { return ++_next_id; }

  std::shared_mutex repository_lock_;
  // This map contains every session, including both named and unnamed ones.
  SessionMap sessions_;
  // These entries point at SessionInfo objects that are also contained in sessions_.
  NamedSessionMap named_sessions_;
  ReservationMap reservations_;
  std::atomic<uint32_t> _next_id{0};
};
}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_SESSION_REPOSITORY
