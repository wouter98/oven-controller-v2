#include <Arduino.h>

#include "config.hpp"
#include "temperature_manager.hpp"
#include "max6675_temperature_sensor.hpp"
#include "ssr_heater.hpp"
#include "arduino_time_provider.hpp"
#include "simple_pid_controller.hpp"

ArduinoTimeProvider timeProvider;

SimplePIDController pidController(PID_KP, PID_KI, PID_KD);

TemperatureManager manager(&timeProvider, &pidController);

Max6675TemperatureSensor sensor1(CLK_PIN, TEMP_SENSOR_1_PIN, MISO_PIN);
Max6675TemperatureSensor sensor2(CLK_PIN, TEMP_SENSOR_2_PIN, MISO_PIN);

SSRHeater heater(HEATER_PIN);

void setup()
{
    Serial.begin();

    sleep(2);
    
    Serial.print("Running on thread: " );
    Serial.println(xPortGetCoreID());

    manager.addTemperatureSensor(&sensor1);
    manager.addTemperatureSensor(&sensor2);
    manager.addHeater(&heater);
}

void loop()
{
    Serial.print("Average Temperature: ");
    Serial.print(manager.getAverageTemperature());
    Serial.println("c");

    Serial.print("Heater status: ");
    Serial.println(heater.enabled());

    // manager.updateHeater(60);

    sleep(1);
}
