// Motor definitions
#define HALFSTEP 8
#define NUM_SENSORS 5
#define STEPS_PER_CELL 2000
#define STEPS_FROM_EDGE_TO_CENTER 2000
#define STEPS_TO_TURN_90_DEG 2000
#define STEPS_TO_TURN 2000
#define SPEED 1000
#define MAX_SPEED 1000.0
#define ACELERATION 100.0


#define motor1Pin1 2 // IN1 on the ULN2003 driver 1
#define motor1Pin2 3 // IN2 on the ULN2003 driver 1
#define motor1Pin3 4 // IN3 on the ULN2003 driver 1
#define motor1Pin4 5 // IN4 on the ULN2003 driver 1

#define motor2Pin1 6 // IN1 on the ULN2003 driver 2
#define motor2Pin2 7 // IN2 on the ULN2003 driver 2
#define motor2Pin3 8 // IN3 on the ULN2003 driver 2
#define motor2Pin4 9 // IN4 on the ULN2003 driver 2

// Analog pins to which the IR sensors are connected
const byte sensorPin[5] = { A0, A1, A2, A3, A4 };

