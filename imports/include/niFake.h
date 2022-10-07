/*
    **** THIS FILE IS GENERATED. ANY CHANGES WILL BE OVERWRITTEN! ****
    Command-line: c:/perforce/build/exports/ni/hapi/hapigen/official/export/23.0/23.0.0d18/tools/win32/i386/hapigen_render.exe --processed-metadata-path c:/dev/_r/1/src/hapigen/niFakeHeaders/objects/niFakeHeaders/win64U/x64/other/release/cheader_expanded_metadata.hapigen_processed --template-path c:/perforce/build/exports/ni/hapi/hapigen_cheader_plugin/official/export/23.0/23.0.0d18/templates/ivi_based_public_header.h.mako --output-path ./objects/codegen/niFakeHeaders/niFake.h --template-search-path c:/perforce/build/exports/ni/hapi/hapigen/official/export/23.0/23.0.0d18/templates --template-search-path c:/perforce/build/exports/ni/hapi/hapigen_cheader_plugin/official/export/23.0/23.0.0d18/templates
*/

#ifndef __NIFAKE_HEADER
#define __NIFAKE_HEADER

/******************************************************************************/
/*                               Include Files                                */
/******************************************************************************/

#define IVI_DO_NOT_INCLUDE_VISA_HEADERS
#include <IviVisaType.h>
#undef IVI_DO_NOT_INCLUDE_VISA_HEADERS

#ifdef _CVI_
#pragma EnableLibraryRuntimeChecking
#endif

/****************************************************************************
 *----------------- Instrument Driver Revision Information -----------------*
 ****************************************************************************/
#define NIFAKE_MAJOR_VERSION                                   23                              // Instrument driver major version
#define NIFAKE_MINOR_VERSION                                   0                               // Instrument driver minor version
#define NIFAKE_UPDATE_VERSION                                  0                               // Instrument driver update version


#define NIFAKE_ATTR_BASE                                       1000000                         // 1000000 (0xf4240)
#define NIFAKE_ATTR_PRIVATE_BASE                               (NIFAKE_ATTR_BASE + 100L)       // 1000100 (0xf42a4)
#define NIFAKE_MAX_MESSAGE_BUF_SIZE                            256                             // 256 (0x100)
#define NIFAKE_FLAG0                                           (1L << 0)                       // 1 (0x1)
#define NIFAKE_FLAG1                                           (1L << 1)                       // 2 (0x2)
#define NIFAKE_FLAG2                                           (1L << 2)                       // 4 (0x4)
#define NIFAKE_FLAG3                                           (1L << 3)                       // 8 (0x8)
#define NIFAKE_FLAG4                                           (1L << 4)                       // 16 (0x10)
#define NIFAKE_FLAG5                                           (1L << 5)                       // 32 (0x20)
#define NIFAKE_FLAG6                                           (1L << 6)                       // 64 (0x40)
#define NIFAKE_FLAG7                                           (1L << 7)                       // 128 (0x80)
#define NIFAKE_FLAG8                                           (1L << 8)                       // 256 (0x100)
#define NIFAKE_FLAG_FLAG3                                      (1L << NIFAKE_FLAG3)            // 256 (0x100)
#define NIFAKE_FLAG_COMBO0                                     (NIFAKE_FLAG0 | NIFAKE_FLAG1)   // 3 (0x3)
#define NIFAKE_FLAG_COMBO1                                     (NIFAKE_FLAG1 | NIFAKE_FLAG4)   // 18 (0x12)
#define NIFAKE_FLOAT_DEFINE                                    42.0
#define NIFAKE_INT_DEFINE                                      42                              // 42 (0x2a)

// Values
// Alt Color
// Test comment
#define NIFAKE_VAL_RED                                         1                               // 1 (0x1)
#define NIFAKE_VAL_BLUE                                        (NIFAKE_VAL_RED + 1L)           // 2 (0x2)
#define NIFAKE_VAL_YELLOW                                      5                               // 5 (0x5)
#define NIFAKE_VAL_BLACK                                       42                              // 42 (0x2a)

// Beautiful Color
#define NIFAKE_VAL_PINK                                        44                              // 44 (0x2c)
#define NIFAKE_VAL_AQUA                                        43                              // 43 (0x2b)
#define NIFAKE_VAL_GREEN                                       45                              // 45 (0x2d)
// #define NIFAKE_VAL_BLACK                                    DEFINED ABOVE (42)              // 42 (0x2a)

