# Steps:
# 1. Open a new RFmx Session.
# 2. Configure Frequency Reference.
# 3. Configure basic signal properties(Center Frequency, Reference Level and External Attenuation).
# 4. Configure Trigger Type and Trigger Parameters.
# 5. Configure Packet Type.
# 6. Configure Data Rate.
# 7. Configure Payload Length.
# 8. Select ACP measurement and enable Traces.
# 9. Configure ACP Burst Sync Type.
# 10. Configure Averaging Parameters for ACP measurement.
# 11. Configure Number of Offsets or Channel Number depending on Offset Channel Mode.
# 12. Initiate the Measurement.
# 13. Fetch ACP Measurements and Trace.
# 14. Close RFmx Session.
#
# The gRPC API is built from the C API. RFmx BT documentation is installed with the driver at:
# C:\Program Files (x86)\National Instruments\RFmx\BT\Documentation\btcvi.chm
#
# Getting Started:
#
# To run this example, install "RFmx BT" on the server machine.
# Link: https://www.ni.com/en-us/support/downloads/software-products/download.rfmx-bt.html
#
# For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC Client" wiki page.
# Link: https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client
#
# Refer to the NI-RFmxBT gRPC Wiki for the latest C Function Reference:
# Link: https://github.com/ni/grpc-device/wiki/NI-RFmxBT-C-Function-Reference
#
# Running from command line:
#
# Server machine's IP address, port number, and physical channel name can be passed as separate command line arguments.
#   > python acp-basic.py <server_address> <port_number> <physical_channel_name>
# If they are not passed in as command line arguments, then by default the server address will be "localhost:31763", with "SimulatedDevice" as the resource name


import sys

import grpc
import nirfmxbt_pb2 as nirfmxbt_types
import nirfmxbt_pb2_grpc as grpc_nirfmxbt

server_address = "localhost"
server_port = "31763"
session_name = "RFmxBTSession"

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
client = grpc_nirfmxbt.NiRFmxBTStub(channel)
instr = None


# Raise an exception if an error was returned
def raise_if_error(response):
    if response.status != 0:
        error_response = client.GetError(
            nirfmxbt_types.GetErrorRequest(
                instrument=instr,
            )
        )
        if response.status < 0:
            raise RuntimeError(f"Error: {error_response.error_description or response.status}")
        else:
            sys.stderr.write(f"Warning: {error_response.error_description or response.status}\n")

    return response


