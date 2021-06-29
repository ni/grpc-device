#ifndef NIDEVICE_GRPC_FEATURE_TOGGLES_H
#define NIDEVICE_GRPC_FEATURE_TOGGLES_H

#include <string>
#include <unordered_map>
namespace nidevice_grpc {

using FeatureToggleConfigurationMap = std::unordered_map<std::string, bool>;
class FeatureToggles {
 public:
  enum class FeatureState {
    kDisabled,
    kEnabled,
    kUnspecified
  };
  FeatureToggles() {}
  FeatureToggles(FeatureToggleConfigurationMap&& map) : map_(map) {}
  FeatureState get_feature_state(const std::string& feature_name) const;

 private:
  FeatureToggleConfigurationMap map_;
};
}  // namespace nidevice_grpc


#endif /* NIDEVICE_GRPC_FEATURE_TOGGLES_H */
