/*
  SharpDistSensorBasic.ino
  Source: https://github.com/DrGFreeman/SharpDistSensor

  MIT License

  Copyright (c) 2017 Julien de la Bruere-Terreault <drgfreeman@tuta.io>

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

/*
  This example shows how to use the SharpDistSensor library to continuously
  read the sensor and display the analog value and the corrseponding distance
  in mm.

  The library default values corresponding to the Sharp GP2Y0A60SZLF 5V sensor
  are used.

  See the library README for how to use pre-defined sensor models or custom
  fit functions.  2048
*/

#include <SharpDistSensor.h>
#include <AccelStepper.h>
#include "HAL.h"  //Local library containing the Hardware setup specific for this robot.

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper stepper1(HALFSTEP, motor1Pin1, motor1Pin3, motor1Pin2, motor1Pin4);
AccelStepper stepper2(HALFSTEP, motor2Pin1, motor2Pin3, motor2Pin2, motor2Pin4);

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

void setup() {
  Serial.begin(9600);
  //stepper1
  stepper1.setMaxSpeed(1000.0);
  stepper1.setAcceleration(100.0);
  //stepper1.setSpeed(200);
  //stepper1.moveTo(20000);
  //stepper2
  stepper1.setMaxSpeed(1000.0);
  stepper1.setAcceleration(100.0);
  //stepper1.setSpeed(200);
  //stepper1.moveTo(20000);
}

void loop() {
GetDistance();



  //When the stepper reaches the target position...
  if (stepper1.distanceToGo() == 0) {
    //stepper1.moveTo(-stepper1.currentPosition());
    
  }

  stepper1.run();
  stepper2.run();
}
