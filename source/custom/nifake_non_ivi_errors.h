#ifndef NIDEVICE_GRPC_DEVICE_NIFAKE_NON_IVI_ERRORS_H
#define NIDEVICE_GRPC_DEVICE_NIFAKE_NON_IVI_ERRORS_H

#include <vector>

template <typename TLibraryPtr>
std::string get_last_error(TLibraryPtr& library)
{
  std::vector<char> error_message;
  const auto buffer_size = library->GetLatestErrorMessage(nullptr, 0);
  error_message.resize(buffer_size);
  library->GetLatestErrorMessage(error_message.data(), buffer_size);

  return std::string(error_message.data());
}

#endif  // NIDEVICE_GRPC_DEVICE_NIFAKE_NON_IVI_ERRORS_H
