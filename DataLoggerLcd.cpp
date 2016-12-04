#include "DataLoggerLcd.h"

DataLoggerLcd::DataLoggerLcd() {
  Initialize(6, 7, 14, 15, 16, 17);
}
DataLoggerLcd::DataLoggerLcd(byte pinRS, byte pinEN, byte pinD1, byte pinD2, byte pinD3, byte pinD4) {
  Initialize(pinRS, pinEN, pinD1, pinD2, pinD3, pinD4);
}

DataLoggerLcd::~DataLoggerLcd() {
  delete _Lcd;
}

void DataLoggerLcd::Initialize(byte pinRS, byte pinEN, byte pinD1, byte pinD2, byte pinD3, byte pinD4) {
  _Lcd = new LiquidCrystal(pinRS, pinEN, pinD1, pinD2, pinD3, pinD4);

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
  _Lcd->begin(16, 2);

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