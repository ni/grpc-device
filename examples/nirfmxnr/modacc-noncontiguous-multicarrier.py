r"""Fetch ACP, ModAcc, and TXP data.

Steps:
1. Open a new RFmx Session.
2. Configure Frequency Reference.
3. Configure Selected Ports.
4. Configure basic signal properties (Center Frequency, Reference Level and External Attenuation).
5. Configure Trigger Type and Trigger Parameters.
6. Configure Auto Increment Cell ID Enabled, Auto RB Detection Enabled and Number of Subblocks.
7. Configure Subblocks and Carriers.
8. Configure PUSCH for all Carriers in each Subblock.
9. Configure PUSCH DMRS for all Carriers in each Subblock.
10. Select ModAcc measurement and enable Traces.
11. Configure Synchronization Mode for ModAcc measurement.
12. Configure Measurement Interval.
13. Initiate the Measurement.
14. Fetch ModAcc Measurements.
15. Close RFmx Session.

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
  > python modacc-noncontiguous-multicarrier.py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedDevice" as the resource name.
"""

import sys

import grpc
import nirfmxnr_pb2 as nirfmxnr_types
import nirfmxnr_pb2_grpc as grpc_nirfmxnr

SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "RFmxWLANSession"

# Resource name and options for a simulated 5663 client.
RESOURCE = "SimulatedDevice"
OPTIONS = "Simulate=1,DriverSetup=Model:5663"

# Initialize variables
NUMBER_OF_SUBBLOCKS = 2
SUBBLOCK_FREQUENCY = [0, 200e6]
NUMBER_OF_COMPONENT_CARRIERS = 2
BAND = [78, 78]
COMPONENT_CARRIER_SPACING_TYPE = [
    nirfmxnr_types.NIRFMXNR_INT32_COMPONENT_CARRIER_SPACING_TYPE_NOMINAL,
    nirfmxnr_types.NIRFMXNR_INT32_COMPONENT_CARRIER_SPACING_TYPE_NOMINAL,
]
COMPONENT_CARRIER_AT_CENTER_FREQUENCY = [-1, -1]
CHANNEL_RASTER = [15e3, 15e3]
COMPONENT_CARRIER_BANDWIDTH = [[100e6, 100e6], [100e6, 100e6]]
COMPONENT_CARRIER_FREQUENCY = [[-49.98e6, 49.98e6], [-49.98e6, 49.98e6]]
CELL_ID = [[0, 1], [0, 1]]

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
client = grpc_nirfmxnr.NiRFmxNRStub(channel)
instr = None


