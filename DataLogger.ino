

#include "DataLoggerSerial.h"
#include "DataLoggerLcd.h"
#include "Thermometre.h"
#include <math.h>

#define ROUND(x,y) (float)(round(x * pow(10, y)) / pow(10, y))

#define PIN_ONEWIRE_BUS 13

Thermometre* Th1;
DataLoggerBase* Logger1;
DataLoggerBase* Logger2;

float OldTemperature;
float DeltaForLogging = 0.1;

void setup() {
  Serial.begin(115200);
  Serial.println("setup...");

  Th1 = new Thermometre(PIN_ONEWIRE_BUS);
  Th1->SetResolution(12);

  Logger1 = new DataLoggerLcd();
  Logger2 = new DataLoggerSerial();

}


void loop() {

  Th1->ReadTemperatureAsync();
  if (Th1->DataReady && Th1->DataChanged) {
    float NewTemperature = ROUND(Th1->Temperature, 1);
    if (abs(NewTemperature - OldTemperature) >= DeltaForLogging) {
      OldTemperature = NewTemperature;
      Logger1->LogData(String(NewTemperature));
      Logger2->LogData(String(NewTemperature));
    }
  }

}
