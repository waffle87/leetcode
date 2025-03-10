// 974. Subarray Sums Divisible by K
#include "leetcode.h"
#include <vector>

/*
 * given: integer array 'nums' and integer 'k'
 * return: number of non-empty subarrays that
 * have a sum divisible by 'k'.
 * a subarray is a contiguous part of an array
 */

class Solution {
public:
  int subarraysDivByK(vector<int> &nums, int k) {
    vector<int> count(k);
    count[0] = 1;
    int prefix = 0, ans = 0;
    for (int i : nums) {
      prefix = (prefix + i % k + k) % k;
      ans += count[prefix]++;
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> nums1 = {4, 5, 0, -2, -3, 1}, nums2 = {5};
  cout << obj.subarraysDivByK(nums1, 5); // expect: 7
  cout << obj.subarraysDivByK(nums2, 9); // expect: 0
  return 0;
}
