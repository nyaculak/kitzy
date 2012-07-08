#include "Ultrasonic.h"

#include <math.h>

#if ARDUINO > 22
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

Ultrasonic::Ultrasonic(int pingPin) {
  this->pingPin = pingPin;
}

long Ultrasonic::getDuration() {
  pinMode(this->pingPin, OUTPUT);
  digitalWrite(this->pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(this->pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(this->pingPin, LOW);
  
  pinMode(pingPin, INPUT);
  return pulseIn(this->pingPin, HIGH);
}

long Ultrasonic::getDistance_in() {
  return this->getDuration() / 74 / 2;
}

long Ultrasonic::getDistance_cm() {
  return this->getDuration() / 29 / 2;
}
