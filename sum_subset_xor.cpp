#include "leetcode.h"

/*
  000 => {empty set}
  001 => {set with only first element}
  010 => {set with only second element}
  011 => {set with first and second element}
  100 ... and so on
  101
  110
  111 => {subset with all three elements}
*/

class Solution {
public:
  int subsetXORSum(vector<int> &nums) {
    int n = nums.size(), subsetNum = pow(2, n), ans = 0;
    for (int i = 1; i < subsetNum; ++i) {
      int runningXOR = 0;
      for (int j = 0, bits = i; j < nums.size(); ++j, bits >>= 1)
        if (bits & 1)
          runningXOR ^= nums[j];
      ans += runningXOR;
    }
    return ans;
  }
};

int main() {
  vector<int> nums = {3, 4, 5, 6, 7, 8};
  Solution obj;
  cout << obj.subsetXORSum(nums);
}
