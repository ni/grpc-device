r"""Demostration on how to use RFSA, RFSG and RFmx in Analysis Only mode.

This example shows how to generate a TDMS waveform using RFSG, to capture the raw IQ data using
RFSA and to demodulate it using RFmx Analysis Only mode.

The gRPC API is built from the C API. NI-RFSG documentation is installed with the driver at:
  C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niRFSG\documentation\English\RFSG.chm

The gRPC API is built from the C API. NI-RFSA documentation is installed with the driver at:
  C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niRFSG\documentation\English\RFSA.chm

The gRPC API is built from the C API. RFmx NR documentation is installed with the driver at:
  C:\Program Files (x86)\National Instruments\RFmx\NR\Documentation\rfmxnrcvi.chm

Getting Started:

To run this example, install "RFmx NR" on the server machine:
  https://www.ni.com/en-us/support/downloads/software-products/download.rfmx-nr.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-RFmxNR gRPC Wiki for the latest C Function Reference:
  https://github.com/ni/grpc-device/wiki/NI-RFmxNR-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and physical channel name can be passed as separate
command line arguments.
  > python rfsa-rfsg-NR-analysis-only-modacc.py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedDevice" as the resource name.
"""

import sys

import os

sys.path.append(os.getcwd())

import grpc
import nidevice_pb2 as nidevice_grpc
import nirfmxinstr_pb2 as nirfmxinstr_types
import nirfmxnr_pb2 as nirfmxnr_types
import nirfmxnr_pb2_grpc as grpc_nirfmxnr
import nirfsa_pb2 as nirfsa_types
import nirfsa_pb2_grpc as grpc_nirfsa
import nirfsg_pb2 as nirfsg_types
import nirfsg_pb2_grpc as grpc_nirfsg

SERVER_ADDRESS = "mercury07"
SERVER_PORT = "31763"
RFMXSESSION_NAME = "RFmxNRSession"
RFSASESSION_NAME = "RfsaSession"
RFSGSESSION_NAME = "RfsgSession"

# Resource name and options for a simulated 5663 client.
RESOURCE = "5840_1"
RFMXOPTIONS = "AnalysisOnly=1"
RFSAOPTIONS = "DriverSetup=SFPSessionAccess:1"
RFSGOPTIONS = ""

# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]
if len(sys.argv) >= 4:
    RESOURCE = sys.argv[3]
    OPTIONS = ""
# Create a gRPC channel + client.
# Use a larger buffer for the messages as we are transfering the raw data from instrument.
# In this example up to 1.6M samples
options = [("grpc.max_receive_message_length", 2**21)]
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}", options=options)
rfmxclient = grpc_nirfmxnr.NiRFmxNRStub(channel)
rfsaclient = grpc_nirfsa.NiRFSAStub(channel)
rfsgclient = grpc_nirfsg.NiRFSGStub(channel)
rfsgsession = None
rfmxsession = None
rfsasession = None


def raise_if_initialization_error(response):
    """Raise an exception if an error was returned from Initialize."""
    if response.status < 0:
        raise RuntimeError(f"Error: {response.error_message or response.status}")
    if response.status > 0:
        sys.stderr.write(f"Warning: {response.error_message or response.status}\n")
    return response


def raise_if_error(response):
    """Raise an exception if an error was returned."""
    if response.status != 0:
        error_response = rfmxclient.GetError(
            nirfmxnr_types.GetErrorRequest(
                instrument=rfmxsession,
            )
        )
        if response.status < 0:
            raise RuntimeError(
                f"Error: {error_response.error_description or response.status}"
            )
        else:
            sys.stderr.write(
                f"Warning: {error_response.error_description or response.status}\n"
            )
    return response


