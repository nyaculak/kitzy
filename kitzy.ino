#include <Wire.h>

#include "PS2X_lib.h"
#include "RobotDrive.h"
#include "Ultrasonic.h"
#include "Gyro.h"
#include "PIDController.h"
#include "PID_v1.h"

double Setpoint, Input, Output;

double aggKp=4, aggKi=0.2, aggKd=1;
#define consKp 6
#define consKi .7
#define consKd .0000007

PS2X controller;
RobotDrive drive;
Ultrasonic ultrasonic(8);
Gyro gyro;
PIDController pid(.5, 0, 0, .01, 255, -255);
PID myPID(&Input, &Output, &Setpoint,consKp,consKi,consKd, DIRECT);

#define CLOCK 7
#define COMMAND 6
#define ATTENTION 5
#define DATA 4
#define PRESSURE false
#define RUMBLE false

#define greenled 2
#define redled 1

int controller_error = 0;
byte controller_type = 0;
byte controller_vibration = 0;

int lspeed = 0;
int rspeed = 0;

float distance;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  gyro.configure();
  
  Input = gyro.getZ();
  Setpoint = 90;
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(-255, 255);
  

  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);

  /*
  controller_error = controller.config_gamepad(CLOCK, COMMAND, ATTENTION, DATA, PRESSURE, RUMBLE);
   
   switch(controller_error) {
   case 0:
   Serial.println("Found controller, configured successfully");
   break;
   case 1:
   Serial.println("No controller found");
   break;
   case 2:
   Serial.println("Controller found, not accepting commands.  See README for debug");
   break;
   case 3:
   Serial.println("Controller refusing to enter pressure mode, may not support pressure");
   break;
   }
   
   controller_type = controller.readType();
   
   switch(controller_type) {
   case 0:
   Serial.println("Unknown Controller Type");
   break;
   case 1:
   Serial.println("DualShock Controller Found");
   break;
   case 2:
   Serial.println("GuitarHero Controller Found");
   break;
   }
   */

}

void loop() {

  Serial.print("Gyro:  ");
  Serial.println(gyro.getZ());

  /*
  controller.read_gamepad();
   
   // left = 0; right = 255
   // up = 0; down = 255;
   
   lspeed = controller.Analog(PSS_LY); // left = 0, right = 255
   rspeed = controller.Analog(PSS_RY);
   
   // make up = 255; down = 0;
   lspeed = map(lspeed, 0, 255, 255, 0);
   rspeed = map(rspeed, 0, 255, 255, 0);
   
   // map values -> -255 to 255
   lspeed = map(lspeed, 0, 255, -255, 255);
   rspeed = map(rspeed, 0, 255, -255, 255);
   
  /*
   Serial.println("Left: ");
   Serial.println(lspeed);
   Serial.println("Right: ");
   Serial.println(rspeed);
   */

  distance = ultrasonic.getDistance_in();

  /*
  if (distance <= 4) {
   digitalWrite(redled, HIGH);
   digitalWrite(greenled, LOW);
   }
   else {
   digitalWrite(redled, LOW);
   digitalWrite(greenled, HIGH);
   }
   */

  //Serial.print("Distance:  ");
  //Serial.println(distance);
  
  Input = gyro.getZ();
  
  int go = pid.run((float)gyro.getZ(), 90);
  
  myPID.Compute();
  
  //Serial.println(go);
  
  drive.tankDrive(Output * -1, Output);
  
  Serial.println(Output);

}



