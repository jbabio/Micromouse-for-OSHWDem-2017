void Movements(int movType) // distances in mm
{
  float distL = cellLengt;// Temporal, should be introduced as parameter to function.
  float distR = cellLengt;//Temporal, should be introduced as parameter to function.
  bool brakeLeftMotor = 0; //brake disabled
  bool brakeRightMotor = 0; //brake disabled

  PrintCurrenFunction("Movements()");
  //calculation of steps to travel
  switch (movType) {
    case 0: // mvAhead
      leftMotorPosition   = + (distL * stepsPerMillimeter);
      rightMotorPosition  = + (distR * stepsPerMillimeter);
      break;
    case 1: // mvBack
      leftMotorPosition   = - (distL * stepsPerMillimeter);
      rightMotorPosition  = - (distR * stepsPerMillimeter);
      break;
    case 2: // mvSpinL
      leftMotorPosition   = - (quarterTurn * stepsPerMillimeter);
      rightMotorPosition  = + (quarterTurn * stepsPerMillimeter);
      break;
    case 3: // mvSpinR
      leftMotorPosition   = + (quarterTurn * stepsPerMillimeter);
      rightMotorPosition  = - (quarterTurn * stepsPerMillimeter);
      break;
    case 4: // mvTurnL
      brakeLeftMotor      = 1; //brake
      rightMotorPosition  = + (halfTurn * stepsPerMillimeter);
      break;
    case 5: // mvTurnR
      leftMotorPosition   = + (halfTurn * stepsPerMillimeter);
      brakeRightMotor     = 1; //brake
      break;
    case 6: // mvBkTurnL
      brakeLeftMotor      = 1; //brake
      rightMotorPosition  = - (halfTurn * stepsPerMillimeter);
      break;
    case 7: // mvBkTurnR
      leftMotorPosition   = - (halfTurn * stepsPerMillimeter);
      brakeRightMotor     = 1; //brake
      break;
    case 8: // mvTurn180
      static bool lastHand = 0;
      if (lastHand == 0) {
        leftMotorPosition   = + (halfTurn * stepsPerMillimeter);
        rightMotorPosition  = - (halfTurn * stepsPerMillimeter);
        lastHand = 1;
      } else if (lastHand == 1) {
        leftMotorPosition   = - (halfTurn * stepsPerMillimeter);
        rightMotorPosition  = +(halfTurn * stepsPerMillimeter);
        lastHand = 0;
      }
      if (activateWallAlign == HIGH){
      wallAlignFlag = HIGH;
      }
      break;
    case 9: // mvBrake
      brakeLeftMotor      = 1; //brake
      brakeRightMotor     = 1; //brake
      break;
    case 20: // mvRearGap
      leftMotorPosition   = + (rearGapAtStart * stepsPerMillimeter);
      rightMotorPosition  = + (rearGapAtStart * stepsPerMillimeter);
      break;
    case 21: // mvAlignToWall
      leftMotorPosition   = -1*(40 * stepsPerMillimeter); //go back 40mm
      rightMotorPosition  = -1*(40 * stepsPerMillimeter);
      break;
  }
  ExecuteMoves(movType, brakeLeftMotor, brakeRightMotor);
}

//**************************************************************************************

void ExecuteMoves(int movType, bool brakeLeftMotor , bool brakeRightMotor ) {
  // Movement
  if (brakeLeftMotor == 1)  {                   // if brake order was issued
    leftMotor.stop();                           // Brake motor
  } else {
    leftMotor.move(leftMotorPosition);        // set the destination position.
    if (movType == 0 || movType == 1) {         // if we're going straight forward or backwards
      leftMotor.setMaxSpeed(maxSpeed);          // Set speed to maximum.
    } else {                                    // if we're turning
      leftMotor.setMaxSpeed(speed);             // set speed to normal speed
    }
    leftMotor.setAcceleration(acceleration);    // set acceleration

  }

  if (brakeRightMotor == 1)  {                  // if brake order was issued
    rightMotor.stop();                          // Brake motor
  } else {
    rightMotor.move(rightMotorPosition);      // set the destination position.
    if (movType == 0 || movType == 1) {         // if we're going straight forward or backwards
      rightMotor.setMaxSpeed(maxSpeed);         // Set speed to maximum.
    } else {                                    // if we're turning
      rightMotor.setMaxSpeed(speed);            // set speed to normal speed
    }
    rightMotor.setAcceleration(acceleration);   // set acceleration

  }

  WaitTillMotionEnds(movType);
}

