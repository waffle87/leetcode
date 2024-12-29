// 1639. Number of Ways to Form a Target String Given a Dictionary
#include "leetcode.h"

/*
 * you are given a list of strings of the same length 'words' and a string
 * 'target'. your task is to form 'target' using the given 'words'. notice that
 * you can use multiple characters from the same string in 'words' provided the
 * conditions above are met. return the number of ways to from 'target' from
 * 'words'. since the answer may be too large, return it modulo 10^9+7
 */

int numWays(char **words, int words_size, char *target) {
  const int mod = 1e9 + 7;
  int t_len = strlen(target), w_len = strlen(words[0]);
  long *ans = (long *)calloc(t_len + 1, sizeof(long));
  ans[0] = 1;
  for (int i = 0; i < w_len; i++) {
    int cnt[26] = {0};
    for (int j = 0; j < words_size; j++)
      cnt[words[i][j] - 'a']++;
    for (int j = t_len - 1; j >= 0; j--)
      ans[j + 1] += ans[j] * cnt[target[j] - 'a'] % mod;
  }
  return ans[t_len] % mod;
}

int main() {
  char *w1[] = {"acca", "bbbb", "caca"}, *t1 = "aba";
  char *w2[] = {"abba", "baab"}, *t2 = "bab";
  printf("%d\n", numWays((char **)w1, ARRAY_SIZE(w1), t1)); // expect: 6
  printf("%d\n", numWays((char **)w2, ARRAY_SIZE(w2), t2)); // expect: 4
}
