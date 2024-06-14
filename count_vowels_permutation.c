// 1220. Count Vowels Permutation
#include <stdio.h>
#include <stdlib.h>

int countVowelPermutation(int n) {
  int mod = 1e9 + 7, ans = 0;
  long long int dp[n + 1][5];
  for (int i = 0; i < 5; i++)
    dp[1][i] = 1;
  for (int i = 2; i < n + 1; i++) {
    dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % mod;
    dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
    dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % mod;
    dp[i][3] = dp[i - 1][2];
    dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
  }
  for (int i = 0; i < 5; i++)
    ans = (ans + dp[n][i]) % mod;
  return ans;
}

int main() {
  printf("%d\n", countVowelPermutation(1)); // expect: 5
  printf("%d\n", countVowelPermutation(2)); // expect: 10
  printf("%d\n", countVowelPermutation(5)); // expect: 68
}
