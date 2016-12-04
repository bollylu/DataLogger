#pragma once
#include "DataLoggerBase.h"
#include <LiquidCrystal.h>

class DataLoggerLcd : public DataLoggerBase {
public:

  byte PinEN;
  byte PinRS;
  byte PinD1;
  byte PinD2;
  byte PinD3;
  byte PinD4;

  DataLoggerLcd();
  ~DataLoggerLcd();
  void LogData(String data);

private:
  LiquidCrystal* _Lcd;

};


