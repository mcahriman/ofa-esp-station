#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <functional>

#include <util/Utils.hpp>

#include "device/Example/SampleDriver.hpp"
#include "device/DHT/DHTDriver.hpp"

SampleDriver sampleDriver("TestingDriver");
DHTDriver DHTDriver("DHTDriver");

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  delay(1000);
  Serial.println("Capabilities:" + utils_json_array(sampleDriver.getCapabilities().listCapabilities()));
  Serial.printf("Driver %s is %s\n", sampleDriver.getName().c_str(), (sampleDriver.isOnline() ? "Online" : "Offline"));

  Serial.println(utils_json_object(sampleDriver.getCapabilities().getAllReadings()));

  Serial.println(utils_json_object(DHTDriver.getCapabilities().getAllReadings()));
}