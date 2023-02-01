"""Generate any number and power of tones.
At least one tone needs to be at 0 dB. Use Power level to set the power of all the tones relative to their selected power.
The minimum separation is mandated by a variable below. A smaller number needs more samples to meet the needs.
The maximum separation is mandated by the instrument used.

Gerardo orozco
RF Systems R&D Semiconductor
National Instruments

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

import sys
import math
import numpy as np

import os
sys.path.append(os.getcwd())

import grpc
import nirfsg_pb2 as nirfsg_types
import nirfsg_pb2_grpc as grpc_nirfsg
import nidevice_pb2 as nidevice_grpc


SERVER_ADDRESS = "mercury07"
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
    def __init__(self,offsetHz, gaindB):
        self.offsetHz = offsetHz
        self.gaindB = gaindB
    def __repr__(self):
        return 'Offset: {0} Hz and Gain: {1} dB'.format(self.offsetHz,self.gaindB)

def gcd(my_list):
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
    #Tones to Generate

    #Documentation
    #Tones power is relative to the generated power.

    #Test Cases
    #Tones = [Tone(0, 0)]
    #Tones = [Tone(-1E6, 0), Tone(1E6, 0)]
    Tones = [Tone(-1E6, 0), Tone(1E6, 0), Tone(-5E6, 0), Tone(5E6, 0), Tone(-10E6, 0), Tone(10E6, 0)]
    #Tones = [Tone(-1E6, 0), Tone(1E6, -5), Tone(2.5E6, -10), Tone(3.9E6, -20), Tone(-10E6, 0)]
    #Tones = [Tone(100E3, 0), Tone(-835E3, -6)]
    #Tones = [Tone(10E6, -3), Tone(-100.1E6, -6)]
    #Tones = [Tone(1E6, 2.45), Tone(-50E6, -6)]
    #Tones = [Tone(499E6, 0), Tone(-499E6, -6)]
    #Tones = [Tone(1E6, 0), Tone(-50E6, -6)] + [Tone(499E6, 0), Tone(-499E6, -6)]
    #Tones = [Tone(0, 0), Tone(-835E3, -6)]
    #Tones = [Tone(2501200001-3e9, 0), Tone(3405200000-3e9, 0), Tone(3305300000-3e9, 0)]

    #Error Test Cases
    #Tones = [Tone(0, -6)]
    #Tones = [Tone(100E6, -10), Tone(-100E6, -10)]
    #Tones = [Tone(1E9, 0), Tone(-100.1E6, -6)]
    #Tones = [Tone(100E6, -20)]
    #Tones = [Tone(1, 0), Tone(10E6, -6)]

    minSamplingRateHz = 4e6
    minFrequencyStepHz = 5000
    minWaveformSize = 100000
    print(Tones)


    # Define the instrument and RF parameters
    print("Setting measurement parameters.. ", end='')
    centerFrequency = 3e9
    rfsgPowerLevel_dBm = -10
    rfsgResourceName = '5840_1'    
    rfsgSelectedPorts = ""                                              
    rfsgWaveformName = "wfm"
    rfsg_script = 'script GenerateWaveform repeat forever generate wfm end repeat end script'
    rfsgExternalAttenuation = 0.0
    rfsgFrequencyReferenceSource = nirfsg_types.REF_CLOCK_SOURCE_ONBOARD_CLOCK
    rfsgAutomaticSharedLO = nirfsg_types.NIRFSG_INT32_ENABLE_VALUES_DISABLE
    SamplingRateHz = max([abs(tone.offsetHz) for tone in Tones] + [minSamplingRateHz]) * 2.5 #Max rate 2.5x the max offset
    #Greatest common denominator of the tones we need to make it divisible by Sampling Rate so we add it to the list it and then we divide it by a minimum resolution
    FrequencyStepHz = max(gcd([abs(tone.offsetHz) for tone in Tones] + [SamplingRateHz])/minFrequencyStepHz, SamplingRateHz/minWaveformSize) 
    #Sum all the tones power for scaling on the SG power
    TonesPower = 10*math.log(sum([math.pow(10,tone.gaindB/10) for tone in Tones]),10)
    print("FrequencyStep = {} Hz and Sampling Frequency = {} Hz and Tone Total Power = {}".format(FrequencyStepHz, SamplingRateHz, TonesPower))

    client.SetAttributeViString(nirfsg_types.SetAttributeViStringRequest(vi=vi, 
                                channel_name="", 
                                attribute_id=nirfsg_types.NIRFSG_ATTRIBUTE_SELECTED_PORTS, 
                                value_raw = rfsgSelectedPorts)
                                )

    
    # We wante the TONES to be at a specific power, for that reason, we adjust our generator power to the desired power + whatever the tones constructive interference
    # This was computed above as the "tones power"
    client.SetAttributeViReal64(nirfsg_types.SetAttributeViReal64Request(
                            vi = vi,
                            channel_name = "",
                            attribute_id = nirfsg_types.NIRFSG_ATTRIBUTE_POWER_LEVEL,
                            value_raw = rfsgPowerLevel_dBm + TonesPower)
                            )

    client.SetAttributeViReal64(nirfsg_types.SetAttributeViReal64Request(
                            vi = vi,
                            channel_name = "",
                            attribute_id = nirfsg_types.NIRFSG_ATTRIBUTE_EXTERNAL_GAIN,
                            value_raw = -rfsgExternalAttenuation)
                            )
    
    client.SetAttributeViReal64(nirfsg_types.SetAttributeViReal64Request(
                            vi = vi,
                            channel_name = "",
                            attribute_id = nirfsg_types.NIRFSG_ATTRIBUTE_FREQUENCY,
                            value_raw = centerFrequency)
                            )

    #Coarce Settings
    for item in Tones:
        item.offsetHz = np.floor(item.offsetHz/FrequencyStepHz)*FrequencyStepHz
        print(item)


    #Init initial waveform
    waveform = np.full(int(1/FrequencyStepHz * SamplingRateHz), 0+0j)
    Buffer = np.full(int(1/FrequencyStepHz * SamplingRateHz), 1+0j)
    #Create Tones on waveform
    for item in Tones:
        phaseDrif = item.offsetHz/SamplingRateHz * 2 * np.pi
        OffsetWaveform = [1*np.exp(i*phaseDrif*1j) for i in np.arange(0,len(waveform))]
        waveform = waveform + np.array(OffsetWaveform) * math.pow(10,item.gaindB/20)

    
    # Waveform needs to normalize as we will use Peak Power Mode. This is easier to integrate with other pieces of code as it's the same mode.
    # This means that what we write magnitude (sqrt(I^2 + Q^2)) be larger than 1. 1 is the maximum and corresponds to the peak power setting.
    # If the power is set to -10 dBm, then a 1 means that the instantaneous power will be at -10 dBm.
    # To normalize, we divide all numbers by the peak to average ratio. If the signal has gaps, then we should not use that section to compute power.
    
    waveform_papr = 10*math.log(np.max(np.square(abs(waveform)))/np.mean(np.square(abs(waveform))), 10)
    waveformNorm = waveform/math.pow(10,waveform_papr/10)
    print(f"Previous max value is: {np.max(abs(waveform))} average value is: {np.mean(abs(waveform))} and new max value is: {np.max(abs(waveformNorm))} and PAPR: {waveform_papr}")
    # convert to NI complex datatype
    iqNI = [nidevice_grpc.NIComplexNumberF32(real = sample.real, imaginary = sample.imag) for sample in waveformNorm]
    
    client.ConfigurePowerLevelType(nirfsg_types.ConfigurePowerLevelTypeRequest(
                            vi = vi,
                            power_level_type = nirfsg_types.POWER_LEVEL_TYPE_PEAK_POWER)
                            )

    client.WriteArbWaveformComplexF32(nirfsg_types.WriteArbWaveformComplexF32Request(
                            vi = vi,
                            waveform_name = 'wfm',
                            wfm_data = iqNI,
                            more_data_pending = False)
                            )
    client.SetAttributeViReal64(nirfsg_types.SetAttributeViReal64Request(
                            vi = vi,
                            channel_name = 'waveform::wfm',
                            attribute_id = nirfsg_types.NIRFSG_ATTRIBUTE_WAVEFORM_IQ_RATE,
                            value_raw = SamplingRateHz)
                            )
    
    # Example of how to set/get parameters of a waveform, the channel_name needs to have the prefix waveform:: before the name of the waveform
    client.SetAttributeViReal64(nirfsg_types.SetAttributeViReal64Request(
                            vi = vi,
                            channel_name = 'waveform::wfm',
                            attribute_id = nirfsg_types.NIRFSG_ATTRIBUTE_WAVEFORM_PAPR,
                            value_raw = waveform_papr)
                            )

    response = client.GetAttributeViReal64(nirfsg_types.GetAttributeViReal64Request(
                            vi = vi,
                            channel_name = 'waveform::wfm',
                            attribute_id = nirfsg_types.NIRFSG_ATTRIBUTE_WAVEFORM_PAPR)
                            )
    waveform_papr = response.value
    # The runtime scaling is to help reduce the chance of overflow the DAC by reducing the signal a little bit more. The driver compensates for this reduction and no need to compensate for this.
    runtimeScaling = 1.5
    client.SetAttributeViReal64(nirfsg_types.SetAttributeViReal64Request(
                            vi = vi,
                            channel_name = 'waveform::wfm',
                            attribute_id = nirfsg_types.NIRFSG_ATTRIBUTE_WAVEFORM_RUNTIME_SCALING,
                            value_raw = -runtimeScaling)
                            )
    client.SetAttributeViReal64(nirfsg_types.SetAttributeViReal64Request(
                            vi = vi,
                            channel_name = 'waveform::wfm',
                            attribute_id = nirfsg_types.NIRFSG_ATTRIBUTE_WAVEFORM_SIGNAL_BANDWIDTH,
                            value_raw = 8E6)
                            )

    client.ConfigureGenerationMode(nirfsg_types.ConfigureGenerationModeRequest(
                            vi = vi,
                            generation_mode = nirfsg_types.GENERATION_MODE_SCRIPT)
                            )

    client.WriteScript(nirfsg_types.WriteScriptRequest(
                            vi = vi,
                            script = rfsg_script)
                            )

    initiate_response = client.Initiate(nirfsg_types.InitiateRequest(vi=vi))
    check_for_warning(initiate_response, vi)
    print("Generating tone...")
    input("Press Any Key to Stop Generation")

    client.Abort(nirfsg_types.AbortRequest(vi=vi))

except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
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