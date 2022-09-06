#ifndef CLIENT_HELPERS
#define CLIENT_HELPERS

#include <grpcpp/grpcpp.h>
#include <server/converters.h>

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

  // If T is the active slot: return a copy of the data. Else return default initialized T.
  template <typename T>
  T unpack() const
  {
    auto ptr_to_data = get_if<T>();
    return ptr_to_data ? *ptr_to_data : T{};
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

class grpc_driver_error : public std::runtime_error {
 private:
  ::grpc::StatusCode code_;
  std::multimap<std::string, std::string> trailers_;

 public:
  grpc_driver_error(const std::string& message, ::grpc::StatusCode code, const std::multimap<grpc::string_ref, grpc::string_ref>& trailers)
      : std::runtime_error(message), code_(code)
  {
    for (const auto& trailer : trailers) {
      trailers_.emplace(
          std::string(trailer.first.data(), trailer.first.length()),
          std::string(trailer.second.data(), trailer.second.length()));
    }
  }
  ::grpc::StatusCode StatusCode() const
  {
    return code_;
  }
  const std::multimap<std::string, std::string>& Trailers() const
  {
    return trailers_;
  }
};

inline void
raise_if_error(const ::grpc::Status& status, const ::grpc::ClientContext& context)
{
  if (!status.ok()) {
    throw grpc_driver_error(status.error_message(), status.error_code(), context.GetServerTrailingMetadata());
  }
}

template <typename TSource, typename TDestination>
inline void copy_array(const TSource& source, TDestination* destination)
{
  destination->CopyFrom({source.cbegin(), source.cend()});
}

template <typename TArray, typename TBitfield>
inline google::protobuf::int32 copy_bitfield_as_enum_array(const simple_variant<TArray, TBitfield>& input)
{
  // Note: "template" qualifiers required for dependent name:
  // https://stackoverflow.com/questions/610245/where-and-why-do-i-have-to-put-the-template-and-typename-keywords
  const auto unpacked_array = input.template unpack<TArray>();
  const auto unpacked_bitfield = input.template unpack<TBitfield>();
  return nidevice_grpc::converters::convert_bitfield_as_enum_array_input(unpacked_array, unpacked_bitfield);
}

}  // namespace nidevice_grpc::experimental::client

#endif /* CLIENT_HELPERS */
