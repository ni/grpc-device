#ifndef ___niScopeCal_h___
#define ___niScopeCal_h___

#ifndef ___niScope_h___
#include "niScope.h"
#endif

/* Pragma used in CVI to indicate that functions in this file have
 * user protection associated with them */
#ifdef _CVI_
 #pragma EnableLibraryRuntimeChecking
#endif

// Values used in
//     niScope_CalEnd
#define NISCOPE_VAL_CAL_ACTION_STORE                                           0                                                             // 0 (0x0)
#define NISCOPE_VAL_CAL_ACTION_ABORT                                           1                                                             // 1 (0x1)
#define NISCOPE_VAL_CAL_ACTION_RESET                                           101                                                           // 101 (0x65)

// Options For Error Handling
#define NISCOPE_VAL_CAL_ABORT_ON_ERR                                           0                                                             // 0 (0x0)
#define NISCOPE_VAL_CAL_ABORT_ON_MAJOR_ERR                                     1                                                             // 1 (0x1)
#define NISCOPE_VAL_CAL_SKIP_BAD_SECTIONS                                      2                                                             // 2 (0x2)
#define NISCOPE_VAL_CAL_RESET_BAD_SECTIONS                                     3                                                             // 3 (0x3)

// Values used in
//     niScope_CalFetchCount, niScope_CalFetchDate
#define NISCOPE_VAL_CAL_SELF                                                   1                                                             // 1 (0x1)
#define NISCOPE_VAL_CAL_EXTERNAL                                               0                                                             // 0 (0x0)
#define NISCOPE_VAL_CAL_MANUFACTURE                                            2                                                             // 2 (0x2)

// Values used in
//     niScope_CalRouteInternalReference
#define NISCOPE_VAL_CAL_UNROUTE_SIGNAL                                         (ViUInt32)0xfffffff
#define NISCOPE_VAL_CAL_POSITIVE                                               (ViUInt32)0xffff
#define NISCOPE_VAL_CAL_NEGATIVE                                               0                                                             // 0 (0x0)

// Values used in
//     niScope_CalSetAccessorySource
#define NISCOPE_VAL_CAL_SOURCE_GROUND                                          0                                                             // 0 (0x0)
#define NISCOPE_VAL_CAL_SOURCE_POSITIVEFS                                      1                                                             // 1 (0x1)
#define NISCOPE_VAL_CAL_SOURCE_NEGATIVEFS                                      2                                                             // 2 (0x2)

// Reference Parameter For Routing And Storing And Fetching Int Ref
#define NISCOPE_VAL_CAL_10V_CH0                                                0                                                             // 0 (0x0)


#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

// -- Open / Close / Change Password --
// Gives calibration session handle
ViStatus _VI_FUNC niScope_CalStart(
   ViRsrc resourceName,             // e.g. "DAQ:1"
   ViConstString password,          // pointer to 4 bytes for password, 0 or "" by default
   ViSession* newSessionHandle);    // returns this session handle

// Either store constants in eeprom or abort.
ViStatus _VI_FUNC niScope_CalEnd(
   ViSession vi,                    // session handle from CalStart
   ViInt32 action);                 // see defined "action" constants above

// If the old password is correct, the new password is stored in eeprom
ViStatus _VI_FUNC niScope_CalChangePassword(
   ViSession vi,                    // session handle from CalStart or niScope_init
   ViConstString oldPassword,       // previous password is verfied (pointer to 4 bytes)
   ViConstString newPassword);      // new password is written to eeprom (pointer to 4 bytes)

// -- Fetch --
ViStatus _VI_FUNC niScope_CalFetchCount(
   ViSession vi,                    // session handle from CalStart or niScope_init
   ViInt32 whichOne,                // internal or external count: see defines
   ViInt32* calibrationCount);      // number of calibrations peformed

ViStatus _VI_FUNC niScope_CalFetchDate(
   ViSession vi,                    // session handle from CalStart or niScope_init
   ViInt32 whichOne,                // internal or external cal date, or manufacture date
   ViInt32* year,                   // year of last calibration from eeprom
   ViInt32* month,                  // month of last calibration from eeprom
   ViInt32* day);                   // day of last calibration from eeprom

// Not supported yet, but will be for temperature sensing devices
ViStatus _VI_FUNC niScope_CalFetchTemperature(
   ViSession vi,                    // session handle from CalStart or niScope_init
   ViInt32 whichOne,                // internal or external cal temperature
   ViReal64* temperature);          // temperature in degrees C

