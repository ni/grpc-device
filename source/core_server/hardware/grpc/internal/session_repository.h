#ifndef NI_HARDWARE_GRPC_INTERNAL_SESSIONREPOSITORY
#define NI_HARDWARE_GRPC_INTERNAL_SESSIONREPOSITORY

#include <server_utilities.grpc.pb.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <shared_mutex>
#include "hardware/grpc/internal/semaphore.h"

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

      using CleanupSessionProc = void (*)(ViSession session);

      ViSession* add_session(ViSession vi, const std::string& session_user_id, CleanupSessionProc cleanup_proc);
      void remove_session(const ViSession& remote_session);
      ViSession lookup_session(const ViSession& remote_session);

      void reserve(::grpc::ServerContext* context, const ReserveRequest* request, ReserveResponse* response);
      void is_reserved_by_client(::grpc::ServerContext* context, const IsReservedByClientRequest* request, IsReservedByClientResponse* response);
      void unreserve(::grpc::ServerContext* context, const UnreserveRequest* request, UnreserveResponse* response);
      void force_close_all_sessions(::grpc::ServerContext* context, const ForceCloseAllSessionsRequest* request, ForceCloseAllSessionsResponse* response);

   private:
      struct SessionInfo
      {
         ViSession session;
         std::unique_ptr<internal::Semaphore> lock;
         std::chrono::steady_clock::time_point last_access_time;
         SessionRepository::CleanupSessionProc cleanup_proc;
      };

      using NamedSessionMap = std::map<std::string, std::shared_ptr<SessionInfo>>;
      using SessionMap = std::map<google::protobuf::int64, std::shared_ptr<SessionInfo>>;
      using SessionReservationMap = std::map<std::string, std::shared_ptr<SessionInfo>>;

      std::shared_ptr<SessionInfo> lookup_session_info_unlocked(const ViSession& remote_session);
      template<class MapType>
      void close_sessions(MapType& map);
      
      SessionReservationMap reserved_sessions_;
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
