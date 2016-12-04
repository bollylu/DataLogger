#include <Arduino.h>
#include "Thermometre.h"
#include <math.h>

#include "DataLoggerSerial.h"
#include "DataLoggerLcd.h"

#define ROUND(x,y) (float)(round(x * pow(10, y)) / pow(10, y))

#define PIN_ONEWIRE_BUS 13
Thermometre* Th1;

#define LOGGERS_COUNT 2
DataLoggerBase* Loggers[LOGGERS_COUNT];

float OldTemperature;
float DeltaForLogging = 0.1;

void setup() {
  Serial.begin(115200);
  Serial.println("setup...");

  Th1 = new Thermometre(PIN_ONEWIRE_BUS);
  Th1->SetResolution(12);

  Loggers[0] = new DataLoggerLcd();
  Loggers[1] = new DataLoggerSerial();

}


void loop() {

  Th1->ReadTemperatureAsync();
  if (Th1->DataReady && Th1->DataChanged) {
    float NewTemperature = ROUND(Th1->Temperature, 1);
    if (abs(NewTemperature - OldTemperature) >= DeltaForLogging) {
      OldTemperature = NewTemperature;
      for (int i = 0; i < LOGGERS_COUNT; i++) {
        Loggers[i]->LogData(String(NewTemperature));
      }
    }
  }

}


