#include "ssr_heater.hpp"

SSRHeater::SSRHeater(int pin)
    : _pin(pin)
{
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
}

void SSRHeater::enable()
{
    digitalWrite(_pin, HIGH);
}

void SSRHeater::disable()
{
    digitalWrite(_pin, LOW);
}

bool SSRHeater::enabled()
{
    return digitalRead(_pin);
}
