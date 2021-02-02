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
      : next_session_id_(1000)
   {
   }

   ViSession* SessionRepository::add_session(ViSession vi, const std::string& session_user_id, CleanupSessionProc cleanup_proc)
   {
      std::unique_lock<std::shared_mutex> lock(session_lock_);

      auto session = new ViSession();
      if (!session_user_id.empty()) {
         session->set_session_name(session_user_id);
      }
      else {
         int id = ++next_session_id_;
         session->set_id(id);
      }
      auto info = lookup_session_info_unlocked(*session);
      if (!info) {
         info = std::make_shared<SessionInfo>();
         if (session_user_id.empty()) {
            unnamed_sessions_.emplace(session->id(), info);
         }
         else {
            named_sessions_.emplace(session_user_id, info);
         }
      }
      auto now = std::chrono::steady_clock::now();
      info->session = vi;
      info->cleanup_proc = cleanup_proc;
      info->last_access_time = now;
      return session;
   }

   void SessionRepository::remove_session(const ViSession& remote_session)
   {
      std::unique_lock<std::shared_mutex> lock(session_lock_);

      auto it = named_sessions_.find(remote_session.session_name());
      if (it != named_sessions_.end()) {
         named_sessions_.erase(it);
      }
      else {
         auto it = unnamed_sessions_.find(remote_session.id());
         if (it != unnamed_sessions_.end()) {
            unnamed_sessions_.erase(it);
         }
      }
   }

   ViSession SessionRepository::lookup_session(const ViSession& remote_session)
   {
      std::shared_lock<std::shared_mutex> lock(session_lock_);
      auto session = lookup_session_info_unlocked(remote_session);
      if (session) {
         return session->session;
      }
      return ViSession();
   }

   std::shared_ptr<SessionRepository::SessionInfo> SessionRepository::lookup_session_info_unlocked(const ViSession& remote_session)
   {
      auto now = std::chrono::steady_clock::now();
      if (!remote_session.session_name().empty()) {
         auto it = named_sessions_.find(remote_session.session_name());
         if (it != named_sessions_.end()) {
            it->second->last_access_time = now;
            return it->second;
         }
      }
      else {
         auto it = unnamed_sessions_.find(remote_session.id());
         if (it != unnamed_sessions_.end()) {
            it->second->last_access_time = now;
            return it->second;
         }
      }
      return nullptr;
   }

   template<class MapType>
   void SessionRepository::close_sessions(MapType& map)
   {
      for (auto sessionIterator = map.begin(); sessionIterator != map.end(); sessionIterator++)
      {
         if (sessionIterator != map.end()) {          
            auto sessionInfo = sessionIterator->second;
            auto session = sessionInfo->session;
            auto cleanupProcess  = sessionInfo->cleanup_proc;
            if (cleanupProcess != NULL){
               cleanupProcess(sessionInfo->session);
            }
            map.erase(sessionIterator);
         }
      }
   }
   
   void SessionRepository::clear_reservations()
   {
      for (auto reservationIterator = reserved_sessions_.begin(); reservationIterator != reserved_sessions_.end(); reservationIterator++)
      {
         if (reservationIterator != reserved_sessions_.end()) {    
            auto clientReserveId = reservationIterator->first;         
            unreserve_unlocked(clientReserveId);
         }
      }
   }
   
   void SessionRepository::reserve(::grpc::ServerContext* context, const ReserveRequest* request, ReserveResponse* response)
   {
      std::shared_ptr<SessionInfo> session_info;
      {
         std::unique_lock<std::shared_mutex> lock(session_lock_);
         session_info = lookup_session_info_unlocked(request->session());
      }
      if (session_info) {
         if (!session_info->lock) {
            session_info->lock = std::make_unique<internal::Semaphore>();
         }
         session_info->lock->wait();
         {
            auto now = std::chrono::steady_clock::now();
            std::unique_lock<std::shared_mutex> lock(session_lock_);
            session_info->last_access_time = now;
            reserved_sessions_.emplace(request->client_reserve_id(), session_info);
         }
         response->set_status(ReserveResponse_ReserveStatus_RESERVED);
      }
      else {
         response->set_status(ReserveResponse_ReserveStatus_INVALID_SESSION);
      }
   }

   void SessionRepository::is_reserved_by_client(::grpc::ServerContext* context, const IsReservedByClientRequest* request, IsReservedByClientResponse* response)
   {
      std::unique_lock<std::shared_mutex> lock(session_lock_);
      auto it = reserved_sessions_.find(request->client_reserve_id());
      if (it != reserved_sessions_.end()) {
         response->set_is_reserved(true);
      }
   }

   void SessionRepository::unreserve(::grpc::ServerContext* context, const UnreserveRequest* request, UnreserveResponse* response)
   {
         std::unique_lock<std::shared_mutex> lock(session_lock_);
         auto isUnreserved = unreserve_unlocked(request->client_reserve_id());
         response->set_is_unreserved(isUnreserved);
   }
   
   bool SessionRepository::unreserve_unlocked(const std::string& clientReserveId)
   {
      auto it = reserved_sessions_.find(clientReserveId);
      std::shared_ptr<SessionInfo> sessionInfo;
      if (it != reserved_sessions_.end()) {
         sessionInfo = it->second;
         reserved_sessions_.erase(it);
      }

      if (sessionInfo) {
         auto now = std::chrono::steady_clock::now();
         sessionInfo->last_access_time = now;
         sessionInfo->lock->notify();
         return true;
      }
      return false;
   }
      
   bool SessionRepository::reset_server()
   {
      std::unique_lock<std::shared_mutex> lock(session_lock_);
      clear_reservations();
      close_sessions(named_sessions_);
      close_sessions(unnamed_sessions_);
      bool allClosed = named_sessions_.empty() && unnamed_sessions_.empty();
      return allClosed && reserved_sessions_.empty();
   }
} // namespace internal
} // namespace grpc
} // namespace hardware
} // namespace ni
