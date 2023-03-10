r"""Fetch ACP data.

Steps:
1. Open a new RFmx session
2. Configure Reference Clock
3. Configure the basic signal properties  (Center Frequency, Reference Level and External
   Attenuation)
4. Configure RF Attenuation
5. Configure Trigger
6. Configure Band Class
7. Set Measurement to ACP
8. Configure Number of Offsets
9. Set Noise Compensation
10. Set Dynamic Range Mode
11. Configure Sweep Time
12. Configure Averaging Parameters
13. Commit Settings and Initiate Measurement
14. Fetch diverse ACP Measurement Results
15. Close the RFmx Session

The gRPC API is built from the C API. RFmx CDMA2k documentation is installed with the driver at:
C:\Program Files (x86)\National Instruments\RFmx\CDMA2k\Documentation\cdma2kcvi.chm

Getting Started:

To run this example, install "RFmx CDMA2k" on the server machine.
Link: https://www.ni.com/en-us/support/downloads/software-products/download.rfmx-cdma2k.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a 
gRPC Client" wiki page.
Link: https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-RFmxCDMA2k gRPC Wiki for the latest C Function Reference:
Link: https://github.com/ni/grpc-device/wiki/NI-RFmxCDMA2k-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and physical channel name can be passed as separate
command line arguments.
  > python RFmxCdma2kAcp.c <server_address> <port_number> <physical_channel_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedDevice" as the resource name
"""

import sys

import grpc
import nirfmxcdma2k_pb2 as nirfmxcdma2k_types
import nirfmxcdma2k_pb2_grpc as grpc_nirfmxcdma2k

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "RFmxCDMA2kSession"

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
client = grpc_nirfmxcdma2k.NiRFmxCDMA2kStub(channel)
instr = None


NUMBER_OF_OFFSETS = 2


def check_for_warning(response, instrument):
    """Print to console if the status indicates a warning."""
    if response.status > 0:
        warning_message = client.GetErrorString(
            nirfmxcdma2k_types.GetErrorStringRequest(
                instrument=instrument,
                error_code=response.status,
            )
        )
        sys.stderr.write(
            f"{warning_message.error_description}\nWarning status: {response.status}\n"
        )


