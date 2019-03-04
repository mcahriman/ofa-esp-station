#pragma once

enum class LogLevel {
    TRACE,
    INFO,
    WARN,
    ERROR,
    FATAL
};

class BaseLogger {
    public:
        virtual void Log(LogLevel, const char*) = 0;

    protected:
        virtual const char* resolveLogLevelLabel(LogLevel);
        virtual const char* getLogFormatStr();
};