#include "unity.h"
#include "timer.hpp"

class MockTimeProvider : public TimeProvider
{
public:
    MockTimeProvider(long timeToReturn) { _timeToReturn = timeToReturn; }
    void setTimeToReturn(long timeToReturn) { _timeToReturn = timeToReturn; }
    long getTimeMillis() { return _timeToReturn; }

private:
    long _timeToReturn;
};

void test_createTimer_hasCorrectInterval()
{
    MockTimeProvider timeProvider(0);
    Timer timer(&timeProvider, 1000);

    TEST_ASSERT_EQUAL_INT64(1000, timer.getIntervalMilliseconds());
}

void test_createTimer_createsRepeatingTimer()
{
    MockTimeProvider timeProvider(0);
    Timer timer(&timeProvider, 1000);

    TEST_ASSERT_TRUE(timer.isRepeating());
    TEST_ASSERT_FALSE(timer.isTriggered());

    timeProvider.setTimeToReturn(1000);

    TEST_ASSERT_TRUE(timer.isTriggered());
    TEST_ASSERT_FALSE(timer.isTriggered());

    timeProvider.setTimeToReturn(2000);

    TEST_ASSERT_TRUE(timer.isTriggered());
}

void test_createNonRepeatingTimer_createsNonRepeatingTimer()
{
    MockTimeProvider timeProvider(0);
    Timer timer(&timeProvider, 1000, false);

    TEST_ASSERT_FALSE(timer.isRepeating());
    TEST_ASSERT_FALSE(timer.isTriggered());

    timeProvider.setTimeToReturn(1000);

    TEST_ASSERT_TRUE(timer.isTriggered());
    TEST_ASSERT_FALSE(timer.isTriggered());

    timeProvider.setTimeToReturn(2000);

    TEST_ASSERT_FALSE(timer.isTriggered());
}

int main()
{ 
    UNITY_BEGIN();
    RUN_TEST(test_createTimer_hasCorrectInterval);
    RUN_TEST(test_createTimer_createsRepeatingTimer);
    RUN_TEST(test_createNonRepeatingTimer_createsNonRepeatingTimer);
    UNITY_END();
}