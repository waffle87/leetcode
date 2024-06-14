// 664. Strange Printer
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * there is a strange printer with the following two special properties:
 * - the printer can only print a sequence of the same character each time
 * - at each turn, the printer can print new characters starting from and eding
 * at any place and will cover the origin existing characters given a string
 * 's', return the minimum number of turns the printer needed to print it.
 */

int f[100][100];

int dfs(char *s, int left, int right) {
  if (left > right)
    return 0;
  if (f[left][right])
    return f[left][right];
  f[left][right] = dfs(s, left, right - 1) + 1;
  for (int i = left; i < right; i++) {
    if (s[i] == s[right])
      f[left][right] =
          fmin(f[left][right], dfs(s, left, i) + dfs(s, i + 1, right - 1));
  }
  return f[left][right];
}

int strangePrinter(char *s) {
  memset(f, 0, sizeof(f));
  int len = strlen(s);
  return dfs(s, 0, len - 1);
}

int main() {
  char s1[] = {"aaabbb"}, s2[] = {"aba"};
  printf("%d\n", strangePrinter(s1)); // expect: 2
  printf("%d\n", strangePrinter(s2)); // expect: 2
}
