#include <Arduino.h>

String debugString = "";

void SetupSerial() {
  Serial.begin(9600);
  for(int i = 0; i < 8; i++)
    Serial.println("");
}