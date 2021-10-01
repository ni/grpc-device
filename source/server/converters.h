#ifndef NIDEVICE_GRPC_DEVICE_CONVERTERS_H
#define NIDEVICE_GRPC_DEVICE_CONVERTERS_H

#include <google/protobuf/repeated_field.h>

#include <algorithm>
#include <string>
#include <vector>

namespace nidevice_grpc {
namespace converters {
inline void trim_trailing_nulls(std::string& s)
{
  // Erase from the first non-null character (going backwards) to the end.
  s.erase(
      std::find_if(
          s.rbegin(),
          s.rend(),
          [](unsigned char ch) { return ch != 0; })
          .base(),
      s.end());
}

template <typename CType, typename GrpcType>
void convert_to_grpc(const CType& value, GrpcType* value_out)
{
  *value_out = static_cast<GrpcType>(value);
}

template <typename CType, typename GrpcType>
CType convert_from_grpc(const GrpcType& value)
{
  return static_cast<CType>(value);
}

template <typename CType, typename GrpcType>
inline std::vector<CType> convert_from_grpc(const google::protobuf::RepeatedPtrField<GrpcType>& input)
{
  auto output = std::vector<CType>();
  output.reserve(input.size());
  std::transform(
      input.begin(),
      input.end(),
      std::back_inserter(output),
      [&](GrpcType x) { return convert_from_grpc<CType>(x); });
  return output;
}

template <typename GrpcType, typename CType>
inline void convert_to_grpc(const std::vector<CType>& input, google::protobuf::RepeatedPtrField<GrpcType>* output)
{
  for (auto item : input) {
    auto message = new GrpcType();
    convert_to_grpc(item, message);
    output->AddAllocated(message);
  }
}

template <typename BoolType>
inline void convert_to_grpc(const std::vector<BoolType>& input, google::protobuf::RepeatedField<bool>* output)
{
  for (auto item : input) {
    output->Add(item != BoolType(0));
  }
}

}  // namespace converters
}  // namespace nidevice_grpc

#endif /* NIDEVICE_GRPC_DEVICE_CONVERTERS_H */
