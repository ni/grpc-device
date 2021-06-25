#include "feature_toggles.h"

namespace nidevice_grpc {
FeatureToggles::FeatureState FeatureToggles::get_feature_state(const std::string& feature_name) const
{
  auto found = map_.find(feature_name);
  if (found != map_.end()) {
    return found->second 
    ? FeatureState::kEnabled 
    : FeatureState::kDisabled;
  }
  return FeatureState::kUnspecified;
}
}  // namespace nidevice_grpc
