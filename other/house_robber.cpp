#include "leetcode.h"

class Solution {
public:
  int rob(vector<int> &nums) {
    // space-optimized dynamic programming approach
    int prev = 0, prev2 = 0, curr = 0;
    for (auto i : nums) {
      curr = max(prev, i + prev2);
      prev2 = prev;
      prev = curr;
    }
    return curr;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {1, 2, 3, 1};
  cout << obj.rob(nums); // expect 4
}
