#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <functional>

#include <core/System.hpp>
#include <core/StreamLogger.hpp>


StreamLogger logger(&Serial);
System station_system; 

void setup()
{
  Serial.begin(115200);
  station_system.setLogger(&logger);
  station_system.startUp();

}

void loop()
{
  //sleep checks
}