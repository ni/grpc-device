#ifndef NIDEVICE_GRPC_DEVICE_NIMXLCTERMINALADAPTOR_RESTRICTED_CONVERTERS_H
#define NIDEVICE_GRPC_DEVICE_NIMXLCTERMINALADAPTOR_RESTRICTED_CONVERTERS_H

#include "nimxlcterminaladaptor_restricted.pb.h"
#include "nimxlcterminaladaptor_restricted/nimxlcterminaladaptor_restricted_library_interface.h"
#include "server/converters.h"
#include "server/session_resource_repository.h"
#include <nierr_Status.h>

#include <algorithm>
#include <cstring>
#include <memory>

namespace nimxlcterminaladaptor_restricted_grpc {

// Add underscore to usings so they don't conflict with including files in the same namespace.
namespace pb_ = ::google::protobuf;

struct NiErrStatusInputConverter {
  NiErrStatusInputConverter(const NIErrStatus& input)
  {
    status.code = input.code();
    status.capacity = input.capacity();
    status.reallocJson = &nierr_defaultReallocJson;
    status.json = (char*)malloc(status.capacity);
    std::memcpy(status.json, input.json().c_str(), status.capacity);
  }

  operator nierr_Status*()
  {
    return &status;
  }

  nierr_Status status{};
};

template <typename TniErrStatus>
inline NiErrStatusInputConverter convert_from_grpc(const NIErrStatus& input)
{
  return NiErrStatusInputConverter(input);
}
}  // namespace nimxlcterminaladaptor_restricted_grpc

// Template specializations go in nidevice_grpc::converters.
namespace nidevice_grpc {
namespace converters {

inline void convert_to_grpc(nierr_Status& input, nimxlcterminaladaptor_restricted_grpc::NIErrStatus* output)
{
  output->set_code(input.code);
  output->set_capacity(input.capacity);
  output->set_json(input.json);
}
}
}

#endif /* NIDEVICE_GRPC_DEVICE_NIMXLCTERMINALADAPTOR_RESTRICTED_CONVERTERS_H */
