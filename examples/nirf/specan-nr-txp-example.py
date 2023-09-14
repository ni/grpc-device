r"""Multi Rfmx Personality Example with SpecAn and NR.

Steps:
  1. Open only one RFmx Session. No need to open every personality.
  2. Configure Frequency Reference.
  3. Configure Selected Ports.
  4. Configure basic signal properties(Center Frequency, Reference Level and External Attenuation).
  5. Configure Link Direction, Frequency Range, Carrier Bandwidthand Subcarrier Spacing.
  6. Select NR TXP and SpecAn TXP measurement and enable Traces.
  7. Configure Measurement Offset & Measurement Length Parameters and Averaging Parameters for TXP
     measurement.
  9. Initiate NR Measurement.
  10. Fetch NR Measurements and Traces.
  11. Initiate SpecAn Measurement.
  12. Fetch SpecAn Measurements and Traces.
  13. Close RFmx Session.

The gRPC API is built from the C API. RFmx NR documentation is installed with the driver at:
  C:\Program Files (x86)\National Instruments\RFmx\NR\Documentation\rfmxnrcvi.chm

Getting Started:

To run this example, install "RFmx NR" on the server machine:
  https://www.ni.com/en-us/support/downloads/software-products/download.rfmx-nr.html

To run this example, install "RFmx SpecAn" on the server machine:
  https://www.ni.com/en-us/support/downloads/software-products/download.rfmx-specan.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-RFmxNR gRPC Wiki for the latest C Function Reference:
  https://github.com/ni/grpc-device/wiki/NI-RFmxNR-C-Function-Reference

Refer to the NI-RFmxSpecAn gRPC Wiki for the latest C Function Reference:
  https://github.com/ni/grpc-device/wiki/NI-RFmxSpecAn-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and physical channel name can be passed as separate
command line arguments.
  > python txp-single-carrier.py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedDevice" as the resource name.
"""

import sys

import grpc
import nirfmxinstr_pb2 as nirfmxinstr_types
import nirfmxinstr_pb2_grpc as grpc_nirfmxinstr
import nirfmxnr_pb2 as nirfmxnr_types
import nirfmxnr_pb2_grpc as grpc_nirfmxnr
import nirfmxspecan_pb2 as nirfmxspecan_types
import nirfmxspecan_pb2_grpc as grpc_nirfmxspecan

SERVER_ADDRESS = "mercury07"
SERVER_PORT = "31763"
SESSION_NAME = "RFmxNRSession"

# Resource name and options for a simulated 5663 client.
RESOURCE = "5840_1"
OPTIONS = ""

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
instrclient = grpc_nirfmxinstr.NiRFmxInstrStub(channel)
nrclient = grpc_nirfmxnr.NiRFmxNRStub(channel)
specanclient = grpc_nirfmxspecan.NiRFmxSpecAnStub(channel)
instr = None


def check_for_warning(response, instrument):
    """Print to console if the status indicates a warning."""
    if response.status > 0:
        warning_message = nrclient.GetErrorString(
            nirfmxnr_types.GetErrorStringRequest(
                instrument=instrument,
                error_code=response.status,
            )
        )
        sys.stderr.write(
            f"{warning_message.error_description}\nWarning status: {response.status}\n"
        )


