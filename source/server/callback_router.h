#ifndef NIDEVICE_GRPC_DEVICE_CALLBACK_ROUTER_H
#define NIDEVICE_GRPC_DEVICE_CALLBACK_ROUTER_H

#include <atomic>
#include <functional>
#include <mutex>
#include <unordered_map>

namespace nidevice_grpc {

// Allows registering Handlers taking TArgs... and exposes a static handle_callback
// method that can be passed as a function pointer to C APIs.
// This allows Handlers to be implemented with stateful lambdas, which are not convertible
// to function pointers.
template <typename TReturn, typename... TArgs>
class CallbackRouter {
 public:
  using Handler = std::function<TReturn(TArgs...)>;
  using Token = void*;

  // Move-only RAII type exposed through register_handler, to auto-unregister_handler when leaving scope.
  class CallbackRegistration {
   public:
    CallbackRegistration() : token_(0) {}
    CallbackRegistration(Token token) : token_(token) {}
    CallbackRegistration(const CallbackRegistration&) = delete;
    CallbackRegistration& operator=(const CallbackRegistration&) = delete;
    CallbackRegistration(CallbackRegistration&& rhs) : token_(rhs.token_) { rhs.token_ = reinterpret_cast<Token>(0); }
    CallbackRegistration& operator=(CallbackRegistration&& rhs)
    {
      std::swap(token_, rhs.token_);
      return *this;
    }
    ~CallbackRegistration()
    {
      if (token_) {
        instance().unregister_handler(token_);
      }
    }

    Token token()
    {
      return token_;
    }

   private:
    Token token_;
  };

  static CallbackRegistration register_handler(const Handler& handler)
  {
    auto token = instance().allocate_token_for_handler(handler);
    return {token};
  }

  static TReturn handle_callback(TArgs... args, Token token)
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

  Token allocate_token_for_handler(const Handler& handler)
  {
    LockGuard guard(mutex_);
    auto token = reinterpret_cast<Token>(callback_id_++);
    handlers_[token] = handler;
    return token;
  }

  TReturn route_callback_to_handler(TArgs... args, Token token)
  {
    Handler handler;

    {
      LockGuard guard(mutex_);
      auto handler_it = handlers_.find(token);
      if (handler_it == handlers_.end()) {
        return 0;
      }
      handler = handler_it->second;
    }

    return handler(args...);
  }

  void unregister_handler(Token token)
  {
    LockGuard guard(mutex_);
    handlers_.erase(token);
  }

  using LockGuard = std::lock_guard<std::mutex>;
  using HandlerMap = std::unordered_map<Token, Handler>;
  std::atomic<size_t> callback_id_{0};
  std::mutex mutex_;
  HandlerMap handlers_;
};
}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_DEVICE_CALLBACK_ROUTER_H
