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
   {
   }

   int SessionRepository::add_session(
      const std::string& session_name,
      std::function<std::tuple<int, uint64_t>()> init_func,
      CleanupSessionFunc cleanup_func,
      uint64_t& session_id)
   {
      session_id = 0;
      std::unique_lock<std::shared_mutex> lock(repository_lock_);
      auto now = std::chrono::steady_clock::now();
      auto it = named_sessions_.find(session_name);
      if (it != named_sessions_.end()) {
         session_id = it->second->id;
         it->second->last_access_time = now;
         return 0;
      }
      auto info = std::make_shared<SessionInfo>();
      auto init_result = init_func();
      int status = std::get<0>(init_result);
      if (status != 0) {
         return status;
      }
      session_id = std::get<1>(init_result);
      info->id = session_id;
      info->cleanup_func = cleanup_func;
      info->last_access_time = now;
      sessions_.emplace(session_id, info);
      if (!session_name.empty()) {
         info->name = session_name;
         named_sessions_.emplace(session_name, info);
      }
      return 0;
   }

   uint64_t SessionRepository::access_session(uint64_t session_id, const std::string& session_name)
   {
      std::unique_lock<std::shared_mutex> lock(repository_lock_);
      auto now = std::chrono::steady_clock::now();
      auto it = named_sessions_.find(session_name);
      if (it != named_sessions_.end()) {
         it->second->last_access_time = now;
         return it->second->id;
      }
      auto sessions_it = sessions_.find(session_id);
      if (sessions_it != sessions_.end()) {
         sessions_it->second->last_access_time = now;
         return session_id;
      }
      return 0;
   }

   void SessionRepository::remove_session(uint64_t id)
   {
      std::unique_lock<std::shared_mutex> lock(repository_lock_);
      auto it = sessions_.find(id);
      if (it != sessions_.end()) {
         auto named_it = named_sessions_.find(it->second->name);
         if (named_it != named_sessions_.end()) {
            named_sessions_.erase(named_it);
         }
         sessions_.erase(it);
      }
   }

   std::shared_ptr<SessionRepository::ReservationInfo> SessionRepository::find_or_create_reservation(const std::string& reservation_id, const std::string& client_id)
   {
      std::unique_lock<std::shared_mutex> lock(repository_lock_);
      std::shared_ptr<ReservationInfo> info;
      auto it = reservations_.find(reservation_id);
      if (it != reservations_.end()) {
         info = it->second;
         if (info->client_id == client_id) {
            return nullptr;
         }
         ++info->client_count;
      }
      else {
         info = std::make_shared<SessionRepository::ReservationInfo>();
         info->creation_time = std::chrono::steady_clock::now();
         info->client_id = client_id;
         info->lock = std::make_unique<internal::Semaphore>();
         info->client_count = 1;
         reservations_.emplace(reservation_id, info);
      }
      return info;
   }

   bool SessionRepository::reserve(const std::string& reservation_id, const std::string& client_id)
   {
      if (reservation_id.empty() || client_id.empty())
      {
         return false;
      }
      std::shared_ptr<ReservationInfo> info = find_or_create_reservation(reservation_id, client_id);
      if (!info) {
         return true;
      }
      // if the info was newly created by find_or_create_reservation, this call
      // will not wait. on subsequent calls to reserve with the same reservation_id
      // and a different client_id, it will wait until the lock calls notify which
      // releases the lock one client at a time.
      info->lock->wait();
      {
         std::unique_lock<std::shared_mutex> lock(repository_lock_);
         info->client_count--;
         info->client_id = client_id;
      }
      return true;
   }

   bool SessionRepository::is_reserved_by_client(const std::string& reservation_id, const std::string& client_id)
   {
      std::unique_lock<std::shared_mutex> lock(repository_lock_);
      auto it = reservations_.find(reservation_id);
      return it != reservations_.end() && client_id == it->second->client_id;
   }

   bool SessionRepository::unreserve(const std::string& reservation_id, const std::string& client_id)
   {
      std::unique_lock<std::shared_mutex> lock(repository_lock_);
      std::shared_ptr<SessionRepository::ReservationInfo> reservation_info;
      auto it = reservations_.find(reservation_id);
      if (it != reservations_.end() && client_id == it->second->client_id) {
         reservation_info = it->second;
         if (it->second->client_count <= 0) {
            reservations_.erase(it);
         }
      }
      return release_reservation(reservation_info.get());
   }
   
   bool SessionRepository::release_reservation(const ReservationInfo* reservation_info)
   {
      if (reservation_info) {
         reservation_info->lock->notify();
         return true;
      }
      return false;
   }
   
   void SessionRepository::clear_reservations()
   {
      for (auto it = reservations_.begin(); it != reservations_.end();)
      {
         std::shared_ptr<SessionRepository::ReservationInfo> reservation_info = it->second;
         it = reservations_.erase(it);
         release_reservation(reservation_info.get());
      }
   }
      
   bool SessionRepository::reset_server()
   {
      std::unique_lock<std::shared_mutex> lock(repository_lock_);
      clear_reservations();
      named_sessions_.clear();
      sessions_.clear();
      auto is_server_reset = named_sessions_.empty() && sessions_.empty();
      return is_server_reset && reservations_.empty();	   
   }
   
   SessionRepository::SessionInfo::~SessionInfo()
   {
      if (cleanup_func != nullptr){
         cleanup_func(id);
      }
   }
} // namespace internal
} // namespace grpc
} // namespace hardware
} // namespace ni
