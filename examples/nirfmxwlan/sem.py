r"""Fetch SEM data.

Steps:
  1. Open a new RFmx session.
  2. Configure the frequency reference properties (Clock Source and Clock Frequency).
  3. Configure the basic signal properties (Center Frequency and External Attenuation).
  4. Configure IQ Power Edge Trigger properties (Trigger Delay, IQ Power Edge Level, Minimum Quiet
     Time).
  5. Configure Standard and Channel Bandwidth Properties.
  6. Configure Reference Level.
  7. Select SEM measurement and enable the traces.
  8. Configure Averaging parameters.
  9. Configure Mask Type.
  10. Configure Sweep Time.
  11. Configure Span.
  12. Initiate the Measurement.
  13. Fetch SEM Measurements.
  14. Close the RFmx Session.

The gRPC API is built from the C API. RFmx WLAN documentation is installed with the driver at:
  C:\Program Files (x86)\National Instruments\RFmx\WLAN\Documentation\rfmxwlancvi.chm

Getting Started:

To run this example, install "RFmx WLAN" on the server machine:
  https://www.ni.com/en-us/support/downloads/software-products/download.rfmx-wlan.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-RFmxWLAN gRPC Wiki for the latest C Function Reference:
  https://github.com/ni/grpc-device/wiki/NI-RFmxWLAN-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and physical channel name can be passed as separate
command line arguments.
  > python sem
  .py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedDevice" as the resource name.
"""

import sys

import grpc
import nirfmxwlan_pb2 as nirfmxwlan_types
import nirfmxwlan_pb2_grpc as grpc_nirfmxwlan

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "RFmxWLANSession"

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
client = grpc_nirfmxwlan.NiRFmxWLANStub(channel)
instr = None


def check_for_warning(response, instrument):
    """Print to console if the status indicates a warning."""
    if response.status > 0:
        warning_message = client.GetErrorString(
            nirfmxwlan_types.GetErrorStringRequest(
                instrument=instrument,
                error_code=response.status,
            )
        )
        sys.stderr.write(
            f"{warning_message.error_description}\nWarning status: {response.status}\n"
        )


