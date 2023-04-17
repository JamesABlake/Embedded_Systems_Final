#include <stdint.h>;
#include "Game.h"

#define LEFT 1;
#define RIGHT 2;
#define UP 4;
#define DOWN 8;
#define BUTTON 16;

class JoyStick {
  public:
    JoyStick(uint8_t pinX, uint8_t pinY, uint8_t pinS);

    bool IsButtonPressed();
    bool GetInput(Point* result);

  private: 
    uint8_t pinX;
    uint8_t pinY;
    uint8_t pinS;

    const int midPoint = 511;
    const int tapOffset = 64;
};