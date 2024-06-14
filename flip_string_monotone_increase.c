#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minFlipsMonoIncr(char *s) {
  int n = strlen(s), *dp = malloc((n + 1) * sizeof(int));
  dp[0] = 0;
  for (int i = 0; i < n; i++)
    dp[i + 1] = dp[i] + (s[i] == '1');
  int min = INT_MAX;
  for (int i = 1; i <= n + 1; i++)
    min = fmin(min, 2 * dp[i - 1] + n - i + 1 - dp[n]);
  return min;
}

int main() {
  char s1[] = {"00110"}, s2[] = {"010110"}, s3[] = {"00011000"};
  printf("%c\n", minFlipsMonoIncr(s1));
  printf("%c\n", minFlipsMonoIncr(s2));
  printf("%c\n", minFlipsMonoIncr(s3));
}
