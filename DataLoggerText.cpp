#include "DataLoggerText.h"
#include "time.h"

DataLoggerText::DataLoggerText() {
}


DataLoggerText::~DataLoggerText() {
}

void DataLoggerText::LogData(String data) {
  if (!data) {
    return;
  }
  Serial.print(DataLoggerBase::GetTimeStamp());
  Serial.print(" ");
  Serial.println(data);
}