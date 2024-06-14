#include "leetcode.h"

class Solution {
public:
  int longestOnes(vector<int> &nums, int k) {
    int start = 0, end, count = 0, ans = 0;
    for (int end = 0; end < nums.size(); end++) {
      if (!nums[end])
        count++;
      if (count == k + 1) {
        while (nums[start])
          start++;
        start++;
        count--;
      }
      ans = max(ans, end - start + 1);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
  int k = 2;
  cout << obj.longestOnes(nums, k);
}
