// 137. Single Number II
#include "leetcode.h"

/*
 * given an integer array 'nums' where every element appears three times except
 * for one, which appears exactly once. find the single element and return it.
 * you must implement a solution with a linear runtime complexity and use only
 * constant extra space.
 */

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    unordered_map<int, int> um;
    for (auto i : nums)
      um[i]++;
    for (auto i : um)
      if (i.second == 1)
        return i.first;
    return -1;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {2, 2, 3, 2}, n2 = {0, 1, 0, 1, 0, 1, 99};
  printf("%d\n", obj.singleNumber(n1)); // expect: 3
  printf("%d\n", obj.singleNumber(n2)); // expect: 99
}
