#include "ssr_heater.hpp"

SSRHeater::SSRHeater(int pin)
    : _pin(pin)
{
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);

    
}

void SSRHeater::setPower(float power)
{
    _power = power;
}

float SSRHeater::getPower()
{
    return _power;
}