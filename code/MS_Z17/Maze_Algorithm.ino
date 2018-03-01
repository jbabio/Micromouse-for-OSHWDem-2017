/*
#define mvAhead   0
#define mvBack    1
#define mvSpinL   2
#define mvSpinR   3
#define mvTurnL   4
#define mvTurnR   5
#define mvBkTurnL 6
#define mvBkTurnR 7
#define mvTurn180 8
#define mvBrake   9
#define mvRearGap 20
#define mvAlignToWall 21
*/
void MazeSolverRight () { // Right hand
  BUZZER.beep();
  PrintCurrenFunction ("MazeSolverRight");
  if (distance[3] > 500) { //If there is no wall at right.
    if (LastmovType == 3) {
      Movements(mvAhead);
    } else {
      Movements(mvSpinR);
    }
  } else if (distance[1] > 500) { //If there is no wall in front.
    Movements(mvAhead);
  } else if (distance[0] > 500) { //If there is no wall at left.
    if (LastmovType == 2) {
      Movements(mvAhead);
    } else {
      Movements(mvSpinL);
    }
  } else {
    Movements(mvTurn180);
  }
}

void MazeSolverLeft () { // Left hand
  BUZZER.beep();
  PrintCurrenFunction ("MazeSolverLeft");
  if (distance[0] > 500) { //If there is no wall at left.
    if (LastmovType == 2) {
      Movements(mvAhead); //Last movement
    } else {
      Movements(mvSpinL);
    }
  } else if (distance[1] > 500) { //If there is no wall in front.
    Movements(mvAhead);
  } else if (distance[3] > 500) { //If there is no wall at Right.
    if (LastmovType == 3) {
      Movements(mvAhead);
    } else {
      Movements(mvSpinR);
    }
  } else {
    Movements(mvTurn180);
  }
}

int navigation(int movType) {
  const int botHeading = 4;


}