// Test comment
// Values used in
//     NIFAKE_ATTR_READ_WRITE_COLOR
// #define NIFAKE_VAL_RED                                      DEFINED ABOVE (1)               // 1 (0x1)
// #define NIFAKE_VAL_BLUE                                     DEFINED ABOVE ((NIFAKE_VAL_RED + 1L)) // 2 (0x2)
// #define NIFAKE_VAL_YELLOW                                   DEFINED ABOVE (5)               // 5 (0x5)
// #define NIFAKE_VAL_BLACK                                    DEFINED ABOVE (42)              // 42 (0x2a)

// Test comment
// Values used in
//     NIFAKE_ATTR_READ_WRITE_ENUM_WITH_CONVERTER
// #define NIFAKE_VAL_RED                                      DEFINED ABOVE (1)               // 1 (0x1)
// #define NIFAKE_VAL_BLUE                                     DEFINED ABOVE ((NIFAKE_VAL_RED + 1L)) // 2 (0x2)
// #define NIFAKE_VAL_YELLOW                                   DEFINED ABOVE (5)               // 5 (0x5)
// #define NIFAKE_VAL_BLACK                                    DEFINED ABOVE (42)              // 42 (0x2a)

// Values used in
//     NIFAKE_ATTR_FLOAT_ENUM, niFake_ParametersAreMultipleTypes, niFake_ReturnMultipleTypes
#define NIFAKE_VAL_THREE_POINT_FIVE                            3.5
#define NIFAKE_VAL_FOUR_POINT_FIVE                             4.5
#define NIFAKE_VAL_FIVE_POINT_FIVE                             5.5
#define NIFAKE_VAL_SIX_POINT_FIVE                              6.5
#define NIFAKE_VAL_SEVEN_POINT_FIVE                            7.5

// Values used in
//     niFake_StringValuedEnumInputFunctionWithDefaults
#define NIFAKE_VAL_ANDROID                                     "Android"
#define NIFAKE_VAL_IOS                                         "iOS"
#define NIFAKE_VAL_NONE                                        "None"

// Values used in
//     niFake_EnumArrayOutputFunction, niFake_EnumInputFunctionWithDefaults, niFake_GetEnumValue,
//     niFake_ParametersAreMultipleTypes, niFake_ReturnMultipleTypes
#define NIFAKE_VAL_LEONARDO                                    0                               // 0 (0x0)
#define NIFAKE_VAL_DONATELLO                                   1                               // 1 (0x1)
#define NIFAKE_VAL_RAPHAEL                                     2                               // 2 (0x2)
#define NIFAKE_VAL_MICHELANGELO                                3                               // 3 (0x3)

// Attributes
#define NIFAKE_ATTR_READ_WRITE_BOOL                            (NIFAKE_ATTR_BASE + 0L)         // 1000000 (0xf4240), ViBoolean
#define NIFAKE_ATTR_READ_WRITE_DOUBLE                          (NIFAKE_ATTR_BASE + 1L)         // 1000001 (0xf4241), ViReal64
#define NIFAKE_ATTR_READ_WRITE_STRING                          (NIFAKE_ATTR_BASE + 2L)         // 1000002 (0xf4242), ViString
#define NIFAKE_ATTR_READ_WRITE_COLOR                           (NIFAKE_ATTR_BASE + 3L)         // 1000003 (0xf4243), ViInt32
#define NIFAKE_ATTR_READ_WRITE_INTEGER                         (NIFAKE_ATTR_BASE + 4L)         // 1000004 (0xf4244), ViInt32
// Test comment
#define NIFAKE_ATTR_FLOAT_ENUM                                 (NIFAKE_ATTR_BASE + 5L)         // 1000005 (0xf4245), ViReal64
#define NIFAKE_ATTR_READ_WRITE_INT64                           (NIFAKE_ATTR_BASE + 6L)         // 1000006 (0xf4246), ViInt64
#define NIFAKE_ATTR_READ_WRITE_DOUBLE_WITH_CONVERTER           (NIFAKE_ATTR_BASE + 7L)         // 1000007 (0xf4247), ViReal64
#define NIFAKE_ATTR_READ_WRITE_INTEGER_WITH_CONVERTER          (NIFAKE_ATTR_BASE + 8L)         // 1000008 (0xf4248), ViInt32
#define NIFAKE_ATTR_READ_WRITE_DOUBLE_WITH_REPEATED_CAPABILITY (NIFAKE_ATTR_BASE + 9L)         // 1000009 (0xf4249), ViReal64,   multi-channel
#define NIFAKE_ATTR_READ_WRITE_STRING_REPEATED_CAPABILITY      (NIFAKE_ATTR_BASE + 10L)        // 1000010 (0xf424a), ViString
#define NIFAKE_ATTR_READ_WRITE_ENUM_WITH_CONVERTER             (NIFAKE_ATTR_BASE + 11L)        // 1000011 (0xf424b), ViInt32

