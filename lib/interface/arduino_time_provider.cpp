#include "arduino_time_provider.hpp"

long ArduinoTimeProvider::getTimeMillis()
{
    return millis();
}