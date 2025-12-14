// 2147. Number of Ways to Divide a Long Corridor
#include "leetcode.h"

/*
 * along a long library corridor, there is a line of seats and decorative
 * plants. you are given a 0-indexed string 'corridor' of length 'n' consisting
 * of letters 's' and 'p' where each 's' represents a seat and each 'p'
 * represents a plant. one room divider has already been installed to the left
 * of index 0. and another to the right of index 'n - 1'. additional room
 * dividers can be installed. for each position between indices 'i - 1' and 'i'
 * at most one divider can be installed. divide the corridor into
 * non-overlapping sections, where each section has exactly two seats with any
 * number of plants. there may be multiple ways to perform the division. two
 * ways are different if there is a position with a room divider installed in
 * the first way but not the second way.
 */

int numberOfWays(char *corridor) {
  static int mod = 1e9 + 7;
  long ans = 1, j = 0, k = 0, n = strlen(corridor);
  for (int i = 0; i < n; ++i) {
    if (corridor[i] == 'S') {
      if (++k > 2 && k % 2 == 1)
        ans = ans * (i - j) % mod;
      j = i;
    }
  }
  return !(k % 2) && k > 0 ? ans : 0;
}

int main() {
  char *c1 = "SSPPSPS", *c2 = "PPSPSP", *c3 = "S";
  printf("%d\n", numberOfWays(c1)); // expect: 3
  printf("%d\n", numberOfWays(c2)); // expect: 1
  printf("%d\n", numberOfWays(c3)); // expect: 0
}
