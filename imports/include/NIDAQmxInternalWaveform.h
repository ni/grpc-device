#ifndef ___nicai_NIDAQmxInternal_h___
#define ___nicai_NIDAQmxInternal_h___
#include "NIDAQmx.h"
#ifdef __cplusplus
extern "C"
{
#endif
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
#ifdef __cplusplus
}
#endif
#endif // ___nicai_NIDAQmxInternal_h___