ViStatus _VI_FUNC niScope_CalFetchMiscInfo(
   ViSession vi,                    // session handle from CalStart or niScope_init
   ViChar miscInfo[5]);             // pointer to 5 bytes; returned from eeprom

// Return the last stored internal reference value.
// This value is not used during device operation.
ViStatus _VI_FUNC niScope_CalFetchInternalReference(
   ViSession vi,                    // session handle from CalStart or niScope_init
   ViInt32 whichReference,          // see defines
   ViReal64* internalRefValue);     // last stored internal reference measurement

// -- Store --
ViStatus _VI_FUNC niScope_CalStoreMiscInfo(
   ViSession vi,                    // session handle from CalStart
   ViConstString miscInfo);         // pointer to 4 characters to store in eeprom (operator id?)

// For verification, store the internal reference. This value is not
// used during device operation.
ViStatus _VI_FUNC niScope_CalStoreInternalReference(
   ViSession vi,                    // session handle from CalStart
   ViInt32 whichReference,          // see defines
   ViReal64 internalRefValue);      // last stored internal reference measurement

// -- Adjustment --
ViStatus _VI_FUNC niScope_CalAdjustRange(
   ViSession vi,                    // session handle from CalStart
   ViConstString channelName,       // e.g. "0" or "1"
   ViReal64 range,                  // see niscope calibration document
   ViReal64 stimulus);              // peak voltage of applied signal

ViStatus _VI_FUNC niScope_CalAdjustVCXO(
   ViSession vi,                    // session handle from CalStart
   ViReal64 stimulusFreq);          // frequency of applied signal

ViStatus _VI_FUNC niScope_CalAdjustDCM(
   ViSession vi,                    // session handle from CalStart
   ViConstString channelName,       // e.g. "0" or "1"
   ViReal64 stimulusFreq);          // frequency of applied signal

ViStatus _VI_FUNC niScope_CalAdjustOffset(
   ViSession vi,                    // session handle from CalStart
   ViConstString channelName,       // e.g. "0" or "1"
   ViReal64 range);                 // see niscope calibration document

ViStatus _VI_FUNC niScope_CalAdjustOffsetRange(
   ViSession vi,                    // session handle from CalStart
   ViConstString channelName,       // e.g. "0" or "1"
   ViReal64 range,                  // see niscope calibration document
   ViReal64 stimulus);              // peak voltage of applied signal

ViStatus _VI_FUNC niScope_CalAdjustCompensationAttenuator(
   ViSession vi,                    // session handle from CalStart
   ViConstString channelName,       // e.g. "0" or "1"
   ViReal64 range);                 // see niscope calibration document

ViStatus _VI_FUNC niScope_CalAdjustFrequencyResponse(
   ViSession vi,                    // session handle from CalStart
   ViConstString channelName,       // e.g. "0" or "1"
   ViReal64 range,                  // see niscope calibration document
   ViReal64 stimulusFreq,           // frequency of applied signal
   ViReal64 stimulusAmp);           // peak voltage of applied signal

// For the 5911 external calibration with a single DC external voltage source
ViStatus _VI_FUNC niScope_CalAdjustInternalReference(
   ViSession vi,                    // session handle from CalStart
   ViInt32 option,                  // use VI_NULL
   ViReal64 stimulus);              // voltage of applied signal

// For 5112 verification, this routes the internal reference out the
// front BNC connector for measurement.
ViStatus _VI_FUNC niScope_CalRouteInternalReference(
   ViSession vi,                    // session handle from CalStart
   ViInt32 option,                  // see defines
   ViInt32 whichReference);         // see constants

// For the 5900 external calibration
ViStatus _VI_FUNC niScope_CalAdjustAccessoryGainAndOffset(
   ViSession vi,                    // session handle from CalStart
   ViConstString channelName,       // e.g. "0" or "1"
   ViReal64 posFs,
   ViReal64 gnd,
   ViReal64 negFs);

ViStatus _VI_FUNC niScope_CalSetAccessorySource(
   ViSession vi,
   ViConstString channelName,
   ViInt32 calSource);

// -- Verification --
ViStatus _VI_FUNC niScope_CalMeasureRISDistribution(
   ViSession vi,                    // session handle from CalStart or niScope_init
   ViConstString channelName,       // e.g. "0" or "1"
   ViInt32 maxTime,                 // max time in ms for each acquisition
   ViReal64* minBinPercent,         // percent (0-1) of trigers in the least full bin
   ViInt32 distributionSize,        // number of bins for distribution
   ViInt32* distribution);          // array for distribution, NULL for "do not return it"


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif
#endif /* ___niScopeCal_h___ */