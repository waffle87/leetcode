// 1659. Maximize Grid Happiness
#include "leetcode.h"

/*
 * you are given four integers 'm', 'n', 'introvertsCount', and
 * 'extrovertsCount'. you have an 'm * n' grid and there are two types of
 * people: introverts and extroverts. there are 'introvertsCount' introverts and
 * 'extrovertsCount' extroverts. you should decide how many people ou want to
 * live in the grid and assign each of them one grid cell. note that you do not
 * have to have all the people living in the grid. neighbours live directly
 * adjacent cells, north, east, south, and west of a person's cell. the grid
 * happiness is the sum of each person's happiness. return the maximum possible
 * grid happiness
 */

class Solution {
private:
  int dp[25][7][7][64][64] = {};
  int n_cost(int m, int n, int i, int j, int introvert_mask, int extrovert_mask,
             int d) {
    int diff = 0, up = (1 << (n - 1));
    if (j && (introvert_mask & 1))
      diff += d - 30;
    if (i && (introvert_mask & up))
      diff += d - 30;
    if (j && (extrovert_mask & 1))
      diff += d + 20;
    if (i && (extrovert_mask & up))
      diff += d + 20;
    return diff;
  }
  int dfs(int m, int n, int p, int in, int out, int introvert_mask,
          int extrovert_mask) {
    int i = p / n, j = p % n;
    if (i >= m)
      return 0;
    if (dp[p][in][out][introvert_mask][extrovert_mask])
      return dp[p][in][out][introvert_mask][extrovert_mask] - 1;
    int n_introvert_mask = (introvert_mask << 1) & 63,
        n_extrovert_mask = (extrovert_mask << 1) & 63;
    int res = dfs(m, n, p + 1, in, out, n_introvert_mask, n_extrovert_mask);
    if (in) {
      int diff = n_cost(m, n, i, j, introvert_mask, extrovert_mask, -30) + 120;
      res = max(res, diff + dfs(m, n, p + 1, in - 1, out, n_introvert_mask + 1,
                                n_extrovert_mask));
    }
    if (out) {
      int diff = n_cost(m, n, i, j, introvert_mask, extrovert_mask, 20) + 40;
      res = max(res, diff + dfs(m, n, p + 1, in, out - 1, n_introvert_mask,
                                n_extrovert_mask + 1));
    }
    return res;
  }

public:
  int getMaxGridHappiness(int m, int n, int introvertsCount,
                          int extrovertsCount) {
    return dfs(m, n, 0, introvertsCount, extrovertsCount, 0, 0);
  }
};

int main() {
  Solution obj;
  printf("%d\n", obj.getMaxGridHappiness(2, 3, 1, 2)); // expect: 240
  printf("%d\n", obj.getMaxGridHappiness(3, 1, 2, 1)); // expect: 260
}
