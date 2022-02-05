# Steps:
# 1. Open a new RFmx session
# 2. Configure Selected Ports
# 3. Configure Frequency Reference
# 4. Configure the basic signal properties  (Center Frequency, Reference Level and External Attenuation)
# 5. Configure RF Attenuation
# 6. Select ACP measurement and enable the traces
# 7. Configure ACP Measurement Method, Power Units and Averaging Parameters
# 8. Configure ACP rbw filter
# 9. Configure ACP Sweep Time
# 10. Configure ACP Noise Compensation
# 11. Configure ACP Carrier Channel Settings (Integration BW, RRC Filter)
# 12. Configure ACP Number of Offset Channels
# 13. Configure ACP Offset Channel Settings (Offset Frequencies, Integration BW, RRC Filter)
# Use "offset:all" selector string to set a parameter for all the Offset Channels
# 14. Initiate Measurement
# 15. Fetch ACP Measurements and Traces
# 16. Close the RFmx Session

import sys
from typing import Iterable

import grpc
import nirfmxspecan_pb2 as nirfmxspecan_types
import nirfmxspecan_pb2_grpc as grpc_nirfmxspecan

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
client = grpc_nirfmxspecan.NiRFmxSpecAnStub(channel)
instr = None

# Maximum size of an error message
MAX_ERROR_DESCRIPTION = 4096

