#ifndef NI_HARDWARE_GRPC_INTERNAL_SESSIONREPOSITORY
#define NI_HARDWARE_GRPC_INTERNAL_SESSIONREPOSITORY

#include <shared_mutex>
#include "hardware/grpc/internal/semaphore.h"
#include <grpcpp/grpcpp.h>
#include <server_utilities.grpc.pb.h>

namespace ni
{
namespace hardware
{
namespace grpc
{
namespace internal
{
   class SessionRepository
   {
   public:
      SessionRepository();

      using CleanupSessionProc = void (*)(uint64_t session_id);

      int add_session(const std::string& session_name, std::function<std::tuple<int, uint64_t>()> init_func, CleanupSessionProc cleanup_proc, uint64_t& session_id);
      uint64_t access_session(uint64_t session_id, const std::string& session_name);
      void remove_session(uint64_t id);

      bool reserve(const std::string& reservation_id, const std::string& client_id);
      bool is_reserved_by_client(const std::string& reservation_id, const std::string& client_id);
      bool unreserve(const std::string& reservation_id, const std::string& client_id);

   private:
      struct ReservationInfo
      {
         std::string client_id;
         std::unique_ptr<internal::Semaphore> lock;
         std::chrono::steady_clock::time_point creation_time;
         int client_count;
      };

      struct SessionInfo
      {
         uint64_t id;
         std::string name;
         std::chrono::steady_clock::time_point last_access_time;
         SessionRepository::CleanupSessionProc cleanup_proc;
      };

      using NamedSessionMap = std::map<std::string, std::shared_ptr<SessionInfo>>;
      using SessionMap = std::map<google::protobuf::int64, std::shared_ptr<SessionInfo>>;
      using ReservationMap = std::map<std::string, std::shared_ptr<ReservationInfo>>;

      std::shared_ptr<ReservationInfo> find_or_create_reservation(const std::string& reservation_id, const std::string& client_id);

      std::shared_mutex repository_lock_;
      SessionMap sessions_;
      NamedSessionMap named_sessions_;
      ReservationMap reservations_;
   };
} // namespace internal
} // namespace grpc
} // namespace hardware
} // namespace ni
#endif // NI_HARDWARE_GRPC_INTERNAL_SESSIONREPOSITORY
