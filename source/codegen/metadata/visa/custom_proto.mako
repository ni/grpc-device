message SessionOrObjectData {
  oneof data {
    nidevice_grpc.Session vi = 1;
    ViObject object_handle = 2;
  }
}

message AttributeValueData {
  oneof data {
    uint32 value8 = 1;
    uint32 value16 = 2;
    uint32 value32 = 3;
    fixed64 value64 = 4;
    string valueString = 5;
  }
}
