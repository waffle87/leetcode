#include "leetcode.h"

class Solution {
public:
  vector<int> findErrorNums(vector<int> &nums) {
    int p = 0, ac1 = 0, ac2 = 0;
    for (uint i = 0; i < nums.size(); ++i)
      p ^= (i + 1) ^ nums[i];
    p &= -p;
    for (uint i = 0; i < nums.size(); ++i) {
      ((nums[i] & p) == 0) ? ac1 ^= nums[i] : ac2 ^= nums[i];
      (((i + 1) & p) == 0) ? ac1 ^= i + 1 : ac2 ^= i + 1;
    }
    for (auto n : nums)
      if (n == ac1)
        return {ac1, ac2};
    return {ac2, ac1};
  }
};