try:
    auto_level = True

    initialize_response = client.Initialize(
        nirfmxwlan_types.InitializeRequest(
            session_name=SESSION_NAME,
            resource_name=RESOURCE,
            option_string=OPTIONS,
        )
    )
    instr = initialize_response.instrument
    client.CfgFrequencyReference(
        nirfmxwlan_types.CfgFrequencyReferenceRequest(
            instrument=instr,
            channel_name="",
            frequency_reference_source_mapped=nirfmxwlan_types.FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK,
            frequency_reference_frequency=10e6,
        )
    )

    client.CfgFrequency(
        nirfmxwlan_types.CfgFrequencyRequest(
            instrument=instr,
            selector_string="",
            center_frequency=6.412e9,
        )
    )

    client.CfgExternalAttenuation(
        nirfmxwlan_types.CfgExternalAttenuationRequest(
            instrument=instr,
            selector_string="",
            external_attenuation=0.0,
        )
    )

    client.CfgIQPowerEdgeTrigger(
        nirfmxwlan_types.CfgIQPowerEdgeTriggerRequest(
            instrument=instr,
            selector_string="",
            iq_power_edge_source="0",
            iq_power_edge_slope=nirfmxwlan_types.IQ_POWER_EDGE_TRIGGER_SLOPE_RISING,
            iq_power_edge_level=-20.0,
            trigger_delay=0.0,
            trigger_min_quiet_time_mode=nirfmxwlan_types.TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO,
            trigger_min_quiet_time_duration=5.0e-6,
            iq_power_edge_level_type=nirfmxwlan_types.IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE,
            enable_trigger=True,
        )
    )

    client.CfgStandard(
        nirfmxwlan_types.CfgStandardRequest(
            instrument=instr,
            selector_string="",
            standard=nirfmxwlan_types.STANDARD_802_11_AG,
        )
    )

    client.CfgChannelBandwidth(
        nirfmxwlan_types.CfgChannelBandwidthRequest(
            instrument=instr,
            selector_string="",
            channel_bandwidth=20e6,
        )
    )

    if auto_level:
        client.AutoLevel(
            nirfmxwlan_types.AutoLevelRequest(
                instrument=instr,
                selector_string="",
                measurement_interval=10e-3,
            )
        )

    else:
        client.CfgReferenceLevel(
            nirfmxwlan_types.CfgReferenceLevelRequest(
                instrument=instr,
                selector_string="",
                reference_level=0.0,
            )
        )

    client.SelectMeasurements(
        nirfmxwlan_types.SelectMeasurementsRequest(
            instrument=instr,
            selector_string="",
            measurements=nirfmxwlan_types.MEASUREMENT_TYPES_SEM,
            enable_all_traces=True,
        )
    )

    client.SEMCfgAveraging(
        nirfmxwlan_types.SEMCfgAveragingRequest(
            instrument=instr,
            selector_string="",
            averaging_enabled=nirfmxwlan_types.SEM_AVERAGING_ENABLED_FALSE,
            averaging_count=10,
            averaging_type=nirfmxwlan_types.SEM_AVERAGING_TYPE_RMS,
        )
    )

    client.SEMCfgMaskType(
        nirfmxwlan_types.SEMCfgMaskTypeRequest(
            instrument=instr,
            selector_string="",
            mask_type=nirfmxwlan_types.SEM_MASK_TYPE_STANDARD,
        )
    )

    client.SEMCfgSweepTime(
        nirfmxwlan_types.SEMCfgSweepTimeRequest(
            instrument=instr,
            selector_string="",
            sweep_time_auto=nirfmxwlan_types.SEM_SWEEP_TIME_AUTO_TRUE,
            sweep_time_interval=1.0e-3,
        )
    )

    client.SEMCfgSpan(
        nirfmxwlan_types.SEMCfgSpanRequest(
            instrument=instr,
            selector_string="",
            span_auto=nirfmxwlan_types.SEM_SPAN_AUTO_TRUE,
            span=66.0e6,
        )
    )

    initiate_response = client.Initiate(
        nirfmxwlan_types.InitiateRequest(
            instrument=instr,
            selector_string="",
            result_name="",
        )
    )
    check_for_warning(initiate_response, instr)

    ### Fetch results ###

    sem_fetch_measurement_status_response = client.SEMFetchMeasurementStatus(
        nirfmxwlan_types.SEMFetchMeasurementStatusRequest(
            instrument=instr,
            selector_string="",
            timeout=10.0,
        )
    )
    check_for_warning(sem_fetch_measurement_status_response, instr)
    measurement_status = sem_fetch_measurement_status_response.measurement_status

    sem_fetch_carrier_measurement_response = client.SEMFetchCarrierMeasurement(
        nirfmxwlan_types.SEMFetchCarrierMeasurementRequest(
            instrument=instr,
            selector_string="",
            timeout=10.0,
        )
    )
    check_for_warning(sem_fetch_carrier_measurement_response, instr)
    absolute_power = sem_fetch_carrier_measurement_response.absolute_power
    relative_power = sem_fetch_carrier_measurement_response.relative_power

    sem_fetch_lower_offset_margin_array_response = client.SEMFetchLowerOffsetMarginArray(
        nirfmxwlan_types.SEMFetchLowerOffsetMarginArrayRequest(
            instrument=instr,
            selector_string="",
            timeout=10.0,
        )
    )
    check_for_warning(sem_fetch_lower_offset_margin_array_response, instr)
    lower_offset_array_size = len(
        sem_fetch_lower_offset_margin_array_response.margin_absolute_power
    )
    lower_offset_measurement_status = (
        sem_fetch_lower_offset_margin_array_response.measurement_status
    )
    lower_offset_margin = sem_fetch_lower_offset_margin_array_response.margin
    lower_offset_margin_frequency = sem_fetch_lower_offset_margin_array_response.margin_frequency
    lower_offset_margin_absolute_power = (
        sem_fetch_lower_offset_margin_array_response.margin_absolute_power
    )
    lower_offset_margin_relative_power = (
        sem_fetch_lower_offset_margin_array_response.margin_relative_power
    )

    sem_fetch_upper_offset_margin_array_response = client.SEMFetchUpperOffsetMarginArray(
        nirfmxwlan_types.SEMFetchUpperOffsetMarginArrayRequest(
            instrument=instr,
            selector_string="",
            timeout=10.0,
        )
    )
    check_for_warning(sem_fetch_upper_offset_margin_array_response, instr)
    upper_offset_array_size = len(
        sem_fetch_upper_offset_margin_array_response.margin_absolute_power
    )
    upper_offset_measurement_status = (
        sem_fetch_upper_offset_margin_array_response.measurement_status
    )
    upper_offset_margin = sem_fetch_upper_offset_margin_array_response.margin
    upper_offset_margin_frequency = sem_fetch_upper_offset_margin_array_response.margin_frequency
    upper_offset_margin_absolute_power = (
        sem_fetch_upper_offset_margin_array_response.margin_absolute_power
    )
    upper_offset_margin_relative_power = (
        sem_fetch_upper_offset_margin_array_response.margin_relative_power
    )

    sem_fetch_spectrum_response = client.SEMFetchSpectrum(
        nirfmxwlan_types.SEMFetchSpectrumRequest(
            instrument=instr,
            selector_string="",
            timeout=10.0,
        )
    )
    check_for_warning(sem_fetch_spectrum_response, instr)

    print("\n----------SEM Results----------\n")
    if measurement_status == nirfmxwlan_types.SEM_MEASUREMENT_STATUS_PASS:
        print("Measurement Status               : PASS")
    elif measurement_status == nirfmxwlan_types.SEM_MEASUREMENT_STATUS_FAIL:
        print("Measurement Status               : FAIL")
    print(f"Carrier Absolute Power (dBm)     : {absolute_power}")
    print("\n-----------Lower Offset Measurements----------- \n")
    for i in range(lower_offset_array_size):
        print(f"Offset  {i}")
        if (
            lower_offset_measurement_status[i]
            == nirfmxwlan_types.SEM_LOWER_OFFSET_MEASUREMENT_STATUS_PASS
        ):
            print("Measurement Status               : PASS")
        elif (
            lower_offset_measurement_status[i]
            == nirfmxwlan_types.SEM_LOWER_OFFSET_MEASUREMENT_STATUS_FAIL
        ):
            print("Measurement Status               : FAIL")
        print(f"Margin (dB)                      : {lower_offset_margin[i]}")
        print(f"Margin Frequency (Hz)            : {lower_offset_margin_frequency[i]}")
        print(f"Margin Absolute Power (dBm)      : {lower_offset_margin_absolute_power[i]}")
    print("\n-----------Upper Offset Measurements----------- \n")
    for i in range(upper_offset_array_size):
        print(f"Offset  {i}")
        if (
            upper_offset_measurement_status[i]
            == nirfmxwlan_types.SEM_UPPER_OFFSET_MEASUREMENT_STATUS_PASS
        ):
            print("Measurement Status               : PASS")
        elif (
            upper_offset_measurement_status[i]
            == nirfmxwlan_types.SEM_UPPER_OFFSET_MEASUREMENT_STATUS_FAIL
        ):
            print("Measurement Status               : FAIL")
        print(f"Margin (dB)                      : {upper_offset_margin[i]}")
        print(f"Margin Frequency (Hz)            : {upper_offset_margin_frequency[i]}")
        print(f"Margin Absolute Power (dBm)      : {upper_offset_margin_absolute_power[i]}")

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
        client.Close(nirfmxwlan_types.CloseRequest(instrument=instr, force_destroy=False))
