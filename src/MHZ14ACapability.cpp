#include "MHZ14ACapability.hpp"
#include "Arduino.h"

MHZ14ACapability::MHZ14ACapability(int rx, int tx) {
    MHZ14ACapability(rx, rx, capabilityName);
}

MHZ14ACapability::MHZ14ACapability(int rx, int tx, String name) {
    serialPort = new SoftwareSerial(rx, tx);
    serialPort->begin(baud);
    performReading();
    
    if(responseBuffer[8] == 0) {
        is_valid = false;
        Serial.printf("Could not initialize MHZ Sensor on rx: %d tx: %d\n", rx, tx);
    } else {
        Serial.printf("Initialised MHZ Sensor on rx: %d tx: %d\n", rx, tx);
    }
    
    capabilityName = name;  
}

MHZ14ACapability::~MHZ14ACapability() {
    delete serialPort;
}

String MHZ14ACapability::getValue() 
{
    return isValid() ? String(read_value()) : "n/a";
}

int MHZ14ACapability::read_value() {
    performReading();
    return responseBuffer[2] * 256 + responseBuffer[3];
}

void MHZ14ACapability::performReading() {
    serialPort->write(MHZ14A_READ_CMD, cmd_len);
    serialPort->readBytes(responseBuffer,cmd_len);
}