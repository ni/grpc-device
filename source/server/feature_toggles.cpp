#include "feature_toggles.h"

namespace nidevice_grpc {
bool FeatureToggles::is_enabled(const std::string& feature_name) const
{
  auto found = map_.find(feature_name);
  if (found != map_.end()) {
    return found->second;
  }
  return false;
}
}  // namespace nidevice_grpc
