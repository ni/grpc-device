message Frame {
  uint64 timestamp = 1;
  uint32 identifier = 2;
  uint32 type = 3;
  uint32 flags = 4;
  uint32 info = 5;
  uint32 payload_length = 6;
  bytes payload = 7;
}

message EnetFrame {
  uint32 length = 1;
  uint32 type = 2;
  uint64 device_timestamp = 3;
  uint64 network_timestamp = 4;
  uint32 flags = 5;
  bytes frame_data = 6;
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

message ConvertByteArrayToFramesSinglePointRequest {
  nidevice_grpc.Session session_ref = 1;
  bytes value_buffer = 2;
  uint32 size_of_buffer = 3;
  FrameType frame_type = 4;
}

message ConvertByteArrayToFramesSinglePointResponse {
  int32 status = 1;
  repeated FrameBuffer frame_buffer = 2;
}

message ConvertSignalsToFramesSinglePointRequest {
  nidevice_grpc.Session session_ref = 1;
  repeated double value_buffer = 2;
  uint32 size_of_buffer = 3;
  FrameType frame_type = 4;
}

message ConvertSignalsToFramesSinglePointResponse {
  int32 status = 1;
  repeated FrameBuffer frame_buffer = 2;
}

enum FrameType {
  FRAME_TYPE_UNSPECIFIED = 0;
  FRAME_TYPE_CAN = 1;
  FRAME_TYPE_LIN = 2;
  FRAME_TYPE_FLEX_RAY = 3;
  FRAME_TYPE_J1939 = 4;
  FRAME_TYPE_ENET = 5;
}
