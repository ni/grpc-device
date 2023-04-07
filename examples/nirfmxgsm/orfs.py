r"""ORFS example.

Steps:
1. Open a new RFmx Session.
2. Configure Frequency Reference.
3. Configure External Attenuation.
4. Configure Center Frequency.
5. Configure Link Direction.
6. Configure Trigger Parameters for IQ Power Edge Trigger.
7. Configure Number of Timeslots.
8. Configure Signal Type.
9. Configure Auto Level.
10. Configure Auto tsc Detection Enabled.
11. Configure tsc.
12. Select  ORFS  measurement and enable Traces.
13. Configure Noise Compensation Enabled.
14. Configure Measurement Type.
15. Configure Offset Frequency Mode.
16. Configure Evaluation Symbols.
17. Configure Averaging Parameters.
18. Initiate the Measurement.
19. Fetch ORFS Measurements and Traces.
20. Close RFmx Session.

The gRPC API is built from the C API. RFmx GSM documentation is installed with the driver at:
C:\Program Files (x86)\National Instruments\RFmx\GSM\Documentation\rfmxgsmcvi.chm

Getting Started:

To run this example, install "RFmx GSM" on the server machine.
Link: https://www.ni.com/en-us/support/downloads/software-products/download.rfmx-gsm-edge-.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page.
Link: https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-RFmx GSM gRPC Wiki for the latest C Function Reference:
Link: https://github.com/ni/grpc-device/wiki/NI-RFmx-GSM-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and physical channel name can be passed as separate
command line arguments.
  > python orfs.py <server_address> <port_number> <physical_channel_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedDevice" as the resource name
"""

import sys

import grpc
import nirfmxgsm_pb2 as nirfmxgsm_types
import nirfmxgsm_pb2_grpc as grpc_nirfmxgsm

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "RFmxGSMSession"

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
client = grpc_nirfmxgsm.NiRFmxGSMStub(channel)
instr = None


def check_for_warning(response, instrument):
    """Print to console if the status indicates a warning."""
    if response.status > 0:
        warning_message = client.GetErrorString(
            nirfmxgsm_types.GetErrorStringRequest(
                instrument=instrument,
                error_code=response.status,
            )
        )
        sys.stderr.write(
            f"{warning_message.error_description}\nWarning status: {response.status}\n"
        )


