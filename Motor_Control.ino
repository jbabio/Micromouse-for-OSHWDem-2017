void AdvanceOneCell() // Make the bot advance to the next cell.
{
  //RecalibrateDistance();
  if (stepper1.distanceToGo() == 0 && stepper2.distanceToGo() == 0) { // Assure last movement has ended before starting a new one
    stepper1.setMaxSpeed(MAX_SPEED);
    stepper1.setAcceleration(400.0);
    stepper1.setSpeed(SPEED);
    stepper1.moveTo(STEPS_PER_CELL);
    
    stepper2.setMaxSpeed(MAX_SPEED);
    stepper2.setAcceleration(400.0);
    stepper2.setSpeed(SPEED);
    stepper2.moveTo(STEPS_PER_CELL);
  }
}

void RecalibrateDistance() // When an opening is detected at one f the sides, we now we're entering a new cell so we can adjust
{                          // distanceToGo to meet the expected steps. This way we avoid the acumulative distance travelled error.
  if (distance[0] > 500 || distance[4] > 500) { //If there is no wall at right.
  PrintCurrenFunction("RecalibrateDistance()");
  stepper1.setCurrentPosition(STEPS_FROM_EDGE_TO_CENTER);
  stepper1.setSpeed(SPEED);
  stepper2.setCurrentPosition(STEPS_FROM_EDGE_TO_CENTER);
  stepper2.setSpeed(SPEED);
  }
}

void TurnLeft() // Make the bot turn left 90º
{
  if (stepper1.isRunning() == false && stepper2.isRunning() == false) { // Assure last movement has ended before starting a new one
    stepper1.setMaxSpeed(MAX_SPEED);
    stepper1.setAcceleration(ACELERATION);
    stepper1.setSpeed(SPEED);
    stepper1.moveTo(STEPS_TO_TURN_90_DEG);

    stepper2.setMaxSpeed(MAX_SPEED);
    stepper2.setAcceleration(ACELERATION);
    stepper2.setSpeed(SPEED);
    stepper2.moveTo(-STEPS_TO_TURN_90_DEG);
  }
}

void TurnRight() // Make the bot turn right 90º
{
  if (stepper1.isRunning() == false && stepper2.isRunning() == false) { // Assure last movement has ended before starting a new one
    stepper1.setSpeed(SPEED);
    stepper1.moveTo(-STEPS_TO_TURN_90_DEG);

    stepper2.setSpeed(SPEED);
    stepper2.moveTo(STEPS_TO_TURN_90_DEG);
  }
}

void TurnBack() // Make the bot turn 180º
{
  if (stepper1.isRunning() == false && stepper2.isRunning() == false) { // Assure last movement has ended before starting a new one
    stepper1.setSpeed(SPEED);
    stepper1.moveTo(-STEPS_TO_TURN);

    stepper2.setSpeed(SPEED);
    stepper2.moveTo(STEPS_TO_TURN);
  }
}
