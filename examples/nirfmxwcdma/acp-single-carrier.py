r"""Fetch ACP data.

Steps:
1. Open a new RFmx Session.
2. Configure Frequency Reference.
3. Configure basic signal properties (Center Frequency, RF Attenuation and External Attenuation)
4. Configure Trigger Type and Trigger Parameters.
5. Configure Reference Level.
6. Select ACP measurement and enable Traces.
7. Configure Measurement Method.
8. Configure Averaging Parameters for ACP measurement.
9. Configure Sweep Time Parameters.
10. Configure Noise Compensation Parameter.
11. Configure Number of offset channels.
12. Initiate the Measurement.
13. Fetch ACP Measurements and Traces.
14. Close RFmx Session.


The gRPC API is built from the C API. RFmx WCDMA documentation is installed with the driver at:
C:\Program Files (x86)\National Instruments\RFmx\WCDMA\Documentation\wcdmacvi.chm

Getting Started:

To run this example, install "RFmx WCDMA" on the server machine.
Link: https://www.ni.com/en-us/support/downloads/software-products/download.rfmx-wcdma.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a
gRPC Client" wiki page.
Link: https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-RFmxWCDMA gRPC Wiki for the latest C Function Reference:
Link: https://github.com/ni/grpc-device/wiki/NI-RFmxWCDMA-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and physical channel name can be passed as separate
command line arguments.
  > python acp-single-carrier.py <server_address> <port_number> <physical_channel_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedDevice" as the resource name
"""

import sys

import grpc
import nirfmxwcdma_pb2 as nirfmxwcdma_types
import nirfmxwcdma_pb2_grpc as grpc_nirfmxwcdma

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "RFmxWCDMASession"

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
client = grpc_nirfmxwcdma.NiRFmxWCDMAStub(channel)
instr = None


NUMBER_OF_OFFSETS = 2


def check_for_warning(response, instrument):
    """Print to console if the status indicates a warning."""
    if response.status > 0:
        warning_message = client.GetErrorString(
            nirfmxwcdma_types.GetErrorStringRequest(
                instrument=instrument,
                error_code=response.status,
            )
        )
        sys.stderr.write(
            f"{warning_message.error_description}\nWarning status: {response.status}\n"
        )