#pragma pack(push,8)
// Test comment
#if !defined(_NIStruct)
#define _NIStruct
struct CustomStruct
{
    ViInt32 structInt;
    ViReal64 structDouble;
};
#endif // !defined(_NIStruct)

// Test comment
#if !defined(_NIStructTypedef)
#define _NIStructTypedef
typedef struct CustomStructTypedef_struct
{
    ViInt32 structInt;
    ViReal64 structDouble;
} CustomStructTypedef;
#endif // !defined(_NIStructTypedef)

// Test comment
#if !defined(_NIStructNestedTypedef)
#define _NIStructNestedTypedef
typedef struct CustomStructNestedTypedef_struct
{
    struct CustomStruct structCustomStruct;
    CustomStructTypedef structCustomStructTypedef;
} CustomStructNestedTypedef;
#endif // !defined(_NIStructNestedTypedef)

#pragma pack(pop)

// Functions
ViStatus _VI_FUNC niFake_Abort(
   ViSession vi);

ViStatus _VI_FUNC niFake_BoolArrayOutputFunction(
   ViSession vi,
   ViInt32 numberOfElements,
   ViBoolean anArray[]);

ViStatus _VI_FUNC niFake_ClearError(
   ViSession vi);

ViStatus _VI_FUNC niFake_close(
   ViSession vi);

ViStatus _VI_FUNC niFake_EnumArrayOutputFunction(
   ViSession vi,
   ViInt32 numberOfElements,
   ViInt16 anArray[]);

ViStatus _VI_FUNC niFake_EnumInputFunctionWithDefaults(
   ViSession vi,
   ViInt16 aTurtle);

ViStatus _VI_FUNC niFake_StringValuedEnumInputFunctionWithDefaults(
   ViSession vi,
   ViConstString aMobileOSName);

ViStatus _VI_FUNC niFake_error_message(
   ViSession vi,
   ViStatus errorCode,
   ViChar errorMessage[NIFAKE_MAX_MESSAGE_BUF_SIZE]);

ViStatus _VI_FUNC niFake_FetchWaveform(
   ViSession vi,
   ViInt32 numberOfSamples,
   ViReal64 waveformData[],
   ViInt32* actualNumberOfSamples);

ViStatus _VI_FUNC niFake_GetABoolean(
   ViSession vi,
   ViBoolean* aBoolean);

ViStatus _VI_FUNC niFake_GetANumber(
   ViSession vi,
   ViInt16* aNumber);

ViStatus _VI_FUNC niFake_GetAStringOfFixedMaximumSize(
   ViSession vi,
   ViChar aString[NIFAKE_MAX_MESSAGE_BUF_SIZE]);

ViStatus _VI_FUNC niFake_GetAStringUsingPythonCode(
   ViSession vi,
   ViInt16 aNumber,
   ViChar aString[]);

// Test comment
ViStatus _VI_FUNC niFake_GetAnIviDanceString(
   ViSession vi,
   ViInt32 bufferSize,
   ViChar aString[]);

ViStatus _VI_FUNC niFake_GetArrayForPythonCodeDouble(
   ViSession vi,
   ViInt32 numberOfElements[],
   ViReal64 arrayOut[]);

ViStatus _VI_FUNC niFake_GetArraySizeForPythonCode(
   ViSession vi,
   ViInt32* sizeOut);

ViStatus _VI_FUNC niFake_GetArrayUsingIviDance(
   ViSession vi,
   ViInt32 arraySize,
   ViReal64 arrayOut[]);

ViStatus _VI_FUNC niFake_GetAttributeViBoolean(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViBoolean* attributeValue);

ViStatus _VI_FUNC niFake_GetAttributeViInt32(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt32* attributeValue);

ViStatus _VI_FUNC niFake_GetAttributeViInt64(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt64* attributeValue);

ViStatus _VI_FUNC niFake_GetAttributeViReal64(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViReal64* attributeValue);

ViStatus _VI_FUNC niFake_GetAttributeViSession(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViSession* attributeValue);

ViStatus _VI_FUNC niFake_GetAttributeViString(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt32 bufferSize,
   ViChar attributeValue[]);

ViStatus _VI_FUNC niFake_GetCalDateAndTime(
   ViSession vi,
   ViInt32 calType,
   ViInt32* month,
   ViInt32* day,
   ViInt32* year,
   ViInt32* hour,
   ViInt32* minute);

ViStatus _VI_FUNC niFake_GetCalInterval(
   ViSession vi,
   ViInt32* months);

