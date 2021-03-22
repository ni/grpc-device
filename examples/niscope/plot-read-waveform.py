#
# Example communication with NI-SCOPE over gRPC
#
# Getting Started:
#
# To run this example, install "NI-SCOPE Driver" on the server machine.
# Link : https://www.ni.com/en-us/support/downloads/drivers/download.ni-scope.html
#
# Install the gRPC tools for Python
#     > pip install grpcio-tools
#   if you are using anaconda
#     > conda install grpcio-tools
#
# Generate the python API from the gRPC definition (.proto) files
# Note: The snippets below assume you are executing from the examples/niscope folder in the repo directory. 
# If not, you will need to adjust the -I arguments so the compiler knows where to find the proto files.
#   > python -m grpc_tools.protoc -I="../../source/protobuf" --python_out=. --grpc_python_out=. session.proto
#   > python -m grpc_tools.protoc -I="../../generated/niscope" -I="../../source/protobuf" --python_out=. --grpc_python_out=. niscope.proto 
#
# Refer to the NI-SCOPE gRPC Wiki to determine the valid channel and resource names for your NI-SCOPE module.
# Link : https://github.com/ni/grpc-device/wiki/niScope_header
#
# Run the code to read a waveform from the scope
#

import grpc
import niscope_pb2 as niscope_types
import niscope_pb2_grpc as grpc_scope
import sys

def CheckStatus(scope_service, result):
    if (result.status != 0):
        error = scope_service.GetError(niscope_types.GetErrorRequest())
        print(error.description)

# Server machine's IP address and port number have to be passed as two separate command line arguments.
#   > python plot-read-waveform.py localhost 31763
# If not passed as command line arguments, then by default server address would be "localhost:31763" and a resource will be simulated
server_address = "localhost"
server_port = 31763
resource = "SimulatedScope"
options = "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe; MemorySize:1610612736"
if len(sys.argv) >= 3 :
    server_address = sys.argv[1]
    server_port = int(sys.argv[2])
    if (len(sys.argv) == 4):
        resource = sys.argv[3]
        options = ""

# Create the communcation channel for the remote host (in this case we are connecting to a local server)
# and create a connection to the niScope service
channel = grpc.insecure_channel(server_address)
scope_service = grpc_scope.NiScopeStub(channel)

# Initialize the scope
init_result = scope_service.InitWithOptions(niscope_types.InitWithOptionsRequest(
    session_name = "demo",
    resource_name = resource, 
    id_query = False, 
    option_string = options
    ))
vi = init_result.vi
CheckStatus(scope_service, init_result)

# Configure horizontal timing
config_result = scope_service.ConfigureHorizontalTiming(niscope_types.ConfigureHorizontalTimingRequest(
    vi = vi,
    min_sample_rate = 1000000,
    min_num_pts = 100000,
    ref_position = 50,
    num_records = 1,
    enforce_realtime = True
))
CheckStatus(scope_service, config_result)

# Configure vertical timing
vertical_result = scope_service.ConfigureVertical(niscope_types.ConfigureVerticalRequest(
    vi = vi,
    channel_list = "0",
    range = 30.0,
    offset = 0,
    coupling = niscope_types.VerticalCoupling.VERTICAL_COUPLING_NISCOPE_VAL_DC,
    enabled = True,
    probe_attenuation = 1
))
CheckStatus(scope_service, vertical_result)

confTrigger_edge_result = scope_service.ConfigureTriggerEdge(niscope_types.ConfigureTriggerEdgeRequest(
    vi = vi,
    trigger_source = "0",
    level = 0.00,
    trigger_coupling = niscope_types.TriggerCoupling.TRIGGER_COUPLING_NISCOPE_VAL_DC,
    slope = niscope_types.TriggerSlope.TRIGGER_SLOPE_NISCOPE_VAL_POSITIVE
))
CheckStatus(scope_service, confTrigger_edge_result)

result = scope_service.SetAttributeViInt32(niscope_types.SetAttributeViInt32Request(
    vi = vi,
    channel_list = "0",
    attribute_id = niscope_types.NiScopeAttributes.NISCOPE_ATTRIBUTE_MEAS_REF_LEVEL_UNITS,
    value = niscope_types.RefLevelUnits.REF_LEVEL_UNITS_NISCOPE_VAL_VOLTS
))
CheckStatus(scope_service, result)

# Read a waveform from the scope
read_result = scope_service.Read(niscope_types.ReadRequest(
    vi = vi,
    channel_list = "0",
    timeout = 10000,
    num_samples = 100000
))
CheckStatus(scope_service, read_result)
values = read_result.waveform[0:10]
print(values)

scope_service.Close(niscope_types.CloseRequest(
    vi = vi
))
