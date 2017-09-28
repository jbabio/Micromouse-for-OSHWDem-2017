void mazeSolver () { // Right hand
  if (distance[0] > 500) { //If there is no wall at right.
    TurnRight();
  } else if (distance[2] > 500) { //If there is no wall in front.
    AdvanceOneCell();
  } else if (distance[4] > 500) { //If there is no wall at left.
    TurnLeft();
  } else {
    TurnBack();
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

