// 403. Frog Jump
#include "leetcode.h"

/*
 * a frog is crossing a river. the river is divided into some number of units
 * and at each unit, there may or may not exist a stone. the frog can jump on a
 * stone, but it must not jump into the water. given a list of 'stones'
 * positions in (units) in sorted ascending order, determine if the frog can
 * cross the river by landing on the last stone. initially, the frog is on the
 * first stone and assumes the frist just must be 1 unit. if the frog's last
 * jump was k units, its next jujp must be either 'k - 1' or 'k + 1' units. the
 * frog can only jump in the forward direction.
 */

class Solution {
  bool process(vector<int> &stones, map<int, int> &mp, int i, int k,
               vvd & dp) {
    if (i == stones.size() - 1)
      return dp[i][k] = 1;
    if (dp[i][k] != -1)
      return dp[i][k];
    for (int t = k - 1; t <= k + 1; t++)
      if (t && mp.find(stones[i] + t) != mp.end()) {
        int idx = mp[stones[i] + t];
        if (process(stones, mp, idx, t, dp))
          return dp[i][k] = 1;
      }
    return dp[i][k] = 0;
  }

public:
  bool canCross(vector<int> &stones) {
    int n = stones.size();
    map<int, int> mp;
    for (int i = 0; i < n; i++)
      mp[stones[i]] = i;
    vvd dp(n + 1, vector<int>(n + 1, -1));
    return process(stones, mp, 0, 0, dp);
  }
};

int main() {
  Solution obj;
  vector<int> s1 = {0, 1, 3, 5, 6, 8, 12, 17}, s2 = {0, 1, 2, 3, 4, 8, 9, 11};
  printf("%d\n", obj.canCross(s1)); // expect: 1
  printf("%d\n", obj.canCross(s2)); // expect: 0
}