ViStatus _VI_FUNC niFake_GetEnumValue(
   ViSession vi,
   ViInt32* aQuantity,
   ViInt16* aTurtle);

ViStatus _VI_FUNC niFake_GetError(
   ViSession vi,
   ViStatus* errorCode,
   ViInt32 bufferSize,
   ViChar description[]);

ViStatus _VI_FUNC niFake_GetErrorMessage(
   ViSession vi,
   ViStatus errorCode,
   ViInt32 bufferSize,
   ViChar errorMessage[]);

ViStatus _VI_FUNC niFake_InitWithOptions(
   ViString resourceName,
   ViBoolean idQuery,
   ViBoolean resetDevice,
   ViConstString optionString,
   ViSession* vi);

ViStatus _VI_FUNC niFake_Initiate(
   ViSession vi);

ViStatus _VI_FUNC niFake_LockSession(
   ViSession vi,
   ViBoolean* callerHasLock);

ViStatus _VI_FUNC niFake_UnlockSession(
   ViSession vi,
   ViBoolean* callerHasLock);

ViStatus _VI_FUNC niFake_MultipleArrayTypes(
   ViSession vi,
   ViInt32 outputArraySize,
   ViReal64 outputArray[],
   ViReal64 outputArrayOfFixedLength[3],
   ViInt32 inputArraySizes,
   ViReal64 inputArrayOfFloats[],
   ViInt16 inputArrayOfIntegers[]);

ViStatus _VI_FUNC niFake_MultipleArraysSameSize(
   ViSession vi,
   ViReal64 values1[],
   ViReal64 values2[],
   ViReal64 values3[],
   ViReal64 values4[],
   ViInt32 size);

ViStatus _VI_FUNC niFake_OneInputFunction(
   ViSession vi,
   ViInt32 aNumber);

ViStatus _VI_FUNC niFake_ParametersAreMultipleTypes(
   ViSession vi,
   ViBoolean aBoolean,
   ViInt32 anInt32,
   ViInt64 anInt64,
   ViInt16 anIntEnum,
   ViReal64 aFloat,
   ViReal64 aFloatEnum,
   ViInt32 stringSize,
   ViConstString aString[]);

ViStatus _VI_FUNC niFake_PoorlyNamedSimpleFunction(
   ViSession vi);

ViStatus _VI_FUNC niFake_Read(
   ViSession vi,
   ViReal64 maximumTime,
   ViReal64* reading);

ViStatus _VI_FUNC niFake_ReadFromChannel(
   ViSession vi,
   ViConstString channelName,
   ViInt32 maximumTime,
   ViReal64* reading);

ViStatus _VI_FUNC niFake_ReturnANumberAndAString(
   ViSession vi,
   ViInt16* aNumber,
   ViChar aString[NIFAKE_MAX_MESSAGE_BUF_SIZE]);

ViStatus _VI_FUNC niFake_ReturnMultipleTypes(
   ViSession vi,
   ViBoolean* aBoolean,
   ViInt32* anInt32,
   ViInt64* anInt64,
   ViInt16* anIntEnum,
   ViReal64* aFloat,
   ViReal64* aFloatEnum,
   ViInt32 arraySize,
   ViReal64 anArray[],
   ViInt32 stringSize,
   ViChar aString[]);

ViStatus _VI_FUNC niFake_self_test(
   ViSession vi,
   ViInt16* selfTestResult,
   ViChar selfTestMessage[NIFAKE_MAX_MESSAGE_BUF_SIZE]);

ViStatus _VI_FUNC niFake_SetAttributeViBoolean(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViBoolean attributeValue);

ViStatus _VI_FUNC niFake_SetAttributeViInt32(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt32 attributeValue);

ViStatus _VI_FUNC niFake_SetAttributeViInt64(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt64 attributeValue);

ViStatus _VI_FUNC niFake_SetAttributeViReal64(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViReal64 attributeValue);

ViStatus _VI_FUNC niFake_SetAttributeViSession(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViSession attributeValue);

ViStatus _VI_FUNC niFake_SetAttributeViString(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViConstString attributeValue);

ViStatus _VI_FUNC niFake_TwoInputFunction(
   ViSession vi,
   ViReal64 aNumber,
   ViString aString);

ViStatus _VI_FUNC niFake_Use64BitNumber(
   ViSession vi,
   ViInt64 input,
   ViInt64* output);

ViStatus _VI_FUNC niFake_WriteWaveform(
   ViSession vi,
   ViInt32 numberOfSamples,
   ViReal64 waveform[]);

