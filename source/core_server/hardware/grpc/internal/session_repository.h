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

      using CleanupSessionProc = void (*)(const std::string& session_name);

      void add_session(const std::string& session_user_id, CleanupSessionProc cleanup_proc);
      void remove_session(const std::string& session_name);

      ReserveResponse_ReserveStatus reserve(const std::string& reservation_id, const std::string& client_id);
      bool is_reserved_by_client(const std::string& reservation_id, const std::string& client_id);
      bool unreserve(const std::string& reservation_id, const std::string& client_id);

   private:
      struct ReservationInfo
      {
         std::string client_id;
         std::unique_ptr<internal::Semaphore> lock;
         std::chrono::steady_clock::time_point creation_time;
      };

      struct SessionInfo
      {
         std::chrono::steady_clock::time_point last_access_time;
         SessionRepository::CleanupSessionProc cleanup_proc;
      };

      using NamedSessionMap = std::map<std::string, std::shared_ptr<SessionInfo>>;
      using SessionMap = std::map<google::protobuf::int64, std::shared_ptr<SessionInfo>>;
      using ReservationMap = std::map<std::string, std::shared_ptr<ReservationInfo>>;

      std::shared_ptr<ReservationInfo> lookup_reservation_info_unlocked(const std::string& reservation_id);

      ReservationMap reservations_;
      std::shared_mutex session_lock_;
      int next_session_id_;
      NamedSessionMap named_sessions_;
      SessionMap unnamed_sessions_;
   };
} // namespace internal
} // namespace grpc
} // namespace hardware
} // namespace ni
#endif // NI_HARDWARE_GRPC_INTERNAL_SESSIONREPOSITORY
