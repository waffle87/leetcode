// 2262. Total Appeal of A String
#include "leetcode.h"

/*
 * the appeal of a string is the number of distinct characters found in the
 * string. for example, the appeal of "aabca" is 3 because it has 3 distinct
 * characters 'a', 'b' and 'c'. given a string 's', return the total appeal of
 * along long its substrings. a substring is a contiguous sequence of characters
 * within a string.
 */

long long appealSum(char *s) {
  long long ans = 0;
  int n = strlen(s);
  int *dp = (int *)calloc(26, sizeof(int));
  for (int i = 0; i < n; i++) {
    ans += (long long)(i + 1 - dp[s[i] - 'a']) * (long long)(n - i);
    dp[s[i] - 'a'] = i + 1;
  }
  free(dp);
  return ans;
}

int main() {
  char *s1 = "aabca", *s2 = "code";
  printf("%lld\n", appealSum(s1)); // expect: 28
  printf("%lld\n", appealSum(s2)); // expect: 20
}
