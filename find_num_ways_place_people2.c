// 3027. Find the Number of Ways to Place People II
#include "leetcode.h"

/*
 * you are given a 2d array 'points' of size 'n x 2' representing integer
 * coordinates of some points on a 2d plane where 'points[i] = [x_i, y_i]'. we
 * define the right direction as positive x-axis and the left direction as
 * negative x-axis. similarly, up and down are postive and negative y-axis
 * accordingly. you have to place 'n' people including alice and bob at these
 * points such that there is exactly one person at every point. alice wants to
 * be alone with bob, so alice will build a rectangular fence with alice's
 * position as the upper left corner and bob's position as the lower right
 * corner
 */

int cmp(const void *a, const void *b) {
  const int *aa = *(const int **)a;
  const int *bb = *(const int **)b;
  return aa[0] == bb[0] ? aa[1] - bb[1] : bb[0] - aa[0];
}

int numberOfPairs(int **points, int pointsSize, int *pointsColSize) {
  int ans = 0;
  qsort(points, pointsSize, sizeof(int *), cmp);
  for (int i = 0; i < pointsSize - 1; i++) {
    int y = INT_MAX, yi = points[i][1];
    for (int j = i + 1; j < pointsSize; j++) {
      const int yj = points[j][1];
      if (yj >= yi && y > j) {
        ans++;
        y = yj;
        if (yi == yj)
          break;
      }
    }
  }
  return ans;
}

int main() {
  int p1i[3][2] = {{1, 1}, {2, 2}, {3, 3}},
      p2i[3][2] = {{6, 2}, {4, 4}, {2, 6}},
      p3i[3][2] = {{3, 1}, {1, 3}, {1, 1}};
  struct two_d_arr *p1 =
      two_d_arr_init(ARRAY_SIZE(p1i), ARRAY_SIZE(p1i[0]), p1i);
  struct two_d_arr *p2 =
      two_d_arr_init(ARRAY_SIZE(p2i), ARRAY_SIZE(p2i[0]), p2i);
  struct two_d_arr *p3 =
      two_d_arr_init(ARRAY_SIZE(p3i), ARRAY_SIZE(p3i[0]), p3i);
  printf("%d\n",
         numberOfPairs(p1->arr, p1->row_size, p1->col_size)); // expect: 0
  printf("%d\n",
         numberOfPairs(p2->arr, p2->row_size, p2->col_size)); // expect: 2
  printf("%d\n",
         numberOfPairs(p3->arr, p3->row_size, p3->col_size)); // expect: 2
  two_d_arr_free(p1);
  two_d_arr_free(p2);
  two_d_arr_free(p3);
}