def check_for_warning(response, instrument):
    """Print to console if the status indicates a warning."""
    if response.status > 0:
        warning_message = client.GetErrorString(
            nirfmxnr_types.GetErrorStringRequest(
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
        nirfmxnr_types.InitializeRequest(
            session_name=SESSION_NAME,
            resource_name=RESOURCE,
            option_string=OPTIONS,
        )
    )
    instr = initialize_response.instrument

    client.CfgFrequencyReference(
        nirfmxnr_types.CfgFrequencyReferenceRequest(
            instrument=instr,
            channel_name="",
            frequency_reference_source_mapped=nirfmxnr_types.FREQUENCY_REFERENCE_SOURCE_ONBOARD_CLOCK,
            frequency_reference_frequency=10.0e6,
        )
    )

    client.SetAttributeString(
        nirfmxnr_types.SetAttributeStringRequest(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_SELECTED_PORTS,
            attr_val_raw="",
        )
    )

    client.CfgFrequency(
        nirfmxnr_types.CfgFrequencyRequest(
            instrument=instr,
            selector_string="",
            center_frequency=3.5e9,
        )
    )

    client.CfgExternalAttenuation(
        nirfmxnr_types.CfgExternalAttenuationRequest(
            instrument=instr,
            selector_string="",
            external_attenuation=0.0,
        )
    )

    client.CfgRFAttenuation(
        nirfmxnr_types.CfgRFAttenuationRequest(
            instrument=instr,
            channel_name="",
            rf_attenuation_auto=nirfmxnr_types.RF_ATTENUATION_AUTO_TRUE,
            rf_attenuation_value=10.0,
        )
    )

    client.CfgDigitalEdgeTrigger(
        nirfmxnr_types.CfgDigitalEdgeTriggerRequest(
            instrument=instr,
            selector_string="",
            digital_edge_source_mapped=nirfmxnr_types.DIGITAL_EDGE_TRIGGER_SOURCE_PXI_TRIG0,
            digital_edge=nirfmxnr_types.DIGITAL_EDGE_TRIGGER_EDGE_RISING,
            trigger_delay=0.0,
            enable_trigger=True,
        )
    )

    client.CfgIQPowerEdgeTrigger(
        nirfmxnr_types.CfgIQPowerEdgeTriggerRequest(
            instrument=instr,
            selector_string="",
            iq_power_edge_source="0",
            iq_power_edge_slope=nirfmxnr_types.IQ_POWER_EDGE_TRIGGER_SLOPE_RISING,
            iq_power_edge_level=-20.0,
            trigger_delay=0.0,
            trigger_min_quiet_time_mode=nirfmxnr_types.TRIGGER_MINIMUM_QUIET_TIME_MODE_AUTO,
            trigger_min_quiet_time_duration=8.0e-6,
            iq_power_edge_level_type=nirfmxnr_types.IQ_POWER_EDGE_TRIGGER_LEVEL_TYPE_RELATIVE,
            enable_trigger=False,
        )
    )

    client.SetAttributeI32(
        nirfmxnr_types.SetAttributeI32Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_LINK_DIRECTION,
            attr_val_raw=nirfmxnr_types.NIRFMXNR_INT32_LINK_DIRECTION_UPLINK,
        )
    )

    client.SetAttributeI32(
        nirfmxnr_types.SetAttributeI32Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_AUTO_RESOURCE_BLOCK_DETECTION_ENABLED,
            attr_val_raw=nirfmxnr_types.NIRFMXNR_INT32_AUTO_RESOURCE_BLOCK_DETECTION_ENABLED_TRUE,
        )
    )

    client.SetAttributeI32(
        nirfmxnr_types.SetAttributeI32Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_AUTO_INCREMENT_CELL_ID_ENABLED,
            attr_val_raw=nirfmxnr_types.NIRFMXNR_INT32_AUTO_INCREMENT_CELL_ID_ENABLED_TRUE,
        )
    )

    client.SetAttributeI32(
        nirfmxnr_types.SetAttributeI32Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_NUMBER_OF_SUBBLOCKS,
            attr_val_raw=NUMBER_OF_SUBBLOCKS,
        )
    )

    for i in range(NUMBER_OF_SUBBLOCKS):
        build_subblock_string_response = client.BuildSubblockString(
            nirfmxnr_types.BuildSubblockStringRequest(
                selector_string="",
                subblock_number=i,
            )
        )
        check_for_warning(build_subblock_string_response, instr)
        subblock_string = build_subblock_string_response.selector_string_out

        client.SetAttributeI32(
            nirfmxnr_types.SetAttributeI32Request(
                instrument=instr,
                selector_string=subblock_string,
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_FREQUENCY_RANGE,
                attr_val_raw=nirfmxnr_types.NIRFMXNR_INT32_FREQUENCY_RANGE_RANGE1,
            )
        )

        client.SetAttributeF64(
            nirfmxnr_types.SetAttributeF64Request(
                instrument=instr,
                selector_string=subblock_string,
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_SUBBLOCK_FREQUENCY,
                attr_val=SUBBLOCK_FREQUENCY[i],
            )
        )

        client.SetAttributeI32(
            nirfmxnr_types.SetAttributeI32Request(
                instrument=instr,
                selector_string=subblock_string,
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_BAND,
                attr_val_raw=BAND[i],
            )
        )

        client.SetAttributeI32(
            nirfmxnr_types.SetAttributeI32Request(
                instrument=instr,
                selector_string=subblock_string,
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_SPACING_TYPE,
                attr_val_raw=COMPONENT_CARRIER_SPACING_TYPE[i],
            )
        )

        client.SetAttributeI32(
            nirfmxnr_types.SetAttributeI32Request(
                instrument=instr,
                selector_string=subblock_string,
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_AT_CENTER_FREQUENCY,
                attr_val_raw=COMPONENT_CARRIER_AT_CENTER_FREQUENCY[i],
            )
        )

        client.SetAttributeF64(
            nirfmxnr_types.SetAttributeF64Request(
                instrument=instr,
                selector_string=subblock_string,
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_CHANNEL_RASTER,
                attr_val=CHANNEL_RASTER[i],
            )
        )

        client.SetAttributeI32(
            nirfmxnr_types.SetAttributeI32Request(
                instrument=instr,
                selector_string=subblock_string,
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_NUMBER_OF_COMPONENT_CARRIERS,
                attr_val_raw=NUMBER_OF_COMPONENT_CARRIERS,
            )
        )

        for j in range(NUMBER_OF_COMPONENT_CARRIERS):
            build_carrier_string_response = client.BuildCarrierString(
                nirfmxnr_types.BuildCarrierStringRequest(
                    selector_string=subblock_string,
                    carrier_number=j,
                )
            )
            check_for_warning(build_carrier_string_response, instr)
            carrier_string = build_carrier_string_response.selector_string_out

            client.SetAttributeF64(
                nirfmxnr_types.SetAttributeF64Request(
                    instrument=instr,
                    selector_string=carrier_string,
                    attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_BANDWIDTH,
                    attr_val=COMPONENT_CARRIER_BANDWIDTH[i][j],
                )
            )

            client.SetAttributeF64(
                nirfmxnr_types.SetAttributeF64Request(
                    instrument=instr,
                    selector_string=carrier_string,
                    attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_COMPONENT_CARRIER_FREQUENCY,
                    attr_val=COMPONENT_CARRIER_FREQUENCY[i][j],
                )
            )

            client.SetAttributeI32(
                nirfmxnr_types.SetAttributeI32Request(
                    instrument=instr,
                    selector_string=carrier_string,
                    attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_CELL_ID,
                    attr_val_raw=CELL_ID[i][j],
                )
            )

        build_carrier_string_response = client.BuildCarrierString(
            nirfmxnr_types.BuildCarrierStringRequest(
                selector_string=subblock_string,
                carrier_number=-1,
            )
        )
        check_for_warning(build_carrier_string_response, instr)
        carrier_string = build_carrier_string_response.selector_string_out

        client.SetAttributeI32(
            nirfmxnr_types.SetAttributeI32Request(
                instrument=instr,
                selector_string=carrier_string,
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_PUSCH_TRANSFORM_PRECODING_ENABLED,
                attr_val_raw=nirfmxnr_types.NIRFMXNR_INT32_PUSCH_TRANSFORM_PRECODING_ENABLED_FALSE,
            )
        )

        client.SetAttributeString(
            nirfmxnr_types.SetAttributeStringRequest(
                instrument=instr,
                selector_string=carrier_string,
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_PUSCH_SLOT_ALLOCATION,
                attr_val_raw="0-Last",
            )
        )

        client.SetAttributeString(
            nirfmxnr_types.SetAttributeStringRequest(
                instrument=instr,
                selector_string=carrier_string,
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_PUSCH_SYMBOL_ALLOCATION,
                attr_val_raw="0-Last",
            )
        )

        client.SetAttributeF64(
            nirfmxnr_types.SetAttributeF64Request(
                instrument=instr,
                selector_string=carrier_string,
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_BANDWIDTH_PART_SUBCARRIER_SPACING,
                attr_val=30e3,
            )
        )

        client.SetAttributeI32(
            nirfmxnr_types.SetAttributeI32Request(
                instrument=instr,
                selector_string=carrier_string,
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_POWER_MODE,
                attr_val_raw=nirfmxnr_types.NIRFMXNR_INT32_PUSCH_DMRS_POWER_MODE_CDM_GROUPS,
            )
        )

        client.SetAttributeF64(
            nirfmxnr_types.SetAttributeF64Request(
                instrument=instr,
                selector_string=carrier_string,
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_POWER,
                attr_val=0.0,
            )
        )

        client.SetAttributeI32(
            nirfmxnr_types.SetAttributeI32Request(
                instrument=instr,
                selector_string=carrier_string,
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_CONFIGURATION_TYPE,
                attr_val_raw=nirfmxnr_types.NIRFMXNR_INT32_PUSCH_DMRS_CONFIGURATION_TYPE_1,
            )
        )

        client.SetAttributeI32(
            nirfmxnr_types.SetAttributeI32Request(
                instrument=instr,
                selector_string=carrier_string,
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_PUSCH_MAPPING_TYPE,
                attr_val_raw=nirfmxnr_types.NIRFMXNR_INT32_PUSCH_MAPPING_TYPE_A,
            )
        )

        client.SetAttributeI32(
            nirfmxnr_types.SetAttributeI32Request(
                instrument=instr,
                selector_string=carrier_string,
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_TYPE_A_POSITION,
                attr_val_raw=2,
            )
        )

        client.SetAttributeI32(
            nirfmxnr_types.SetAttributeI32Request(
                instrument=instr,
                selector_string=carrier_string,
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_DURATION,
                attr_val_raw=nirfmxnr_types.NIRFMXNR_INT32_PUSCH_DMRS_DURATION_SINGLE_SYMBOL,
            )
        )

        client.SetAttributeI32(
            nirfmxnr_types.SetAttributeI32Request(
                instrument=instr,
                selector_string=carrier_string,
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_DURATION,
                attr_val_raw=nirfmxnr_types.NIRFMXNR_INT32_PUSCH_DMRS_DURATION_SINGLE_SYMBOL,
            )
        )

        client.SetAttributeI32(
            nirfmxnr_types.SetAttributeI32Request(
                instrument=instr,
                selector_string=carrier_string,
                attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_PUSCH_DMRS_ADDITIONAL_POSITIONS,
                attr_val_raw=0,
            )
        )

    if auto_level:
        auto_level_response = client.AutoLevel(
            nirfmxnr_types.AutoLevelRequest(
                instrument=instr, selector_string="", measurement_interval=10.0e-3
            )
        )
        reference_level = auto_level_response.reference_level
        print(f"Reference level (dBm)        : {reference_level}\n")
    else:
        client.CfgReferenceLevel(
            nirfmxnr_types.CfgReferenceLevelRequest(
                instrument=instr, selector_string="", reference_level=0.0
            )
        )

    client.SelectMeasurements(
        nirfmxnr_types.SelectMeasurementsRequest(
            instrument=instr,
            selector_string="",
            measurements=nirfmxnr_types.MEASUREMENT_TYPES_MODACC,
            enable_all_traces=True,
        )
    )

    client.SetAttributeI32(
        nirfmxnr_types.SetAttributeI32Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_MODACC_SYNCHRONIZATION_MODE,
            attr_val_raw=nirfmxnr_types.NIRFMXNR_INT32_MODACC_SYNCHRONIZATION_MODE_SLOT,
        )
    )

    client.SetAttributeI32(
        nirfmxnr_types.SetAttributeI32Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_LENGTH_UNIT,
            attr_val_raw=nirfmxnr_types.NIRFMXNR_INT32_MODACC_MEASUREMENT_LENGTH_UNIT_SLOT,
        )
    )

    client.SetAttributeF64(
        nirfmxnr_types.SetAttributeF64Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_OFFSET,
            attr_val=0.0,
        )
    )

    client.SetAttributeF64(
        nirfmxnr_types.SetAttributeF64Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_MODACC_MEASUREMENT_LENGTH,
            attr_val=1.0,
        )
    )

    client.SetAttributeI32(
        nirfmxnr_types.SetAttributeI32Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_MODACC_AVERAGING_ENABLED,
            attr_val_raw=nirfmxnr_types.NIRFMXNR_INT32_MODACC_AVERAGING_ENABLED_FALSE,
        )
    )

    client.SetAttributeI32(
        nirfmxnr_types.SetAttributeI32Request(
            instrument=instr,
            selector_string="",
            attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_MODACC_AVERAGING_COUNT,
            attr_val_raw=10,
        )
    )

    initiate_response = client.Initiate(
        nirfmxnr_types.InitiateRequest(
            instrument=instr,
            selector_string="",
            result_name="",
        )
    )
    check_for_warning(initiate_response, instr)

    # Fetch results
    composite_rms_evm_mean = [
        [0.0] * NUMBER_OF_COMPONENT_CARRIERS for i in range(NUMBER_OF_SUBBLOCKS)
    ]
    composite_peak_evm_maximum = [
        [0.0] * NUMBER_OF_COMPONENT_CARRIERS for i in range(NUMBER_OF_SUBBLOCKS)
    ]
    composite_peak_evm_slot_index = [
        [0.0] * NUMBER_OF_COMPONENT_CARRIERS for i in range(NUMBER_OF_SUBBLOCKS)
    ]
    composite_peak_evm_symbol_index = [
        [0.0] * NUMBER_OF_COMPONENT_CARRIERS for i in range(NUMBER_OF_SUBBLOCKS)
    ]
    composite_peak_evm_subcarrier_index = [
        [0.0] * NUMBER_OF_COMPONENT_CARRIERS for i in range(NUMBER_OF_SUBBLOCKS)
    ]
    component_carrier_frequency_error_mean = [
        [0.0] * NUMBER_OF_COMPONENT_CARRIERS for i in range(NUMBER_OF_SUBBLOCKS)
    ]
    component_carrier_iq_origin_offset_mean = [
        [0.0] * NUMBER_OF_COMPONENT_CARRIERS for i in range(NUMBER_OF_SUBBLOCKS)
    ]
    component_carrier_iq_gain_imbalance_mean = [
        [0.0] * NUMBER_OF_COMPONENT_CARRIERS for i in range(NUMBER_OF_SUBBLOCKS)
    ]
    component_carrier_quadrature_error_mean = [
        [0.0] * NUMBER_OF_COMPONENT_CARRIERS for i in range(NUMBER_OF_SUBBLOCKS)
    ]
    in_band_emission_margin = [
        [0.0] * NUMBER_OF_COMPONENT_CARRIERS for i in range(NUMBER_OF_SUBBLOCKS)
    ]

    for i in range(NUMBER_OF_SUBBLOCKS):
        build_subblock_string_response = client.BuildSubblockString(
            nirfmxnr_types.BuildSubblockStringRequest(
                selector_string="",
                subblock_number=i,
            )
        )
        check_for_warning(build_subblock_string_response, instr)
        subblock_string = build_subblock_string_response.selector_string_out

        for j in range(NUMBER_OF_COMPONENT_CARRIERS):
            build_carrier_string_response = client.BuildCarrierString(
                nirfmxnr_types.BuildCarrierStringRequest(
                    selector_string=subblock_string,
                    carrier_number=j,
                )
            )
            check_for_warning(build_carrier_string_response, instr)
            carrier_string = build_carrier_string_response.selector_string_out

            modacc_fetch_composite_evm = client.ModAccFetchCompositeEVM(
                nirfmxnr_types.ModAccFetchCompositeEVMRequest(
                    instrument=instr, selector_string=carrier_string, timeout=10.0
                )
            )
            check_for_warning(modacc_fetch_composite_evm, instr)
            composite_rms_evm_mean[i][j] = modacc_fetch_composite_evm.composite_rms_evm_mean
            composite_peak_evm_maximum[i][j] = modacc_fetch_composite_evm.composite_peak_evm_maximum

            modacc_fetch_composite_peak_evm_slot_index = client.GetAttributeI32(
                nirfmxnr_types.GetAttributeI32Request(
                    instrument=instr,
                    selector_string=carrier_string,
                    attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SLOT_INDEX,
                )
            )
            check_for_warning(modacc_fetch_composite_peak_evm_slot_index, instr)
            composite_peak_evm_slot_index[i][
                j
            ] = modacc_fetch_composite_peak_evm_slot_index.attr_val_raw

            modacc_fetch_composite_peak_evm_symbol_index = client.GetAttributeI32(
                nirfmxnr_types.GetAttributeI32Request(
                    instrument=instr,
                    selector_string=carrier_string,
                    attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SYMBOL_INDEX,
                )
            )
            check_for_warning(modacc_fetch_composite_peak_evm_symbol_index, instr)
            composite_peak_evm_symbol_index[i][
                j
            ] = modacc_fetch_composite_peak_evm_symbol_index.attr_val_raw

            modacc_fetch_composite_peak_evm_subcarrier_index = client.GetAttributeI32(
                nirfmxnr_types.GetAttributeI32Request(
                    instrument=instr,
                    selector_string=carrier_string,
                    attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPOSITE_PEAK_EVM_SUBCARRIER_INDEX,
                )
            )
            check_for_warning(modacc_fetch_composite_peak_evm_subcarrier_index, instr)
            composite_peak_evm_subcarrier_index[i][
                j
            ] = modacc_fetch_composite_peak_evm_subcarrier_index.attr_val_raw

            modacc_fetch_component_carrier_frequency_error_mean = client.GetAttributeF64(
                nirfmxnr_types.GetAttributeF64Request(
                    instrument=instr,
                    selector_string=carrier_string,
                    attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_FREQUENCY_ERROR_MEAN,
                )
            )
            check_for_warning(modacc_fetch_component_carrier_frequency_error_mean, instr)
            component_carrier_frequency_error_mean[i][
                j
            ] = modacc_fetch_component_carrier_frequency_error_mean.attr_val

            modacc_fetch_component_carrier_iq_origin_offset_mean = client.GetAttributeF64(
                nirfmxnr_types.GetAttributeF64Request(
                    instrument=instr,
                    selector_string=carrier_string,
                    attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_IQ_ORIGIN_OFFSET_MEAN,
                )
            )
            check_for_warning(modacc_fetch_component_carrier_iq_origin_offset_mean, instr)
            component_carrier_iq_origin_offset_mean[i][
                j
            ] = modacc_fetch_component_carrier_iq_origin_offset_mean.attr_val

            modacc_fetch_component_carrier_iq_gain_imbalance_mean = client.GetAttributeF64(
                nirfmxnr_types.GetAttributeF64Request(
                    instrument=instr,
                    selector_string=carrier_string,
                    attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_IQ_GAIN_IMBALANCE_MEAN,
                )
            )
            check_for_warning(modacc_fetch_component_carrier_iq_gain_imbalance_mean, instr)
            component_carrier_iq_gain_imbalance_mean[i][
                j
            ] = modacc_fetch_component_carrier_iq_gain_imbalance_mean.attr_val

            modacc_fetch_component_carrier_quadrature_error_mean = client.GetAttributeF64(
                nirfmxnr_types.GetAttributeF64Request(
                    instrument=instr,
                    selector_string=carrier_string,
                    attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_COMPONENT_CARRIER_QUADRATURE_ERROR_MEAN,
                )
            )
            check_for_warning(modacc_fetch_component_carrier_quadrature_error_mean, instr)
            component_carrier_quadrature_error_mean[i][
                j
            ] = modacc_fetch_component_carrier_quadrature_error_mean.attr_val

            modacc_fetch_in_band_emission_margin = client.GetAttributeF64(
                nirfmxnr_types.GetAttributeF64Request(
                    instrument=instr,
                    selector_string=carrier_string,
                    attribute_id=nirfmxnr_types.NIRFMXNR_ATTRIBUTE_MODACC_RESULTS_IN_BAND_EMISSION_MARGIN,
                )
            )
            check_for_warning(modacc_fetch_in_band_emission_margin, instr)
            in_band_emission_margin[i][j] = modacc_fetch_in_band_emission_margin.attr_val

    print("************************* ModAcc Results *************************")
    for i in range(NUMBER_OF_SUBBLOCKS):
        print(f"Subblock  :   {i}\n")
        for j in range(NUMBER_OF_COMPONENT_CARRIERS):
            print(f"Carrier  :   {j}")
            print(f"Composite RMS EVM Mean (%)                    : {composite_rms_evm_mean[i][j]}")
            print(
                f"Composite Peak EVM Maximum (%)                : {composite_peak_evm_maximum[i][j]}"
            )
            print(
                f"Composite Peak EVM Slot Index                 : {composite_peak_evm_slot_index[i][j]}"
            )
            print(
                f"Composite Peak EVM Symbol Index               : {composite_peak_evm_symbol_index[i][j]}"
            )
            print(
                f"Composite Peak EVM Subcarrier Index           : {composite_peak_evm_subcarrier_index[i][j]}\n"
            )
            print(
                f"Component Carrier Frequency Error Mean (Hz)   : {component_carrier_frequency_error_mean[i][j]}"
            )
            print(
                f"Component Carrier IQ Origin Offset Mean (dBc) : {component_carrier_iq_origin_offset_mean[i][j]}"
            )
            print(
                f"Component Carrier IQ Gain Imbalance Mean (dB) : {component_carrier_iq_gain_imbalance_mean[i][j]}"
            )
            print(
                f"Component Carrier Quadrature Error Mean (Hz)  : {component_carrier_quadrature_error_mean[i][j]}"
            )
            print(
                f"In-Band Emission Margin (dB)                  : {in_band_emission_margin[i][j]}\n"
            )
            print("******************************************************************\n")

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
        client.Close(nirfmxnr_types.CloseRequest(instrument=instr, force_destroy=False))
