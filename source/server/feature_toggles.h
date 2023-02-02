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
  enum class CodeReadiness {
    kPrototype = 0,
    kIncomplete = 1,
    kNextRelease = 2,
    kRelease = 3,
  };

  FeatureToggles() {}
  FeatureToggles(FeatureToggleConfigurationMap&& map, CodeReadiness app_readiness = CodeReadiness::kRelease)
      : map_(map),
        app_readiness_(app_readiness) {}
  FeatureState get_feature_state(const std::string& feature_name) const;
  bool is_feature_enabled(
      const std::string& feature_name,
      CodeReadiness feature_readiness) const;

 private:
  FeatureToggleConfigurationMap map_;
  CodeReadiness app_readiness_ = CodeReadiness::kRelease;
};
}  // namespace nidevice_grpc

#endif /* NIDEVICE_GRPC_FEATURE_TOGGLES_H */
