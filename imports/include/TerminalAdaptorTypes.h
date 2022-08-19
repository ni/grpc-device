#ifndef NIMXLC_TERMINALADAPTORTYPES_H_
#define NIMXLC_TERMINALADAPTORTYPES_H_

#include <stdint.h>
#include <nierr_Status.h>

/*
  This macro defines opaque handle types that have a little more type-safety
  than void pointers.  These will always be reinterpret_cast'd to the actual
  type internally.

  Although these opaque types are implemented using a pointer, NULL may be a
  valid value.
 */
#define NIMXLCAPI_DEFINE_OPAQUE_TYPE(name) \
   struct undefined_ ## name; \
   typedef struct undefined_ ## name* name

/** A handle to a Routing Adaptor session */
NIMXLCAPI_DEFINE_OPAQUE_TYPE(nimxlc_Session);

/** A handle to a container with a list of devices */
NIMXLCAPI_DEFINE_OPAQUE_TYPE(nimxlc_DeviceContainer);

/** A handle to an iterator for a nimxlc_DeviceContainer */
NIMXLCAPI_DEFINE_OPAQUE_TYPE(nimxlc_DeviceIterator);

/** A handle to a container with a list of terminals */
NIMXLCAPI_DEFINE_OPAQUE_TYPE(nimxlc_TerminalContainer);

/** A handle to an iterator for a nimxlc_TerminalContainer */
NIMXLCAPI_DEFINE_OPAQUE_TYPE(nimxlc_TerminalIterator);

#define NIMXLC_DEFINE_OPAQUE_TYPE_ACCESSOR_FNS(newFnName, fromFnName, opaqueTypeName, actualPtrType) \
   static opaqueTypeName newFnName(actualPtrType* ptr = NULL) \
   {                                                          \
      return reinterpret_cast<opaqueTypeName>(ptr);           \
   }                                                          \
   static actualPtrType* fromFnName(opaqueTypeName opaque)    \
   {                                                          \
      return reinterpret_cast<actualPtrType*>(opaque);        \
   }

#define NIMXLC_DEFINE_OPAQUE_INDEX_ACCESSOR_FNS(newFnName, fromFnName, opaqueTypeName) \
   static opaqueTypeName newFnName(size_t index = 0)     \
   {                                                     \
      return reinterpret_cast<opaqueTypeName>(index);    \
   }                                                     \
   static size_t fromFnName(opaqueTypeName opaque)       \
   {                                                     \
      return reinterpret_cast<size_t>(opaque);           \
   }

#endif
