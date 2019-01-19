#pragma once

#include <Arduino.h>

#include "ICapability.hpp"
#include "SoftwareSerial.h"

#define MHZ14A_READ_CMD                 "\xFF\x01\x86\x00\x00\x00\x00\x00\x79"
#define MHZ14A_CALIBRATE_ZERO_POINT_CMD "\xFF\x01\x87\x00\x00\x00\x00\x00\x78"
/**
 * MHZ14A Capability
 * Constructor takes tx and rx pins as 
 * 
 */

class MHZ14ACapability : ICapability {
  public:
       MHZ14ACapability(int rx, int tx, String name);
       MHZ14ACapability(int rx, int tx);
       ~MHZ14ACapability();

       bool isValid();
       String getName();
       String getValue();

    private:
       const int baud = 9600;
       const int cmd_len = 9;       
       char responseBuffer[9];
       String capabilityName = "MHZ14A_CO2";
       SoftwareSerial* serialPort;

       int read_value();
       void performReading();
       bool is_valid;
};