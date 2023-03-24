/**********************
 * This code was writen by Carolina Neves for the project: P117
 * Date: 23 November 2020
 * 
 * This file deals with all the code related with the decision on 
 * the way to go on auto mode.
 */

#define DEGRES_90 500 // time to turn aprox. 90 degrees

int state; // this variable keeps the state of the decision
unsigned long millisTemp; // this variable stores the initial time for the timer

/*******************************************************************
 * movementDecision - it implements the flowchart created
 * it returns the decision that was made.
 * 
 * This function considers the possibility that objects can no apear 
 * from nowhere. Whitch means that if the robot took a certain path 
 * it can go on that same path again.
 *******************************************************************/
int movementDecision(){
  switch(state){
    case STOP: //turns right to avaluate the distance
      state = FRONT;
      break;
    case FRONT: // when it first finds an object
      if (getDistance() > DISTANCE_TO_DODGE){ //object not found
        state = FRONT;
      }
      else // object found
        state = FRONT_STOP;
      break; 
        
    case FRONT_STOP: //turns right to avaluate the distance
      millisTemp = millis() + DEGRES_90; //starts timer
      state = ROTATE_RIGHT_90_START;
      break; 
      
    case ROTATE_RIGHT_90_START: //turns right to avaluate the distance
      if(millis() > millisTemp){
        if (getDistance() > DISTANCE_TO_DODGE){ //object not found
          state = FRONT;
        }
        else // object found
          state = ROTATE_RIGHT_90_EXEC;
      }
      break;
      
    case ROTATE_RIGHT_90_EXEC: //turns left to avaluate the distance
      millisTemp = millis() + DEGRES_90*2; // starts timer to turn 180 = 90*2
      state = ROTATE_LEFT_180_START;
      break;
      
    case ROTATE_LEFT_180_START: //turns right to avaluate the distance
      if(millis() > millisTemp)
        if (getDistance() > DISTANCE_TO_DODGE){ //object not found
          state = FRONT;
        }
        else // object found
          state = ROTATE_LEFT_180_EXEC;
      break;   
      
    case ROTATE_LEFT_180_EXEC: //turns left to avaluate the distance
      millisTemp = millis() + DEGRES_90; // starts timer to turn 90
      state = ROTATE_LEFT_90_START;
      break; 
      
    case ROTATE_LEFT_90_START: //turns right to avaluate the distance
      if(millis() > millisTemp){
        state = FRONT;
      }
      break;
  }  
  return state; 
}