try:
    print(f"Initializing Instruments...", end="")
    initialize_response = raise_if_initialization_error(
        rfmxclient.Initialize(
            nirfmxnr_types.InitializeRequest(
                session_name=RFMXSESSION_NAME,
                resource_name=RESOURCE,
                option_string=RFMXOPTIONS,
            )
        )
    )
    rfmxsession = initialize_response.instrument

    initialize_response = raise_if_initialization_error(
        rfsaclient.InitWithOptions(
            nirfsa_types.InitWithOptionsRequest(
                session_name=RFSASESSION_NAME,
                resource_name=RESOURCE,
                option_string=RFSAOPTIONS,
            )
        )
    )
    rfsasession = initialize_response.vi

    initialize_response = raise_if_initialization_error(
        rfsgclient.InitWithOptions(
            nirfsg_types.InitWithOptionsRequest(
                session_name=RFSGSESSION_NAME,
                resource_name=RESOURCE,
                option_string=RFSGOPTIONS,
            )
        )
    )
    rfsgsession = initialize_response.vi
    print("Done")

    center_frequency = 3.5e9
    reference_level_dbm = 0
    power_level_dbm = -10
    rfsg_script = "script GenerateWaveform  repeat forever generate waveform end repeat end script"
    rfsg_waveform_name = "waveform"
    # The following waveform is installed with RFmx NR
    file_path = r"C:\Users\Public\Documents\National Instruments\NI-RFmx\NR\Examples\C\Support\NR_FR1_UL_BW-100MHz_SCS-30kHz.tdms"

    print(f"Configuring RFmx NR, RFSG and RFSA settings...", end="")
    ###### Configure RFSA Settigs ######
    raise_if_error(
        rfsaclient.ConfigureRefClock(
            nirfsa_types.ConfigureRefClockRequest(
                vi=rfsasession,
                clock_source_mapped=nirfsa_types.RefClockSource.REF_CLOCK_SOURCE_ONBOARD_CLOCK,
                ref_clock_rate=10e6,
            )
        )
    )
    raise_if_error(
        rfsaclient.ConfigureReferenceLevel(
            nirfsa_types.ConfigureReferenceLevelRequest(
                vi=rfsasession, reference_level=reference_level_dbm
            )
        )
    )
    raise_if_error(
        rfsaclient.ConfigureAcquisitionType(
            nirfsa_types.ConfigureAcquisitionTypeRequest(
                vi=rfsasession,
                acquisition_type=nirfsa_types.AcquisitionType.ACQUISITION_TYPE_IQ,
            )
        )
    )
    raise_if_error(
        rfsaclient.ConfigureIQCarrierFrequency(
            nirfsa_types.ConfigureIQCarrierFrequencyRequest(
                vi=rfsasession, carrier_frequency=center_frequency
            )
        )
    )
    ###### Configure RFSG Settigs ######
    raise_if_error(
        rfsgclient.SetAttributeViReal64(
            nirfsg_types.SetAttributeViReal64Request(
                vi=rfsgsession,
                channel_name="",
                attribute_id=nirfsg_types.NIRFSG_ATTRIBUTE_POWER_LEVEL,
                value_raw=power_level_dbm,
            )
        )
    )
    raise_if_error(
        rfsgclient.SetAttributeViReal64(
            nirfsg_types.SetAttributeViReal64Request(
                vi=rfsgsession,
                channel_name="",
                attribute_id=nirfsg_types.NIRFSG_ATTRIBUTE_FREQUENCY,
                value_raw=center_frequency,
            )
        )
    )
    raise_if_error(
        rfsgclient.ConfigureGenerationMode(
            nirfsg_types.ConfigureGenerationModeRequest(
                vi=rfsgsession, generation_mode=nirfsg_types.GENERATION_MODE_SCRIPT
            )
        )
    )
    raise_if_error(
        rfsgclient.ReadAndDownloadWaveformFromFileTDMS(
            nirfsg_types.ReadAndDownloadWaveformFromFileTDMSRequest(
                vi=rfsgsession,
                waveform_name=rfsg_waveform_name,
                file_path=str(file_path),
                waveform_index=0,
            )
        )
    )
    raise_if_error(
        rfsgclient.WriteScript(
            nirfsg_types.WriteScriptRequest(vi=rfsgsession, script=rfsg_script)
        )
    )
    raise_if_error(
        rfsgclient.ExportSignal(
            nirfsg_types.ExportSignalRequest(
                vi=rfsgsession,
                signal=nirfsg_types.ROUTED_SIGNAL_MARKER_EVENT,
                signal_identifier_mapped=nirfsg_types.SIGNAL_IDENTIFIER_MARKER0,
                output_terminal_mapped=nirfsg_types.OUTPUT_SIGNAL_PXI_TRIG1,
            )
        )
    )

    ###### Configure NR Settigs ######
    nr_frequency_range = nirfmxnr_types.NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1
    nr_carrier_bandwidth = 100e6
    nr_subcarrier_spacing = 30e3
    nr_auto_resource_block_detection_enabled = True
    nr_pusch_modulation_type = nirfmxnr_types.NIRFMXNR_INT32_PUSCH_MODULATION_TYPE_QAM64
    nr_measurement_length_unit = (
        nirfmxnr_types.NIRFMXNR_INT32_MODACC_MEASUREMENT_LENGTH_UNIT_SLOT
    )
    nr_link_direction = nirfmxnr_types.NIRFMXNR_INT32_LINK_DIRECTION_UPLINK
    nr_measurement_offset = 0
    nr_measurement_length = 1
    raise_if_error(
        rfmxclient.SetAttributeI32(
            nirfmxnr_types.SetAttributeI32Request(
                instrument=rfmxsession,
                selector_string="",
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_LINK_DIRECTION,
                attr_val_raw=nr_link_direction,
            )
        )
    )
    raise_if_error(
        rfmxclient.SetAttributeI32(
            nirfmxnr_types.SetAttributeI32Request(
                instrument=rfmxsession,
                selector_string="",
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE,
                attr_val_raw=nr_frequency_range,
            )
        )
    )
    raise_if_error(
        rfmxclient.SetAttributeF64(
            nirfmxnr_types.SetAttributeF64Request(
                instrument=rfmxsession,
                selector_string="",
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH,
                attr_val=nr_carrier_bandwidth,
            )
        )
    )
    raise_if_error(
        rfmxclient.SetAttributeF64(
            nirfmxnr_types.SetAttributeF64Request(
                instrument=rfmxsession,
                selector_string="",
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING,
                attr_val=nr_subcarrier_spacing,
            )
        )
    )
    raise_if_error(
        rfmxclient.SetAttributeI32(
            nirfmxnr_types.SetAttributeI32Request(
                instrument=rfmxsession,
                selector_string="",
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_PUSCH_MODULATION_TYPE,
                attr_val=nr_pusch_modulation_type,
            )
        )
    )
    raise_if_error(
        rfmxclient.SetAttributeI32(
            nirfmxnr_types.SetAttributeI32Request(
                instrument=rfmxsession,
                selector_string="",
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_LENGTH_UNIT,
                attr_val=nr_measurement_length_unit,
            )
        )
    )
    raise_if_error(
        rfmxclient.SetAttributeF64(
            nirfmxnr_types.SetAttributeF64Request(
                instrument=rfmxsession,
                selector_string="",
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_OFFSET,
                attr_val=nr_measurement_offset,
            )
        )
    )
    raise_if_error(
        rfmxclient.SetAttributeF64(
            nirfmxnr_types.SetAttributeF64Request(
                instrument=rfmxsession,
                selector_string="",
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_LENGTH,
                attr_val=nr_measurement_length,
            )
        )
    )
    raise_if_error(
        rfmxclient.SelectMeasurements(
            nirfmxnr_types.SelectMeasurementsRequest(
                instrument=rfmxsession,
                selector_string="",
                measurements=nirfmxnr_types.MEASUREMENT_TYPES_MODACC,
                enable_all_traces=False,
            )
        )
    )
    raise_if_error(
        rfmxclient.Commit(
            nirfmxnr_types.CommitRequest(
                instrument=rfmxsession,
                selector_string="",
            )
        )
    )
    # Once commit is called, the recommended acquisition settings can be queried
    response = rfmxclient.GetAttributeF64(
        nirfmxinstr_types.GetAttributeF64Request(
            instrument=rfmxsession,
            channel_name="",
            attribute_id=nirfmxinstr_types.NIRFMXINSTR_ATTRIBUTE_RECOMMENDED_IQ_MINIMUM_SAMPLE_RATE,
        )
    )
    minimum_sample_rate = response.attr_val
    response = rfmxclient.GetAttributeF64(
        nirfmxinstr_types.GetAttributeF64Request(
            instrument=rfmxsession,
            channel_name="",
            attribute_id=nirfmxinstr_types.NIRFMXINSTR_ATTRIBUTE_RECOMMENDED_IQ_ACQUISITION_TIME,
        )
    )
    acquisition_time = response.attr_val
    number_of_samples = acquisition_time * minimum_sample_rate
    response = rfmxclient.GetAttributeF64(
        nirfmxinstr_types.GetAttributeF64Request(
            instrument=rfmxsession,
            channel_name="",
            attribute_id=nirfmxinstr_types.NIRFMXINSTR_ATTRIBUTE_RECOMMENDED_IQ_PRE_TRIGGER_TIME,
        )
    )
    pre_trigger_time = response.attr_val
    number_of_pre_samples = pre_trigger_time * minimum_sample_rate
    response = rfmxclient.GetAttributeI32(
        nirfmxinstr_types.GetAttributeI32Request(
            instrument=rfmxsession,
            channel_name="",
            attribute_id=nirfmxinstr_types.NIRFMXINSTR_ATTRIBUTE_RECOMMENDED_NUMBER_OF_RECORDS,
        )
    )
    number_of_records = response.attr_val

    # Configure RFSA Acquisition Settings
    raise_if_error(
        rfsaclient.ConfigureNumberOfSamples(
            nirfsa_types.ConfigureNumberOfSamplesRequest(
                vi=rfsasession,
                number_of_samples_is_finite=True,
                samples_per_record=int(number_of_samples),
            )
        )
    )
    raise_if_error(
        rfsaclient.ConfigureIQRate(
            nirfsa_types.ConfigureIQRateRequest(
                vi=rfsasession, iq_rate=minimum_sample_rate
            )
        )
    )
    print(f"Done")
    print(f"Starting Generation...", end="")
    raise_if_error(rfsgclient.Initiate(nirfsg_types.InitiateRequest(vi=rfsgsession)))
    print("Generating")
    print("Starting Acquisition and Analysis Loop:")

    ###### Start Acquisition and AO Analyze ######
    read_response = raise_if_error(
        rfsaclient.Initiate(nirfsa_types.InitiateRequest(vi=rfsasession))
    )
    for record in range(number_of_records):
        read_response = raise_if_error(
            rfsaclient.FetchIQSingleRecordComplexF32(
                nirfsa_types.FetchIQSingleRecordComplexF32Request(
                    vi=rfsasession,
                    channel_list="",
                    record_number=record,
                    number_of_samples=int(number_of_samples),
                    timeout=10.0,
                )
            )
        )

        iq = [
            nidevice_grpc.NIComplexNumberF32(
                real=sample.real, imaginary=sample.imaginary
            )
            for sample in read_response.data
        ]

        ###### Feed IQ Data to Analysis Only ######
        raise_if_error(
            rfmxclient.AnalyzeIQ1Waveform(
                nirfmxnr_types.AnalyzeIQ1WaveformRequest(
                    instrument=rfmxsession,
                    selector_string="",
                    result_name="",
                    x0=read_response.wfm_info.relative_initial_x,
                    dx=read_response.wfm_info.x_increment,
                    iq=iq,
                    reset=True,
                )
            )
        )
    ###### Fetch ModAcc results ######
    modacc_fetch_measurement = raise_if_error(
        rfmxclient.ModAccFetchCompositeEVM(
            nirfmxnr_types.ModAccFetchCompositeEVMRequest(
                instrument=rfmxsession, selector_string="", timeout=10.0
            )
        )
    )
    print(modacc_fetch_measurement)
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    for entry in rpc_error.trailing_metadata() or []:
        if entry.key == "ni-error":
            value = (
                entry.value
                if isinstance(entry.value, str)
                else entry.value.decode("utf-8")
            )
            error_message += f"\nError status: {value}"
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE:
        error_message = f"Failed to connect to server on {SERVER_ADDRESS}:{SERVER_PORT}"
    elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
        error_message = "The operation is not implemented or is not supported/enabled in this service"
    print(f"{error_message}")
finally:
    if rfmxsession:
        rfmxclient.Close(
            nirfmxnr_types.CloseRequest(instrument=rfmxsession, force_destroy=True)
        )
    if rfsasession:
        rfsaclient.Close(nirfsa_types.CloseRequest(vi=rfsasession))
    raise_if_error(rfsgclient.Abort(nirfsg_types.AbortRequest(vi=rfsgsession)))
    if rfsgsession:
        rfsgclient.Close(nirfsg_types.CloseRequest(vi=rfsgsession))
