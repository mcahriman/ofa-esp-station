#include "System.hpp"

System::System() {
    
}

void System::setLogger(BaseLogger* logger) {
    this->logger = logger;
}

void System::startUp() {
    logger->Log(LogLevel::INFO, "System startup sequence initialized lol");
    // check mode (configuration or work)
    // here say if it is ok
}