message IPAddress {
  uint32 family = 1;
  string address = 2;
  string net_mask = 3;
  uint32 prefix_length = 4;
}

message GatewayAddress {
  uint32 family = 1;
  string address = 2;
}

message VirtualInterface {
  string xnet_interface_name = 1;
  string vlane_name = 2;
  string mac_address = 3;
  uint32 mac_mtu = 4;
  uint32 operational_status = 5;
  uint32 if_index = 6;
  repeated IPAddress ip_addresses = 7;
  repeated GatewayAddress gateway_addresses = 8;
}

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

message AddrInfo {
  int32 flags = 1;
  int32 family = 2;
  int32 sock_type = 3;
  int32 protocol = 4;
  SockAddr addr = 5;
  string canon_name = 6;
}

message SockOptData {
  oneof data {
    int32 data_int32 = 2;
    bool data_bool = 3;
    string data_string = 4;
  }
}
