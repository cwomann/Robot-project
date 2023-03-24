/**********************
 * This code was writen by Carolina Neves for the project: P117
 * Date: 23 November 2020
 * 
 * This file deals with all the code related with the motors 
 * movements.
 */

/******************************************************
 * rolling - this funcion recives the direction that the 
 * motors are suposed to rotate and the velocity (so it 
 * can be altered with PWM in the future.
 ******************************************************/
void rolling(int diretion, bool velocity){
    switch(diretion){
      case ROTATE_RIGHT_90_START:
        diretion = RIGHT;
        break;
      case ROTATE_RIGHT_90_EXEC:
        diretion = STOP;
        break;
      case ROTATE_LEFT_180_START:
        diretion = LEFT;
        break;
      case ROTATE_LEFT_180_EXEC:
        diretion = STOP;
        break;
      case ROTATE_LEFT_90_START:
        diretion = LEFT;
        break;
      case FRONT_STOP:
        diretion = STOP;
        break;
    }
    
    for(int i = 0; i < NUMBER_OF_MOTORS; i++){
      motorSetUp(diretion, i, velocity); 
      delay(100);      
    } 
    //digitalWrite(pwm1, velocity); //pwm output
    //digitalWrite(pwm2, velocity); //pwm output
}

/******************************************************
 * motorSetUp - it recives the direction the motor is 
 * suposed to rotate(direction); the number of the motor 
 * implement (number_of_motor) and the velocity (so it 
 * can be altered with PWM in the future (velocity).
 * 
 * This puts the digital value in each terminal of the 
 * motor passed by parameter.
 ******************************************************/
void motorSetUp(int diretion, int number_of_motor, bool velocity){
  if (number_of_motor == 0){ //inicia o primeiro motor
    for(int i = 0; i < 2; i++){ // the 2 are the number of terminals the motor has
      digitalWrite(motor[i], direction__motor1[diretion][i]); 
    }
  }
  if (number_of_motor == 1){ //inicia o segundo motor
    for(int i = 0; i < 2; i++){ // the 2 are the number of terminals the motor has
      digitalWrite(motor[i+2], direction__motor2[diretion][i]); // +2 is so itimplements the right motor on the array
    }
  }
}
