#ifndef NIFAKE_NON_IVI_H
#define NIFAKE_NON_IVI_H
#include <cstdint>
// For CVIAbsoluteTime
#include "NIDAQmx.h"

const int32 kDriverSuccess = 0;
const int32 kDriverFailure = 1;

using FakeCrossDriverHandle = int32;
using FakeHandle = uint64_t;
using SecondarySessionHandle = int32;
using myInt16 = int16_t;
using myUInt16 = uint16_t;
using myInt8 = int8_t;
using myUInt8 = uint8_t;

struct StructWithCoercion_struct {
  myInt16 first;
  myUInt16 second;
  myInt8 third;
};

using CallbackPtr = int32(myInt16, void*);

#endif /* NIFAKE_NON_IVI_H */
