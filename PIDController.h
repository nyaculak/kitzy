#ifndef PIDController_h
#define PIDController_h

#include <Arduino.h>
#include <math.h>

class PIDController {
public:
  PIDController(float kp, float ki, float kd, 
                float min_error, float max, float min);
  void setConstants(float kp, float ki, float kd);
  float run(float currentVal, float targetVal);
  void stop();
private:
  float kp, ki, kd;
  float min_error, max, min;
  int integral_err, prev_err;
};
#endif

