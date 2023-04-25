#include "JoyStick.h";
#include "Arduino.h"

JoyStick::JoyStick(uint8_t pinX, uint8_t pinY, uint8_t pinS) {
  this->pinX = pinX;
  this->pinY = pinY;
  this->pinS = pinS;

  pinMode(pinS, INPUT_PULLUP);
}

bool JoyStick::ButtonDown() {
  if (!isButtonHeld) {
    isButtonHeld = !digitalRead(pinS);
    return isButtonHeld;
  }

  isButtonHeld = !digitalRead(pinS);
  return false;
}

bool JoyStick::GetInput(Point *direction) {
  int x = 511 - analogRead(pinX);
  int y = 511 - analogRead(pinY);

  if (abs(x) < tapOffset && abs(y) < tapOffset)
    return false;

  if (abs(x) > abs(y)) {
    direction->x = constrain(x, -1, 1);
    direction->y = 0;
  } else {
    direction->x = 0;
    direction->y = constrain(-y, -1, 1);
  }

  return true;
}