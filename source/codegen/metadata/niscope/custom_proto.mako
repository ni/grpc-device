message WaveformInfo {
  double absolute_initial_x = 1;
  double relative_initial_x = 2;
  double x_increment = 3;
  sint32 actual_samples = 4;
  double offset = 5;
  double gain = 6;
  double reserved1 = 7;
  double reserved2 = 8; 
} 

message CoefficientInfo {
  double offset = 1;
  double gain = 2;
  double reserved1 = 3;
  double reserved2 = 4;
}

message NIComplexNumber {
    double real = 1;
    double imaginary = 2;
} 

message NIComplexInt32 {
    sint32 real = 1;
    sint32 imaginary = 2;
}