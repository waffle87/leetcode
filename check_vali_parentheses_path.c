// 2267. Check if There Is a Valid Parentheses String Path
#include "leetcode.h"

/*
 * a parentheses string is non-empty string that consists of only '(' and ')'.
 * it is valid if any of the following conditions is true: it is '()', it can be
 * written as 'AB', or it can be written as '(A)'. you are given an 'm x n'
 * matrix of parentheses 'grid'. a valid parentheses string path in the grid is
 * a path satisfying all of the given conditions. return true if there exists a
 * valid parentheses string path in the grid. otherwise, return 'false'.
 */

bool hasValidPath(char **grid, int gridSize, int *gridColSize) {
  int m = gridSize, n = *gridColSize;
  int len = m + n - 1;
  if (len % 2 && grid[0][0] != '(' && grid[m - 1][n - 1] != ')')
    return false;
  enum { WORDS = 4, BITS = 201 };
  unsigned long long dp[n][WORDS];
  memset(dp, 0, sizeof(dp));
  for (int row = 0; row < m; ++row) {
    for (int col = 0; col < n; ++col) {
      unsigned long long reachable[WORDS];
      memset(reachable, 0, sizeof(reachable));
      if (row > 0) {
        for (int w = 0; w < WORDS; ++w)
          reachable[w] |= dp[col][w];
      }
      if (col > 0) {
        for (int w = 0; w < WORDS; ++w)
          reachable[w] |= dp[col - 1][w];
      }
      if (!row && !col)
        reachable[0] |= 1ULL;
      unsigned long long ans[WORDS];
      memset(ans, 0, sizeof(ans));
      if (grid[row][col] == '(') {
        for (int w = WORDS - 1; w >= 0; --w) {
          unsigned long long val = reachable[w] << 1;
          if (w > 0 && (reachable[w - 1] & (1ULL << 63)))
            val |= 1ULL;
          ans[w] = val;
        }
      } else {
        for (int w = 0; w < WORDS; ++w) {
          unsigned long long val = reachable[w] >> 1;
          if (w < WORDS - 1 && (reachable[w + 1] & 1ULL))
            val |= (1ULL << 63);
          ans[w] = val;
        }
      }
      memcpy(dp[col], ans, sizeof(ans));
    }
  }
  return (dp[n - 1][0] & 1ULL) != 0;
}

int main() {
  char g1[4][3] = {
      {'(', '(', '('},
      {')', '(', ')'},
      {'(', '(', ')'},
      {'(', '(', ')'},
  };
  char g2[2][2] = {
      {')', ')'},
      {'(', '('},
  };
  int m1 = ARRAY_SIZE(g1), n1 = ARRAY_SIZE(g1[0]);
  int m2 = ARRAY_SIZE(g2), n2 = ARRAY_SIZE(g2[0]);
  bool r1 = hasValidPath((char **)g1, m1, &n1);
  bool r2 = hasValidPath((char **)g2, m2, &n2);
  printf("%d\n", r1);
  assert(r1 == true);
  printf("%d\n", r2);
  assert(r2 == false);
}
