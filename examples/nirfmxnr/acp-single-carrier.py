r"""Fetch ACP data.

Steps:
  1. Open a new RFmx Session.
  2. Configure Frequency Reference.
  3. Configure Selected Ports.
  4. Configure basic signal properties (Center Frequency, RF Attenuation and External Attenuation).
  5. Configure Trigger Parameters for IQ Power Edge Trigger.
  6. Configure Link Direction, Frequency Range and Carrier Bandwidth and Subcarrier Spacing.
  7. Configure Reference Level.
  8. Select ACP measurement and enable Traces.
  9. Configure Measurement Method.
  10. Configure Noise Compensation Parameter.
  11. Configure Sweep Time Parameters.
  12. Configure Averaging Parameters for ACP measurement.
  13. Initiate the Measurement.
  14. Fetch ACP Measurements and Traces.
  15. Close RFmx Session.

The gRPC API is built from the C API. RFmx NR documentation is installed with the driver at:
  C:\Program Files (x86)\National Instruments\RFmx\NR\Documentation\rfmxnrcvi.chm

Getting Started:

To run this example, install "RFmx NR" on the server machine:
  https://www.ni.com/en-us/support/downloads/software-products/download.rfmx-nr.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-RFmxNR gRPC Wiki for the latest C Function Reference:
  https://github.com/ni/grpc-device/wiki/NI-RFmxNR-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and physical channel name can be passed as separate
command line arguments.
  > python acp-single-carrier.py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedDevice" as the resource name.
"""

import sys

import grpc
import nirfmxnr_pb2 as nirfmxnr_types
import nirfmxnr_pb2_grpc as grpc_nirfmxnr

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "RFmxNRSession"

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
client = grpc_nirfmxnr.NiRFmxNRStub(channel)
instr = None


def raise_if_initialization_error(response):
    """Raise an exception if an error was returned from Initialize."""
    if response.status < 0:
        raise RuntimeError(f"Error: {response.error_message or response.status}")
    if response.status > 0:
        sys.stderr.write(f"Warning: {response.error_message or response.status}\n")
    return response


def raise_if_error(response):
    """Raise an exception if an error was returned."""
    if response.status != 0:
        error_response = client.GetError(
            nirfmxnr_types.GetErrorRequest(
                instrument=instr,
            )
        )
        if response.status < 0:
            raise RuntimeError(f"Error: {error_response.error_description or response.status}")
        else:
            sys.stderr.write(f"Warning: {error_response.error_description or response.status}\n")

    return response


