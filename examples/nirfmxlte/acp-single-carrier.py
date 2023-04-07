r"""Fetch ACP data.

Steps:
  1. Open a new RFmx Session.
  2. Configure Frequency Reference.
  3. Configure basic signal properties(Center Frequency, RF Attenuation and External Attenuation).
  4. Configure Trigger Type and Trigger Parameters.
  5. Configure Carrier Bandwidth.
  6. Configure Reference Level.
  7. Configure Duplex Mode.
  8. Configure Link Direction.
  9. Select ACP measurement and enable Traces.
  10. Configure Measurement Method.
  11. Configure Averaging Parameters for ACP measurement.
  12. Configure Sweep Time Parameters.
  13. Configure Noise Compensation Parameter.
  14. Initiate the Measurement.
  15. Fetch ACP Measurements and Traces.
  16. Close RFmx Session.

The gRPC API is built from the C API. RFmx LTE documentation is installed with the driver at:
  C:\Program Files (x86)\National Instruments\RFmx\LTE\Documentation\ltecvi.chm

Getting Started:

To run this example, install "RFmx LTE" on the server machine:
  https://www.ni.com/en-us/support/downloads/software-products/download.rfmx-lte.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-RFmxLTE gRPC Wiki for the latest C Function Reference:
  https://github.com/ni/grpc-device/wiki/NI-RFmxLTE-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and physical channel name can be passed as separate
command line arguments.
  > python acp-single-carrier.py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedDevice" as the resource name.
"""

import sys

import grpc
import nirfmxlte_pb2 as nirfmxlte_types
import nirfmxlte_pb2_grpc as grpc_nirfmxlte

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "RFmxLTESession"

# Resource name and options for a simulated 5663 client.
RESOURCE = "SimulatedDevice"
OPTIONS = "Simulate=1,DriverSetup=Model:5663"

NUMBER_OF_OFFSETS = 3

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
client = grpc_nirfmxlte.NiRFmxLTEStub(channel)
instr = None


def check_for_warning(response, instrument):
    """Print to console if the status indicates a warning."""
    if response.status > 0:
        warning_message = client.GetErrorString(
            nirfmxlte_types.GetErrorStringRequest(
                instrument=instrument,
                error_code=response.status,
            )
        )
        sys.stderr.write(
            f"{warning_message.error_description}\nWarning status: {response.status}\n"
        )


