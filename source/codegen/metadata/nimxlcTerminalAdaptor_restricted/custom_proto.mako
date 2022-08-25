message NIErrStatus {
  int32 code = 1;
  uint32 capacity = 2;
  string json = 3;
}

message NIMXLCDevice {
  string name = 1;
  bool supportsOnboardClock = 2;
  repeated NIMXLCTerminal terminals= 3;
}

message NIMXLCTerminal {
  string name = 1;
  string visibility = 2;
}