#include <Arduino.h>
#include "SampleDriver.hpp"
#include "device/BaseCapability.hpp"
#include <memory>

#define SAMPLE_CAP "WOOF"

bool SampleDriver::isOnline() {
    //Woof Driver is always online
    return true;
}

String SampleDriver::getName() {
    return deviceName;
}

String SampleDriver::getSomeValue() {
    doSomeSampleMagic();
    return "woof woof";
}


String SampleDriver::getSomeAnotherValue() {
    return "Ktulkhu fhtagn";
}

void SampleDriver::doSomeSampleMagic() {
    Serial.println("BOO WOO CAPABILITY MAGIC HAS OCCURED\n");
    Serial.println("Behold the serial writer you have invoked\n");
}    

SampleDriver::SampleDriver(String name) {
    deviceName = name;
    getWoofValueDelegate = [this] { return this->getSomeValue(); };
    getKtulhuFhtagnDelegate = [this] { return this->getSomeAnotherValue(); };
    driverOnlineDelegate = [this] { return this->isOnline(); };
    capabilities.registerCapability(new BaseCapability("WoofValue", getWoofValueDelegate, driverOnlineDelegate));
    capabilities.registerCapability(new BaseCapability("FhthagnVal", getKtulhuFhtagnDelegate, driverOnlineDelegate));
}