try:
    offset_channel_mode = nirfmxbt_types.ACP_OFFSET_CHANNEL_MODE_SYMMETRIC

    initialize_response = raise_if_error(
        client.Initialize(
            nirfmxbt_types.InitializeRequest(
                session_name=session_name, resource_name=resource, option_string=options
            )
        )
    )
    instr = initialize_response.instrument
    raise_if_error(
        client.CfgFrequencyReference(
            nirfmxbt_types.CfgFrequencyReferenceRequest(
                instrument=instr,
                channel_name="",
                frequency_reference_source_mapped=nirfmxbt_types.FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK,
                frequency_reference_frequency=10e6,
            )
        )
    )
    raise_if_error(
        client.CfgRF(
            nirfmxbt_types.CfgRFRequest(
                instrument=instr,
                selector_string="",
                center_frequency=2.402e9,
                reference_level=0.0,
                external_attenuation=0.0,
            )
        )
    )
    raise_if_error(
        client.CfgIQPowerEdgeTrigger(
            nirfmxbt_types.CfgIQPowerEdgeTriggerRequest(
                instrument=instr,
                selector_string="",
                iq_power_edge_source="0",
                iq_power_edge_slope=nirfmxbt_types.IQ_POWER_EDGE_TRIGGER_SLOPE_RISING_SLOPE,
                iq_power_edge_level=-20.0,
                trigger_delay=0.0,
                trigger_min_quiet_time_mode=nirfmxbt_types.TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO,
                trigger_min_quiet_time_duration=100e-6,
                iq_power_edge_level_type=nirfmxbt_types.IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE,
                enable_trigger=True,
            )
        )
    )
    raise_if_error(
        client.CfgPacketType(
            nirfmxbt_types.CfgPacketTypeRequest(
                instrument=instr, selector_string="", packet_type=nirfmxbt_types.PACKET_TYPE_DH1
            )
        )
    )
    raise_if_error(
        client.CfgDataRate(
            nirfmxbt_types.CfgDataRateRequest(
                instrument=instr, selector_string="", data_rate=1000000
            )
        )
    )
    raise_if_error(
        client.CfgPayloadLength(
            nirfmxbt_types.CfgPayloadLengthRequest(
                instrument=instr,
                selector_string="",
                payload_length_mode=nirfmxbt_types.PAYLOAD_LENGTH_MODE_AUTO,
                payload_length=10,
            )
        )
    )
    raise_if_error(
        client.SelectMeasurements(
            nirfmxbt_types.SelectMeasurementsRequest(
                instrument=instr,
                selector_string="",
                measurements=nirfmxbt_types.MEASUREMENT_TYPES_ACP,
                enable_all_traces=True,
            )
        )
    )
    raise_if_error(
        client.ACPCfgBurstSynchronizationType(
            nirfmxbt_types.ACPCfgBurstSynchronizationTypeRequest(
                instrument=instr,
                selector_string="",
                burst_synchronization_type=nirfmxbt_types.ACP_BURST_SYNCHRONIZATION_TYPE_PREAMBLE,
            )
        )
    )
    raise_if_error(
        client.ACPCfgAveraging(
            nirfmxbt_types.ACPCfgAveragingRequest(
                instrument=instr,
                selector_string="",
                averaging_enabled=nirfmxbt_types.ACP_AVERAGING_ENABLED_FALSE,
                averaging_count=10,
            )
        )
    )
    raise_if_error(
        client.ACPCfgOffsetChannelMode(
            nirfmxbt_types.ACPCfgOffsetChannelModeRequest(
                instrument=instr,
                selector_string="",
                offset_channel_mode=offset_channel_mode,
            )
        )
    )
    if offset_channel_mode == nirfmxbt_types.ACP_OFFSET_CHANNEL_MODE_SYMMETRIC:
        raise_if_error(
            client.ACPCfgNumberOfOffsets(
                nirfmxbt_types.ACPCfgNumberOfOffsetsRequest(
                    instrument=instr, selector_string="", number_of_offsets=5
                )
            )
        )
    elif offset_channel_mode == nirfmxbt_types.ACP_OFFSET_CHANNEL_MODE_INBAND:
        raise_if_error(
            client.CfgChannelNumber(
                nirfmxbt_types.CfgChannelNumberRequest(
                    instrument=instr, selector_string="", channel_number=0
                )
            )
        )
    raise_if_error(
        client.Initiate(
            nirfmxbt_types.InitiateRequest(instrument=instr, selector_string="", result_name="")
        )
    )

    ### Fetch Results ###

    acp_fetch_measurement_status_response = raise_if_error(
        client.ACPFetchMeasurementStatus(
            nirfmxbt_types.ACPFetchMeasurementStatusRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    measurement_status = acp_fetch_measurement_status_response.measurement_status
    if (
        measurement_status
        == nirfmxbt_types.NIRFMXBT_INT32_ACP_RESULTS_MEASUREMENT_STATUS_NOT_APPLICABLE
    ):
        measurement_status_string = "Not Applicable"
    elif measurement_status == nirfmxbt_types.NIRFMXBT_INT32_ACP_RESULTS_MEASUREMENT_STATUS_PASS:
        measurement_status_string = "Pass"
    else:
        measurement_status_string = "Fail"

    acp_fetch_reference_channel_power_response = raise_if_error(
        client.ACPFetchReferenceChannelPower(
            nirfmxbt_types.ACPFetchReferenceChannelPowerRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    reference_channel_power = acp_fetch_reference_channel_power_response.reference_channel_power

    acp_fetch_offset_measurement_array_response = raise_if_error(
        client.ACPFetchOffsetMeasurementArray(
            nirfmxbt_types.ACPFetchOffsetMeasurementArrayRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    lower_absolute_power = acp_fetch_offset_measurement_array_response.lower_absolute_power
    upper_absolute_power = acp_fetch_offset_measurement_array_response.upper_absolute_power
    lower_relative_power = acp_fetch_offset_measurement_array_response.lower_relative_power
    upper_relative_power = acp_fetch_offset_measurement_array_response.upper_relative_power
    lower_margin = acp_fetch_offset_measurement_array_response.lower_margin
    upper_margin = acp_fetch_offset_measurement_array_response.upper_margin

    acp_fetch_mask_trace_response = raise_if_error(
        client.ACPFetchMaskTrace(
            nirfmxbt_types.ACPFetchMaskTraceRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    x0 = acp_fetch_mask_trace_response.x0
    dx = acp_fetch_mask_trace_response.dx
    limit_with_exception_mask = acp_fetch_mask_trace_response.limit_with_exception_mask
    limit_without_exception_mask = acp_fetch_mask_trace_response.limit_without_exception_mask

    x0 = 0.0
    dx = 0.0
    acp_fetch_absolute_power_trace_response = raise_if_error(
        client.ACPFetchAbsolutePowerTrace(
            nirfmxbt_types.ACPFetchAbsolutePowerTraceRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    x0 = acp_fetch_absolute_power_trace_response.x0
    dx = acp_fetch_absolute_power_trace_response.dx
    absolute_power = acp_fetch_absolute_power_trace_response.absolute_power

    x0 = 0.0
    dx = 0.0
    acp_fetch_spectrum_response = raise_if_error(
        client.ACPFetchSpectrum(
            nirfmxbt_types.ACPFetchSpectrumRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    x0 = acp_fetch_spectrum_response.x0
    dx = acp_fetch_spectrum_response.dx
    spectrum = acp_fetch_spectrum_response.spectrum

    print("------------------ACP------------------")
    print(f"Measurement Status                   : {measurement_status_string}")
    print(f"Reference Channel Power (dBm)        : {reference_channel_power}\n")
    print("------------------Offset Measuremensts------------------")
    if len(lower_absolute_power) == 0:
        print("No data")
    for i in range(len(lower_absolute_power)):
        print(f"Offset {i}")
        print(f"Lower Absolute Powers (dBm)          : {lower_absolute_power[i]}")
        print(f"Upper Absolute Powers (dBm)          : {upper_absolute_power[i]}")
        print(f"Lower Relative Powers (dB)           : {lower_relative_power[i]}")
        print(f"Upper Relative Powers (dB)           : {upper_relative_power[i]}")
        print(f"Lower Margin (dB)                    : {lower_margin[i]}")
        print(f"Upper Margin (dB)                    : {upper_margin[i]}\n")
finally:
    if instr:
        client.Close(nirfmxbt_types.CloseRequest(instrument=instr, force_destroy=False))
