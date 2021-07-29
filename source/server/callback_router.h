#ifndef NIDEVICE_GRPC_DEVICE_CALLBACK_ROUTER_H
#define NIDEVICE_GRPC_DEVICE_CALLBACK_ROUTER_H

#include <atomic>
#include <functional>
#include <mutex>
#include <unordered_map>

namespace nidevice_grpc {

struct CallbackRegistration {
  using Token = void*;

  virtual ~CallbackRegistration() {}
  virtual Token token() { return {}; }
};

// Allows registering Handlers taking TArgs... and exposes a static handle_callback
// method that can be passed as a function pointer to C APIs.
// This allows Handlers to be implemented with stateful lambdas, which are not convertible
// to function pointers.
template <typename TReturn, typename... TArgs>
class CallbackRouter {
 public:
  using Handler = std::function<TReturn(TArgs...)>;
  using Token = CallbackRegistration::Token;

  class CallbackRegistrationImpl : public CallbackRegistration {
    using LockGuard = std::lock_guard<std::mutex>;

   public:
    CallbackRegistrationImpl(Token token) : token_(token) {}
    CallbackRegistrationImpl(const CallbackRegistrationImpl&) = delete;
    CallbackRegistrationImpl& operator=(const CallbackRegistrationImpl&) = delete;
    CallbackRegistrationImpl(CallbackRegistrationImpl&& rhs) = delete;
    CallbackRegistrationImpl& operator=(CallbackRegistrationImpl&& rhs) = delete;
    ~CallbackRegistrationImpl()
    {
      instance().unregister_handler(token_);
    }

    Token token()
    {
      return token_;
    }

   private:
    Token token_;
  };

  static std::unique_ptr<CallbackRegistration> register_handler(const Handler& handler)
  {
    auto token = instance().allocate_token_for_handler(handler);
    return std::make_unique<CallbackRegistrationImpl>(token);
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
    auto token = reinterpret_cast<Token>(++callback_id_);
    handlers_[token] = std::make_shared<Handler>(handler);
    return token;
  }

  TReturn route_callback_to_handler(TArgs... args, Token token)
  {
    // shared_ptr in this method scope ensures that the callback is not deleted
    // while it's being called.
    auto handler_shared_ptr = get_handler(token);
    Handler* handler_ptr = handler_shared_ptr.get();
    if (!handler_ptr) return 0;

    return (*handler_ptr)(args...);
  }

  std::shared_ptr<Handler> get_handler(Token token)
  {
    LockGuard guard(mutex_);
    auto handler_it = handlers_.find(token);
    if (handler_it == handlers_.end()) {
      return {};
    }
    return handler_it->second;
  }

  void unregister_handler(Token token)
  {
    LockGuard guard(mutex_);
    handlers_.erase(token);
  }

  using LockGuard = std::lock_guard<std::mutex>;
  using HandlerMap = std::unordered_map<Token, std::shared_ptr<Handler>>;
  std::atomic<size_t> callback_id_{0};
  std::mutex mutex_;
  HandlerMap handlers_;
};
}  // namespace nidevice_grpc

#endif  // NIDEVICE_GRPC_DEVICE_CALLBACK_ROUTER_H
