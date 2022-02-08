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
#
# The gRPC API is built from the C API. RFmx SpecAn documentation is installed with the driver at:
# C:\Program Files (x86)\National Instruments\RFmx\SpecAn\Documentation\specancvi.chm
#
# Getting Started:
#
# To run this example, install "RFmx SpecAn" on the server machine.
# Link: https://www.ni.com/en-us/support/downloads/software-products/download.rfmx-specan.html
#
# For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC Client" wiki page.
# Link: https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client
#
# Refer to the NI-RFmxSpecAn gRPC Wiki for the latest C Function Reference:
# Link: https://github.com/ni/grpc-device/wiki/NI-RFmxSpecAn-C-Function-Reference
#
# Running from command line:
#
# Server machine's IP address, port number, and physical channel name can be passed as separate command line arguments.
#   > python acp-basic.py <server_address> <port_number> <physical_channel_name>
# If they are not passed in as command line arguments, then by default the server address will be "localhost:31763", with "SimulatedDevice" as the resource name


import sys

import grpc
import nirfmxspecan_pb2 as nirfmxspecan_types
import nirfmxspecan_pb2_grpc as grpc_nirfmxspecan

server_address = "localhost"
server_port = "31763"
session_name = "RFmxSpecAnSession"

# Resource name and options for a simulated 5663 client.
resource = "SimulatedDevice"
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


