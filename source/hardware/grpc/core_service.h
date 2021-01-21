#include <core.grpc.pb.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <shared_mutex>

namespace ni
{
namespace hardware
{
namespace grpc
{
namespace impl
{
   class Semaphore;

   class CoreService final : public ni::hardware::grpc::CoreService::Service
   {
   public:
      using CleanupSessionProc = void (*)(ViSession session);

      static ViSession* AddSession(ViSession vi, const std::string& sessionUserId, CleanupSessionProc cleanupProc);
      static void RemoveSession(ViSession session);
      static ViSession LookupSession(const ViSession& remoteSession);

      ::grpc::Status Reserve(::grpc::ServerContext* context, const ReserveRequest* request, ReserveResponse* response) override;
      ::grpc::Status IsReservedByClient(::grpc::ServerContext* context, const IsReservedByClientRequest* request, IsReservedByClientResponse* response) override;
      ::grpc::Status Unreserve(::grpc::ServerContext* context, const UnreserveRequest* request, UnreserveResponse* response) override;

   private:
      struct SessionInfo
      {
         ViSession Session;
         std::unique_ptr<Semaphore> Lock;
         std::chrono::steady_clock::time_point LastAccessTime;
         CoreService::CleanupSessionProc CleanupProc;
      };

      using NamedSessionMap = std::map<std::string, std::shared_ptr<SessionInfo>>;
      using SessionMap = std::map<int, std::shared_ptr<SessionInfo>>;
      using SessionReservationMap = std::map<std::string, std::shared_ptr<SessionInfo>>;

   private:
      static std::shared_ptr<SessionInfo> LookupSessionInfoUnlocked(const ViSession& remoteSession);

   private:
      SessionReservationMap _reservedSessions;

   private:
      static std::shared_mutex s_SessionLock;
      static int s_NextSessionId;
      static NamedSessionMap s_NamedSessions;
      static SessionMap s_UnnamedSessions;
   };

   class Semaphore
   {
   public:
      Semaphore (int count_ = 1)
         : count(count_)
      {        
      }

      inline void notify()
      {
         std::unique_lock<std::mutex> lock(mtx);
         count++;
         cv.notify_one();
      }

      inline void wait()
      {
         std::unique_lock<std::mutex> lock(mtx);

         while(count == 0)
         {
               cv.wait(lock);
         }
         count--;
      }

   private:
      std::mutex mtx;
      std::condition_variable cv;
      int count;
   };
}
}
}
}
