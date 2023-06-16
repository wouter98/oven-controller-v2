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

class MockTimeProvider : public TimeProvider
{
public:
    long getTimeMillis() { return _timeToReturn; }
    void setTimeToReturn(long timeToReturn) { _timeToReturn = timeToReturn; }

private:
    long _timeToReturn;
};

class MockPIDController : public PIDController
{
public:
    float calculateOutput(float setpoint, float input) { return _outputValue; }
    void setOutputValue(float outputValue) { _outputValue = outputValue; }

private:
    float _outputValue;
};

void test_addTemperatureSensor_addsTemperatureSensor()
{
    MockTimeProvider timeProvider;
    MockPIDController pidController;

    TemperatureManager manager(&timeProvider, &pidController);
    MockSensor sensor(10.0f);

    TEST_ASSERT_EQUAL_INT16(0, manager.getTemperatureSensorCount());

    manager.addTemperatureSensor(&sensor);

    TEST_ASSERT_EQUAL_INT16(1, manager.getTemperatureSensorCount());
}

void test_getAverageTemperature_returnsAverageTemperature()
{
    MockTimeProvider timeProvider;
    MockPIDController pidController;

    TemperatureManager manager(&timeProvider, &pidController);
    MockSensor sensor1(30.0f);
    MockSensor sensor2(20.0f);

    manager.addTemperatureSensor(&sensor1);
    manager.addTemperatureSensor(&sensor2);

    TEST_ASSERT_EQUAL_FLOAT(25.0f, manager.getAverageTemperature());
}

void test_getAverageTemperature_withoutSensors_returnsZero()
{
    MockTimeProvider timeProvider;
    MockPIDController pidController;

    TemperatureManager manager(&timeProvider, &pidController);

    TEST_ASSERT_EQUAL_FLOAT(0.0f, manager.getAverageTemperature());
}

void test_addHeater_addsHeater()
{
    MockTimeProvider timeProvider;
    MockPIDController pidController;

    TemperatureManager manager(&timeProvider, &pidController);
    MockHeater heater;

    TEST_ASSERT_EQUAL_INT16(0, manager.getHeaterCount());

    manager.addHeater(&heater);

    TEST_ASSERT_EQUAL_INT16(1, manager.getHeaterCount());
}

void test_updateHeater_withHighPidOutput_turnsOnHeater()
{
    MockTimeProvider timeProvider;
    MockPIDController pidController;

    pidController.setOutputValue(200);

    TemperatureManager manager(&timeProvider, &pidController);
    MockHeater heater;

    heater.disable();
    manager.addHeater(&heater);

    TEST_ASSERT_FALSE(heater.enabled());

    manager.updateHeater(200);

    TEST_ASSERT_TRUE(heater.enabled());
}

void test_updateHeater_withLowPidOutput_turnsOffHeater()
{
    MockTimeProvider timeProvider;
    MockPIDController pidController;

    pidController.setOutputValue(20);

    TemperatureManager manager(&timeProvider, &pidController);
    MockHeater heater;

    heater.enable();
    manager.addHeater(&heater);

    TEST_ASSERT_TRUE(heater.enabled());

    manager.updateHeater(200);

    TEST_ASSERT_FALSE(heater.enabled());
}

void runUnityTests()
{
    UNITY_BEGIN();

    RUN_TEST(test_addTemperatureSensor_addsTemperatureSensor);
    RUN_TEST(test_getAverageTemperature_returnsAverageTemperature);
    RUN_TEST(test_getAverageTemperature_withoutSensors_returnsZero);

    RUN_TEST(test_addHeater_addsHeater);
    RUN_TEST(test_updateHeater_withHighPidOutput_turnsOnHeater);
    RUN_TEST(test_updateHeater_withLowPidOutput_turnsOffHeater);

    UNITY_END();
}

int main()
{
    runUnityTests();
}