try:
    # Auto Level
    auto_level = 1

    # Create a new RFmx Session
    initialize_response = client.Initialize(
        nirfmxcdma2k_types.InitializeRequest(
            session_name=SESSION_NAME,
            resource_name=RESOURCE,
            option_string=OPTIONS,
        )
    )
    instr = initialize_response.instrument
    check_for_warning(initialize_response, instr)

    # Configure CDMA2k ACP measurement parameters
    client.CfgFrequencyReference(
        nirfmxcdma2k_types.CfgFrequencyReferenceRequest(
            instrument=instr,
            channel_name="",
            frequency_reference_source_mapped=nirfmxcdma2k_types.FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK,
            frequency_reference_frequency=10.0e6,
        )
    )
    client.CfgExternalAttenuation(
        nirfmxcdma2k_types.CfgExternalAttenuationRequest(
            instrument=instr, selector_string="", external_attenuation=0.00
        )
    )
    client.CfgFrequency(
        nirfmxcdma2k_types.CfgFrequencyRequest(
            instrument=instr, selector_string="", center_frequency=833.490e6
        )
    )
    client.CfgRFAttenuation(
        nirfmxcdma2k_types.CfgRFAttenuationRequest(
            instrument=instr,
            channel_name="",
            rf_attenuation_auto=nirfmxcdma2k_types.RF_ATTENUATION_AUTO_TRUE,
            rf_attenuation_value=10.00,
        )
    )
    client.CfgDigitalEdgeTrigger(
        nirfmxcdma2k_types.CfgDigitalEdgeTriggerRequest(
            instrument=instr,
            selector_string="",
            digital_edge_source_mapped=nirfmxcdma2k_types.DIGITAL_EDGE_TRIGGER_SOURCE_PFI0,
            digital_edge=nirfmxcdma2k_types.DIGITAL_EDGE_TRIGGER_EDGE_RISING,
            trigger_delay=0.0,
            enable_trigger=False,
        )
    )
    if auto_level:
        auto_level_response = client.AutoLevel(
            nirfmxcdma2k_types.AutoLevelRequest(
                instrument=instr, selector_string="", measurement_interval=0.02
            )
        )
        reference_level = auto_level_response.reference_level
        print(f"Reference level (dBm)                    : {reference_level}")
    else:
        client.CfgReferenceLevel(
            nirfmxcdma2k_types.CfgReferenceLevelRequest(
                instrument=instr, selector_string="", reference_level=0.00
            )
        )
    client.CfgBandClass(
        nirfmxcdma2k_types.CfgBandClassRequest(instrument=instr, selector_string="", band_class=0)
    )
    client.SelectMeasurements(
        nirfmxcdma2k_types.SelectMeasurementsRequest(
            instrument=instr,
            selector_string="",
            measurements_array=[nirfmxcdma2k_types.MEASUREMENT_TYPES_ACP],
            enable_all_traces=True,
        )
    )
    client.ACPCfgNumberOfOffsets(
        nirfmxcdma2k_types.ACPCfgNumberOfOffsetsRequest(
            instrument=instr, selector_string="", number_of_offsets=NUMBER_OF_OFFSETS
        )
    )
    client.ACPCfgNoiseCompensationEnabled(
        nirfmxcdma2k_types.ACPCfgNoiseCompensationEnabledRequest(
            instrument=instr,
            selector_string="",
            noise_compensation_enabled=nirfmxcdma2k_types.ACP_NOISE_COMPENSATION_ENABLED_FALSE,
        )
    )
    client.ACPCfgMeasurementMethod(
        nirfmxcdma2k_types.ACPCfgMeasurementMethodRequest(
            instrument=instr,
            selector_string="",
            measurement_method=nirfmxcdma2k_types.ACP_MEASUREMENT_METHOD_NORMAL,
        )
    )
    client.ACPCfgSweepTime(
        nirfmxcdma2k_types.ACPCfgSweepTimeRequest(
            instrument=instr,
            selector_string="",
            sweep_time_auto=nirfmxcdma2k_types.ACP_SWEEP_TIME_AUTO_TRUE,
            sweep_time_interval=1.67e-3,
        )
    )
    client.ACPCfgAveraging(
        nirfmxcdma2k_types.ACPCfgAveragingRequest(
            instrument=instr,
            selector_string="",
            averaging_enabled=nirfmxcdma2k_types.ACP_AVERAGING_ENABLED_FALSE,
            averaging_count=10,
            averaging_type=nirfmxcdma2k_types.ACP_AVERAGING_TYPE_RMS,
        )
    )
    initiate_response = client.Initiate(
        nirfmxcdma2k_types.InitiateRequest(instrument=instr, selector_string="", result_name="")
    )
    check_for_warning(initiate_response, instr)

    # Fetch diverse ACP Measurement Results

    acp_fetch_offset_measurement_array_response = client.ACPFetchOffsetMeasurementArray(
        nirfmxcdma2k_types.ACPFetchOffsetMeasurementArrayRequest(
            instrument=instr, selector_string="", timeout=10.0
        )
    )
    check_for_warning(acp_fetch_offset_measurement_array_response, instr)
    lower_relative_power = acp_fetch_offset_measurement_array_response.lower_relative_power
    upper_relative_power = acp_fetch_offset_measurement_array_response.upper_relative_power
    upper_absolute_power = acp_fetch_offset_measurement_array_response.lower_absolute_power
    lower_absolute_power = acp_fetch_offset_measurement_array_response.upper_absolute_power

    acp_fetch_carrier_absolute_power_response = client.ACPFetchCarrierAbsolutePower(
        nirfmxcdma2k_types.ACPFetchCarrierAbsolutePowerRequest(
            instrument=instr, selector_string="", timeout=10.0
        )
    )
    check_for_warning(acp_fetch_carrier_absolute_power_response, instr)
    carrier_absolute_power = acp_fetch_carrier_absolute_power_response.carrier_absolute_power

    acp_fetch_spectrum_response = client.ACPFetchSpectrum(
        nirfmxcdma2k_types.ACPFetchSpectrumRequest(
            instrument=instr, selector_string="", timeout=10.0
        )
    )
    check_for_warning(acp_fetch_spectrum_response, instr)
    x0 = acp_fetch_spectrum_response.x0
    dx = acp_fetch_spectrum_response.dx
    spectrum = acp_fetch_spectrum_response.spectrum

    # Display ACP Measurement Results
    print(f"Carrier Absolute Power (dBm)             : {carrier_absolute_power}")

    print("\n-------------- Offset Channel Measurements --------------")

    for i in range(NUMBER_OF_OFFSETS):
        print(f"\nOFFSET {i}")
        print(f"Lower Relative Power (dB)                : {lower_relative_power[i]}")
        print(f"Upper Relative Power (dB)                : {upper_relative_power[i]}")
        print(f"Lower Absolute Power (dBm)               : {upper_absolute_power[i]}")
        print(f"Upper Absolute Power (dBm)               : {lower_absolute_power[i]}")
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
        client.Close(nirfmxcdma2k_types.CloseRequest(instrument=instr, force_destroy=False))