//**************************************************************************************

void WaitTillMotionEnds(int movType) {//targetPosition
  if (LastmovType != movType) {
    //PrintDistances ();
    Serial.println(movType);
    LastmovType = movType;
  }
  while (leftMotor.distanceToGo() != 0 || rightMotor.distanceToGo() != 0) {
    GetDistance(0);
    //PrintDistances ();
    leftMotor.run();
    rightMotor.run();
  }
}

//**************************************************************************************

void SetAtStartPosition() {

}

//**************************************************************************************

void SetAtStartPosition2() {
  int startPosition = 350;
  static int positioningAttempts = 0;
  static bool restoreCurrentPosition = 0;
  long leftMotorCurrentPosition = leftMotor.currentPosition();
  long rightMotorCurrentPosition = rightMotor.currentPosition();
  int correction;

  if (leftMotor.currentPosition() < 1000 || rightMotor.currentPosition() < 1000) {
    leftMotor.setCurrentPosition(1000); // Sets motor postition to 1000 to be able to adjust position backwards at start.
    rightMotor.setCurrentPosition(1000);// Sets motor postition to 1000 to be able to adjust position backwards at start.
    restoreCurrentPosition = 1;
  }
  distance[4] = irSensor[4].getDist(); //read back sensor
  Serial.println(distance[4] / 10);

  if (distance[4] > startPosition) {
    correction          = ((distance[4] - startPosition) / 10) * stepsPerMillimeter;
    leftMotorPosition   = leftMotor.currentPosition() - correction;
    rightMotorPosition  = rightMotor.currentPosition() - correction;
  } else if (distance[4] < startPosition) {
    correction          = ((startPosition - distance[4]) / 10) * stepsPerMillimeter;
    leftMotorPosition   = leftMotor.currentPosition() + correction;
    rightMotorPosition  = rightMotor.currentPosition() + correction;
  }
  WaitTillPositioned(correction, 50);
  Serial.print("distancia tras ajuste: ");
  Serial.println(distance[4] / 10);
  Serial.print("Valor bruto: ");
  Serial.println(distance[4]);
  if (positioningAttempts < 3) {
    if (distance[4] < startPosition * 0.98 || distance[4] > startPosition * 1.02) {
      positioningAttempts++;
      SetAtStartPosition();
    }
  } else if (restoreCurrentPosition == 1) {
    leftMotor.setCurrentPosition(leftMotorCurrentPosition); // Restores CurrentPosition to previous value once positioned.
    rightMotor.setCurrentPosition(rightMotorCurrentPosition);// Restores CurrentPosition to previous value once positioned.
    restoreCurrentPosition = 0;
  }
}

//**************************************************************************************

void WaitTillPositioned(int correction, int movType) {//targetPosition
  ExecuteMoves(movType, 0, 0);
  distance[4] = irSensor[4].getDist(); //read back sensor
}

//**************************************************************************************

void Brake(bool motor1, bool motor2) {
  if (motor1 == HIGH) {
    leftMotor.enableOutputs();
  } else {
    leftMotor.disableOutputs();
  }
  if (motor2 == HIGH) {
    rightMotor.enableOutputs();
  } else {
    rightMotor.disableOutputs();
  }
}

//**************************************************************************************

void DetectMissingWall () {
  if (distance[0] > 500 || distance[3] > 500) { //If there's no wall at the sides.
    if (distance[0] >= distance[3]) {           // In Right hand distance[0] (right) >= distance[3], th opposite in left hand
      static int missingWall = 0;               // Missing Right Wall
    } else {
      static int missingWall = 4;               // Missing Left Wall
    }
  }
}



