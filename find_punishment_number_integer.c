// 2698. Find the Punishment Number of an Integer
#include "leetcode.h"

/*
 * given a positive integer 'n', return the punishment number of 'n'. the
 * punishment number of 'n' is defined as the sum of the squares of all integers
 * 'i' such that '1 <= i <= n' and the decimal representation of 'i * i' can be
 * partitioned into contiguous substrings such that the sum of the integer
 * values of the substrings equals 'i'.
 */

bool partition(char *s, int idx, int target) {
  int sum = 0, base = 1;
  bool res = false;
  if (!s[idx])
    return !target;
  for (int i = idx; s[i]; i++) {
    sum += (s[i] - '0') * base;
    res = partition(s, i + 1, target - sum);
    if (res)
      break;
    base *= 10;
  }
  return res;
}

void reverse(char *s, int i, int j) {
  for (; i < j; i++, j--) {
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
  }
}

int punishment(int n, int *dp) {
  int sum = 0, res = 0;
  char s[8];
  if (!n)
    return 0;
  if (dp[n] != -1)
    return dp[n];
  sprintf(s, "%d", n * n);
  reverse(s, 0, strlen(s) - 1);
  res = partition(s, 0, n) ? (n * n) + punishment(n - 1, dp)
                           : punishment(n - 1, dp);
  dp[n] = res;
  return res;
}

int punishmentNumber(int n) {
  int dp[1001] = {0};
  if (!dp[0]) {
    memset(dp, -1, sizeof(dp));
    punishment(1000, dp);
  }
  return dp[n];
}

int main() {
  printf("%d\n", punishmentNumber(10)); // expect: 182
  printf("%d\n", punishmentNumber(37)); // expect: 1478
}
