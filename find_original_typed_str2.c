// 3333. Find the Original Typed String II
#include "leetcode.h"

/*
 * alice is attempting to type a specific string on her computer. however, she
 * tends to be clumsy and may press a key for too long, resulting in a character
 * being typed multiple times. you are given a string 'word', which represents
 * the final output displayed on alice's screen. you are also given a positive
 * integer 'k'. return the total number of possible original strings that alice
 * might have intended to type, if she was trying to type a string of size at
 * least 'k'. since the answer may be very large, return it modul 10^9+7.
 */

int possibleStringCount(char *word, int k) {
  long long prod = 1, mod = 1e9 + 7;
  int g[2000], m = 0, n = strlen(word);
  for (int i = 1, cnt = 1; i <= n; ++i) {
    if (i < n && word[i] == word[i - 1])
      ++cnt;
    else {
      g[m++] = cnt - 1;
      prod = (prod * cnt) % mod;
      cnt = 1;
    }
  }
  if (k <= m)
    return (int)prod;
  int dp[2][2001] = {{1}}, ps[2001] = {0}, sz = m;
  for (int i = 0; i < sz; ++i) {
    ps[0] = 0;
    for (int j = 0; j < k - sz; ++j)
      ps[j + 1] = (ps[j] + dp[i % 2][j]) % mod;
    for (int j = 0; j < k - sz; ++j) {
      int low = j - g[i];
      if (low < 0)
        low = 0;
      dp[!(i % 2)][j] = (ps[j + 1] - ps[low]) % mod;
      if (dp[!(i % 2)][j] < 0)
        dp[!(i % 2)][j] += mod;
    }
  }
  long long ans = 0;
  for (int i = 0; i < k; ++i)
    ans = (ans + dp[sz % 2][i]) % mod;
  return (int)((mod + prod - ans) % mod);
}

int main() {
  char *w1 = "aabbccdd", *w2 = "aabbccdd", *w3 = "aaabbb";
  printf("%d\n", possibleStringCount(w1, 7)); // expect: 5
  printf("%d\n", possibleStringCount(w2, 8)); // expect: 1
  printf("%d\n", possibleStringCount(w3, 3)); // expect: 8
}
