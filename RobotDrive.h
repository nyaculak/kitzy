/*
	Simple Class designed to work with the Ardumoto
	Motor Shield available from http://www.sparkfun.com/
	Should be able to be ported to similar shields
	without too much change in code

	Released under GNU GPL v. 3 or later
	Latest version (git) is available at
	http://www.github.com/erhs-53-hackers/Ardumoto/
	
*/

#ifndef RobotDrive_h
#define RobotDrive_h

#if ARDUINO > 22
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <math.h>

#define left_speed 3
#define left_dir 12
#define right_speed 11
#define right_dir 13

#define FORWARD 1
#define BACKWARD 0

class RobotDrive {
public:
  RobotDrive();
  void tankDrive(int leftVal, int rightVal);
  void arcadeDrive(int moveVal, int rotateVal);
private:
  bool isLeftInverted;
  bool isRightInverted;
};

#endif
