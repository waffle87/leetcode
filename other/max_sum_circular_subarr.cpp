// 918. Maximum Sum Circular Subarray
#include "leetcode.h"

/*
 * given: circular int array 'nums' of length 'n', return the max possible
 * sum of non-empty subarray of 'nums'
 *
 * a circular array means the end of the array connects to the beginning.
 * formally, the previous element of 'nums[i]' is 'nums[(i -/+ 1) % n]'
 *
 * a subarray may only include each element of the fixed buffer 'nums' at
 * most once. formally, for a subarray 'nums[i], nums[i + 1], ..., nums[j]'
 * there does not exist i <= k1, k2 <= j with k1 % n == k2 % n
 */

class Solution {
public:
  int maxSubarraySumCircular(vector<int> &nums) {
    int sum = 0;
    for (int i : nums)
      sum += i;
    int s1 = helper(nums.begin(), nums.end());
    for (int &i : nums)
      i *= -1;
    int s2 = sum + helper(nums.begin(), nums.end() - 1);
    int s3 = sum + helper(nums.begin() + 1, nums.end());
    return max(s1, max(s2, s3));
  }

private:
  int helper(vector<int>::iterator p, vector<int>::iterator q) {
    int res = INT_MIN, n = 0;
    for (auto i = p; i != q; i++) {
      n += *i;
      res = max(res, n);
      if (n < 0)
        n = 0;
    }
    return res;
  }
};

int main() {
  Solution obj;
  vector<int> nums1 = {-2}, nums2 = {5, -3, 5}, nums3 = {-3, -2, -3};
  cout << obj.maxSubarraySumCircular(nums1) << endl; // expect: 3
  cout << obj.maxSubarraySumCircular(nums2) << endl; // expect: 10
  cout << obj.maxSubarraySumCircular(nums3) << endl; // expect: -2
}
