void AdvanceOneCell() // Make the bot advance to the next cell.
{
  //RecalibrateDistance();
  if (leftMotor.distanceToGo() == 0 && rightMotor.distanceToGo() == 0) { // Assure last movement has ended before starting a new one
    //leftMotor.setMaxSpeed(MAX_SPEED);
    PrintCurrenFunction("AdvanceOneCell()");
    leftMotor.moveTo(leftMotor.currentPosition()-STEPS_PER_CELL);
    leftMotor.setAcceleration(ACELERATION);
    leftMotor.setSpeed(SPEED);
        
    //rightMotor.setMaxSpeed(MAX_SPEED);
    rightMotor.moveTo(rightMotor.currentPosition() + STEPS_PER_CELL);
    rightMotor.setAcceleration(ACELERATION);
    rightMotor.setSpeed(SPEED);
  }
}

void TurnLeft() // Make the bot turn left 90º
{
  if (leftMotor.isRunning() == false && rightMotor.isRunning() == false) { // Assure last movement has ended before starting a new one
    PrintCurrenFunction("TurnLeft()");

    leftMotor.moveTo(leftMotor.currentPosition() - STEPS_TO_TURN_90_DEG);
    leftMotor.setAcceleration(ACELERATION);
    leftMotor.setSpeed(SPEED);

    rightMotor.moveTo(rightMotor.currentPosition() - STEPS_TO_TURN_90_DEG);
    rightMotor.setAcceleration(ACELERATION);
    rightMotor.setSpeed(SPEED);
  }
}

void TurnRight() // Make the bot turn right 90º
{
  if (leftMotor.isRunning() == false && rightMotor.isRunning() == false) { // Assure last movement has ended before starting a new one
    PrintCurrenFunction("TurnRight()");
    leftMotor.moveTo(leftMotor.currentPosition() + STEPS_TO_TURN_90_DEG);
    leftMotor.setAcceleration(ACELERATION);
    leftMotor.setSpeed(SPEED);

    rightMotor.moveTo(rightMotor.currentPosition() + STEPS_TO_TURN_90_DEG);
    rightMotor.setAcceleration(ACELERATION);
    rightMotor.setSpeed(SPEED);
  }
}

void TurnBack() // Make the bot turn 180º
{
  if (leftMotor.isRunning() == false && rightMotor.isRunning() == false) { // Assure last movement has ended before starting a new one
    PrintCurrenFunction("TurnBack()");
    leftMotor.moveTo(leftMotor.currentPosition() - STEPS_TO_TURN);
    leftMotor.setAcceleration(ACELERATION);
    leftMotor.setSpeed(SPEED);

    rightMotor.moveTo(rightMotor.currentPosition() - STEPS_TO_TURN);
    rightMotor.setAcceleration(ACELERATION);
    rightMotor.setSpeed(SPEED);
  }
}

void RecalibrateDistance() // When an opening is detected at one f the sides, we now we're entering a new cell so we can adjust
{                          // distanceToGo to meet the expected steps. This way we avoid the acumulative distance travelled error.
  if (distance[0] > 500 || distance[4] > 500) { //If there is no wall at right.
  PrintCurrenFunction("RecalibrateDistance()");
  //leftMotor.setCurrentPosition(STEPS_FROM_EDGE_TO_CENTER);
  leftMotor.setAcceleration(ACELERATION);
  leftMotor.setSpeed(SPEED);
  
  //rightMotor.setCurrentPosition(STEPS_FROM_EDGE_TO_CENTER);
  rightMotor.setAcceleration(ACELERATION);
  rightMotor.setSpeed(SPEED);
  }
}
