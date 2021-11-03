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

bool FeatureToggles::is_feature_enabled(
    const std::string& feature_name,
    FeatureToggles::CodeReadiness feature_readiness) const
{
  auto toggle_state = get_feature_state(feature_name);
  if (feature_readiness >= app_readiness_) {
    return toggle_state != FeatureState::kDisabled;
  }
  return toggle_state == FeatureState::kEnabled;
}
}  // namespace nidevice_grpc
