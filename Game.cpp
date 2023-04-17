#include "Game.h"

Point AddPoints(Point lhs, Point rhs) {
  Point result;
  result.x = lhs.x + rhs.x;
  result.y = lhs.y + rhs.y;
  return result;
}