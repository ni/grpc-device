#include "session_repository.h"

namespace ni
{
namespace hardware
{
namespace grpc
{
namespace internal
{
   SessionRepository::SessionRepository()
      : nextSessionId_(1000)
   {
   }

   ViSession* SessionRepository::add_session(ViSession vi, const std::string& session_user_id, CleanupSessionProc cleanup_proc)
   {
      std::unique_lock<std::shared_mutex> lock(sessionLock_);

      auto session = new ViSession();
      if (!session_user_id.empty()) {
         session->set_session_name(session_user_id);
      }
      else {
         int id = ++nextSessionId_;
         session->set_id(id);
      }
      auto info = lookup_session_info_unlocked(*session);
      if (info == nullptr) {
         info = std::make_shared<SessionInfo>();
         if (session_user_id.empty()) {
               unnamedSessions_.emplace(session->id(), info);
         }
         else {
               namedSessions_.emplace(session_user_id, info);
         }
      }
      auto now = std::chrono::steady_clock::now();
      info->session = vi;
      info->cleanupProc = cleanup_proc;
      info->lastAccessTime = now;
      return session;
   }

   void SessionRepository::remove_session(const ViSession& remote_session)
   {
      std::unique_lock<std::shared_mutex> lock(sessionLock_);

      auto it = namedSessions_.find(remote_session.session_name());
      if (it != namedSessions_.end()) {
         namedSessions_.erase(it);
      }
      else {
         auto it = unnamedSessions_.find(remote_session.id());
         if (it != unnamedSessions_.end()) {
                  unnamedSessions_.erase(it);
         }
      }
   }

   ViSession SessionRepository::lookup_session(const ViSession& remote_session)
   {
      std::shared_lock<std::shared_mutex> lock(sessionLock_);
      auto session = lookup_session_info_unlocked(remote_session);
      if (session != nullptr) {
         return session->session;
      }
      return ViSession();
   }

   std::shared_ptr<SessionRepository::SessionInfo> SessionRepository::lookup_session_info_unlocked(const ViSession& remote_session)
   {
      auto now = std::chrono::steady_clock::now();
      if (!remote_session.session_name().empty()) {
         auto it = namedSessions_.find(remote_session.session_name());
         if (it != namedSessions_.end()) {
               it->second->lastAccessTime = now;
               return it->second;
         }
      }
      else {
         auto it = unnamedSessions_.find(remote_session.id());
         if (it != unnamedSessions_.end()) {
               it->second->lastAccessTime = now;
               return it->second;
         }
      }
      return nullptr;
   }

   void SessionRepository::reserve(::grpc::ServerContext* context, const ReserveRequest* request, ReserveResponse* response)
   {
      std::shared_ptr<SessionInfo> session_info;
      {
         std::unique_lock<std::shared_mutex> lock(sessionLock_);
         session_info = lookup_session_info_unlocked(request->session());
      }
      if (session_info != nullptr) {
         if (session_info->lock == nullptr) {
               session_info->lock = std::make_unique<internal::Semaphore>();
         }
         session_info->lock->wait();
         {
               auto now = std::chrono::steady_clock::now();
               std::unique_lock<std::shared_mutex> lock(sessionLock_);
               session_info->lastAccessTime = now;
               reservedSessions_.emplace(request->client_reserve_id(), session_info);
         }
         response->set_status(ReserveResponse_ReserveStatus_RESERVED);
      }
      else {
         response->set_status(ReserveResponse_ReserveStatus_INVALID_SESSION);
      }
   }

   void SessionRepository::is_reserved_by_client(::grpc::ServerContext* context, const IsReservedByClientRequest* request, IsReservedByClientResponse* response)
   {
      std::unique_lock<std::shared_mutex> lock(sessionLock_);
      auto it = reservedSessions_.find(request->client_reserve_id());
      if (it != reservedSessions_.end()) {
         response->set_is_reserved(true);
      }
   }

   void SessionRepository::unreserve(::grpc::ServerContext* context, const UnreserveRequest* request, UnreserveResponse* response)
   {
      std::shared_ptr<SessionInfo> sessionInfo;
      {
         std::unique_lock<std::shared_mutex> lock(sessionLock_);
         auto it = reservedSessions_.find(request->client_reserve_id());
         if (it != reservedSessions_.end()) {
               sessionInfo = it->second;
               reservedSessions_.erase(it);
         }
      }
      if (sessionInfo != nullptr) {
         auto now = std::chrono::steady_clock::now();
         sessionInfo->lastAccessTime = now;
         sessionInfo->lock->notify();
         response->set_is_unreserved(true);
      }
   }
} // namespace internal
} // namespace grpc
} // namespace hardware
} // namespace ni
