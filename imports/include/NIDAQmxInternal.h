#ifndef ___nicai_NIDAQmxInternal_h___
#define ___nicai_NIDAQmxInternal_h___
#include "NIDAQmx.h"
#ifdef __cplusplus
extern "C"
{
#endif
/******************************************************/
/***                Import/Export                   ***/
/******************************************************/
#define DAQmx_Val_INI 0
#define DAQmx_Val_TabDelimited 1
#define DAQmx_Val_JSON 2
    int32 __CFUNC DAQmxInternalCreateTaskFromString(const char newTaskName[], int32 fileFormat, const char taskString[], TaskHandle *taskHandle);
    int32 __CFUNC DAQmxInternalSaveTaskToString(TaskHandle taskHandle, const char saveAs[], int32 fileFormat, char taskString[], uInt32 bufferSize);
/******************************************************/
/***                 Read Data                      ***/
/******************************************************/
#define DAQmx_Val_WfmAttrType_Bool32 1
#define DAQmx_Val_WfmAttrType_Float64 2
#define DAQmx_Val_WfmAttrType_Int32 3
#define DAQmx_Val_WfmAttrType_String 4
    // To retrieve waveform attributes, provide this optional callback:
    // - attributeName is "NI_ChannelName", "NI_UnitDescription", etc.
    // - attributeType uses the WfmAttrType enum.
    // - Boolean and numeric values are in native byte order.
    // - String values are in the encoding used by the DLL (MBCS for nicaiu.dll, UTF-8 for nicai_utf8.dll).
    // - callbackData is used to pass an object instance into the callback.
    // - The callback returns an error code.
    typedef int32(CVICALLBACK *DAQmxSetWfmAttrCallbackPtr)(uInt32 channelIndex, const char attributeName[], int32 attributeType, const void *value, uInt32 valueSizeInBytes, void *callbackData);
    // int64 t0 and dt use the same format as .NET System.DateTime and System.TimeSpan: 100 ns ticks
    // with an epoch of Jan 1, 0001. The t0 and dt arrays are optional and may be NULL.
    int32 __CFUNC DAQmxInternalReadAnalogWaveform(TaskHandle taskHandle, int32 numSampsPerChan, float64 timeout, bool32 fillMode, int64 t0Array[], int64 dtArray[], uInt32 timingArraySize, float64 readArray[], uInt32 arraySizeInSamps, int32 *sampsPerChanRead, bool32 *reserved);
    int32 __CFUNC DAQmxInternalReadAnalogWaveformEx(TaskHandle taskHandle, int32 numSampsPerChan, float64 timeout, bool32 fillMode, int64 t0Array[], int64 dtArray[], uInt32 timingArraySize, DAQmxSetWfmAttrCallbackPtr setWfmAttrCallback, void *setWfmAttrCallbackData, float64 readArray[], uInt32 arraySizeInSamps, int32 *sampsPerChanRead, bool32 *reserved);
    int32 __CFUNC DAQmxInternalReadAnalogWaveformPerChan(TaskHandle taskHandle, int32 numSampsPerChan, float64 timeout, int64 t0Array[], int64 dtArray[], uInt32 timingArraySize, DAQmxSetWfmAttrCallbackPtr setWfmAttrCallback, void *setWfmAttrCallbackData, float64 *readArrayPtrs[], uInt32 readArrayCount, uInt32 arraySizeInSampsPerChan, int32 *sampsPerChanRead, bool32 *reserved);
    // DAQmxInternalReadDigitalWaveform reverses the order of lines within ports. For example,
    // DAQmxReadDigitalLines expands Dev1/port0 into Dev1/port0/line0:31 (little-endian), but
    // DAQmxInternalReadDigitalWaveform expands Dev1/port0 into Dev1/port0/line31:0 (big-endian). This
    // matches the data layout of the digital waveform datatype in LabVIEW and .NET.
    //
    // Depending on fillMode, readArray is assumed to be in the format (numChans x numSampsPerChan x
    // maxDataWidth) or (numSampsPerChan x numChans x maxDataWidth), where numChans = ReadNumChans and
    // maxDataWidth = ReadDigitalLinesBytesPerChan.
    //
    // If bytesPerChanArray is specified, this function uses it to return DINumLines[i], to enable
    // resizing waveform buffers efficiently. This function does not validate expected data widths.
    int32 __CFUNC DAQmxInternalReadDigitalWaveform(TaskHandle taskHandle, int32 numSampsPerChan, float64 timeout, bool32 fillMode, int64 t0Array[], int64 dtArray[], uInt32 timingArraySize, DAQmxSetWfmAttrCallbackPtr setWfmAttrCallback, void *setWfmAttrCallbackData, uInt8 readArray[], uInt32 arraySizeInBytes, int32 *sampsPerChanRead, int32 *numBytesPerSamp, uInt32 bytesPerChanArray[], uInt32 bytesPerChanArraySize, bool32 *reserved);
    /******************************************************/
    /***                 Write Data                     ***/
    /******************************************************/
    int32 __CFUNC DAQmxInternalWriteAnalogWaveformPerChan(TaskHandle taskHandle, int32 numSampsPerChan, bool32 autoStart, float64 timeout, const float64 *const writeArrayPtrs[], uInt32 writeArrayCount, int32 *sampsPerChanWritten, bool32 *reserved);
    // DAQmxInternalWriteDigitalWaveform reverses the order of lines within ports. See comments about
    // DAQmxInternalReadDigitalWaveform, above.
    //
    // Depending on dataLayout, writeArray is assumed to be in the format (numChans x numSampsPerChan x
    // maxDataWidth) or (numSampsPerChan x numChans x maxDataWidth), where numChans = WriteNumChans and
    // maxDataWidth = WriteDigitalLinesPerChan.
    //
    // If bytesPerChanArray is specified, this function validates expected number of channels and
    // expected data width per channel: bytesPerArraySize == WriteNumChans and bytesPerChanArray[i] ==
    // DONumLines[i]. Each channel's data must still be padded to maxDataWidth. If not specified, the
    // data is assumed to be in the correct format and no validation is performed.
    int32 __CFUNC DAQmxInternalWriteDigitalWaveform(TaskHandle taskHandle, int32 numSampsPerChan, bool32 autoStart, float64 timeout, bool32 dataLayout, const uInt8 writeArray[], const uInt32 bytesPerChanArray[], uInt32 bytesPerChanArraySize, int32 *sampsPerChanWritten, bool32 *reserved);
    /******************************************************/
    /***         Task Configuration/Control             ***/
    /******************************************************/
    int32 __CFUNC DAQmxInternalDisableChannel(TaskHandle taskHandle, const char channelNames[]);
/******************************************************/
/***                 Error Handling                 ***/
/******************************************************/
#define DAQmx_Val_LabVIEW 0
#define DAQmx_Val_Cvi 1
#define DAQmx_Val_MStudio 2
#define DAQmx_Val_Raw -1
#define DAQmx_Val_Eng 0
#define DAQmx_Val_Fra 1
#define DAQmx_Val_Deu 2
#define DAQmx_Val_Jpn 3
#define DAQmx_Val_Kor 4
#define DAQmx_Val_Chs 5
#define DAQmx_Val_Bit_ErrorFormatFlags_AddStatic (1 << 0)
#define DAQmx_Val_Bit_ErrorFormatFlags_AddDynamic (1 << 1)
#define DAQmx_Val_Bit_ErrorFormatFlags_AddDebug (1 << 2)
    // Get the static, localized error string for the specified error code, using the specified language.
    int32 __CFUNC DAQmxInternalGetLocalizedErrorString(int32 language, int32 errorCode, char errorString[], uInt32 bufferSize);
    // Get the error description in JSON1 format for the last error, using the specified ADE and language.
    // Example: {"dynamic":[{"type":"usage","key":"Device Specified","value":"NonexistentDevice"},...]}
    int32 __CFUNC DAQmxInternalGetLastErrorDescription(int32 ade, int32 language, char errorDescription[], uInt32 bufferSize);
    // Get formatted text for the last error, using the specified ADE, language, and flags.
    int32 __CFUNC DAQmxInternalGetLastErrorFormattedText(int32 ade, int32 language, uInt32 formatFlags, char errorString[], uInt32 bufferSize);
    /******************************************************/
    /***          Get Attribute Default Value           ***/
    /******************************************************/
    // These functions are obsolete and are not supported with the feature toggle
    // nidaqmxCApiRedirection=True.
    int32 __CFUNC DAQmxInternalGetChanAttributeDefaultI32(TaskHandle taskID, const char activeChannels[], int32 attributeID, int32 *defaultValue);
    int32 __CFUNC DAQmxInternalGetChanAttributeDefaultU32(TaskHandle taskID, const char activeChannels[], int32 attributeID, uInt32 *defaultValue);
    int32 __CFUNC DAQmxInternalGetChanAttributeDefaultU64(TaskHandle taskID, const char activeChannels[], int32 attributeID, uInt64 *defaultValue);
    int32 __CFUNC DAQmxInternalGetChanAttributeDefaultF64(TaskHandle taskID, const char activeChannels[], int32 attributeID, float64 *defaultValue);
    int32 __CFUNC DAQmxInternalGetChanAttributeDefaultString(TaskHandle taskID, const char activeChannels[], int32 attributeID, char defaultValue[], uInt32 bufferSize);
    int32 __CFUNC DAQmxInternalGetTrigAttributeDefaultI32(TaskHandle taskID, int32 attributeID, int32 *defaultValue);
    int32 __CFUNC DAQmxInternalGetTrigAttributeDefaultU32(TaskHandle taskID, int32 attributeID, uInt32 *defaultValue);
    int32 __CFUNC DAQmxInternalGetTrigAttributeDefaultU64(TaskHandle taskID, int32 attributeID, uInt64 *defaultValue);
    int32 __CFUNC DAQmxInternalGetTrigAttributeDefaultF64(TaskHandle taskID, int32 attributeID, float64 *defaultValue);
    int32 __CFUNC DAQmxInternalGetTrigAttributeDefaultString(TaskHandle taskID, int32 attributeID, char defaultValue[], uInt32 bufferSize);
    int32 __CFUNC DAQmxInternalGetTimingAttributeDefaultI32(TaskHandle taskID, int32 attributeID, int32 *defaultValue);
    int32 __CFUNC DAQmxInternalGetTimingAttributeDefaultU32(TaskHandle taskID, int32 attributeID, uInt32 *defaultValue);
    int32 __CFUNC DAQmxInternalGetTimingAttributeDefaultU64(TaskHandle taskID, int32 attributeID, uInt64 *defaultValue);
    int32 __CFUNC DAQmxInternalGetTimingAttributeDefaultF64(TaskHandle taskID, int32 attributeID, float64 *defaultValue);
    int32 __CFUNC DAQmxInternalGetTimingAttributeDefaultString(TaskHandle taskID, int32 attributeID, char defaultValue[], uInt32 bufferSize);
    /******************************************************/
    /***             Get Attribute Range                ***/
    /******************************************************/
    // These functions are obsolete and are not supported with the feature toggle
    // nidaqmxCApiRedirection=True.
    int32 __CFUNC DAQmxInternalGetChanAttributeRangeI32(TaskHandle taskID, const char activeChannels[], int32 attributeID, char range[], uInt32 bufferSize);
    int32 __CFUNC DAQmxInternalGetChanAttributeRangeU32(TaskHandle taskID, const char activeChannels[], int32 attributeID, char range[], uInt32 bufferSize);
    int32 __CFUNC DAQmxInternalGetChanAttributeRangeU64(TaskHandle taskID, const char activeChannels[], int32 attributeID, char range[], uInt32 bufferSize);
    int32 __CFUNC DAQmxInternalGetChanAttributeRangeF64(TaskHandle taskID, const char activeChannels[], int32 attributeID, char range[], uInt32 bufferSize);
    int32 __CFUNC DAQmxInternalGetChanAttributeRangeString(TaskHandle taskID, const char activeChannels[], int32 attributeID, char range[], uInt32 bufferSize);
    int32 __CFUNC DAQmxInternalGetTrigAttributeRangeI32(TaskHandle taskID, int32 attributeID, char range[], uInt32 bufferSize);
    int32 __CFUNC DAQmxInternalGetTrigAttributeRangeU32(TaskHandle taskID, int32 attributeID, char range[], uInt32 bufferSize);
    int32 __CFUNC DAQmxInternalGetTrigAttributeRangeU64(TaskHandle taskID, int32 attributeID, char range[], uInt32 bufferSize);
    int32 __CFUNC DAQmxInternalGetTrigAttributeRangeF64(TaskHandle taskID, int32 attributeID, char range[], uInt32 bufferSize);
    int32 __CFUNC DAQmxInternalGetTrigAttributeRangeString(TaskHandle taskID, int32 attributeID, char range[], uInt32 bufferSize);
    int32 __CFUNC DAQmxInternalGetTimingAttributeRangeI32(TaskHandle taskID, int32 attributeID, char range[], uInt32 bufferSize);
    int32 __CFUNC DAQmxInternalGetTimingAttributeRangeU32(TaskHandle taskID, int32 attributeID, char range[], uInt32 bufferSize);
    int32 __CFUNC DAQmxInternalGetTimingAttributeRangeU64(TaskHandle taskID, int32 attributeID, char range[], uInt32 bufferSize);
    int32 __CFUNC DAQmxInternalGetTimingAttributeRangeF64(TaskHandle taskID, int32 attributeID, char range[], uInt32 bufferSize);
    int32 __CFUNC DAQmxInternalGetTimingAttributeRangeString(TaskHandle taskID, int32 attributeID, char range[], uInt32 bufferSize);
    /******************************************************/
    /***          Get Attribute Desired Value           ***/
    /******************************************************/
    int32 __CFUNC DAQmxInternalGetChanAttributeDesiredI32(TaskHandle taskID, const char activeChannels[], int32 attributeID, int32 *desiredValue);
    int32 __CFUNC DAQmxInternalGetChanAttributeDesiredU32(TaskHandle taskID, const char activeChannels[], int32 attributeID, uInt32 *desiredValue);
    int32 __CFUNC DAQmxInternalGetChanAttributeDesiredF64(TaskHandle taskID, const char activeChannels[], int32 attributeID, float64 *desiredValue);
    int32 __CFUNC DAQmxInternalGetTimingAttributeDesiredU32(TaskHandle taskID, int32 attributeID, uInt32 *desiredValue);
    int32 __CFUNC DAQmxInternalGetTimingAttributeDesiredF64(TaskHandle taskID, int32 attributeID, float64 *desiredValue);
/******************************************************/
/***             Attribute Filtering                ***/
/******************************************************/
#define DAQmx_Val_ShowSelectedDeviceAttributes 0
#define DAQmx_Val_ShowAllDeviceAttributes 1
#define DAQmx_Val_ShowAllConfiguredDeviceAttributes 2
    // Note: each entry in deviceMAXDisplayNames should be in the format 'NI PXIe-6363: "Dev1"'.
    // Also, calling this function sets the MSAI filter preferences in MXS.
    //
    int32 __CFUNC DAQmxInternalGetFilteredAttributeIDs(const char deviceMAXDisplayNames[], uInt32 option, int32 buffer[], uInt32 bufferSize, bool32 *filteringEnabled);
    int32 __CFUNC DAQmxInternalGetAttributeName(int32 attributeID, int32 ade, int32 language, char buffer[], uInt32 bufferSize);
    /******************************************************/
    /***               Debug Sessions                   ***/
    /******************************************************/
    int32 __CFUNC DAQmxInternalCommitDebugSession(TaskHandle taskID);
    int32 __CFUNC DAQmxInternalGetDebugTargets(char jsonOutput[], uInt32 bufferSize);
#define DAQmx_Val_ScaledDataFormat_AnalogF64 16111
#define DAQmx_Val_ScaledDataFormat_PortDigitalU8 16112
#define DAQmx_Val_ScaledDataFormat_PortDigitalU16 16113
#define DAQmx_Val_ScaledDataFormat_PortDigitalU32 16114
#define DAQmx_Val_ScaledDataFormat_BinaryU16 16115
#define DAQmx_Val_ScaledDataFormat_BinaryI16 16116
#define DAQmx_Val_ScaledDataFormat_BinaryU32 16117
#define DAQmx_Val_ScaledDataFormat_BinaryI32 16118
#define DAQmx_Val_ScaledDataFormat_BinaryU64 16119
#define DAQmx_Val_ScaledDataFormat_TimeAbsolute 16120
#define DAQmx_Val_ScaledDataFormat_CounterDutyCycleAndFrequencyF64 16121
#define DAQmx_Val_ScaledDataFormat_CounterHighAndLowTimesF64 16122
#define DAQmx_Val_ScaledDataFormat_CounterHighAndLowTicksU32 16123
#define DAQmx_Val_ScaledDataFormat_LineDigitalU8 16124
#define DAQmx_Val_ScaledDataFormat_WaveformDigitalU8 16125
#define DAQmx_Val_ScaledDataFormat_PowerVoltageAndCurrentF64 15504
#define DAQmx_Val_ScaledDataFormat_PowerVoltageAndCurrentI16 15505
    int32 __CFUNC DAQmxInternalGetCachedSamplesDataFormat(TaskHandle taskHandle, int32 channelType, int32 *dataFormat, uInt64 *sequenceNumber);
    int32 __CFUNC DAQmxInternalGetCachedSamplesF64(TaskHandle taskHandle, int32 channelType, int32 dataFormat, bool32 interleaved, float64 readArray[], uInt32 arraySizeInSamples, int32 *numSamplesTransferred, uInt64 *sequenceNumber);
    int32 __CFUNC DAQmxInternalGetCachedSamplesU32(TaskHandle taskHandle, int32 channelType, int32 dataFormat, bool32 interleaved, uInt32 readArray[], uInt32 arraySizeInSamples, int32 *numSamplesTransferred, uInt64 *sequenceNumber);
    int32 __CFUNC DAQmxInternalGetCachedSamplesI32(TaskHandle taskHandle, int32 channelType, int32 dataFormat, bool32 interleaved, int32 readArray[], uInt32 arraySizeInSamples, int32 *numSamplesTransferred, uInt64 *sequenceNumber);
    int32 __CFUNC DAQmxInternalGetCachedSamplesU16(TaskHandle taskHandle, int32 channelType, int32 dataFormat, bool32 interleaved, uInt16 readArray[], uInt32 arraySizeInSamples, int32 *numSamplesTransferred, uInt64 *sequenceNumber);
    int32 __CFUNC DAQmxInternalGetCachedSamplesI16(TaskHandle taskHandle, int32 channelType, int32 dataFormat, bool32 interleaved, int16 readArray[], uInt32 arraySizeInSamples, int32 *numSamplesTransferred, uInt64 *sequenceNumber);
    int32 __CFUNC DAQmxInternalGetCachedSamplesU8(TaskHandle taskHandle, int32 channelType, int32 dataFormat, bool32 interleaved, uInt8 readArray[], uInt32 arraySizeInSamples, int32 *numSamplesTransferred, uInt64 *sequenceNumber);
    int32 __CFUNC DAQmxInternalGetCachedSamplesDigitalLines(TaskHandle taskHandle, int32 channelType, int32 dataFormat, bool32 interleaved, uInt8 readArray[], uInt32 arraySizeInBytes, int32 *numSamplesTransferred, uInt64 *sequenceNumber);
    int32 __CFUNC DAQmxInternalGetCachedSamplesAnalogWaveform(TaskHandle taskHandle, int32 channelType, int32 dataFormat, bool32 interleaved, int64 t0Array[], int64 dtArray[], uInt32 timingArraySize, DAQmxSetWfmAttrCallbackPtr setWfmAttrCallback, void *setWfmAttrCallbackData, float64 readArray[], uInt32 arraySizeInSamples, int32 *numSamplesTransferred, uInt64 *sequenceNumber);
    int32 __CFUNC DAQmxInternalGetCachedSamplesDigitalWaveform(TaskHandle taskHandle, int32 channelType, int32 dataFormat, bool32 interleaved, int64 t0Array[], int64 dtArray[], uInt32 timingArraySize, DAQmxSetWfmAttrCallbackPtr setWfmAttrCallback, void *setWfmAttrCallbackData, uInt8 readArray[], uInt32 arraySizeInSamples, int32 *numSamplesTransferred, uInt64 *sequenceNumber);
    int32 __CFUNC DAQmxInternalGetCachedSamplesCtrFrequency(TaskHandle taskHandle, int32 channelType, int32 dataFormat, bool32 interleaved, float64 readArrayFrequency[], float64 readArrayDutyCycle[], uInt32 arraySizeInSamples, int32 *numSamplesTransferred, uInt64 *sequenceNumber);
    int32 __CFUNC DAQmxInternalGetCachedSamplesCtrTime(TaskHandle taskHandle, int32 channelType, int32 dataFormat, bool32 interleaved, float64 readArrayHighTime[], float64 readArrayLowTime[], uInt32 arraySizeInSamples, int32 *numSamplesTransferred, uInt64 *sequenceNumber);
    int32 __CFUNC DAQmxInternalGetCachedSamplesCtrTicks(TaskHandle taskHandle, int32 channelType, int32 dataFormat, bool32 interleaved, uInt32 readArrayHighTicks[], uInt32 readArrayLowTicks[], uInt32 arraySizeInSamples, int32 *numSamplesTransferred, uInt64 *sequenceNumber);
    int32 __CFUNC DAQmxInternalGetCachedSamplesPowerF64(TaskHandle taskHandle, int32 channelType, int32 dataFormat, bool32 interleaved, float64 readArrayVoltage[], float64 readArrayCurrent[], uInt32 arraySizeInSamples, int32 *numSamplesTransferred, uInt64 *sequenceNumber);
    int32 __CFUNC DAQmxInternalGetCachedSamplesPowerBinaryI16(TaskHandle taskHandle, int32 channelType, int32 dataFormat, bool32 interleaved, int16 readArrayVoltage[], int16 readArrayCurrent[], uInt32 arraySizeInSamples, int32 *numSamplesTransferred, uInt64 *sequenceNumber);
    /******************************************************/
    /***                    CEIP                        ***/
    /******************************************************/
    int32 __CFUNC DAQmxSetRuntimeEnvironment(const char environment[], const char environmentVersion[], const char reserved1[], const char reserved2[]);
    /******************************************************/
    /***             Virtual Channel Names              ***/
    /******************************************************/
    int32 __CFUNC DAQmxInternalGetLastCreatedChan(char buffer[], uInt32 bufferSize);
/******************************************************/
/***                Name Controls                   ***/
/******************************************************/
#define DAQmx_Val_IOClass_Task 1
#define DAQmx_Val_IOClass_Channel 2
#define DAQmx_Val_IOClass_Scale 3
#define DAQmx_Val_IOClass_Device 4
#define DAQmx_Val_IOClass_Terminal 5
#define DAQmx_Val_IOClass_PhysChan 6
#define DAQmx_Val_IOClass_Switch 8
#define DAQmx_Val_Bit_DisplayFilter_None (0)
#define DAQmx_Val_Bit_Channel_IOType_AI (1 << 0)
#define DAQmx_Val_Bit_Channel_IOType_AO (1 << 1)
#define DAQmx_Val_Bit_Channel_IOType_DI (1 << 2)
#define DAQmx_Val_Bit_Channel_IOType_DO (1 << 3)
#define DAQmx_Val_Bit_Channel_IOType_CI (1 << 4)
#define DAQmx_Val_Bit_Channel_IOType_CO (1 << 5)
#define DAQmx_Val_Bit_Channel_IOType_Invalid (1 << 6)
#define DAQmx_Val_Bit_Channel_IOType_Nav (1 << 7)
#define DAQmx_Val_Bit_Channel_IOType_Pwr (1 << 8)
#define DAQmx_Val_Bit_PhysChan_IOType_AI (1 << 0)
#define DAQmx_Val_Bit_PhysChan_IOType_AO (1 << 1)
#define DAQmx_Val_Bit_PhysChan_IOType_DI_Line (1 << 2)
#define DAQmx_Val_Bit_PhysChan_IOType_DI_Port (1 << 3)
#define DAQmx_Val_Bit_PhysChan_IOType_DO_Line (1 << 4)
#define DAQmx_Val_Bit_PhysChan_IOType_DO_Port (1 << 5)
#define DAQmx_Val_Bit_PhysChan_IOType_CI (1 << 6)
#define DAQmx_Val_Bit_PhysChan_IOType_CO (1 << 7)
#define DAQmx_Val_Bit_PhysChan_IOType_Switch (1 << 8)
#define DAQmx_Val_Bit_PhysChan_IOType_Nav (1 << 9)
#define DAQmx_Val_Bit_PhysChan_IOType_Pwr (1 << 10)
#define DAQmx_Val_Bit_PhysChan_Category_ExtCommon (1 << 13)
#define DAQmx_Val_Bit_PhysChan_Category_IntCommon (1 << 14)
#define DAQmx_Val_Bit_PhysChan_Category_IntBizarre (1 << 15)
#define DAQmx_Val_Bit_Terminal_Category_Basic (1 << 0)
#define DAQmx_Val_Bit_Terminal_Category_Advanced (1 << 1)
#define DAQmx_Val_Bit_Terminal_Category_Private (1 << 2)
#define DAQmx_Val_Bit_Switch_Category_Chan (1 << 0)
#define DAQmx_Val_Bit_Switch_Category_Relay (1 << 1)
#define DAQmx_Val_Bit_Switch_Category_Topology (1 << 2)
    int32 __CFUNC DAQmxInternalGetFilteredIOControlNames(int32 ioClass, uInt32 displayFilter, const char deviceName[], char buffer[], uInt32 bufferSize);
/******************************************************************************
 *** NI-DAQmx Internal Attribute Values ***************************************
 ******************************************************************************/
//*** Values for DAQmx_AttributeState ***
//*** Value set AttributeState ***
#define DAQmx_Val_AttributeState_Initializing 0 // Initializing
#define DAQmx_Val_AttributeState_NotVerified 1  // Not Verified
#define DAQmx_Val_AttributeState_Verifying 2    // Verifying
#define DAQmx_Val_AttributeState_Verified 3     // Verified
//*** Values for DAQmx_InternalTaskState ***
//*** Value set InternalTaskState ***
#define DAQmx_Val_InternalTaskState_NotVerified 0 // Not Verified
#define DAQmx_Val_InternalTaskState_Verified 1    // Verified
#define DAQmx_Val_InternalTaskState_Reserved 2    // Reserved
#define DAQmx_Val_InternalTaskState_Committed 3   // Committed
#define DAQmx_Val_InternalTaskState_Running 4     // Running
//*** Values for DAQmx_RuntimeState ***
//*** Value set RuntimeState ***
#define DAQmx_Val_RuntimeState_NotReserved 0 // Not Reserved
#define DAQmx_Val_RuntimeState_Reserved 1    // Reserved
#define DAQmx_Val_RuntimeState_Committed 2   // Committed
#define DAQmx_Val_RuntimeState_Running 3     // Running
//*** Values for DAQmx_DebugSession_PrivilegeLevel ***
//*** Value set DebugPrivilegeLevel ***
#define DAQmx_Val_DebugPrivilegeLevel_None 0               // None
#define DAQmx_Val_DebugPrivilegeLevel_Monitor 1            // Monitor
#define DAQmx_Val_DebugPrivilegeLevel_RevocableControl 2   // Revocable Control
#define DAQmx_Val_DebugPrivilegeLevel_IrrevocableControl 3 // Irrevocable Control
/******************************************************************************
 *** NI-DAQmx Internal Attributes *********************************************
 ******************************************************************************/
#define DAQmx_MSeriesLegacyCompatibility 0x2EC8     // xx Set this property to true to enable emulation of bugs present in the DAQ-STC, NI-TIO, and NI-STC 2 ASICs, so that more existing applications will work without further modification. Note that some applications may still require further modifications, such as updating of hardcoded 80 MHz timebase rates/terminals. Set this property to false to disable emulation of DAQ-STC, NI-TIO, and NI-STC 2 bugs.
#define DAQmx_Dev_MSeriesLegacyCompatibility 0x2ECF // xx Specifies the default value of the CI.MSeriesLegacyCompatibility and CO.MSeriesLegacyCompatibility properties. This property is stored in MXS on a per-device basis, and can only be written a limited number of times. Therefore, you should write to this property as infrequently as possible.
#define DAQmx_DefaultNumberOfSamplesToRead 0x31E8   // xx Indicates the default number of samples to read per channel. This value is the same for all channels in the task.
#define DAQmx_RawDataWidthInBits 0x31E9             // xx Indicates in bits the size of a raw sample from the task. The bit width accounts for compressed data, while the byte width does not.
#define DAQmx_AttributeState 0x3199                 // xx Indicates the current attribute state of a DAQmx Task.
#define DAQmx_InternalTaskState 0x319A              // xx Indicates the current internal state of a DAQmx Task.
#define DAQmx_RuntimeState 0x319B                   // xx Indicates the current runtime state of a DAQmx Task.
#define DAQmx_DebugSession_Enable 0x31A1            // xx Specifies whether this task is a debug session. A debug session is a task that monitors or controls another task, which may be running in a different process.
#define DAQmx_DebugSession_PrivilegeLevel 0x31A2    // xx Specifies the debug session's privilege level.
#define DAQmx_DebugSession_Target_ProcessId 0x31A3  // xx Specifies the debug session's target process identifier. If this attribute is set, then the debug session looks for tasks matching this process identifier; otherwise, the debug session ignores the process identifier when looking for tasks.
#define DAQmx_DebugSession_Target_TaskName 0x31A4   // xx Specifies the debug session's target task name. If this attribute is set, then the debug session looks for tasks matching this task name; otherwise, the debug session ignores the task name when looking for tasks.
#define DAQmx_DebugSession_Target_Devices 0x31A5    // xx Specifies the debug session's target devices. If this attribute is set, then the debug session looks for tasks containing one or more of these devices; otherwise, the debug session ignores device names when looking for tasks.
#define DAQmx_DebugSession_Target_PhysChans 0x31A6  // xx Specifies the debug session's target physical channels. If this attribute is set, then the debug session looks for tasks containing one or more of these physical channels; otherwise, the debug session ignores physical channels when looking for tasks.
#define DAQmx_DebugSession_Target_PipeName 0x31A9   // xx Specifies the debug session's target pipe name. This is for testing the debug session code. Clients should use the other debug session target properties.
    /******************************************************************************
     *** NI-DAQmx Internal Attribute Get/Set/Reset Function Declarations **********
     ******************************************************************************/
    //*** Set/Get functions for DAQmx_MSeriesLegacyCompatibility ***
    int32 __CFUNC DAQmxGetMSeriesLegacyCompatibility(TaskHandle taskHandle, const char channel[], bool32 *data);
    int32 __CFUNC DAQmxSetMSeriesLegacyCompatibility(TaskHandle taskHandle, const char channel[], bool32 data);
    int32 __CFUNC DAQmxResetMSeriesLegacyCompatibility(TaskHandle taskHandle, const char channel[]);
    //*** Set/Get functions for DAQmx_Dev_MSeriesLegacyCompatibility ***
    int32 __CFUNC DAQmxGetDevMSeriesLegacyCompatibility(const char device[], bool32 *data);
    int32 __CFUNC DAQmxSetDevMSeriesLegacyCompatibility(const char device[], bool32 data);
    //*** Set/Get functions for DAQmx_DefaultNumberOfSamplesToRead ***
    int32 __CFUNC DAQmxGetDefaultNumberOfSamplesToRead(TaskHandle taskHandle, uInt32 *data);
    //*** Set/Get functions for DAQmx_RawDataWidthInBits ***
    int32 __CFUNC DAQmxGetRawDataWidthInBits(TaskHandle taskHandle, uInt32 *data);
    //*** Set/Get functions for DAQmx_AttributeState ***
    // Uses value set AttributeState
    int32 __CFUNC DAQmxGetAttributeState(TaskHandle taskHandle, int32 *data);
    //*** Set/Get functions for DAQmx_InternalTaskState ***
    // Uses value set InternalTaskState
    int32 __CFUNC DAQmxGetInternalTaskState(TaskHandle taskHandle, int32 *data);
    //*** Set/Get functions for DAQmx_RuntimeState ***
    // Uses value set RuntimeState
    int32 __CFUNC DAQmxGetRuntimeState(TaskHandle taskHandle, int32 *data);
    //*** Set/Get functions for DAQmx_DebugSession_Enable ***
    int32 __CFUNC DAQmxGetDebugSessionEnable(TaskHandle taskHandle, bool32 *data);
    int32 __CFUNC DAQmxSetDebugSessionEnable(TaskHandle taskHandle, bool32 data);
    int32 __CFUNC DAQmxResetDebugSessionEnable(TaskHandle taskHandle);
    //*** Set/Get functions for DAQmx_DebugSession_PrivilegeLevel ***
    // Uses value set DebugPrivilegeLevel
    int32 __CFUNC DAQmxGetDebugSessionPrivilegeLevel(TaskHandle taskHandle, int32 *data);
    int32 __CFUNC DAQmxSetDebugSessionPrivilegeLevel(TaskHandle taskHandle, int32 data);
    int32 __CFUNC DAQmxResetDebugSessionPrivilegeLevel(TaskHandle taskHandle);
    //*** Set/Get functions for DAQmx_DebugSession_Target_ProcessId ***
    int32 __CFUNC DAQmxGetDebugSessionTargetProcessId(TaskHandle taskHandle, int32 *data);
    int32 __CFUNC DAQmxSetDebugSessionTargetProcessId(TaskHandle taskHandle, int32 data);
    int32 __CFUNC DAQmxResetDebugSessionTargetProcessId(TaskHandle taskHandle);
    //*** Set/Get functions for DAQmx_DebugSession_Target_TaskName ***
    int32 __CFUNC DAQmxGetDebugSessionTargetTaskName(TaskHandle taskHandle, char *data, uInt32 bufferSize);
    int32 __CFUNC DAQmxSetDebugSessionTargetTaskName(TaskHandle taskHandle, const char *data);
    int32 __CFUNC DAQmxResetDebugSessionTargetTaskName(TaskHandle taskHandle);
    //*** Set/Get functions for DAQmx_DebugSession_Target_Devices ***
    int32 __CFUNC DAQmxGetDebugSessionTargetDevices(TaskHandle taskHandle, char *data, uInt32 bufferSize);
    int32 __CFUNC DAQmxSetDebugSessionTargetDevices(TaskHandle taskHandle, const char *data);
    int32 __CFUNC DAQmxResetDebugSessionTargetDevices(TaskHandle taskHandle);
    //*** Set/Get functions for DAQmx_DebugSession_Target_PhysChans ***
    int32 __CFUNC DAQmxGetDebugSessionTargetPhysChans(TaskHandle taskHandle, char *data, uInt32 bufferSize);
    int32 __CFUNC DAQmxSetDebugSessionTargetPhysChans(TaskHandle taskHandle, const char *data);
    int32 __CFUNC DAQmxResetDebugSessionTargetPhysChans(TaskHandle taskHandle);
    //*** Set/Get functions for DAQmx_DebugSession_Target_PipeName ***
    int32 __CFUNC DAQmxGetDebugSessionTargetPipeName(TaskHandle taskHandle, char *data, uInt32 bufferSize);
    int32 __CFUNC DAQmxSetDebugSessionTargetPipeName(TaskHandle taskHandle, const char *data);
    int32 __CFUNC DAQmxResetDebugSessionTargetPipeName(TaskHandle taskHandle);
#ifdef __cplusplus
}
#endif
#endif // ___nicai_NIDAQmxInternal_h___
