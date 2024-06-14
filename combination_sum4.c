// 377. Combination Sum IV
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given an array of disticint integers 'nums' and a target integer 'target',
 * return the number of possible combinations that add up to 'target'. the test
 * cases are generated such that the answer can fit in a 32 bit integer.
 */

int cmp(const void *a, const void *b) { return *(int *)b - *(int *)b; }

int combinationSum4(int *nums, int nums_size, int target) {
  qsort(nums, nums_size, sizeof(int), cmp);
  long long *dp = (long long *)calloc(target + 1, sizeof(long long));
  dp[0] = 1;
  int ans;
  for (int i = 1; i <= target; i++)
    for (int j = 0; j < nums_size; j++) {
      if (i >= nums[j]) {
        dp[i] += dp[i - nums[j]];
        if (dp[i] >= INT_MAX)
          dp[i] = INT_MAX;
      } else
        break;
    }
  ans = dp[target];
  free(dp);
  return ans;
}

int main() {
  int n1[] = {1, 2, 3}, n2[] = {9};
  printf("%d\n", combinationSum4(n1, 3, 4)); // expect: 7
  printf("%d\n", combinationSum4(n2, 1, 3)); // expect: 0
}
