/**********************
 * This code was writen by Carolina Neves for the project: P117
 * Date: 23 November 2020
 * 
 * This file deals with all the code related with the server
 */

/*********************************
 *      MACROS AND VARIABLES
 *********************************/
#include "web_page.h"

String accessName = "p107";
// wifi's pass and id
//const char *ssid = "TP-Link_DAF2";
//const char *password = "37481735";
const char *ssid = "NOS-BED0"; //192.168.1.7
const char *password = "5ab74797f6aa";

String id_btn; // it stores the id of the button pressed
int  control_type = 0; // flag that says if it's on auto or remote mode

/*********************************
 *            CODE
 *********************************/

/******************************************************
 * serverSetUp - it implements the server
 ******************************************************/
void serverSetUp(){
  // Connect to WiFi network
  WiFi.begin(ssid, password); // it gives the id and pass to the board

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED){ // it checks the status
    delay(500);
    Serial.print(".");
  }

  Serial.println("success!"); // it conected succesfully
  Serial.print("WiFi connected to: ");
  Serial.println(WiFi.SSID()); // prints the id
  Serial.print("IP Address is: ");
  Serial.println(WiFi.localIP()); // Will print IP address

  server.on("/", handleIndex); //Handle Index page
  server.on("/control", HTTP_GET, remoteControl); // it sets the hangle, the request http GET and it gives the fuction to be redirected to
  
  server.begin(); //Start the server
  Serial.println("Server listening"); //waits for a client
}

/******************************************************
 * handleIndex - it return the OK whet it recives the get 
 * request.
 ******************************************************/
void handleIndex(){
  server.send(200, "text/html", control_page); // it returs the OK
}

/******************************************************
 * remoteControl - this function  controls the type of 
 * mode (remote or auto). It gets the pressed button and 
 * avaluates the button assigning it a decision
 ******************************************************/
void remoteControl(){
  id_btn = server.arg("control");//recive the parameter of function and returns teh pressed button
  // it assigns a value to the flag
  if(id_btn == "AUTO")
    control_type = AUTO;
  else if(id_btn != "AUTO")
    control_type = REMOTE;
  // it assigns a value to the decision
  if (control_type == REMOTE){
    if(id_btn == "FWD")
      decision = FRONT;
    else if(id_btn == "LFT")
      decision = LEFT;
    else if(id_btn == "STP")
      decision = STOP;
    else if(id_btn == "RGT")
      decision = RIGHT;
    else if(id_btn == "REV")
      decision = BACK;  
  }
  server.send(200, "OK"); // sends the OK
}

/******************************************************
 * getTypeControl - it returns the mode type
 ******************************************************/
int getTypeControl(){
  return control_type;
}
