r"""Fetch TXP data.

Steps:
  1. Open a new RFmx Session.
  2. Configure Frequency Reference.
  3. Configure Selected Ports.
  4. Configure basic signal properties(Center Frequency, Reference Level and External Attenuation).
  5. Configure Trigger Parameters for Digital Edge Trigger.
  6. Configure Link Direction, Frequency Range, Carrier Bandwidthand Subcarrier Spacing.
  7. Select TXP measurement and enable Traces.
  8. Configure Measurement Offset & Measurement Length Parameters and Averaging Parameters for TXP
     measurement.
  9. Initiate the Measurement.
  10. Fetch TXP Measurements and Traces.
  11. Close RFmx Session.

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
  > python txp-single-carrier.py <server_address> <port_number> <resource_name>
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
                frequency_reference_frequency=10e6,
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
        client.CfgRF(
            nirfmxnr_types.CfgRFRequest(
                instrument=instr,
                selector_string="",
                center_frequency=3.5e9,
                reference_level=0.0,
                external_attenuation=0.0,
            )
        )
    )
    raise_if_error(
        client.CfgDigitalEdgeTrigger(
            nirfmxnr_types.CfgDigitalEdgeTriggerRequest(
                instrument=instr,
                selector_string="",
                digital_edge_source_mapped=nirfmxnr_types.DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0,
                digital_edge=nirfmxnr_types.DIGITAL_EDGE_TRIGGER_EDGE_RISING,
                trigger_delay=0.0,
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

    raise_if_error(
        client.SelectMeasurements(
            nirfmxnr_types.SelectMeasurementsRequest(
                instrument=instr,
                selector_string="",
                measurements=nirfmxnr_types.MEASUREMENT_TYPES_TXP,
                enable_all_traces=True,
            )
        )
    )

    raise_if_error(
        client.SetAttributeF64(
            nirfmxnr_types.SetAttributeF64Request(
                instrument=instr,
                selector_string="",
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_TXP_MEASUREMENT_INTERVAL,
                attr_val=1.0e-3,
            )
        )
    )
    raise_if_error(
        client.SetAttributeF64(
            nirfmxnr_types.SetAttributeF64Request(
                instrument=instr,
                selector_string="",
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_TXP_MEASUREMENT_OFFSET,
                attr_val=0.0,
            )
        )
    )

    raise_if_error(
        client.SetAttributeI32(
            nirfmxnr_types.SetAttributeI32Request(
                instrument=instr,
                selector_string="",
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_TXP_AVERAGING_ENABLED,
                attr_val_raw=nirfmxnr_types.NIRFMXNR_INT32_TXP_AVERAGING_ENABLED_TRUE,
            )
        )
    )
    raise_if_error(
        client.SetAttributeI32(
            nirfmxnr_types.SetAttributeI32Request(
                instrument=instr,
                selector_string="",
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_TXP_AVERAGING_COUNT,
                attr_val_raw=10,
            )
        )
    )

    raise_if_error(
        client.Initiate(
            nirfmxnr_types.InitiateRequest(instrument=instr, selector_string="", result_name="")
        )
    )

    ### Fetch results ###

    txp_fetch_measurement_response = raise_if_error(
        client.TXPFetchMeasurement(
            nirfmxnr_types.TXPFetchMeasurementRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    avearge_power_mean = txp_fetch_measurement_response.average_power_mean
    peak_power_maximum = txp_fetch_measurement_response.peak_power_maximum

    txp_fetch_power_trace_response = raise_if_error(
        client.TXPFetchPowerTrace(
            nirfmxnr_types.TXPFetchPowerTraceRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    x0 = txp_fetch_power_trace_response.x0
    dx = txp_fetch_power_trace_response.dx
    power = txp_fetch_power_trace_response.power

    print("\n------------Measurement------------\n")
    print(f"Average Power Mean (dBm) : {avearge_power_mean}")
    print(f"Peak Power Maximum (dBm) : {peak_power_maximum}")
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
