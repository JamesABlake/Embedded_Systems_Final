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

  /// Returns true only once after the button is pressed, until it is released
  bool ButtonDown();
  /// Gets a point in any 4 cardinal directions based on which way the joystick is moved
  bool GetInput(Point *result);

private:
  uint8_t pinX;
  uint8_t pinY;
  uint8_t pinS;

  bool isButtonHeld;

  const int midPoint = 511;
  const int tapOffset = 64;
};