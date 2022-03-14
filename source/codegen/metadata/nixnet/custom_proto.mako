message Frame {
  uint64 timestamp = 1;
  uint32 identifier = 2;
  uint32 type = 3;
  uint32 flags = 4;
  uint32 info = 5;
  bytes payload = 6;
}

message EnetFrame {
  uint32 type = 1;
  uint64 device_timestamp = 2;
  uint64 network_timestamp = 3;
  uint32 flags = 4;
  bytes frame_data = 5;
}

message FrameBuffer {
  oneof frame {
    Frame can = 1;
    Frame lin = 2;
    Frame flex_ray = 3;
    Frame j1939 = 4;
    EnetFrame enet = 5;
  }
}
