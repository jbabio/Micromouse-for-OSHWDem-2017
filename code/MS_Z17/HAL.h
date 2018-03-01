// General pin assignment
#define led1          12    // Yellow
#define led2          12    // Green
// Analog pins where the IR sensors are connected
const byte sensorPin[5] = { A0, A1, A2, A3, A4 }; //SL,FL,FR,SR,B
// BUTTONS
  const int buttonPin = A7;     // the number of the pushbutton pin
  const int NUM_BUTTONS = 5;
  const int BUTTON[5] = { 1, 2, 3, 4, 5 };
  const int BUTTONTHRESHOLDLOW[5] = { 848, 814, 763, 677, 506 };
  const int BUTTONTHRESHOLDHIGH[5] = { 858, 824, 773, 687, 516 };
// buzzer
#define USE_BUZZER true
#define BUZZER_PIN 11
#define PROGRAM_FINISHED_RTTL RTTL_FIDO


// Motor definitions
//CONSTANTS
  const int HALFSTEP = 8;
  const int NUM_SENSORS = 5;

#define motor1Pin1 7 // IN1 on the ULN2003 driver 1 2
#define motor1Pin2 6 // IN2 on the ULN2003 driver 1 3
#define motor1Pin3 5 // IN3 on the ULN2003 driver 1 4
#define motor1Pin4 4 // IN4 on the ULN2003 driver 1 5

#define motor2Pin1 13 // IN1 on the ULN2003 driver 2 6
#define motor2Pin2 10 // IN2 on the ULN2003 driver 2 7
#define motor2Pin3 9 // IN3 on the ULN2003 driver 2 8
#define motor2Pin4 8 // IN4 on the ULN2003 driver 2 9

//VARIABLES
float speed = 1000;                                            // speed 1000
float maxSpeed = 1500;                                         // Max speed 1000
float acceleration = 100;                                   // Acceleration 1000000
const float pi = 3.1416;
float wheelDiameter = 74.6;                           // Wheel Diameter
float wheelRadius = wheelDiameter/2;                  // Wheel Radius
float wheelPerimeter = 2*pi*wheelRadius;              // Distance travelled by the wheel to do a complete turn 
float botWidth = 77;                               // Diameter of a theoretic turn circle
float botRadius = botWidth/2;
float fullTurnCircumference = 2*pi*botRadius;         // Distance travelled by the bot to do a 360 turn 
float fullTurn = fullTurnCircumference;
float halfTurn = fullTurn/2;                          // Distance travelled by the bot to do a 360 turn 
float quarterTurn = fullTurn/4;                       // Distance travelled by the bot to do a 360 turn 
long  stepsPerRevolution = 2048;                              // Number of steps per output shaft revolution.
float stepsPerMillimeter = stepsPerRevolution/wheelPerimeter; // Number of steps per millimeter calculated from wheelDiameter and stepsPerRevolution

int cellLengt = 180; // Cell lengt in millimeters.
float rearGapAtStart = 25; // Gap between back bumper and wall at start in millimeters.

// This values are calculated
//float stepsPerMillimeter = 9; // Number of steps per millimeter calculated from wheelDiameter and stepsPerRevolution