try:
    auto_level = True

    initialize_response = client.Initialize(
        nirfmxlte_types.InitializeRequest(
            session_name=SESSION_NAME,
            resource_name=RESOURCE,
            option_string=OPTIONS,
        )
    )
    instr = initialize_response.instrument

    client.CfgFrequencyReference(
        nirfmxlte_types.CfgFrequencyReferenceRequest(
            instrument=instr,
            channel_name="",
            frequency_reference_source_mapped=nirfmxlte_types.FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK,
            frequency_reference_frequency=10e6,
        )
    )

    client.CfgFrequency(
        nirfmxlte_types.CfgFrequencyRequest(
            instrument=instr, selector_string="", center_frequency=1.95e9
        )
    )

    client.CfgExternalAttenuation(
        nirfmxlte_types.CfgExternalAttenuationRequest(
            instrument=instr, selector_string="", external_attenuation=0.0
        )
    )

    client.CfgRFAttenuation(
        nirfmxlte_types.CfgRFAttenuationRequest(
            instrument=instr,
            channel_name="",
            rf_attenuation_auto=nirfmxlte_types.RF_ATTENUATION_AUTO_TRUE,
            rf_attenuation_value=10.0,
        )
    )

    client.CfgDigitalEdgeTrigger(
        nirfmxlte_types.CfgDigitalEdgeTriggerRequest(
            instrument=instr,
            selector_string="",
            digital_edge_source_mapped=nirfmxlte_types.DIGITAL_EDGE_TRIGGER_SOURCE_PFI0,
            digital_edge=nirfmxlte_types.DIGITAL_EDGE_TRIGGER_EDGE_RISING,
            trigger_delay=0.0,
            enable_trigger=False,
        )
    )

    client.CfgComponentCarrier(
        nirfmxlte_types.CfgComponentCarrierRequest(
            instrument=instr,
            selector_string="",
            component_carrier_bandwidth=10e6,
            component_carrier_frequency=0.0,
            cell_id=0,
        )
    )

    if auto_level:
        auto_level_response = client.AutoLevel(
            nirfmxlte_types.AutoLevelRequest(
                instrument=instr,
                selector_string="",
                measurement_interval=0.01,
            )
        )

        reference_level = auto_level_response.reference_level
        print(f"Reference level (dBm)        : {reference_level}")
    else:
        client.CfgReferenceLevel(
            nirfmxlte_types.CfgReferenceLevelRequest(
                instrument=instr, selector_string="", reference_level=0.0
            )
        )

    client.CfgDuplexScheme(
        nirfmxlte_types.CfgDuplexSchemeRequest(
            instrument=instr,
            selector_string="",
            duplex_scheme=nirfmxlte_types.DUPLEX_SCHEME_FDD,
            uplink_downlink_configuration=nirfmxlte_types.UPLINK_DOWNLINK_CONFIGURATION_0,
        )
    )

    client.CfgLinkDirection(
        nirfmxlte_types.CfgLinkDirectionRequest(
            instrument=instr,
            selector_string="",
            link_direction=nirfmxlte_types.LINK_DIRECTION_UPLINK,
        )
    )

    client.SelectMeasurements(
        nirfmxlte_types.SelectMeasurementsRequest(
            instrument=instr,
            selector_string="",
            measurements=nirfmxlte_types.MEASUREMENT_TYPES_ACP,
            enable_all_traces=True,
        )
    )

    client.ACPCfgMeasurementMethod(
        nirfmxlte_types.ACPCfgMeasurementMethodRequest(
            instrument=instr,
            selector_string="",
            measurement_method=nirfmxlte_types.ACP_MEASUREMENT_METHOD_NORMAL,
        )
    )

    client.ACPCfgAveraging(
        nirfmxlte_types.ACPCfgAveragingRequest(
            instrument=instr,
            selector_string="",
            averaging_enabled=nirfmxlte_types.ACP_AVERAGING_ENABLED_FALSE,
            averaging_count=10,
            averaging_type=nirfmxlte_types.ACP_AVERAGING_TYPE_RMS,
        )
    )

    client.ACPCfgSweepTime(
        nirfmxlte_types.ACPCfgSweepTimeRequest(
            instrument=instr,
            selector_string="",
            sweep_time_auto=nirfmxlte_types.ACP_SWEEP_TIME_AUTO_TRUE,
            sweep_time_interval=0.001,
        )
    )

    client.ACPCfgNoiseCompensationEnabled(
        nirfmxlte_types.ACPCfgNoiseCompensationEnabledRequest(
            instrument=instr,
            selector_string="",
            noise_compensation_enabled=nirfmxlte_types.ACP_NOISE_COMPENSATION_ENABLED_FALSE,
        )
    )

    initiate_response = client.Initiate(
        nirfmxlte_types.InitiateRequest(
            instrument=instr,
            selector_string="",
            result_name="",
        )
    )
    check_for_warning(initiate_response, instr)

    ### Fetch results ###

    acp_fetch_offset_measurement_array_response = client.ACPFetchOffsetMeasurementArray(
        nirfmxlte_types.ACPFetchOffsetMeasurementArrayRequest(
            instrument=instr,
            selector_string="",
            timeout=10.0,
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

    acp_fetch_component_carrier_measurement_response = client.ACPFetchComponentCarrierMeasurement(
        nirfmxlte_types.ACPFetchComponentCarrierMeasurementRequest(
            instrument=instr,
            selector_string="",
            timeout=10.0,
        )
    )
    check_for_warning(acp_fetch_component_carrier_measurement_response, instr)

    absolute_power = acp_fetch_component_carrier_measurement_response.absolute_power
    relative_power = acp_fetch_component_carrier_measurement_response.relative_power

    for i in range(NUMBER_OF_OFFSETS):
        acp_fetch_absolute_powers_trace_response = client.ACPFetchAbsolutePowersTrace(
            nirfmxlte_types.ACPFetchAbsolutePowersTraceRequest(
                instrument=instr,
                selector_string="",
                timeout=10.0,
                trace_index=i,
            )
        )
        check_for_warning(acp_fetch_absolute_powers_trace_response, instr)

    for i in range(NUMBER_OF_OFFSETS):
        acp_fetch_relative_powers_trace_response = client.ACPFetchRelativePowersTrace(
            nirfmxlte_types.ACPFetchRelativePowersTraceRequest(
                instrument=instr,
                selector_string="",
                timeout=10.0,
                trace_index=i,
            )
        )
        check_for_warning(acp_fetch_relative_powers_trace_response, instr)

    acp_fetch_spectrum_response = client.ACPFetchSpectrum(
        nirfmxlte_types.ACPFetchSpectrumRequest(
            instrument=instr,
            selector_string="",
            timeout=10.0,
        )
    )
    check_for_warning(acp_fetch_spectrum_response, instr)
    x0 = acp_fetch_spectrum_response.x0
    dx = acp_fetch_spectrum_response.dx
    spectrum = acp_fetch_spectrum_response.spectrum

    print(f"\nCarrier Absolute Power (dBm) : {absolute_power}")

    print("\n-----------Offset Channel Measurements----------- ")
    for i in range(NUMBER_OF_OFFSETS):
        print(f"Offset : {i}")
        print(f"Lower Relative Power (dB)    : {lower_relative_power[i]}")
        print(f"Upper Relative Power (dB)    : {upper_relative_power[i]}")
        print(f"Lower Absolute Power (dBm)   : {lower_absolute_power[i]}")
        print(f"Upper Absolute Power (dBm)   : {upper_absolute_power[i]}")
        print("------------------------------------------")
except grpc.RpcError as rpc_error:
    error_message = str(rpc_error.details() or "")
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
        client.Close(nirfmxlte_types.CloseRequest(instrument=instr, force_destroy=False))
