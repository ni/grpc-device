r"""Acp example.

Steps:
1. Open a new RFmx session.
2. Configure Frequency Reference.
3. Configure External Attenuation.
4. Configure the Center Frequency directly or via Channel Number.
5. Configure Trigger Type and Trigger Parameters.
6. Configure the Reference Level directly or via Auto Level.
7. Select ACP measurement and enable traces.
8. Configure Averaging parameters.
9. Configure Sweep Time parameters.
10. Configure Noise Compensation parameter.
11. Configure Number of Offset Channels.
12. Initiate the Measurement.
13[A-E]. Fetch ACP Measurements and Traces.
14. Close the RFmx session.

The gRPC API is built from the C API. RFmx TDSCDMA documentation is installed with the driver at:
C:\Program Files (x86)\National Instruments\RFmx\TDSCDMA\Documentation\tdscdmacvi.chm

Getting Started:

To run this example, install "RFmx TDSCDMA" on the server machine.
Link: https://www.ni.com/en-us/support/downloads/software-products/download.rfmx-tdscdma.html

For instructions on how to use protoc to generate gRPC client interfaces,
see our "Creating a gRPC Client" wiki page.
Link: https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-RFmxTDSCDMA gRPC Wiki for the latest C Function Reference:
Link: https://github.com/ni/grpc-device/wiki/NI-RFmxTDSCDMA-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and physical channel name can be passed as separate
command line arguments.
  > python acp.py <server_address> <port_number> <physical_channel_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedDevice" as the resource name
"""


import sys

import grpc
import nirfmxtdscdma_pb2 as nirfmxtdscdma_types
import nirfmxtdscdma_pb2_grpc as grpc_nirfmxtdscdma

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "RFmxTDSCDMASession"

# Resource name and options for a simulated 5663 client.
RESOURCE = "SimulatedDevice"
OPTIONS = "Simulate=1,DriverSetup=Model:5663"

# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]
if len(sys.argv) >= 4:
    RESOURCE = sys.argv[3]
    OPTIONS = ""

# Create a gRPC channel + client.
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
client = grpc_nirfmxtdscdma.NiRFmxTDSCDMAStub(channel)
instr = None


NUMBER_OF_OFFSETS = 2


def check_for_warning(response, instrument):
    """Print to console if the status indicates a warning."""
    if response.status > 0:
        warning_message = client.GetErrorString(
            nirfmxtdscdma_types.GetErrorStringRequest(
                instrument=instrument,
                error_code=response.status,
            )
        )
        sys.stderr.write(
            f"{warning_message.error_description}\nWarning status: {response.status}\n"
        )