try:
    # Only one personality needs to be initialized. The return session, can be used across all
    # other personalities
    initialize_response = instrclient.Initialize(
        nirfmxinstr_types.InitializeRequest(
            session_name=SESSION_NAME,
            resource_name=RESOURCE,
            option_string=OPTIONS,
        )
    )
    instr = initialize_response.instrument

    # Configure RfInstr reference clock
    instrclient.CfgFrequencyReference(
        nirfmxinstr_types.CfgFrequencyReferenceRequest(
            instrument=instr,
            channel_name="",
            frequency_reference_source_mapped=nirfmxinstr_types.FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK,
            frequency_reference_frequency=10e6,
        )
    )

    # Configure and test NR
    nrclient.SetAttributeString(
        nirfmxnr_types.SetAttributeStringRequest(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_SELECTED_PORTS,
            attr_val_raw="",
        )
    )

    nrclient.CfgRF(
        nirfmxnr_types.CfgRFRequest(
            instrument=instr,
            selector_string="",
            center_frequency=3.5e9,
            reference_level=0.0,
            external_attenuation=0.0,
        )
    )

    nrclient.SetAttributeI32(
        nirfmxnr_types.SetAttributeI32Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_LINK_DIRECTION,
            attr_val_raw=nirfmxnr_types.NIRFMXNR_INT32_LINK_DIRECTION_UPLINK,
        )
    )

    nrclient.SetAttributeI32(
        nirfmxnr_types.SetAttributeI32Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE,
            attr_val_raw=nirfmxnr_types.NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1,
        )
    )

    nrclient.SetAttributeF64(
        nirfmxnr_types.SetAttributeF64Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH,
            attr_val=20e6,
        )
    )

    nrclient.SetAttributeF64(
        nirfmxnr_types.SetAttributeF64Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING,
            attr_val=30e3,
        )
    )

    nrclient.SelectMeasurements(
        nirfmxnr_types.SelectMeasurementsRequest(
            instrument=instr,
            selector_string="",
            measurements=nirfmxnr_types.MEASUREMENT_TYPES_TXP,
            enable_all_traces=True,
        )
    )

    nrclient.SetAttributeF64(
        nirfmxnr_types.SetAttributeF64Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_TXP_MEASUREMENT_INTERVAL,
            attr_val=1.0e-3,
        )
    )

    nrclient.SetAttributeF64(
        nirfmxnr_types.SetAttributeF64Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_TXP_MEASUREMENT_OFFSET,
            attr_val=0.0,
        )
    )

    nrclient.SetAttributeI32(
        nirfmxnr_types.SetAttributeI32Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_TXP_AVERAGING_ENABLED,
            attr_val_raw=nirfmxnr_types.NIRFMXNR_INT32_TXP_AVERAGING_ENABLED_TRUE,
        )
    )

    nrclient.SetAttributeI32(
        nirfmxnr_types.SetAttributeI32Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_TXP_AVERAGING_COUNT,
            attr_val_raw=10,
        )
    )

    initiate_response = nrclient.Initiate(
        nirfmxnr_types.InitiateRequest(
            instrument=instr,
            selector_string="",
            result_name="",
        )
    )
    check_for_warning(initiate_response, instr)
    ### Fetch NR TXP results ###

    txp_fetch_measurement_response = nrclient.TXPFetchMeasurement(
        nirfmxnr_types.TXPFetchMeasurementRequest(
            instrument=instr,
            selector_string="",
            timeout=10.0,
        )
    )
    check_for_warning(txp_fetch_measurement_response, instr)
    avearge_power_mean = txp_fetch_measurement_response.average_power_mean
    peak_power_maximum = txp_fetch_measurement_response.peak_power_maximum

    txp_fetch_power_trace_response = nrclient.TXPFetchPowerTrace(
        nirfmxnr_types.TXPFetchPowerTraceRequest(
            instrument=instr,
            selector_string="",
            timeout=10.0,
        )
    )
    check_for_warning(txp_fetch_power_trace_response, instr)
    x0 = txp_fetch_power_trace_response.x0
    dx = txp_fetch_power_trace_response.dx
    power = txp_fetch_power_trace_response.power

    print("\n------------NR TXP Measurement------------\n")
    print(f"Average Power Mean (dBm) : {avearge_power_mean}")
    print(f"Peak Power Maximum (dBm) : {peak_power_maximum}")

    # Configure and test SpecAn TXP
    specanclient.SetAttributeString(
        nirfmxspecan_types.SetAttributeStringRequest(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxspecan_types.NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS,
            attr_val_raw="",
        )
    )

    specanclient.CfgRF(
        nirfmxspecan_types.CfgRFRequest(
            instrument=instr,
            selector_string="",
            center_frequency=1e9,
            reference_level=0.00,
            external_attenuation=0.00,
        )
    )

    specanclient.TXPCfgMeasurementInterval(
        nirfmxspecan_types.TXPCfgMeasurementIntervalRequest(
            instrument=instr,
            selector_string="",
            measurement_interval=1e-3,
        )
    )

    specanclient.TXPCfgRBWFilter(
        nirfmxspecan_types.TXPCfgRBWFilterRequest(
            instrument=instr,
            selector_string="",
            rbw=100e3,
            rbw_filter_type=nirfmxspecan_types.TXP_RBW_FILTER_TYPE_GAUSSIAN,
            rrc_alpha=0.1,
        )
    )

    specanclient.TXPCfgAveraging(
        nirfmxspecan_types.TXPCfgAveragingRequest(
            instrument=instr,
            selector_string="",
            averaging_enabled=nirfmxspecan_types.TXP_AVERAGING_ENABLED_FALSE,
            averaging_count=10,
            averaging_type=nirfmxspecan_types.TXP_AVERAGING_TYPE_RMS,
        )
    )

    ### Fetch SpecAn measurement data ###

    txp_read_response = specanclient.TXPRead(
        nirfmxspecan_types.TXPReadRequest(
            instrument=instr,
            selector_string="",
            timeout=10.0,
        )
    )
    check_for_warning(txp_read_response, instr)

    minimum_power = txp_read_response.minimum_power
    maximum_power = txp_read_response.maximum_power
    peak_to_average_ratio = txp_read_response.peak_to_average_ratio
    average_mean_power = txp_read_response.average_mean_power

    print("\n------------SpecAn TXP Measurement------------\n")
    print(f"Average Mean Power(dBm)    {average_mean_power}")
    print(f"Peak to Average Ratio(dB)  {peak_to_average_ratio}")
    print(f"Maximum Power(dBm)         {maximum_power}")
    print(f"Minimum Power(dBm)         {minimum_power}")
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
        instrclient.Close(
            # Only one session can be closed and using any personality
            nirfmxinstr_types.CloseRequest(instrument=instr, force_destroy=False)
        )
