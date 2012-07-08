#include "RobotDrive.h"

#include <math.h>

#if ARDUINO > 22
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

RobotDrive::RobotDrive() {
  pinMode(left_dir, OUTPUT);
  pinMode(right_dir, OUTPUT);
  pinMode(left_speed, OUTPUT);
  pinMode(right_speed, OUTPUT);
}

void RobotDrive::tankDrive(int leftVal, int rightVal) {
  if (leftVal < 0 ) {
    leftVal = abs(leftVal);
    digitalWrite(left_dir, BACKWARD);
    analogWrite(left_speed, leftVal);
  } else {
    digitalWrite(left_dir, FORWARD);
    analogWrite(left_speed, leftVal);
  }
  if (rightVal < 0) {
     rightVal = abs(rightVal);
     digitalWrite(right_dir, BACKWARD);
     analogWrite(right_speed, rightVal);
  } else {
    digitalWrite(right_dir, FORWARD);
    analogWrite(right_speed, rightVal);
  }
}
    

