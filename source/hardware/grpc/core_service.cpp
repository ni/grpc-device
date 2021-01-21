#include "core_service.h"

namespace ni
{
namespace hardware
{
namespace grpc
{
namespace impl
{
std::shared_mutex CoreService::s_SessionLock;
int CoreService::s_NextSessionId = 1000;
CoreService::NamedSessionMap CoreService::s_NamedSessions;
CoreService::SessionMap CoreService::s_UnnamedSessions;

//---------------------------------------------------------------------
//---------------------------------------------------------------------
ViSession* CoreService::AddSession(ViSession vi, const std::string& sessionUserId, CleanupSessionProc cleanupProc)
{    
    std::unique_lock<std::shared_mutex> lock(s_SessionLock);

    auto session = new ViSession();
    if (!sessionUserId.empty())
    {
        session->set_sessionname(sessionUserId);
    }
    else
    {
        auto id = ++s_NextSessionId;
        session->set_id(id);
    }
    auto info = LookupSessionInfoUnlocked(*session);
    if (info == nullptr)
    {
        info = std::make_shared<SessionInfo>();
        if (sessionUserId.empty())
        {
            s_UnnamedSessions.emplace(session->id(), info);
        }
        else
        {
            s_NamedSessions.emplace(sessionUserId, info);
        }
    }
    auto now = std::chrono::steady_clock::now();
    info->Session = vi;
    info->CleanupProc = cleanupProc;
    info->LastAccessTime = now;
    return session;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
void CoreService::RemoveSession(ViSession remoteSession)
{
   std::unique_lock<std::shared_mutex> lock(s_SessionLock);

   auto it = s_NamedSessions.find(remoteSession.sessionname());
   if (it != s_NamedSessions.end())
   {
      s_NamedSessions.erase(it);
   }
   else
   {
      auto it = s_UnnamedSessions.find(remoteSession.id());
      if (it != s_UnnamedSessions.end())
      {
            s_UnnamedSessions.erase(it);
      }
   }
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
ViSession CoreService::LookupSession(const ViSession& remoteSession)
{
   std::shared_lock<std::shared_mutex> lock(s_SessionLock);
   auto session = LookupSessionInfoUnlocked(remoteSession);
   if (session != nullptr)
   {
      return session->Session;
   }
   return ViSession();
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
std::shared_ptr<CoreService::SessionInfo> CoreService::LookupSessionInfoUnlocked(const ViSession& remoteSession)
{
    auto now = std::chrono::steady_clock::now();
    if (!remoteSession.sessionname().empty())
    {
        auto it = s_NamedSessions.find(remoteSession.sessionname());
        if (it != s_NamedSessions.end())
        {
            (*it).second->LastAccessTime = now;
            return (*it).second;
        }
    }
    else
    {
        auto it = s_UnnamedSessions.find(remoteSession.id());
        if (it != s_UnnamedSessions.end())
        {
            (*it).second->LastAccessTime = now;
            return (*it).second;
        }
    }
    return nullptr;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status CoreService::Reserve(::grpc::ServerContext* context, const ReserveRequest* request, ReserveResponse* response)
{
    std::shared_ptr<SessionInfo> sessionInfo;
    {
        std::unique_lock<std::shared_mutex> lock(s_SessionLock);
        sessionInfo = LookupSessionInfoUnlocked(request->session());
        if (sessionInfo->Lock == nullptr)
        {
            sessionInfo->Lock = std::make_unique<Semaphore>();
        }
    }
    if (sessionInfo != nullptr)
    {
        sessionInfo->Lock->wait();
        {
            auto now = std::chrono::steady_clock::now();
            std::unique_lock<std::shared_mutex> lock(s_SessionLock);
            sessionInfo->LastAccessTime = now;
            _reservedSessions.emplace(request->clientreserveid(), sessionInfo);
        }
        response->set_status(ReserveResponse_ReserveStatus_Reserved);
    }    
    else
    {
        response->set_status(ReserveResponse_ReserveStatus_InvaidSession);
    }
    return ::grpc::Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status CoreService::IsReservedByClient(::grpc::ServerContext* context, const IsReservedByClientRequest* request, IsReservedByClientResponse* response)
{
   std::unique_lock<std::shared_mutex> lock(s_SessionLock);
   auto it = _reservedSessions.find(request->clientreserveid());
   if (it != _reservedSessions.end())
   {
      response->set_isreserved(true);
   }
   return ::grpc::Status::OK;
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
::grpc::Status CoreService::Unreserve(::grpc::ServerContext* context, const UnreserveRequest* request, UnreserveResponse* response)
{
    std::shared_ptr<SessionInfo> sessionInfo;
    {
        std::unique_lock<std::shared_mutex> lock(s_SessionLock);
        auto it = _reservedSessions.find(request->clientreserveid());
        if (it != _reservedSessions.end())
        {
            sessionInfo = (*it).second;
            _reservedSessions.erase(it);
        }
    }
    if (sessionInfo != nullptr)
    {
        auto now = std::chrono::steady_clock::now();
        sessionInfo->LastAccessTime = now;
        sessionInfo->Lock->notify();
        response->set_isunreserved(true);
    }    
    return ::grpc::Status::OK;
}
}
}
}
}
