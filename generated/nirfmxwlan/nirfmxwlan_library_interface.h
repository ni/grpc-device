//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Library wrapper for implementing interactions with NI-RFMXWLAN
//---------------------------------------------------------------------
#ifndef NIRFMXWLAN_GRPC_LIBRARY_WRAPPER_H
#define NIRFMXWLAN_GRPC_LIBRARY_WRAPPER_H

#include <grpcpp/grpcpp.h>
#include <niRFmxWLAN.h>

namespace nirfmxwlan_grpc {

class NiRFmxWLANLibraryInterface {
 public:
  virtual ~NiRFmxWLANLibraryInterface() {}

  virtual int32 Close(niRFmxInstrHandle instrumentHandle, int32 forceDestroy) = 0;
  virtual int32 Initialize(char resourceName[], char optionString[], niRFmxInstrHandle* handleOut, int32* isNewSession) = 0;
};

}  // namespace nirfmxwlan_grpc
#endif  // NIRFMXWLAN_GRPC_LIBRARY_WRAPPER_H