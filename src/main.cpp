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

controller Controller1;
competition Competition;
brain brain;

motor frontL = motor(PORT14, ratio18_1,false);
motor backL = motor(PORT2, ratio18_1,false);
motor frontR = motor(PORT15, ratio18_1,false);
motor backR = motor(PORT1, ratio18_1,false);

void userController(void) 
{
  while (1) 
  {

 int x = Controller1.Axis4.value();
 int y = Controller1.Axis3.value();
 
  backL.spin(vex::directionType::fwd, Controller1.Axis3.value() + Controller1.Axis1.value() - Controller1.Axis4.value(), vex::velocityUnits::pct);
  frontL.spin(vex::directionType::fwd, Controller1.Axis3.value() + Controller1.Axis1.value() + Controller1.Axis4.value(), vex::velocityUnits::pct);
  backR.spin(vex::directionType::rev, Controller1.Axis3.value() - Controller1.Axis1.value() + Controller1.Axis4.value(), vex::velocityUnits::pct);
  frontR.spin(vex::directionType::rev, Controller1.Axis3.value() - Controller1.Axis1.value() - Controller1.Axis4.value(), vex::velocityUnits::pct);

  //North East
  if (x > 25  && y > 25 ){
  backL.stop(brakeType::brake);
  frontR.stop(brakeType::brake);
  } 
  //South East
  else if (x > 25  && y < -25 ){
  backR.stop(brakeType::brake);
  frontL.stop(brakeType::brake);
  }
  //South West
  else if (y < -25 && x < -25){
  backL.stop(brakeType::brake);
  frontR.stop(brakeType::brake);
  }
  //North West
  else if (x < -25 && y > 25){
  backR.stop(brakeType::brake);
  frontL.stop(brakeType::brake);
  }

  }
}

int main() {
  Competition.drivercontrol(userController);
 while (true){
 wait(100, msec);
 }
}
