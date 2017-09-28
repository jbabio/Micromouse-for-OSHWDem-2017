void mazeSolver () { // Right hand
  if (distance[0] > 500) { //If there is no wall at right.
    PrintCurrenFunction("TurnRight()");
    TurnRight();
  } else if (distance[2] > 500) { //If there is no wall in front.
    PrintCurrenFunction("AdvanceOneCell()");
    AdvanceOneCell();
  } else if (distance[4] > 500) { //If there is no wall at left.
    PrintCurrenFunction("TurnLeft()");
    TurnLeft();
  } else {
    PrintCurrenFunction("TurnBack()");
    TurnBack();
  }
}

void PrintCurrenFunction(String CurrenFunction) {
  static String LastFunction;
  if (LastFunction != CurrenFunction) {
    Serial.println(CurrenFunction);
    LastFunction = CurrenFunction;
  }
}

