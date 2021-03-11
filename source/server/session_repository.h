#ifndef NI_HARDWARE_GRPC_INTERNAL_SESSIONREPOSITORY
#define NI_HARDWARE_GRPC_INTERNAL_SESSIONREPOSITORY

#include <grpcpp/grpcpp.h>
#include <session.grpc.pb.h>

#include <shared_mutex>

#include "semaphore.h"

namespace grpc {
namespace nidevice {

class SessionRepository {
 public:
  SessionRepository();

  typedef std::function<std::tuple<int, uint32_t>()> InitFunc;
  typedef std::function<void(uint32_t)> CleanupSessionFunc;

  int add_session(const std::string& session_name, InitFunc init_func, CleanupSessionFunc cleanup_func, uint32_t& session_id);
  uint32_t access_session(uint32_t session_id, const std::string& session_name);
  void remove_session(uint32_t id);

  bool reserve(
      const ::grpc::ServerContext* context,
      const std::string& reservation_id,
      const std::string& client_id,
      ::grpc::Status& status);
  bool is_reserved_by_client(const std::string& reservation_id, const std::string& client_id);
  bool unreserve(const std::string& reservation_id, const std::string& client_id);
  bool reset_server();

 private:
  struct ReservationInfo {
    std::string client_id;
    std::unique_ptr<Semaphore> lock;
    std::chrono::steady_clock::time_point creation_time;
    // The number of clients that have asked to reserve this reservation, but have not yet acquired the lock.
    int client_count;
  };

  struct SessionInfo {
    uint32_t id;
    std::string name;
    std::chrono::steady_clock::time_point last_access_time;
    SessionRepository::CleanupSessionFunc cleanup_func;
  };

  using NamedSessionMap = std::map<std::string, std::shared_ptr<SessionInfo>>;
  using SessionMap = std::map<uint32_t, std::shared_ptr<SessionInfo>>;
  using ReservationMap = std::map<std::string, std::shared_ptr<ReservationInfo>>;

  std::shared_ptr<ReservationInfo> find_or_create_reservation(const std::string& reservation_id, const std::string& client_id);
  void clear_reservations();
  bool close_sessions();
  void cleanup_session(const std::shared_ptr<SessionInfo>& session_info);
  bool release_reservation(const ReservationInfo* reservation_info);

  std::shared_mutex repository_lock_;
  // This map contains every session, including both named and unnamed ones.
  SessionMap sessions_;
  // These entries point at SessionInfo objects that are also contained in sessions_.
  NamedSessionMap named_sessions_;
  ReservationMap reservations_;
};

}  // namespace nidevice
}  // namespace grpc

#endif  // NI_HARDWARE_GRPC_INTERNAL_SESSIONREPOSITORY
