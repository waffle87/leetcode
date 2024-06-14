// 1498. Number of Subsequences That Satisfy the Given Sum Condition
#include "leetcode.h"

/*
 * given an array of integers 'nums' and an integer 'target'
 * return the numbe of non-empty subsequences of 'nums' such
 * that the sum of the minimum and maximum element on it is
 * less or equal to 'target'. return modulo 10^9+7
 */

class Solution {
public:
  int numSubSeq(vector<int> &nums, int target) {
    int ans = 0, mod = 1000000007;
    vector<int> pre = {0, 1};
    for (auto i = pre.size(); i <= nums.size(); ++i)
      pre.push_back((pre.back() << 1) % mod);
    sort(nums.begin(), nums.end());
    for (int i = 0, j = nums.size() - 1; i <= j; ++i) {
      while (i <= j && nums[i] + nums[j] > target)
        --j;
      ans = (ans + pre[j - i + 1]) % mod;
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {3, 5, 6, 7}, n2 = {3, 3, 6, 8}, n3 = {2, 3, 3, 4, 6, 7};
  printf("%d\n", obj.numSubSeq(n1, 9));  // expect: 4
  printf("%d\n", obj.numSubSeq(n2, 10)); // expect: 6
  printf("%d\n", obj.numSubSeq(n3, 12)); // expect: 61
}
