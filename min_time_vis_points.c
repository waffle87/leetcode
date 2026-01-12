// 1266. Minimum Time Visiting All Points
#include "leetcode.h"

/*
 * on a 2d plane, there are 'n' points with integer coordinate points 'points[i]
 * = [x_i, y_i]'. return the minimum time in seconds to visit all the points in
 * the order given by 'points'. you can move according to these rules: in 1
 * second, you can either move vertically or horizontally by one unit, or move
 * diagonally 'sqrt(2)' units. you have to visit the points in the same order
 * they appear in the array, and you are allowed to pass through points that
 * appear late in the order, but these do not count as visits.
 */

int minTimeToVisitAllPoints(int **points, int pointsSize, int *pointsColSize) {
  int ans = 0;
  int dist_x = 0, mask_x = 0, abs_x = 0;
  int dist_y = 0, mask_y = 0, abs_y = 0;
  for (int i = 0; i < pointsSize - 1; i++) {
    dist_x = points[i][0] - points[i + 1][0];
    mask_x = dist_x >> 31;
    abs_x = (dist_x ^ mask_x) - mask_x;
    dist_y = points[i][1] - points[i + 1][1];
    mask_y = dist_y >> 31;
    abs_y = (dist_y ^ mask_y) - mask_y;
    ans += abs_x ^ ((abs_x ^ abs_y) & -(abs_x < abs_y));
  }
  return ans;
}

int main() {
  int p1i[3][2] = {{1, 1}, {3, 4}, {-1, 0}}, p2i[2][2] = {{3, 2}, {-2, 2}};
  struct two_d_arr *p1 =
      two_d_arr_init(ARRAY_SIZE(p1i), ARRAY_SIZE(p1i[0]), p1i);
  struct two_d_arr *p2 =
      two_d_arr_init(ARRAY_SIZE(p2i), ARRAY_SIZE(p2i[0]), p2i);
  printf("%d\n", minTimeToVisitAllPoints(p1->arr, p1->row_size,
                                         p1->col_size)); // expect: 7
  printf("%d\n", minTimeToVisitAllPoints(p2->arr, p2->row_size,
                                         p2->col_size)); // expect: 5
  two_d_arr_free(p1);
  two_d_arr_free(p2);
}
