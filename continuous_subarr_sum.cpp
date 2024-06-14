#include "leetcode.h"

class Solution {
public:
  bool checkSubarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> um;
    int s = 0;
    um[0] = -1;
    for (int i = 0; i < nums.size(); i++) {
      s += nums[i];
      if (k != 0)
        s %= k;
      if (um.find(s) != um.end()) {
        if (i - um[s] > 1)
          return true;
      } else
        um[s] = i;
    }
    return false;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {23, 2, 4, 6, 7};
  int k = 6;
  if (obj.checkSubarraySum(nums, k))
    cout << "true";
  else
    cout << "false";
}
