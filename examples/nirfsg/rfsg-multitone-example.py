r"""Generate any number and power of tones using RFSG.

At least one tone needs to be at 0 dB. Use Power level to set the power of all the tones relative to their selected power.
The minimum separation is mandated by a variable below. A smaller number needs more samples to meet the needs.
The maximum separation is mandated by the instrument used.

The gRPC API is built from the C API. NI-RFSG documentation is installed with the driver at:
  C:\Program Files (x86)\IVI Foundation\IVI\Drivers\niRFSG\documentation\English\RFSG.chm

Getting Started:

To run this example, install "NI-RFSG Driver" on the server machine:
  https://www.ni.com/en-us/support/downloads/drivers/download.ni-rfsg.html

For instructions on how to use protoc to generate gRPC client interfaces, see our "Creating a gRPC
Client" wiki page:
  https://github.com/ni/grpc-device/wiki/Creating-a-gRPC-Client

Refer to the NI-RFSG gRPC Wiki for the latest C Function Reference:
  https://github.com/ni/grpc-device/wiki/NI-RFSG-C-Function-Reference

Running from command line:

Server machine's IP address, port number, and physical channel name can be passed as separate
command line arguments.
  > python getting-started-single-tone-generation.py <server_address> <port_number> <resource_name>
If they are not passed in as command line arguments, then by default the server address will be
"localhost:31763", with "SimulatedRFSG" as the physical channel name.
"""  # noqa: W505

import math
import sys

import grpc
import nidevice_pb2 as nidevice_grpc
import nirfsg_pb2 as nirfsg_types
import nirfsg_pb2_grpc as grpc_nirfsg
import numpy as np


SERVER_ADDRESS = "localhost"
SERVER_PORT = "31763"
SESSION_NAME = "NI-RFSG-Session"

# Resource name, channel name and options for a simulated 5841 client.
RESOURCE = "5840_1"
OPTIONS = ""

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
client = grpc_nirfsg.NiRFSGStub(channel)
vi = None


def check_for_warning(response, vi):
    """Print to console if the status indicates a warning."""
    if response.status > 0:
        warning_message = client.ErrorMessage(
            nirfsg_types.ErrorMessageRequest(vi=vi, error_code=response.status)
        )
        sys.stderr.write(f"{warning_message.error_message}\nWarning status: {response.status}\n")


class Tone:
    """Class definition for tones.

    Define the tone with relative offset from the carrier frequency in Hz (relative to the
     generator center frequency).
    Relative power level in dBc (relative to the generator defined power level).
    """

    def __init__(self, offset_hz, gain_db):
        """Construct each tone using a relative offset in Hz and relative power in dBc."""
        self.offset_hz = offset_hz
        self.gain_db = gain_db

    def __repr__(self):
        """Make a string with Tones information."""
        return "Offset: {0} Hz and Gain: {1} dB".format(self.offset_hz, self.gain_db)


def gcd(my_list):
    """Return the greatest common denominator.

    Given a list of numbers find the smallest number that can divide them all.
    """
    result = my_list[0]
    for x in my_list[1:]:
        if result < x:
            temp = result
            result = x
            x = temp
        while x != 0:
            temp = x
            x = result % x
            result = temp
    return result


