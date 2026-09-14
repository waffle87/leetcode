// 836. Rectangle Overlap
#include "leetcode.h"

/*
 * an axis-aligned rectangle is represented as a list '[x1, y1, x2, y2]' where
 * '(x1, y1)' is the coordinate of its bottom left corner, and '(x2, y2)' is the
 * coordinate of its top right corner. its top and bottom edges are parallel to
 * the x-axis and its left and right edges are paralled to the y-axis. two
 * rectangles overlap if the area of their intersection is positive. given two
 * axis-aligned rectangles, return true if they overlap, otherwise return false.
 */

bool isRectangleOverlap(int *rec1, int rec1Size, int *rec2, int rec2Size) {
  return rec1[0] < rec2[2] && rec2[0] < rec1[2] && rec1[1] < rec2[3] &&
         rec2[1] < rec1[3];
}

int main() {
  int r11[] = {0, 0, 2, 2}, r21[] = {1, 1, 3, 3};
  int r12[] = {0, 0, 1, 1}, r22[] = {1, 0, 2, 1};
  int r13[] = {0, 0, 1, 1}, r23[] = {2, 2, 3, 3};
  bool r1 = isRectangleOverlap(r11, ARRAY_SIZE(r11), r21, ARRAY_SIZE(r21));
  bool r2 = isRectangleOverlap(r12, ARRAY_SIZE(r12), r22, ARRAY_SIZE(r22));
  bool r3 = isRectangleOverlap(r13, ARRAY_SIZE(r13), r23, ARRAY_SIZE(r23));
  printf("%d\n", r1);
  assert(r1 == true);
  printf("%d\n", r2);
  assert(r2 == false);
  printf("%d\n", r3);
  assert(r3 == false);
}
