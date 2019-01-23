#include <Arduino.h>
#include "SampleDriver.hpp"
#include "device/BaseCapability.hpp"

#define SAMPLE_CAP "WOOF"

bool SampleDriver::isOnline() {
    //Woof Driver is always online
    return true;
}

String SampleDriver::getName() {
    return capabilityName;
}

String SampleDriver::getValue() {
    doSomeSampleMagic();
    return "woof woof";
}

void SampleDriver::doSomeSampleMagic() {
    Serial.println("BOO WOO CAPABILITY MAGIC HAS OCCURED\n");
    Serial.println("Behold the serial writer you have invoked\n");
}    

SampleDriver::SampleDriver(String name) {
    deviceName = name;
    getWoofValueDelegate = [this] { return this->getValue(); };
    driverOnlineDelegate = [this] { return this->isOnline(); };
    capabilities.push_back(new BaseCapability("WoofValue", getWoofValueDelegate, driverOnlineDelegate));
}
