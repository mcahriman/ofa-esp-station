#include "StreamLogger.hpp"

StreamLogger::StreamLogger(Stream *loggerStream)
{
    stream = loggerStream;
}

void StreamLogger::Log(LogLevel level, const char* message) {
    if(stream) {
        stream->printf(getLogFormatStr(),resolveLogLevelLabel(level), message);
    }
}