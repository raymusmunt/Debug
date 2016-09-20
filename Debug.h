#ifndef DEBUG_H
#define DEBUG_H

#include "Arduino.h"
#include <FS.h>

enum DEBUG_STATE {
    OFF,
    SERIAL_OUT,
    LOG
};

// Think about this maybe
// enum DEBUG_TYPE {
//     NOT_SPECIFIED,
//     WIFI,
//     LIGHT_CONTROL,
//     DEVICE_CONTROL,
//     FILE_SYSTEM,
//     CRITICAL
// };
// template <class U>  void Print(DEBUG_TYPE debug_type = NOT_SPECIFIED, const U &x)

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

    template <class T, class U>
    void Printf(const T &x, const U &y)
    {
        switch (_debugState) {
            case SERIAL_OUT:
                Serial.printf(x, y);
                break;
            case LOG:
                openLog("a");
                _log.printf(x, y);
                closeLog();
                break;
            default:
                break;
        }
    }

    template <class T, class U, class V>
    void Printf(const T &x, const U &y, const V &z)
    {
        switch (_debugState) {
            case SERIAL_OUT:
                Serial.printf(x, y, z);
                break;
            case LOG:
                openLog("a");
                _log.printf(x, y, z);
                closeLog();
                break;
            default:
                break;
        }
    }

    template <class S, class T, class U, class V>
    void Printf(const S &w, const T &x, const U &y, const V &z)
    {
        switch (_debugState) {
            case SERIAL_OUT:
                Serial.printf(w, x, y, z);
                break;
            case LOG:
                openLog("a");
                _log.printf(w, x, y, z);
                closeLog();
                break;
            default:
                break;
        }
    }

    template <class A, class B, class C, class D, class E>
    void Printf(const A &v, const B &w, const C &x, const D &y, const E &z)
    {
        switch (_debugState) {
            case SERIAL_OUT:
                Serial.printf(v, w, x, y, z);
                break;
            case LOG:
                openLog("a");
                _log.printf(v, w, x, y, z);
                closeLog();
                break;
            default:
                break;
        }
    }
};

extern Debug debug;

#endif