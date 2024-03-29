//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Mock of LibraryInterface for NI-SYNC
//---------------------------------------------------------------------
#ifndef NISYNC_GRPC_MOCK_LIBRARY_H
#define NISYNC_GRPC_MOCK_LIBRARY_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "nisync_library_interface.h"

namespace ni {
namespace tests {
namespace unit {

class NiSyncMockLibrary : public nisync_grpc::NiSyncLibraryInterface {
 public:
  MOCK_METHOD(ViStatus, Init, (ViRsrc resourceName, ViBoolean idQuery, ViBoolean resetDevice, ViSession* vi), (override));
  MOCK_METHOD(ViStatus, Close, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, ErrorMessage, (ViSession vi, ViStatus errorCode, ViChar errorMessage[256]), (override));
  MOCK_METHOD(ViStatus, Reset, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, PersistConfig, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, SelfTest, (ViSession vi, ViInt16* selfTestResult, ViChar selfTestMessage[256]), (override));
  MOCK_METHOD(ViStatus, RevisionQuery, (ViSession vi, ViChar driverRevision[256], ViChar firmwareRevision[256]), (override));
  MOCK_METHOD(ViStatus, ConnectTrigTerminals, (ViSession vi, ViConstString srcTerminal, ViConstString destTerminal, ViConstString syncClock, ViInt32 invert, ViInt32 updateEdge), (override));
  MOCK_METHOD(ViStatus, DisconnectTrigTerminals, (ViSession vi, ViConstString srcTerminal, ViConstString destTerminal), (override));
  MOCK_METHOD(ViStatus, ConnectSWTrigToTerminal, (ViSession vi, ViConstString srcTerminal, ViConstString destTerminal, ViConstString syncClock, ViInt32 invert, ViInt32 updateEdge, ViReal64 delay), (override));
  MOCK_METHOD(ViStatus, DisconnectSWTrigFromTerminal, (ViSession vi, ViConstString srcTerminal, ViConstString destTerminal), (override));
  MOCK_METHOD(ViStatus, SendSoftwareTrigger, (ViSession vi, ViConstString srcTerminal), (override));
  MOCK_METHOD(ViStatus, ConnectClkTerminals, (ViSession vi, ViConstString srcTerminal, ViConstString destTerminal), (override));
  MOCK_METHOD(ViStatus, DisconnectClkTerminals, (ViSession vi, ViConstString srcTerminal, ViConstString destTerminal), (override));
  MOCK_METHOD(ViStatus, MeasureFrequency, (ViSession vi, ViConstString srcTerminal, ViReal64 duration, ViReal64* actualDuration, ViReal64* frequency, ViReal64* error), (override));
  MOCK_METHOD(ViStatus, MeasureFrequencyEx, (ViSession vi, ViConstString srcTerminal, ViReal64 duration, ViUInt32 decimationCount, ViReal64* actualDuration, ViReal64* frequency, ViReal64* frequencyError), (override));
  MOCK_METHOD(ViStatus, Start1588, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, Stop1588, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, Start8021AS, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, Stop8021AS, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, SetTime, (ViSession vi, ViInt32 timeSource, ViUInt32 timeSeconds, ViUInt32 timeNanoseconds, ViUInt16 timeFractionalNanoseconds), (override));
  MOCK_METHOD(ViStatus, GetTime, (ViSession vi, ViUInt32* timeSeconds, ViUInt32* timeNanoseconds, ViUInt16* timeFractionalNanoseconds), (override));
  MOCK_METHOD(ViStatus, ResetFrequency, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, CreateFutureTimeEvent, (ViSession vi, ViConstString terminal, ViInt32 outputLevel, ViUInt32 timeSeconds, ViUInt32 timeNanoseconds, ViUInt16 timeFractionalNanoseconds), (override));
  MOCK_METHOD(ViStatus, ClearFutureTimeEvents, (ViSession vi, ViConstString terminal), (override));
  MOCK_METHOD(ViStatus, EnableTimeStampTrigger, (ViSession vi, ViConstString terminal, ViInt32 activeEdge), (override));
  MOCK_METHOD(ViStatus, EnableTimeStampTriggerWithDecimation, (ViSession vi, ViConstString terminal, ViInt32 activeEdge, ViUInt32 decimationCount), (override));
  MOCK_METHOD(ViStatus, ReadTriggerTimeStamp, (ViSession vi, ViConstString terminal, ViReal64 timeout, ViUInt32* timeSeconds, ViUInt32* timeNanoseconds, ViUInt16* timeFractionalNanoseconds, ViInt32* detectedEdge), (override));
  MOCK_METHOD(ViStatus, ReadMultipleTriggerTimeStamp, (ViSession vi, ViConstString terminal, ViUInt32 timestampsToRead, ViReal64 timeout, ViUInt32 timeSecondsBuffer[], ViUInt32 timeNanosecondsBuffer[], ViUInt16 timeFractionalNanosecondsBuffer[], ViInt32 detectedEdgeBuffer[], ViUInt32* timestampsRead), (override));
  MOCK_METHOD(ViStatus, DisableTimeStampTrigger, (ViSession vi, ViConstString terminal), (override));
  MOCK_METHOD(ViStatus, CreateClock, (ViSession vi, ViConstString terminal, ViUInt32 highTicks, ViUInt32 lowTicks, ViUInt32 startTimeSeconds, ViUInt32 startTimeNanoseconds, ViUInt16 startTimeFractionalNanoseconds, ViUInt32 stopTimeSeconds, ViUInt32 stopTimeNanoseconds, ViUInt16 stopTimeFractionalNanoseconds), (override));
  MOCK_METHOD(ViStatus, ClearClock, (ViSession vi, ViConstString terminal), (override));
  MOCK_METHOD(ViStatus, SetTimeReferenceFreeRunning, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, SetTimeReferenceGPS, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, SetTimeReferenceIRIG, (ViSession vi, ViInt32 irigType, ViConstString terminalName), (override));
  MOCK_METHOD(ViStatus, SetTimeReferencePPS, (ViSession vi, ViConstString terminalName, ViBoolean useManualTime, ViUInt32 initialTimeSeconds, ViUInt32 initialTimeNanoseconds, ViUInt16 initialTimeFractionalNanoseconds), (override));
  MOCK_METHOD(ViStatus, SetTimeReference1588OrdinaryClock, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, SetTimeReference8021AS, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, EnableGPSTimestamping, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, EnableIRIGTimestamping, (ViSession vi, ViInt32 irigType, ViConstString terminalName), (override));
  MOCK_METHOD(ViStatus, ReadLastGPSTimestamp, (ViSession vi, ViUInt32* timestampSeconds, ViUInt32* timestampNanoseconds, ViUInt16* timestampFractionalNanoseconds, ViUInt32* gpsSeconds, ViUInt32* gpsNanoseconds, ViUInt16* gpsFractionalNanoseconds), (override));
  MOCK_METHOD(ViStatus, ReadLastIRIGTimestamp, (ViSession vi, ViConstString terminal, ViUInt32* timestampSeconds, ViUInt32* timestampNanoseconds, ViUInt16* timestampFractionalNanoseconds, ViUInt32* irigbSeconds, ViUInt32* irigbNanoseconds, ViUInt16* irigbFractionalNanoseconds), (override));
  MOCK_METHOD(ViStatus, DisableGPSTimestamping, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, DisableIRIGTimestamping, (ViSession vi, ViConstString terminalName), (override));
  MOCK_METHOD(ViStatus, GetVelocity, (ViSession vi, ViReal64* eastVelocity, ViReal64* northVelocity, ViReal64* upVelocity), (override));
  MOCK_METHOD(ViStatus, GetLocation, (ViSession vi, ViReal64* latitude, ViReal64* longitude, ViReal64* altitude), (override));
  MOCK_METHOD(ViStatus, GetTimeReferenceNames, (ViSession vi, ViUInt32 bufferSize, ViChar timeReferenceNames[]), (override));
  MOCK_METHOD(ViStatus, GetAttributeViInt32, (ViSession vi, ViConstString activeItem, ViAttr attribute, ViInt32* value), (override));
  MOCK_METHOD(ViStatus, GetAttributeViReal64, (ViSession vi, ViConstString activeItem, ViAttr attribute, ViReal64* value), (override));
  MOCK_METHOD(ViStatus, GetAttributeViBoolean, (ViSession vi, ViConstString activeItem, ViAttr attribute, ViBoolean* value), (override));
  MOCK_METHOD(ViStatus, GetAttributeViString, (ViSession vi, ViConstString activeItem, ViAttr attribute, ViInt32 bufferSize, ViChar value[]), (override));
  MOCK_METHOD(ViStatus, SetAttributeViInt32, (ViSession vi, ViConstString activeItem, ViAttr attribute, ViInt32 value), (override));
  MOCK_METHOD(ViStatus, SetAttributeViReal64, (ViSession vi, ViConstString activeItem, ViAttr attribute, ViReal64 value), (override));
  MOCK_METHOD(ViStatus, SetAttributeViBoolean, (ViSession vi, ViConstString activeItem, ViAttr attribute, ViBoolean value), (override));
  MOCK_METHOD(ViStatus, SetAttributeViString, (ViSession vi, ViConstString activeItem, ViAttr attribute, ViConstString value), (override));
  MOCK_METHOD(ViStatus, GetExtCalLastDateAndTime, (ViSession vi, ViInt32* year, ViInt32* month, ViInt32* day, ViInt32* hour, ViInt32* minute), (override));
  MOCK_METHOD(ViStatus, GetExtCalLastTemp, (ViSession vi, ViReal64* temp), (override));
  MOCK_METHOD(ViStatus, GetExtCalRecommendedInterval, (ViSession vi, ViInt32* months), (override));
  MOCK_METHOD(ViStatus, ChangeExtCalPassword, (ViSession vi, ViConstString oldPassword, ViConstString newPassword), (override));
  MOCK_METHOD(ViStatus, ReadCurrentTemperature, (ViSession vi, ViReal64* temperature), (override));
  MOCK_METHOD(ViStatus, CalGetOscillatorVoltage, (ViSession vi, ViReal64* voltage), (override));
  MOCK_METHOD(ViStatus, CalGetClk10PhaseVoltage, (ViSession vi, ViReal64* voltage), (override));
  MOCK_METHOD(ViStatus, CalGetDDSStartPulsePhaseVoltage, (ViSession vi, ViReal64* voltage), (override));
  MOCK_METHOD(ViStatus, CalGetDDSInitialPhase, (ViSession vi, ViReal64* phase), (override));
  MOCK_METHOD(ViStatus, InitExtCal, (ViRsrc resourceName, ViConstString password, ViSession* vi), (override));
  MOCK_METHOD(ViStatus, CloseExtCal, (ViSession vi, ViInt32 action), (override));
  MOCK_METHOD(ViStatus, CalAdjustOscillatorVoltage, (ViSession vi, ViReal64 measuredVoltage, ViReal64* oldVoltage), (override));
  MOCK_METHOD(ViStatus, CalAdjustClk10PhaseVoltage, (ViSession vi, ViReal64 measuredVoltage, ViReal64* oldVoltage), (override));
  MOCK_METHOD(ViStatus, CalAdjustDDSStartPulsePhaseVoltage, (ViSession vi, ViReal64 measuredVoltage, ViReal64* oldVoltage), (override));
  MOCK_METHOD(ViStatus, CalAdjustDDSInitialPhase, (ViSession vi, ViReal64 measuredPhase, ViReal64* oldPhase), (override));
};

}  // namespace unit
}  // namespace tests
}  // namespace ni
#endif  // NISYNC_GRPC_MOCK_LIBRARY_H
