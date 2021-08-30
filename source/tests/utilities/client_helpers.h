#ifndef CLIENT_HELPERS
#define CLIENT_HELPERS

#include <grpcpp/grpcpp.h>

#include <cstdint>

// EXPERIMENTAL client helpers for grpc-device testing.
namespace nidevice_grpc::experimental::client {

// Simplified (EXPERIMENTAL) version of std::variant that we can use on compilers with
// incomplete C++17 support.
// Note: this is semantically similar to a 2 item variant, but doesn't have the same
// internal characteristics (i.e, it's not an actual union).
template <typename TFirst, typename TSecond>
class simple_variant {
 public:
  // Implicit constructors allow passing arguments of either type to methods
  // accepting a simple_variant.
  simple_variant(const TFirst& first) : first_(first), slot_(0) {}
  simple_variant(const TSecond& second) : second_(second), slot_(1) {}

  template <typename T>
  const T* get_if() const
  {
    return get_if(type_selection<T>{});
  }

 private:
  template <typename T>
  struct type_selection {
  };

  const TFirst* get_if(type_selection<TFirst>&& selection) const
  {
    return slot_ == 0 ? &first_ : nullptr;
  }

  const TSecond* get_if(type_selection<TSecond>&& selection) const
  {
    return slot_ == 1 ? &second_ : nullptr;
  }

  TFirst first_;
  TSecond second_;
  int8_t slot_{-1};
};

inline void raise_if_error(const ::grpc::Status& status)
{
  if (!status.ok()) {
    throw new std::runtime_error(status.error_message());
  }
}

template <typename TSource, typename TDestination>
inline void copy_array(const TSource& source, TDestination* destination)
{
  destination->CopyFrom({source.cbegin(), source.cend()});
}

}  // namespace nidevice_grpc::experimental::client

#endif /* CLIENT_HELPERS */
