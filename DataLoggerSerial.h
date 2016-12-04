#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "DataLoggerBase.h"

class DataLoggerSerial : public DataLoggerBase {
public:
  DataLoggerSerial();
  virtual ~DataLoggerSerial();

  void LogData(String data);

};

