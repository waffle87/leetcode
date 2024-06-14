#include "leetcode.h"

class Solution {
public:
  int missingNumber(vector<int> &nums) {
    int sum = 0, n = nums.size();
    int total = n * (n + 1) / 2;
    for (auto number : nums)
      sum += number;
    return total - sum;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
  cout << obj.missingNumber(nums);
}
