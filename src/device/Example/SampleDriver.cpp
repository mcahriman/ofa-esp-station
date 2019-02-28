#include <string>
#include <memory>

#include "SampleDriver.hpp"
#include "device/BaseCapability.hpp"

#define SAMPLE_CAP "WOOF"

bool SampleDriver::isOnline() {
    //Woof Driver is always online
    return true;
}

string SampleDriver::getName() {
    return capabilityName;
}

string SampleDriver::getValue() {
    doSomeSampleMagic();
    return "woof woof";
}

void SampleDriver::doSomeSampleMagic() {
    //Some platform-agnostic magic
}    

SampleDriver::SampleDriver(string name) {
    deviceName = name;
    getWoofValueDelegate = [this] { return this->getValue(); };
    driverOnlineDelegate = [this] { return this->isOnline(); };
    capabilities.push_back(unique_ptr<ICapability>(new BaseCapability("WoofValue", getWoofValueDelegate, driverOnlineDelegate)));
}
