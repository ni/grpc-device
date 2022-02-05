# Steps:
# 1. Open a new RFmx session
# 2. Configure Selected Ports
# 3. Configure the basic signal properties  (Center Frequency, Reference Level and External Attenuation)
# 4. Configure TXP rbw
# 5. Configure TXP Measurement Interval
# 6. Configure TXP Averaging
# 7. Read TXP Measurement Results
# 8. Close the RFmx Session

import sys

import grpc
import nirfmxspecan_pb2 as nirfmxspecan_types
import nirfmxspecan_pb2_grpc as grpc_nirfmxspecan

server_address = "localhost"
server_port = "31763"
session_name = "NI-RFSASession"

# Resource name and options for a simulated 5663 client.
resource = "SimulatedRFSA"
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

# Maximum size of an error message
MAX_ERROR_DESCRIPTION = 4096


# Raise an exception if an error was returned
def raise_if_error(response):
    if response.status != 0:
        error_response = client.GetError(
            nirfmxspecan_types.GetErrorRequest(
                instrument=instr,
            )
        )
        raise Exception(f"Error: {error_response.error_description}")

    return response


try:
    selected_ports = ""
    center_frequency = 1e9  # Hz
    reference_level = 0.00  # dBm
    external_attenuation = 0.00  # dB

    timeout = 10.0  # seconds

    meas_interval = 1e-3  # seconds

    # rbw Filter
    rbw = 100e3
    rbw_filter_type = nirfmxspecan_types.TXP_RBW_FILTER_TYPE_GAUSSIAN
    rrc_alpha = 0.1

    # Averaging
    averaging_enabled = nirfmxspecan_types.TXP_AVERAGING_ENABLED_FALSE
    averaging_count = 10
    averaging_type = nirfmxspecan_types.TXP_AVERAGING_TYPE_RMS

    # Variables to store measurement data
    average_mean_power = 0.0
    peak_to_average_ratio = 0.0
    maximum_power = 0.0
    minimum_power = 0.0

    # Create a new RFmx Session
    initialize_response = client.Initialize(
        nirfmxspecan_types.InitializeRequest(
            session_name=session_name, resource_name=resource, option_string=""
        )
    )
    instr = initialize_response.instrument

    # Configure TXP parameters
    client.SetAttributeString(
        nirfmxspecan_types.SetAttributeStringRequest(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxspecan_types.NIRFMXSPECAN_ATTRIBUTE_SELECTED_PORTS,
            attr_val_raw=selected_ports,
        )
    )
    client.CfgRF(
        nirfmxspecan_types.CfgRFRequest(
            instrument=instr,
            selector_string="",
            center_frequency=center_frequency,
            reference_level=reference_level,
            external_attenuation=external_attenuation,
        )
    )
    client.TXPCfgMeasurementInterval(
        nirfmxspecan_types.TXPCfgMeasurementIntervalRequest(
            instrument=instr, selector_string="", measurement_interval=meas_interval
        )
    )
    client.TXPCfgRBWFilter(
        nirfmxspecan_types.TXPCfgRBWFilterRequest(
            instrument=instr,
            selector_string="",
            rbw=rbw,
            rbw_filter_type=rbw_filter_type,
            rrc_alpha=rrc_alpha,
        )
    )
    client.TXPCfgAveraging(
        nirfmxspecan_types.TXPCfgAveragingRequest(
            instrument=instr,
            selector_string="",
            averaging_enabled=averaging_enabled,
            averaging_count=averaging_count,
            averaging_type=averaging_type,
        )
    )

    # Fetch measurement data
    txp_read_response = client.TXPRead(
        nirfmxspecan_types.TXPReadRequest(instrument=instr, selector_string="", timeout=timeout)
    )
    minimum_power = txp_read_response.minimum_power
    maximum_power = txp_read_response.maximum_power
    peak_to_average_ratio = txp_read_response.peak_to_average_ratio
    average_mean_power = txp_read_response.average_mean_power

    # Display results
    print(f"Average Mean Power(dBm)    {average_mean_power}\n")
    print(f"Peak to Average Ratio(dB)  {peak_to_average_ratio}\n")
    print(f"Maximum Power(dBm)         {maximum_power}\n")
    print(f"Minimum Power(dBm)         {minimum_power}\n")
finally:
    if instr:
        client.Close(nirfmxspecan_types.CloseRequest(instrument=instr, force_destroy=False))
