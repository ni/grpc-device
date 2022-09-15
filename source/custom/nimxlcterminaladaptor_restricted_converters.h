#ifndef NIDEVICE_GRPC_DEVICE_NIMXLCTERMINALADAPTOR_RESTRICTED_CONVERTERS_H
#define NIDEVICE_GRPC_DEVICE_NIMXLCTERMINALADAPTOR_RESTRICTED_CONVERTERS_H

#include "nimxlcterminaladaptor_restricted.pb.h"
#include "nimxlcterminaladaptor_restricted/nimxlcterminaladaptor_restricted_library_interface.h"
#include "server/converters.h"
#include "server/session_resource_repository.h"
#include "server/nierr_Status.h"

#include <algorithm>
#include <cstring>
#include <memory>

namespace nimxlcterminaladaptor_restricted_grpc {

// Add underscore to usings so they don't conflict with including files in the same namespace.
namespace pb_ = ::google::protobuf;

template <typename TServerContext>
struct NIErrStatusOutputConverter {
  NIErrStatusOutputConverter(TServerContext *serverContext)
  {
    context = serverContext;
    nierr_Status_initialize(&status);
  }

  ~NIErrStatusOutputConverter()
  {
    context = nullptr;
    nierr_Status_jsonFree(&status);
  }

  nierr_Status* operator&()
  {
    return &status;
  }

  std::string url_encode(const char* input) const
  {
    std::string encoded(input);
    // Replace the following characters to their equivalent '%xx' hex code
    const char* charsToEncode = "!*'();:@&=+$,/?%#[] <>~";
    for (size_t position = 0;
          ((position = encoded.find_first_of(charsToEncode, position)) != std::string::npos);
          // If an unsafe character is found, advance past the replacement hex code
          position += 3) {
        char character[4];
        ::_snprintf(character, 4, "%%%2x", static_cast<int>(encoded[position]));
        encoded.replace(position, 1, character);
    }
    return encoded;
  }

  void to_grpc(nimxlcterminaladaptor_restricted_grpc::NIErrStatus& output) const
  {
    output.set_code(status.code);
    if (nierr_Status_isFatal(&status))
    {
      std::string description = "Error " + std::to_string(status.code) + " has occurred in nimxlcTerminalAdaptor. Refer to the trailing metadata for details.";
      output.set_description(description);
      context->AddTrailingMetadata("ni-error", std::to_string((&status)->code));
      context->AddTrailingMetadata("ni-error-json", url_encode((&status)->json));
    }
  }

  TServerContext *context;
  nierr_Status status{};
};

inline void convert_to_grpc(const NIErrStatusOutputConverter<grpc::ServerContext>& storage, nimxlcterminaladaptor_restricted_grpc::NIErrStatus* output)
{
  storage.to_grpc(*output);
}

}  // namespace nimxlcterminaladaptor_restricted_grpc

// Template specializations go in nidevice_grpc::converters.
namespace nidevice_grpc {
namespace converters {

template <>
struct TypeToStorageType<nierr_Status, nimxlcterminaladaptor_restricted_grpc::NIErrStatus> {
  using StorageType = nimxlcterminaladaptor_restricted_grpc::NIErrStatusOutputConverter<grpc::ServerContext>;
};

}  // namespace converters
}  // namespace nidevice_grpc

#endif /* NIDEVICE_GRPC_DEVICE_NIMXLCTERMINALADAPTOR_RESTRICTED_CONVERTERS_H */
