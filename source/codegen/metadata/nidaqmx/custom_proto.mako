message AnalogPowerUpState {
  string channelNames = 1;
  double state = 2;
  PowerUpChannelType channelType = 3;
}

message DigitalPowerUpState {
  string channelNames = 1;
  DigitalPowerUpChannelType state = 2;
}