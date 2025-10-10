enum WaveformAttributeMode {
  WAVEFORM_ATTRIBUTE_MODE_NONE = 0;
  WAVEFORM_ATTRIBUTE_MODE_TIMING = 1;
  WAVEFORM_ATTRIBUTE_MODE_EXTENDED_PROPERTIES = 2;
}

message AnalogWaveform {
  repeated double samples = 1;
  google.protobuf.Timestamp t0 = 2;
  double dt = 3;
  repeated string channel_names = 4;
  uint32 samples_per_channel = 5;
  uint32 number_of_channels = 6;
}