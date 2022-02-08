#ifndef NIDEVICE_GRPC_TESTS_WAVEFORM_HELPERS
#define NIDEVICE_GRPC_TESTS_WAVEFORM_HELPERS

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <vector>

namespace ni {
namespace tests {
namespace system {

template <typename TComplex>
struct TestWaveform {
  double t0;
  double dt;
  std::vector<TComplex> data;
};

template <typename TFloat>
struct TestIQData {
  double t0;
  double dt;
  std::vector<TFloat> I;
  std::vector<TFloat> Q;
};

template <typename TFloat, typename TComplex>
TComplex complex(TFloat real, TFloat imaginary)
{
  auto c = TComplex{};
  c.set_real(real);
  c.set_imaginary(imaginary);
  return c;
}

template <typename TFloat, typename TComplex>
std::vector<TComplex> complex_array(
    const std::vector<TFloat>& reals,
    const std::vector<TFloat>& imaginaries)
{
  auto c = std::vector<TComplex>{};
  c.reserve(reals.size());
  std::transform(
      reals.begin(),
      reals.end(),
      imaginaries.begin(),
      std::back_inserter(c),
      [](TFloat real, TFloat imaginary) { return complex<TFloat, TComplex>(real, imaginary); });
  return c;
}

template <typename TFloat>
TestIQData<TFloat> load_iq_data_from_json(nlohmann::json json)
{
  auto t0 = json.find("t0")->get<double>();
  auto dt = json.find("dt")->get<double>();
  auto reals = json.find("reals")->get<std::vector<TFloat>>();
  auto imaginaries = json.find("imaginaries")->get<std::vector<TFloat>>();
  return {t0, dt, reals, imaginaries};
}

template <typename TFloat>
TestIQData<TFloat> load_test_iq_data(const std::string& file_name)
{
  std::ifstream input_stream(file_name);
  auto json = nlohmann::json::parse(input_stream);
  return load_iq_data_from_json<TFloat>(json);
}

template <typename TFloat, typename TComplex>
TestWaveform<TComplex> load_test_waveform_data(const std::string& file_name)
{
  const auto iq_data = load_test_iq_data<TFloat>(file_name);
  return {iq_data.t0, iq_data.dt, complex_array<TFloat, TComplex>(iq_data.I, iq_data.Q)};
}

template <typename TFloat>
std::vector<TestIQData<TFloat>> load_test_multiple_iq_data(const std::string& file_name, const int count)
{
  auto iq_data = std::vector<TestIQData<TFloat>>{};
  std::ifstream input_stream(file_name);
  auto json = nlohmann::json::parse(input_stream);
  for (int i = 1; i <= count; i++) {
    auto key = "waveform" + std::to_string(i);
    auto waveform_json = json.at(key);
    auto data = load_iq_data_from_json<TFloat>(waveform_json);
    iq_data.push_back(data);
  }
  return iq_data;
}

template <typename TFloat, typename TComplex>
std::vector<TestWaveform<TComplex>> load_test_multiple_waveforms_data(const std::string& file_name, const int count)
{
  auto waveforms = std::vector<TestWaveform<TComplex>>{};
  const auto iq_data = load_test_multiple_iq_data<TFloat>(file_name, count);
  for (int i = 0; i < count; i++) {
    auto waveform = iq_data[i];
    waveforms.push_back({waveform.t0, waveform.dt, complex_array<TFloat, TComplex>(waveform.I, waveform.Q)});
  }
  return waveforms;
}

}  // namespace system
}  // namespace tests
}  // namespace ni

#endif  // NIDEVICE_GRPC_TESTS_WAVEFORM_HELPERS
