// 120. Triangle
#include "leetcode.h"

/*
 * given a 'triangle' array, return the minimum path sum from top to bottom. for
 * each step, you may move to an adjacent number of the row below. more
 * formally, if you are index 'i', on the current row, you may move to either
 * index 'i' or index 'i + 1' on the next row.
 */

int minimumTotal(int **triangle, int triangleSize, int *triangleColSize) {
  int prev = triangleColSize[triangleSize - 1];
  int *memo = (int *)malloc(prev * sizeof(int));
  for (int i = 0; i < prev; ++i)
    memo[i] = triangle[triangleSize - 1][i];
  for (int r = triangleSize - 2; r >= 0; --r)
    for (int c = 0; c < triangleColSize[r]; ++c)
      memo[c] = triangle[r][c] + fmin(memo[c], memo[c + 1]);
  int ans = memo[0];
  free(memo);
  return ans;
}

int main() {
  int t1i[4][4] = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}, tcs1[] = {};
  int t2i[1][1] = {{-10}};
  for (int i = 0; i < ARRAY_SIZE(t1i); i++)
    tcs1[i] = ARRAY_SIZE(t1i[0]);
  struct two_d_arr *t1 =
      two_d_arr_init(ARRAY_SIZE(t1i), ARRAY_SIZE(t1i[3]), t1i);
  struct two_d_arr *t2 =
      two_d_arr_init(ARRAY_SIZE(t2i), ARRAY_SIZE(t2i[0]), t2i);
  printf("%d\n", minimumTotal(t1->arr, t1->row_size, tcs1)); // expect: 11
  printf("%d\n",
         minimumTotal(t2->arr, t2->row_size, t2->col_size)); // expect: -10
  two_d_arr_free(t1);
  two_d_arr_free(t2);
}
