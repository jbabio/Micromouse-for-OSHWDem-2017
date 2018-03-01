# Micromouse for the Maze Solving contest at OSHWDem 2017 
(https://oshwdem.org/)

![MZ_Z17](/images/MZ_Z17.jpg)

__Note: This version uses Left/Right algorithm to solve the maze, No further development will be made on it__

## Hardware Used:
  * Robot base: Modified Escornabot (http://escornabot.com) (https://github.com/escornabot)
  * Main Electronics: ~~Arduino UNO~~ Ogaki board from @abierto-cc 
  * Motors: 2x 28BYJ-48 5V
  * Motor Drivers: ~~2x ULN2003 breakout boards.~~ 1x ULN2803 in the Ogaki board
  * Power:
    * UBSAN 610mah, 2S Battery.
    * 3A 2-6S 5V BEC
  * Sensors:
    * 5 Sharp GP2Y0A51SK0F  2-15 cm
    * ~~1 HMC6352 Compass (not Implemented yet)~~
    * ~~1 ADXL330K Acelerometer (not Implemented yet)~~
    
## Acknowledgements

* @Escornabot creators for the design and software www.escornabot.com https://github.com/escornabot
* Mike McCauley for the AccelStepper library.
* Julien de la Bruère-Terreault for the SharpDistSensor library. https://github.com/DrGFreeman
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

Fully working with left and right hand algorithms.

## Known issues

Software: None at this moment.

Hardware:
  * Sharp GP2Y0A51SK0F sensing range is too short for advancing more than one cell per movement.
  * 28BYJ-48 5V are too slow for a real micromouse maze and not as precise as they should.

## Todo

* Read IR Sensors -> DONE
* Control motors -> DONE
* ~~Center of maze detection~~ - > DEPRECATED
* Right hand algorithm -> DONE
* Left Hand algorithm -> DONE
* ~~Flood Algorithm~~ -> DEPRECATED
