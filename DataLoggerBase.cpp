// 
// 
// 

#include "DataLoggerBase.h"
#include "time.h"


String DataLoggerBase::GetTimeStamp() {
#ifndef REALTIME
  return "2016-12-06 13:54:23";
#else
  time_t Now = now();
  Serial.print(hour(Now));
  Serial.print(":");
  Serial.print(minute(Now));
  Serial.print(":");
  Serial.print(second(Now));
  Serial.print(data);
#endif
}

