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

enum SockOptNames {
  SOCK_OPT_NAMES_UNSPECIFIED = 0;
  SOCK_OPT_NAMES_RX_DATA = 257;
  SOCK_OPT_NAMES_RCV_BUF = 258;
  SOCK_OPT_NAMES_SND_BUF = 259;
  SOCK_OPT_NAMES_NON_BLOCK = 260;
  SOCK_OPT_NAMES_BIND_TO_DEVICE = 261;
  SOCK_OPT_NAMES_ERROR = 262;
  SOCK_OPT_NAMES_LINGER = 263;
  SOCK_OPT_NAMES_REUSE_ADDR = 264;
}

message SockOptData {
  SockOptNames opt_name = 1;
  oneof data {
    int32 data_int32 = 2;
    bool data_bool = 3;
    string data_string = 4;
  }
}
