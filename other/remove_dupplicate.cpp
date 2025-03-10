#include "leetcode.h"

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    int ans = 0;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[ans] != nums[i])
        ans++;
      nums[ans] = nums[i];
    }
    return ans + 1;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  cout << obj.removeDuplicates(nums);
}
