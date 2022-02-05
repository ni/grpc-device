# Steps:
# 1. Open a new RFmx Session.
# 2. Configure Frequency Reference.
# 3. Configure Selected Ports.
# 4. Configure basic signal properties (Center Frequency, RF Attenuation and External Attenuation).
# 5. Configure Trigger Parameters for IQ Power Edge Trigger.
# 6. Configure Link Direction, Frequency Range and Carrier Bandwidth and Subcarrier Spacing.
# 7. Configure Reference Level.
# 8. Select ACP measurement and enable Traces.
# 9. Configure Measurement Method.
# 10. Configure Noise Compensation Parameter.
# 11. Configure Sweep Time Parameters.
# 12. Configure Averaging Parameters for ACP measurement.
# 13. Initiate the Measurement.
# 14. Fetch ACP Measurements and Traces.
# 15. Close RFmx Session.

import sys

import grpc
import nirfmxnr_pb2 as nirfmxnr_types
import nirfmxnr_pb2_grpc as grpc_nirfmxnr

server_address = "localhost"
server_port = "31763"
session_name = "NI-RFSASession"

# Resource name and options for a simulated 5663 client.
resource = "SimulatedRFSA"
options = "Simulate=1,DriverSetup=Model:5663"

# Read in cmd args
if len(sys.argv) >= 2:
    server_address = sys.argv[1]
if len(sys.argv) >= 3:
    server_port = sys.argv[2]
if len(sys.argv) >= 4:
    resource = sys.argv[3]
    options = ""

# Create a gRPC channel + client.
channel = grpc.insecure_channel(f"{server_address}:{server_port}")
client = grpc_nirfmxnr.NiRFmxNRStub(channel)
instr = None


# Maximum size of an error message
MAX_ERROR_DESCRIPTION = 4096


# Raise an exception if an error was returned
def raise_if_error(response):
    if response.status != 0:
        error_response = client.GetError(
            nirfmxspecan_types.GetErrorRequest(
                instrument=instr,
            )
        )
        raise Exception(f"Error: {error_response.error_description}")

    return response


