// 812. Largest Triangle Area
#include "leetcode.h"

/*
 * given an array of points on the x-y plane 'points' where 'points[i] = [x_i,
 * y_i]' return the area of the largest triangle that can be formed by any three
 * different points. answers within 10^-5 will be accepted.
 */

double largestTriangleArea(int **points, int pointsSize, int *pointsColSize) {
  double ans = INT_MIN;
  for (int i = 0; i < pointsSize; i++)
    for (int j = i + 1; j < pointsSize; j++)
      for (int k = j + 1; k < pointsSize; k++) {
        int x1 = points[i][0], y1 = points[i][1];
        int x2 = points[j][0], y2 = points[j][1];
        int x3 = points[k][0], y3 = points[k][1];
        double tmp = abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));
        ans = fmax(ans, 0.5 * tmp);
      }
  return ans;
}

int main() {
  int p1i[5][2] = {{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}},
      p2i[3][2] = {{1, 0}, {0, 0}, {0, 1}};
  struct two_d_arr *p1 =
      two_d_arr_init(ARRAY_SIZE(p1i), ARRAY_SIZE(p1i[0]), p1i);
  struct two_d_arr *p2 =
      two_d_arr_init(ARRAY_SIZE(p2i), ARRAY_SIZE(p2i[0]), p2i);
  printf("%f\n", largestTriangleArea(p1->arr, p1->row_size,
                                     p1->col_size)); // expect: 2.00000
  printf("%f\n", largestTriangleArea(p2->arr, p2->row_size,
                                     p2->col_size)); // expect: 0.50000
  two_d_arr_free(p1);
  two_d_arr_free(p2);
}
