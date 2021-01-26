#include "session_repository.h"

namespace ni
{
namespace hardware
{
namespace grpc
{
namespace internal
{
    static SessionRepository* instance_ = 0;

    std::shared_mutex SessionRepository::sessionLock_;
    int SessionRepository::nextSessionId_ = 1000;
    SessionRepository::NamedSessionMap SessionRepository::namedSessions_;
    SessionRepository::SessionMap SessionRepository::unnamedSessions_;

    SessionRepository* SessionRepository::instance()
    {
        if (!instance_) {
            instance_ = new SessionRepository;
        }
        return instance_;
    }

    ViSession* SessionRepository::add_session(ViSession vi, const std::string& session_user_id, CleanupSessionProc cleanup_proc)
    {    
        std::unique_lock<std::shared_mutex> lock(sessionLock_);

        auto session = new ViSession();
        if (!session_user_id.empty()) {
            session->set_sessionname(session_user_id);
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
        info->Session = vi;
        info->CleanupProc = cleanup_proc;
        info->LastAccessTime = now;
        return session;
    }

    void SessionRepository::remove_session(const ViSession& remoteSession)
    {
        std::unique_lock<std::shared_mutex> lock(sessionLock_);

        auto it = namedSessions_.find(remoteSession.sessionname());
        if (it != namedSessions_.end()) {
            namedSessions_.erase(it);
        }
        else {
            auto it = unnamedSessions_.find(remoteSession.id());
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
            return session->Session;
        }
        return ViSession();
    }

    std::shared_ptr<SessionRepository::SessionInfo> SessionRepository::lookup_session_info_unlocked(const ViSession& remote_session)
    {
        auto now = std::chrono::steady_clock::now();
        if (!remote_session.sessionname().empty()) {
            auto it = namedSessions_.find(remote_session.sessionname());
            if (it != namedSessions_.end()) {
                (*it).second->LastAccessTime = now;
                return (*it).second;
            }
        }
        else {
            auto it = unnamedSessions_.find(remote_session.id());
            if (it != unnamedSessions_.end()) {
                (*it).second->LastAccessTime = now;
                return (*it).second;
            }
        }
        return nullptr;
    }

    void SessionRepository::reserve(::grpc::ServerContext* context, const ReserveRequest* request, ReserveResponse* response)
    {
        std::shared_ptr<SessionInfo> sessionInfo;
        {
            std::unique_lock<std::shared_mutex> lock(sessionLock_);
            sessionInfo = lookup_session_info_unlocked(request->session());
        }
        if (sessionInfo != nullptr) {
            if (sessionInfo->Lock == nullptr) {
                sessionInfo->Lock = std::make_unique<internal::Semaphore>();
            }
            sessionInfo->Lock->wait();
            {
                auto now = std::chrono::steady_clock::now();
                std::unique_lock<std::shared_mutex> lock(sessionLock_);
                sessionInfo->LastAccessTime = now;
                reservedSessions_.emplace(request->clientreserveid(), sessionInfo);
            }
            response->set_status(ReserveResponse_ReserveStatus_Reserved);
        }    
        else {
            response->set_status(ReserveResponse_ReserveStatus_InvalidSession);
        }
    }

    void SessionRepository::is_reserved_by_client(::grpc::ServerContext* context, const IsReservedByClientRequest* request, IsReservedByClientResponse* response)
    {
        std::unique_lock<std::shared_mutex> lock(sessionLock_);
        auto it = reservedSessions_.find(request->clientreserveid());
        if (it != reservedSessions_.end()) {
            response->set_isreserved(true);
        }
    }

    void SessionRepository::unreserve(::grpc::ServerContext* context, const UnreserveRequest* request, UnreserveResponse* response)
    {
        std::shared_ptr<SessionInfo> sessionInfo;
        {
            std::unique_lock<std::shared_mutex> lock(sessionLock_);
            auto it = reservedSessions_.find(request->clientreserveid());
            if (it != reservedSessions_.end()) {
                sessionInfo = (*it).second;
                reservedSessions_.erase(it);
            }
        }
        if (sessionInfo != nullptr) {
            auto now = std::chrono::steady_clock::now();
            sessionInfo->LastAccessTime = now;
            sessionInfo->Lock->notify();
            response->set_isunreserved(true);
        }
    }
} // namespace internal
} // namespace grpc
} // namespace hardware
} // namespace ni
