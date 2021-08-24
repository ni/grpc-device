message AnalogPowerUpChannelsAndState {
  string channelNames = 1;
  double state = 2;
  PowerUpChannelType channelType = 3;
}

message WatchdogExpChannelsAndState {
  string lines = 1;
  DigitalLineState expState = 2;
}

message DigitalPowerUpTypeAndChannel {
  string channelName = 1;
  PowerUpStates state = 2;
}

message DigitalPowerUpChannelsAndState {
  string channelNames = 1;
  PowerUpStates state = 2;
}

message DigitalPullUpPullDownChannelsAndState {
  string channelNames = 1;
  ResistorState state = 2;
}

message AnalogPowerUpChannelAndType {
  string channelName = 1;
  PowerUpChannelType channelType = 2;
}