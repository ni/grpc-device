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

   void SessionRepository::add_session(const std::string& session_user_id, CleanupSessionProc cleanup_proc)
   {
   }

   void SessionRepository::remove_session(const std::string& session_name)
   {
   }

   std::shared_ptr<SessionRepository::ReservationInfo> SessionRepository::lookup_reservation_info_unlocked(const std::string& reservation_id)
   {
      auto it = reservations_.find(reservation_id);
      if (it != reservations_.end()) {
         return it->second;
      }
      return nullptr;
   }

   ReserveResponse_ReserveStatus SessionRepository::reserve(const std::string& reservation_id, const std::string& client_id)
   {
      if (reservation_id.empty() || client_id.empty())
      {
         return ReserveResponse_ReserveStatus_INVALID_SESSION;
      }
      std::shared_ptr<ReservationInfo> info;
      {
         std::unique_lock<std::shared_mutex> lock(session_lock_);
         info = lookup_reservation_info_unlocked(reservation_id);
      }
      if (!info) {
         info = std::make_shared<SessionRepository::ReservationInfo>();
         info->creation_time = std::chrono::steady_clock::now();
         info->client_id = client_id;
         reservations_.emplace(reservation_id, info);
      }
      else if (info->client_id == client_id) {
         return ReserveResponse_ReserveStatus_RESERVED;
      }
      if (!info->lock) {
         info->lock = std::make_unique<internal::Semaphore>();
      }
      info->lock->wait();
      {
         std::unique_lock<std::shared_mutex> lock(session_lock_);
         info->client_id = client_id;
      }
      return ReserveResponse_ReserveStatus_RESERVED;
   }

   bool SessionRepository::is_reserved_by_client(const std::string& reservation_id, const std::string& client_id)
   {
      std::unique_lock<std::shared_mutex> lock(session_lock_);
      auto it = reservations_.find(reservation_id);
      if (it != reservations_.end() && client_id == it->second->client_id) {
         return true;
      }
      return false;
   }

   bool SessionRepository::unreserve(const std::string& reservation_id, const std::string& client_id)
   {
      std::shared_ptr<SessionRepository::ReservationInfo> reservation_info;
      {
         std::unique_lock<std::shared_mutex> lock(session_lock_);
         auto it = reservations_.find(reservation_id);
         if (it != reservations_.end() && client_id == it->second->client_id) {
            reservation_info = it->second;
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