NUMBER_OF_OFFSETS = 2

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
    auto_level = True

    # Variables to store the results
    x0 = 0.0
    dx = 0.0
    spectrum = None

    initialize_response = raise_if_error(
        client.Initialize(
            nirfmxspecan_types.InitializeRequest(
                session_name=session_name, resource_name=resource, option_string=""
            )
        )
    )
    instr = initialize_response.instrument

    raise_if_error(
        client.CfgFrequencyReference(
            nirfmxspecan_types.CfgFrequencyReferenceRequest(
                instrument=None,
                channel_name="",
                frequency_reference_source_mapped=nirfmxspecan_types.FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK,
                frequency_reference_frequency=10.0e6,
            )
        )
    )
    raise_if_error(
        client.SetAttributeString(
            nirfmxspecan_types.SetAttributeStringRequest(
                instrument=instr,
                selector_string="",
                attribute_id=nirfmxspecan_types.NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS,
                attr_val_raw="",
            )
        )
    )
    raise_if_error(
        client.CfgFrequency(
            nirfmxspecan_types.CfgFrequencyRequest(
                instrument=None, selector_string="", center_frequency=1e9
            )
        )
    )
    raise_if_error(
        client.CfgExternalAttenuation(
            nirfmxspecan_types.CfgExternalAttenuationRequest(
                instrument=None, selector_string="", external_attenuation=0.00
            )
        )
    )

    if auto_level:
        auto_level_response = raise_if_error(
            client.AutoLevel(
                nirfmxspecan_types.AutoLevelRequest(
                    instrument=None, selector_string="", bandwidth=1e6, measurement_interval=10e-3
                )
            )
        )
        auto_set_reference_level = auto_level_response.reference_level
        print(f"Reference level                         : {auto_set_reference_level}")
    else:
        raise_if_error(
            client.CfgReferenceLevel(
                nirfmxspecan_types.CfgReferenceLevelRequest(
                    instrument=None, selector_string="", reference_level=0.00
                )
            )
        )
    raise_if_error(
        client.SelectMeasurements(
            nirfmxspecan_types.SelectMeasurementsRequest(
                instrument=None,
                selector_string="",
                measurements=nirfmxspecan_types.MEASUREMENT_TYPES_ACP,
                enable_all_traces=True,
            )
        )
    )
    raise_if_error(
        client.ACPCfgPowerUnits(
            nirfmxspecan_types.ACPCfgPowerUnitsRequest(
                instrument=None,
                selector_string="",
                power_units=nirfmxspecan_types.ACP_POWER_UNITS_DBM,
            )
        )
    )
    raise_if_error(
        client.ACPCfgAveraging(
            nirfmxspecan_types.ACPCfgAveragingRequest(
                instrument=None,
                selector_string="",
                averaging_enabled=nirfmxspecan_types.ACP_AVERAGING_ENABLED_FALSE,
                averaging_count=10,
                averaging_type=nirfmxspecan_types.ACP_AVERAGING_TYPE_RMS,
            )
        )
    )
    raise_if_error(
        client.ACPCfgRBWFilter(
            nirfmxspecan_types.ACPCfgRBWFilterRequest(
                instrument=None,
                selector_string="",
                rbw_auto=nirfmxspecan_types.ACP_RBW_AUTO_BANDWIDTH_TRUE,
                rbw=10.0e3,
                rbw_filter_type=nirfmxspecan_types.ACP_RBW_FILTER_TYPE_GAUSSIAN,
            )
        )
    )
    raise_if_error(
        client.ACPCfgSweepTime(
            nirfmxspecan_types.ACPCfgSweepTimeRequest(
                instrument=None,
                selector_string="",
                sweep_time_auto=nirfmxspecan_types.ACP_SWEEP_TIME_AUTO_TRUE,
                sweep_time_interval=1.00e-3,
            )
        )
    )
    raise_if_error(
        client.ACPCfgNoiseCompensationEnabled(
            nirfmxspecan_types.ACPCfgNoiseCompensationEnabledRequest(
                instrument=None,
                selector_string="",
                noise_compensation_enabled=nirfmxspecan_types.ACP_NOISE_COMPENSATION_ENABLED_FALSE,
            )
        )
    )
    raise_if_error(
        client.ACPCfgCarrierIntegrationBandwidth(
            nirfmxspecan_types.ACPCfgCarrierIntegrationBandwidthRequest(
                instrument=None, selector_string="", integration_bandwidth=1.0e6
            )
        )
    )
    raise_if_error(
        client.ACPCfgCarrierRRCFilter(
            nirfmxspecan_types.ACPCfgCarrierRRCFilterRequest(
                instrument=None,
                selector_string="",
                rrc_filter_enabled=nirfmxspecan_types.ACP_CARRIER_RRC_FILTER_ENABLED_FALSE,
                rrc_alpha=0.220,
            )
        )
    )
    raise_if_error(
        client.ACPCfgNumberOfOffsets(
            nirfmxspecan_types.ACPCfgNumberOfOffsetsRequest(
                instrument=None, selector_string="", number_of_offsets=NUMBER_OF_OFFSETS
            )
        )
    )
    raise_if_error(
        client.ACPCfgOffsetArray(
            nirfmxspecan_types.ACPCfgOffsetArrayRequest(
                instrument=None,
                selector_string="",
                offset_frequency=[1.0e6, 2.0e6],
                offset_sideband=None,
                offset_enabled=None,
            )
        )
    )
    raise_if_error(
        client.ACPCfgOffsetIntegrationBandwidth(
            nirfmxspecan_types.ACPCfgOffsetIntegrationBandwidthRequest(
                instrument=None, selector_string="offset::all", integration_bandwidth=1.0e6
            )
        )
    )
    raise_if_error(
        client.ACPCfgOffsetRRCFilter(
            nirfmxspecan_types.ACPCfgOffsetRRCFilterRequest(
                instrument=None,
                selector_string="offset::all",
                rrc_filter_enabled=nirfmxspecan_types.ACP_OFFSET_RRC_FILTER_ENABLED_FALSE,
                rrc_alpha=0.220,
            )
        )
    )
    raise_if_error(
        client.Initiate(
            nirfmxspecan_types.InitiateRequest(instrument=None, selector_string="", result_name="")
        )
    )

    ### Retrieve results ###

    acp_fetch_offset_measurement_array_response = raise_if_error(
        client.ACPFetchOffsetMeasurementArray(
            nirfmxspecan_types.ACPFetchOffsetMeasurementArrayRequest(
                instrument=None, selector_string="", timeout=10.0
            )
        )
    )
    lower_relative_power = acp_fetch_offset_measurement_array_response.lower_relative_power
    upper_relative_power = acp_fetch_offset_measurement_array_response.upper_relative_power
    lower_absolute_power = acp_fetch_offset_measurement_array_response.lower_absolute_power
    upper_absolute_power = acp_fetch_offset_measurement_array_response.upper_absolute_power

    acp_fetch_carrier_measurement_response = raise_if_error(
        client.ACPFetchCarrierMeasurement(
            nirfmxspecan_types.ACPFetchCarrierMeasurementRequest(
                instrument=None, selector_string="", timeout=10.0
            )
        )
    )
    absolute_power = acp_fetch_carrier_measurement_response.absolute_power
    x0 = 0.0
    dx = 0.0
    acp_fetch_spectrum_response = raise_if_error(
        client.ACPFetchSpectrum(
            nirfmxspecan_types.ACPFetchSpectrumRequest(
                instrument=None, selector_string="", timeout=10.0
            )
        )
    )
    x0 = acp_fetch_spectrum_response.x0
    dx = acp_fetch_spectrum_response.dx
    spectrum = acp_fetch_spectrum_response.spectrum

    print("Carrier Measurements:")
    print(f"Absolute Power (dBm or dBm/Hz)          : {absolute_power}")
    print("---------------------------------------------------")

    print("Offset Channel Measurements: ")
    for i in range(NUMBER_OF_OFFSETS):
        print(f"Offset  :  {i}")
        print(f"Lower Relative Power (dB)               : {lower_relative_power[i]}")
        print(f"Upper Relative Power (dB)               : {upper_relative_power[i]}")
        print(f"Lower Absolute Power (dBm or dBm/Hz)    : {lower_absolute_power[i]}")
        print(f"Upper Absolute Power (dBm or dBm/Hz)    : {upper_absolute_power[i]}")
        print("-------------------------------------------------")
finally:
    if instr:
        client.Close(nirfmxspecan_types.CloseRequest(instrument=instr, force_destroy=False))
