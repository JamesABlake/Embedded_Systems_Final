#ifndef GAME_H
#define GAME_H

#include <Arduino.h>
#include "Point.h"
#include "Queue.h"

#define WormPoint 1
#define FoodPoint 2
#define GAMESIZE 8

class Game {

public:
  Point direction = (Point){ 1, 0 };

  void Setup();
  int Update();
  void GetVisuals(uint8_t *buffer);

private:
  int delay = 750;
  unsigned long delayTimer;

  int deadState;  // 0 if alive, 1-4 for dead/animation
  int deadDelay = 500;
  unsigned long deadTimer;

  int used[8][8];
  Queue<Point, 64> queue;

  int *GetPosition(Point point);

  void AddRandomFood();
  void SetDead();
};
#endif