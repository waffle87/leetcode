// 1401. Circle and Rectangle Overlapping
#include "leetcode.h"

/*
 * you are given a circle represented as '(radius, xcenter, ycenter)' and an
 * axis-aligned rectangle represented as '(x1, y1, x2, y2)' where '(x1, y1)' are
 * the coordinates of the bottom left corner, and '(x2, y2)' are the coordinates
 * of the top right corner of the rectangle. return true if the circle and
 * rectangle are overlapped otherwise return 'false'. in other words, check if
 * there is any point '(xi, yi)' that belongs to the circle and the rectangle at
 * the same time.
 */

bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2,
                  int y2) {
  int x = fmin(fmax(xCenter, x1), x2) - xCenter;
  int y = fmin(fmax(yCenter, y1), y2) - yCenter;
  return x * x + y * y <= radius * radius;
}

int main() {
  bool r1 = checkOverlap(1, 0, 0, 1, -1, 3, 1);
  bool r2 = checkOverlap(1, 1, 1, 1, -3, 2, -1);
  bool r3 = checkOverlap(1, 0, 0, -1, 0, 0, 1);
  printf("%d\n", r1);
  assert(r1 == true);
  printf("%d\n", r2);
  assert(r2 == false);
  printf("%d\n", r3);
  assert(r3 == true);
}
