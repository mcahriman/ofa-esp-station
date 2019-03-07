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
  static unsigned long last_health_check = 0;
  unsigned long currentTime = millis(); 
  if (last_health_check !=  currentTime && millis() % 30000 == 0) {
    station_system.healthCheck();
    last_health_check = currentTime;
  }
}