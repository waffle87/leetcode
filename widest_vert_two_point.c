// 1637. Widest Vertical Area Between Two Points Containing No Points
#include "leetcode.h"

/*
 * given 'n' points on a 2d plane where 'points [i] = [x[i], y[i]]', return the
 * widest veritcal area between two points such that no points are inside the
 * area. a vertical area is an area of fixed width extending infinitely along
 * the y-axis. the widest vertical area is the one with the maximum width. note
 * that the points on the edge of a vertical area are not considred included in
 * the area.
 */

int cmp(const void **a, const void **b) {
  int **pa = (const int **)a;
  int **pb = (const int **)b;
  return pa[0][0] - pb[0][0];
}

// int maxWidthOfVerticalArea(int **points, int points_size,
//                            int *points_col_size) {
int maxWidthOfVerticalArea(int r, int c, int points[r][c], int points_size) {
  qsort(points, points_size, sizeof(int **), cmp);
  int area = 0;
  for (int i = 0; i + 1 < points_size; i++)
    area = points[i + 1][0] - points[i][0] > area
               ? points[i + 1][0] - points[i][0]
               : area;
  return area;
}

int main() {
  int p1[4][2] = {{8, 7}, {9, 9}, {7, 4}, {9, 7}},
      p2[6][2] = {{3, 1}, {9, 0}, {1, 0}, {1, 4}, {5, 3}, {8, 3}};
  printf("%d\n", maxWidthOfVerticalArea(4, 2, p1, 4)); // expect: 1
  printf("%d\n", maxWidthOfVerticalArea(6, 2, p2, 6)); // expect: 3
}
