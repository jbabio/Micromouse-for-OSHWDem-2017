void GetDistance() {
  // Get distance from sensor
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    distance[i] = irSensor[i].getDist();
    if (i == 0){
      irChecksum = 0;
    }
    irChecksum = irChecksum + distance[i];
    if (irChecksum == 7500) {
      GetDistance();
    } 
  }
}

void PrintDistances () {
  // Print distances measured to Serial
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(distance[i]);
    Serial.print("\t");
  }
  Serial.println();
  Serial.println(irChecksum);
}

