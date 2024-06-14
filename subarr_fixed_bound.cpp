// 2444. Count Subarrays With Fixed Bounds
#include "leetcode.h"

/*
 * given integer array 'nums' and two integers 'min_k' and 'max_k'. a fixed
 * bound subarr of 'nums' is a subarray that satisfies the following conditions:
 * minimum value in subarray is equal to 'min_k'. the max value in subarray is
 * equal to 'max_k'. return number of fixed-bound subarrays.
 */

class Solution {
public:
  long long countSubarrays(vector<int> &nums, int min_k, int max_k) {
    long long ans = 0, n = nums.size();
    for (int i = 0, j = 0; i <= n; ++i)
      if (i == n || nums[i] < min_k || nums[i] > max_k)
        for (int p1 = j, p2 = j; j <= i; ++j) {
          while (p1 < i && (p1 < j || nums[p1] != min_k))
            ++p1;
          while (p2 < i && (p2 < j || nums[p2] != max_k))
            ++p2;
          ans += i - max(p1, p2);
        }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {1, 3, 5, 2, 7, 5}, n2 = {1, 1, 1, 1};
  cout << obj.countSubarrays(n1, 1, 5) << endl; // expect: 2
  cout << obj.countSubarrays(n2, 1, 1) << endl; // expect: 10
}
