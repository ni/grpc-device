message FlexRayStats {
    uint32 NumSyntaxErrorChA;
    uint32 NumSyntaxErrorChB;
    uint32 NumContentErrorChA;
    uint32 NumContentErrorChB;
    uint32 NumSlotBoundaryViolationChA;
    uint32 NumSlotBoundaryViolationChB;
}

message J1939CommState{
    uint32 PGN;
    uint32  SourceAddress;
    uint32  DestinationAddress;
    uint32  TransmitError;
    uint32  ReceiveError;
    uint32 Reserved1;
    uint32 Reserved2;
}

message TimeLocalNetwork{
    uint64 LocalTime;
    uint64 NetworkTime;
    uint32 Flags;
}

message StateValue {
    oneof value{
        uint64 time_stamp_100_ns = 1,
        uint32 can_lin_comm = 2,
        FlexRayStats flex_ray_stat = 3,
        J1939CommState comm_stat = 4,
        TimeLocalNetwork time_local_network = 5
    }
}