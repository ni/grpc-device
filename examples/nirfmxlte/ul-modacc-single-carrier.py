r"""Fetch UL ModAcc data.

Steps:
  1. Open a new RFmx Session.
  2. Configure Frequency Reference.
  3. Configure basic signal properties (Center Frequency, Reference Level and External Attenuation).
  4. Configure Trigger Type and Trigger Parameters.
  5. Configure Carrier Bandwidth.
  6. Configure operating Band.
  7. Configure Duplex Mode.
  8. Configure Auto DMRS Detection Enabled.
  9. Select ModAcc measurement and enable Traces.
  10. Configure Synchronization Mode and Measurement Interval.
  11. Configure EVM Unit.
  12. Configure In-Band Emission Mask Type.
  13. Configure Averaging Parameters for ModAcc measurement.
  14. Initiate the Measurement.
  15. Fetch ModAcc Measurements and Traces.
  16. Close RFmx Session.

The gRPC API is built from the C API. RFmx LTE documentation is installed with the driver at:
  C:\Program Files (x86)\National Instruments\RFmx\LTE\Documentation\ltecvi.chm

Getting Started:

To run this example, install "RFmx LTE" on the server machine:
  https://www.ni.com/en-us/support/downloads/software-products/download.rfmx-lte.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-RFmxLTE gRPC Wiki for the latest C Function Reference:
  https://github.com/ni/grpc-device/wiki/NI-RFmxLTE-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and physical channel name can be passed as separate
command line arguments.
  > python ul-modacc-single-carrier.py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedDevice" as the resource name.
"""

import sys

import grpc
import nirfmxlte_pb2 as nirfmxlte_types
import nirfmxlte_pb2_grpc as grpc_nirfmxlte

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "RFmxLTESession"

# Resource name and options for a simulated 5663 client.
RESOURCE = "SimulatedDevice"
OPTIONS = "Simulate=1,DriverSetup=Model:5663"

# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]
if len(sys.argv) >= 4:
    resource = sys.argv[3]
    OPTIONS = ""

# Create a gRPC channel + client.
channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
client = grpc_nirfmxlte.NiRFmxLTEStub(channel)
instr = None


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
        error_response = client.GetError(
            nirfmxlte_types.GetErrorRequest(
                instrument=instr,
            )
        )
        if response.status < 0:
            raise RuntimeError(f"Error: {error_response.error_description or response.status}")
        else:
            sys.stderr.write(f"Warning: {error_response.error_description or response.status}\n")

    return response


