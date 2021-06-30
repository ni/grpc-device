#include "session_repository.h"

namespace nidevice_grpc {

SessionRepository::SessionRepository()
{
}

// Either returns (via session_id) an existing session with the specified name or initializes and
// adds a new session using the init_func provided. The init_func is only called when an existing
// session with session_name is not found. It is expected to return a tuple, where the first value
// is a status code, and the second value is the ID of a newly initialized session. The return
// value is the status returned from the init_func, or 0 if an existing named session is found.
int SessionRepository::add_session(
    const std::string& session_name,
    InitFunc init_func,
    CleanupSessionFunc cleanup_func,
    uint32_t& session_id)
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
  auto status = init_func();
  if (status) {
    return status;
  }
  session_id = next_id();
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

// Updates the last_access_time of a session, if one is found with the given ID or name. Returns
// the ID of the session that matches the given ID or name, or 0 if such a session is not found.
// Only one of the two parameters needs to be specified.
// Passing only a name returns the corresponding ID.
uint32_t SessionRepository::access_session(uint32_t session_id, const std::string& session_name)
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

// Removes a session by ID.
// To remove a session by name, use access_session to get the session ID.
void SessionRepository::remove_session(uint32_t id)
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

// This method has three behaviors:
// 1) If no ReservationInfo exists with the given reservation_id, it creates a new ReservationInfo,
//    adds it to reservations_, and returns it.
// 2) If a ReservationInfo does exist with the given reservation_id
//    a) If the client_id on the existing reservation matches the given client_id given, returns a nullptr.
//    b) Otherwise, increments the client_count on the existing ReservationInfo and returns the info.
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
    info->lock = std::make_unique<Semaphore>();
    info->client_count = 1;
    reservations_.emplace(reservation_id, info);
  }
  return info;
}

// Returns a boolean value indicating whether or not the client_id holds the reservation_id and it also sets the
// status to an appropriate grpc::Status providing more detail about the circumstances surrounding
// the returned reservation state. There are two states that are possible but multiple statuses in each state:
// 1. The provided client_id does not hold the reservation_id:
//   a. If the reservation_id or client_id are empty then the status is set to INVALID_ARGUMENT
//   b. If the reservation is not created because an external call like reset_server changed the server state while
//      waiting to acquire the reservation then the status is set to ABORTED.
//   c. If the reserve call is cancelled by a client call to cancel or by exceeding the client's deadline then
//      the status is set to CANCELLED.
// 2. The provided client_id does hold the reservation_id:
//   a. If the reservation requested is already reserved by client_id then status is set to FAILED_PRECONDITION. The
//      precondition in this case is that the client_id doesn't already hold the reservation_id.
//   b. If the reservation is created for client_id or if the reservation is changed from another client to client_id
//      then the status is set to OK.
bool SessionRepository::reserve(
    const ::grpc::ServerContext* context,
    const std::string& reservation_id,
    const std::string& client_id,
    ::grpc::Status& status)
{
  if (reservation_id.empty() || client_id.empty()) {
    status = ::grpc::Status(::grpc::INVALID_ARGUMENT, "You must specify a non-empty reservation_id and client_id.");
    return false;
  }
  std::shared_ptr<ReservationInfo> info = find_or_create_reservation(reservation_id, client_id);
  if (!info) {
    status = ::grpc::Status(::grpc::FAILED_PRECONDITION, "The provided reservation_id is already reserved by the provided client_id.");
    return true;
  }
  // If the info was newly created by find_or_create_reservation, this call
  // will not wait. On subsequent calls to reserve with the same reservation_id
  // and a different client_id, it will wait until the lock calls notify which
  // releases the lock one client at a time.
  info->lock->wait();
  {
    std::unique_lock<std::shared_mutex> lock(repository_lock_);
    info->client_count--;
    auto it = reservations_.find(reservation_id);
    if (context->IsCancelled()) {
      info->lock->notify();
      if (it != reservations_.end() && info->client_count <= 0) {
        reservations_.erase(it);
      }
      status = ::grpc::Status::CANCELLED;
      return false;
    }
    info->client_id = client_id;
    bool is_reserved = it != reservations_.end() && client_id == it->second->client_id;
    status = is_reserved
        ? ::grpc::Status::OK
        : ::grpc::Status(::grpc::ABORTED, "The reservation attempt was aborted by another server operation.");
    return is_reserved;
  }
}

bool SessionRepository::is_reserved_by_client(const std::string& reservation_id, const std::string& client_id)
{
  std::unique_lock<std::shared_mutex> lock(repository_lock_);
  auto it = reservations_.find(reservation_id);
  return it != reservations_.end() && client_id == it->second->client_id;
}

// Unreserving a reservation notifies the lock on the reservation, allowing the next client
// waiting to get the reservation.
// If there are no clients waiting on the lock, the reservation is removed from the reservations_ map.
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
  for (auto it = reservations_.begin(); it != reservations_.end();) {
    std::shared_ptr<SessionRepository::ReservationInfo> reservation_info = it->second;
    it = reservations_.erase(it);
    reservation_info->lock->cancel();
  }
}

bool SessionRepository::reset_server()
{
  std::unique_lock<std::shared_mutex> lock(repository_lock_);
  clear_reservations();
  bool is_server_reset = close_sessions();
  return is_server_reset && reservations_.empty();
}

bool SessionRepository::close_sessions()
{
  named_sessions_.clear();
  for (auto it = sessions_.begin(); it != sessions_.end();) {
    cleanup_session(it->second);
    it = sessions_.erase(it);
  }
  return named_sessions_.empty() && sessions_.empty();
}

void SessionRepository::cleanup_session(const std::shared_ptr<SessionInfo>& session_info)
{
  auto cleanup_process = session_info->cleanup_func;
  if (cleanup_process) {
    cleanup_process(session_info->id);
  }
}

}  // namespace nidevice_grpc
