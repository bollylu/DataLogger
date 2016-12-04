#include "DataLoggerSerial.h"

DataLoggerSerial::DataLoggerSerial() {
}

DataLoggerSerial::~DataLoggerSerial() {
}

void DataLoggerSerial::LogData(String data) {
  if (!data) {
    return;
  }
  Serial.print(DataLoggerBase::GetTimeStamp());
  Serial.print(" ");
  Serial.println(data);
}