try:
    auto_level = True

    mod_lower_absolute_power = None
    mod_upper_absolute_power = None
    mod_lower_relative_power = None
    mod_upper_relative_power = None

    switch_lower_absolute_power = None
    switch_upper_absolute_power = None
    switch_lower_relative_power = None
    switch_upper_relative_power = None

    mod_offset_frequency = None
    mod_absolute_power = None
    mod_relative_power = None
    switch_offset_frequency = None
    switch_absolute_power = None
    switch_relative_power = None
    actual_array_size = 0

    initialize_response = client.Initialize(
        nirfmxgsm_types.InitializeRequest(
            session_name=SESSION_NAME, resource_name=RESOURCE, option_string=OPTIONS
        )
    )
    instr = initialize_response.instrument
    client.CfgFrequencyReference(
        nirfmxgsm_types.CfgFrequencyReferenceRequest(
            instrument=instr,
            channel_name="",
            frequency_reference_source_mapped=nirfmxgsm_types.FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK,
            frequency_reference_frequency=10e6,
        )
    )
    client.CfgExternalAttenuation(
        nirfmxgsm_types.CfgExternalAttenuationRequest(
            instrument=instr, selector_string="", external_attenuation=0.0
        )
    )
    client.CfgFrequency(
        nirfmxgsm_types.CfgFrequencyRequest(
            instrument=instr, selector_string="", center_frequency=890.2e6
        )
    )
    client.CfgLinkDirection(
        nirfmxgsm_types.CfgLinkDirectionRequest(
            instrument=instr,
            selector_string="",
            link_direction=nirfmxgsm_types.LINK_DIRECTION_UPLINK,
        )
    )
    client.CfgIQPowerEdgeTrigger(
        nirfmxgsm_types.CfgIQPowerEdgeTriggerRequest(
            instrument=instr,
            selector_string="",
            iq_power_edge_source="0",
            iq_power_edge_slope=nirfmxgsm_types.IQ_POWER_EDGE_TRIGGER_SLOPE_RISING,
            iq_power_edge_level=-20.0,
            trigger_delay=0.0,
            minimum_quiet_time_mode=nirfmxgsm_types.TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO,
            minimum_quiet_time=582e-6,
            iq_power_edge_level_type=nirfmxgsm_types.IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE,
            enable_trigger=True,
        )
    )
    client.CfgNumberOfTimeslots(
        nirfmxgsm_types.CfgNumberOfTimeslotsRequest(
            instrument=instr, selector_string="", number_of_timeslots=1
        )
    )

    client.CfgSignalType(
        nirfmxgsm_types.CfgSignalTypeRequest(
            instrument=instr,
            selector_string="slot::all",
            modulation_type=nirfmxgsm_types.MODULATION_TYPE_8PSK,
            burst_type=nirfmxgsm_types.BURST_TYPE_NB,
            hb_filter_width=nirfmxgsm_types.HB_FILTER_WIDTH_NARROW,
        )
    )

    if auto_level:
        auto_level_response = client.AutoLevel(
            nirfmxgsm_types.AutoLevelRequest(
                instrument=instr, selector_string="", measurement_interval=0.0046
            )
        )
        auto_reference_level = auto_level_response.reference_level
        print(f"Reference Level                     : {auto_reference_level}\n")
    else:
        client.CfgReferenceLevel(
            nirfmxgsm_types.CfgReferenceLevelRequest(
                instrument=instr, selector_string="", reference_level=0.0
            )
        )

    client.CfgAutoTSCDetectionEnabled(
        nirfmxgsm_types.CfgAutoTSCDetectionEnabledRequest(
            instrument=instr,
            selector_string="",
            auto_tsc_detection_enabled=nirfmxgsm_types.AUTO_TSC_DETECTION_ENABLED_TRUE,
        )
    )
    client.CfgTSC(
        nirfmxgsm_types.CfgTSCRequest(
            instrument=instr, selector_string="slot::all", tsc=nirfmxgsm_types.TSC_TSC0
        )
    )
    client.SelectMeasurements(
        nirfmxgsm_types.SelectMeasurementsRequest(
            instrument=instr,
            selector_string="",
            measurements_raw=nirfmxgsm_types.MEASUREMENT_TYPES_ORFS,
            enable_all_traces=True,
        )
    )
    client.ORFSCfgNoiseCompensationEnabled(
        nirfmxgsm_types.ORFSCfgNoiseCompensationEnabledRequest(
            instrument=instr,
            selector_string="",
            noise_compensation_enabled=nirfmxgsm_types.ORFS_NOISE_COMPENSATION_ENABLED_FALSE,
        )
    )
    client.ORFSCfgMeasurementType(
        nirfmxgsm_types.ORFSCfgMeasurementTypeRequest(
            instrument=instr,
            selector_string="",
            measurement_type=nirfmxgsm_types.ORFS_MEASUREMENT_TYPE_MODULATION_AND_SWITCHING,
        )
    )
    client.ORFSCfgOffsetFrequencyMode(
        nirfmxgsm_types.ORFSCfgOffsetFrequencyModeRequest(
            instrument=instr,
            selector_string="",
            offset_frequency_mode=nirfmxgsm_types.ORFS_OFFSET_FREQUENCY_MODE_STANDARD,
        )
    )
    client.ORFSCfgEvaluationSymbols(
        nirfmxgsm_types.ORFSCfgEvaluationSymbolsRequest(
            instrument=instr,
            selector_string="",
            evaluation_symbols_start=50.0,
            evaluation_symbols_include_tsc=nirfmxgsm_types.ORFS_EVALUATION_SYMBOLS_INCLUDE_TSC_FALSE,
            evaluation_symbols_stop=90.0,
        )
    )
    client.ORFSCfgAveraging(
        nirfmxgsm_types.ORFSCfgAveragingRequest(
            instrument=instr,
            selector_string="",
            averaging_enabled=nirfmxgsm_types.ORFS_AVERAGING_ENABLED_FALSE,
            averaging_count=10,
            averaging_type=nirfmxgsm_types.ORFS_AVERAGING_TYPE_LOG,
        )
    )
    initiate_response = client.Initiate(
        nirfmxgsm_types.InitiateRequest(instrument=instr, selector_string="", result_name="")
    )
    check_for_warning(initiate_response, instr)

    orfs_fetch_modulation_results_array_response = client.ORFSFetchModulationResultsArray(
        nirfmxgsm_types.ORFSFetchModulationResultsArrayRequest(
            instrument=instr, selector_string="", timeout=10.0
        )
    )
    check_for_warning(orfs_fetch_modulation_results_array_response, instr)
    modulation_carrier_power = orfs_fetch_modulation_results_array_response.modulation_carrier_power
    mod_lower_relative_power = orfs_fetch_modulation_results_array_response.lower_relative_power
    mod_upper_relative_power = orfs_fetch_modulation_results_array_response.upper_relative_power
    mod_lower_absolute_power = orfs_fetch_modulation_results_array_response.lower_absolute_power
    mod_upper_absolute_power = orfs_fetch_modulation_results_array_response.upper_absolute_power

    orfs_fetch_switching_results_array_response = client.ORFSFetchSwitchingResultsArray(
        nirfmxgsm_types.ORFSFetchSwitchingResultsArrayRequest(
            instrument=instr, selector_string="", timeout=10.0
        )
    )
    check_for_warning(orfs_fetch_switching_results_array_response, instr)
    switching_carrier_power = orfs_fetch_switching_results_array_response.switching_carrier_power
    switch_lower_relative_power = orfs_fetch_switching_results_array_response.lower_relative_power
    switch_upper_relative_power = orfs_fetch_switching_results_array_response.upper_relative_power
    switch_lower_absolute_power = orfs_fetch_switching_results_array_response.lower_absolute_power
    switch_upper_absolute_power = orfs_fetch_switching_results_array_response.upper_absolute_power

    orfs_fetch_modulation_power_trace_response = client.ORFSFetchModulationPowerTrace(
        nirfmxgsm_types.ORFSFetchModulationPowerTraceRequest(
            instrument=instr, selector_string="", timeout=10.0
        )
    )
    check_for_warning(orfs_fetch_modulation_power_trace_response, instr)
    mod_offset_frequency = orfs_fetch_modulation_power_trace_response.offset_frequency
    mod_absolute_power = orfs_fetch_modulation_power_trace_response.absolute_power
    mod_relative_power = orfs_fetch_modulation_power_trace_response.relative_power

    orfs_fetch_switching_power_trace_response = client.ORFSFetchSwitchingPowerTrace(
        nirfmxgsm_types.ORFSFetchSwitchingPowerTraceRequest(
            instrument=instr, selector_string="", timeout=10.0
        )
    )
    check_for_warning(orfs_fetch_switching_power_trace_response, instr)
    switch_offset_frequency = orfs_fetch_switching_power_trace_response.offset_frequency
    switch_absolute_power = orfs_fetch_switching_power_trace_response.absolute_power
    switch_relative_power = orfs_fetch_switching_power_trace_response.relative_power

    print("---------Modulation Results---------")
    print(f"Modulation Carrier Power  (dBm)     : {modulation_carrier_power}\n")
    for i in range(len(mod_lower_absolute_power)):
        print(f"Offset : {i}")
        print(f"Lower Absolute Power (dBm)        : {mod_lower_absolute_power[i]}")
        print(f"Lower Relative Power (dB)        : {mod_lower_relative_power[i]}")
        print(f"Upper Absolute Power (dBm)        : {mod_upper_absolute_power[i]}")
        print(f"Upper Relative Power (dB)        : {mod_upper_relative_power[i]}")
    print("\n---------Switching Results---------")
    print(f"Switching Carrier Power  (dBm)      : {switching_carrier_power}\n")
    for i in range(len(switch_lower_absolute_power)):
        print(f"Offset : {i}")
        print(f"Lower Absolute Power (dBm)          : {switch_lower_absolute_power[i]}")
        print(f"Lower Relative Power (dB)           : {switch_lower_relative_power[i]}")
        print(f"Upper Absolute Power (dBm)          : {switch_upper_absolute_power[i]}")
        print(f"Upper Relative Power (dB)           : {switch_upper_relative_power[i]}")
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
        client.Close(nirfmxgsm_types.CloseRequest(instrument=instr, force_destroy=False))
