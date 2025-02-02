// 1542. Find Longest Awesome Substring
#include "leetcode.h"

/*
 * you are given a string 's'. an awesome substring is a non-empty substring of
 * 's' such that we can make any number of swaps in order to make it a
 * palindrome. return the length of the maximum length awesome substring of 's'.
 */

int longestAwesome(char *s) {
  int n = strlen(s), ans = 0, mask = 0, dp[1024];
  memset(dp, n, sizeof(dp));
  dp[0] = -1;
  for (int i = 0; i < n; ++i) {
    mask ^= 1 << (s[i] - '0');
    ans = fmax(ans, i - dp[mask]);
    for (int j = 0; j <= 9; ++j)
      ans = fmax(ans, i - dp[mask ^ (1 << j)]);
    dp[mask] = fmin(dp[mask], i);
  }
  return ans;
}

int main() {
  char *s1 = "3242415", *s2 = "12345678", *s3 = "213123";
  printf("%d\n", longestAwesome(s1)); // expect: 5
  printf("%d\n", longestAwesome(s2)); // expect: 1
  printf("%d\n", longestAwesome(s3)); // expect: 6
}
