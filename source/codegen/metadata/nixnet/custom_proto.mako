message FlexRayStats {
    uint32 NumSyntaxErrorChA = 1;
    uint32 NumSyntaxErrorChB = 2;
    uint32 NumContentErrorChA = 3;
    uint32 NumContentErrorChB = 4;
    uint32 NumSlotBoundaryViolationChA = 5;
    uint32 NumSlotBoundaryViolationChB = 6;
}

message J1939CommState{
    uint32 PGN = 1;
    uint32  SourceAddress = 2;
    uint32  DestinationAddress = 3;
    uint32  TransmitError = 4;
    uint32  ReceiveError = 5;
    uint32 Reserved1 = 6;
    uint32 Reserved2 = 7;
}

message TimeLocalNetwork{
    uint64 LocalTime = 1;
    uint64 NetworkTime = 2;
    uint32 Flags = 3;
}

message StateValue {
    oneof value{
        uint64 time_current = 1;
        uint64 time_communicating = 2;
        uint64 time_start = 3;
        uint32 can_comm = 4;
        uint32 flex_ray_comm = 5;
        FlexRayStats flex_ray_stat = 6;
        uint32 lin_comm = 7;
        uint32 session_info = 8;
        J1939CommState comm_stat = 9;
        TimeLocalNetwork time_current2 = 10;
        TimeLocalNetwork time_communicating2 = 11;
        TimeLocalNetwork time_start2 = 12;
    }
}