#include "leetcode.h"

/*
 * given array 'nums' of integers, return how
 * many of them contain an even number of digits.
 */

class Solution {
public:
  int findNumbers(vector<int> &nums) {
    int ans = 0;
    // use auto to identify data type & iterate through array
    for (auto i : nums)
      /*
       * log10 returns a decimal so convert it to int
       * it also returns n - 1. eg. log10(100) = 2
       * use bitwise and to check if it's odd
       */
      ans += log10(i) & 1;
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> nums1 = {12, 345, 2, 6, 7896}, nums2 = {555, 901, 482, 1771};
  cout << obj.findNumbers(nums1) << endl; // expect: 2
  cout << obj.findNumbers(nums2) << endl; // expect: 1
}
