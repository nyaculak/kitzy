#include "PIDController.h"

#include <Arduino.h>

PIDController::PIDController(float kp, float ki, float kd, float max_error, float min, float max) {
  this->kp = kp; this->ki = ki; this->kd = kd;
  this->min_error = min_error; this->min = min; this->max = max;
};

void PIDController::setConstants(float kp, float ki, float kd) {
  this->kp = kp; this->ki = ki; this->kd = kd;
}

float PIDController::run(float currentVal, float targetVal) {
  int err;
  int delta_err;
  int p_out;
  int i_out;
  int d_out;
  int output;
  
  err = targetVal - currentVal;
  delta_err = prev_err - err;
  
  if (abs(err) > this->min_error) {
    integral_err +=err;
  }
  
  /*
  if (integral_err > this->max_error) {
    integral_err = max_error;
  }
  else if (integral_err < abs(max_error)) {
    integral_err = max_error * -1;
  }
  */
  
  p_out = err * this->kp;
  i_out = integral_err * this->ki;
  d_out = delta_err * this->kd;
  
  output = p_out + i_out + d_out;
  
  if (output > this->max) {
    output = this->max;
  }
  else if (output < this->min) {
    output = this->min;
  }
  
  this->prev_err = err;
  
  return output;
  
}
  