try:
    auto_level = True

    # Initialize a session
    initialize_response = client.Initialize(
        nirfmxwcdma_types.InitializeRequest(
            session_name=SESSION_NAME,
            resource_name=RESOURCE,
            option_string=OPTIONS,
        )
    )
    instr = initialize_response.instrument
    check_for_warning(initialize_response, instr)

    client.CfgFrequencyReference(
        nirfmxwcdma_types.CfgFrequencyReferenceRequest(
            instrument=instr,
            channel_name="",
            frequency_reference_source_mapped=nirfmxwcdma_types.FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK,
            frequency_reference_frequency=10e6,
        )
    )

    client.CfgFrequency(
        nirfmxwcdma_types.CfgFrequencyRequest(
            instrument=instr,
            selector_string="",
            center_frequency=1.95e9,
        )
    )

    client.CfgExternalAttenuation(
        nirfmxwcdma_types.CfgExternalAttenuationRequest(
            instrument=instr,
            selector_string="",
            external_attenuation=0.000000,
        )
    )

    client.CfgRFAttenuation(
        nirfmxwcdma_types.CfgRFAttenuationRequest(
            instrument=instr,
            channel_name="",
            rf_attenuation_auto=nirfmxwcdma_types.RF_ATTENUATION_AUTO_TRUE,
            rf_attenuation_value=10.0,
        )
    )

    client.CfgDigitalEdgeTrigger(
        nirfmxwcdma_types.CfgDigitalEdgeTriggerRequest(
            instrument=instr,
            selector_string="",
            digital_edge_source_mapped=nirfmxwcdma_types.DIGITAL_EDGE_TRIGGER_SOURCE_PFI0,
            digital_edge=nirfmxwcdma_types.DIGITAL_EDGE_TRIGGER_EDGE_RISING,
            trigger_delay=0.000000,
            enable_trigger=False,
        )
    )

    if auto_level:
        auto_level_response = client.AutoLevel(
            nirfmxwcdma_types.AutoLevelRequest(
                instrument=instr,
                selector_string="",
                measurement_interval=0.010000,
            )
        )

        reference_level = auto_level_response.reference_level
        print(f"Reference level (dBm)          : {reference_level}")
    else:
        client.CfgReferenceLevel(
            nirfmxwcdma_types.CfgReferenceLevelRequest(
                instrument=instr,
                selector_string="",
                reference_level=0.000000,
            )
        )

    client.SelectMeasurements(
        nirfmxwcdma_types.SelectMeasurementsRequest(
            instrument=instr,
            selector_string="",
            measurements_array=[nirfmxwcdma_types.MEASUREMENT_TYPES_ACP],
            enable_all_traces=True,
        )
    )

    client.ACPCfgMeasurementMethod(
        nirfmxwcdma_types.ACPCfgMeasurementMethodRequest(
            instrument=instr,
            selector_string="",
            measurement_method=nirfmxwcdma_types.ACP_MEASUREMENT_METHOD_NORMAL,
        )
    )

    client.ACPCfgAveraging(
        nirfmxwcdma_types.ACPCfgAveragingRequest(
            instrument=instr,
            selector_string="",
            averaging_enabled=nirfmxwcdma_types.ACP_AVERAGING_ENABLED_FALSE,
            averaging_count=10,
            averaging_type=nirfmxwcdma_types.ACP_AVERAGING_TYPE_RMS,
        )
    )

    client.ACPCfgSweepTime(
        nirfmxwcdma_types.ACPCfgSweepTimeRequest(
            instrument=instr,
            selector_string="",
            sweep_time_auto=nirfmxwcdma_types.ACP_SWEEP_TIME_AUTO_TRUE,
            sweep_time_interval=0.000667,
        )
    )

    client.ACPCfgNoiseCompensationEnabled(
        nirfmxwcdma_types.ACPCfgNoiseCompensationEnabledRequest(
            instrument=instr,
            selector_string="",
            noise_compensation_enabled=nirfmxwcdma_types.ACP_NOISE_COMPENSATION_ENABLED_FALSE,
        )
    )

    client.ACPCfgNumberOfOffsets(
        nirfmxwcdma_types.ACPCfgNumberOfOffsetsRequest(
            instrument=instr,
            selector_string="",
            number_of_offsets=NUMBER_OF_OFFSETS,
        )
    )

    client.Initiate(
        nirfmxwcdma_types.InitiateRequest(
            instrument=instr,
            selector_string="",
            result_name="",
        )
    )

    # Fetch the measurements array
    acp_fetch_offset_measurement_array_response = client.ACPFetchOffsetMeasurementArray(
        nirfmxwcdma_types.ACPFetchOffsetMeasurementArrayRequest(
            instrument=instr,
            selector_string="",
            timeout=10.000000,
        )
    )
    check_for_warning(acp_fetch_offset_measurement_array_response, instr)

    lower_relative_power = acp_fetch_offset_measurement_array_response.lower_relative_power
    upper_relative_power = acp_fetch_offset_measurement_array_response.upper_relative_power
    lower_absolute_power = acp_fetch_offset_measurement_array_response.lower_absolute_power
    upper_absolute_power = acp_fetch_offset_measurement_array_response.upper_absolute_power

    assert len(lower_relative_power) == NUMBER_OF_OFFSETS, len(lower_relative_power)
    assert len(upper_relative_power) == NUMBER_OF_OFFSETS, len(upper_relative_power)
    assert len(lower_absolute_power) == NUMBER_OF_OFFSETS, len(lower_absolute_power)
    assert len(upper_absolute_power) == NUMBER_OF_OFFSETS, len(upper_absolute_power)

    acp_fetch_carrier_measurement_response = client.ACPFetchCarrierMeasurement(
        nirfmxwcdma_types.ACPFetchCarrierMeasurementRequest(
            instrument=instr,
            selector_string="",
            timeout=10.000000,
        )
    )
    check_for_warning(acp_fetch_carrier_measurement_response, instr)

    absolute_power = acp_fetch_carrier_measurement_response.absolute_power
    relative_power = acp_fetch_carrier_measurement_response.relative_power

    acp_fetch_spectrum_response = client.ACPFetchSpectrum(
        nirfmxwcdma_types.ACPFetchSpectrumRequest(
            instrument=instr,
            selector_string="",
            timeout=10.000000,
        )
    )
    check_for_warning(acp_fetch_spectrum_response, instr)

    x0 = acp_fetch_spectrum_response.x0
    dx = acp_fetch_spectrum_response.dx
    spectrum = acp_fetch_spectrum_response.spectrum

    print(f"\nCarrier Absolute Power  (dBm)  : {absolute_power}")

    print("\nOffset Channel Measurements: ")
    for i in range(NUMBER_OF_OFFSETS):
        print(f"Offset  :  {i}")
        print(f"Lower Relative Power (dB)      : {lower_relative_power[i]}")
        print(f"Upper Relative Power (dB)      : {upper_relative_power[i]}")
        print(f"Lower Absolute Power (dBm)     : {lower_absolute_power[i]}")
        print(f"Upper Absolute Power (dBm)     : {upper_absolute_power[i]}")
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
        client.Close(nirfmxwcdma_types.CloseRequest(instrument=instr, force_destroy=False))
