//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Mock of LibraryInterface for NI-rfmxvna
//---------------------------------------------------------------------
#ifndef NIRFMXVNA_GRPC_MOCK_LIBRARY_H
#define NIRFMXVNA_GRPC_MOCK_LIBRARY_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "nirfmxvna_library_interface.h"

namespace ni {
namespace tests {
namespace unit {

class NiRFmxVNAMockLibrary : public nirfmxvna_grpc::NiRFmxVNALibraryInterface {
 public:
  MOCK_METHOD(int32, AbortMeasurements, (niRFmxInstrHandle instrumentHandle, char selectorString[]), (override));
  MOCK_METHOD(int32, BuildCalibrationElementString, (char selectorString[], char calibrationElementID[], int32 selectorStringOutLength, char selectorStringOut[]), (override));
  MOCK_METHOD(int32, BuildCalkitString, (char selectorString[], char calkitID[], int32 selectorStringOutLength, char selectorStringOut[]), (override));
  MOCK_METHOD(int32, BuildCalstepString, (char selectorString[], int32 calstepNumber, int32 selectorStringOutLength, char selectorStringOut[]), (override));
  MOCK_METHOD(int32, BuildConnectorString, (char selectorString[], char connectorID[], int32 selectorStringOutLength, char selectorStringOut[]), (override));
  MOCK_METHOD(int32, BuildMarkerString, (char selectorString[], int32 markerNumber, int32 selectorStringOutLength, char selectorStringOut[]), (override));
  MOCK_METHOD(int32, BuildPortString, (char selectorString[], char portString[], int32 selectorStringOutLength, char selectorStringOut[]), (override));
  MOCK_METHOD(int32, BuildPulseGeneratorString, (char selectorString[], int32 pulseGeneratorNumber, int32 selectorStringOutLength, char selectorStringOut[]), (override));
  MOCK_METHOD(int32, BuildSParameterString, (char selectorString[], int32 sParameterNumber, int32 selectorStringOutLength, char selectorStringOut[]), (override));
  MOCK_METHOD(int32, BuildSegmentString, (char selectorString[], int32 segmentNumber, int32 selectorStringOutLength, char selectorStringOut[]), (override));
  MOCK_METHOD(int32, BuildSignalString, (char signalName[], char resultName[], int32 selectorStringLength, char selectorString[]), (override));
  MOCK_METHOD(int32, BuildWaveString, (char selectorString[], int32 waveNumber, int32 selectorStringOutLength, char selectorStringOut[]), (override));
  MOCK_METHOD(int32, CalibrationAbort, (niRFmxInstrHandle instrumentHandle, char selectorString[]), (override));
  MOCK_METHOD(int32, CalibrationAcquire, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout), (override));
  MOCK_METHOD(int32, CalibrationInitiate, (niRFmxInstrHandle instrumentHandle, char selectorString[]), (override));
  MOCK_METHOD(int32, CalibrationSave, (niRFmxInstrHandle instrumentHandle, char selectorString[], char calsetName[]), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitAddCalibrationElement, (niRFmxInstrHandle instrumentHandle, char selectorString[], char calibrationElementID[]), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitAddConnector, (niRFmxInstrHandle instrumentHandle, char selectorString[], char connectorID[]), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementDelayModelGetDelay, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64* delay), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementDelayModelSetDelay, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 delay), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementGetDescription, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 arraySize, char description[]), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementGetMaximumFrequency, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64* maximumFrequency), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementGetMinimumFrequency, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64* minimumFrequency), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementGetPortConnectors, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 arraySize, char connectorIDs[]), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementGetSParameterDefinition, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32* sParameterDefinition), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementGetTypes, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 calibrationElementTypes[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementReflectModelGetC0, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64* c0), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementReflectModelGetC1, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64* c1), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementReflectModelGetC2, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64* c2), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementReflectModelGetC3, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64* c3), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementReflectModelGetModelType, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32* modelType), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementReflectModelGetOffsetDelay, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64* offsetDelay), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementReflectModelGetOffsetLoss, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64* offsetLoss), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementReflectModelGetOffsetZ0, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64* offsetZ0), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementReflectModelGetReferenceImpedance, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64* referenceImpedance), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementReflectModelGetSParamAvailability, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32* sParameterAvailability), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementReflectModelSetC0, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 c0), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementReflectModelSetC1, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 c1), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementReflectModelSetC2, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 c2), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementReflectModelSetC3, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 c3), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementReflectModelSetModelType, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 modelType), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementReflectModelSetOffsetDelay, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 offsetDelay), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementReflectModelSetOffsetLoss, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 offsetLoss), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementReflectModelSetOffsetZ0, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 offsetZ0), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementReflectModelSetReferenceImpedance, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 referenceImpedance), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementReflectModelSetSParamAvailability, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 sParameterAvailability), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementSParameterGetFrequency, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 frequency[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementSParameterGetS11, (niRFmxInstrHandle instrumentHandle, char selectorString[], NIComplexDouble s11[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementSParameterGetS11Split, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 s11I[], float64 s11Q[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementSParameterGetS12, (niRFmxInstrHandle instrumentHandle, char selectorString[], NIComplexDouble s12[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementSParameterGetS12Split, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 s12I[], float64 s12Q[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementSParameterGetS21, (niRFmxInstrHandle instrumentHandle, char selectorString[], NIComplexDouble s21[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementSParameterGetS21Split, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 s21I[], float64 s21Q[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementSParameterGetS22, (niRFmxInstrHandle instrumentHandle, char selectorString[], NIComplexDouble s22[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementSParameterGetS22Split, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 s22I[], float64 s22Q[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementSParameterGetSParamAvailability, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32* sParameterAvailability), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementSParameterSetFrequency, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 frequency[], int32 arraySize), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementSParameterSetFromFile, (niRFmxInstrHandle instrumentHandle, char selectorString[], char fileName[]), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementSParameterSetS11, (niRFmxInstrHandle instrumentHandle, char selectorString[], NIComplexDouble s11[], int32 arraySize), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementSParameterSetS12, (niRFmxInstrHandle instrumentHandle, char selectorString[], NIComplexDouble s12[], int32 arraySize), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementSParameterSetS21, (niRFmxInstrHandle instrumentHandle, char selectorString[], NIComplexDouble s21[], int32 arraySize), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementSParameterSetS22, (niRFmxInstrHandle instrumentHandle, char selectorString[], NIComplexDouble s22[], int32 arraySize), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementSParameterSetSParamAvailability, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 sParameterAvailability), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementSetDescription, (niRFmxInstrHandle instrumentHandle, char selectorString[], char description[]), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementSetMaximumFrequency, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 maximumFrequency), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementSetMinimumFrequency, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 minimumFrequency), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementSetPortConnectors, (niRFmxInstrHandle instrumentHandle, char selectorString[], char connectorIDs[], int32 arraySize), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementSetSParameterDefinition, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 sParameterDefinition), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitCalibrationElementSetTypes, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 calibrationElementTypes[], int32 arraySize), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitConnectorGetDescription, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 arraySize, char description[]), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitConnectorGetGender, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32* connectorGender), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitConnectorGetImpedance, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64* impedance), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitConnectorGetMaximumFrequency, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64* maximumFrequency), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitConnectorGetMinimumFrequency, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64* minimumFrequency), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitConnectorGetType, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 arraySize, char connectorType[]), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitConnectorSetDescription, (niRFmxInstrHandle instrumentHandle, char selectorString[], char description[]), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitConnectorSetGender, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 connectorGender), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitConnectorSetImpedance, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 impedance), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitConnectorSetMaximumFrequency, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 maximumFrequency), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitConnectorSetMinimumFrequency, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 minimumFrequency), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitConnectorSetType, (niRFmxInstrHandle instrumentHandle, char selectorString[], char connectorType[]), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitGetCalibrationElementIDs, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 arraySize, char calibrationElementIDs[]), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitGetConnectorIDs, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 arraySize, char connectorIDs[]), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitGetDescription, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 arraySize, char calkitDescription[]), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitGetVersion, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 arraySize, char calkitVersion[]), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitRemoveCalibrationElement, (niRFmxInstrHandle instrumentHandle, char selectorString[], char calibrationElementID[]), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitRemoveConnector, (niRFmxInstrHandle instrumentHandle, char selectorString[], char connectorID[]), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitSetDescription, (niRFmxInstrHandle instrumentHandle, char selectorString[], char calkitDescription[]), (override));
  MOCK_METHOD(int32, CalkitManagerCalkitSetVersion, (niRFmxInstrHandle instrumentHandle, char selectorString[], char calkitVersion[]), (override));
  MOCK_METHOD(int32, CalkitManagerCreateCalkit, (niRFmxInstrHandle instrumentHandle, char selectorString[], char calkitID[]), (override));
  MOCK_METHOD(int32, CalkitManagerExportCalkit, (niRFmxInstrHandle instrumentHandle, char selectorString[], char calkitID[], char calkitFilePath[]), (override));
  MOCK_METHOD(int32, CalkitManagerGetCalkitIDs, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 arraySize, char calkitIDs[]), (override));
  MOCK_METHOD(int32, CalkitManagerImportCalkit, (niRFmxInstrHandle instrumentHandle, char selectorString[], char calkitFilePath[]), (override));
  MOCK_METHOD(int32, CalkitManagerRemoveCalkit, (niRFmxInstrHandle instrumentHandle, char selectorString[], char calkitID[]), (override));
  MOCK_METHOD(int32, CalkitManagerValidateCalkit, (niRFmxInstrHandle instrumentHandle, char selectorString[], char calkitID[]), (override));
  MOCK_METHOD(int32, CalsetEmbedFixtureS2p, (niRFmxInstrHandle instrumentHandle, char selectorString[], char calsetName[], char fixtureS2pFilePath[], char vnaPort[], int32 sParameterOrientation, char newCalsetName[]), (override));
  MOCK_METHOD(int32, CalsetGetErrorTerm, (niRFmxInstrHandle instrumentHandle, char selectorString[], char calsetName[], int32 errorTermIdentifier, char measurementPort[], char sourcePort[], NIComplexSingle errorTerm[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, CalsetGetErrorTermSplit, (niRFmxInstrHandle instrumentHandle, char selectorString[], char calsetName[], int32 errorTermIdentifier, char measurementPort[], char sourcePort[], float32 errorTermI[], float32 errorTermQ[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, CalsetGetFrequencyGrid, (niRFmxInstrHandle instrumentHandle, char selectorString[], char calsetName[], int32 errorTermIdentifier, float64 frequencyGrid[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, CalsetLoadFromFile, (niRFmxInstrHandle instrumentHandle, char selectorString[], char calsetName[], char calsetFilePath[]), (override));
  MOCK_METHOD(int32, CalsetSaveToFile, (niRFmxInstrHandle instrumentHandle, char selectorString[], char calsetName[], char calsetFilePath[]), (override));
  MOCK_METHOD(int32, CfgCorrectionPortSubset, (niRFmxInstrHandle instrumentHandle, char selectorString[], char portSubset[]), (override));
  MOCK_METHOD(int32, CfgFrequencyReference, (niRFmxInstrHandle instrumentHandle, char channelName[], char frequencyReferenceSource[], float64 frequencyReferenceFrequency), (override));
  MOCK_METHOD(int32, CfgMechanicalAttenuation, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 mechanicalAttenuationAuto, float64 mechanicalAttenuationValue), (override));
  MOCK_METHOD(int32, CfgRFAttenuation, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 rfAttenuationAuto, float64 rfAttenuationValue), (override));
  MOCK_METHOD(int32, CheckMeasurementStatus, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32* isDone), (override));
  MOCK_METHOD(int32, ClearAllNamedResults, (niRFmxInstrHandle instrumentHandle, char selectorString[]), (override));
  MOCK_METHOD(int32, ClearCalset, (niRFmxInstrHandle instrumentHandle, char selectorString[], char calsetName[]), (override));
  MOCK_METHOD(int32, ClearMeasurementMemoryNames, (niRFmxInstrHandle instrumentHandle, char selectorString[]), (override));
  MOCK_METHOD(int32, ClearNamedResult, (niRFmxInstrHandle instrumentHandle, char selectorString[]), (override));
  MOCK_METHOD(int32, CloneSignalConfiguration, (niRFmxInstrHandle instrumentHandle, char oldSignalName[], char newSignalName[]), (override));
  MOCK_METHOD(int32, Close, (niRFmxInstrHandle instrumentHandle, int32 forceDestroy), (override));
  MOCK_METHOD(int32, Commit, (niRFmxInstrHandle instrumentHandle, char selectorString[]), (override));
  MOCK_METHOD(int32, CopyCalset, (niRFmxInstrHandle instrumentHandle, char selectorString[], char sourceCalsetName[], char newCalsetName[]), (override));
  MOCK_METHOD(int32, CopyDataToMeasurementMemory, (niRFmxInstrHandle instrumentHandle, char selectorString[], char memoryDataName[]), (override));
  MOCK_METHOD(int32, CreateSignalConfiguration, (niRFmxInstrHandle instrumentHandle, char signalName[]), (override));
  MOCK_METHOD(int32, DeleteSignalConfiguration, (niRFmxInstrHandle instrumentHandle, char signalName[]), (override));
  MOCK_METHOD(int32, DeselectActiveCalset, (niRFmxInstrHandle instrumentHandle, char selectorString[]), (override));
  MOCK_METHOD(int32, GetAllCalsetNames, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 arraySize, char calsetNames[]), (override));
  MOCK_METHOD(int32, GetAllNamedResultNames, (niRFmxInstrHandle instrumentHandle, char selectorString[], char resultNames[], int32 resultNamesBufferSize, int32* actualResultNamesSize, int32* defaultResultExists), (override));
  MOCK_METHOD(int32, GetAttributeF32, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, float32* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeF32Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, float32 attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeF64, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, float64* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeF64Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, float64 attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeI16, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int16* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeI32, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int32* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeI32Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int32 attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeI64, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int64* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeI64Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int64 attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeI8, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int8* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeI8Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int8 attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeNIComplexDoubleArray, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, NIComplexDouble attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeNIComplexSingleArray, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, NIComplexSingle attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeString, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int32 arraySize, char attrVal[]), (override));
  MOCK_METHOD(int32, GetAttributeU16, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt16* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeU32, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt32* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeU32Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt32 attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeU64Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt64 attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeU8, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt8* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeU8Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt8 attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetError, (niRFmxInstrHandle instrumentHandle, int32* errorCode, int32 errorDescriptionBufferSize, char errorDescription[]), (override));
  MOCK_METHOD(int32, GetErrorString, (niRFmxInstrHandle instrumentHandle, int32 errorCode, int32 errorDescriptionBufferSize, char errorDescription[]), (override));
  MOCK_METHOD(int32, GetMeasurementMemoryNames, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 arraySize, char measurementMemoryNames[]), (override));
  MOCK_METHOD(int32, GetMeasurementMemoryXData, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 x[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetMeasurementMemoryYData, (niRFmxInstrHandle instrumentHandle, char selectorString[], float32 y1[], float32 y2[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, IQFetchData, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* x0, float64* dx, NIComplexSingle data[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, IQFetchDataSplit, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64* x0, float64* dx, float32 dataI[], float32 dataQ[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, Initialize, (char resourceName[], char optionString[], niRFmxInstrHandle* handleOut, int32* isNewSession), (override));
  MOCK_METHOD(int32, InitializeFromNIRFSASession, (uInt32 nirfsaSession, niRFmxInstrHandle* handleOut), (override));
  MOCK_METHOD(int32, Initiate, (niRFmxInstrHandle instrumentHandle, char selectorString[], char resultName[]), (override));
  MOCK_METHOD(int32, LoadDataToMeasurementMemoryFromFile, (niRFmxInstrHandle instrumentHandle, char selectorString[], char filePath[], char parameter[], char memoryDataName[]), (override));
  MOCK_METHOD(int32, MarkerCfgDataSource, (niRFmxInstrHandle instrumentHandle, char selectorString[], char dataSource[]), (override));
  MOCK_METHOD(int32, MarkerCfgNumberOfMarkers, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 numberOfMarkers), (override));
  MOCK_METHOD(int32, MarkerCfgPeakSearchExcursion, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 peakExcursionEnabled, float64 peakExcursion), (override));
  MOCK_METHOD(int32, MarkerCfgPeakSearchThreshold, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 thresholdEnabled, float64 threshold), (override));
  MOCK_METHOD(int32, MarkerCfgReferenceMarker, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 referenceMarker), (override));
  MOCK_METHOD(int32, MarkerCfgType, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 markerType), (override));
  MOCK_METHOD(int32, MarkerCfgX, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 markerX), (override));
  MOCK_METHOD(int32, MarkerCfgY, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 markerY1, float64 markerY2), (override));
  MOCK_METHOD(int32, MarkerFetchX, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64* markerX), (override));
  MOCK_METHOD(int32, MarkerFetchY, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64* markerY1, float64* markerY2), (override));
  MOCK_METHOD(int32, MarkerSearch, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 searchMode), (override));
  MOCK_METHOD(int32, ResetAttribute, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID), (override));
  MOCK_METHOD(int32, ResetToDefault, (niRFmxInstrHandle instrumentHandle, char selectorString[]), (override));
  MOCK_METHOD(int32, SParamsCfgSParameter, (niRFmxInstrHandle instrumentHandle, char selectorString[], char sParameter[]), (override));
  MOCK_METHOD(int32, SParamsExportToSnPFile, (niRFmxInstrHandle instrumentHandle, char selectorString[], char snpFilePath[]), (override));
  MOCK_METHOD(int32, SParamsFetchXData, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64 x[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, SParamsFetchYData, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float32 y1[], float32 y2[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, SParamsGetSParameter, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 arraySize, char sParameter[]), (override));
  MOCK_METHOD(int32, SelectActiveCalset, (niRFmxInstrHandle instrumentHandle, char selectorString[], char calsetName[], int32 restoreConfiguration), (override));
  MOCK_METHOD(int32, SelectMeasurements, (niRFmxInstrHandle instrumentHandle, char selectorString[], uInt32 measurements, int32 enableAllTraces), (override));
  MOCK_METHOD(int32, SendSoftwareEdgeTrigger, (niRFmxInstrHandle instrumentHandle), (override));
  MOCK_METHOD(int32, SetAttributeF32, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, float32 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeF32Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, float32 attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeF64, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, float64 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeF64Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, float64 attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeI16, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int16 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeI32, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int32 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeI32Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int32 attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeI64, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int64 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeI64Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int64 attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeI8, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int8 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeI8Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, int8 attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeNIComplexDoubleArray, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, NIComplexDouble attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeNIComplexSingleArray, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, NIComplexSingle attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeString, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, char attrVal[]), (override));
  MOCK_METHOD(int32, SetAttributeU16, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt16 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeU32, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt32 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeU32Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt32 attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeU64Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt64 attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeU8, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt8 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeU8Array, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 attributeID, uInt8 attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, WaitForAcquisitionComplete, (niRFmxInstrHandle instrumentHandle, float64 timeout), (override));
  MOCK_METHOD(int32, WaitForMeasurementComplete, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout), (override));
  MOCK_METHOD(int32, WavesCfgWave, (niRFmxInstrHandle instrumentHandle, char selectorString[], char wave[]), (override));
  MOCK_METHOD(int32, WavesFetchXData, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float64 x[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, WavesFetchYData, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, float32 y1[], float32 y2[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, WavesGetWave, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 arraySize, char wave[]), (override));
};

}  // namespace unit
}  // namespace tests
}  // namespace ni
#endif  // NIRFMXVNA_GRPC_MOCK_LIBRARY_H