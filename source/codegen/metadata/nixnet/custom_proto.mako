message u32Array {
    repeated uint32 u32_array = 1;
}

message refArray {
    repeated  nidevice_grpc.Session ref = 1;
}

message GetPropertyRequest {
    nidevice_grpc.Session session_ref = 1;
    oneof property_id_enum {
        Property property_id = 2;
        uint32 property_id_raw = 3;
    }
} 

message GetPropertyResponse {
    int32 status = 1;
    oneof property_value {
        uint32 u32_scalar = 2;
        bool bool_scalar = 3;
        string str = 4;
        uint64 u64_scalar = 5;
        int32 i32_scalar = 6;
        double f64_scalar = 7;
        nidevice_grpc.Session ref = 8;
        bytes string_array = 9;
        u32Array u32_array = 10;
        refArray ref_array = 11;
    }
}