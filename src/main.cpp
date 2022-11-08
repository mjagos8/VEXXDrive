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
// frontL               motor         9               
// backL                motor         10              
// frontR               motor         2               
// backR                motor         1               
// TopLimit             limit         H               
// BottomLimit          limit         G               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

using code = vision::code;

controller Controller1;
competition Competition;
brain brain;

// motor frontL = motor(PORT9, ratio18_1,false);
// motor backL = motor(PORT10, ratio18_1,false);
// motor frontR = motor(PORT2, ratio18_1,false);
// motor backR = motor(PORT1, ratio18_1,false);
motor flywheel = motor(PORT13, ratio18_1,false);
motor feeder = motor(PORT15, ratio18_1,false);
motor intake = motor(PORT14, ratio18_1,false);
bool feederdirection = true;
bool flywheelOn = false;
bool intakeOn = false;
bool endgameOn = false;

void userController(void) 
{
  Brain.Screen.clearScreen(); 
  while (1) 
  {
  
 int x = Controller1.Axis4.value();
 int y = Controller1.Axis3.value();
 
 
  backL.spin(vex::directionType::fwd, Controller1.Axis3.value() + Controller1.Axis1.value() + Controller1.Axis4.value(), vex::velocityUnits::pct);
  frontL.spin(vex::directionType::fwd, Controller1.Axis3.value() + Controller1.Axis1.value() - Controller1.Axis4.value(), vex::velocityUnits::pct);
  backR.spin(vex::directionType::rev, Controller1.Axis3.value() - Controller1.Axis1.value() - Controller1.Axis4.value(), vex::velocityUnits::pct);
  frontR.spin(vex::directionType::rev, Controller1.Axis3.value() - Controller1.Axis1.value() + Controller1.Axis4.value(), vex::velocityUnits::pct);

  //North East
  if (x > 25  && y > 25 ){
  backR.stop(brakeType::brake);
  frontL.stop(brakeType::brake);
  } 
  //South East
  else if (x > 25  && y < -25 ){
  backL.stop(brakeType::brake);
  frontR.stop(brakeType::brake);
  }
  //South West
  else if (y < -25 && x < -25){
  backR.stop(brakeType::brake);
  frontL.stop(brakeType::brake);
  }
  //North West
  else if (x < -25 && y > 25){
  backL.stop(brakeType::brake);
  frontR.stop(brakeType::brake);
  }



  

  if (Controller1.ButtonB.pressing()) 
  {
    if(feederdirection)
    {
      feeder.spin(directionType::rev, 100, velocityUnits::pct);
    }
    else
    {
      feeder.spin(directionType::fwd, 100, velocityUnits::pct);
    }
  }

if(TopLimit.value() == 1)
  {
    feederdirection = false;
  }
if(BottomLimit.value() == 1)
  {
    feederdirection = true;
  }
  



if( Controller1.ButtonY.pressing())
{
  if(intakeOn)
{
    intake.stop(brakeType::brake);
    intakeOn = false;
    wait(250, msec);

}
else{
    intake.spin(directionType::rev, 100, velocityUnits::pct);
  intakeOn = true;
  wait(250, msec);
}
}

if( Controller1.ButtonR1.pressing())
{
  if(flywheelOn)
{
    flywheel.stop(brakeType::brake);
    flywheelOn = false;
    wait(250, msec);

}
else{
    flywheel.spin(directionType::rev, 100, velocityUnits::pct);
  flywheelOn = true;
  wait(250, msec);
}

}

}

}




int main() {
  Competition.drivercontrol(userController);
 while (true){ // Genius by Nino
 wait(100, msec);
 }
}

