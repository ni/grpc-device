message NIErrStatus {
  int32 code = 1;
  string json = 2;
}

message NIMXLCDevice {
  string name = 1;
  bool supportsOnboardClock = 2;
  repeated NIMXLCTerminal terminals = 3;
}

message NIMXLCTerminal {
  string name = 1;
  string visibility = 2;
}