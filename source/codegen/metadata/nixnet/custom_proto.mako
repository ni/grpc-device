message U32Array {
    repeated uint32 u32_array = 1;
}

message DbRefArray {
    repeated nidevice_grpc.Session db_ref = 1;
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
        U32Array u32_array = 9;
        nidevice_grpc.Session db_ref = 10;
        DbRefArray db_ref_array = 11;
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
        U32Array u32_array = 11;
        nidevice_grpc.Session db_ref = 12;
        DbRefArray db_ref_array = 13;
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
        U32Array u32_array = 7;
        bytes u8_array = 8;
        nidevice_grpc.Session db_ref = 9;
        DbRefArray db_ref_array = 10;
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
        U32Array u32_array = 9;
        bytes u8_array = 10;
        nidevice_grpc.Session db_ref = 11;
        DbRefArray db_ref_array = 12;
    }
}

message DbSetPropertyResponse {
    int32 status = 1;
}

message DbGetDatabaseListRequest {
    string ip_address = 1;    
}

message DbGetDatabaseListResponse {
    int32 status = 1;
    string alias_buffer = 2;
    string file_path_buffer = 3;
    uint32 number_of_databases = 4;
}