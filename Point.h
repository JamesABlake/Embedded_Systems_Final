#ifndef POINT_H
#define POINT_H

struct Point {
  int x;
  int y;

  Point Add(Point other) {
    return (Point){ x + other.x, y + other.y };
  }
};
#endif