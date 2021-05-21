#
# This is an example of plotting waveforms read from an NI-SCOPE device through gRPC
# Tested with a 100 kHz tone input to channel 0
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
#   > python graph-measurement.py <server_address> <port_number> <resource_name>
# If they are not passed in as command line arguments, then by default the server address will be "localhost:31763", with "SimulatedScope" as the resource name


import grpc
import niscope_pb2 as niscope_types
import niscope_pb2_grpc as grpc_scope
import matplotlib.pyplot as plt
import time
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

# Create the communication channel for the remote host (in this case we are connecting to a local server)
# and create a connection to the NI-SCOPE service
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

# Configure Vertical
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

# Configure Horizontal Timing
config_result = scope_service.ConfigureHorizontalTiming(niscope_types.ConfigureHorizontalTimingRequest(
    vi = vi,
    min_sample_rate = 1000000,
    min_num_pts = 1000,
    ref_position = 50,
    num_records = 1,
    enforce_realtime = True
    ))
CheckStatus(scope_service, vi, config_result)

# Setup an Edge Trigger
result = scope_service.SetAttributeViInt32(niscope_types.SetAttributeViInt32Request(
    vi = vi,
    attribute_id = niscope_types.NiScopeAttributes.NISCOPE_ATTRIBUTE_TRIGGER_TYPE,
    value = niscope_types.NiScopeInt32AttributeValues.NISCOPE_INT32_VAL_TRIGGER_TYPE_EDGE_TRIGGER
))
CheckStatus(scope_service, vi, result)

conf_trigger_edge_result = scope_service.ConfigureTriggerEdge(niscope_types.ConfigureTriggerEdgeRequest(
    vi = vi,
    trigger_source = channels,
    level = 0.00,
    slope = niscope_types.TriggerSlope.TRIGGER_SLOPE_NISCOPE_VAL_POSITIVE,
    trigger_coupling = niscope_types.TriggerCoupling.TRIGGER_COUPLING_NISCOPE_VAL_DC,
    holdoff = 0.0
))
CheckStatus(scope_service, vi, conf_trigger_edge_result)

result = scope_service.SetAttributeViInt32(niscope_types.SetAttributeViInt32Request(
    vi = vi,
    channel_list = channels,
    attribute_id = niscope_types.NiScopeAttributes.NISCOPE_ATTRIBUTE_MEAS_REF_LEVEL_UNITS,
    value = niscope_types.NiScopeInt32AttributeValues.NISCOPE_INT32_VAL_REF_LEVEL_UNITS_PERCENTAGE
))
CheckStatus(scope_service, vi, result)

# Setup a plot to draw the captured waveform
fig = plt.gcf()
fig.show()
fig.canvas.draw()

print("\nReading values in loop. CTRL+C to stop.\n")
try:
    while True:
        # Clear the plot and setup the axis
        plt.clf()
        plt.axis([0, 100, -6, 6])
        # Read a waveform from the scope
        read_result = scope_service.Read(niscope_types.ReadRequest(
            vi = vi,
            channel_list = channels,
            timeout = 1,
            num_samples = 10000
        ))
        CheckStatus(scope_service, vi, read_result)
        values = read_result.waveform[0:10]
        print(values)

        # Update the plot with the new waveform
        plt.plot(read_result.waveform[0:100])
        fig.canvas.draw()
        plt.pause(0.001)

        # Fetch the measured average frequency
        fetch_result = scope_service.FetchMeasurementStats(niscope_types.FetchMeasurementStatsRequest(
            vi = vi,
            channel_list = channels,
            timeout = 1,
            scalar_meas_function = niscope_types.ScalarMeasurement.SCALAR_MEASUREMENT_NISCOPE_VAL_AVERAGE_FREQUENCY
        ))
        CheckStatus(scope_service, vi, fetch_result)
        print("Average Frequency: " + str("%.2f" % round(fetch_result.result[0], 2)) + " Hz")
        print("")

        time.sleep(0.1)
except KeyboardInterrupt:
    pass

# Close
scope_service.Close(niscope_types.CloseRequest(
    vi = vi
))
channel.close()
