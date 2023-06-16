#pragma once

class PIDController {
public:
    virtual float calculateOutput(float setpoint, float input) = 0;
};