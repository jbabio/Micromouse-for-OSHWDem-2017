/*
  Micromouse for the Maze Solving contest at OSHWDem 2017(https://oshwdem.org/)

  Note: This first version will use Left/Right algorithm to solve the maze.

  Hardware Used:

    Robot base: Modified Escornabot (http://escornabot.com) (https://github.com/escornabot)
    Main Electronics: Arduino UNO
    Motors: 28BYJ-48
    Motor Drivers: ULN2003 breakout board.
    Sensors:
        5 Sharp GP2Y0A51SK0F 2-15 cm


  Dependencies.

    SharpDistSensor Library for Arduino, By Julien de la Bruère-Terreault. MIT License
      (https://github.com/DrGFreeman/SharpDistSensor)

    AccelStepper library for Arduino, Copyright (C) 2010 Mike McCauley. GPL V2
      http://www.airspayce.com/mikem/arduino/AccelStepper/
      Class Reference: http://www.airspayce.com/mikem/arduino/AccelStepper/classAccelStepper.html

  Acknowledgements

    Mike McCauley for the AccelStepper library.
    Julien de la Bruère-Terreault for the SharpDistSensor library.
    Andrew Kramer (https://github.com/1988kramer) for inspiration about implementing the sensor polling.
    42Bots.com (http://42Bots.com / https://github.com/42Bots) For their example to use 28BYJ-48 motors with accelstepper library.
    Anyone who create or share Open Source Hardware or Software.

    Buzzer.h & .cpp from Escornabot

*/

#include <SharpDistSensor.h>
#include <AccelStepper.h>
#include "HAL.h"                            //Local library containing the Hardware setup specific for this robot.
#include "Buzzer.h"
Buzzer BUZZER = Buzzer(BUZZER_PIN);

// movements
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

static unsigned long lastDebounceTime = 0;      // *the last time the output pin was toggled
static unsigned long debounceDelay = 50;        // *the debounce time; increase if the output flickers
static int buttonState;                        // Reading from the button pin, static type to have global lifetime
static int lastButtonState = LOW;              // *The previous reading from the button pin, static type to have global lifetime


// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48 ////AccelStepper::FULL4WIRE
AccelStepper leftMotor(AccelStepper::FULL4WIRE, motor1Pin4, motor1Pin2, motor1Pin3, motor1Pin1); // Left Stepper
AccelStepper rightMotor(AccelStepper::FULL4WIRE, motor2Pin1, motor2Pin3, motor2Pin2, motor2Pin4); // Right Stepper

// Window size of the median filter for the IR sensors(odd number, 1 = no filtering)
const byte mediumFilterWindowSize = 1;

// Create an array of object instances of the SharpDistSensor class for the sensors. This allows us to access them in a for loop.
SharpDistSensor irSensor [NUM_SENSORS] = {
  SharpDistSensor (sensorPin[0], mediumFilterWindowSize),   // LEFT SIDE SENSOR
  SharpDistSensor (sensorPin[1], mediumFilterWindowSize),   // FRONT LEFT SENSOR
  SharpDistSensor (sensorPin[2], mediumFilterWindowSize),   // FRONT RIGHT SENSOR
  SharpDistSensor (sensorPin[3], mediumFilterWindowSize),   // RIGHT SIDE SENSOR
  SharpDistSensor (sensorPin[4], mediumFilterWindowSize),   // BACK SENSOR
};

//Create an array to store the distances measured by the sensors. This allows us to access them in a for loop.
int distance[5]; // = { 0, 0, 0, 0, 0 };
long leftMotorPosition = 0;
long rightMotorPosition = 0;
int LastmovType = 0; // 0 Start, 0 front, 2 left, 3 right
// Setup Flags
bool bootMode = LOW;
bool solverHand = LOW;                           // 0 Right hand | 1 Left hand
bool activateWallAlign = LOW;
bool wallAlignFlag = LOW;

//bool verboseReadingOut = LOW;                  // Flag to output verbose QTR8 readings




void setup() {
  Serial.begin(9600);
  Serial.println("RESET");
  pinMode(buttonPin, INPUT);
  delay(1000);
  BUZZER.beep();
  ShowBotSetup();
  //pinMode(led1, OUTPUT);
  //pinMode(led2, OUTPUT);
  GetDistance(1);
  PrintDistances ();
  WaitForStart();
  BUZZER.playRttl(RTTL_INTEL);
}

void loop() {
 GetDistance(1); // Parameter: 1 mandatory | 0 Optional
  PrintDistances ();
  if (wallAlignFlag == HIGH){
    Movements(mvAlignToWall);
    wallAlignFlag = LOW;
    Movements(mvRearGap);
  }
  if (solverHand == 0) {
    MazeSolverRight();
  } else if (solverHand == 1) {
    MazeSolverLeft();
  }
  //CheckButton();
  //PauseCheck();
}
