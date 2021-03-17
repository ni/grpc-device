###############################################################
#
# Copyright 2020 National Instruments
#
# Licensed under the MIT license
#
# This is an example of using the niScope driver through gRPC
# Tested with a 100 kHz tone input to channel 0
# The gRPC API is built from the C API.  NI-SCOPE documentation is found:
# C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niScope\Documentation\scopeFunc.chm
#
# Getting Started:
#
# Install the gRPC tools for Python
#     > pip install grpcio-tools
#   if you are using anaconda
#     > conda install grpcio-tools
#
# Generate the python API from the gRPC definition (.ptoto) files
#   > python -m grpc_tools.protoc -I. --python_out=. --grpc_python_out=. ./session.proto
#   > python -m grpc_tools.protoc -I. --python_out=. --grpc_python_out=. ./niscope.proto
#
# Update the server address and resource name and options in this file
# Run the code to read a waveform from the scope

import grpc
import niScope_pb2 as scope_types
import niScope_pb2_grpc as gRPC_scope
import matplotlib.pyplot as plt
import time
import sys

def check_status(scope_service, result):
    if (result.status != 0):
        error = scope_service.GetError(scope_types.GetErrorRequest())
        print(error.description)

# Server machine's IP address and port number have to be passed as two separate command line arguments.
#   > python EnumerateDevice.py localhost 31763
# If not passed as command line arguments, then by default server address would be "localhost:31763"
server_address = "localhost:31763"
if len(sys.argv) == 3 :
    server_address = f"{sys.argv[1]}:{sys.argv[2]}"

# Resource name and options for a simulated 5164 scope
resource = "SimulatedScope7c632f66-e7c2-4fab-85a4-cd15c8be4130"
options = "Simulate=1, DriverSetup=Model:5164; BoardType:PXIe; MemorySize:1610612736"

# Or use real hardware
# resource = "Scope"
# options = ""

# Create the communication channel for the remote host (in this case we are connecting to a local server)
# and create a connection to the niScope service
channel = grpc.insecure_channel(server_address)
scope_service = gRPC_scope.NiScopeStub(channel)

# Initialize the scope
init_result = scope_service.InitWithOptions(scope_types.InitWithOptionsRequest(
    session_name = "demo",
    resource_name = resource, 
    id_query = False, 
    option_string = options
    ))
vi = init_result.vi
check_status(scope_service, init_result)

#############################################################################################
# Configure Vertical
vertical_result = scope_service.ConfigureVertical(scope_types.ConfigureVerticalRequest(
    vi = vi,
    channel_list = "0",
    range = 10.0,
    offset = 0,
    coupling = scope_types.VerticalCoupling.VERTICAL_COUPLING_NISCOPE_VAL_DC,
    enabled = True,
    probe_attenuation = 1
    ))
check_status(scope_service, vertical_result)

##############################################################################################
# Configure Horizontal Timing
config_result = scope_service.ConfigureHorizontalTiming(scope_types.ConfigureHorizontalTimingRequest(
    vi = vi,
    min_sample_rate = 1000000,
    min_num_pts = 1000,
    ref_position = 50,
    num_records = 1,
    enforce_realtime = True
    ))
check_status(scope_service, config_result)

##############################################################################################
# Setup an Edge Trigger
result = scope_service.SetAttributeViInt32(scope_types.SetAttributeViInt32Request(
    vi = vi,
    attribute_id = scope_types.NiScopeAttributes.NISCOPE_ATTRIBUTE_TRIGGER_TYPE,
    value = scope_types.TriggerType.TRIGGER_TYPE_NISCOPE_VAL_EDGE_TRIGGER
))
check_status(scope_service, result)

conf_trigger_edge_result = scope_service.ConfigureTriggerEdge(scope_types.ConfigureTriggerEdgeRequest(
    vi = vi,
    trigger_source = "0",
    level = 0.00,
    slope = scope_types.TriggerSlope.TRIGGER_SLOPE_NISCOPE_VAL_POSITIVE,
    trigger_coupling = scope_types.TriggerCoupling.TRIGGER_COUPLING_NISCOPE_VAL_DC,
    holdoff = 0.0
))
check_status(scope_service, conf_trigger_edge_result)

result = scope_service.SetAttributeViInt32(scope_types.SetAttributeViInt32Request(
    vi = vi,
    channel_list = "0",
    attribute_id = scope_types.NiScopeAttributes.NISCOPE_ATTRIBUTE_MEAS_REF_LEVEL_UNITS,
    value = scope_types.RefLevelUnits.REF_LEVEL_UNITS_NISCOPE_VAL_PERCENTAGE
))
check_status(scope_service, result)

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
        read_result = scope_service.Read(scope_types.ReadRequest(
            vi = vi,
            channel_list = "0",
            timeout = 1,
            num_samples = 10000
        ))
        check_status(scope_service, read_result)
        values = read_result.waveform[0:10]
        print(values)

        # Update the plot with the new waveform
        plt.plot(read_result.waveform[0:100])
        fig.canvas.draw()
        plt.pause(0.001)

        # Fetch the measured average frequency
        fetch_result = scope_service.FetchMeasurementStats(scope_types.FetchMeasurementStatsRequest(
            vi = vi,
            channel_list = "0",
            timeout = 1,
            scalar_meas_function = scope_types.ScalarMeasurement.SCALAR_MEASUREMENT_NISCOPE_VAL_AVERAGE_FREQUENCY
        ))
        check_status(scope_service, fetch_result)
        print("Average Frequency: " + str("%.2f" % round(fetch_result.result[0], 2)) + " Hz")
        print("")

        time.sleep(0.1)
except KeyboardInterrupt:
    pass

##############################################################################################
# Close
scope_service.Close(scope_types.CloseRequest(
    vi = vi
))
