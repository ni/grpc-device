#ifndef NIDEVICE_GRPC_DEVICE_IVI_ERRORS_H
#define NIDEVICE_GRPC_DEVICE_IVI_ERRORS_H
#include <vector>

#include "IviVisaType.h"

template <typename TLibraryPtr>
std::string get_last_error_message(TLibraryPtr& library)
{
  std::vector<char> error_message;
  ViStatus error_code;
  // Calling with no ViSession gives us thread-local errors instead of session
  // scoped errors. This method should only be used in cases where that is correct.
  constexpr auto INVALID_SESSION = static_cast<ViSession>(0UL);
  const auto buffer_size = library->GetError(INVALID_SESSION, &error_code, 0, nullptr);
  error_message.resize(buffer_size);
  library->GetError(INVALID_SESSION, &error_code, buffer_size, error_message.data());

  return std::string(error_message.data());
}

#endif  // NIDEVICE_GRPC_DEVICE_IVI_ERRORS_H
