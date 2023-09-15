message AttributeValueData {
  oneof data {
    uint32 value_u8 = 1;
    int32 value_i16 = 2;
    uint32 value_u16 = 3;
    int32 value_i32 = 4;
    uint32 value_u32 = 5;
    fixed64 value_u64 = 6;
    bool value_bool = 7;
    string value_string = 8;
    bytes value_bytes = 9;
  }
}
