#ifndef NI_HARDWARE_GRPC_INTERNAL_SESSIONREPOSITORY
#define NI_HARDWARE_GRPC_INTERNAL_SESSIONREPOSITORY

#include <grpcpp/grpcpp.h>
#include <server_utilities.grpc.pb.h>

#include <shared_mutex>

#include "hardware/grpc/internal/semaphore.h"

namespace ni {
namespace hardware {
namespace grpc {
namespace internal {

class SessionRepository {
 public:
  SessionRepository();

  using CleanupSessionFunc = void (*)(uint64_t session_id);

  int add_session(const std::string& session_name, std::function<std::tuple<int, uint64_t>()> init_func, CleanupSessionFunc cleanup_func, uint64_t& session_id);
  uint64_t access_session(uint64_t session_id, const std::string& session_name);
  void remove_session(uint64_t id);

  bool reserve(
   const ::grpc::ServerContext* context,
   const std::string& reservation_id,
   const std::string& client_id);
  bool is_reserved_by_client(const std::string& reservation_id, const std::string& client_id);
  bool unreserve(const std::string& reservation_id, const std::string& client_id);
  bool reset_server();

 private:
  struct ReservationInfo {
    std::string client_id;
    std::unique_ptr<internal::Semaphore> lock;
    std::chrono::steady_clock::time_point creation_time;
    // The number of clients that have asked to reserve this reservation, but have not yet acquired the lock.
    int client_count;
  };

  struct SessionInfo {
    virtual ~SessionInfo();

    uint64_t id;
    std::string name;
    std::chrono::steady_clock::time_point last_access_time;
    SessionRepository::CleanupSessionFunc cleanup_func;
  };

  using NamedSessionMap = std::map<std::string, std::shared_ptr<SessionInfo>>;
  using SessionMap = std::map<uint64_t, std::shared_ptr<SessionInfo>>;
  using ReservationMap = std::map<std::string, std::shared_ptr<ReservationInfo>>;

  std::shared_ptr<ReservationInfo> find_or_create_reservation(const std::string& reservation_id, const std::string& client_id);
  void clear_reservations();
  bool release_reservation(const ReservationInfo* reservation_info);

  std::shared_mutex repository_lock_;
  // This map contains every session, including both named and unnamed ones.
  SessionMap sessions_;
  // These entries point at SessionInfo objects that are also contained in sessions_.
  NamedSessionMap named_sessions_;
  ReservationMap reservations_;
};

}  // namespace internal
}  // namespace grpc
}  // namespace hardware
}  // namespace ni

#endif  // NI_HARDWARE_GRPC_INTERNAL_SESSIONREPOSITORY
