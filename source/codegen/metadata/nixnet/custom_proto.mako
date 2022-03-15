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
        bytes state_value_raw = 13;
    }
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