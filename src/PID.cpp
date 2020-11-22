#include <algorithm>
#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  previous_cte = 0.0;
  error_count = 0;
  sum_error = 0.0;
  min_error = std::numeric_limits<double>::max();
  max_error = std::numeric_limits<double>::min();
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  // derivative error is diff of current cte and proportional error
  d_error = cte - p_error;
  // integration error is total so far
  i_error += cte;
  // proportional error is current cte
  p_error = cte;
  
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  double total_error = -(Kp * p_error + Kd * d_error + Ki * i_error);
  return total_error;
}

double PID::MaxError() {
  return max_error;
}

double PID::MinError() {
  return min_error;  
}

double PID::AverageError() {
  return sum_error/error_count;
}