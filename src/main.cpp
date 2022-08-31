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

motor frontL = motor(PORT14, ratio18_1,false);
motor backL = motor(PORT2, ratio18_1,false);
motor frontR = motor(PORT15, ratio18_1,false);
motor backR = motor(PORT1, ratio18_1,false);

void userController(void) 
{
  while (1) {

 int x = Controller.Axis4.value();
 int y = Controller.Axis3.value();

 int xy = (y + x);
 //int yx = (y - x);


    
  //North East (Probably doesnt work)
  if (x > 25  && y > 25 ){
  frontL.spin(directionType::fwd, (xy), percentUnits::pct);
  backR.spin(directionType::rev, (xy), percentUnits::pct);
  backL.stop(brakeType::brake);
  frontR.stop(brakeType::brake);
  } //South East
  else if (x > 25  && y < -25 ){
  backL.spin(directionType::fwd, (xy), percentUnits::pct);
  frontR.spin(directionType::rev, (xy), percentUnits::pct);
  backR.stop(brakeType::brake);
  frontL.stop(brakeType::brake);
  }
  //South West
  else if (y < -25 && x < -25){
    frontL.spin(directionType::fwd, (xy), percentUnits::pct);
    backR.spin(directionType::rev, (xy), percentUnits::pct);
    backL.stop(brakeType::brake);
    frontR.stop(brakeType::brake);
  }
  //North West
 else if (x < -25 && y > 25){
    frontR.spin(directionType::rev, (xy), percentUnits::pct);
    backL.spin(directionType::fwd, (xy), percentUnits::pct);
    backR.stop(brakeType::brake);
    frontL.stop(brakeType::brake);
  }//North
  else if ( y > 0 && x < 25 && x > -25){
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
