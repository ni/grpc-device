//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Compilation test for the NI-rfmxpulse Metadata
//---------------------------------------------------------------------
#include "nirfmxpulse_library.h"

namespace nirfmxpulse_grpc {

int32 AbortMeasurements(niRFmxInstrHandle instrumentHandle, char selectorString[])
{
  return RFmxPulse_AbortMeasurements(instrumentHandle, selectorString);
}

int32 AnalyzeIQ1Waveform(niRFmxInstrHandle instrumentHandle, char selectorString[], char resultName[], float64 x0, float64 dx, NIComplexSingle iq[], int32 arraySize, int32 reset, int64 reserved)
{
  return RFmxPulse_AnalyzeIQ1Waveform(instrumentHandle, selectorString, resultName, x0, dx, iq, arraySize, reset, reserved);
}

int32 AnalyzeIQ1WaveformSplit(niRFmxInstrHandle instrumentHandle, char selectorString[], char resultName[], float64 x0, float64 dx, float32 iqi[], float32 iqq[], int32 arraySize, int32 reset, int64 reserved)
{
  return RFmxPulse_AnalyzeIQ1WaveformSplit(instrumentHandle, selectorString, resultName, x0, dx, iqi, iqq, arraySize, reset, reserved);
}

int32 AutoLevel(niRFmxInstrHandle instrumentHandle, char selectorString[], float64 bandwidth, float64 measurementInterval, float64* referenceLevel)
{
  return RFmxPulse_AutoLevel(instrumentHandle, selectorString, bandwidth, measurementInterval, referenceLevel);
}

int32 BuildSignalString(char signalName[], char resultName[], int32 selectorStringLength, char selectorString[])
{
  return RFmxPulse_BuildSignalString(signalName, resultName, selectorStringLength, selectorString);
}

int32 Cfg1ReferenceWaveform(niRFmxInstrHandle instrumentHandle, char selectorString[], float64 x0, float64 dx, NIComplexSingle referenceWaveform[], int32 arraySize)
{
  return RFmxPulse_Cfg1ReferenceWaveform(instrumentHandle, selectorString, x0, dx, referenceWaveform, arraySize);
}

int32 Cfg1ReferenceWaveformSplit(niRFmxInstrHandle instrumentHandle, char selectorString[], float64 x0, float64 dx, float32 referenceWaveformI[], float32 referenceWaveformQ[], int32 arraySize)
{
  return RFmxPulse_Cfg1ReferenceWaveformSplit(instrumentHandle, selectorString, x0, dx, referenceWaveformI, referenceWaveformQ, arraySize);
}

int32 CfgDigitalEdgeTrigger(niRFmxInstrHandle instrumentHandle, char selectorString[], char digitalEdgeSource[], int32 digitalEdge, float64 triggerDelay, int32 enableTrigger)
{
  return RFmxPulse_CfgDigitalEdgeTrigger(instrumentHandle, selectorString, digitalEdgeSource, digitalEdge, triggerDelay, enableTrigger);
}

int32 CfgExternalAttenuation(niRFmxInstrHandle instrumentHandle, char selectorString[], float64 externalAttenuation)
{
  return RFmxPulse_CfgExternalAttenuation(instrumentHandle, selectorString, externalAttenuation);
}

int32 CfgFrequency(niRFmxInstrHandle instrumentHandle, char selectorString[], float64 centerFrequency)
{
  return RFmxPulse_CfgFrequency(instrumentHandle, selectorString, centerFrequency);
}

int32 CfgFrequencyReference(niRFmxInstrHandle instrumentHandle, char channelName[], char frequencyReferenceSource[], float64 frequencyReferenceFrequency)
{
  return RFmxPulse_CfgFrequencyReference(instrumentHandle, channelName, frequencyReferenceSource, frequencyReferenceFrequency);
}

int32 CfgIQPowerEdgeTrigger(niRFmxInstrHandle instrumentHandle, char selectorString[], char iqPowerEdgeSource[], int32 iqPowerEdgeSlope, float64 iqPowerEdgeLevel, float64 triggerDelay, int32 triggerMinQuietTimeMode, float64 triggerMinQuietTimeDuration, int32 iqPowerEdgeLevelType, int32 enableTrigger)
{
  return RFmxPulse_CfgIQPowerEdgeTrigger(instrumentHandle, selectorString, iqPowerEdgeSource, iqPowerEdgeSlope, iqPowerEdgeLevel, triggerDelay, triggerMinQuietTimeMode, triggerMinQuietTimeDuration, iqPowerEdgeLevelType, enableTrigger);
}

int32 CfgMechanicalAttenuation(niRFmxInstrHandle instrumentHandle, char channelName[], int32 mechanicalAttenuationAuto, float64 mechanicalAttenuationValue)
{
  return RFmxPulse_CfgMechanicalAttenuation(instrumentHandle, channelName, mechanicalAttenuationAuto, mechanicalAttenuationValue);
}

int32 CfgRF(niRFmxInstrHandle instrumentHandle, char selectorString[], float64 centerFrequency, float64 referenceLevel, float64 externalAttenuation)
{
  return RFmxPulse_CfgRF(instrumentHandle, selectorString, centerFrequency, referenceLevel, externalAttenuation);
}

int32 CfgRFAttenuation(niRFmxInstrHandle instrumentHandle, char channelName[], int32 rfAttenuationAuto, float64 rfAttenuationValue)
{
  return RFmxPulse_CfgRFAttenuation(instrumentHandle, channelName, rfAttenuationAuto, rfAttenuationValue);
}

int32 CfgReferenceLevel(niRFmxInstrHandle instrumentHandle, char selectorString[], float64 referenceLevel)
{
  return RFmxPulse_CfgReferenceLevel(instrumentHandle, selectorString, referenceLevel);
}

int32 CfgSoftwareEdgeTrigger(niRFmxInstrHandle instrumentHandle, char selectorString[], float64 triggerDelay, int32 enableTrigger)
{
  return RFmxPulse_CfgSoftwareEdgeTrigger(instrumentHandle, selectorString, triggerDelay, enableTrigger);
}

int32 CheckMeasurementStatus(niRFmxInstrHandle instrumentHandle, char selectorString[], int32* isDone)
{
  return RFmxPulse_CheckMeasurementStatus(instrumentHandle, selectorString, isDone);
}

int32 ClearAllNamedResults(niRFmxInstrHandle instrumentHandle, char selectorString[])
{
  return RFmxPulse_ClearAllNamedResults(instrumentHandle, selectorString);
}

int32 ClearNamedResult(niRFmxInstrHandle instrumentHandle, char selectorString[])
{
  return RFmxPulse_ClearNamedResult(instrumentHandle, selectorString);
}

int32 CloneSignalConfiguration(niRFmxInstrHandle instrumentHandle, char oldSignalName[], char newSignalName[])
{
  return RFmxPulse_CloneSignalConfiguration(instrumentHandle, oldSignalName, newSignalName);
}

int32 Close(niRFmxInstrHandle instrumentHandle, int32 forceDestroy)
{
  return RFmxPulse_Close(instrumentHandle, forceDestroy);
}

int32 Commit(niRFmxInstrHandle instrumentHandle, char selectorString[])
{
  return RFmxPulse_Commit(instrumentHandle, selectorString);
}

int32 CreateSignalConfiguration(niRFmxInstrHandle instrumentHandle, char signalName[])
{
  return RFmxPulse_CreateSignalConfiguration(instrumentHandle, signalName);
}

int32 DeleteSignalConfiguration(niRFmxInstrHandle instrumentHandle, char signalName[])
{
  return RFmxPulse_DeleteSignalConfiguration(instrumentHandle, signalName);
}

int32 DisableTrigger(niRFmxInstrHandle instrumentHandle, char selectorString[])
{
  return RFmxPulse_DisableTrigger(instrumentHandle, selectorString);
}

int32 FetchAcquiredAmplitudeTrace(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 arraySize, float64* sampleDuration, float32 amplitude[], int32 amplitudeArraySize, int32* amplitudeActualArraySize, int32 startIndex[], float64 startTimeStamp[], int32 startArraySize, int32* startActualArraySize)
{
  return RFmxPulse_FetchAcquiredAmplitudeTrace(instrumentHandle, selectorString, arraySize, sampleDuration, amplitude, amplitudeArraySize, amplitudeActualArraySize, startIndex, startTimeStamp, startArraySize, startActualArraySize);
}

int32 FetchAmplitudeTrace(niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* x0, float64* dx, float32 amplitude[], int32 arraySize, int32* actualArraySize)
{
  return RFmxPulse_FetchAmplitudeTrace(instrumentHandle, selectorString, timeout, x0, dx, amplitude, arraySize, actualArraySize);
}

int32 FetchBurstIntrapulseStabilityTrace(niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* x0, float64* dx, float32 intrapulseAverageAmplitudeStability[], float32 intrapulseAveragePhaseStability[], float32 intrapulseAverageTotalStability[], int32 arraySize, int32* actualArraySize)
{
  return RFmxPulse_FetchBurstIntrapulseStabilityTrace(instrumentHandle, selectorString, timeout, x0, dx, intrapulseAverageAmplitudeStability, intrapulseAveragePhaseStability, intrapulseAverageTotalStability, arraySize, actualArraySize);
}

int32 FetchBurstSelectedPositionStabilityTrace(niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* x0, float64* dx, float32 pulseAmplitudeStability[], float32 pulsePhaseStability[], float32 pulseTotalStability[], int32 arraySize, int32* actualArraySize)
{
  return RFmxPulse_FetchBurstSelectedPositionStabilityTrace(instrumentHandle, selectorString, timeout, x0, dx, pulseAmplitudeStability, pulsePhaseStability, pulseTotalStability, arraySize, actualArraySize);
}

int32 FetchFrequencyTrace(niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* x0, float64* dx, float32 frequency[], int32 arraySize, int32* actualArraySize)
{
  return RFmxPulse_FetchFrequencyTrace(instrumentHandle, selectorString, timeout, x0, dx, frequency, arraySize, actualArraySize);
}

int32 FetchIQTrace(niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* x0, float64* dx, NIComplexSingle iqData[], int32 arraySize, int32* actualArraySize)
{
  return RFmxPulse_FetchIQTrace(instrumentHandle, selectorString, timeout, x0, dx, iqData, arraySize, actualArraySize);
}

int32 FetchIQTraceSplit(niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* x0, float64* dx, float32 iqDataI[], float32 iqDataQ[], int32 arraySize, int32* actualArraySize)
{
  return RFmxPulse_FetchIQTraceSplit(instrumentHandle, selectorString, timeout, x0, dx, iqDataI, iqDataQ, arraySize, actualArraySize);
}

int32 FetchIntrapulseStabilityTrace(niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* x0, float64* dx, float32 intrapulseAmplitudeStability[], float32 intrapulsePhaseStability[], float32 intrapulseTotalStability[], int32 arraySize, int32* actualArraySize)
{
  return RFmxPulse_FetchIntrapulseStabilityTrace(instrumentHandle, selectorString, timeout, x0, dx, intrapulseAmplitudeStability, intrapulsePhaseStability, intrapulseTotalStability, arraySize, actualArraySize);
}

int32 FetchMultipleMeasurementPointsStabilityTrace(niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* x0, float64* dx, float32 pulseAverageAmplitudeStability[], float32 pulseAveragePhaseStability[], float32 pulseAverageTotalStability[], int32 arraySize, int32* actualArraySize)
{
  return RFmxPulse_FetchMultipleMeasurementPointsStabilityTrace(instrumentHandle, selectorString, timeout, x0, dx, pulseAverageAmplitudeStability, pulseAveragePhaseStability, pulseAverageTotalStability, arraySize, actualArraySize);
}

int32 FetchPhaseWrappedTrace(niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* x0, float64* dx, float32 wrappedPhase[], int32 arraySize, int32* actualArraySize)
{
  return RFmxPulse_FetchPhaseWrappedTrace(instrumentHandle, selectorString, timeout, x0, dx, wrappedPhase, arraySize, actualArraySize);
}

int32 FetchPulseToPulseStabilityTrace(niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, int32 pulseIndex[], float64 pulseToPulseAmplitudeStability[], float64 pulseToPulsePhaseStability[], float64 pulseToPulseTotalStability[], int32 arraySize, int32* actualArraySize)
{
  return RFmxPulse_FetchPulseToPulseStabilityTrace(instrumentHandle, selectorString, timeout, pulseIndex, pulseToPulseAmplitudeStability, pulseToPulsePhaseStability, pulseToPulseTotalStability, arraySize, actualArraySize);
}

int32 FetchStabilityTrace(niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* x0, float64* dx, float32 pulseAmplitudeStability[], float32 pulsePhaseStability[], float32 pulseTotalStability[], int32 arraySize, int32* actualArraySize)
{
  return RFmxPulse_FetchStabilityTrace(instrumentHandle, selectorString, timeout, x0, dx, pulseAmplitudeStability, pulsePhaseStability, pulseTotalStability, arraySize, actualArraySize);
}

int32 FetchTimeSidelobeTrace(niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* x0, float64* dx, float32 timeSidelobe[], int32 arraySize, int32* actualArraySize)
{
  return RFmxPulse_FetchTimeSidelobeTrace(instrumentHandle, selectorString, timeout, x0, dx, timeSidelobe, arraySize, actualArraySize);
}

int32 GetAllNamedResultNames(niRFmxInstrHandle instrumentHandle, char selectorString[], char resultNames[], int32 resultNamesBufferSize, int32* actualResultNamesSize, int32* defaultResultExists)
{
  return RFmxPulse_GetAllNamedResultNames(instrumentHandle, selectorString, resultNames, resultNamesBufferSize, actualResultNamesSize, defaultResultExists);
}

int32 GetAttributeF32(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, float32* attrVal)
{
  return RFmxPulse_GetAttributeF32(instrumentHandle, selectorString, attributeID, attrVal);
}

int32 GetAttributeF32Array(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, float32 attrVal[], int32 arraySize, int32* actualArraySize)
{
  return RFmxPulse_GetAttributeF32Array(instrumentHandle, selectorString, attributeID, attrVal, arraySize, actualArraySize);
}

int32 GetAttributeF64(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, float64* attrVal)
{
  return RFmxPulse_GetAttributeF64(instrumentHandle, selectorString, attributeID, attrVal);
}

int32 GetAttributeF64Array(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, float64 attrVal[], int32 arraySize, int32* actualArraySize)
{
  return RFmxPulse_GetAttributeF64Array(instrumentHandle, selectorString, attributeID, attrVal, arraySize, actualArraySize);
}

int32 GetAttributeI16(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int16* attrVal)
{
  return RFmxPulse_GetAttributeI16(instrumentHandle, selectorString, attributeID, attrVal);
}

int32 GetAttributeI32(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int32* attrVal)
{
  return RFmxPulse_GetAttributeI32(instrumentHandle, selectorString, attributeID, attrVal);
}

int32 GetAttributeI32Array(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int32 attrVal[], int32 arraySize, int32* actualArraySize)
{
  return RFmxPulse_GetAttributeI32Array(instrumentHandle, selectorString, attributeID, attrVal, arraySize, actualArraySize);
}

int32 GetAttributeI64(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int64* attrVal)
{
  return RFmxPulse_GetAttributeI64(instrumentHandle, selectorString, attributeID, attrVal);
}

int32 GetAttributeI64Array(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int64 attrVal[], int32 arraySize, int32* actualArraySize)
{
  return RFmxPulse_GetAttributeI64Array(instrumentHandle, selectorString, attributeID, attrVal, arraySize, actualArraySize);
}

int32 GetAttributeI8(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int8* attrVal)
{
  return RFmxPulse_GetAttributeI8(instrumentHandle, selectorString, attributeID, attrVal);
}

int32 GetAttributeI8Array(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int8 attrVal[], int32 arraySize, int32* actualArraySize)
{
  return RFmxPulse_GetAttributeI8Array(instrumentHandle, selectorString, attributeID, attrVal, arraySize, actualArraySize);
}

int32 GetAttributeNIComplexDoubleArray(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, NIComplexDouble attrVal[], int32 arraySize, int32* actualArraySize)
{
  return RFmxPulse_GetAttributeNIComplexDoubleArray(instrumentHandle, selectorString, attributeID, attrVal, arraySize, actualArraySize);
}

int32 GetAttributeNIComplexSingleArray(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, NIComplexSingle attrVal[], int32 arraySize, int32* actualArraySize)
{
  return RFmxPulse_GetAttributeNIComplexSingleArray(instrumentHandle, selectorString, attributeID, attrVal, arraySize, actualArraySize);
}

int32 GetAttributeString(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int32 arraySize, char attrVal[])
{
  return RFmxPulse_GetAttributeString(instrumentHandle, selectorString, attributeID, arraySize, attrVal);
}

int32 GetAttributeU16(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt16* attrVal)
{
  return RFmxPulse_GetAttributeU16(instrumentHandle, selectorString, attributeID, attrVal);
}

int32 GetAttributeU32(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt32* attrVal)
{
  return RFmxPulse_GetAttributeU32(instrumentHandle, selectorString, attributeID, attrVal);
}

int32 GetAttributeU32Array(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt32 attrVal[], int32 arraySize, int32* actualArraySize)
{
  return RFmxPulse_GetAttributeU32Array(instrumentHandle, selectorString, attributeID, attrVal, arraySize, actualArraySize);
}

int32 GetAttributeU64Array(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt64 attrVal[], int32 arraySize, int32* actualArraySize)
{
  return RFmxPulse_GetAttributeU64Array(instrumentHandle, selectorString, attributeID, attrVal, arraySize, actualArraySize);
}

int32 GetAttributeU8(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt8* attrVal)
{
  return RFmxPulse_GetAttributeU8(instrumentHandle, selectorString, attributeID, attrVal);
}

int32 GetAttributeU8Array(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt8 attrVal[], int32 arraySize, int32* actualArraySize)
{
  return RFmxPulse_GetAttributeU8Array(instrumentHandle, selectorString, attributeID, attrVal, arraySize, actualArraySize);
}

int32 GetError(niRFmxInstrHandle instrumentHandle, int32* errorCode, int32 errorDescriptionBufferSize, char errorDescription[])
{
  return RFmxPulse_GetError(instrumentHandle, errorCode, errorDescriptionBufferSize, errorDescription);
}

int32 GetErrorString(niRFmxInstrHandle instrumentHandle, int32 errorCode, int32 errorDescriptionBufferSize, char errorDescription[])
{
  return RFmxPulse_GetErrorString(instrumentHandle, errorCode, errorDescriptionBufferSize, errorDescription);
}

int32 Initialize(char resourceName[], char optionString[], niRFmxInstrHandle* handleOut, int32* isNewSession)
{
  return RFmxPulse_Initialize(resourceName, optionString, handleOut, isNewSession);
}

int32 InitializeFromNIRFSASession(uInt32 nirfsaSession, niRFmxInstrHandle* handleOut)
{
  return RFmxPulse_InitializeFromNIRFSASession(nirfsaSession, handleOut);
}

int32 Initiate(niRFmxInstrHandle instrumentHandle, char selectorString[], char resultName[])
{
  return RFmxPulse_Initiate(instrumentHandle, selectorString, resultName);
}

int32 ResetAttribute(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID)
{
  return RFmxPulse_ResetAttribute(instrumentHandle, selectorString, attributeID);
}

int32 ResetToDefault(niRFmxInstrHandle instrumentHandle, char selectorString[])
{
  return RFmxPulse_ResetToDefault(instrumentHandle, selectorString);
}

int32 SelectMeasurements(niRFmxInstrHandle instrumentHandle, char selectorString[], uInt32 measurements, int32 enableAllTraces)
{
  return RFmxPulse_SelectMeasurements(instrumentHandle, selectorString, measurements, enableAllTraces);
}

int32 SendSoftwareEdgeTrigger(niRFmxInstrHandle instrumentHandle)
{
  return RFmxPulse_SendSoftwareEdgeTrigger(instrumentHandle);
}

int32 SetAttributeF32(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, float32 attrVal)
{
  return RFmxPulse_SetAttributeF32(instrumentHandle, selectorString, attributeID, attrVal);
}

int32 SetAttributeF32Array(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, float32 attrVal[], int32 arraySize)
{
  return RFmxPulse_SetAttributeF32Array(instrumentHandle, selectorString, attributeID, attrVal, arraySize);
}

int32 SetAttributeF64(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, float64 attrVal)
{
  return RFmxPulse_SetAttributeF64(instrumentHandle, selectorString, attributeID, attrVal);
}

int32 SetAttributeF64Array(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, float64 attrVal[], int32 arraySize)
{
  return RFmxPulse_SetAttributeF64Array(instrumentHandle, selectorString, attributeID, attrVal, arraySize);
}

int32 SetAttributeI16(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int16 attrVal)
{
  return RFmxPulse_SetAttributeI16(instrumentHandle, selectorString, attributeID, attrVal);
}

int32 SetAttributeI32(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int32 attrVal)
{
  return RFmxPulse_SetAttributeI32(instrumentHandle, selectorString, attributeID, attrVal);
}

int32 SetAttributeI32Array(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int32 attrVal[], int32 arraySize)
{
  return RFmxPulse_SetAttributeI32Array(instrumentHandle, selectorString, attributeID, attrVal, arraySize);
}

int32 SetAttributeI64(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int64 attrVal)
{
  return RFmxPulse_SetAttributeI64(instrumentHandle, selectorString, attributeID, attrVal);
}

int32 SetAttributeI64Array(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int64 attrVal[], int32 arraySize)
{
  return RFmxPulse_SetAttributeI64Array(instrumentHandle, selectorString, attributeID, attrVal, arraySize);
}

int32 SetAttributeI8(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int8 attrVal)
{
  return RFmxPulse_SetAttributeI8(instrumentHandle, selectorString, attributeID, attrVal);
}

int32 SetAttributeI8Array(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int8 attrVal[], int32 arraySize)
{
  return RFmxPulse_SetAttributeI8Array(instrumentHandle, selectorString, attributeID, attrVal, arraySize);
}

int32 SetAttributeNIComplexDoubleArray(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, NIComplexDouble attrVal[], int32 arraySize)
{
  return RFmxPulse_SetAttributeNIComplexDoubleArray(instrumentHandle, selectorString, attributeID, attrVal, arraySize);
}

int32 SetAttributeNIComplexSingleArray(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, NIComplexSingle attrVal[], int32 arraySize)
{
  return RFmxPulse_SetAttributeNIComplexSingleArray(instrumentHandle, selectorString, attributeID, attrVal, arraySize);
}

int32 SetAttributeString(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, char attrVal[])
{
  return RFmxPulse_SetAttributeString(instrumentHandle, selectorString, attributeID, attrVal);
}

int32 SetAttributeU16(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt16 attrVal)
{
  return RFmxPulse_SetAttributeU16(instrumentHandle, selectorString, attributeID, attrVal);
}

int32 SetAttributeU32(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt32 attrVal)
{
  return RFmxPulse_SetAttributeU32(instrumentHandle, selectorString, attributeID, attrVal);
}

int32 SetAttributeU32Array(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt32 attrVal[], int32 arraySize)
{
  return RFmxPulse_SetAttributeU32Array(instrumentHandle, selectorString, attributeID, attrVal, arraySize);
}

int32 SetAttributeU64Array(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt64 attrVal[], int32 arraySize)
{
  return RFmxPulse_SetAttributeU64Array(instrumentHandle, selectorString, attributeID, attrVal, arraySize);
}

int32 SetAttributeU8(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt8 attrVal)
{
  return RFmxPulse_SetAttributeU8(instrumentHandle, selectorString, attributeID, attrVal);
}

int32 SetAttributeU8Array(niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt8 attrVal[], int32 arraySize)
{
  return RFmxPulse_SetAttributeU8Array(instrumentHandle, selectorString, attributeID, attrVal, arraySize);
}

int32 WaitForAcquisitionComplete(niRFmxInstrHandle instrumentHandle, float64 timeout)
{
  return RFmxPulse_WaitForAcquisitionComplete(instrumentHandle, timeout);
}

int32 WaitForMeasurementComplete(niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout)
{
  return RFmxPulse_WaitForMeasurementComplete(instrumentHandle, selectorString, timeout);
}

}  // namespace nirfmxpulse_grpc
