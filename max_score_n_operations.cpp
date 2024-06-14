// 1799. Maximize Score After N Operations
#include "leetcode.h"

/*
 * given 'nums', an array of positive integers of size '2 * n'. you must perform
 * 'n' operations on this array. in the i'th operation (1-index), you will:
 * - choose two elements 'x' and 'y'
 * - receive a score of 'i * gcd(x, y)'
 * - remove 'x' and 'y' from 'nums'
 * return the maximum score you can receive after performing 'n' operations. the
 * function 'gcd(x, y)' is the greatest common divisor.
 */

class Solution {
public:
  int maxScore(vector<int> nums) {
    m = nums.size();
    n = m / 2;
    return dp(nums, 1, 0);
  }

private:
  int gcd_memo[14][14] = {};
  int memo[1 << 4] = {};
  int m, n;
  int dp(vector<int> &nums, int op, int mask) {
    if (op > n)
      return 0;
    if (memo[mask])
      return memo[mask];
    for (int i = 0; i < m; ++i) {
      if ((mask >> i) & 0x1)
        continue;
      for (int j = i + 1; j < m; ++j) {
        if ((mask >> j) & 0x1)
          continue;
        int new_mask = (0x1 << i) | (0x1 << j) | mask;
        int score = op * gcd(nums, i, j) + dp(nums, op + 1, new_mask);
        memo[mask] = max(memo[mask], score);
      }
    }
    return memo[mask];
  }
  int gcd(vector<int> &nums, int i, int j) {
    if (gcd_memo[i][j])
      return gcd_memo[i][j];
    return gcd_memo[i][j] = __gcd(nums[i], nums[j]);
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {1, 2};
  vector<int> n2 = {3, 4, 6, 8};
  vector<int> n3 = {1, 2, 3, 4, 5, 6};
  printf("%d\n", obj.maxScore(n1)); // expect: 1
  printf("%d\n", obj.maxScore(n2)); // expect: 11
  printf("%d\n", obj.maxScore(n3)); // expect: 14
}
