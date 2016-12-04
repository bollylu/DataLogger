#include "DataLoggerText.h"
#include "Thermometre.h"
#include <math.h>

#define   PIN_ONEWIRE_BUS 13

Thermometre* Th1;
DataLoggerText* SerialOutput;

float OldTemperature;
float DeltaForLogging = 0.1;

void setup() {
  Serial.begin(115200);
  Serial.println("setup...");

  Th1 = new Thermometre(PIN_ONEWIRE_BUS);
  Th1->SetResolution(12);

  SerialOutput = new DataLoggerText();

}

#define ROUND(x,y) (float)((long)((float)(x*(10^y))+0.5f)/(10^y))

void loop() {

  Th1->ReadTemperatureAsync();
  if (Th1->DataReady && Th1->DataChanged) {
    float NewTemperature = Rounded(Th1->Temperature, 1);
    //Serial.print("(");
    //Serial.print(Th1->Temperature);
    //Serial.print(") ");
    //Serial.print(NewTemperature);
    //Serial.print("-");
    //Serial.println(OldTemperature);
    if (abs(NewTemperature - OldTemperature) >= DeltaForLogging) {
      OldTemperature = NewTemperature;
      SerialOutput->LogData(String(NewTemperature));
    }
  }

}

float Rounded(float value, int decimals) {
  //Serial.print("value=");
  //Serial.println(value);
  float TempValue = value * pow(10,decimals);
  //Serial.print("TempValue=");
  //Serial.println(TempValue);
  //float TempValue2 = TempValue + 0.5;
  //Serial.print("TempValue2=");
  //Serial.println(TempValue2);
  long TempValue3 = round(TempValue);
  //Serial.print("TempValue3=");
  //Serial.println(TempValue3);
  float TempValue4 = TempValue3 / pow(10, decimals);
  //Serial.print("TempValue4=");
  //Serial.println(TempValue4);
  return TempValue4;
}
