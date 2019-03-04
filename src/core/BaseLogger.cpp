#include "BaseLogger.hpp"

const char* FATAL_LABEL = "FATAL";
const char* ERROR_LABEL = "ERROR";
const char* WARN_LABEL = "WARN";
const char* INFO_LABEL = "INFO";
const char* TRACE_LABEL = "TRACE";

const char* LOG_FORMAT = "%s - %s\n";


const char* BaseLogger::resolveLogLevelLabel(LogLevel level) {

    //duck
    switch (level)
    {
        case LogLevel::INFO: return INFO_LABEL;
        case LogLevel::TRACE: return TRACE_LABEL;
        case LogLevel::WARN: return WARN_LABEL;
        case LogLevel::ERROR: return ERROR_LABEL;
        case LogLevel::FATAL: return FATAL_LABEL;
        default: return INFO_LABEL;
    }
}

const char* BaseLogger::getLogFormatStr() {
    return LOG_FORMAT;
}