try:
    response = client.InitWithOptions(
        nirfsg_types.InitWithOptionsRequest(
            session_name=SESSION_NAME, resource_name=RESOURCE, option_string=OPTIONS
        )
    )
    vi = response.vi
    # tones to Generate
    # tones power is relative to the generated power.

    # Test Cases
    # tones = [Tone(0, 0)]
    tones = [Tone(-1e6, 0), Tone(1e6, 0)]
    # tones = [Tone(-1E6, 0), Tone(1E6, 0), Tone(-5E6, 0), Tone(5E6, 0), Tone(-10E6, 0)]
    # tones = [Tone(-1E6, 0), Tone(1E6, -5), Tone(2.5E6, -10), Tone(3.9E6, -20), Tone(-10E6, 0)]
    # tones = [Tone(100E3, 0), Tone(-835E3, -6)]
    # tones = [Tone(10E6, -3), Tone(-100.1E6, -6)]
    # tones = [Tone(1E6, 2.45), Tone(-50E6, -6)]
    # tones = [Tone(499E6, 0), Tone(-499E6, -6)]
    # tones = [Tone(1E6, 0), Tone(-50E6, -6)] + [Tone(499E6, 0), Tone(-499E6, -6)]
    # tones = [Tone(0, 0), Tone(-835E3, -6)]
    # tones = [Tone(2501200001-3e9, 0), Tone(3405200000-3e9, 0), Tone(3305300000-3e9, 0)]

    # Error Test Cases
    # tones = [Tone(0, -6)]
    # tones = [Tone(100E6, -10), Tone(-100E6, -10)]
    # tones = [Tone(1E9, 0), Tone(-100.1E6, -6)]
    # tones = [Tone(100E6, -20)]
    # tones = [Tone(1, 0), Tone(10E6, -6)]

    min_sampling_rate_hz = 4e6
    min_frequency_step_hz = 5000
    min_waveform_size = 100000
    print(tones)

    # Define the instrument and RF parameters
    print("Setting measurement parameters.. ", end="")
    center_frequency = 3e9
    rfsg_power_level_dbm = -10
    rfsg_resource_name = "5840_1"
    rfsg_selected_ports = ""
    rfsg_waveform_name = "wfm"
    rfsg_script = "script GenerateWaveform repeat forever generate wfm end repeat end script"
    rfsg_external_attenuation = 0.0
    rfsg_frequency_reference_source = nirfsg_types.REF_CLOCK_SOURCE_ONBOARD_CLOCK
    rfsg_automatic_shared_lo = nirfsg_types.NIRFSG_INT32_ENABLE_VALUES_DISABLE
    # Max rate 2.5x the max offset
    sampling_rate_hz = max([abs(tone.offset_hz) for tone in tones] + [min_sampling_rate_hz]) * 2.5
    # Greatest common denominator of the tones we need to make it divisible by Sampling Rate
    # thus we add it to the list it and then we divide it by a minimum resolution
    frequency_step_hz = max(
        gcd([abs(tone.offset_hz) for tone in tones] + [sampling_rate_hz]) / min_frequency_step_hz,
        sampling_rate_hz / min_waveform_size,
    )
    # Sum all the tones power for scaling on the SG power
    tones_power = 10 * math.log(sum([math.pow(10, tone.gain_db / 10) for tone in tones]), 10)
    print(
        "FrequencyStep = {} Hz and Sampling Frequency = {} Hz and Tone Total Power = {}".format(
            frequency_step_hz, sampling_rate_hz, tones_power
        )
    )

    client.SetAttributeViString(
        nirfsg_types.SetAttributeViStringRequest(
            vi=vi,
            channel_name="",
            attribute_id=nirfsg_types.NIRFSG_ATTRIBUTE_SELECTED_PORTS,
            value_raw=rfsg_selected_ports,
        )
    )

    # We want the tones to be at a specific power, for that reason, we adjust
    # generator power to the desired power + whatever the tones constructive
    # interference. This was computed above as the "tones power"
    client.SetAttributeViReal64(
        nirfsg_types.SetAttributeViReal64Request(
            vi=vi,
            channel_name="",
            attribute_id=nirfsg_types.NIRFSG_ATTRIBUTE_POWER_LEVEL,
            value_raw=rfsg_power_level_dbm + tones_power,
        )
    )

    client.SetAttributeViReal64(
        nirfsg_types.SetAttributeViReal64Request(
            vi=vi,
            channel_name="",
            attribute_id=nirfsg_types.NIRFSG_ATTRIBUTE_EXTERNAL_GAIN,
            value_raw=-rfsg_external_attenuation,
        )
    )

    client.SetAttributeViReal64(
        nirfsg_types.SetAttributeViReal64Request(
            vi=vi,
            channel_name="",
            attribute_id=nirfsg_types.NIRFSG_ATTRIBUTE_FREQUENCY,
            value_raw=center_frequency,
        )
    )

    # Coerce Settings
    for item in tones:
        item.offset_hz = np.floor(item.offset_hz / frequency_step_hz) * frequency_step_hz
        print(item)
    # Init initial waveform
    waveform = np.full(int(1 / frequency_step_hz * sampling_rate_hz), 0 + 0j)
    buffer = np.full(int(1 / frequency_step_hz * sampling_rate_hz), 1 + 0j)
    # Create tones on waveform
    for item in tones:
        phase_drif = item.offset_hz / sampling_rate_hz * 2 * np.pi
        offset_waveform = [1 * np.exp(i * phase_drif * 1j) for i in np.arange(0, len(waveform))]
        waveform = waveform + np.array(offset_waveform) * math.pow(10, item.gain_db / 20)
    # Waveform needs to normalize as we will use Peak Power Mode. This is easier to
    #  integrate with other pieces of code as it's the same mode.
    # This means that what we write magnitude (sqrt(I^2 + Q^2)) be larger than 1. 1 is
    #  the maximum and corresponds to the peak power setting.
    # If the power is set to -10 dBm, then a 1 means that the instantaneous power
    #  will be at -10 dBm.
    # To normalize, we divide all numbers by the peak to average ratio.
    # If the signal has gaps, then we should not use that section to compute power.

    waveform_papr = 10 * math.log(
        np.max(np.square(abs(waveform))) / np.mean(np.square(abs(waveform))), 10
    )
    waveform_normalized = waveform / math.pow(10, waveform_papr / 10)
    print(
        f"Previous max value is: {np.max(abs(waveform))} average value is: {np.mean(abs(waveform))} and new max value is: {np.max(abs(waveform_normalized))} and PAPR: {waveform_papr}"
    )
    # convert to NI complex datatype
    iq_ni_format = [
        nidevice_grpc.NIComplexNumberF32(real=sample.real, imaginary=sample.imag)
        for sample in waveform_normalized
    ]

    client.ConfigurePowerLevelType(
        nirfsg_types.ConfigurePowerLevelTypeRequest(
            vi=vi, power_level_type=nirfsg_types.POWER_LEVEL_TYPE_PEAK_POWER
        )
    )

    client.WriteArbWaveformComplexF32(
        nirfsg_types.WriteArbWaveformComplexF32Request(
            vi=vi, waveform_name="wfm", wfm_data=iq_ni_format, more_data_pending=False
        )
    )
    client.SetAttributeViReal64(
        nirfsg_types.SetAttributeViReal64Request(
            vi=vi,
            channel_name="waveform::wfm",
            attribute_id=nirfsg_types.NIRFSG_ATTRIBUTE_WAVEFORM_IQ_RATE,
            value_raw=sampling_rate_hz,
        )
    )

    # Example of how to set/get parameters of a waveform, the channel_name needs to have the
    #  prefix waveform:: before the name of the waveform
    client.SetAttributeViReal64(
        nirfsg_types.SetAttributeViReal64Request(
            vi=vi,
            channel_name="waveform::wfm",
            attribute_id=nirfsg_types.NIRFSG_ATTRIBUTE_WAVEFORM_PAPR,
            value_raw=waveform_papr,
        )
    )

    response_papr = client.GetAttributeViReal64(
        nirfsg_types.GetAttributeViReal64Request(
            vi=vi,
            channel_name="waveform::wfm",
            attribute_id=nirfsg_types.NIRFSG_ATTRIBUTE_WAVEFORM_PAPR,
        )
    )
    waveform_papr = response_papr.value
    # The runtime scaling is to help reduce the chance of overflow the DAC by reducing
    #  the signal a bit more (1.5 dB). The driver compensates for this reduction and
    #  no need to compensate for this.
    runtime_scaling = 1.5
    client.SetAttributeViReal64(
        nirfsg_types.SetAttributeViReal64Request(
            vi=vi,
            channel_name="waveform::wfm",
            attribute_id=nirfsg_types.NIRFSG_ATTRIBUTE_WAVEFORM_RUNTIME_SCALING,
            value_raw=-runtime_scaling,
        )
    )
    client.SetAttributeViReal64(
        nirfsg_types.SetAttributeViReal64Request(
            vi=vi,
            channel_name="waveform::wfm",
            attribute_id=nirfsg_types.NIRFSG_ATTRIBUTE_WAVEFORM_SIGNAL_BANDWIDTH,
            value_raw=8e6,
        )
    )

    client.ConfigureGenerationMode(
        nirfsg_types.ConfigureGenerationModeRequest(
            vi=vi, generation_mode=nirfsg_types.GENERATION_MODE_SCRIPT
        )
    )

    client.WriteScript(nirfsg_types.WriteScriptRequest(vi=vi, script=rfsg_script))

    initiate_response = client.Initiate(nirfsg_types.InitiateRequest(vi=vi))
    check_for_warning(initiate_response, vi)
    print("Generating tone...")
    input("Press Any Key to Stop Generation")

    client.Abort(nirfsg_types.AbortRequest(vi=vi))
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
    print(f"{error_message}")
finally:
    if vi:
        client.ConfigureOutputEnabled(
            nirfsg_types.ConfigureOutputEnabledRequest(output_enabled=False)
        )
        client.Close(nirfsg_types.CloseRequest(vi=vi))
