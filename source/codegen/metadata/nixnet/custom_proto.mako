message Frame {
    uint64 timestamp = 1;
    uint32 identifier = 2;
    uint32 type = 3;
    uint32 flags = 4;
    uint32 info = 5;
    uint32 payload_length = 6;
    bytes payload = 7;
}
