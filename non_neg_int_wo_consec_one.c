// 600. Non-negative Integers without Consecutive Ones
#include "leetcode.h"

/*
 * given a positive integer 'n', return the number of the integers in the range
 * '[0, n]' whose binary representations do not contain consecutive ones.
 */

void dfs(int curr, int n, int *res) {
  if (curr > n)
    return;
  (*res)++;
  if ((curr & 1))
    dfs((curr << 1), n, res);
  else {
    dfs((curr << 1), n, res);
    dfs((curr << 1) + 1, n, res);
  }
}

int findIntegers(int n) {
  int ans = 1;
  dfs(1, n, &ans);
  return ans;
}

int main() {
  printf("%d\n", findIntegers(5)); // expect: 5
  printf("%d\n", findIntegers(1)); // expect: 2
  printf("%d\n", findIntegers(2)); // expect: 3
}
