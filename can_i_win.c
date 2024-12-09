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

static int mem[1 << 20] = {};

bool dfs(int maxChoosableInteger, int desiredTotal, int k) {
  if (mem[k])
    return mem[k] > 0;
  if (desiredTotal <= 0)
    return false;
  for (int i = 0; i < maxChoosableInteger; ++i)
    if (!(k & (1 << i)) &
        !dfs(maxChoosableInteger, desiredTotal - i - 1, k | (1 << i))) {
      mem[k] = 1;
      return true;
    }
  mem[k] = -1;
  return false;
}

bool canIWin(int maxChoosableInteger, int desiredTotal) {
  int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
  if (desiredTotal < 2)
    return true;
  else if (sum < desiredTotal)
    return false;
  else if (sum == desiredTotal)
    return maxChoosableInteger % 2;
  else
    return dfs(maxChoosableInteger, desiredTotal, 0);
}

int main() {
  printf("%d\n", canIWin(10, 11)); // expect: 0
  printf("%d\n", canIWin(10, 0));  // expect: 1
  printf("%d\n", canIWin(10, 1));  // expect: 1
}
