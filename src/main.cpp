/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Wed Sep 25 2019                                           */
/*    Description:  Speedbot (4-motor Drivetrain, No Gyro)                    */
/*                                                                            */
/*    Name:                                                                   */
/*    Date:                                                                   */
/*    Class:                                                                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 11, 2, 12   
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

using code = vision::code;

controller Controller;
competition Competition;
brain brain;

motor frontL = motor(PORT1, ratio18_1,false);
motor backL = motor(PORT13, ratio18_1,false);
motor frontR = motor(PORT2, ratio18_1,false);
motor backR = motor(PORT12, ratio18_1,false);

void userController(void) 
{
  while (1) {

 int x = Controller.Axis4.value();
 int y = Controller.Axis3.value();

 int xy = (y + x);
 //int yx = (y - x);


    //North
  if (Controller.Axis3.value() > 0 && Controller.Axis4.value() < 25 && Controller.Axis4.value() > -25 ){
  frontL.spin(directionType::fwd, (xy), percentUnits::pct);
  frontR.spin(directionType::rev, (xy), percentUnits::pct);
  backL.spin(directionType::fwd, (xy), percentUnits::pct);
  backR.spin(directionType::rev, (xy), percentUnits::pct);
  }//East
  else if (Controller.Axis4.value() > 0 && Controller.Axis3.value() < 25  && Controller.Axis3.value() > -25 ){
  frontL.spin(directionType::fwd, (xy), percentUnits::pct);
  backL.spin(directionType::rev, (xy), percentUnits::pct);
  backR.spin(directionType::rev, (xy), percentUnits::pct);
  frontR.spin(directionType::fwd, (xy), percentUnits::pct);
  }//South
  else if (Controller.Axis3.value() < 0 && Controller.Axis4.value() < 25 && Controller.Axis4.value() > -25 ){
  frontL.spin(directionType::fwd, (xy), percentUnits::pct);
  frontR.spin(directionType::rev, (xy), percentUnits::pct);
  backL.spin(directionType::fwd, (xy), percentUnits::pct);
  backR.spin(directionType::rev, (xy), percentUnits::pct);
  }//West
  else if (Controller.Axis4.value() < 0 && Controller.Axis3.value() < 25  && Controller.Axis3.value() > -25 ){
  frontL.spin(directionType::fwd, (xy), percentUnits::pct);
  backL.spin(directionType::rev, (xy), percentUnits::pct);
  backR.spin(directionType::rev, (xy), percentUnits::pct);
  frontR.spin(directionType::fwd, (xy), percentUnits::pct);
  }//North East (Probably doesnt work)
  else if (Controller.Axis3.value() > 0 && Controller.Axis4.value() < 75 && Controller.Axis4.value() > 25 ){
  frontL.spin(directionType::fwd, (xy), percentUnits::pct);
  backR.spin(directionType::rev, (xy), percentUnits::pct);
  }
else {
frontL.stop(brakeType::brake);
frontR.stop(brakeType::brake);
backL.stop(brakeType::brake);
backR.stop(brakeType::brake);
}
  }
  }



int main() {
  Competition.drivercontrol(userController);
 while (true){
 wait(100, msec);
 }
}
