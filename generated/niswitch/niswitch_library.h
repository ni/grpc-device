//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Real implementation of LibraryInterface for NI-SWITCH
//---------------------------------------------------------------------
#ifndef NISWITCH_GRPC_LIBRARY_H
#define NISWITCH_GRPC_LIBRARY_H

#include "niswitch_library_interface.h"

#include <server/shared_library_interface.h>

#include <memory>

namespace niswitch_grpc {

class NiSwitchLibrary : public niswitch_grpc::NiSwitchLibraryInterface {
 public:
  NiSwitchLibrary();
  explicit NiSwitchLibrary(std::shared_ptr<nidevice_grpc::SharedLibraryInterface> shared_library);
  virtual ~NiSwitchLibrary();

  ::grpc::Status check_function_exists(std::string functionName);
  ViStatus AbortScan(ViSession vi) override;
  ViStatus CanConnect(ViSession vi, ViConstString channel1, ViConstString channel2, ViInt32* pathCapability) override;
  ViStatus CheckAttributeViBoolean(ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean attributeValue) override;
  ViStatus CheckAttributeViInt32(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 attributeValue) override;
  ViStatus CheckAttributeViReal64(ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64 attributeValue) override;
  ViStatus CheckAttributeViSession(ViSession vi, ViConstString channelName, ViAttr attributeId, ViSession attributeValue) override;
  ViStatus CheckAttributeViString(ViSession vi, ViConstString channelName, ViAttr attributeId, ViString attributeValue) override;
  ViStatus ClearError(ViSession vi) override;
  ViStatus ClearInterchangeWarnings(ViSession vi) override;
  ViStatus Close(ViSession vi) override;
  ViStatus Commit(ViSession vi) override;
  ViStatus ConfigureScanList(ViSession vi, ViConstString scanlist, ViInt32 scanMode) override;
  ViStatus ConfigureScanTrigger(ViSession vi, ViReal64 scanDelay, ViInt32 triggerInput, ViInt32 scanAdvancedOutput) override;
  ViStatus Connect(ViSession vi, ViConstString channel1, ViConstString channel2) override;
  ViStatus ConnectMultiple(ViSession vi, ViConstString connectionList) override;
  ViStatus Disable(ViSession vi) override;
  ViStatus Disconnect(ViSession vi, ViConstString channel1, ViConstString channel2) override;
  ViStatus DisconnectAll(ViSession vi) override;
  ViStatus DisconnectMultiple(ViSession vi, ViConstString disconnectionList) override;
  ViStatus ErrorMessage(ViSession vi, ViStatus errorCode, ViChar errorMessage[256]) override;
  ViStatus ErrorQuery(ViSession vi, ViInt32* errorCode, ViChar errorMessage[256]) override;
  ViStatus GetAttributeViBoolean(ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean* attributeValue) override;
  ViStatus GetAttributeViInt32(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32* attributeValue) override;
  ViStatus GetAttributeViReal64(ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64* attributeValue) override;
  ViStatus GetAttributeViSession(ViSession vi, ViConstString channelName, ViAttr attributeId, ViSession* attributeValue) override;
  ViStatus GetAttributeViString(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 arraySize, ViChar attributeValue[]) override;
  ViStatus GetChannelName(ViSession vi, ViInt32 index, ViInt32 bufferSize, ViChar channelNameBuffer[]) override;
  ViStatus GetError(ViSession vi, ViStatus* code, ViInt32 bufferSize, ViChar description[]) override;
  ViStatus GetNextCoercionRecord(ViSession vi, ViInt32 bufferSize, ViChar coercionRecord[]) override;
  ViStatus GetNextInterchangeWarning(ViSession vi, ViInt32 bufferSize, ViChar interchangeWarning[]) override;
  ViStatus GetPath(ViSession vi, ViConstString channel1, ViConstString channel2, ViInt32 bufferSize, ViChar path[]) override;
  ViStatus GetRelayCount(ViSession vi, ViConstString relayName, ViInt32* relayCount) override;
  ViStatus GetRelayName(ViSession vi, ViInt32 index, ViInt32 relayNameBufferSize, ViChar relayNameBuffer[]) override;
  ViStatus GetRelayPosition(ViSession vi, ViConstString relayName, ViInt32* relayPosition) override;
  ViStatus Init(ViRsrc resourceName, ViBoolean idQuery, ViBoolean resetDevice, ViSession* vi) override;
  ViStatus InitWithOptions(ViRsrc resourceName, ViBoolean idQuery, ViBoolean resetDevice, ViConstString optionsString, ViSession* vi) override;
  ViStatus InitWithTopology(ViRsrc resourceName, ViConstString topology, ViBoolean simulate, ViBoolean resetDevice, ViSession* vi) override;
  ViStatus InitiateScan(ViSession vi) override;
  ViStatus InvalidateAllAttributes(ViSession vi) override;
  ViStatus IsDebounced(ViSession vi, ViBoolean* isDebounced) override;
  ViStatus IsScanning(ViSession vi, ViBoolean* isScanning) override;
  ViStatus LockSession(ViSession vi, ViBoolean* callerHasLock) override;
  ViStatus RelayControl(ViSession vi, ViConstString relayName, ViInt32 relayAction) override;
  ViStatus Reset(ViSession vi) override;
  ViStatus ResetInterchangeCheck(ViSession vi) override;
  ViStatus ResetWithDefaults(ViSession vi) override;
  ViStatus RevisionQuery(ViSession vi, ViChar instrumentDriverRevision[256], ViChar firmwareRevision[256]) override;
  ViStatus RouteScanAdvancedOutput(ViSession vi, ViInt32 scanAdvancedOutputConnector, ViInt32 scanAdvancedOutputBusLine, ViBoolean invert) override;
  ViStatus RouteTriggerInput(ViSession vi, ViInt32 triggerInputConnector, ViInt32 triggerInputBusLine, ViBoolean invert) override;
  ViStatus Scan(ViSession vi, ViConstString scanlist, ViInt16 initiation) override;
  ViStatus SelfTest(ViSession vi, ViInt16* selfTestResult, ViChar selfTestMessage[256]) override;
  ViStatus SendSoftwareTrigger(ViSession vi) override;
  ViStatus SetAttributeViBoolean(ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean attributeValue) override;
  ViStatus SetAttributeViInt32(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 attributeValue) override;
  ViStatus SetAttributeViReal64(ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64 attributeValue) override;
  ViStatus SetAttributeViSession(ViSession vi, ViConstString channelName, ViAttr attributeId, ViSession attributeValue) override;
  ViStatus SetAttributeViString(ViSession vi, ViConstString channelName, ViAttr attributeId, ViString attributeValue) override;
  ViStatus SetContinuousScan(ViSession vi, ViBoolean continuousScan) override;
  ViStatus SetPath(ViSession vi, ViConstString pathList) override;
  ViStatus UnlockSession(ViSession vi, ViBoolean* callerHasLock) override;
  ViStatus WaitForDebounce(ViSession vi, ViInt32 maximumTimeMs) override;
  ViStatus WaitForScanComplete(ViSession vi, ViInt32 maximumTimeMs) override;
  ViStatus SetRuntimeEnvironment(ViConstString environment, ViConstString environmentVersion, ViConstString reserved1, ViConstString reserved2) override;
  bool is_runtime_environment_set() const; // needed to test that we properly call SetRuntimeEnvironment

