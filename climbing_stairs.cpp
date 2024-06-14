#include "leetcode.h"

class Solution {
public:
  int climbStairs(int n) {
    /*
     * base case
     * because if 0 steps -> 0 ways,
     * 1 step -> 1 way, & 2 step -> 2 ways
     */
    if (n <= 2)
      return n;
    /*
     * last step was either:
     * 1 step (oneStep) or 2 steps (twoStep)
     * so simply add the two values (fibonacci sequence)
     */
    int oneStep = 1, twoStep = 2, ans;
    for (int i = 3; i <= n; i++) { // 0-2 steps already determined
      ans = oneStep + twoStep;
      oneStep = twoStep;
      twoStep = ans;
    }
    return ans;
  }
};

int main() {
  Solution obj;
  cout << obj.climbStairs(4);
}
