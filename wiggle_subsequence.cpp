#include "leetcode.h"

class Solution {
public:
  int wiggleMaxLength(vector<int> &nums) {
    int ans = 1, i = 1;
    while (i < nums.size() && nums[i] == nums[i - 1])
      i++;
    if (i == nums.size())
      return 1;
    bool upper = nums[i - 1] > nums[i];
    for (; i < nums.size(); i++)
      if ((upper && nums[i] < nums[i - 1]) || !upper && nums[i] > nums[i - 1])
        upper = !upper, ans++;
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
  cout << obj.wiggleMaxLength(nums);
}
