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
        static SessionRepository* instance();

        using CleanupSessionProc = void (*)(ViSession session);

        static ViSession* add_session(ViSession vi, const std::string& session_user_id, CleanupSessionProc cleanup_proc);
        static void remove_session(const ViSession& session);
        static ViSession lookup_session(const ViSession& remote_session);

        void reserve(::grpc::ServerContext* context, const ReserveRequest* request, ReserveResponse* response);
        void is_reserved_by_client(::grpc::ServerContext* context, const IsReservedByClientRequest* request, IsReservedByClientResponse* response);
        void unreserve(::grpc::ServerContext* context, const UnreserveRequest* request, UnreserveResponse* response);

    private:
    struct SessionInfo
    {
        ViSession Session;
        std::unique_ptr<internal::Semaphore> Lock;
        std::chrono::steady_clock::time_point LastAccessTime;
        SessionRepository::CleanupSessionProc CleanupProc;
    };

    using NamedSessionMap = std::map<std::string, std::shared_ptr<SessionInfo>>;
    using SessionMap = std::map<google::protobuf::int64, std::shared_ptr<SessionInfo>>;
    using SessionReservationMap = std::map<std::string, std::shared_ptr<SessionInfo>>;

    private:
        static std::shared_ptr<SessionInfo> lookup_session_info_unlocked(const ViSession& remote_session);

    private:
        SessionReservationMap reservedSessions_;

   private:
      static std::shared_mutex sessionLock_;
      static int nextSessionId_;
      static NamedSessionMap namedSessions_;
      static SessionMap unnamedSessions_;
    };
} // namespace internal
} // namespace grpc
} // namespace hardware
} // namespace ni
#endif // NI_HARDWARE_GRPC_INTERNAL_SESSIONREPOSITORY
