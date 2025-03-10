#include "leetcode.h"

class Solution {
public:
  int minOperations(vector<int> &nums) {
    int n = nums.size(), ans = n, j = 0;
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      while (j < nums.size() && nums[j] < nums[i] + n)
        ++j;
      ans = min(ans, n - j + i);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {4, 2, 5, 3};
  cout << obj.minOperations(nums);
}
