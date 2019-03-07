#include "StreamLogger.hpp" 

const char* StreamLogger::logFormatStr = "%lu: %s: %s\n";

StreamLogger::StreamLogger(Stream *loggerStream)
{
    stream = loggerStream;
}

void StreamLogger::Log(LogLevel level, const char* message) {
    if(stream) {
        stream->printf(getLogFormatStr(), millis(), resolveLogLevelLabel(level), message);
    }
}

const char* StreamLogger::getLogFormatStr() {
    return  logFormatStr;
}