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

   // the return value is the status code returned by the init_func.
   // session_name is optional. if a session with the given name already exists, this returns a 0 status, session_id is the ID of the existing session, and init_func is not called.
   // the function passed as the init_func returns a tuple, where the first value is a status code, and the second value is the ID of the initialized session.
   // when a 0 status is returned, the session_id is set to the ID of the new session (or existing session with the given name).
   // if a non-zero status is returned, the session_id is 0 and meaningless.
   int SessionRepository::add_session(
      const std::string& session_name,
      std::function<std::tuple<int, uint64_t>()> init_func,
      CleanupSessionProc cleanup_proc,
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
      info->cleanup_proc = cleanup_proc;
      info->last_access_time = now;
      sessions_.emplace(session_id, info);
      if (!session_name.empty()) {
         info->name = session_name;
         named_sessions_.emplace(session_name, info);
      }
      return 0;
   }

   // this method updates the last_access_time of a session, if one is found with the given ID or name.
   // the return value is the ID of the session that matches the given ID or name, or 0 if such a session is not found.
   // it's only necessary to specify one of the two parameters. passing only a name will cause the corresponding ID to be returned.
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

   // removes a session by ID.
   // to remove a session by name, a caller can use access_session to get the session ID from the name and then call this method.
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

   // this method has three behaviors:
   // 1) if no ReservationInfo exists with the given reservation_id, it creates a new ReservationInfo, adds it to reservations_, and returns it.
   // 2) if a ReservationInfo does exist with the given reservation_id
   //    a) if the client_id on the existing reservation matches the client_id given to this method, it returns a nullptr
   //    b) otherwise, it increments the client_count on the existing ReservationInfo and returns the existing info
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

   // unreserving a reservation causes the lock on the reservation to notify, allowing the next client waiting on that reservation ID to use it.
   // if there are no clients waiting on the reservation's lock, the reservation is also removed from the reservations_ map.
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
      if (reservation_info) {
         reservation_info->lock->notify();
         return true;
      }
      return false;
   }
} // namespace internal
} // namespace grpc
} // namespace hardware
} // namespace ni
