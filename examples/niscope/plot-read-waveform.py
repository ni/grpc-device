#
# Example communication with NI-SCOPE over gRPC
#
# The gRPC API is built from the C API.  NI-SCOPE documentation is installed with the driver at:
# C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niScope\Documentation\English\Digitizers.chm
#
# A version of this .chm is available online at:
# Link: https://zone.ni.com/reference/en-XX/help/370592AB-01/
#
# Getting Started:
#
# To run this example, install "NI-SCOPE Driver" on the server machine.
# Link : https://www.ni.com/en-us/support/downloads/drivers/download.ni-scope.html
#
# For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC Client" wiki page.
# Link: https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client
#
# Refer to the NI-SCOPE gRPC Wiki to determine the valid channel and resource names for your NI-SCOPE module.
# Link : https://github.com/ni/grpc-device/wiki/NI-SCOPE-C-Function-Reference
#
# Running from command line:
#
# Server machine's IP address, port number, and resource name can be passed as separate command line arguments.
#   > python plot-read-waveform.py <server_address> <port_number> <resource_name>
# If they are not passed in as command line arguments, then by default the server address will be "localhost:31763", with "SimulatedScope" as the resource name

import grpc
import niscope_pb2 as niscope_types
import niscope_pb2_grpc as grpc_scope
import sys

server_address = "localhost"
server_port = "31763"

# Resource name and options for a simulated 5164 client. Change them according to the NI-SCOPE model.
resource = "SimulatedScope"
options = "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe; MemorySize:1610612736"

channels = "0"

def CheckStatus(scope_service, vi, result):
    if (result.status != 0):
        error_result = scope_service.GetErrorMessage(niscope_types.GetErrorMessageRequest(vi = vi, error_code = result.status))
        print(error_result.error_message)
        exit()

# Read in cmd args
if len(sys.argv) >= 2:
    server_address = sys.argv[1]
if len(sys.argv) >= 3:
    server_port = sys.argv[2]
if len(sys.argv) >= 4:
    resource = sys.argv[3]
    options = ""

# Create the communcation channel for the remote host (in this case we are connecting to a local server)
# and create a connection to the niScope service
channel = grpc.insecure_channel(f"{server_address}:{server_port}")
scope_service = grpc_scope.NiScopeStub(channel)

# Initialize the scope
init_result = scope_service.InitWithOptions(niscope_types.InitWithOptionsRequest(
    session_name = "demo",
    resource_name = resource, 
    id_query = False, 
    option_string = options
    ))
vi = init_result.vi
CheckStatus(scope_service, vi, init_result)

# Configure horizontal timing
config_result = scope_service.ConfigureHorizontalTiming(niscope_types.ConfigureHorizontalTimingRequest(
    vi = vi,
    min_sample_rate = 1000000,
    min_num_pts = 100000,
    ref_position = 50,
    num_records = 1,
    enforce_realtime = True
))
CheckStatus(scope_service, vi, config_result)

# Configure vertical timing
vertical_result = scope_service.ConfigureVertical(niscope_types.ConfigureVerticalRequest(
    vi = vi,
    channel_list = channels,
    range = 10.0,
    offset = 0,
    coupling = niscope_types.VerticalCoupling.VERTICAL_COUPLING_NISCOPE_VAL_DC,
    enabled = True,
    probe_attenuation = 1
))
CheckStatus(scope_service, vi, vertical_result)

confTrigger_edge_result = scope_service.ConfigureTriggerEdge(niscope_types.ConfigureTriggerEdgeRequest(
    vi = vi,
    trigger_source = channels,
    level = 0.00,
    trigger_coupling = niscope_types.TriggerCoupling.TRIGGER_COUPLING_NISCOPE_VAL_DC,
    slope = niscope_types.TriggerSlope.TRIGGER_SLOPE_NISCOPE_VAL_POSITIVE
))
CheckStatus(scope_service, vi, confTrigger_edge_result)

result = scope_service.SetAttributeViInt32(niscope_types.SetAttributeViInt32Request(
    vi = vi,
    channel_list = channels,
    attribute_id = niscope_types.NiScopeAttributes.NISCOPE_ATTRIBUTE_MEAS_REF_LEVEL_UNITS,
    value = niscope_types.NiScopeInt32AttributeValues.NISCOPE_INT32_REF_LEVEL_UNITS_VAL_VOLTS
))
CheckStatus(scope_service, vi, result)

# Read a waveform from the scope
read_result = scope_service.Read(niscope_types.ReadRequest(
    vi = vi,
    channel_list = channels,
    timeout = 10000,
    num_samples = 100000
))
CheckStatus(scope_service, vi, read_result)
values = read_result.waveform[0:10]
print(values)

scope_service.Close(niscope_types.CloseRequest(
    vi = vi
))
channel.close()
