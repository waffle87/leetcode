#include "leetcode.h"

class Solution {
public:
  int maxResult(vector<int> &nums, int k) {
    int ans = 0;
    deque<int> dq;
    for (int i = nums.size() - 1; i >= 0; i--) {
      ans = nums[i] + (dq.empty() ? 0 : nums[dq.front()]);
      while (!dq.empty() && ans > nums[dq.back()])
        dq.pop_back();
      dq.push_back(i);
      if (dq.front() >= i + k)
        dq.pop_front();
      nums[i] = ans;
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {1, -1, -2, 4, -7, 3};
  int k = 2;
  cout << obj.maxResult(nums, k);
}