NUMBER_OF_OFFSETS = 2
AUTO_LEVEL_OFF = 0
AUTO_LEVEL_ON = 1


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
    center_frequency = 1e9  # Hz
    reference_level = 0.00  # dBm
    external_attenuation = 0.00  # dB
    integration_bandwidth = 1e6
    measurement_interval = 10e-3
    auto_level = AUTO_LEVEL_ON

    frequency_source = nirfmxspecan_types.FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK
    frequency = 10.0e6  # Hz

    power_units = nirfmxspecan_types.ACP_POWER_UNITS_DBM
    noise_compensation_enabled = nirfmxspecan_types.ACP_NOISE_COMPENSATION_ENABLED_FALSE

    # Sweep Time
    sweep_time_auto = nirfmxspecan_types.ACP_SWEEP_TIME_AUTO_TRUE
    sweep_time_interval = 1.00e-3  # seconds

    # rbw Filter
    rbw_filter_type = nirfmxspecan_types.ACP_RBW_FILTER_TYPE_GAUSSIAN
    rbw_auto = nirfmxspecan_types.ACP_RBW_AUTO_BANDWIDTH_TRUE
    rbw = 10.0e3  # Hz

    # Averaging
    averaging_enabled = nirfmxspecan_types.ACP_AVERAGING_ENABLED_FALSE
    averaging_count = 10
    averaging_type = nirfmxspecan_types.ACP_AVERAGING_TYPE_RMS

    timeout = 10.0  # seconds

    # Variables to store the results

    lower_relative_power = []  # type: Iterable[float]
    upper_relative_power = []  # type: Iterable[float]
    lower_absolute_power = []  # type: Iterable[float]
    upper_absolute_power = []  # type: Iterable[float]
    x0 = 0.0
    dx = 0.0
    spectrum = None

    # Carrier Channels
    carrier_integration_bandwidth = 1.0e6  # Hz
    carrier_rrc_filter_enabled = nirfmxspecan_types.ACP_OFFSET_RRC_FILTER_ENABLED_FALSE
    carrier_rrc_filter_alpha = 0.220

    # Offset Channels
    offset_integration_bandwidth = 1.0e6  # Hz
    offset_rrc_filter_enabled = nirfmxspecan_types.ACP_OFFSET_RRC_FILTER_ENABLED_FALSE
    offset_rrc_filter_alpha = 0.220

    offset_frequency_offset = [1.0e6, 2.0e6]  # Hz

    # Create new RFmx session

    initialize_response = client.Initialize(
        nirfmxspecan_types.InitializeRequest(
            session_name=session_name, resource_name=resource, option_string=""
        )
    )
    instr = initialize_response.instrument

    # Configure ACP measurements
    client.CfgFrequencyReference(
        nirfmxspecan_types.CfgFrequencyReferenceRequest(
            instrument=instr,
            channel_name="",
            frequency_reference_source_mapped=frequency_source,
            frequency_reference_frequency=frequency,
        )
    )
    client.SetAttributeString(
        nirfmxspecan_types.SetAttributeStringRequest(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxspecan_types.NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS,
            attr_val_raw=selected_ports,
        )
    )
    client.CfgFrequency(
        nirfmxspecan_types.CfgFrequencyRequest(
            instrument=instr, selector_string="", center_frequency=center_frequency
        )
    )
    client.CfgExternalAttenuation(
        nirfmxspecan_types.CfgExternalAttenuationRequest(
            instrument=instr, selector_string="", external_attenuation=external_attenuation
        )
    )

    if auto_level:
        auto_level_response = client.AutoLevel(
            nirfmxspecan_types.AutoLevelRequest(
                instrument=instr,
                selector_string="",
                bandwidth=integration_bandwidth,
                measurement_interval=measurement_interval,
            )
        )
        auto_set_reference_level = auto_level_response.reference_level
        print(f"Reference level                         : {auto_set_reference_level}\n")
    else:
        client.CfgReferenceLevel(
            nirfmxspecan_types.CfgReferenceLevelRequest(
                instrument=instr, selector_string="", reference_level=reference_level
            )
        )
    client.SelectMeasurements(
        nirfmxspecan_types.SelectMeasurementsRequest(
            instrument=instr,
            selector_string="",
            measurements=nirfmxspecan_types.MEASUREMENT_TYPES_ACP,
            enable_all_traces=True,
        )
    )
    client.ACPCfgPowerUnits(
        nirfmxspecan_types.ACPCfgPowerUnitsRequest(
            instrument=instr, selector_string="", power_units=power_units
        )
    )
    client.ACPCfgAveraging(
        nirfmxspecan_types.ACPCfgAveragingRequest(
            instrument=instr,
            selector_string="",
            averaging_enabled=averaging_enabled,
            averaging_count=averaging_count,
            averaging_type=averaging_type,
        )
    )
    client.ACPCfgRBWFilter(
        nirfmxspecan_types.ACPCfgRBWFilterRequest(
            instrument=instr,
            selector_string="",
            rbw_auto=rbw_auto,
            rbw=rbw,
            rbw_filter_type=rbw_filter_type,
        )
    )
    client.ACPCfgSweepTime(
        nirfmxspecan_types.ACPCfgSweepTimeRequest(
            instrument=instr,
            selector_string="",
            sweep_time_auto=sweep_time_auto,
            sweep_time_interval=sweep_time_interval,
        )
    )
    client.ACPCfgNoiseCompensationEnabled(
        nirfmxspecan_types.ACPCfgNoiseCompensationEnabledRequest(
            instrument=instr,
            selector_string="",
            noise_compensation_enabled=noise_compensation_enabled,
        )
    )
    client.ACPCfgCarrierIntegrationBandwidth(
        nirfmxspecan_types.ACPCfgCarrierIntegrationBandwidthRequest(
            instrument=instr,
            selector_string="",
            integration_bandwidth=carrier_integration_bandwidth,
        )
    )
    client.ACPCfgCarrierRRCFilter(
        nirfmxspecan_types.ACPCfgCarrierRRCFilterRequest(
            instrument=instr,
            selector_string="",
            rrc_filter_enabled=carrier_rrc_filter_enabled,
            rrc_alpha=carrier_rrc_filter_alpha,
        )
    )
    client.ACPCfgNumberOfOffsets(
        nirfmxspecan_types.ACPCfgNumberOfOffsetsRequest(
            instrument=instr, selector_string="", number_of_offsets=NUMBER_OF_OFFSETS
        )
    )
    client.ACPCfgOffsetArray(
        nirfmxspecan_types.ACPCfgOffsetArrayRequest(
            instrument=instr,
            selector_string="",
            offset_frequency=offset_frequency_offset,
            offset_sideband=None,
            offset_enabled=None,
        )
    )
    client.ACPCfgOffsetIntegrationBandwidth(
        nirfmxspecan_types.ACPCfgOffsetIntegrationBandwidthRequest(
            instrument=instr,
            selector_string="offset::all",
            integration_bandwidth=offset_integration_bandwidth,
        )
    )
    client.ACPCfgOffsetRRCFilter(
        nirfmxspecan_types.ACPCfgOffsetRRCFilterRequest(
            instrument=instr,
            selector_string="offset::all",
            rrc_filter_enabled=offset_rrc_filter_enabled,
            rrc_alpha=offset_rrc_filter_alpha,
        )
    )
    client.Initiate(
        nirfmxspecan_types.InitiateRequest(instrument=instr, selector_string="", result_name="")
    )

    # Retrieve results

    # Fetch the measurements array
    acp_fetch_offset_measurement_array_response = client.ACPFetchOffsetMeasurementArray(
        nirfmxspecan_types.ACPFetchOffsetMeasurementArrayRequest(
            instrument=instr, selector_string="", timeout=timeout
        )
    )
    lower_relative_power = acp_fetch_offset_measurement_array_response.lower_relative_power
    upper_relative_power = acp_fetch_offset_measurement_array_response.upper_relative_power
    lower_absolute_power = acp_fetch_offset_measurement_array_response.lower_absolute_power
    upper_absolute_power = acp_fetch_offset_measurement_array_response.upper_absolute_power

    acp_fetch_carrier_measurement_response = client.ACPFetchCarrierMeasurement(
        nirfmxspecan_types.ACPFetchCarrierMeasurementRequest(
            instrument=instr, selector_string="", timeout=timeout
        )
    )
    absolute_power = acp_fetch_carrier_measurement_response.absolute_power
    NULL = acp_fetch_carrier_measurement_response.total_relative_power
    NULL = acp_fetch_carrier_measurement_response.carrier_offset
    NULL = acp_fetch_carrier_measurement_response.integration_bandwidth
    x0 = 0.0
    dx = 0.0
    acp_fetch_spectrum_response = client.ACPFetchSpectrum(
        nirfmxspecan_types.ACPFetchSpectrumRequest(
            instrument=instr, selector_string="", timeout=timeout
        )
    )
    x0 = acp_fetch_spectrum_response.x0
    dx = acp_fetch_spectrum_response.dx
    spectrum = acp_fetch_spectrum_response.spectrum

    print("Carrier Measurements: \n")
    print(f"Absolute Power (dBm or dBm/Hz)          : {absolute_power}\n")
    print("---------------------------------------------------\n")

    print("Offset Channel Measurements: \n")
    for i in range(NUMBER_OF_OFFSETS):
        print(f"Offset  :  {i}\n")
        print(f"Lower Relative Power (dB)               : {lower_relative_power[i]}\n")
        print(f"Upper Relative Power (dB)               : {upper_relative_power[i]}\n")
        print(f"Lower Absolute Power (dBm or dBm/Hz)    : {lower_absolute_power[i]}\n")
        print(f"Upper Absolute Power (dBm or dBm/Hz)    : {upper_absolute_power[i]}\n")
        print("-------------------------------------------------\n")
finally:
    if instr:
        client.Close(nirfmxspecan_types.CloseRequest(instrument=instr, force_destroy=False))