 private:
  using AbortScanPtr = decltype(&niSwitch_AbortScan);
  using CanConnectPtr = decltype(&niSwitch_CanConnect);
  using CheckAttributeViBooleanPtr = decltype(&niSwitch_CheckAttributeViBoolean);
  using CheckAttributeViInt32Ptr = decltype(&niSwitch_CheckAttributeViInt32);
  using CheckAttributeViReal64Ptr = decltype(&niSwitch_CheckAttributeViReal64);
  using CheckAttributeViSessionPtr = decltype(&niSwitch_CheckAttributeViSession);
  using CheckAttributeViStringPtr = decltype(&niSwitch_CheckAttributeViString);
  using ClearErrorPtr = decltype(&niSwitch_ClearError);
  using ClearInterchangeWarningsPtr = decltype(&niSwitch_ClearInterchangeWarnings);
  using ClosePtr = decltype(&niSwitch_close);
  using CommitPtr = decltype(&niSwitch_Commit);
  using ConfigureScanListPtr = decltype(&niSwitch_ConfigureScanList);
  using ConfigureScanTriggerPtr = decltype(&niSwitch_ConfigureScanTrigger);
  using ConnectPtr = decltype(&niSwitch_Connect);
  using ConnectMultiplePtr = decltype(&niSwitch_ConnectMultiple);
  using DisablePtr = decltype(&niSwitch_Disable);
  using DisconnectPtr = decltype(&niSwitch_Disconnect);
  using DisconnectAllPtr = decltype(&niSwitch_DisconnectAll);
  using DisconnectMultiplePtr = decltype(&niSwitch_DisconnectMultiple);
  using ErrorMessagePtr = decltype(&niSwitch_error_message);
  using ErrorQueryPtr = decltype(&niSwitch_error_query);
  using GetAttributeViBooleanPtr = decltype(&niSwitch_GetAttributeViBoolean);
  using GetAttributeViInt32Ptr = decltype(&niSwitch_GetAttributeViInt32);
  using GetAttributeViReal64Ptr = decltype(&niSwitch_GetAttributeViReal64);
  using GetAttributeViSessionPtr = decltype(&niSwitch_GetAttributeViSession);
  using GetAttributeViStringPtr = decltype(&niSwitch_GetAttributeViString);
  using GetChannelNamePtr = decltype(&niSwitch_GetChannelName);
  using GetErrorPtr = decltype(&niSwitch_GetError);
  using GetNextCoercionRecordPtr = decltype(&niSwitch_GetNextCoercionRecord);
  using GetNextInterchangeWarningPtr = decltype(&niSwitch_GetNextInterchangeWarning);
  using GetPathPtr = decltype(&niSwitch_GetPath);
  using GetRelayCountPtr = decltype(&niSwitch_GetRelayCount);
  using GetRelayNamePtr = decltype(&niSwitch_GetRelayName);
  using GetRelayPositionPtr = decltype(&niSwitch_GetRelayPosition);
  using InitPtr = decltype(&niSwitch_init);
  using InitWithOptionsPtr = decltype(&niSwitch_InitWithOptions);
  using InitWithTopologyPtr = decltype(&niSwitch_InitWithTopology);
  using InitiateScanPtr = decltype(&niSwitch_InitiateScan);
  using InvalidateAllAttributesPtr = decltype(&niSwitch_InvalidateAllAttributes);
  using IsDebouncedPtr = decltype(&niSwitch_IsDebounced);
  using IsScanningPtr = decltype(&niSwitch_IsScanning);
  using LockSessionPtr = ViStatus (*)(ViSession vi, ViBoolean* callerHasLock);
  using RelayControlPtr = decltype(&niSwitch_RelayControl);
  using ResetPtr = decltype(&niSwitch_reset);
  using ResetInterchangeCheckPtr = decltype(&niSwitch_ResetInterchangeCheck);
  using ResetWithDefaultsPtr = decltype(&niSwitch_ResetWithDefaults);
  using RevisionQueryPtr = decltype(&niSwitch_revision_query);
  using RouteScanAdvancedOutputPtr = decltype(&niSwitch_RouteScanAdvancedOutput);
  using RouteTriggerInputPtr = decltype(&niSwitch_RouteTriggerInput);
  using ScanPtr = decltype(&niSwitch_Scan);
  using SelfTestPtr = decltype(&niSwitch_self_test);
  using SendSoftwareTriggerPtr = decltype(&niSwitch_SendSoftwareTrigger);
  using SetAttributeViBooleanPtr = decltype(&niSwitch_SetAttributeViBoolean);
  using SetAttributeViInt32Ptr = decltype(&niSwitch_SetAttributeViInt32);
  using SetAttributeViReal64Ptr = decltype(&niSwitch_SetAttributeViReal64);
  using SetAttributeViSessionPtr = decltype(&niSwitch_SetAttributeViSession);
  using SetAttributeViStringPtr = decltype(&niSwitch_SetAttributeViString);
  using SetContinuousScanPtr = decltype(&niSwitch_SetContinuousScan);
  using SetPathPtr = decltype(&niSwitch_SetPath);
  using UnlockSessionPtr = ViStatus (*)(ViSession vi, ViBoolean* callerHasLock);
  using WaitForDebouncePtr = decltype(&niSwitch_WaitForDebounce);
  using WaitForScanCompletePtr = decltype(&niSwitch_WaitForScanComplete);
  using SetRuntimeEnvironmentPtr = ViStatus (*)(ViConstString environment, ViConstString environmentVersion, ViConstString reserved1, ViConstString reserved2);