try:
    # Initialize a session
    initialize_response = client.Initialize(
        nirfmxtdscdma_types.InitializeRequest(
            session_name=SESSION_NAME, resource_name=RESOURCE, option_string=OPTIONS
        )
    )
    instr = initialize_response.instrument
    client.CfgFrequencyReference(
        nirfmxtdscdma_types.CfgFrequencyReferenceRequest(
            instrument=instr,
            channel_name="",
            frequency_reference_source_mapped=nirfmxtdscdma_types.FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK,
            frequency_reference_frequency=10e6,
        )
    )
    client.CfgExternalAttenuation(
        nirfmxtdscdma_types.CfgExternalAttenuationRequest(
            instrument=instr, selector_string="", external_attenuation=0.00
        )
    )
    client.CfgFrequency(
        nirfmxtdscdma_types.CfgFrequencyRequest(
            instrument=instr, selector_string="", center_frequency=1.91e9
        )
    )
    client.CfgIQPowerEdgeTrigger(
        nirfmxtdscdma_types.CfgIQPowerEdgeTriggerRequest(
            instrument=instr,
            selector_string="",
            iq_power_edge_source="0",
            iq_power_edge_slope=nirfmxtdscdma_types.IQ_POWER_EDGE_TRIGGER_SLOPE_RISING,
            iq_power_edge_level=-20.00,
            trigger_delay=0.00,
            minimum_quiet_time_mode=nirfmxtdscdma_types.TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO,
            minimum_quiet_time=16e-6,
            iq_power_edge_level_type=nirfmxtdscdma_types.IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE,
            enable_trigger=True,
        )
    )
    auto_level = False
    if auto_level:
        auto_level_response = client.AutoLevel(
            nirfmxtdscdma_types.AutoLevelRequest(
                instrument=instr, selector_string="", measurement_interval=0.005
            )
        )
        reference_level = auto_level_response.reference_level
        print(f"Reference Level (dBm)        : {reference_level}")
    else:
        client.CfgReferenceLevel(
            nirfmxtdscdma_types.CfgReferenceLevelRequest(
                instrument=instr, selector_string="", reference_level=0.00
            )
        )
    client.SelectMeasurements(
        nirfmxtdscdma_types.SelectMeasurementsRequest(
            instrument=instr,
            selector_string="",
            measurements_raw=nirfmxtdscdma_types.MEASUREMENT_TYPES_ACP,
            enable_all_traces=True,
        )
    )
    client.ACPCfgAveraging(
        nirfmxtdscdma_types.ACPCfgAveragingRequest(
            instrument=instr,
            selector_string="",
            averaging_enabled=nirfmxtdscdma_types.ACP_AVERAGING_ENABLED_FALSE,
            averaging_count=10,
            averaging_type=nirfmxtdscdma_types.ACP_AVERAGING_TYPE_RMS,
        )
    )
    client.ACPCfgSweepTime(
        nirfmxtdscdma_types.ACPCfgSweepTimeRequest(
            instrument=instr,
            selector_string="",
            sweep_time_auto=nirfmxtdscdma_types.ACP_SWEEP_TIME_AUTO_TRUE,
            sweep_time_interval=0.000660,
        )
    )
    client.ACPCfgNoiseCompensationEnabled(
        nirfmxtdscdma_types.ACPCfgNoiseCompensationEnabledRequest(
            instrument=instr,
            selector_string="",
            noise_compensation_enabled=nirfmxtdscdma_types.ACP_NOISE_COMPENSATION_ENABLED_FALSE,
        )
    )
    client.ACPCfgNumberOfOffsets(
        nirfmxtdscdma_types.ACPCfgNumberOfOffsetsRequest(
            instrument=instr, selector_string="", number_of_offsets=NUMBER_OF_OFFSETS
        )
    )
    client.Initiate(
        nirfmxtdscdma_types.InitiateRequest(instrument=instr, selector_string="", result_name="")
    )

    # Fetch the measurements array
    acp_fetch_offset_measurement_array_response = client.ACPFetchOffsetMeasurementArray(
        nirfmxtdscdma_types.ACPFetchOffsetMeasurementArrayRequest(
            instrument=instr, selector_string="", timeout=10.00
        )
    )
    lower_relative_power = acp_fetch_offset_measurement_array_response.lower_relative_power
    upper_relative_power = acp_fetch_offset_measurement_array_response.upper_relative_power
    lower_absolute_power = acp_fetch_offset_measurement_array_response.lower_absolute_power
    upper_absolute_power = acp_fetch_offset_measurement_array_response.upper_absolute_power

    acp_fetch_carrier_absolute_power_response = client.ACPFetchCarrierAbsolutePower(
        nirfmxtdscdma_types.ACPFetchCarrierAbsolutePowerRequest(
            instrument=instr, selector_string="", timeout=10.00
        )
    )
    carrier_absolute_power = acp_fetch_carrier_absolute_power_response.carrier_absolute_power
    acp_fetch_spectrum_response = client.ACPFetchSpectrum(
        nirfmxtdscdma_types.ACPFetchSpectrumRequest(
            instrument=instr, selector_string="", timeout=10.00
        )
    )
    x0 = acp_fetch_spectrum_response.x0
    dx = acp_fetch_spectrum_response.dx
    spectrum = acp_fetch_spectrum_response.spectrum

    print(f"Carrier Absolute Power (dBm) : {carrier_absolute_power}")
    for i in range(NUMBER_OF_OFFSETS):
        print(f"\nOffset                       :  {i}")
        print(f"Lower Relative Power (dB)    : {lower_relative_power[i]}")
        print(f"Upper Relative Power (dB)    : {upper_relative_power[i]}")
        print(f"Lower Absolute Power (dBm)   : {lower_absolute_power[i]}")
        print(f"Upper Absolute Power (dBm)   : {upper_absolute_power[i]}")
        print("-------------------------------------------------")
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    for entry in rpc_error.trailing_metadata() or []:
        if entry.key == "ni-error":
            value = entry.value if isinstance(entry.value, str) else entry.value.decode("utf-8")
            error_message += f"\nError status: {value}"
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE:
        error_message = f"Failed to connect to server on {SERVER_ADDRESS}:{SERVER_PORT}"
    elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
        error_message = (
            "The operation is not implemented or is not supported/enabled in this service"
        )
    sys.stderr.write(f"{error_message}\n")
finally:
    if instr:
        client.Close(nirfmxtdscdma_types.CloseRequest(instrument=instr, force_destroy=False))
