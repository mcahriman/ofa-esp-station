#include <unity.h>
#include "device/Example/SampleDriver.hpp"

void test_default_constructor() {
    const char* name = "MyFirstTest";
    SampleDriver *sampleDriver = new SampleDriver(name);
    TEST_ASSERT_EQUAL(name, sampleDriver->getName);
}