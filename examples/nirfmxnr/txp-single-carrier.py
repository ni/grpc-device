# Steps:
# 1. Open a new RFmx Session.
# 2. Configure Frequency Reference.
# 3. Configure Selected Ports.
# 4. Configure basic signal properties(Center Frequency, Reference Level and External Attenuation).
# 5. Configure Trigger Parameters for Digital Edge Trigger.
# 6. Configure Link Direction, Frequency Range, Carrier Bandwidthand Subcarrier Spacing.
# 7. Select TXP measurement and enable Traces.
# 8. Configure Measurement Offset & Measurement Length Parameters and Averaging Parameters for TXP measurement.
# 9. Initiate the Measurement.
# 10. Fetch TXP Measurements and Traces.
# 11. Close RFmx Session.

import sys

import grpc
import nirfmxnr_pb2 as nirfmxnr_types
import nirfmxnr_pb2_grpc as grpc_nirfmxnr

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
client = grpc_nirfmxnr.NiRFmxNRStub(channel)
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
    center_frequency = 3.5e9  # (Hz)
    reference_level = 0.0  # (dBm)
    external_attenuation = 0.0  # (dB)

    frequency_reference_source = nirfmxnr_types.FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK
    frequency_reference_frequency = 10e6  # (Hz)

    digital_trigger_enabled = False
    digital_edge_source = nirfmxnr_types.DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0
    trigger_delay = 0.0  # (s)
    digital_edge = nirfmxnr_types.DIGITAL_EDGE_TRIGGER_EDGE_RISING_EDGE

    link_direction = nirfmxnr_types.NIRFMXNR_INT32_LINK_DIRECTION_UPLINK

    frequency_range = nirfmxnr_types.NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1

    carrier_bandwidth = 100e6  # (Hz)
    subcarrier_spacing = 30e3  # (Hz)

    measurement_offset = 0.0  # (s)
    measurement_length = 1.0e-3  # (s)

    averaging_enabled = nirfmxnr_types.NIRFMXNR_INT32_TXP_AVERAGING_ENABLED_TRUE
    averaging_count = 10

    timeout = 10.0  # (s)

    avearge_power_mean = 0.0  # (dBm)
    peak_power_maximum = 0.0  # (dBm)

    actual_array_size = 0
    array_size = 0
    x0 = 0.0
    dx = 0.0
    power = None

    # Initialize a session
    initialize_response = client.Initialize(
        nirfmxnr_types.InitializeRequest(
            session_name=session_name, resource_name=resource, option_string=""
        )
    )
    instr = initialize_response.instrument
    client.CfgFrequencyReference(
        nirfmxnr_types.CfgFrequencyReferenceRequest(
            instrument=instr,
            channel_name="",
            frequency_reference_source_mapped=frequency_reference_source,
            frequency_reference_frequency=frequency_reference_frequency,
        )
    )
    client.SetAttributeString(
        nirfmxnr_types.SetAttributeStringRequest(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_SELECTED_PORTS,
            attr_val_raw=selected_ports,
        )
    )
    client.CfgRF(
        nirfmxnr_types.CfgRFRequest(
            instrument=instr,
            selector_string="",
            center_frequency=center_frequency,
            reference_level=reference_level,
            external_attenuation=external_attenuation,
        )
    )
    client.CfgDigitalEdgeTrigger(
        nirfmxnr_types.CfgDigitalEdgeTriggerRequest(
            instrument=instr,
            selector_string="",
            digital_edge_source_mapped=digital_edge_source,
            digital_edge=digital_edge,
            trigger_delay=trigger_delay,
            enable_trigger=digital_trigger_enabled,
        )
    )

    client.SetAttributeI32(
        nirfmxnr_types.SetAttributeI32Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_LINK_DIRECTION,
            attr_val_raw=link_direction,
        )
    )
    client.SetAttributeI32(
        nirfmxnr_types.SetAttributeI32Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE,
            attr_val_raw=frequency_range,
        )
    )
    client.SetAttributeF64(
        nirfmxnr_types.SetAttributeF64Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH,
            attr_val=carrier_bandwidth,
        )
    )
    client.SetAttributeF64(
        nirfmxnr_types.SetAttributeF64Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING,
            attr_val=subcarrier_spacing,
        )
    )

    client.SelectMeasurements(
        nirfmxnr_types.SelectMeasurementsRequest(
            instrument=instr,
            selector_string="",
            measurements=nirfmxnr_types.MEASUREMENT_TYPES_TXP,
            enable_all_traces=True,
        )
    )

    client.SetAttributeF64(
        nirfmxnr_types.SetAttributeF64Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_TXP_MEASUREMENT_INTERVAL,
            attr_val=measurement_length,
        )
    )
    client.SetAttributeF64(
        nirfmxnr_types.SetAttributeF64Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_TXP_MEASUREMENT_OFFSET,
            attr_val=measurement_offset,
        )
    )

    client.SetAttributeI32(
        nirfmxnr_types.SetAttributeI32Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_TXP_AVERAGING_ENABLED,
            attr_val_raw=averaging_enabled,
        )
    )
    client.SetAttributeI32(
        nirfmxnr_types.SetAttributeI32Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_TXP_AVERAGING_COUNT,
            attr_val_raw=averaging_count,
        )
    )

    client.Initiate(
        nirfmxnr_types.InitiateRequest(instrument=instr, selector_string="", result_name="")
    )

    # Fetch results

    txp_fetch_measurement_response = client.TXPFetchMeasurement(
        nirfmxnr_types.TXPFetchMeasurementRequest(
            instrument=instr, selector_string="", timeout=timeout
        )
    )
    avearge_power_mean = txp_fetch_measurement_response.average_power_mean
    peak_power_maximum = txp_fetch_measurement_response.peak_power_maximum

    txp_fetch_power_trace_response = client.TXPFetchPowerTrace(
        nirfmxnr_types.TXPFetchPowerTraceRequest(
            instrument=instr, selector_string="", timeout=timeout
        )
    )
    x0 = txp_fetch_power_trace_response.x0
    dx = txp_fetch_power_trace_response.dx
    power = txp_fetch_power_trace_response.power

    print("\n------------Measurement------------\n\n")
    print(f"Average Power Mean (dBm) : {avearge_power_mean}\n")
    print(f"Peak Power Maximum (dBm) : {peak_power_maximum}\n")
finally:
    if instr:
        client.Close(nirfmxnr_types.CloseRequest(instrument=instr, force_destroy=False))
