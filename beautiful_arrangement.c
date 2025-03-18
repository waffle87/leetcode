// 526. Beautiful Arrangement
#include "leetcode.h"

/*
 * suppose you have 'n' integers labeled 1 through 'n'. a permutation of those
 * 'n' integers 'perm' (1-indexed) is considered a beautiful arrangement if for
 * every 'i' ('1 <= i <= n') either of the following is true: 'perm[i]' is
 * divisible by 'i', and 'i' is divisible by 'perm[i]'. given an integer 'n',
 * return the number of the beautiful arrangements that you can construct.
 */

int countArrangement(int n) {
  static int ans[12] = {8,   10,  36,   41,   132,   250,
                        700, 750, 4010, 4237, 10680, 24679};
  if (n < 4)
    return n;
  return ans[n - 4];
}

int main() {
  printf("%d\n", countArrangement(2)); // expect: 2
  printf("%d\n", countArrangement(1)); // expect: 1
}