try:
    initialize_response = raise_if_initialization_error(
        client.Initialize(
            nirfmxlte_types.InitializeRequest(
                session_name=SESSION_NAME, resource_name=RESOURCE, option_string=OPTIONS
            )
        )
    )
    instr = initialize_response.instrument
    raise_if_error(
        client.CfgFrequencyReference(
            nirfmxlte_types.CfgFrequencyReferenceRequest(
                instrument=instr,
                channel_name="",
                frequency_reference_source_mapped=nirfmxlte_types.FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK,
                frequency_reference_frequency=10e6,
            )
        )
    )
    raise_if_error(
        client.CfgRF(
            nirfmxlte_types.CfgRFRequest(
                instrument=instr,
                selector_string="",
                center_frequency=1.95e9,
                reference_level=0.0,
                external_attenuation=0.0,
            )
        )
    )
    raise_if_error(
        client.CfgDigitalEdgeTrigger(
            nirfmxlte_types.CfgDigitalEdgeTriggerRequest(
                instrument=instr,
                selector_string="",
                digital_edge_source_mapped=nirfmxlte_types.DIGITAL_EDGE_TRIGGER_SOURCE_PFI0,
                digital_edge=nirfmxlte_types.DIGITAL_EDGE_TRIGGER_EDGE_RISING,
                trigger_delay=0.0,
                enable_trigger=False,
            )
        )
    )
    raise_if_error(
        client.CfgComponentCarrier(
            nirfmxlte_types.CfgComponentCarrierRequest(
                instrument=instr,
                selector_string="",
                component_carrier_bandwidth=10e6,
                component_carrier_frequency=0.0,
                cell_id=0,
            )
        )
    )
    raise_if_error(
        client.CfgBand(nirfmxlte_types.CfgBandRequest(instrument=instr, selector_string="", band=1))
    )
    raise_if_error(
        client.CfgDuplexScheme(
            nirfmxlte_types.CfgDuplexSchemeRequest(
                instrument=instr,
                selector_string="",
                duplex_scheme=nirfmxlte_types.DUPLEX_SCHEME_FDD,
                uplink_downlink_configuration=nirfmxlte_types.UPLINK_DOWNLINK_CONFIGURATION_0,
            )
        )
    )
    raise_if_error(
        client.CfgAutoDMRSDetectionEnabled(
            nirfmxlte_types.CfgAutoDMRSDetectionEnabledRequest(
                instrument=instr,
                selector_string="",
                auto_dmrs_detection_enabled=nirfmxlte_types.AUTO_DMRS_DETECTION_ENABLED_TRUE,
            )
        )
    )
    raise_if_error(
        client.SelectMeasurements(
            nirfmxlte_types.SelectMeasurementsRequest(
                instrument=instr,
                selector_string="",
                measurements=nirfmxlte_types.MEASUREMENT_TYPES_MODACC,
                enable_all_traces=True,
            )
        )
    )
    raise_if_error(
        client.ModAccCfgSynchronizationModeAndInterval(
            nirfmxlte_types.ModAccCfgSynchronizationModeAndIntervalRequest(
                instrument=instr,
                selector_string="",
                synchronization_mode=nirfmxlte_types.MODACC_SYNCHRONIZATION_MODE_SLOT,
                measurement_offset=0,
                measurement_length=1,
            )
        )
    )
    raise_if_error(
        client.ModAccCfgEVMUnit(
            nirfmxlte_types.ModAccCfgEVMUnitRequest(
                instrument=instr,
                selector_string="",
                evm_unit=nirfmxlte_types.MODACC_EVM_UNIT_PERCENTAGE,
            )
        )
    )
    raise_if_error(
        client.ModAccCfgInBandEmissionMaskType(
            nirfmxlte_types.ModAccCfgInBandEmissionMaskTypeRequest(
                instrument=instr,
                selector_string="",
                in_band_emission_mask_type=nirfmxlte_types.MODACC_IN_BAND_EMISSION_MASK_TYPE_RELEASE_11_ONWARDS,
            )
        )
    )
    raise_if_error(
        client.ModAccCfgAveraging(
            nirfmxlte_types.ModAccCfgAveragingRequest(
                instrument=instr,
                selector_string="",
                averaging_enabled=nirfmxlte_types.MODACC_AVERAGING_ENABLED_FALSE,
                averaging_count=10,
            )
        )
    )
    raise_if_error(
        client.Initiate(
            nirfmxlte_types.InitiateRequest(instrument=instr, selector_string="", result_name="")
        )
    )

    modacc_fetch_composite_evm_response = raise_if_error(
        client.ModAccFetchCompositeEVM(
            nirfmxlte_types.ModAccFetchCompositeEVMRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    mean_rms_composite_evm = modacc_fetch_composite_evm_response.mean_rms_composite_evm
    max_peak_composite_evm = modacc_fetch_composite_evm_response.maximum_peak_composite_evm
    mean_frequency_error = modacc_fetch_composite_evm_response.mean_frequency_error
    peak_composite_evm_symbol_index = (
        modacc_fetch_composite_evm_response.peak_composite_evm_symbol_index
    )
    peak_composite_evm_subcarrier_index = (
        modacc_fetch_composite_evm_response.peak_composite_evm_subcarrier_index
    )
    peak_composite_evm_slot_index = (
        modacc_fetch_composite_evm_response.peak_composite_evm_slot_index
    )
    modacc_fetch_iq_impairments_response = raise_if_error(
        client.ModAccFetchIQImpairments(
            nirfmxlte_types.ModAccFetchIQImpairmentsRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    mean_iq_origin_offset = modacc_fetch_iq_impairments_response.mean_iq_origin_offset
    mean_iq_gain_imbalance = modacc_fetch_iq_impairments_response.mean_iq_gain_imbalance
    mean_iq_quadrature_error = modacc_fetch_iq_impairments_response.mean_iq_quadrature_error
    modacc_fetch_in_band_emission_margin_response = raise_if_error(
        client.ModAccFetchInBandEmissionMargin(
            nirfmxlte_types.ModAccFetchInBandEmissionMarginRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    in_band_emission_margin = modacc_fetch_in_band_emission_margin_response.in_band_emission_margin

    modacc_fetch_pusch_constellation_trace_response = raise_if_error(
        client.ModAccFetchPUSCHConstellationTrace(
            nirfmxlte_types.ModAccFetchPUSCHConstellationTraceRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    data_constellation = modacc_fetch_pusch_constellation_trace_response.data_constellation
    dmrs_constellation = modacc_fetch_pusch_constellation_trace_response.dmrs_constellation

    modacc_fetch_evm_per_subcarrier_trace_response = raise_if_error(
        client.ModAccFetchEVMPerSubcarrierTrace(
            nirfmxlte_types.ModAccFetchEVMPerSubcarrierTraceRequest(
                instrument=instr, selector_string="", timeout=10.0
            )
        )
    )
    x0 = modacc_fetch_evm_per_subcarrier_trace_response.x0
    dx = modacc_fetch_evm_per_subcarrier_trace_response.dx
    mean_rmsevm_per_subcarrier = (
        modacc_fetch_evm_per_subcarrier_trace_response.mean_rms_evm_per_subcarrier
    )

    print("------------------Measurement------------------")
    print(f"Mean RMS Composite EVM (% or dB)     : {mean_rms_composite_evm}")
    print(f"Max Peak Composite EVM (% or dB)     : {max_peak_composite_evm}")
    print(f"Peak Composite EVM Slot Index        : {peak_composite_evm_slot_index}")
    print(f"Peak Composite EVM Symbol Index      : {peak_composite_evm_symbol_index}")
    print(f"Peak Composite EVM Subcarrier Index  : {peak_composite_evm_subcarrier_index}")
    print(f"Mean Frequency Error (Hz)            : {mean_frequency_error}")
    print(f"Mean IQ Origin Offset (dBc)          : {mean_iq_origin_offset}")
    print(f"Mean IQ Gain Imbalance (dB)          : {mean_iq_gain_imbalance}")
    print(f"Mean IQ Quadrature Error (deg)       : {mean_iq_quadrature_error}")
    print(f"In Band Emission Margin (dB)         : {in_band_emission_margin}")
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE:
        error_message = f"Failed to connect to server on {SERVER_ADDRESS}:{SERVER_PORT}"
    elif rpc_error.code() == grpc.StatusCode.UNIMPLEMENTED:
        error_message = (
            "The operation is not implemented or is not supported/enabled in this service"
        )
    sys.stderr.write(f"{error_message}\n")
finally:
    if instr:
        client.Close(nirfmxlte_types.CloseRequest(instrument=instr, force_destroy=False))
