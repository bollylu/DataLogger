#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "DataLoggerBase.h"

class DataLoggerText : public DataLoggerBase {
public:
  DataLoggerText();
  virtual ~DataLoggerText();

  void LogData(String data);

};

