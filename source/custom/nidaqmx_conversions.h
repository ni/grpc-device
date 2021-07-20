// Needed for the definition of CVIAbsoluteTime
#include <google/protobuf/util/time_util.h>

#include "NIDAQmx.h"

template <typename CType, typename GrpcType>
GrpcType convert_to_grpc(const CType& value)
{
  return static_cast<GrpcType>(value);
}

template <typename CType, typename GrpcType>
CType convert_from_grpc(const GrpcType& value)
{
  return static_cast<CType>(value);
}

const int64 SecondsFromCVI1900EpochTo1970Epoch = 2208988800LL;

template <>
google::protobuf::Timestamp convert_to_grpc(const CVIAbsoluteTime& value)
{
  // msb is whole seconds after 12:00 a.m., Friday, January 1, 1904, Universal Time
  time_t unixTime = (time_t)(value.cviTime.msb - SecondsFromCVI1900EpochTo1970Epoch);
  google::protobuf::Timestamp timestamp = google::protobuf::util::TimeUtil::TimeTToTimestamp(unixTime);

  //TODO
  return timestamp;
}

template <>
CVIAbsoluteTime convert_from_grpc(const google::protobuf::Timestamp& value)
{
  time_t unixTime = google::protobuf::util::TimeUtil::TimestampToTimeT(value);
  CVIAbsoluteTime cviTime;
  cviTime.cviTime.msb = (int64)(unixTime + SecondsFromCVI1900EpochTo1970Epoch);
  //TODO
  return cviTime;
}