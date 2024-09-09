// 1000. Minimum Cost to Merge Stones
#include "leetcode.h"

/*
 * there are 'n' piles of 'stones' arrange in a row. the i'th pile has
 * 'stones[i]' stones. a move consists of merging exactly 'k' consecutive piles
 * into one pile and the cost of this move is equal to the total number of
 * stones in these 'k' piles. return the minimum cost to merge all piles of
 * stones into one pile. if it is impossible, return -1
 */

#define MAX_CNT 20

int mergeStones(int *stones, int stonesSize, int k) {
  if ((stonesSize - 1) % (k - 1))
    return -1;
  int sum = 0, dp[MAX_CNT][MAX_CNT] = {0}, sum_arr[MAX_CNT + 1] = {0};
  for (int i = 0; i < stonesSize; i++)
    sum = sum_arr[i] = sum + stones[i];
  for (int i = 0; i < stonesSize; i++) {
    int j = i + k - 1;
    if (j < stonesSize) {
      dp[i][j] = sum_arr[j];
      if (i)
        dp[i][j] -= sum_arr[i - 1];
    }
  }
  for (int i = 0; i < stonesSize - k; i++)
    for (int j = 0, n = k + i; n < stonesSize; j++, n++) {
      dp[j][n] = INT_MAX;
      for (int mid = j; mid < n; mid += (k - 1)) {
        int res = dp[j][mid] + dp[mid + 1][n];
        dp[j][n] = res < dp[j][n] ? res : dp[j][n];
      }
      if (!((n - j) % (k - 1))) {
        dp[j][n] += sum_arr[j];
        if (j)
          dp[j][n] -= sum_arr[j - 1];
      }
    }
  return dp[0][stonesSize - 1];
}

int main() {
  int s1[] = {3, 2, 4, 1}, s2[] = {3, 2, 4, 1}, s3[] = {3, 5, 1, 2, 6};
  printf("%d\n", mergeStones(s1, ARRAY_SIZE(s1), 2)); // expect: 20
  printf("%d\n", mergeStones(s2, ARRAY_SIZE(s2), 3)); // expect: -1
  printf("%d\n", mergeStones(s3, ARRAY_SIZE(s3), 3)); // expect: 25
}
