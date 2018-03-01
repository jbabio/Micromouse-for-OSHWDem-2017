void GetDistance (bool priority) {
  int getIRInterval = 1000;
  static unsigned long previousGetIRMillis = 0;                  //
  unsigned long currentGetIRMillis;
  if (priority == 1) {
    currentGetIRMillis = millis() + getIRInterval; // Forces the update making sure that currentGetIRMillis - previousGetIRMillis >= getIRInterval
  } else {
    currentGetIRMillis = millis();
  }
  if (currentGetIRMillis - previousGetIRMillis >= getIRInterval) {
    previousGetIRMillis = currentGetIRMillis;                         // save the last time you readed the Ir Sensor
    for (int i = 0; i < NUM_SENSORS-1; i++)
    {
      distance[i] = irSensor[i].getDist();
      leftMotor.run(); //Moves the motors after reading each sensor to avoid lag
      rightMotor.run();
    }
  }
}



