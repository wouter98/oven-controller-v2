#pragma once

#include "pid_controller.hpp"
#include "pidcontroller.h"

class SimplePIDController : public PIDController
{
public:
    SimplePIDController(float kP, float kI, float kD);
    float calculateOutput(float setPoint, float input);

private:
    PID _pid;
};