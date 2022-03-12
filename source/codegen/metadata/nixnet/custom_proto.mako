message u32Array {
    repeated uint32 u32_array = 1;
}

message refArray {
    repeated nidevice_grpc.Session ref = 1;
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
        string string_array = 8;
        u32Array u32_array = 9;
    }
}

message SetPropertyRequest {
    nidevice_grpc.Session session_ref = 1;
    oneof property_id_enum {
        Property property_id = 2;
        uint32 property_id_raw = 3;
    }
    oneof property_value {
        uint32 u32_scalar = 4;
        bool bool_scalar = 5;
        string str = 6;
        uint64 u64_scalar = 7;
        int32 i32_scalar = 8;
        double f64_scalar = 9;
        string string_array = 10;
        u32Array u32_array = 11;
    }
}

message SetPropertyResponse {
    int32 status = 1;
}

message GetSubPropertyRequest {
    nidevice_grpc.Session session_ref = 1;
    uint32 active_index = 2;
    oneof subproperty_id_enum {
        SubProperty property_id = 3;
        uint32 property_id_raw = 4;
    }
}

message GetSubPropertyResponse {
    int32 status = 1;
    oneof property_value {
        uint32 u32_scalar = 2;
        string str = 3;
        double f64_scalar = 9;
    }
}

message DbGetPropertyRequest {
    nidevice_grpc.Session dbobject_ref = 1;
    oneof dbproperty_id_enum {
        DBProperty property_id = 2;
        uint32 property_id_raw = 3;
    }
}

message DbGetPropertyResponse {
    int32 status = 1;
    oneof property_value {
        uint32 u32_scalar = 2;
        bool bool_scalar = 3;
        string str = 4;
        uint64 u64_scalar = 5;
        double f64_scalar = 6;
        u32Array u32_array = 7;
        bytes u8_array = 8;
    }
}

message SetSubPropertyRequest {
    nidevice_grpc.Session session_ref = 1;
    uint32 active_index = 2;
    oneof subproperty_id_enum {
        SubProperty property_id = 3;
        uint32 property_id_raw = 4;
    }
    oneof property_value {
        uint32 u32_scalar = 5;
        string str = 6;
        double f64_scalar = 7;
    }
}

message SetSubPropertyResponse {
    int32 status = 1;
}

message DbSetPropertyRequest {
    nidevice_grpc.Session dbobject_ref = 1;
    oneof dbproperty_id_enum {
        DBProperty property_id = 2;
        uint32 property_id_raw = 3;
    }
    oneof property_value {
        uint32 u32_scalar = 4;
        bool bool_scalar = 5;
        string str = 6;
        uint64 u64_scalar = 7;
        double f64_scalar = 8;
        u32Array u32_array = 9;
        bytes u8_array = 10;
    }
}

message DbSetPropertyResponse {
    int32 status = 1;
}