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
        1 HMC6352 Compass (not Implemented yet)
        1 ADXL330K Acelerometer (not Implemented yet)

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

*/

#include <SharpDistSensor.h>
#include <AccelStepper.h>
#include "HAL.h"  //Local library containing the Hardware setup specific for this robot.

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper leftMotor(AccelStepper::FULL4WIRE, motor1Pin1, motor1Pin3, motor1Pin2, motor1Pin4); // Left Stepper
AccelStepper rightMotor(AccelStepper::FULL4WIRE, motor2Pin1, motor2Pin3, motor2Pin2, motor2Pin4); // Right Stepper

// Window size of the median filter for the IR sensors(odd number, 1 = no filtering)
const byte mediumFilterWindowSize = 5;

// Create an array of object instances of the SharpDistSensor class for the sensors. This allows us to access them in a for loop.
SharpDistSensor irSensor [NUM_SENSORS] = {                   
  SharpDistSensor (sensorPin[0], mediumFilterWindowSize),
  SharpDistSensor (sensorPin[1], mediumFilterWindowSize),
  SharpDistSensor (sensorPin[2], mediumFilterWindowSize),
  SharpDistSensor (sensorPin[3], mediumFilterWindowSize),
  SharpDistSensor (sensorPin[4], mediumFilterWindowSize),
};

//Create an array to store the distances measured by the sensors. This allows us to access them in a for loop.
unsigned int distance[5] = { 0, 0, 0, 0, 0 };
int irChecksum =0;
long leftMotorPosition = 0;
long rightMotorPosition = 0;
void setup() {
  Serial.begin(9600);
  GetDistance();
  //delay(10000);
  PrintDistances ();
  //leftMotor.setMaxSpeed(MAX_SPEED);
  //leftMotor.setAcceleration(ACELERATION);
  //leftMotor.setSpeed(300);
  //leftMotor.moveTo(20000);
}

void loop() {
GetDistance();
mazeSolver ();


  //When the stepper reaches the target position...
  if (leftMotor.distanceToGo() == 0) {
    //leftMotor.moveTo(-leftMotor.currentPosition());
    
  }

  leftMotor.run();
  rightMotor.run();
}
