//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Compilation test for the NI-RFSA Metadata
//---------------------------------------------------------------------
#include "nirfsa_library.h"

namespace nirfsa_grpc {

ViStatus Abort(ViSession vi)
{
  return niRFSA_Abort(vi);
}

ViStatus CheckAcquisitionStatus(ViSession vi, ViBoolean* isDone)
{
  return niRFSA_CheckAcquisitionStatus(vi, isDone);
}

ViStatus ClearError(ViSession vi)
{
  return niRFSA_ClearError(vi);
}

ViStatus ClearSelfCalibrateRange(ViSession vi)
{
  return niRFSA_ClearSelfCalibrateRange(vi);
}

ViStatus Close(ViSession vi)
{
  return niRFSA_close(vi);
}

ViStatus Commit(ViSession vi)
{
  return niRFSA_Commit(vi);
}

ViStatus ConfigureAcquisitionType(ViSession vi, ViInt32 acquisitionType)
{
  return niRFSA_ConfigureAcquisitionType(vi, acquisitionType);
}

ViStatus ConfigureDeembeddingTableInterpolationLinear(ViSession vi, ViConstString port, ViConstString tableName, ViInt32 format)
{
  return niRFSA_ConfigureDeembeddingTableInterpolationLinear(vi, port, tableName, format);
}

ViStatus ConfigureDeembeddingTableInterpolationNearest(ViSession vi, ViConstString port, ViConstString tableName)
{
  return niRFSA_ConfigureDeembeddingTableInterpolationNearest(vi, port, tableName);
}

ViStatus ConfigureDeembeddingTableInterpolationSpline(ViSession vi, ViConstString port, ViConstString tableName)
{
  return niRFSA_ConfigureDeembeddingTableInterpolationSpline(vi, port, tableName);
}

ViStatus ConfigureDigitalEdgeAdvanceTrigger(ViSession vi, ViConstString source, ViInt32 edge)
{
  return niRFSA_ConfigureDigitalEdgeAdvanceTrigger(vi, source, edge);
}

ViStatus ConfigureDigitalEdgeRefTrigger(ViSession vi, ViConstString source, ViInt32 edge, ViInt64 pretriggerSamples)
{
  return niRFSA_ConfigureDigitalEdgeRefTrigger(vi, source, edge, pretriggerSamples);
}

ViStatus ConfigureDigitalEdgeStartTrigger(ViSession vi, ViConstString source, ViInt32 edge)
{
  return niRFSA_ConfigureDigitalEdgeStartTrigger(vi, source, edge);
}

ViStatus ConfigureIQCarrierFrequency(ViSession vi, ViConstString channelList, ViReal64 carrierFrequency)
{
  return niRFSA_ConfigureIQCarrierFrequency(vi, channelList, carrierFrequency);
}

ViStatus ConfigureIQPowerEdgeRefTrigger(ViSession vi, ViConstString source, ViReal64 level, ViInt32 slope, ViInt64 pretriggerSamples)
{
  return niRFSA_ConfigureIQPowerEdgeRefTrigger(vi, source, level, slope, pretriggerSamples);
}

ViStatus ConfigureIQRate(ViSession vi, ViConstString channelList, ViReal64 iqRate)
{
  return niRFSA_ConfigureIQRate(vi, channelList, iqRate);
}

ViStatus ConfigureNumberOfRecords(ViSession vi, ViConstString channelList, ViBoolean numberOfRecordsIsFinite, ViInt64 numberOfRecords)
{
  return niRFSA_ConfigureNumberOfRecords(vi, channelList, numberOfRecordsIsFinite, numberOfRecords);
}

ViStatus ConfigureNumberOfSamples(ViSession vi, ViConstString channelList, ViBoolean numberOfSamplesIsFinite, ViInt64 samplesPerRecord)
{
  return niRFSA_ConfigureNumberOfSamples(vi, channelList, numberOfSamplesIsFinite, samplesPerRecord);
}

ViStatus ConfigurePXIChassisClk10(ViSession vi, ViConstString pxiClk10Source)
{
  return niRFSA_ConfigurePXIChassisClk10(vi, pxiClk10Source);
}

ViStatus ConfigureRefClock(ViSession vi, ViConstString clockSource, ViReal64 refClockRate)
{
  return niRFSA_ConfigureRefClock(vi, clockSource, refClockRate);
}

ViStatus ConfigureReferenceLevel(ViSession vi, ViConstString channelList, ViReal64 referenceLevel)
{
  return niRFSA_ConfigureReferenceLevel(vi, channelList, referenceLevel);
}

ViStatus ConfigureResolutionBandwidth(ViSession vi, ViConstString channelList, ViReal64 resolutionBandwidth)
{
  return niRFSA_ConfigureResolutionBandwidth(vi, channelList, resolutionBandwidth);
}

ViStatus ConfigureSoftwareEdgeAdvanceTrigger(ViSession vi)
{
  return niRFSA_ConfigureSoftwareEdgeAdvanceTrigger(vi);
}

ViStatus ConfigureSoftwareEdgeRefTrigger(ViSession vi, ViInt64 pretriggerSamples)
{
  return niRFSA_ConfigureSoftwareEdgeRefTrigger(vi, pretriggerSamples);
}

ViStatus ConfigureSoftwareEdgeStartTrigger(ViSession vi)
{
  return niRFSA_ConfigureSoftwareEdgeStartTrigger(vi);
}

ViStatus ConfigureSpectrumFrequencyCenterSpan(ViSession vi, ViConstString channelList, ViReal64 centerFrequency, ViReal64 span)
{
  return niRFSA_ConfigureSpectrumFrequencyCenterSpan(vi, channelList, centerFrequency, span);
}

ViStatus ConfigureSpectrumFrequencyStartStop(ViSession vi, ViConstString channelList, ViReal64 startFrequency, ViReal64 stopFrequency)
{
  return niRFSA_ConfigureSpectrumFrequencyStartStop(vi, channelList, startFrequency, stopFrequency);
}

ViStatus CreateConfigurationList(ViSession vi, ViConstString listName, ViInt32 numberOfListAttributes, ViAttr listAttributeIds[], ViBoolean setAsActiveList)
{
  return niRFSA_CreateConfigurationList(vi, listName, numberOfListAttributes, listAttributeIds, setAsActiveList);
}

ViStatus CreateConfigurationListStep(ViSession vi, ViBoolean setAsActiveStep)
{
  return niRFSA_CreateConfigurationListStep(vi, setAsActiveStep);
}

ViStatus CreateDeembeddingSparameterTableArray(ViSession vi, ViConstString port, ViConstString tableName, ViReal64 frequencies[], ViInt32 frequenciesSize, NIComplexNumber_struct sparameterTable[], ViInt32 sparameterTableSize, ViInt32 numberOfPorts, ViInt32 sparameterOrientation)
{
  return niRFSA_CreateDeembeddingSparameterTableArray(vi, port, tableName, frequencies, frequenciesSize, sparameterTable, sparameterTableSize, numberOfPorts, sparameterOrientation);
}

ViStatus CreateDeembeddingSparameterTableS2PFile(ViSession vi, ViConstString port, ViConstString tableName, ViConstString s2pFilePath, ViInt32 sparameterOrientation)
{
  return niRFSA_CreateDeembeddingSparameterTableS2PFile(vi, port, tableName, s2pFilePath, sparameterOrientation);
}

ViStatus DeleteAllDeembeddingTables(ViSession vi)
{
  return niRFSA_DeleteAllDeembeddingTables(vi);
}

ViStatus DeleteConfigurationList(ViSession vi, ViConstString listName)
{
  return niRFSA_DeleteConfigurationList(vi, listName);
}

ViStatus DeleteDeembeddingTable(ViSession vi, ViConstString port, ViConstString tableName)
{
  return niRFSA_DeleteDeembeddingTable(vi, port, tableName);
}

ViStatus Disable(ViSession vi)
{
  return niRFSA_Disable(vi);
}

ViStatus DisableAdvanceTrigger(ViSession vi)
{
  return niRFSA_DisableAdvanceTrigger(vi);
}

ViStatus DisableRefTrigger(ViSession vi)
{
  return niRFSA_DisableRefTrigger(vi);
}

ViStatus DisableStartTrigger(ViSession vi)
{
  return niRFSA_DisableStartTrigger(vi);
}

ViStatus EnableSessionAccess(ViSession vi, ViBoolean enable)
{
  return niRFSA_EnableSessionAccess(vi, enable);
}

ViStatus ErrorMessage(ViSession vi, ViStatus statusCode, ViChar errorMessage[1024])
{
  return niRFSA_error_message(vi, statusCode, errorMessage);
}

ViStatus ErrorQuery(ViSession vi, ViInt32* errorCode, ViChar errorMessage[1024])
{
  return niRFSA_error_query(vi, errorCode, errorMessage);
}

ViStatus ExportSignal(ViSession vi, ViInt32 signal, ViConstString signalIdentifier, ViConstString outputTerminal)
{
  return niRFSA_ExportSignal(vi, signal, signalIdentifier, outputTerminal);
}

ViStatus FetchIQMultiRecordComplexF32(ViSession vi, ViConstString channelList, ViInt64 startingRecord, ViInt64 numberOfRecords, ViInt64 numberOfSamples, ViReal64 timeout, NIComplexNumberF32_struct data[], niRFSA_wfmInfo_struct wfmInfo[])
{
  return niRFSA_FetchIQMultiRecordComplexF32(vi, channelList, startingRecord, numberOfRecords, numberOfSamples, timeout, data, wfmInfo);
}

ViStatus FetchIQMultiRecordComplexF64(ViSession vi, ViConstString channelList, ViInt64 startingRecord, ViInt64 numberOfRecords, ViInt64 numberOfSamples, ViReal64 timeout, NIComplexNumber_struct data[], niRFSA_wfmInfo_struct wfmInfo[])
{
  return niRFSA_FetchIQMultiRecordComplexF64(vi, channelList, startingRecord, numberOfRecords, numberOfSamples, timeout, data, wfmInfo);
}

ViStatus FetchIQMultiRecordComplexI16(ViSession vi, ViConstString channelList, ViInt64 startingRecord, ViInt64 numberOfRecords, ViInt64 numberOfSamples, ViReal64 timeout, NIComplexI16_struct data[], niRFSA_wfmInfo_struct wfmInfo[])
{
  return niRFSA_FetchIQMultiRecordComplexI16(vi, channelList, startingRecord, numberOfRecords, numberOfSamples, timeout, data, wfmInfo);
}

ViStatus FetchIQSingleRecordComplexF32(ViSession vi, ViConstString channelList, ViInt64 recordNumber, ViInt64 numberOfSamples, ViReal64 timeout, NIComplexNumberF32_struct data[], niRFSA_wfmInfo_struct* wfmInfo)
{
  return niRFSA_FetchIQSingleRecordComplexF32(vi, channelList, recordNumber, numberOfSamples, timeout, data, wfmInfo);
}

ViStatus FetchIQSingleRecordComplexF64(ViSession vi, ViConstString channelList, ViInt64 recordNumber, ViInt64 numberOfSamples, ViReal64 timeout, NIComplexNumber_struct data[], niRFSA_wfmInfo_struct* wfmInfo)
{
  return niRFSA_FetchIQSingleRecordComplexF64(vi, channelList, recordNumber, numberOfSamples, timeout, data, wfmInfo);
}

ViStatus FetchIQSingleRecordComplexI16(ViSession vi, ViConstString channelList, ViInt64 recordNumber, ViInt64 numberOfSamples, ViReal64 timeout, NIComplexI16_struct data[], niRFSA_wfmInfo_struct* wfmInfo)
{
  return niRFSA_FetchIQSingleRecordComplexI16(vi, channelList, recordNumber, numberOfSamples, timeout, data, wfmInfo);
}

ViStatus GetAttributeViBoolean(ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean* value)
{
  return niRFSA_GetAttributeViBoolean(vi, channelName, attributeId, value);
}

ViStatus GetAttributeViInt32(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32* value)
{
  return niRFSA_GetAttributeViInt32(vi, channelName, attributeId, value);
}

ViStatus GetAttributeViInt64(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt64* value)
{
  return niRFSA_GetAttributeViInt64(vi, channelName, attributeId, value);
}

ViStatus GetAttributeViReal64(ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64* value)
{
  return niRFSA_GetAttributeViReal64(vi, channelName, attributeId, value);
}

ViStatus GetAttributeViSession(ViSession vi, ViConstString channelName, ViAttr attributeId, ViSession* value)
{
  return niRFSA_GetAttributeViSession(vi, channelName, attributeId, value);
}

ViStatus GetAttributeViString(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 bufSize, ViChar value[])
{
  return niRFSA_GetAttributeViString(vi, channelName, attributeId, bufSize, value);
}

ViStatus GetCalUserDefinedInfo(ViSession vi, ViChar info[2048])
{
  return niRFSA_GetCalUserDefinedInfo(vi, info);
}

ViStatus GetCalUserDefinedInfoMaxSize(ViSession vi, ViInt32* infoSize)
{
  return niRFSA_GetCalUserDefinedInfoMaxSize(vi, infoSize);
}

ViStatus GetDeembeddingSparameters(ViSession vi, NIComplexNumber_struct sparameters[], ViInt32 sparametersArraySize, ViInt32* numberOfSparameters, ViInt32* numberOfPorts)
{
  return niRFSA_GetDeembeddingSparameters(vi, sparameters, sparametersArraySize, numberOfSparameters, numberOfPorts);
}

ViStatus GetDeviceResponse(ViSession vi, ViConstString channelList, ViInt32 responseType, ViInt32 bufferSize, ViReal64 frequencies[], ViReal64 magnitudeResponse[], ViReal64 phaseResponse[], ViInt32* numberOfFrequencies)
{
  return niRFSA_GetDeviceResponse(vi, channelList, responseType, bufferSize, frequencies, magnitudeResponse, phaseResponse, numberOfFrequencies);
}

ViStatus GetError(ViSession vi, ViStatus* errorCode, ViInt32 errorDescriptionBufferSize, ViChar errorDescription[])
{
  return niRFSA_GetError(vi, errorCode, errorDescriptionBufferSize, errorDescription);
}

ViStatus GetExtCalLastDateAndTime(ViSession vi, ViInt32* year, ViInt32* month, ViInt32* day, ViInt32* hour, ViInt32* minute)
{
  return niRFSA_GetExtCalLastDateAndTime(vi, year, month, day, hour, minute);
}

ViStatus GetExtCalLastTemp(ViSession vi, ViReal64* temperature)
{
  return niRFSA_GetExtCalLastTemp(vi, temperature);
}

ViStatus GetExtCalRecommendedInterval(ViSession vi, ViInt32* months)
{
  return niRFSA_GetExtCalRecommendedInterval(vi, months);
}

ViStatus GetFetchBacklog(ViSession vi, ViConstString channelList, ViInt64 recordNumber, ViInt64* backlog)
{
  return niRFSA_GetFetchBacklog(vi, channelList, recordNumber, backlog);
}

ViStatus GetFrequencyResponse(ViSession vi, ViConstString channelList, ViInt32 bufferSize, ViReal64 frequencies[], ViReal64 magnitudeResponse[], ViReal64 phaseResponse[], ViInt32* numberOfFrequencies)
{
  return niRFSA_GetFrequencyResponse(vi, channelList, bufferSize, frequencies, magnitudeResponse, phaseResponse, numberOfFrequencies);
}

ViStatus GetNormalizationCoefficients(ViSession vi, ViConstString channelList, ViInt32 arraySize, niRFSA_coefficientInfo_struct coefficientInfo[], ViInt32* numberOfCoefficientSets)
{
  return niRFSA_GetNormalizationCoefficients(vi, channelList, arraySize, coefficientInfo, numberOfCoefficientSets);
}

ViStatus GetNumberOfSpectralLines(ViSession vi, ViConstString channelList, ViInt32* numberOfSpectralLines)
{
  return niRFSA_GetNumberOfSpectralLines(vi, channelList, numberOfSpectralLines);
}

ViStatus GetRelayName(ViSession vi, ViConstString channelList, ViInt32 index, ViChar name[], ViInt32* bufferSize)
{
  return niRFSA_GetRelayName(vi, channelList, index, name, bufferSize);
}

ViStatus GetRelayOperationsCount(ViSession vi, ViConstString channelList, ViInt32 operationsCount[], ViInt32* bufferSize)
{
  return niRFSA_GetRelayOperationsCount(vi, channelList, operationsCount, bufferSize);
}

ViStatus GetScalingCoefficients(ViSession vi, ViConstString channelList, ViInt32 arraySize, niRFSA_coefficientInfo_struct coefficientInfo[], ViInt32* numberOfCoefficientSets)
{
  return niRFSA_GetScalingCoefficients(vi, channelList, arraySize, coefficientInfo, numberOfCoefficientSets);
}

ViStatus GetSelfCalLastDateAndTime(ViSession vi, ViInt64 selfCalibrationStep, ViInt32* year, ViInt32* month, ViInt32* day, ViInt32* hour, ViInt32* minute)
{
  return niRFSA_GetSelfCalLastDateAndTime(vi, selfCalibrationStep, year, month, day, hour, minute);
}

ViStatus GetSelfCalLastTemp(ViSession vi, ViInt64 selfCalibrationStep, ViReal64* temp)
{
  return niRFSA_GetSelfCalLastTemp(vi, selfCalibrationStep, temp);
}

ViStatus GetSpectralInfoForSMT(ViSession vi, SmtSpectrumInfo_struct* spectrumInfo)
{
  return niRFSA_GetSpectralInfoForSMT(vi, spectrumInfo);
}

ViStatus GetStreamEndpointHandle(ViSession vi, ViConstString streamEndpoint, ViUInt32* writerHandle)
{
  return niRFSA_GetStreamEndpointHandle(vi, streamEndpoint, writerHandle);
}

ViStatus GetTerminalName(ViSession vi, ViInt32 signal, ViConstString signalIdentifier, ViInt32 bufferSize, ViChar terminalName[])
{
  return niRFSA_GetTerminalName(vi, signal, signalIdentifier, bufferSize, terminalName);
}

ViStatus GetUserData(ViSession vi, ViConstString identifier, ViInt32 bufferSize, ViInt8 data[], ViInt32* actualDataSize)
{
  return niRFSA_GetUserData(vi, identifier, bufferSize, data, actualDataSize);
}

ViStatus Init(ViRsrc resourceName, ViBoolean idQuery, ViBoolean reset, ViSession* vi)
{
  return niRFSA_init(resourceName, idQuery, reset, vi);
}

ViStatus InitWithOptions(ViRsrc resourceName, ViBoolean idQuery, ViBoolean reset, ViConstString optionString, ViSession* vi)
{
  return niRFSA_InitWithOptions(resourceName, idQuery, reset, optionString, vi);
}

ViStatus Initiate(ViSession vi)
{
  return niRFSA_Initiate(vi);
}

ViStatus InvalidateAllAttributes(ViSession vi)
{
  return niRFSA_InvalidateAllAttributes(vi);
}

ViStatus IsSelfCalValid(ViSession vi, ViBoolean* selfCalValid, ViInt64* validSteps)
{
  return niRFSA_IsSelfCalValid(vi, selfCalValid, validSteps);
}

ViStatus PerformThermalCorrection(ViSession vi)
{
  return niRFSA_PerformThermalCorrection(vi);
}

ViStatus ReadIQSingleRecordComplexF64(ViSession vi, ViConstString channelList, ViReal64 timeout, NIComplexNumber_struct data[], ViInt64 dataArraySize, niRFSA_wfmInfo_struct* wfmInfo)
{
  return niRFSA_ReadIQSingleRecordComplexF64(vi, channelList, timeout, data, dataArraySize, wfmInfo);
}

ViStatus ReadPowerSpectrumF32(ViSession vi, ViConstString channelList, ViReal64 timeout, ViReal32 powerSpectrumData[], ViInt32 dataArraySize, niRFSA_spectrumInfo_struct* spectrumInfo)
{
  return niRFSA_ReadPowerSpectrumF32(vi, channelList, timeout, powerSpectrumData, dataArraySize, spectrumInfo);
}

ViStatus ReadPowerSpectrumF64(ViSession vi, ViConstString channelList, ViReal64 timeout, ViReal64 powerSpectrumData[], ViInt32 dataArraySize, niRFSA_spectrumInfo_struct* spectrumInfo)
{
  return niRFSA_ReadPowerSpectrumF64(vi, channelList, timeout, powerSpectrumData, dataArraySize, spectrumInfo);
}

ViStatus Reset(ViSession vi)
{
  return niRFSA_reset(vi);
}

ViStatus ResetAttribute(ViSession vi, ViConstString channelName, ViAttr attributeId)
{
  return niRFSA_ResetAttribute(vi, channelName, attributeId);
}

ViStatus ResetDevice(ViSession vi)
{
  return niRFSA_ResetDevice(vi);
}

ViStatus ResetWithDefaults(ViSession vi)
{
  return niRFSA_ResetWithDefaults(vi);
}

ViStatus ResetWithOptions(ViSession vi, ViUInt64 stepsToOmit)
{
  return niRFSA_ResetWithOptions(vi, stepsToOmit);
}

ViStatus RevisionQuery(ViSession vi, ViChar driverRev[256], ViChar instrRev[256])
{
  return niRFSA_revision_query(vi, driverRev, instrRev);
}

ViStatus SelfCal(ViSession vi)
{
  return niRFSA_SelfCal(vi);
}

ViStatus SelfCalibrate(ViSession vi, ViInt64 stepsToOmit)
{
  return niRFSA_SelfCalibrate(vi, stepsToOmit);
}

ViStatus SelfCalibrateRange(ViSession vi, ViInt64 stepsToOmit, ViReal64 minFrequency, ViReal64 maxFrequency, ViReal64 minReferenceLevel, ViReal64 maxReferenceLevel)
{
  return niRFSA_SelfCalibrateRange(vi, stepsToOmit, minFrequency, maxFrequency, minReferenceLevel, maxReferenceLevel);
}

ViStatus SelfTest(ViSession vi, ViInt16* testResult, ViChar testMessage[2048])
{
  return niRFSA_self_test(vi, testResult, testMessage);
}

ViStatus SendSoftwareEdgeTrigger(ViSession vi, ViInt32 trigger, ViConstString triggerIdentifier)
{
  return niRFSA_SendSoftwareEdgeTrigger(vi, trigger, triggerIdentifier);
}

ViStatus SetAttributeViBoolean(ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean value)
{
  return niRFSA_SetAttributeViBoolean(vi, channelName, attributeId, value);
}

ViStatus SetAttributeViInt32(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 value)
{
  return niRFSA_SetAttributeViInt32(vi, channelName, attributeId, value);
}

ViStatus SetAttributeViInt64(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt64 value)
{
  return niRFSA_SetAttributeViInt64(vi, channelName, attributeId, value);
}

ViStatus SetAttributeViReal64(ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64 value)
{
  return niRFSA_SetAttributeViReal64(vi, channelName, attributeId, value);
}

ViStatus SetAttributeViSession(ViSession vi, ViConstString channelName, ViAttr attributeId, ViSession value)
{
  return niRFSA_SetAttributeViSession(vi, channelName, attributeId, value);
}

ViStatus SetAttributeViString(ViSession vi, ViConstString channelName, ViAttr attributeId, ViConstString value)
{
  return niRFSA_SetAttributeViString(vi, channelName, attributeId, value);
}

ViStatus SetCalUserDefinedInfo(ViSession vi, ViConstString info)
{
  return niRFSA_SetCalUserDefinedInfo(vi, info);
}

ViStatus SetUserData(ViSession vi, ViConstString identifier, ViInt32 bufferSize, ViInt8 data[])
{
  return niRFSA_SetUserData(vi, identifier, bufferSize, data);
}

}  // namespace nirfsa_grpc