r"""ADemod AM example.

Steps:
1. Open a new RFmxInstrMX session and create a Demod Signal
2. Configure Selected Ports
3. Configure basic signal properties (Center Frequency, Reference Level and External Attenuation)
4. Configure ADemod rbw, Measurement Interval, AM Carrier Suppressed and Averaging
5. Read ADemod AM Measurement Results
6. Dispose Demod Signal and Close the RFmxInstrMX Session

The gRPC API is built from the C API. RFmx Demod documentation is installed with the driver at:
C:\Program Files (x86)\National Instruments\RFmx\Demod\Documentation\demodcvi.chm

Getting Started:

To run this example, install "RFmx Demod" on the server machine.
Link: https://www.ni.com/en-us/support/downloads/software-products/download.rfmx-demod.html

For instructions on how to use protoc to generate gRPC client interfaces, see our
"Creating a gRPC Client" wiki page.
Link: https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-RFmxDemod gRPC Wiki for the latest C Function Reference:
Link: https://github.com/ni/grpc-device/wiki/NI-RFmxDemod-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and physical channel name can be passed as separate
command line arguments.
  > python ADemod-AM-basic.py <server_address> <port_number> <physical_channel_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedDevice" as the resource name
"""


import sys

import grpc
import nirfmxdemod_pb2 as nirfmxdemod_types
import nirfmxdemod_pb2_grpc as grpc_nirfmxdemod

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "RFmxDemodSession"

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
client = grpc_nirfmxdemod.NiRFmxDemodStub(channel)
instr = None


def check_for_warning(response, instrument):
    """Print to console if the status indicates a warning."""
    if response.status > 0:
        warning_message = client.GetErrorString(
            nirfmxdemod_types.GetErrorStringRequest(
                instrument=instrument,
                error_code=response.status,
            )
        )
        sys.stderr.write(
            f"{warning_message.error_description}\nWarning status: {response.status}\n"
        )


try:
    # Create a new RFmx Session
    initialize_response = client.Initialize(
        nirfmxdemod_types.InitializeRequest(
            session_name=SESSION_NAME, resource_name=RESOURCE, option_string=OPTIONS
        )
    )
    instr = initialize_response.instrument

    # Configure ADemod measurement parameters
    client.SetAttributeString(
        nirfmxdemod_types.SetAttributeStringRequest(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxdemod_types.NIRFMXDEMOD_ATTRIBUTE_SELECTED_PORTS,
            attr_val_raw="",
        )
    )
    client.CfgRF(
        nirfmxdemod_types.CfgRFRequest(
            instrument=instr,
            selector_string="",
            center_frequency=1e9,
            reference_level=0.00,
            external_attenuation=0.00,
        )
    )
    client.ADemodCfgRBWFilter(
        nirfmxdemod_types.ADemodCfgRBWFilterRequest(
            instrument=instr,
            selector_string="",
            rbw=100.00e3,
            rbw_filter_type=nirfmxdemod_types.A_DEMOD_RBW_FILTER_TYPE_FLAT,
            rbw_rrc_alpha=0.1,
        )
    )
    client.ADemodCfgMeasurementInterval(
        nirfmxdemod_types.ADemodCfgMeasurementIntervalRequest(
            instrument=instr, selector_string="", measurement_interval=10.00e-3
        )
    )
    client.ADemodCfgAMCarrierSuppressed(
        nirfmxdemod_types.ADemodCfgAMCarrierSuppressedRequest(
            instrument=instr,
            selector_string="",
            am_carrier_suppressed_enabled=nirfmxdemod_types.A_DEMOD_AM_CARRIER_SUPPRESSED_ENABLED_FALSE,
        )
    )
    client.ADemodCfgAveraging(
        nirfmxdemod_types.ADemodCfgAveragingRequest(
            instrument=instr,
            selector_string="",
            averaging_enabled=nirfmxdemod_types.A_DEMOD_AVERAGING_ENABLED_FALSE,
            averaging_count=10,
            averaging_type=nirfmxdemod_types.A_DEMOD_AVERAGING_TYPE_LINEAR,
        )
    )

    # Retrieve results
    a_demod_read_am_response = client.ADemodReadAM(
        nirfmxdemod_types.ADemodReadAMRequest(instrument=instr, selector_string="", timeout=10.0)
    )
    check_for_warning(a_demod_read_am_response, instr)
    mean_carrier_power = a_demod_read_am_response.mean_carrier_power
    mean_modulation_depth = a_demod_read_am_response.mean_modulation_depth

    # Display results
    print(f"Mean Modulation Depth (%%)   : {mean_modulation_depth}")
    print(f"Mean Carrier Power (dBm)    : {mean_carrier_power}")
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
        client.Close(nirfmxdemod_types.CloseRequest(instrument=instr, force_destroy=False))
