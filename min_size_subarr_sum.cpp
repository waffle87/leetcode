// 209. Minimum Size Subarray Sum
#include "leetcode.h"

/*
 * given an array of positive integer 'nums' and a positive integer 'target',
 * return the minimal length of a subarray whose sum is greater than or equal to
 * 'target'. if there is no such subarray, return 0 instead.
 */

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int i = 0, n = nums.size(), ans = n + 1;
    for (int j = 0; j < n; ++j) {
      target -= nums[j];
      while (target <= 0) {
        ans = min(ans, j - i + 1);
        target += nums[i++];
      }
    }
    return ans % (n + 1);
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {2, 3, 1, 2, 4, 3}, n2 = {1, 4, 4},
              n3 = {1, 1, 1, 1, 1, 1, 1, 1};
  printf("%d\n", obj.minSubArrayLen(7, n1));  // expect: 2
  printf("%d\n", obj.minSubArrayLen(4, n2));  // expect: 1
  printf("%d\n", obj.minSubArrayLen(11, n3)); // expect: 0
}
