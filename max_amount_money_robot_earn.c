// 3418. Maximum Amount of Money Robot Can Earn
#include "leetcode.h"

/*
 * you are given an 'm x n' grid. a robot starts at the top left corner of the
 * grid '(0, 0)' and wants to reach the bottom right corner '(m - 1, n - 1)'.
 * the robot can either move right or down at any point in time. the grid
 * contains a value 'coins[i][j]' in each cell the robot has a special ability
 * to neutralise in at most 2 cells on its path, prevening them from stealing
 * coins in those cells. return the maximum profit the robot can gain on the
 * route.
 */

int dfs(int **coins, int ***memo, int m, int n, int i, int j, int k) {
  if (i < 0 || j < 0)
    return INT_MIN;
  int x = coins[i][j];
  if (!i && !j)
    return k > 0 ? (x > 0 ? x : 0) : x;
  if (memo[i][j][k] != INT_MIN)
    return memo[i][j][k];
  int res = fmax(dfs(coins, memo, m, n, i - 1, j, k),
                 dfs(coins, memo, m, n, i, j - 1, k)) +
            x;
  if (k > 0 && x < 0)
    res = fmax(res, fmax(dfs(coins, memo, m, n, i - 1, j, k - 1),
                         dfs(coins, memo, m, n, i, j - 1, k - 1)));
  memo[i][j][k] = res;
  return res;
}
int maximumAmount(int **coins, int coinsSize, int *coinsColSize) {
  int m = coinsSize, n = coinsColSize[0];
  int ***memo = (int ***)malloc(m * sizeof(int **));
  for (int i = 0; i < m; i++) {
    memo[i] = (int **)malloc(n * sizeof(int *));
    for (int j = 0; j < n; j++) {
      memo[i][j] = (int *)malloc(3 * sizeof(int));
      for (int k = 0; k < 3; k++)
        memo[i][j][k] = INT_MIN;
    }
  }
  int res = dfs(coins, memo, m, n, m - 1, n - 1, 2);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++)
      free(memo[i][j]);
    free(memo[i]);
  }
  free(memo);
  return res;
}

int main() {
  int c1i[3][3] = {{0, 1, -1}, {1, -2, 3}, {2, -3, 4}};
  int c2i[2][3] = {{10, 10, 10}, {10, 10, 10}};
  struct two_d_arr *c1 =
      two_d_arr_init(ARRAY_SIZE(c1i), ARRAY_SIZE(c1i[0]), c1i);
  struct two_d_arr *c2 =
      two_d_arr_init(ARRAY_SIZE(c2i), ARRAY_SIZE(c1i[0]), c2i);
  int r1 = maximumAmount(c1->arr, c1->row_size, c1->col_size);
  int r2 = maximumAmount(c2->arr, c2->row_size, c2->col_size);
  printf("%d\n", r1);
  assert(r1 == 8);
  printf("%d\n", r2);
  assert(r2 == 40);
  two_d_arr_free(c1);
  two_d_arr_free(c2);
}
