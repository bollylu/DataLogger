#include "DataLoggerLcd.h"


DataLoggerLcd::DataLoggerLcd() {
  PinEN = 7;
  PinRS = 6;
  PinD1 = 14;
  PinD2 = 15;
  PinD3 = 16;
  PinD4 = 17;
  _Lcd = new LiquidCrystal(PinRS, PinEN, PinD1, PinD2, PinD3, PinD4);

  byte degres[8] = {
    0b01000,
    0b10100,
    0b01000,
    0b00011,
    0b00100,
    0b00100,
    0b00011,
    0b00000
  };
  _Lcd->createChar(1, degres);

  // Initialisations   
  _Lcd->begin(16, 2);
  
  //_Lcd->autoscroll();
}


DataLoggerLcd::~DataLoggerLcd() {
  delete _Lcd;
}

void DataLoggerLcd::LogData(String data) {
  if (!data) {
    return;
  }
  _Lcd->home();
  _Lcd->clear();
  _Lcd->setCursor(0, 0);
  _Lcd->print(DataLoggerBase::GetTimeStamp().substring(0, 16));
  _Lcd->setCursor(0, 1);
  _Lcd->print(data);
  _Lcd->write(1);
}