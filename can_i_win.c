// 464. Can I Win
#include "leetcode.h"

/*
 * in the 100 game two players take turns adding, to a running total, any
 * integer from 1 to 10. the player who first causes the running total to reach
 * or exceed 100 wins. what if we change the same so that players cannot re-use
 * integers? for example, two players might take turns drawing from a common
 * pool of numbers from 1 to 15 without replacement until they reach a total >=
 * 100. given two integers 'maxChoosableInteger' nad 'desiredTotal', return true
 * if the first player to move can force a win, otherwise, return false. assume
 * both players play optimally.
 */

bool dfs(int *vis, int state, long long sum, int maxChoosableInteger,
         int desiredTotal) {
  if (vis[state] == 2)
    return true;
  if (vis[state] == 1)
    return false;
  for (int i = 1; i <= maxChoosableInteger; i++) {
    if ((state >> i) & 1)
      continue;
    if ((sum + 1) >= desiredTotal) {
      vis[state] = 2;
      return true;
    }
    if (!dfs(vis, state + (1 << i), sum + i, maxChoosableInteger,
             desiredTotal)) {
      vis[state] = 2;
      return true;
    }
  }
  vis[state] = 1;
  return false;
}

bool canIWin(int maxChoosableInteger, int desiredTotal) {
  if (maxChoosableInteger >= desiredTotal)
    return true;
  if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal)
    return false;
  int *vis = (int *)calloc(pow(2, 21), sizeof(int)), state = 0;
  long long sum = 0;
  bool ans = dfs(vis, state, sum, maxChoosableInteger, desiredTotal);
  free(vis);
  return ans;
}

int main() {
  printf("%d\n", canIWin(10, 11)); // expect: 0
  printf("%d\n", canIWin(10, 0));  // expect: 1
  printf("%d\n", canIWin(10, 1));  // expect: 1
}
