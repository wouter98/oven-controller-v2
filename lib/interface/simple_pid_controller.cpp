#include "simple_pid_controller.hpp"

SimplePIDController::SimplePIDController(float kP, float kI, float kD)
    : _pid(kP, kI, kD, 0, 255)
{
}

float SimplePIDController::calculateOutput(float setpoint, float input)
{
    _pid.setSetpoint(setpoint);

    return _pid.calculate(input);
}