#ifndef DEBUG_H
#define DEBUG_H

#include "Arduino.h"
#include <FS.h>

enum DEBUG_STATE {
    OFF,
    SERIAL_OUT,
    LOG
};

class Debug {

  private:

    File _log;
    int _maxLogSize = 500;                  // in kilobytes
    int _logSize;
    DEBUG_STATE _debugState = OFF;

    const char* _logLocation = "/sys/log.txt";

    void openLog(const char * mode);
    void closeLog();

  public:
    Debug();
    void setMode(DEBUG_STATE debug_state);
    const char* logLocation();
    void clearLog(int max_log_size = 0);

    template <class U>
    void Print(const U &x)
    {
        switch (_debugState) {
            case SERIAL_OUT:
                Serial.print(x);
                break;
            case LOG:
                openLog("a");
                _log.print(x);
                closeLog();
                break;
            default:
                break;
        }
    }

    template <class U>
    void Println(const U &x)
    {
        switch (_debugState) {
            case SERIAL_OUT:
                Serial.println(x);
                break;
            case LOG:
                openLog("a");
                _log.println(x);
                closeLog();
                break;
            default:
                break;
        }
    }

    template<typename... Args>
    void Printf(const char *s, Args... args)
    {
        switch (_debugState) {
            case SERIAL_OUT:
                Serial.printf(s, args...);
                break;
            case LOG:
                openLog("a");
                _log.printf(s, args...);
                closeLog();
                break;
            default:
                break;
        }

    }
};

extern Debug debug;

#endif