void PrintDistances () {
  int IRPollInterval = 1000;
  static unsigned long previousIRMillis = 0;                  // Last time LEDs were updated, static type to have global lifetime
  unsigned long currentIRMillis = millis();
  if (currentIRMillis - previousIRMillis >= IRPollInterval) {
    previousIRMillis = currentIRMillis;                         // save the last time you blinked the LED
    // Print distances measured to Serial
    for (int i = 0; i < NUM_SENSORS; i++)
    {
      Serial.print(distance[i]);
      Serial.print("\t");
    }
    Serial.println();
  }
}


void PrintCurrenFunction(String CurrenFunction) {
  static String LastFunction;
  if (LastFunction != CurrenFunction) {
    PrintDistances ();
    Serial.println(CurrenFunction);
    LastFunction = CurrenFunction;
  }
}

void ShowBotSetup(){
  Serial.print("stepsPerMillimeter: ");
  Serial.println(stepsPerMillimeter);
  Serial.print("wheelDiameter: ");
  Serial.println(wheelDiameter);
  Serial.print("wheelRadius: ");
  Serial.println(wheelRadius);
  Serial.print("pi: ");
  Serial.println(pi);
  Serial.print("wheelPerimeter: ");
  Serial.println(wheelPerimeter);
}

