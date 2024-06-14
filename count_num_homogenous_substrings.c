// 1759. Count Number of Homogenous Substrings
#include "leetcode.h"

/*
 * given a string 's', return the number of homogenous substrings of 's'. since
 * thhe answer may be very large, return it modulo 10^9+7. a string is
 * homogenous if all the characters of the string are the same. a substring is a
 * continuous sequence of chharacters within a string.
 */

int countHomogenous(char *s) {
  int ans = 0, mod = 1e9 + 7, n = strlen(s), cnt = 1;
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1])
      cnt++;
    else {
      long val = (1 + cnt) * cnt / 2;
      ans = (ans + val % mod) % mod;
      cnt = 1;
    }
  }
  long long val = (long long)(1 + cnt) * cnt / 2;
  ans = (ans + val % mod) % mod;
  return ans;
}

int main() {
  char s1[] = {"abbcccaa"}, s2[] = {"xy"}, s3[] = {"zzzzz"};
  printf("%d\n", countHomogenous(s1)); // expect: 13
  printf("%d\n", countHomogenous(s2)); // expect: 2
  printf("%d\n", countHomogenous(s3)); // expect: 15
}
