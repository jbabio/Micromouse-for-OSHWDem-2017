void GetDistance(){
  // Get distance from sensor
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    distance[i] = irSensor[i].getDist();
  }

  // Print distances measured to Serial
  for (int i = 0; i < NUM_SENSORS; i++)
  {
  Serial.print(distance[i]);
  Serial.print("\t");
  }
  Serial.println();
}
