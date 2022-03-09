message SockAddrIPv4 {
  uint32 port = 1;
  uint32 addr = 2;
}

message SockAddrIPv6 {
  uint32 port = 1;
  uint32 flow_info = 2;
  bytes addr = 3;
  uint32 scope_id = 4;
}

message SockAddr {
  oneof addr {
    SockAddrIPv4 ipv4 = 1;
    SockAddrIPv6 ipv6 = 2;
  }
}

message SockOptData {
  SocketOptions opt = 1;
  oneof data {
    int32 data_int32 = 2;
    bool data_bool = 3;
    string data_string = 4;
  }
}
