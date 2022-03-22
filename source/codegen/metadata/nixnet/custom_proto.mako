message FlexRayStats {
  uint32 num_syntax_error_ch_a = 1;
  uint32 num_syntax_error_ch_b = 2;
  uint32 num_content_error_ch_a = 3;
  uint32 num_content_error_ch_b = 4;
  uint32 num_slot_boundary_violation_ch_a = 5;
  uint32 num_slot_boundary_violation_ch_b = 6;
}

message J1939CommState{
  uint32 pgn = 1;
  uint32 source_address = 2;
  uint32 destination_address = 3;
  uint32 transmit_error = 4;
  uint32 receive_error = 5;
}

message CanComm{
  uint32 comm_state = 1;
  uint32 transceiver_error = 2;
  uint32 sleep = 3;
  uint32 last_error = 4;
  uint32 transmit_error_counter = 5;
  uint32 receive_error_counter = 6;
}

message FlexRayComm{
  uint32 poc_state = 1;
  uint32 clock_correction_failed = 2;
  uint32 passive_to_active_count = 3;
  uint32 channel_a_sleep = 4;
  uint32 channel_b_sleep = 5;
}

message LinComm{
  uint32 sleep = 1;
  uint32 comm_state = 2;
  uint32 last_error = 3;
  uint32 last_error_received = 4;
  uint32 last_error_expected = 5;
  uint32 last_error_id = 6;
  uint32 transceiver_ready = 7;
  uint32 schedule_index = 8;
}

message ReadStateValue {
  oneof value{
    uint64 time_current = 1;
    uint64 time_communicating = 2;
    uint64 time_start = 3;
    CanComm can_comm = 4;
    FlexRayComm flex_ray_comm = 5;
    FlexRayStats flex_ray_stats = 6;
    LinComm lin_comm = 7;
    uint32 session_info = 8;
    J1939CommState j1939_comm_state = 9;
    TimeLocalNetwork time_current2 = 10;
    TimeLocalNetwork time_communicating2 = 11;
    TimeLocalNetwork time_start2 = 12;
  }
  bytes state_value_raw = 13;
}

message WriteStateValue {
  oneof value{
    uint32 lin_schedule_change = 1;
    uint32 flex_ray_symbol = 2;
    uint32 lin_diagnostic_schedule_change = 3;
    uint32 ethernet_sleep = 4;
    uint32 ethernet_wake = 5;
  }
}

message U32Array {
  repeated uint32 u32_array = 1;
}

message DbRefArray {
  repeated nidevice_grpc.Session db_ref = 1;
}

message EptRxFilter {
  uint32 use_flags = 1;
  uint32 vid = 2;
  uint32 priority = 3;
  string destination_mac = 4;    
}

message EptRxFilterArray {
  repeated EptRxFilter ept_rx_filter = 1;
}

message GetPropertyRequest {
  nidevice_grpc.Session session_ref = 1;
  oneof property_id_enum {
    Property property_id = 2;
    uint32 property_id_raw = 3;
  }
} 

message GetPropertyResponse {
  int32 status = 1;
  oneof property_value {
    uint32 u32_scalar = 2;
    bool bool_scalar = 3;
    string str = 4;
    uint64 u64_scalar = 5;
    int32 i32_scalar = 6;
    double f64_scalar = 7;
    string string_array = 8;
    U32Array u32_array = 9;
    nidevice_grpc.Session db_ref = 10;
    DbRefArray db_ref_array = 11;
    EptRxFilterArray ept_rx_filter_array = 12;
  }
}

message SetPropertyRequest {
  nidevice_grpc.Session session_ref = 1;
  oneof property_id_enum {
    Property property_id = 2;
    uint32 property_id_raw = 3;
  }
  oneof property_value {
    uint32 u32_scalar = 4;
    bool bool_scalar = 5;
    string str = 6;
    uint64 u64_scalar = 7;
    int32 i32_scalar = 8;
    double f64_scalar = 9;
    string string_array = 10;
    U32Array u32_array = 11;
    nidevice_grpc.Session db_ref = 12;
    DbRefArray db_ref_array = 13;
    EptRxFilterArray ept_rx_filter_array = 14;
  }
}

message SetPropertyResponse {
  int32 status = 1;
}

message GetSubPropertyRequest {
  nidevice_grpc.Session session_ref = 1;
  uint32 active_index = 2;
  oneof subproperty_id_enum {
    SubProperty property_id = 3;
    uint32 property_id_raw = 4;
  }
}

message GetSubPropertyResponse {
  int32 status = 1;
  oneof property_value {
    uint32 u32_scalar = 2;
    string str = 3;
    double f64_scalar = 9;
  }
}

message DbGetPropertyRequest {
  nidevice_grpc.Session dbobject_ref = 1;
  oneof dbproperty_id_enum {
    DBProperty property_id = 2;
    uint32 property_id_raw = 3;
  }
}

message DbGetPropertyResponse {
  int32 status = 1;
  oneof property_value {
    uint32 u32_scalar = 2;
    bool bool_scalar = 3;
    string str = 4;
    uint64 u64_scalar = 5;
    double f64_scalar = 6;
    U32Array u32_array = 7;
    bytes u8_array = 8;
    nidevice_grpc.Session db_ref = 9;
    DbRefArray db_ref_array = 10;
  }
}

message SetSubPropertyRequest {
  nidevice_grpc.Session session_ref = 1;
  uint32 active_index = 2;
  oneof subproperty_id_enum {
    SubProperty property_id = 3;
    uint32 property_id_raw = 4;
  }
  oneof property_value {
    uint32 u32_scalar = 5;
    string str = 6;
    double f64_scalar = 7;
  }
}

message SetSubPropertyResponse {
  int32 status = 1;
}

message DbSetPropertyRequest {
  nidevice_grpc.Session dbobject_ref = 1;
  oneof dbproperty_id_enum {
    DBProperty property_id = 2;
    uint32 property_id_raw = 3;
  }
  oneof property_value {
    uint32 u32_scalar = 4;
    bool bool_scalar = 5;
    string str = 6;
    uint64 u64_scalar = 7;
    double f64_scalar = 8;
    U32Array u32_array = 9;
    bytes u8_array = 10;
    nidevice_grpc.Session db_ref = 11;
    DbRefArray db_ref_array = 12;
  }
}

message DbSetPropertyResponse {
  int32 status = 1;
}

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
