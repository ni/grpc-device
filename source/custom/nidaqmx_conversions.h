#ifndef NIDAQMX_CONVERSIONS
#define NIDAQMX_CONVERSIONS

// Needed for the definition of CVIAbsoluteTime
#include <google/protobuf/util/time_util.h>
#include <nidaqmx/nidaqmx_library_interface.h>

#include "NIDAQmx.h"
#include "nidaqmx.pb.h"

template <typename CType, typename GrpcType>
inline void convert_to_grpc(const CType& value, GrpcType* value_out)
{
  *value_out = static_cast<GrpcType>(value);
}

template <typename CType, typename GrpcType>
inline CType convert_from_grpc(const GrpcType& value)
{
  return static_cast<CType>(value);
}

const int64 SecondsFromCVI1904EpochTo1970Epoch = 2082844800LL;
const double TwoToSixtyFour = (double)(1 << 31) * (double)(1 << 31) * (double)(1 << 2);
const double NanosecondsPerSecond = 1000000000.0;

template <>
inline void convert_to_grpc(const CVIAbsoluteTime& value, google::protobuf::Timestamp* timestamp)
{
  // msb is whole seconds after 12:00 a.m., Friday, January 1, 1904, Universal Time
  time_t unixTime = static_cast<time_t>(value.cviTime.msb - SecondsFromCVI1904EpochTo1970Epoch);
  google::protobuf::Timestamp temp_timestamp = google::protobuf::util::TimeUtil::TimeTToTimestamp(unixTime);

  timestamp->set_seconds(temp_timestamp.seconds());
  // lsb is positive fractions (2^64) of a second
  // This is losing some precision since doubles have 52 bits of precision.
  // But there are only 10^9 nanoseconds in a second which is ~31 bits of precision,
  // so it's still good enough for our purposes.
  timestamp->set_nanos(static_cast<int32>((static_cast<double>(value.cviTime.lsb) * NanosecondsPerSecond) / TwoToSixtyFour));
}

template <>
inline CVIAbsoluteTime convert_from_grpc(const google::protobuf::Timestamp& value)
{
  time_t unixTime = google::protobuf::util::TimeUtil::TimestampToTimeT(value);
  CVIAbsoluteTime cviTime;
  cviTime.cviTime.msb = static_cast<int64>(unixTime + SecondsFromCVI1904EpochTo1970Epoch);
  cviTime.cviTime.lsb = static_cast<uInt64>((static_cast<double>(value.nanos()) / NanosecondsPerSecond) * TwoToSixtyFour);
  return cviTime;
}

namespace {
void throw_if_failure(int32 status)
{
  if (status) {
    throw nidevice_grpc::FailedStatusException(status);
  }
}
}  // namespace

inline uInt32 get_number_of_channels(nidaqmx_grpc::NiDAQmxLibraryInterface* library, TaskHandle& task)
{
  uInt32 number_of_channels;
  throw_if_failure(library->GetReadAttributeUInt32(task, nidaqmx_grpc::READ_ATTRIBUTE_NUM_CHANS, &number_of_channels, 0));
  return number_of_channels;
}

inline int32 calculate_num_samps_per_chan(nidaqmx_grpc::NiDAQmxLibraryInterface* library, TaskHandle& task, int32 num_samps_per_chan)
{
  if (num_samps_per_chan == 0) {
    // TODO - the Python API uses a sentinel value to indicate acquire only one sample
    // and return a 1D array instead of a 2D array. Since that doesn't make a difference here,
    // we could use 0 (i.e. unset) to mean something different...
    return 1;
  }
  else if (num_samps_per_chan == -1) {
    // READ_ALL_AVAILABLE
    int32 acquisition_type;
    throw_if_failure(library->GetTimingAttributeInt32(task, nidaqmx_grpc::TIMING_ATTRIBUTE_SAMP_QUANT_SAMP_MODE, &acquisition_type, 0));
    bool is_finite_read_all_available_samples = false;
    if (acquisition_type == DAQmx_Val_FiniteSamps) {
      // check read_all_avail_samp
      bool32 read_all_available_samples;
      throw_if_failure(library->GetReadAttributeBool(task, nidaqmx_grpc::READ_ATTRIBUTE_READ_ALL_AVAIL_SAMP, &read_all_available_samples, 0));
      is_finite_read_all_available_samples = read_all_available_samples != 0;
    }
    if (is_finite_read_all_available_samples) {
      uInt64 read_samples_per_channel;
      // TODO - this is actually a timing attribute, but the attribute metadata is wrong so there's
      // no way to read a Timing UInt64 property.
      // See GitHub issue #324
      throw_if_failure(library->GetReadAttributeUInt64(task, nidaqmx_grpc::TIMING_ATTRIBUTE_SAMP_QUANT_SAMP_PER_CHAN, &read_samples_per_channel, 0));
      return static_cast<int32>(read_samples_per_channel);
    }
    else {
      uInt32 samples_per_channel;
      throw_if_failure(library->GetReadAttributeUInt32(task, nidaqmx_grpc::READ_ATTRIBUTE_AVAIL_SAMP_PER_CHAN, &samples_per_channel, 0));
      return static_cast<int32>(samples_per_channel);
    }
  }
  else {
    return num_samps_per_chan;
  }
}

inline uInt32 calculate_array_size_in_samps(nidaqmx_grpc::NiDAQmxLibraryInterface* library, TaskHandle& task)
{
}

#endif  // NIDAQMX_CONVERSIONS