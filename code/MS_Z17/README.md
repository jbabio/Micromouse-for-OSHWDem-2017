# Micromouse for the Maze Solving contest at OSHWDem 2017 
(https://oshwdem.org/)

__Note: This first version will use Left/Right algorithm to solve the maze__

## Hardware Used:
  * Robot base: Modified Escornabot (http://escornabot.com) (https://github.com/escornabot)
  * Main Electronics: Arduino UNO
  * Motors: 28BYJ-48
  * Motor Drivers: ULN2003 breakout board.
  * Sensors:
    * 5 Sharp GP2Y0A51SK0F  2-15 cm
    * 1 HMC6352 Compass (not Implemented yet)
    * 1 ADXL330K Acelerometer (not Implemented yet)
    
## Acknowledgements

* Mike McCauley for the AccelStepper library.
* Julien de la Bruère-Terreault for the SharpDistSensor library.
* Andrew Kramer (https://github.com/1988kramer) for inspiration about implementing the sensor polling.
* 42Bots.com (http://42Bots.com / https://github.com/42Bots) For their example to use 28BYJ-48 motors with accelstepper library.
* Anyone who create or share Open Source Hardware or Software.

## Dependencies.
SharpDistSensor Library for Arduino, By Julien de la Bruère-Terreault. MIT License 
  * (https://github.com/DrGFreeman/SharpDistSensor)
  
AccelStepper library for Arduino, Copyright (C) 2010 Mike McCauley. GPL V2 
  * http://www.airspayce.com/mikem/arduino/AccelStepper/
  * Class Reference: http://www.airspayce.com/mikem/arduino/AccelStepper/classAccelStepper.html

## Current status

Right hand algorithm implemented

## Known issues

Aceleration is too slow, need to revise AccelStepper library to speed it up.

## Todo

* Read IR Sensors -> DONE
* Control motors -> DONE
* Center of maze detection - > PENDING
* Right hand algorithm -> DONE
* Left Hand algorithm -> PENDING
* Flood Algorithm -> PENDING
