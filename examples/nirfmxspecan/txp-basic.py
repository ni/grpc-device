# Steps:
# 1. Open a new RFmx session
# 2. Configure Selected Ports
# 3. Configure the basic signal properties  (Center Frequency, Reference Level and External Attenuation)
# 4. Configure TXP rbw
# 5. Configure TXP Measurement Interval
# 6. Configure TXP Averaging
# 7. Read TXP Measurement Results
# 8. Close the RFmx Session
#
# The gRPC API is built from the C API. RFmx SpecAn documentation is installed with the driver at:
# C:\Program Files (x86)\National Instruments\RFmx\SpecAn\Documentation\rfmxspecancvi.chm
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
#   > python txp-basic.py <server_address> <port_number> <physical_channel_name>
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


# Raise an exception if an error was returned
def raise_if_error(response):
    if response.status != 0:
        error_response = client.GetError(
            nirfmxspecan_types.GetErrorRequest(
                instrument=instr,
            )
        )
        if response.status < 0:
            raise RuntimeError(f"Error: {error_response.error_description or response.status}")
        else:
            sys.stderr.write(f"Warning: {error_response.error_description or response.status}\n")

    return response


try:
    initialize_response = raise_if_error(
        client.Initialize(
            nirfmxspecan_types.InitializeRequest(
                session_name=session_name, resource_name=resource, option_string=options
            )
        )
    )
    instr = initialize_response.instrument

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
        client.CfgRF(
            nirfmxspecan_types.CfgRFRequest(
                instrument=instr,
                selector_string="",
                center_frequency=1e9,
                reference_level=0.00,
                external_attenuation=0.00,
            )
        )
    )
    raise_if_error(
        client.TXPCfgMeasurementInterval(
            nirfmxspecan_types.TXPCfgMeasurementIntervalRequest(
                instrument=instr, selector_string="", measurement_interval=1e-3
            )
        )
    )
    raise_if_error(
        client.TXPCfgRBWFilter(
            nirfmxspecan_types.TXPCfgRBWFilterRequest(
                instrument=instr,
                selector_string="",
                rbw=100e3,
                rbw_filter_type=nirfmxspecan_types.TXP_RBW_FILTER_TYPE_GAUSSIAN,
                rrc_alpha=0.1,
            )
        )
    )
    raise_if_error(
        client.TXPCfgAveraging(
            nirfmxspecan_types.TXPCfgAveragingRequest(
                instrument=instr,
                selector_string="",
                averaging_enabled=nirfmxspecan_types.TXP_AVERAGING_ENABLED_FALSE,
                averaging_count=10,
                averaging_type=nirfmxspecan_types.TXP_AVERAGING_TYPE_RMS,
            )
        )
    )

    ### Fetch measurement data ###

    txp_read_response = raise_if_error(
        client.TXPRead(
            nirfmxspecan_types.TXPReadRequest(instrument=instr, selector_string="", timeout=10.0)
        )
    )
    minimum_power = txp_read_response.minimum_power
    maximum_power = txp_read_response.maximum_power
    peak_to_average_ratio = txp_read_response.peak_to_average_ratio
    average_mean_power = txp_read_response.average_mean_power

    print(f"Average Mean Power(dBm)    {average_mean_power}")
    print(f"Peak to Average Ratio(dB)  {peak_to_average_ratio}")
    print(f"Maximum Power(dBm)         {maximum_power}")
    print(f"Minimum Power(dBm)         {minimum_power}")
finally:
    if instr:
        client.Close(nirfmxspecan_types.CloseRequest(instrument=instr, force_destroy=False))
