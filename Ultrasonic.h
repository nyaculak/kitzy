#ifndef Ultrasonic_h
#define Ultrasonic_h

#if ARDUINO > 22
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <math.h>

class Ultrasonic {
public:
  Ultrasonic(int pingPin);
  long getDistance_in();
  long getDistance_cm();
private:
  int pingPin;
  long getDuration();
};
#endif
