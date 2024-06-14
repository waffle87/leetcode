// 1043. Partition Array for Maximum Sum
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given an integeer array 'arr', partition the array into contiguous subarrays
 * of length at most 'k'. after partitioning, each subarray has their values
 * changed to become the maximum value of that subarray. return the largest sum
 * of the given array after partitioning. test cases are generated so that
 * answer fits in a 32-bit integer
 */

int maxSumAfterPartitioning(int *arr, int arr_size, int k) {
  int n = arr_size, *dp = malloc((n + 1) * sizeof(int));
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    int m = arr[i];
    dp[i + 1] = arr[i] + dp[i];
    for (int j = i - 1; j >= fmax(0, i - k + 1); j--) {
      m = fmax(m, arr[j]);
      dp[i + 1] = fmax(dp[i + 1], m * (i - j + 1) + dp[j]);
    }
  }
  int ans = dp[n];
  free(dp);
  return ans;
}

int main() {
  int a1[] = {1, 15, 7, 9, 2, 5, 10}, a2[] = {1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3},
      a3[] = {1};
  printf("%d\n", maxSumAfterPartitioning(a1, 7, 3));  // expect: 84
  printf("%d\n", maxSumAfterPartitioning(a2, 11, 4)); // expect: 83
  printf("%d\n", maxSumAfterPartitioning(a3, 1, 1));  // expect: 1
}
