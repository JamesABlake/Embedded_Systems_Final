#include "Point.h"
#include <stdint.h>;

#define LEFT 1;
#define RIGHT 2;
#define UP 4;
#define DOWN 8;
#define BUTTON 16;

class JoyStick {
public:
  JoyStick(uint8_t pinX, uint8_t pinY, uint8_t pinS);

  bool ButtonDown();
  bool ButtonHeld();
  bool GetInput(Point *result);

private:
  uint8_t pinX;
  uint8_t pinY;
  uint8_t pinS;

  bool isButtonHeld;

  const int midPoint = 511;
  const int tapOffset = 64;
};