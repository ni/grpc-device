
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// EXPERIMENTAL Client convenience wrapper for NI-rfmxtdscdma.
//---------------------------------------------------------------------
#ifndef NIRFMXTDSCDMA_GRPC_CLIENT_H
#define NIRFMXTDSCDMA_GRPC_CLIENT_H

#include <grpcpp/grpcpp.h>

#include <nirfmxtdscdma.grpc.pb.h>
#include <tests/utilities/client_helpers.h>

#include <memory>
#include <vector>

namespace nirfmxtdscdma_grpc::experimental::client {

namespace pb = ::google::protobuf;
using StubPtr = std::unique_ptr<NiRFmxTDSCDMA::Stub>;
using namespace nidevice_grpc::experimental::client;


ACPCfgAveragingResponse acp_cfg_averaging(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const simple_variant<AcpAveragingEnabled, pb::int32>& averaging_enabled, const pb::int32& averaging_count, const simple_variant<AcpAveragingType, pb::int32>& averaging_type);
ACPCfgMeasurementMethodResponse acp_cfg_measurement_method(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const simple_variant<AcpMeasurementMethod, pb::int32>& measurement_method);
ACPCfgNoiseCompensationEnabledResponse acp_cfg_noise_compensation_enabled(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const simple_variant<AcpNoiseCompensationEnabled, pb::int32>& noise_compensation_enabled);
ACPCfgNumberOfOffsetsResponse acp_cfg_number_of_offsets(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const pb::int32& number_of_offsets);
ACPCfgRBWFilterResponse acp_cfg_rbw_filter(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const simple_variant<AcpRbwAutoBandwidth, pb::int32>& rbw_auto, const double& rbw, const simple_variant<AcpRbwFilterType, pb::int32>& rbw_filter_type);
ACPCfgSweepTimeResponse acp_cfg_sweep_time(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const simple_variant<AcpSweepTimeAuto, pb::int32>& sweep_time_auto, const double& sweep_time_interval);
ACPFetchAbsolutePowersTraceResponse acp_fetch_absolute_powers_trace(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout, const pb::int32& trace_index);
ACPFetchCarrierAbsolutePowerResponse acp_fetch_carrier_absolute_power(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
ACPFetchOffsetMeasurementResponse acp_fetch_offset_measurement(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
ACPFetchOffsetMeasurementArrayResponse acp_fetch_offset_measurement_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
ACPFetchRelativePowersTraceResponse acp_fetch_relative_powers_trace(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout, const pb::int32& trace_index);
ACPFetchSpectrumResponse acp_fetch_spectrum(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
AbortMeasurementsResponse abort_measurements(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string);
AnalyzeIQ1WaveformResponse analyze_iq1_waveform(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const std::string& result_name, const double& x0, const double& dx, const std::vector<nidevice_grpc::NIComplexNumberF32>& iq, const pb::int32& reset);
AnalyzeIQ1WaveformSplitResponse analyze_iq1_waveform_split(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const std::string& result_name, const double& x0, const double& dx, const std::vector<float>& iqi, const std::vector<float>& iqq, const pb::int32& reset);
AnalyzeSpectrum1WaveformResponse analyze_spectrum1_waveform(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const std::string& result_name, const double& x0, const double& dx, const std::vector<float>& spectrum, const pb::int32& reset);
AutoLevelResponse auto_level(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& measurement_interval);
BuildChannelStringResponse build_channel_string(const StubPtr& stub, const std::string& selector_string, const pb::int32& channel_number);
BuildOffsetStringResponse build_offset_string(const StubPtr& stub, const std::string& selector_string, const pb::int32& offset_number);
BuildSegmentStringResponse build_segment_string(const StubPtr& stub, const std::string& selector_string, const pb::int32& segment_number);
BuildSignalStringResponse build_signal_string(const StubPtr& stub, const std::string& signal_name, const std::string& result_name);
CDACfgAveragingResponse cda_cfg_averaging(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const simple_variant<CdaAveragingEnabled, pb::int32>& averaging_enabled, const pb::int32& averaging_count);
CDACfgMeasurementChannelResponse cda_cfg_measurement_channel(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const pb::int32& spreading_factor, const pb::int32& channelization_code);
CDACfgPowerUnitResponse cda_cfg_power_unit(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const simple_variant<CdaPowerUnit, pb::int32>& power_unit);
CDACfgSynchronizationModeAndOffsetResponse cda_cfg_synchronization_mode_and_offset(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const simple_variant<CdaSynchronizationMode, pb::int32>& synchronization_mode, const pb::int32& measurement_offset);
CDAFetchCodeDomainPowerResponse cda_fetch_code_domain_power(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
CDAFetchIQImpairmentsResponse cda_fetch_iq_impairments(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
CDAFetchMaximumCodeDomainPowerTraceResponse cda_fetch_maximum_code_domain_power_trace(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
CDAFetchMaximumSymbolEVMTraceResponse cda_fetch_maximum_symbol_evm_trace(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
CDAFetchMaximumSymbolMagnitudeErrorTraceResponse cda_fetch_maximum_symbol_magnitude_error_trace(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
CDAFetchMaximumSymbolPhaseErrorTraceResponse cda_fetch_maximum_symbol_phase_error_trace(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
CDAFetchMeanCodeDomainPowerTraceResponse cda_fetch_mean_code_domain_power_trace(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
CDAFetchMeanSymbolEVMTraceResponse cda_fetch_mean_symbol_evm_trace(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
CDAFetchMeanSymbolMagnitudeErrorTraceResponse cda_fetch_mean_symbol_magnitude_error_trace(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
CDAFetchMeanSymbolPhaseErrorTraceResponse cda_fetch_mean_symbol_phase_error_trace(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
CDAFetchSymbolConstellationTraceResponse cda_fetch_symbol_constellation_trace(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
CDAFetchSymbolConstellationTraceSplitResponse cda_fetch_symbol_constellation_trace_split(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
CDAFetchSymbolEVMResponse cda_fetch_symbol_evm(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
CHPCfgAveragingResponse chp_cfg_averaging(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const simple_variant<ChpAveragingEnabled, pb::int32>& averaging_enabled, const pb::int32& averaging_count, const simple_variant<ChpAveragingType, pb::int32>& averaging_type);
CHPCfgRBWFilterResponse chp_cfg_rbw_filter(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const simple_variant<ChpRbwAutoBandwidth, pb::int32>& rbw_auto, const double& rbw, const simple_variant<ChpRbwFilterType, pb::int32>& rbw_filter_type);
CHPCfgSweepTimeResponse chp_cfg_sweep_time(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const simple_variant<ChpSweepTimeAuto, pb::int32>& sweep_time_auto, const double& sweep_time_interval);
CHPFetchCarrierAbsolutePowerResponse chp_fetch_carrier_absolute_power(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
CHPFetchSpectrumResponse chp_fetch_spectrum(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
CfgChannelConfigurationModeResponse cfg_channel_configuration_mode(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const simple_variant<ChannelConfigurationMode, pb::int32>& channel_configuration_mode);
CfgDigitalEdgeTriggerResponse cfg_digital_edge_trigger(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const simple_variant<DigitalEdgeTriggerSource, std::string>& digital_edge_source, const simple_variant<DigitalEdgeTriggerEdge, pb::int32>& digital_edge, const double& trigger_delay, const pb::int32& enable_trigger);
CfgExternalAttenuationResponse cfg_external_attenuation(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& external_attenuation);
CfgFrequencyResponse cfg_frequency(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& center_frequency);
CfgFrequencyChannelNumberResponse cfg_frequency_channel_number(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const pb::int32& channel_number);
CfgFrequencyReferenceResponse cfg_frequency_reference(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& channel_name, const simple_variant<FrequencyReferenceSource, std::string>& frequency_reference_source, const double& frequency_reference_frequency);
CfgIQPowerEdgeTriggerResponse cfg_iq_power_edge_trigger(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const std::string& iq_power_edge_source, const simple_variant<IQPowerEdgeTriggerSlope, pb::int32>& iq_power_edge_slope, const double& iq_power_edge_level, const double& trigger_delay, const simple_variant<TriggerMinimumQuietTimeMode, pb::int32>& minimum_quiet_time_mode, const double& minimum_quiet_time, const simple_variant<IQPowerEdgeTriggerLevelType, pb::int32>& iq_power_edge_level_type, const pb::int32& enable_trigger);
CfgMechanicalAttenuationResponse cfg_mechanical_attenuation(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& channel_name, const simple_variant<MechanicalAttenuationAuto, pb::int32>& mechanical_attenuation_auto, const double& mechanical_attenuation_value);
CfgMidambleShiftResponse cfg_midamble_shift(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const simple_variant<MidambleAutoDetectionMode, pb::int32>& midamble_auto_detection_mode, const pb::int32& maximum_number_of_users, const pb::int32& midamble_shift);
CfgNumberOfChannelsResponse cfg_number_of_channels(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const pb::int32& number_of_channels);
CfgPilotResponse cfg_pilot(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const pb::int32& pilot_code);
CfgRFResponse cfg_rf(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& center_frequency, const double& reference_level, const double& external_attenuation);
CfgRFAttenuationResponse cfg_rf_attenuation(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& channel_name, const simple_variant<RFAttenuationAuto, pb::int32>& rf_attenuation_auto, const double& rf_attenuation_value);
CfgReferenceLevelResponse cfg_reference_level(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& reference_level);
CfgSoftwareEdgeTriggerResponse cfg_software_edge_trigger(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& trigger_delay, const pb::int32& enable_trigger);
CfgUplinkScramblingCodeResponse cfg_uplink_scrambling_code(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const pb::int32& uplink_scrambling_code);
CfgUserDefinedChannelResponse cfg_user_defined_channel(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const pb::int32& slot_index, const simple_variant<ChannelType, pb::int32>& channel_type, const pb::int32& slot_format, const simple_variant<ModulationType, pb::int32>& modulation_type, const pb::int32& channelization_code);
CfgUserDefinedChannelArrayResponse cfg_user_defined_channel_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const std::vector<pb::int32>& slot_index, const std::vector<pb::int32>& channel_type, const std::vector<pb::int32>& slot_format, const std::vector<pb::int32>& modulation_type, const std::vector<pb::int32>& channelization_code);
CheckMeasurementStatusResponse check_measurement_status(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string);
ClearAllNamedResultsResponse clear_all_named_results(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string);
ClearNamedResultResponse clear_named_result(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string);
CloneSignalConfigurationResponse clone_signal_configuration(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& old_signal_name, const std::string& new_signal_name);
CloseResponse close(const StubPtr& stub, const nidevice_grpc::Session& instrument, const bool& force_destroy);
CommitResponse commit(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string);
CreateSignalConfigurationResponse create_signal_configuration(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& signal_name);
DeleteSignalConfigurationResponse delete_signal_configuration(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& signal_name);
DisableTriggerResponse disable_trigger(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string);
GetAllNamedResultNamesResponse get_all_named_result_names(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string);
GetAttributeF32Response get_attribute_f32(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id);
GetAttributeF32ArrayResponse get_attribute_f32_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id);
GetAttributeF64Response get_attribute_f64(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id);
GetAttributeF64ArrayResponse get_attribute_f64_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id);
GetAttributeI16Response get_attribute_i16(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id);
GetAttributeI32Response get_attribute_i32(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id);
GetAttributeI32ArrayResponse get_attribute_i32_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id);
GetAttributeI64Response get_attribute_i64(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id);
GetAttributeI64ArrayResponse get_attribute_i64_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id);
GetAttributeI8Response get_attribute_i8(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id);
GetAttributeI8ArrayResponse get_attribute_i8_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id);
GetAttributeNIComplexDoubleArrayResponse get_attribute_ni_complex_double_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id);
GetAttributeNIComplexSingleArrayResponse get_attribute_ni_complex_single_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id);
GetAttributeStringResponse get_attribute_string(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id);
GetAttributeU16Response get_attribute_u16(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id);
GetAttributeU32Response get_attribute_u32(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id);
GetAttributeU32ArrayResponse get_attribute_u32_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id);
GetAttributeU64ArrayResponse get_attribute_u64_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id);
GetAttributeU8Response get_attribute_u8(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id);
GetAttributeU8ArrayResponse get_attribute_u8_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id);
GetErrorResponse get_error(const StubPtr& stub, const nidevice_grpc::Session& instrument);
GetErrorStringResponse get_error_string(const StubPtr& stub, const nidevice_grpc::Session& instrument, const pb::int32& error_code);
InitializeResponse initialize(const StubPtr& stub, const std::string& resource_name, const std::string& option_string, const nidevice_grpc::SessionInitializationBehavior& initialization_behavior = nidevice_grpc::SESSION_INITIALIZATION_BEHAVIOR_UNSPECIFIED);
InitializeFromNIRFSASessionResponse initialize_from_nirfsa_session(const StubPtr& stub, const nidevice_grpc::Session& nirfsa_session, const nidevice_grpc::SessionInitializationBehavior& initialization_behavior = nidevice_grpc::SESSION_INITIALIZATION_BEHAVIOR_UNSPECIFIED);
InitiateResponse initiate(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const std::string& result_name);
ModAccCfgAveragingResponse mod_acc_cfg_averaging(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const simple_variant<ModAccAveragingEnabled, pb::int32>& averaging_enabled, const pb::int32& averaging_count);
ModAccCfgSlotTypeResponse mod_acc_cfg_slot_type(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const simple_variant<ModAccMeasurementSlotType, pb::int32>& slot_type);
ModAccCfgSynchronizationModeAndIntervalResponse mod_acc_cfg_synchronization_mode_and_interval(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const simple_variant<ModAccSynchronizationMode, pb::int32>& synchronization_mode, const pb::int32& measurement_offset, const pb::int32& measurement_length);
ModAccFetchCodeDomainErrorTraceResponse mod_acc_fetch_code_domain_error_trace(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
ModAccFetchCompositeEVMResponse mod_acc_fetch_composite_evm(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
ModAccFetchConstellationTraceResponse mod_acc_fetch_constellation_trace(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
ModAccFetchConstellationTraceSplitResponse mod_acc_fetch_constellation_trace_split(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
ModAccFetchDataActiveCDEResponse mod_acc_fetch_data_active_cde(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
ModAccFetchDataCDEResponse mod_acc_fetch_data_cde(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
ModAccFetchDataEVMResponse mod_acc_fetch_data_evm(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
ModAccFetchDataRCDEResponse mod_acc_fetch_data_rcde(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
ModAccFetchDetectedChannelResponse mod_acc_fetch_detected_channel(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
ModAccFetchDetectedChannelArrayResponse mod_acc_fetch_detected_channel_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
ModAccFetchEVMTraceResponse mod_acc_fetch_evm_trace(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
ModAccFetchIQImpairmentsResponse mod_acc_fetch_iq_impairments(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
ModAccFetchMagnitudeErrorTraceResponse mod_acc_fetch_magnitude_error_trace(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
ModAccFetchMaximumCodeDomainErrorTraceResponse mod_acc_fetch_maximum_code_domain_error_trace(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
ModAccFetchMaximumEVMTraceResponse mod_acc_fetch_maximum_evm_trace(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
ModAccFetchMaximumMagnitudeErrorTraceResponse mod_acc_fetch_maximum_magnitude_error_trace(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
ModAccFetchMaximumPhaseErrorTraceResponse mod_acc_fetch_maximum_phase_error_trace(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
ModAccFetchMidambleAndDataPowerResponse mod_acc_fetch_midamble_and_data_power(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
ModAccFetchMidambleEVMResponse mod_acc_fetch_midamble_evm(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
ModAccFetchNumberOfDetectedChannelsResponse mod_acc_fetch_number_of_detected_channels(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
ModAccFetchPhaseErrorTraceResponse mod_acc_fetch_phase_error_trace(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
ModAccFetchPilotEVMResponse mod_acc_fetch_pilot_evm(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
OBWCfgAveragingResponse obw_cfg_averaging(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const simple_variant<ObwAveragingEnabled, pb::int32>& averaging_enabled, const pb::int32& averaging_count, const simple_variant<ObwAveragingType, pb::int32>& averaging_type);
OBWCfgRBWFilterResponse obw_cfg_rbw_filter(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const simple_variant<ObwRbwAutoBandwidth, pb::int32>& rbw_auto, const double& rbw, const simple_variant<ObwRbwFilterType, pb::int32>& rbw_filter_type);
OBWCfgSweepTimeResponse obw_cfg_sweep_time(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const simple_variant<ObwSweepTimeAuto, pb::int32>& sweep_time_auto, const double& sweep_time_interval);
OBWFetchMeasurementResponse obw_fetch_measurement(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
OBWFetchSpectrumResponse obw_fetch_spectrum(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
PVTCfgAveragingResponse pvt_cfg_averaging(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const simple_variant<PvtAveragingEnabled, pb::int32>& averaging_enabled, const pb::int32& averaging_count, const simple_variant<PvtAveragingType, pb::int32>& averaging_type);
PVTCfgMeasurementMethodResponse pvt_cfg_measurement_method(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const simple_variant<PvtMeasurementMethod, pb::int32>& measurement_method);
PVTFetchMeasurementStatusResponse pvt_fetch_measurement_status(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
PVTFetchPowersResponse pvt_fetch_powers(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
PVTFetchSegmentMeasurementResponse pvt_fetch_segment_measurement(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
PVTFetchSegmentMeasurementArrayResponse pvt_fetch_segment_measurement_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
PVTFetchSignalPowerTraceResponse pvt_fetch_signal_power_trace(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
ResetAttributeResponse reset_attribute(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id);
ResetToDefaultResponse reset_to_default(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string);
SEMCfgAveragingResponse sem_cfg_averaging(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const simple_variant<SemAveragingEnabled, pb::int32>& averaging_enabled, const pb::int32& averaging_count, const simple_variant<SemAveragingType, pb::int32>& averaging_type);
SEMCfgSweepTimeResponse sem_cfg_sweep_time(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const simple_variant<SemSweepTimeAuto, pb::int32>& sweep_time_auto, const double& sweep_time_interval);
SEMFetchCarrierAbsoluteIntegratedPowerResponse sem_fetch_carrier_absolute_integrated_power(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
SEMFetchLowerOffsetMarginResponse sem_fetch_lower_offset_margin(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
SEMFetchLowerOffsetMarginArrayResponse sem_fetch_lower_offset_margin_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
SEMFetchLowerOffsetPowerResponse sem_fetch_lower_offset_power(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
SEMFetchLowerOffsetPowerArrayResponse sem_fetch_lower_offset_power_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
SEMFetchMeasurementStatusResponse sem_fetch_measurement_status(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
SEMFetchSpectrumResponse sem_fetch_spectrum(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
SEMFetchUpperOffsetMarginResponse sem_fetch_upper_offset_margin(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
SEMFetchUpperOffsetMarginArrayResponse sem_fetch_upper_offset_margin_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
SEMFetchUpperOffsetPowerResponse sem_fetch_upper_offset_power(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
SEMFetchUpperOffsetPowerArrayResponse sem_fetch_upper_offset_power_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
SelectMeasurementsResponse select_measurements(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const simple_variant<std::vector<MeasurementTypes>, std::int32_t>& measurements, const bool& enable_all_traces);
SendSoftwareEdgeTriggerResponse send_software_edge_trigger(const StubPtr& stub, const nidevice_grpc::Session& instrument);
SetAttributeF32Response set_attribute_f32(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id, const float& attr_val);
SetAttributeF32ArrayResponse set_attribute_f32_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id, const std::vector<float>& attr_val);
SetAttributeF64Response set_attribute_f64(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id, const double& attr_val);
SetAttributeF64ArrayResponse set_attribute_f64_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id, const std::vector<double>& attr_val);
SetAttributeI16Response set_attribute_i16(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id, const pb::int32& attr_val);
SetAttributeI32Response set_attribute_i32(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id, const simple_variant<NiRFmxTDSCDMAInt32AttributeValues, pb::int32>& attr_val);
SetAttributeI32ArrayResponse set_attribute_i32_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id, const std::vector<pb::int32>& attr_val);
SetAttributeI64Response set_attribute_i64(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id, const pb::int64& attr_val);
SetAttributeI64ArrayResponse set_attribute_i64_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id, const std::vector<pb::int64>& attr_val);
SetAttributeI8Response set_attribute_i8(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id, const pb::int32& attr_val);
SetAttributeI8ArrayResponse set_attribute_i8_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id, const std::vector<pb::int32>& attr_val);
SetAttributeNIComplexDoubleArrayResponse set_attribute_ni_complex_double_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id, const std::vector<nidevice_grpc::NIComplexNumber>& attr_val);
SetAttributeNIComplexSingleArrayResponse set_attribute_ni_complex_single_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id, const std::vector<nidevice_grpc::NIComplexNumberF32>& attr_val);
SetAttributeStringResponse set_attribute_string(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id, const simple_variant<NiRFmxTDSCDMAStringAttributeValuesMapped, std::string>& attr_val);
SetAttributeU16Response set_attribute_u16(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id, const pb::uint32& attr_val);
SetAttributeU32Response set_attribute_u32(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id, const pb::uint32& attr_val);
SetAttributeU32ArrayResponse set_attribute_u32_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id, const std::vector<pb::uint32>& attr_val);
SetAttributeU64ArrayResponse set_attribute_u64_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id, const std::vector<pb::uint64>& attr_val);
SetAttributeU8Response set_attribute_u8(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id, const pb::uint32& attr_val);
SetAttributeU8ArrayResponse set_attribute_u8_array(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const NiRFmxTDSCDMAAttribute& attribute_id, const std::string& attr_val);
SlotPowerCfgMeasurementLengthResponse slot_power_cfg_measurement_length(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const pb::int32& measurement_length);
SlotPowerFetchPowersResponse slot_power_fetch_powers(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);
WaitForAcquisitionCompleteResponse wait_for_acquisition_complete(const StubPtr& stub, const nidevice_grpc::Session& instrument, const double& timeout);
WaitForMeasurementCompleteResponse wait_for_measurement_complete(const StubPtr& stub, const nidevice_grpc::Session& instrument, const std::string& selector_string, const double& timeout);

} // namespace nirfmxtdscdma_grpc::experimental::client

#endif /* NIRFMXTDSCDMA_GRPC_CLIENT_H */
