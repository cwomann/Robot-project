/**********************
 * This code was writen by Carolina Neves for the project: P117
 * Date: 23 November 2020
 * 
 */

#include <ESP8266WebServer.h>

/*********************************
 *      MACROS AND VARIABLES
 *********************************/
#define TRIGGER 0 // gpio sonar trigger
#define ECHO 2 // gpio sonar echo 

// Description of all the states and motions
#define STOP 0
#define FRONT 1
#define BACK 2
#define RIGHT 3
#define LEFT 4
#define FRONT_STOP 11
#define ROTATE_RIGHT_90_START 5
#define ROTATE_RIGHT_90_EXEC 6
#define ROTATE_LEFT_90_START 7
#define ROTATE_LEFT_90_EXEC 8
#define ROTATE_LEFT_180_START 9
#define ROTATE_LEFT_180_EXEC 10

// remote or auto control flag
#define AUTO 1
#define REMOTE 0

#define DISTANCE_TO_DODGE 15 // the maximum distance in cm

#define NUMBER_OF_MOTORS 2 // number of motors

//uint8_t pwm1 = 5; //Nodemcu PWM pin 
//uint8_t pwm2 = 4; //Nodemcu PWM pin
int motor[] = {14, 12, 13, 15}; // motors pins

//                            {{  STOP  },{  FOARD  }, {  BACK   }, {  RIGHT  }, {  LEFT  }}
int direction__motor1[7][2] = {{LOW, LOW},{HIGH, LOW}, {LOW, HIGH}, {HIGH, LOW}, {LOW, HIGH}}; // LEFT MOTOR
int direction__motor2[7][2] = {{LOW, LOW},{HIGH, LOW}, {LOW, HIGH}, {LOW, HIGH}, {HIGH, LOW}}; // RIGHT MOTOR
int decision = 0
; // this variable stores the movement


ESP8266WebServer server(80); // this is the server port


/*********************************
 *            CODE
 *********************************/

void setup() {
  Serial.begin(9600);
  Serial.println();

  // Declaring Sonar pins
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  
  //Declaring l293d control pins as Output (motor pins)
  for (int i = 0; i < 4; i++){
      pinMode(motor[i], OUTPUT);      
  }
  serverSetUp(); // this funtion does the server setup
}

void loop() {
  server.handleClient(); //Handling of incoming client requests

  if (getTypeControl() == AUTO){ // avaliates if it's on auto mode
    distance();
    decision = movementDecision();
  }
  rolling(decision, HIGH); // implements the movement
}
