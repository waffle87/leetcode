// 3047. Find the Largest Area of Square Inside Two Rectangles
#include "leetcode.h"

/*
 * there exists 'n' rectangles in a 2d plane with edges parallel to the x and y
 * axis. you are given two 2d integer arrays 'bottomLeft' and 'topRight' where
 * 'bottomLeft[i] = [ai, bi]' and 'topRight[i] = [ci, di]' represent the bottom
 * left and top right coordinates of the i'th rectangle respectively. you need
 * to find the maximum area of a square that can fit inside the intersection
 * region of at least two rectangles. return 0 if such a square does not exist.
 */

long long largestSquareArea(int **bottomLeft, int bottomLeftSize,
                            int *bottomLeftColSize, int **topRight,
                            int topRightSize, int *topRightColSize) {
  int n = bottomLeftSize;
  long long max_side = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      int overlap_x = fmin(topRight[i][0], topRight[j][0]) -
                      fmax(bottomLeft[i][0], bottomLeft[j][0]);
      int overlap_y = fmin(topRight[i][1], topRight[j][1]) -
                      fmax(bottomLeft[i][1], bottomLeft[j][1]);
      if (overlap_x > 0 && overlap_y > 0)
        max_side = fmax(max_side, fmin(overlap_x, overlap_y));
    }
  return max_side * max_side;
}

int main() {
  int bl1i[3][2] = {{1, 1}, {2, 2}, {3, 1}},
      tr1i[3][2] = {{3, 3}, {4, 4}, {6, 6}};
  int bl2i[3][2] = {{1, 1}, {1, 3}, {1, 5}},
      tr2i[3][2] = {{5, 5}, {5, 7}, {5, 9}};
  int bl3i[3][2] = {{1, 1}, {2, 2}, {1, 2}},
      tr3i[3][2] = {{3, 3}, {4, 4}, {3, 4}};
  int bl4i[3][2] = {{1, 1}, {3, 2}, {3, 1}},
      tr4i[3][2] = {{2, 2}, {4, 4}, {4, 2}};
  struct two_d_arr *bl1 =
      two_d_arr_init(ARRAY_SIZE(bl1i), ARRAY_SIZE(bl1i[0]), bl1i);
  struct two_d_arr *bl2 =
      two_d_arr_init(ARRAY_SIZE(bl2i), ARRAY_SIZE(bl2i[0]), bl2i);
  struct two_d_arr *bl3 =
      two_d_arr_init(ARRAY_SIZE(bl3i), ARRAY_SIZE(bl3i[0]), bl3i);
  struct two_d_arr *bl4 =
      two_d_arr_init(ARRAY_SIZE(bl4i), ARRAY_SIZE(bl4i[0]), bl4i);
  struct two_d_arr *tr1 =
      two_d_arr_init(ARRAY_SIZE(tr1i), ARRAY_SIZE(tr1i[0]), tr1i);
  struct two_d_arr *tr2 =
      two_d_arr_init(ARRAY_SIZE(tr2i), ARRAY_SIZE(tr2i[0]), tr2i);
  struct two_d_arr *tr3 =
      two_d_arr_init(ARRAY_SIZE(tr3i), ARRAY_SIZE(tr3i[0]), tr3i);
  struct two_d_arr *tr4 =
      two_d_arr_init(ARRAY_SIZE(tr4i), ARRAY_SIZE(tr4i[0]), tr4i);
  printf("%lld\n",
         largestSquareArea(bl1->arr, bl1->row_size, bl1->col_size, tr1->arr,
                           tr1->row_size, tr1->col_size)); // expect: 1
  printf("%lld\n",
         largestSquareArea(bl2->arr, bl2->row_size, bl2->col_size, tr2->arr,
                           tr2->row_size, tr2->col_size)); // expect: 4
  printf("%lld\n",
         largestSquareArea(bl3->arr, bl3->row_size, bl3->col_size, tr3->arr,
                           tr3->row_size, tr3->col_size)); // expect: 1
  printf("%lld\n",
         largestSquareArea(bl4->arr, bl4->row_size, bl4->col_size, tr4->arr,
                           tr4->row_size, tr4->col_size)); // expect: 0
  two_d_arr_free(bl1);
  two_d_arr_free(bl2);
  two_d_arr_free(bl3);
  two_d_arr_free(bl4);
  two_d_arr_free(tr1);
  two_d_arr_free(tr2);
  two_d_arr_free(tr3);
  two_d_arr_free(tr4);
}
