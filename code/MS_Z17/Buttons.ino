int CheckButton() {                 // Takes a pin number as parameter and returns a boolean. (HIGH: button pressed)

  static unsigned long lastDebounceTime = 0;      // *the last time the output pin was toggled
  static unsigned long debounceDelay = 50;        // *the debounce time; increase if the output flickers
  static int buttonState;                        // Reading from the button pin, static type to have global lifetime
  static int lastButtonState = LOW;              // *The previous reading from the button pin, static type to have global lifetime

  int reading = analogRead(buttonPin);            // *read the state of the switch into a local variable
  //Serial.println(reading);            // Uncomment this to show readed button values.
  int tmpButtonState = LOW;             // the current reading from the input pin

  for ( int i = 0 ; i < NUM_BUTTONS ; i++) {
    if (reading > BUTTONTHRESHOLDLOW[i] && reading < BUTTONTHRESHOLDHIGH[i]) {
      //Read switch 5
      tmpButtonState = BUTTON[i];
    }
  }

  if (tmpButtonState != lastButtonState) {  // If the switch changed, due to noise or pressing:
    lastDebounceTime = millis();    // reset the debouncing timer
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:
    buttonState = tmpButtonState;
    //Serial.println(buttonState);
  }

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = tmpButtonState;
  return tmpButtonState;
}

void WaitForStart() {                             // Wait for the button to be pressed to exit setup() and start loop()
  bool exitFlag = 0;
  //ToggleLED (LOW, HIGH);                        // LED1 off: calibration ended/parameters restored | LED2 on: Robot ready to start.
  while (exitFlag == 0) {                                  // Infinite loop
    //UpdatePIDParameters ();                     // Check for updated PID gains & speed through serial interface.
    switch (CheckButton()) {                      // Check if the button was pressed
      case 1:
        solverHand = 0;
        BUZZER.beep();
        delay(500);
        break;  // Break the infinite loop
      case 2:
        //ToggleLED (LOW, LOW);                   // Reset LEDs.
        exitFlag = 1;
        break;                                    // Break the infinite loop
      case 3:
        Movements(mvRearGap);
        //ToggleLED (LOW, LOW);                   // Reset LEDs.
        exitFlag = 1;
        break;                                    // Break the infinite loop
      case 4:
        solverHand = 1;
        BUZZER.beep();
        delay(500);
        BUZZER.beep();
        delay(500);
        break;                                    // Break the infinite loop
      case 5:
        if (activateWallAlign == LOW) {
          activateWallAlign = HIGH;
          BUZZER.beep();
          delay(500);
          BUZZER.beep();
          delay(500);
          BUZZER.beep();
          delay(500);
        } else {
          activateWallAlign = LOW;
          BUZZER.beep();
          delay(500);
          BUZZER.beep();
          delay(500);
          BUZZER.beep();
          delay(500);
          BUZZER.beep();
          delay(500);
        }
        break;  // Break the infinite loop
    }
  }
}

void PauseCheck() {                               // Check if the pause button was pressed during loop()
  if (CheckButton() == HIGH) {            // Check if we should be paused (pause button presed)
    PrintCurrenFunction ("PauseCheck()");
    while (CheckButton() == LOW) {
      BlinkLED(11, 200);                          // Blink both LEDs simultaniously at 200ms to indicate it's in pause mode.
    }
  }
}

