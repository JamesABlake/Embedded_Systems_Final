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

  /// Sets up the game. Must be called once before the first Update();
  void Setup();
  /// Updates the game for each frame. Setup() must be called before this.
  int Update();
  /// Puts the visuals in the buffer provided. The buffer should be size should be equal to GAMESIZE (8).
  void GetVisuals(uint8_t *buffer);

private:
  /// The delay between each real update to the game state
  int delay = 750;
  unsigned long delayTimer;

  /// The current state of death. 0 if alive, 1-4 for dead and it's animation state
  int deadState;
  /// The delay between each animation state.
  int deadDelay = 500;
  unsigned long deadTimer;

  /// The array for each dot's state flag.
  int used[GAMESIZE][GAMESIZE];
  /// Keeps track of the order and direction of the worm.
  Queue<Point, GAMESIZE * GAMESIZE> queue;

  /// Gets a pointer to the state flag at a point
  int *GetPosition(Point point);

  /// Randomly adds a food piece to the board where there isn't another object
  void AddRandomFood();

  /// Sets deadState to dead and the starting animation frame
  void SetDead();
};
#endif