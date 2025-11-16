// 1513. Number of Substrings With Only 1s
#include "leetcode.h"

/*
 * given a binary string 's', return the number of substrings with all
 * characters 1's since the answer may be too large, return it modulo 1e9+7.
 */

int numSub(char *s) {
  int ans = 0, cnt = 0, mod = 1e9 + 7, n = strlen(s);
  for (int i = 0; i < n; i++) {
    cnt = s[i] == '1' ? cnt + 1 : 0;
    ans = (ans + cnt) % mod;
  }
  return ans;
}

int main() {
  char *s1 = "0110111", *s2 = "101", *s3 = "11111";
  printf("%d\n", numSub(s1)); // expect: 9
  printf("%d\n", numSub(s2)); // expect: 2
  printf("%d\n", numSub(s3)); // expect: 21
}