  typedef struct FunctionPointers {
    AbortScanPtr AbortScan;
    CanConnectPtr CanConnect;
    CheckAttributeViBooleanPtr CheckAttributeViBoolean;
    CheckAttributeViInt32Ptr CheckAttributeViInt32;
    CheckAttributeViReal64Ptr CheckAttributeViReal64;
    CheckAttributeViSessionPtr CheckAttributeViSession;
    CheckAttributeViStringPtr CheckAttributeViString;
    ClearErrorPtr ClearError;
    ClearInterchangeWarningsPtr ClearInterchangeWarnings;
    ClosePtr Close;
    CommitPtr Commit;
    ConfigureScanListPtr ConfigureScanList;
    ConfigureScanTriggerPtr ConfigureScanTrigger;
    ConnectPtr Connect;
    ConnectMultiplePtr ConnectMultiple;
    DisablePtr Disable;
    DisconnectPtr Disconnect;
    DisconnectAllPtr DisconnectAll;
    DisconnectMultiplePtr DisconnectMultiple;
    ErrorMessagePtr ErrorMessage;
    ErrorQueryPtr ErrorQuery;
    GetAttributeViBooleanPtr GetAttributeViBoolean;
    GetAttributeViInt32Ptr GetAttributeViInt32;
    GetAttributeViReal64Ptr GetAttributeViReal64;
    GetAttributeViSessionPtr GetAttributeViSession;
    GetAttributeViStringPtr GetAttributeViString;
    GetChannelNamePtr GetChannelName;
    GetErrorPtr GetError;
    GetNextCoercionRecordPtr GetNextCoercionRecord;
    GetNextInterchangeWarningPtr GetNextInterchangeWarning;
    GetPathPtr GetPath;
    GetRelayCountPtr GetRelayCount;
    GetRelayNamePtr GetRelayName;
    GetRelayPositionPtr GetRelayPosition;
    InitPtr Init;
    InitWithOptionsPtr InitWithOptions;
    InitWithTopologyPtr InitWithTopology;
    InitiateScanPtr InitiateScan;
    InvalidateAllAttributesPtr InvalidateAllAttributes;
    IsDebouncedPtr IsDebounced;
    IsScanningPtr IsScanning;
    LockSessionPtr LockSession;
    RelayControlPtr RelayControl;
    ResetPtr Reset;
    ResetInterchangeCheckPtr ResetInterchangeCheck;
    ResetWithDefaultsPtr ResetWithDefaults;
    RevisionQueryPtr RevisionQuery;
    RouteScanAdvancedOutputPtr RouteScanAdvancedOutput;
    RouteTriggerInputPtr RouteTriggerInput;
    ScanPtr Scan;
    SelfTestPtr SelfTest;
    SendSoftwareTriggerPtr SendSoftwareTrigger;
    SetAttributeViBooleanPtr SetAttributeViBoolean;
    SetAttributeViInt32Ptr SetAttributeViInt32;
    SetAttributeViReal64Ptr SetAttributeViReal64;
    SetAttributeViSessionPtr SetAttributeViSession;
    SetAttributeViStringPtr SetAttributeViString;
    SetContinuousScanPtr SetContinuousScan;
    SetPathPtr SetPath;
    UnlockSessionPtr UnlockSession;
    WaitForDebouncePtr WaitForDebounce;
    WaitForScanCompletePtr WaitForScanComplete;
    SetRuntimeEnvironmentPtr SetRuntimeEnvironment;
  } FunctionLoadStatus;

  std::shared_ptr<nidevice_grpc::SharedLibraryInterface> shared_library_;
  FunctionPointers function_pointers_;
  bool runtime_environment_set_; // needed to test that we properly call SetRuntimeEnvironment
};

}  // namespace niswitch_grpc

#endif  // NISWITCH_GRPC_LIBRARY_H
