// 3453. Separate Squares I
#include "leetcode.h"

/*
 * you are given a 2d integer array 'squares'. each 'squares[i] = [xi, yi, zi]'
 * represents the coordinates of the bottom-left point and the side length of a
 * sqaure parallel to the x-axis. find the minimum y-coordinate value of a
 * horizontal line such that the total area of the squares above the line equals
 * the total area of the squares below the line. note: sqaures may overlap.
 * overlapping areas should be counted multiple times.
 */

double separateSquares(int **squares, int squaresSize, int *squaresColSize) {
  double l = 0.0, r = INT_MAX, ans = 0.0;
  for (int i = 0; i < 80; i++) {
    double mid = l + (r - l) / 2.0;
    double la = 0.0, ua = 0.0;
    for (int j = 0; j < squaresSize; j++) {
      double y = squares[j][1], l = squares[j][2], ta = l * l;
      if (y + l <= mid)
        la += ta;
      else if (y >= mid)
        ua += ta;
      else {
        double below = (mid - y) * l;
        la += below;
        ua += (ta - below);
      }
    }
    if (la >= ua) {
      ans = mid;
      r = mid;
    } else
      l = mid;
  }
  return ans;
}

int main() {
  int s1i[2][3] = {{0, 0, 1}, {2, 2, 1}}, s2i[2][3] = {{0, 0, 2}, {1, 1, 1}};
  struct two_d_arr *s1 =
      two_d_arr_init(ARRAY_SIZE(s1i), ARRAY_SIZE(s1i[0]), s1i);
  struct two_d_arr *s2 =
      two_d_arr_init(ARRAY_SIZE(s2i), ARRAY_SIZE(s2i[0]), s2i);
  printf("%f\n", separateSquares(s1->arr, s1->row_size,
                                 s1->col_size)); // expect: 1.00000
  printf("%f\n", separateSquares(s2->arr, s2->row_size,
                                 s2->col_size)); // expect: 1.66667
  two_d_arr_free(s1);
  two_d_arr_free(s2);
}