ViStatus _VI_FUNC niFake_SetCustomType(
   ViSession vi,
   struct CustomStruct* cs);

ViStatus _VI_FUNC niFake_SetCustomTypeArray(
   ViSession vi,
   ViInt32 numberOfElements,
   struct CustomStruct cs[]);

ViStatus _VI_FUNC niFake_GetCustomType(
   ViSession vi,
   struct CustomStruct* cs);

ViStatus _VI_FUNC niFake_GetCustomTypeArray(
   ViSession vi,
   ViInt32 numberOfElements,
   struct CustomStruct cs[]);

ViStatus _VI_FUNC niFake_GetArrayForPythonCodeCustomType(
   ViSession vi,
   ViInt32 numberOfElements[],
   struct CustomStruct arrayOut[]);

ViStatus _VI_FUNC niFake_ResetAttribute(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId);

ViStatus _VI_FUNC niFake_GetAttributeWithOptionsViInt32(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt32 retrievalMode,
   ViInt32* attributeValue);

ViStatus _VI_FUNC niFake_GetAttributeWithOptionsViReal64(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt32 retrievalMode,
   ViReal64* attributeValue);

ViStatus _VI_FUNC niFake_GetAttributeWithOptionsViString(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt32 retrievalMode,
   ViInt32 bufferSize,
   ViChar attributeValue[]);

ViStatus _VI_FUNC niFake_OneOutputFunction(
   ViSession vi,
   ViInt16* aNumber);

ViStatus _VI_FUNC niFake_GetAnIviDanceWithATwistString(
   ViSession vi,
   ViInt32 bufferSize,
   ViChar aString[],
   ViInt32* actualSize);

ViStatus _VI_FUNC niFake_InitializeWithChannels(
   ViRsrc resourceName,
   ViConstString channels,
   ViBoolean reset,
   ViConstString optionString,
   ViSession* newVi);

ViStatus _VI_FUNC niFake_GetChannelName(
   ViSession vi,
   ViInt32 index,
   ViInt32 nameSize,
   ViChar name[]);

ViStatus _VI_FUNC niFake_GetChannelNames(
   ViSession vi,
   ViConstString indices,
   ViInt32 nameSize,
   ViChar names[]);

ViStatus _VI_FUNC niFake_GetAttributeWithOptionsViInt64(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt32 retrievalMode,
   ViInt64* attributeValue);

ViStatus _VI_FUNC niFake_GetAttributeWithOptionsViSession(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt32 retrievalMode,
   ViSession* attributeValue);

ViStatus _VI_FUNC niFake_GetAttributeWithOptionsViBoolean(
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId,
   ViInt32 retrievalMode,
   ViBoolean* attributeValue);

ViStatus _VI_FUNC niFake_AttributeWasSetByUser(
   ViSession vi,
   ViConstString repCapName,
   ViAttr attributeId,
   ViBoolean* wasSetByUser);

ViStatus _VI_FUNC niFake_DisableParentSessionAutoClose(
   ViSession vi);

ViStatus _VI_FUNC niFake_DoubleAllTheNums(
   ViSession vi,
   ViInt32 numberCount,
   ViReal64 numbers[]);

ViStatus _VI_FUNC niFake_GetCustomTypeTypedef(
   ViSession vi,
   CustomStructTypedef* cst,
   CustomStructNestedTypedef* csnt);

ViStatus _VI_FUNC niFake_AcceptListOfDurationsInSeconds(
   ViSession vi,
   ViInt32 count,
   ViReal64 delays[]);

ViStatus _VI_FUNC niFake_ReturnDurationInSeconds(
   ViSession vi,
   ViReal64* timedelta);

ViStatus _VI_FUNC niFake_ReturnListOfDurationsInSeconds(
   ViSession vi,
   ViInt32 numberOfElements,
   ViReal64 timedeltas[]);

ViStatus _VI_FUNC niFake_FunctionWithRepeatedCapabilityType(
   ViSession vi,
   ViConstString siteList);

// Test comment
ViStatus _VI_FUNC niDifferentPrefix_GetAnIviDanceWithCFunctionPrefixString(
   ViSession vi,
   ViInt32 bufferSize,
   ViChar aString[]);

ViStatus _VI_FUNC niFake_ImportAttributeConfigurationBuffer(
   ViSession vi,
   ViInt32 sizeInBytes,
   ViInt8 configuration[]);

ViStatus _VI_FUNC niFake_ExportAttributeConfigurationBuffer(
   ViSession vi,
   ViInt32 sizeInBytes,
   ViInt8 configuration[]);


// Errors and Warnings

#include "niFakeObsolete.h"

#endif /* __NIFAKE_HEADER */
