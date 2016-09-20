#include "Debug.h"

Debug::Debug()
{
    _log = SPIFFS.open(_logLocation, "r");
    _logSize = _log.size();
    _log.close();
}

void Debug::setMode(DEBUG_STATE debug_state)
{
    _debugState = debug_state;
}

void Debug::clearLog(int max_log_size)
{
    if (_logSize > max_log_size * 1000) {
        _log = SPIFFS.open(_logLocation, "w");
        _log.close();
    }
}

const char* Debug::logLocation()
{
    return _logLocation;
}

void Debug::openLog(const char* mode)
{
    clearLog(_maxLogSize);
    _log = SPIFFS.open(_logLocation, mode);
}

void Debug::closeLog()
{
    _logSize = _log.size();
    _log.close();
}

Debug debug;

