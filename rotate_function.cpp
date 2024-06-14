#include "leetcode.h"

class Solution {
public:
  int maxRotateFunction(vector<int> &nums) {
    long sum = 0, fn = 0;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
      sum += nums[i];
      fn += (i * nums[i]);
    }
    long l = 1, r, newFn = fn;
    while (l < len) {
      r = l + len - 1;
      long removed = (l - 1) * nums[l - 1];
      long added = r * nums[r % len];
      newFn -= newFn - removed + added - sum;
      fn = max(fn, newFn);
      l++;
    }
    return (int)fn;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {4, 3, 2, 6};
  cout << obj.maxRotateFunction(nums);
}
