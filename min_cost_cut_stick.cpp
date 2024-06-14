// 1547. Minimum Cost to Cut a Stick
#include "leetcode.h"

/*
 * given a wooden stick of length 'n' units. the stick is labelled from 0 to
 * 'n'. for example, a stick of length 6 is labelled as follows (see image).
 * given an integer array 'cuts' where 'cuts[i]' denotes a position you should
 * perform a cut at. you should perform the cuts in order, you can change the
 * order of the cuts as you wish. the cost of one cut is the length of the stick
 * to be cut, the total cost is the sum of costs of all cuts. when you cut a
 * stick, it will be split into two smaller sticks ie. the sum of their lengths
 * is the length of the stick before the cut. refer to first example for better
 * explanation (see image). return minimum cost of the cuts
 */

class Solution {
  int dp[102][102] = {};
  int dfs(vector<int> &cuts, int i, int j) {
    if (j - i <= 1)
      return 0;
    if (!dp[i][j]) {
      dp[i][j] = INT_MAX;
      for (auto k = i + 1; k < j; ++k)
        dp[i][j] = min(dp[i][j],
                       cuts[j] - cuts[i] + dfs(cuts, i, k) + dfs(cuts, k, j));
    }
    return dp[i][j];
  }

public:
  int minCost(int n, vector<int> &cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(begin(cuts), end(cuts));
    return dfs(cuts, 0, cuts.size() - 1);
  }
};

int main() {
  Solution obj;
  vector<int> c1 = {1, 3, 4, 5};
  vector<int> c2 = {5, 6, 1, 4, 2};
  printf("%d\n", obj.minCost(7, c1)); // expect: 16
  printf("%d\n", obj.minCost(9, c2)); // expect: 22
}
