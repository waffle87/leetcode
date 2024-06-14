// 1513. Number of Substrings With Only 1s
#include "leetcode.h"

/*
 * given a binary string 's', return the number of substrings with all
 * characters 1's since the answer may be too large, return it modulo 1e9+7.
 */

int numSub(char *s) {
  int n = strlen(s), mod = 1e9 + 7, ans = 0, one_cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1')
      one_cnt++;
    else {
      if (one_cnt) {
        long long val = (long long)(one_cnt + 1) * one_cnt / 2;
        ans = (ans + val % mod) % mod;
      }
      one_cnt = 0;
    }
  }
  if (one_cnt) {
    long long val = (long long)(one_cnt + 1) * one_cnt / 2;
    ans = (ans + val % mod) % mod;
  }
  return ans;
}

int main() {
  char *s1 = "0110111", *s2 = "101", *s3 = "11111";
  printf("%d\n", numSub(s1)); // expect: 9
  printf("%d\n", numSub(s2)); // expect: 2
  printf("%d\n", numSub(s3)); // expect: 21
}
