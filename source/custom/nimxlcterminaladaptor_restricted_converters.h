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

bool nierr_noOpReallocJson(struct nierr_Status * s, uint32_t size);

void nierr_Status_initialize(struct nierr_Status * status);

struct NIErrStatusOutputConverter {
  NIErrStatusOutputConverter()
  {
    nierr_Status_initialize(&status);
  }

  nierr_Status* operator&()
  {
    return &status;
  }

  void to_grpc(nimxlcterminaladaptor_restricted_grpc::NIErrStatus& output) const
  {
    output.set_code(status.code);
    output.set_capacity(status.capacity);
    if (status.json != nullptr)
    {
      output.set_json(status.json);
    }
  }

  nierr_Status status{};
};

inline void convert_to_grpc(const NIErrStatusOutputConverter& storage, nimxlcterminaladaptor_restricted_grpc::NIErrStatus* output)
{
  storage.to_grpc(*output);
}

}  // namespace nimxlcterminaladaptor_restricted_grpc

// Template specializations go in nidevice_grpc::converters.
namespace nidevice_grpc {
namespace converters {

inline void convert_to_grpc(nierr_Status& input, nimxlcterminaladaptor_restricted_grpc::NIErrStatus* output)
{
  output->set_code(input.code);
  output->set_capacity(input.capacity);
  if (input.capacity > 0) {
    output->set_json(input.json);
  }
  else {
    output->set_json("");
  }
}

template <>
struct TypeToStorageType<nierr_Status, nimxlcterminaladaptor_restricted_grpc::NIErrStatus> {
  using StorageType = nimxlcterminaladaptor_restricted_grpc::NIErrStatusOutputConverter;
};

}  // namespace converters
}  // namespace nidevice_grpc

#endif /* NIDEVICE_GRPC_DEVICE_NIMXLCTERMINALADAPTOR_RESTRICTED_CONVERTERS_H */
