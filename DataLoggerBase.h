// DataLoggerBase.h

#ifndef _DATALOGGERBASE_h
#define _DATALOGGERBASE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class DataLoggerBase {
public:
  virtual void LogData(String data) = 0;
  virtual String GetTimeStamp();

};


#endif

