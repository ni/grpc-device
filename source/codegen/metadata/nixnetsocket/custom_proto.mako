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

enum OptName {
  OPT_NAME_UNSPECIFIED = 0;
  OPT_NAME_TCP_NODELAY = 1;
  OPT_NAME_IP_MULTICAST_TTL = 6;
  OPT_NAME_IPV6_MULTICAST_HOPS = 15;
  OPT_NAME_SO_RX_DATA = 257;
  OPT_NAME_SO_RCV_BUF = 258;
  OPT_NAME_SO_SND_BUF = 259;
  OPT_NAME_SO_NON_BLOCK = 260;
  OPT_NAME_SO_BIND_TO_DEVICE = 261;
  OPT_NAME_SO_ERROR = 262;
  OPT_NAME_SO_LINGER = 263;
  OPT_NAME_SO_REUSE_ADDR = 264;
}

message SockOptData {
  OptName opt_name = 1;
  oneof data {
    int32 data_int32 = 2;
    bool data_bool = 3;
    string data_string = 4;
  }
}
