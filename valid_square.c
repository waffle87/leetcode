// 593. Valid Square
#include "leetcode.h"

/*
 * given the coordinates of four points in a 2d space 'p1 .. p4', return true if
 * the four points oncstruct a square. the coordinate of a point 'p_i' is
 * represented as '[x_i, y_i]'. the input is not given in any order. a valid
 * square has four equal sides with positive length and four equal angles
 * (90-degree angles)
 */

int dist(int x, int y) { return x * x + y * y; }

bool validSquare(int *p1, int p1Size, int *p2, int p2Size, int *p3, int p3Size,
                 int *p4, int p4Size) {
  int *p[4] = {p1, p2, p3, p4}, e[2] = {0};
  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 4; j++) {
      int n = dist(p[i][0] - p[j][0], p[i][1] - p[j][1]);
      if (!n)
        return false;
      if (n == e[0] || (!e[0] && n != e[1]))
        e[0] = n;
      else if (n == e[1] || (!e[1] && n != e[0]))
        e[1] = n;
      else
        return false;
    }
  }
  return true;
}

int main() {
  int p11[] = {0, 0}, p21[] = {1, 1}, p31[] = {1, 0}, p41[] = {0, 1};
  int p12[] = {0, 0}, p22[] = {1, 1}, p32[] = {1, 0}, p42[] = {0, 12};
  int p13[] = {1, 0}, p23[] = {-1, 0}, p33[] = {0, 1}, p43[] = {0, -1};
  printf("%d\n",
         validSquare(p11, ARRAY_SIZE(p11), p21, ARRAY_SIZE(p21), p31,
                     ARRAY_SIZE(p31), p41, ARRAY_SIZE(p41))); // expect: 1
  printf("%d\n",
         validSquare(p12, ARRAY_SIZE(p12), p22, ARRAY_SIZE(p22), p32,
                     ARRAY_SIZE(p32), p42, ARRAY_SIZE(p42))); // expect: 0
  printf("%d\n",
         validSquare(p13, ARRAY_SIZE(p13), p23, ARRAY_SIZE(p23), p33,
                     ARRAY_SIZE(p33), p43, ARRAY_SIZE(p43))); // expect: 1
}
