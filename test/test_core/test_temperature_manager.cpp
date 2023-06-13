#include "unity.h"
#include "temperature_manager.hpp"

class MockSensor : public TemperatureSensor
{
public:
    MockSensor(float temp) { _temp = temp; }
    float getTemperatureCelcius() { return _temp; }

private:
    float _temp;
};

class MockHeater : public Heater
{
public:
    void enable() { _enabled = true; }
    void disable() { _enabled = false; }
    bool enabled() { return _enabled; }

private:
    bool _enabled = false;
};

void test_getAverageTemperature_returnsAverageTemperature()
{
    TemperatureManager manager;
    MockSensor sensor1(30.0f);
    MockSensor sensor2(20.0f);

    manager.addSensor(&sensor1);
    manager.addSensor(&sensor2);

    TEST_ASSERT_EQUAL_FLOAT(25.0f, manager.getAverageTemperature());
}

void test_getAverageTemperature_withoutSensors_returnsZero()
{
    TemperatureManager manager;

    TEST_ASSERT_EQUAL_FLOAT(0.0f, manager.getAverageTemperature());
}

void test_addSensor_addsSensor()
{
    TemperatureManager manager;
    MockSensor sensor(10.0f);

    TEST_ASSERT_EQUAL_INT16(0, manager.getSensorCount());

    manager.addSensor(&sensor);

    TEST_ASSERT_EQUAL_INT16(1, manager.getSensorCount());
}

void test_addHeater_addsHeater()
{
    TemperatureManager manager;
    MockHeater heater;

    TEST_ASSERT_EQUAL_INT16(0, manager.getHeaterCount());

    manager.addHeater(&heater);

    TEST_ASSERT_EQUAL_INT16(1, manager.getHeaterCount());
}

void runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(test_getAverageTemperature_returnsAverageTemperature);
    RUN_TEST(test_getAverageTemperature_withoutSensors_returnsZero);
    RUN_TEST(test_addSensor_addsSensor);
    RUN_TEST(test_addHeater_addsHeater);
    UNITY_END();
}

int main()
{
    runUnityTests();
}