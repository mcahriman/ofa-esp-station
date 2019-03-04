#pragma once

#include <Arduino.h>
#include "BaseLogger.hpp"

#include <memory>

using namespace std;

class StreamLogger : public BaseLogger
{
public:
    StreamLogger(Stream*);
    virtual void Log(LogLevel, const char*);

private:
    Stream* stream;
};