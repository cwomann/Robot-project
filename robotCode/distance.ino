/**********************
 * This code was writen by Carolina Neves for the project: P117
 * Date: 23 November 2020
 * 
 * This file deals with all the code related with getting the distance 
 * from the pulse returned by the sensor
 */

#define SPEED_OF_SOUND 0.0343 // speed sound = 343 m/s and 0.0343 cm/us
#define COMPENSATION_ERROR 1 // the error correction found during the tests

long  distanceValue; // this variable keeps the distance calculated


/******************************************************
 * getDistance - it returns the distance of the object 
 * standing in the way.
 ******************************************************/
long getDistance (){
  return distanceValue + COMPENSATION_ERROR; //the distance calculated plus the compensation
}

/******************************************************
 * distance - it sends and recives a pulse through the 
 * sensor to calculate the distance of the object.
 * And it stores the distance in the variable distanceValue
 ******************************************************/
void distance(){
  long duration; // a local variable that stores the duration os the pulse
  digitalWrite(TRIGGER, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(TRIGGER, HIGH); // sends the pulse
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGER, LOW);
  
  duration = pulseIn(ECHO, HIGH); // returns the length of the pulse in microseconds
  distanceValue = (duration * SPEED_OF_SOUND) / 2; // stores the distance -> speed sound in cm/s; it's devided by 2 because it's the 2 ways the pulse makes
  
}
