#include "Game.h"

void Game::Setup() {
  queue.Enqueue((Point){ 3, 3 });
  used[3][3] = WormPoint;
  AddRandomFood();
  AddRandomFood();

  delayTimer = millis() + delay;
}

int Game::Update() {
  const unsigned long currentTime = millis();

  if (deadState >= 4)
    return 1;

  if (currentTime < delayTimer || deadState)
    return 0;

  delayTimer = currentTime + delay;

  Point wormFront = queue.PeekBack();
  Point nextPoint = wormFront.Add(direction);

  if (nextPoint.x < 0 || nextPoint.x >= GAMESIZE || nextPoint.y < 0 || nextPoint.y >= GAMESIZE) {
    SetDead();
    return 0;
  }

  int *loc = GetPosition(nextPoint);

  if (*loc & WormPoint) {
    SetDead();
  } else if (*loc & FoodPoint) {
    queue.Enqueue(nextPoint);
    *loc = WormPoint;
    AddRandomFood();
  } else {
    queue.Enqueue(nextPoint);
    *loc = WormPoint;
    int *oldLoc = GetPosition(queue.Dequeue());
    *oldLoc = 0;
  }
}

void Game::GetVisuals(uint8_t *buffer) {
  const unsigned long currentTime = millis();

  if (!deadState) {
    const int foodDelay = delay / 1.5;
    bool blinkFood = (currentTime % foodDelay) < (foodDelay / 2);

    for (int x = 0; x < GAMESIZE; x++) {
      buffer[GAMESIZE - 1 - x] = 0;
      for (int y = 0; y < GAMESIZE; y++) {
        if (used[x][y] & WormPoint || (blinkFood && (used[x][y] & FoodPoint)))
          buffer[GAMESIZE - 1 - x] |= 1 << (GAMESIZE - 1 - y);
      }
    }
  } else {
    for (int x = 0; x < GAMESIZE; x++) {
      buffer[GAMESIZE - 1 - x] = 0;
      for (int y = 0; y < GAMESIZE; y++) {
        if (used[x][y] & WormPoint || (x >= (4 - deadState) && x <= (3 + deadState) && y >= (4 - deadState) && y <= (3 + deadState))) {
          buffer[GAMESIZE - 1 - x] |= 1 << (GAMESIZE - 1 - y);
          if (deadTimer < currentTime) {
            deadTimer = currentTime + deadDelay;
            deadState++;
          }
        }
      }
    }
  }
}

int *Game::GetPosition(Point point) {
  return &used[point.x][point.y];
}

void Game::AddRandomFood() {
  int initX = random(0, GAMESIZE);
  int initY = random(0, GAMESIZE);

  int x = initX;
  int y = initY;

  do {
    int *pos = &used[x][y];
    if ((*pos == 0)) {
      *pos = FoodPoint;
      break;
    }

    x++;
    if (x >= GAMESIZE) {
      x = 0;
      y++;
    }

    if (y >= GAMESIZE) {
      y = 0;
    }
  } while (x != initX || y != initY);
}

void Game::SetDead() {
  deadState = 1;
  deadTimer = millis() + deadDelay;
}
