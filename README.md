# Robot-project

This project consists of the development of a robot from scratch. The design started with the selection of all its components throw the software implementation. To allow the establishment of a starting point and gathering the indispensable knowledge for
the robot prototype development, initial research work has been carried out.

After researching and validating the solutions found, the prototype was assembled, and the required algorithms have been implemented. Finally, validation and functionalities check tests were performed to optimize the developed prototype. The autonomous movement of the robot, herein developed, is based on an anti-collision system, which allows the robot to navigate on a surface without human control.

The remote mode has been implemented through the design of a Web page connected to a server deployed into on the development board.

This replication package is structured as follows:

````
  /
  .
  |--- Images/             		The Figures used on the report, as a result of testing and the final prtotype.
  |--- robotCode/             All the code used to program the robot.
  |--- Robot_BThesis_EN       The final bachelor thesis report. Produced at the end of the project. 
```


### code 
---
```
  .
  |--- P117.ino                This is the main file
  |--- decision.ino            This file deals with all the code related with the decision on the way to go on auto mode.
  |--- distance.ino            This file deals with all the code related with getting the distance from the pulse returned by the sensor
  |--- motor.ino               This file deals with all the code related with the motors movements.
  |--- servidor.ino            This file deals with all the code related with the server
  |--- web_page.h              The web page created as the remote control
````
