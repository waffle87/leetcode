// 689. Maximum Sum of 3 Non-Overlapping Subarrays
#include "leetcode.h"

/*
 * given an integer array 'nums' and an integer 'k', find three non-overlapping
 * subarrays of length 'k' with maximum sum and return them. return the result
 * as a list of indices representing the starting position of each interval
 * (0-indexed). if there are multiple answers, return the lexicographcially
 * smallest one
 */

class Solution {
public:
  vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
    int n = nums.size(), max_sum = 0;
    vector<int> sum = {0}, left(n, 0), right(n, n - k), ans(3, 0);
    for (int i : nums)
      sum.push_back(sum.back() + i);
    for (int i = k, tot = sum[k] - sum[0]; i < n; i++) {
      if (sum[i + 1] - sum[i + 1 - k] > tot) {
        left[i] = i + 1 - k;
        tot = sum[i + 1] - sum[i + 1 - k];
      } else
        left[i] = left[i - 1];
    }
    for (int i = n - k - 1, tot = sum[n] - sum[n - k]; i >= 0; i--) {
      if (sum[i + k] - sum[i] >= tot) {
        right[i] = i;
        tot = sum[i + k] - sum[i];
      } else
        right[i] = right[i + 1];
    }
    for (int i = k; i <= n - 2 * k; i++) {
      int l = left[i - 1], r = right[i + k];
      int tot =
          (sum[i + k] - sum[i]) + (sum[l + k] - sum[l]) + (sum[r + k] - sum[r]);
      if (tot > max_sum) {
        max_sum = tot;
        ans = {l, i, r};
      }
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {1, 2, 1, 2, 6, 7, 5, 1}, n2 = {1, 2, 1, 2, 1, 2, 1, 2, 1};
  vector<int> msots1 = obj.maxSumOfThreeSubarrays(n1, 2);
  vector<int> msots2 = obj.maxSumOfThreeSubarrays(n2, 2);
  for (auto i : msots1)
    printf("%d ", i); // expect: 0 3 5
  printf("\n");
  for (auto i : msots2)
    printf("%d ", i); // expect: 0 2 4
  printf("\n");
}
