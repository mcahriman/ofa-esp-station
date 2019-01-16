#include <Arduino.h>
#include "SampleCapability.hpp"

String SampleCapability::getName() {
    return capabilityName;
}

String SampleCapability::getValue() {
    doSomeSampleMagic();
    return "woof woof";
}

void SampleCapability::doSomeSampleMagic() {
    Serial.println("BOO WOO CAPABILITY MAGIC HAS OCCURED\n");
    Serial.println("Behold the serial writer you have invoked\n");
}

SampleCapability::SampleCapability() {
    static int capabilityInstanceRegistered = 0;
    Serial.printf("Registering sample capability instance %d %s\n", capabilityInstanceRegistered++, capabilityName.c_str());
}

SampleCapability::SampleCapability(String name) {
    static int capabilityInstanceRegistered = 0;
    capabilityName = name;
    Serial.printf("Registering sample capability instance %d name %s\n", capabilityInstanceRegistered++, capabilityName.c_str());
}