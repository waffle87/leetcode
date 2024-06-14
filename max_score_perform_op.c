// 1770. Maximum Score from Performing Multiplication Operations
#include "leetcode.h"

/*
 * given two 0 indexed integer arrays 'nums' and multipliers of size n and m
 * respectively, where n >= m. you begin with a score of 0. you want to perform
 * exactly m operations. on the i'th operation, you will choose one integer x
 * from either the start or the end of the array 'nums'. add 'multipliers[i] *
 * x' to your score. note that 'multipliers[0]' correspons to the first
 * operation, 'multipliers[1]' to the second operation and so on. return the
 * maximum score after performing m operations.
 */

int maximumScore(int *nums, int numsSize, int *multipliers,
                 int multipliersSize) {
  int dp_size = fmin(numsSize, multipliersSize);
  int *row = &nums[numsSize - dp_size], *col = nums;
  int **dp = malloc(dp_size * sizeof(int *));
  for (int i = 0; i < dp_size; i++) {
    dp[i] = malloc(dp_size * sizeof(int));
    dp[i][i] = fmax(multipliers[dp_size - 1] * row[i],
                    multipliers[dp_size - 1] * col[i]);
  }
  for (int i = 1; i < dp_size; i++)
    for (int j = 0; j < dp_size - i; j++)
      dp[j][i + j] =
          fmax(col[j] * multipliers[dp_size - 1 - i] + dp[j + 1][i + j],
               row[i + j] * multipliers[dp_size - 1 - i] + dp[j][i + j - 1]);
  return dp[0][dp_size - 1];
}

int main() {
  int n1[] = {1, 2, 3}, m1[] = {3, 2, 1}, n2[] = {-5, -3, -3, -2, 7, 1},
      m2[] = {-10, -5, 3, 4, 6};
  printf("%d\n",
         maximumScore(n1, ARRAY_SIZE(n1), m1, ARRAY_SIZE(m1))); // expect: 14
  printf("%d\n",
         maximumScore(n2, ARRAY_SIZE(n2), m2, ARRAY_SIZE(m2))); // expect: 102
}