try:
    auto_level = True

    initialize_response = raise_if_initialization_error(
        client.Initialize(
            nirfmxnr_types.InitializeRequest(
                session_name=SESSION_NAME, resource_name=RESOURCE, option_string=OPTIONS
            )
        )
    )
    instr = initialize_response.instrument
    raise_if_error(
        client.CfgFrequencyReference(
            nirfmxnr_types.CfgFrequencyReferenceRequest(
                instrument=instr,
                channel_name="",
                frequency_reference_source_mapped=nirfmxnr_types.FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK,
                frequency_reference_frequency=10.0e6,
            )
        )
    )
    raise_if_error(
        client.SetAttributeString(
            nirfmxnr_types.SetAttributeStringRequest(
                instrument=instr,
                selector_string="",
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_SELECTED_PORTS,
                attr_val_raw="",
            )
        )
    )
    raise_if_error(
        client.CfgFrequency(
            nirfmxnr_types.CfgFrequencyRequest(
                instrument=instr, selector_string="", center_frequency=3.5e9
            )
        )
    )
    raise_if_error(
        client.CfgExternalAttenuation(
            nirfmxnr_types.CfgExternalAttenuationRequest(
                instrument=instr, selector_string="", external_attenuation=0.0
            )
        )
    )
    raise_if_error(
        client.CfgRFAttenuation(
            nirfmxnr_types.CfgRFAttenuationRequest(
                instrument=instr,
                channel_name="",
                rf_attenuation_auto=nirfmxnr_types.RF_ATTENUATION_AUTO_TRUE,
                rf_attenuation_value=10.0,
            )
        )
    )
    raise_if_error(
        client.CfgIQPowerEdgeTrigger(
            nirfmxnr_types.CfgIQPowerEdgeTriggerRequest(
                instrument=instr,
                selector_string="",
                iq_power_edge_source="0",
                iq_power_edge_slope=nirfmxnr_types.IQ_POWER_EDGE_TRIGGER_SLOPE_RISING,
                iq_power_edge_level=-20.0,
                trigger_delay=0.0,
                trigger_min_quiet_time_mode=nirfmxnr_types.TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO,
                trigger_min_quiet_time_duration=8.0e-6,
                iq_power_edge_level_type=nirfmxnr_types.IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE,
                enable_trigger=False,
            )
        )
    )
    raise_if_error(
        client.SetAttributeI32(
            nirfmxnr_types.SetAttributeI32Request(
                instrument=instr,
                selector_string="",
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_LINK_DIRECTION,
                attr_val_raw=nirfmxnr_types.NIRFMXNR_INT32_LINK_DIRECTION_UPLINK,
            )
        )
    )
    raise_if_error(
        client.SetAttributeI32(
            nirfmxnr_types.SetAttributeI32Request(
                instrument=instr,
                selector_string="",
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE,
                attr_val_raw=nirfmxnr_types.NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1,
            )
        )
    )
    raise_if_error(
        client.SetAttributeF64(
            nirfmxnr_types.SetAttributeF64Request(
                instrument=instr,
                selector_string="",
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH,
                attr_val=20e6,
            )
        )
    )
    raise_if_error(
        client.SetAttributeF64(
            nirfmxnr_types.SetAttributeF64Request(
                instrument=instr,
                selector_string="",
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING,
                attr_val=30e3,
            )
        )
    )
    if auto_level:
        auto_level_response = raise_if_error(
            client.AutoLevel(
                nirfmxnr_types.AutoLevelRequest(
                    instrument=instr, selector_string="", measurement_interval=10.0e-3
                )
            )
        )
        reference_level = auto_level_response.reference_level
        print(f"Reference level (dBm)        : {reference_level}")
    else:
        raise_if_error(
            client.CfgReferenceLevel(
                nirfmxnr_types.CfgReferenceLevelRequest(
                    instrument=instr, selector_string="", reference_level=0.0
                )
            )
        )
    raise_if_error(
        client.SelectMeasurements(
            nirfmxnr_types.SelectMeasurementsRequest(
                instrument=instr,
                selector_string="",
                measurements=nirfmxnr_types.MEASUREMENT_TYPES_ACP,
                enable_all_traces=True,
            )
        )
    )
    raise_if_error(
        client.ACPCfgMeasurementMethod(
            nirfmxnr_types.ACPCfgMeasurementMethodRequest(
                instrument=instr,
                selector_string="",
                measurement_method=nirfmxnr_types.ACP_MEASUREMENT_METHOD_NORMAL,
            )
        )
    )
    raise_if_error(
        client.ACPCfgNoiseCompensationEnabled(
            nirfmxnr_types.ACPCfgNoiseCompensationEnabledRequest(
                instrument=instr,
                selector_string="",
                noise_compensation_enabled=nirfmxnr_types.ACP_NOISE_COMPENSATION_ENABLED_FALSE,
            )
        )
    )
    raise_if_error(
        client.ACPCfgSweepTime(
            nirfmxnr_types.ACPCfgSweepTimeRequest(
                instrument=instr,
                selector_string="",
                sweep_time_auto=nirfmxnr_types.ACP_SWEEP_TIME_AUTO_TRUE,
                sweep_time_interval=1.0e-3,
            )
        )
    )
    raise_if_error(
        client.ACPCfgAveraging(
            nirfmxnr_types.ACPCfgAveragingRequest(
                instrument=instr,
                selector_string="",
                averaging_enabled=nirfmxnr_types.ACP_AVERAGING_ENABLED_FALSE,
                averaging_count=10,
                averaging_type=nirfmxnr_types.ACP_AVERAGING_TYPE_RMS,
            )
        )
    )
    raise_if_error(
        client.Initiate(
            nirfmxnr_types.InitiateRequest(instrument=instr, selector_string="", result_name="")
        )
    )

    ### Fetch results ###

    acp_fetch_offset_measurement_array_response = raise_if_error(
        client.ACPFetchOffsetMeasurementArray(
            nirfmxnr_types.ACPFetchOffsetMeasurementArrayRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    array_size = len(acp_fetch_offset_measurement_array_response.lower_relative_power)
    lower_relative_power = acp_fetch_offset_measurement_array_response.lower_relative_power
    upper_relative_power = acp_fetch_offset_measurement_array_response.upper_relative_power
    lower_absolute_power = acp_fetch_offset_measurement_array_response.lower_absolute_power
    upper_absolute_power = acp_fetch_offset_measurement_array_response.upper_absolute_power

    acp_fetch_component_carrier_measurement_response = raise_if_error(
        client.ACPFetchComponentCarrierMeasurement(
            nirfmxnr_types.ACPFetchComponentCarrierMeasurementRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    absolute_power = acp_fetch_component_carrier_measurement_response.absolute_power
    relative_power = acp_fetch_component_carrier_measurement_response.relative_power

    for i in range(array_size):
        acp_fetch_relative_powers_trace_response = raise_if_error(
            client.ACPFetchRelativePowersTrace(
                nirfmxnr_types.ACPFetchRelativePowersTraceRequest(
                    instrument=instr, selector_string="", timeout=10.0, trace_index=i
                )
            )
        )
        x0 = acp_fetch_relative_powers_trace_response.x0
        dx = acp_fetch_relative_powers_trace_response.dx
        relative_powers_trace = acp_fetch_relative_powers_trace_response.relative_powers_trace

    acp_fetch_spectrum_response = raise_if_error(
        client.ACPFetchSpectrum(
            nirfmxnr_types.ACPFetchSpectrumRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    x0 = acp_fetch_spectrum_response.x0
    dx = acp_fetch_spectrum_response.dx
    spectrum = acp_fetch_spectrum_response.spectrum

    print(f"\nCarrier Absolute Power (dBm or dBm/Hz) : {absolute_power}")

    print("\n-----------Offset Channel Measurements----------- \n")
    for i in range(array_size):
        print(f"Offset  {i}")
        print(f"Lower Relative Power (dB)              : {lower_relative_power[i]}")
        print(f"Upper Relative Power (dB)              : {upper_relative_power[i]}")
        print(f"Lower Absolute Power (dBm or dBm/Hz)   : {lower_absolute_power[i]}")
        print(f"Upper Absolute Power (dBm or dBm/Hz)   : {upper_absolute_power[i]}")
        print("-------------------------------------------------\n")
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE:
        error_message = f"Failed to connect to server on {SERVER_ADDRESS}:{SERVER_PORT}"
    elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
        error_message = (
            "The operation is not implemented or is not supported/enabled in this service"
        )
    sys.stderr.write(f"{error_message}\n")
finally:
    if instr:
        client.Close(nirfmxnr_types.CloseRequest(instrument=instr, force_destroy=False))