try:
    selected_ports = ""
    center_frequency = 3.5e9  # (Hz)
    external_attenuation = 0.0  # (dB)

    auto_level = True
    reference_level = 0.0  # (dBm)
    measurement_interval = 10.0e-3  # (s)

    rf_attenuation_auto = nirfmxnr_types.RF_ATTENUATION_AUTO_TRUE
    rf_attenuation = 10.0  # (dB)

    frequency_reference_source = nirfmxnr_types.FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK
    frequency_reference_frequency = 10.0e6  # (Hz)

    iq_power_edge_enabled = False
    iq_power_edge_level = -20.0  # (dB or dBm)
    trigger_delay = 0.0  # (s)
    minimum_quiet_time_mode = nirfmxnr_types.TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO
    minimum_quiet_time = 8.0e-6  # (s)

    link_direction = nirfmxnr_types.NIRFMXNR_INT32_LINK_DIRECTION_UPLINK
    frequency_range = nirfmxnr_types.NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1
    carrier_bandwidth = 100e6  # (Hz)
    subcarrier_spacing = 30e3  # (Hz)
    measurement_method = nirfmxnr_types.ACP_MEASUREMENT_METHOD_NORMAL
    noise_compensation_enabled = nirfmxnr_types.ACP_NOISE_COMPENSATION_ENABLED_FALSE

    sweep_time_auto = nirfmxnr_types.ACP_SWEEP_TIME_AUTO_TRUE
    sweep_time_interval = 1.0e-3  # (s)

    averaging_enabled = nirfmxnr_types.ACP_AVERAGING_ENABLED_FALSE
    averaging_count = 10
    averaging_type = nirfmxnr_types.ACP_AVERAGING_TYPE_RMS

    timeout = 10.0  # (s)

    absolute_power = 0.0  # (dBm)
    relative_power = 0.0  # (dB)

    lower_relative_power = None  # (dB)
    upper_relative_power = None  # (dB)
    lower_absolute_power = None  # (dBm)
    upper_absolute_power = None  # (dBm)

    actual_array_size = 0
    array_size = 0
    x0 = 0.0
    dx = 0.0
    relative_powers_trace = None
    spectrum = None

    # Initialize a session
    initialize_response = client.Initialize(
        nirfmxnr_types.InitializeRequest(
            session_name=session_name, resource_name=resource, option_string=""
        )
    )
    instr = initialize_response.instrument
    client.CfgFrequencyReference(
        nirfmxnr_types.CfgFrequencyReferenceRequest(
            instrument=instr,
            channel_name="",
            frequency_reference_source_mapped=frequency_reference_source,
            frequency_reference_frequency=frequency_reference_frequency,
        )
    )
    client.SetAttributeString(
        nirfmxnr_types.SetAttributeStringRequest(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_SELECTED_PORTS,
            attr_val_raw=selected_ports,
        )
    )
    client.CfgFrequency(
        nirfmxnr_types.CfgFrequencyRequest(
            instrument=instr, selector_string="", center_frequency=center_frequency
        )
    )
    client.CfgExternalAttenuation(
        nirfmxnr_types.CfgExternalAttenuationRequest(
            instrument=instr, selector_string="", external_attenuation=external_attenuation
        )
    )
    client.CfgRFAttenuation(
        nirfmxnr_types.CfgRFAttenuationRequest(
            instrument=instr,
            channel_name="",
            rf_attenuation_auto=rf_attenuation_auto,
            rf_attenuation_value=rf_attenuation,
        )
    )
    client.CfgIQPowerEdgeTrigger(
        nirfmxnr_types.CfgIQPowerEdgeTriggerRequest(
            instrument=instr,
            selector_string="",
            iq_power_edge_source="0",
            iq_power_edge_slope=nirfmxnr_types.IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE,
            iq_power_edge_level=iq_power_edge_level,
            trigger_delay=trigger_delay,
            trigger_min_quiet_time_mode=minimum_quiet_time_mode,
            trigger_min_quiet_time_duration=minimum_quiet_time,
            iq_power_edge_level_type=nirfmxnr_types.IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE,
            enable_trigger=iq_power_edge_enabled,
        )
    )
    client.SetAttributeI32(
        nirfmxnr_types.SetAttributeI32Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_LINK_DIRECTION,
            attr_val_raw=link_direction,
        )
    )
    client.SetAttributeI32(
        nirfmxnr_types.SetAttributeI32Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE,
            attr_val_raw=frequency_range,
        )
    )
    client.SetAttributeF64(
        nirfmxnr_types.SetAttributeF64Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH,
            attr_val=carrier_bandwidth,
        )
    )
    client.SetAttributeF64(
        nirfmxnr_types.SetAttributeF64Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING,
            attr_val=subcarrier_spacing,
        )
    )
    if auto_level:
        auto_level_response = client.AutoLevel(
            nirfmxnr_types.AutoLevelRequest(
                instrument=instr, selector_string="", measurement_interval=measurement_interval
            )
        )
        reference_level = auto_level_response.reference_level
        print(f"Reference level (dBm)        : {reference_level}\n")
    else:
        client.CfgReferenceLevel(
            nirfmxnr_types.CfgReferenceLevelRequest(
                instrument=instr, selector_string="", reference_level=reference_level
            )
        )
    client.SelectMeasurements(
        nirfmxnr_types.SelectMeasurementsRequest(
            instrument=instr,
            selector_string="",
            measurements=nirfmxnr_types.MEASUREMENT_TYPES_ACP,
            enable_all_traces=True,
        )
    )
    client.ACPCfgMeasurementMethod(
        nirfmxnr_types.ACPCfgMeasurementMethodRequest(
            instrument=instr, selector_string="", measurement_method=measurement_method
        )
    )
    client.ACPCfgNoiseCompensationEnabled(
        nirfmxnr_types.ACPCfgNoiseCompensationEnabledRequest(
            instrument=instr,
            selector_string="",
            noise_compensation_enabled=noise_compensation_enabled,
        )
    )
    client.ACPCfgSweepTime(
        nirfmxnr_types.ACPCfgSweepTimeRequest(
            instrument=instr,
            selector_string="",
            sweep_time_auto=sweep_time_auto,
            sweep_time_interval=sweep_time_interval,
        )
    )
    client.ACPCfgAveraging(
        nirfmxnr_types.ACPCfgAveragingRequest(
            instrument=instr,
            selector_string="",
            averaging_enabled=averaging_enabled,
            averaging_count=averaging_count,
            averaging_type=averaging_type,
        )
    )
    client.Initiate(
        nirfmxnr_types.InitiateRequest(instrument=instr, selector_string="", result_name="")
    )

    # Fetch results
    acp_fetch_offset_measurement_array_response = client.ACPFetchOffsetMeasurementArray(
        nirfmxnr_types.ACPFetchOffsetMeasurementArrayRequest(
            instrument=instr, selector_string="", timeout=timeout
        )
    )
    array_size = len(acp_fetch_offset_measurement_array_response.lower_relative_power)
    lower_relative_power = acp_fetch_offset_measurement_array_response.lower_relative_power
    upper_relative_power = acp_fetch_offset_measurement_array_response.upper_relative_power
    lower_absolute_power = acp_fetch_offset_measurement_array_response.lower_absolute_power
    upper_absolute_power = acp_fetch_offset_measurement_array_response.upper_absolute_power

    acp_fetch_component_carrier_measurement_response = client.ACPFetchComponentCarrierMeasurement(
        nirfmxnr_types.ACPFetchComponentCarrierMeasurementRequest(
            instrument=instr, selector_string="", timeout=timeout
        )
    )
    absolute_power = acp_fetch_component_carrier_measurement_response.absolute_power
    relative_power = acp_fetch_component_carrier_measurement_response.relative_power

    for i in range(array_size):
        acp_fetch_relative_powers_trace_response = client.ACPFetchRelativePowersTrace(
            nirfmxnr_types.ACPFetchRelativePowersTraceRequest(
                instrument=instr, selector_string="", timeout=timeout, trace_index=i
            )
        )
        x0 = acp_fetch_relative_powers_trace_response.x0
        dx = acp_fetch_relative_powers_trace_response.dx
        relative_powers_trace = acp_fetch_relative_powers_trace_response.relative_powers_trace

    acp_fetch_spectrum_response = client.ACPFetchSpectrum(
        nirfmxnr_types.ACPFetchSpectrumRequest(
            instrument=instr, selector_string="", timeout=timeout
        )
    )
    x0 = acp_fetch_spectrum_response.x0
    dx = acp_fetch_spectrum_response.dx
    spectrum = acp_fetch_spectrum_response.spectrum

    print(f"\nCarrier Absolute Power (dBm or dBm/Hz) : {absolute_power}\n")

    print("\n-----------Offset Channel Measurements----------- \n\n")
    for i in range(array_size):
        print(f"Offset  {i}\n")
        print(f"Lower Relative Power (dB)              : {lower_relative_power[i]}\n")
        print(f"Upper Relative Power (dB)              : {upper_relative_power[i]}\n")
        print(f"Lower Absolute Power (dBm or dBm/Hz)   : {lower_absolute_power[i]}\n")
        print(f"Upper Absolute Power (dBm or dBm/Hz)   : {upper_absolute_power[i]}\n")
        print("-------------------------------------------------\n\n")
finally:
    if instr:
        client.Close(nirfmxnr_types.CloseRequest(instrument=instr, force_destroy=False))
