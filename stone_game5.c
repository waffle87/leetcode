// 1563. Stone Game V
#include "leetcode.h"

/*
 * there are several stones arranged in a row, and each stone has an associated
 * value which is an integer given in the array 'stoneValue'. in each round of
 * the game, alice divides the row into two non-empty rows, then bob calculates
 * the value of each row which is the sum of the values of all the stones in
 * this row. bob throws away the row which has the maximum value, and alice's
 * score increases by the value of the remaining row. if the value of the two
 * rows are equal, bob lets alice decicde which row will be thrown away. the
 * next round starts with the remaining row. the game ends when there is only
 * one stone remaining. alice's score is initially zero. return the maximum
 * score that alice can obtain.
 */

int dfs(int *stoneValue, int left, int right, int **dp) {
  if (left == right)
    return 0;
  if (dp[left][right])
    return dp[left][right];
  int sum = 0;
  for (int i = left; i <= right; i++)
    sum += stoneValue[i];
  int sum_l = 0;
  for (int i = left; i < right; ++i) {
    sum_l += stoneValue[i];
    int sum_r = sum - sum_l;
    if (sum_l < sum_r)
      dp[left][right] =
          fmax(dp[left][right], dfs(stoneValue, left, i, dp) + sum_l);
    else if (sum_l > sum_r)
      dp[left][right] =
          fmax(dp[left][right], dfs(stoneValue, i + 1, right, dp) + sum_r);
    else
      dp[left][right] =
          fmax(dp[left][right], fmax(dfs(stoneValue, left, i, dp),
                                     dfs(stoneValue, i + 1, right, dp)) +
                                    sum_l);
  }
  return dp[left][right];
}

int stoneGameV(int *stoneValue, int stoneValueSize) {
  int n = stoneValueSize;
  int **dp = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
    dp[i] = (int *)calloc(n, sizeof(int));
  int ans = dfs(stoneValue, 0, n - 1, dp);
  for (int i = 0; i < n; i++)
    free(dp[i]);
  free(dp);
  return ans;
}

int main() {
  int sv1[] = {6, 2, 3, 4, 5, 5};
  int sv2[] = {7, 7, 7, 7, 7, 7, 7};
  int sv3[] = {4};
  int r1 = stoneGameV(sv1, ARRAY_SIZE(sv1));
  int r2 = stoneGameV(sv2, ARRAY_SIZE(sv2));
  int r3 = stoneGameV(sv3, ARRAY_SIZE(sv3));
  printf("%d\n", r1);
  assert(r1 == 18);
  printf("%d\n", r2);
  assert(r2 == 28);
  printf("%d\n", r3);
  assert(r3 == 0);
}
