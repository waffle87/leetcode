// 1043. Partition Array for Maximum Sum
#include "leetcode.h"

/*
 * given an integeer array 'arr', partition the array into contiguous subarrays
 * of length at most 'k'. after partitioning, each subarray has their values
 * changed to become the maximum value of that subarray. return the largest sum
 * of the given array after partitioning. test cases are generated so that
 * answer fits in a 32-bit integer
 */

class Solution {
public:
  int maxSumAfterPartitioning(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
      int curr = 0, best = 0;
      for (int j = 1; j <= k && i - j >= 0; ++j) {
        curr = max(curr, arr[i - j]);
        best = max(best, dp[i - j] + curr * j);
      }
      dp[i] = best;
    }
    return dp[n];
  }
};

int main() {
  Solution obj;
  vector<int> a1 = {1, 15, 7, 9, 2, 5, 10},
              a2 = {1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3}, a3 = {1};
  printf("%d\n", obj.maxSumAfterPartitioning(a1, 3)); // expect: 84
  printf("%d\n", obj.maxSumAfterPartitioning(a2, 4)); // expect: 83
  printf("%d\n", obj.maxSumAfterPartitioning(a3, 1)); // expect: 1
}
