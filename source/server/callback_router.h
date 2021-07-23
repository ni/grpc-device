#ifndef NIDEVICE_GRPC_DEVICE_CALLBACK_ROUTER_H
#define NIDEVICE_GRPC_DEVICE_CALLBACK_ROUTER_H

#include <atomic>
#include <functional>
#include <mutex>
#include <unordered_map>

#include "async_method_context.h"

namespace nidevice_grpc {

// Allows registering Handlers taking TArgs... and exposes a static handle_callback
// method that can be passed as a function pointer to C APIs.
// This allows Handlers to be implemented with stateful lambdas, which are not convertible
// to function pointers.
template <typename TReturn, typename... TArgs>
class CallbackRouter {
 public:
  using Handler = std::function<TReturn(TArgs...)>;

  // Move-only RAII type exposed through register_handler, to auto-unregister_handler when leaving scope.
  class CallbackRegistration : public nidevice_grpc::AsyncOperationRegistration {
   public:
    CallbackRegistration(AsyncOperationToken token) : token_(token) {}
    CallbackRegistration(const CallbackRegistration&) = delete;
    CallbackRegistration& operator=(const CallbackRegistration&) = delete;
    CallbackRegistration(CallbackRegistration&& rhs) = delete;
    CallbackRegistration& operator=(CallbackRegistration&& rhs) = delete;
    ~CallbackRegistration()
    {
      instance().unregister_handler(token_);
    }

    AsyncOperationToken token() override
    {
      return token_;
    }

   private:
    AsyncOperationToken token_;
  };

  static std::unique_ptr<AsyncOperationRegistration> register_handler(const Handler& handler)
  {
    auto token = instance().allocate_token_for_handler(handler);
    return std::make_unique<CallbackRegistration>(token);
  }

  static TReturn handle_callback(TArgs... args, AsyncOperationToken token)
  {
    return instance().route_callback_to_handler(args..., token);
  }

 private:
  CallbackRouter() {}
  CallbackRouter(const CallbackRouter&) = delete;
  CallbackRouter& operator=(const CallbackRouter&) = delete;
  CallbackRouter(CallbackRouter&&) = delete;
  CallbackRouter& operator=(CallbackRouter&&) = delete;

  static CallbackRouter& instance()
  {
    static CallbackRouter instance;
    return instance;
  }

  AsyncOperationToken allocate_token_for_handler(const Handler& handler)
  {
    LockGuard guard(mutex_);
    auto token = reinterpret_cast<AsyncOperationToken>(callback_id_++);
    handlers_[token] = std::make_shared<Handler>(handler);
    return token;
  }

  TReturn route_callback_to_handler(TArgs... args, AsyncOperationToken token)
  {
    // shared_ptr in this method scope ensures that the callback is not deleted
    // while it's being called.
    auto handler_shared_ptr = get_handler(token);
    Handler* handler_ptr = handler_shared_ptr.get();
    if (!handler_ptr) return 0;

    return (*handler_ptr)(args...);
  }

  std::shared_ptr<Handler> get_handler(AsyncOperationToken token)
  {
    LockGuard guard(mutex_);
    auto handler_it = handlers_.find(token);
    if (handler_it == handlers_.end()) {
      return {};
    }
    return handler_it->second;
  }

  void unregister_handler(AsyncOperationToken token)
  {
    LockGuard guard(mutex_);
    handlers_.erase(token);
  }

  using LockGuard = std::lock_guard<std::mutex>;
  using HandlerMap = std::unordered_map<AsyncOperationToken, std::shared_ptr<Handler>>;
  std::atomic<size_t> callback_id_{0};
  std::mutex mutex_;
  HandlerMap handlers_;
};

}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_DEVICE_CALLBACK_ROUTER_H
