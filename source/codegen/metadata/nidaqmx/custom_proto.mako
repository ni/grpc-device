message AnalogPowerUpState {
  string channelNames = 1;
  double state = 2;
  PowerUpChannelType channelType = 3;
}

message ChannelNamesAndExpState {
  string channelNames = 1;
  DigitalLineState expState = 2;
}

message DigitalPowerUpTypeAndChannel {
  string channelName = 1;
  DigitalPowerUpChannelType state = 2;
}

message DigitalPowerUpTypeAndChannels {
  string channelNames = 1;
  DigitalPowerUpChannelType state = 2;
}

message DigitalPullUpPullDownStateAndChannel {
  string channelNames = 1;
  DigitalPullUpPullDownState state = 2;
}

message PowerUpChannelTypeAndName {
  string channelName = 1;
  PowerUpChannelType channelType = 2;
}