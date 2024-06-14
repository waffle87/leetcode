#include "leetcode.h"

class Solution {
public:
  int minMoves2(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int mid = nums.size() / 2, steps = 0;
    for (int i = 0; i < nums.size(); i++)
      steps += abs(nums[i] - nums[mid]);
    return steps;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {1, 2, 3};
  cout << obj.minMoves2(nums);
}
