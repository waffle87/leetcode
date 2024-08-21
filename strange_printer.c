// 664. Strange Printer
#include "leetcode.h"

/*
 * there is a strange printer with the following two special properties:
 * - the printer can only print a sequence of the same character each time
 * - at each turn, the printer can print new characters starting from and eding
 * at any place and will cover the origin existing characters given a string
 * 's', return the minimum number of turns the printer needed to print it.
 */

int get_cnt(char *s, int **dp, int r, int l) {
  if (dp[r][l] != -1)
    return dp[r][l];
  else {
    int i = r;
    while (i < l && s[i] == s[l])
      i++;
    int min = l - i;
    for (int j = i; j < l; j++)
      if (get_cnt(s, dp, i, j) + get_cnt(s, dp, j + 1, l) + 1 < min)
        min = get_cnt(s, dp, i, j) + get_cnt(s, dp, j + 1, l) + 1;
    dp[r][l] = min;
    return dp[r][l];
  }
}

int strangePrinter(char *s) {
  int n = strlen(s);
  int **dp = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    dp[i] = (int *)malloc(n * sizeof(int));
    dp[i][i] = 0;
    for (int j = i + 1; j < n; j++)
      dp[i][j] = -1;
  }
  return get_cnt(s, dp, 0, n - 1) + 1;
}

int main() {
  char s1[] = {"aaabbb"}, s2[] = {"aba"};
  printf("%d\n", strangePrinter(s1)); // expect: 2
  printf("%d\n", strangePrinter(s2)); // expect: 2
}
