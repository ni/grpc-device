message FlexRayStats {
  uint32 num_syntax_error_ch_a = 1;
  uint32 num_syntax_error_ch_b = 2;
  uint32 num_content_error_ch_a = 3;
  uint32 num_content_error_ch_b = 4;
  uint32 num_slot_boundary_violation_ch_a = 5;
  uint32 num_slot_boundary_violation_ch_b = 6;
}

message J1939CommState {
  uint32 pgn = 1;
  uint32 source_address = 2;
  uint32 destination_address = 3;
  uint32 transmit_error = 4;
  uint32 receive_error = 5;
}

message CanCommResponse {
  CanCommState comm_state = 1;
  uint32 comm_state_raw = 2;
  uint32 transceiver_error = 3;
  uint32 sleep = 4;
  CanLastErr last_error = 5;
  uint32 last_error_raw = 6;
  uint32 transmit_error_counter = 7;
  uint32 receive_error_counter = 8;
}

message FlexRayCommResponse {
  FlexRayPocState poc_state = 1;
  uint32 poc_state_raw = 2;
  uint32 clock_correction_failed = 3;
  uint32 passive_to_active_count = 4;
  uint32 channel_a_sleep = 5;
  uint32 channel_b_sleep = 6;
}

message LinCommResponse {
  uint32 sleep = 1;
  LinCommState comm_state = 2;
  uint32 comm_state_raw = 3;
  uint32 last_error = 4;
  uint32 last_error_received = 5;
  uint32 last_error_expected = 6;
  uint32 last_error_id = 7;
  uint32 transceiver_ready = 8;
  uint32 schedule_index = 9;
}

message SessionInfoResponse {
  SessionInfoState info = 1;
  uint32 info_raw = 2;
}

message ReadStateValue {
  oneof value {
    uint64 time_current = 1;
    uint64 time_communicating = 2;
    uint64 time_start = 3;
    CanCommResponse can_comm = 4;
    FlexRayCommResponse flex_ray_comm = 5;
    FlexRayStats flex_ray_stats = 6;
    LinCommResponse lin_comm = 7;
    SessionInfoResponse session_info = 8;
    J1939CommState j1939_comm_state = 9;
    TimeLocalNetwork time_current2 = 10;
    TimeLocalNetwork time_communicating2 = 11;
    TimeLocalNetwork time_start2 = 12;
  }
  bytes state_value_raw = 13;
}

message LinDiagnosticScheduleChangeRequest {
  oneof schedule_enum {
    LinDiagnosticSchedule schedule = 1;
    uint32 schedule_raw = 2;
  }
}

message WriteStateValue {
  oneof value {
    uint32 lin_schedule_change = 1;
    uint32 flex_ray_symbol = 2;
    LinDiagnosticScheduleChangeRequest lin_diagnostic_schedule_change = 3;
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

message DeviceRefArray {
  repeated nidevice_grpc.Session dev_ref = 1;
}

message InterfaceRefArray {
  repeated nidevice_grpc.Session intf_ref = 1;
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
  oneof session_repository {
    nidevice_grpc.Session device = 1;
    nidevice_grpc.Session interface_ref = 2;
    nidevice_grpc.Session session = 3;
  }
  oneof property_id_enum {
    Property property_id = 4;
    uint32 property_id_raw = 5;
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
    nidevice_grpc.Session dev_ref = 12;
    DeviceRefArray dev_ref_array = 13;
    InterfaceRefArray intf_ref_array = 14;
    EptRxFilterArray ept_rx_filter_array = 15;
  }
}

message SetPropertyRequest {
  nidevice_grpc.Session session = 1;
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
  nidevice_grpc.Session session = 1;
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
  nidevice_grpc.Session dbobject = 1;
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
  nidevice_grpc.Session session = 1;
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
  nidevice_grpc.Session dbobject = 1;
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

message FrameRequest {
  uint64 timestamp = 1;
  uint32 identifier = 2;
  oneof type_enum{
     FrameType type = 3;
     uint32 type_raw = 4;
  }
  repeated FrameFlags flags = 5;
  uint32 info = 6;
  bytes payload = 7;
}

message FrameResponse {
  uint64 timestamp = 1;
  uint32 identifier = 2;
  FrameType type = 3;
  uint32 type_raw = 4;
  repeated FrameFlags flags = 5;
  uint32 flags_raw = 6;
  uint32 info = 7;
  bytes payload = 8;
}

message EnetFrameRequest {
  oneof type_enum{
    EnetFrameType type = 1;
    uint32 type_raw = 2;
  }
  uint64 device_timestamp = 3;
  uint64 network_timestamp = 4;
  repeated EnetFlags flags_mapped = 5;
  bytes frame_data = 6;
}

message EnetFrameResponse {
  EnetFrameType type = 1;
  uint32 type_raw = 2;
  uint64 device_timestamp = 3;
  uint64 network_timestamp = 4;
  repeated EnetFlags flags_mapped= 5;
  uint32 flags_raw = 6;
  bytes frame_data = 7;
}

message FrameBufferRequest {
  oneof frame {
    FrameRequest can = 1;
    FrameRequest lin = 2;
    FrameRequest flex_ray = 3;
    FrameRequest j1939 = 4;
    EnetFrameRequest enet = 5;
  }
}

message FrameBufferResponse {
  oneof frame {
    FrameResponse can = 1;
    FrameResponse lin = 2;
    FrameResponse flex_ray = 3;
    FrameResponse j1939 = 4;
    EnetFrameResponse enet = 5;
  }
}