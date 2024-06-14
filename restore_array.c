// 1416. Restore The Array
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * a progamme was supposed to print an array of integers. the programme forgot
 * to print whitespace and the array is printing as a string of digits 's' and
 * all we know is that all integers in the array were in the range [1, k] and
 * there are no leading zeros in the array. given the string 's' and the integer
 * 'k', return the number of possible arrays that can be printed as 's' using
 * the mentioned programme. return modulo 10^9+7
 */

int numberOfArrays(char *s, int k) {
  const int mod = 1e9 + 7;
  int n = strlen(s);
  int *dp = calloc(n + 1, sizeof(int));
  dp[n] = 1;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '0')
      continue;
    long long num = 0;
    for (int j = i; j < n; j++) {
      num = num * 10 + s[j] - '0';
      if (num > k)
        break;
      dp[i] = (dp[i] + dp[j + 1]) % mod;
    }
  }
  int ans = dp[0];
  free(dp);
  return ans;
}

int main() {
  char s1_2[] = {"1000"}, s3[] = {"1317"};
  printf("%d\n", numberOfArrays(s1_2, 10000)); // expect: 1
  printf("%d\n", numberOfArrays(s1_2, 10));    // expect: 0
  printf("%d\n", numberOfArrays(s3, 2000));    // expect: 8
}
