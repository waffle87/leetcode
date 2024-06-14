// 1639. Number of Ways to Form a Target String Given a Dictionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

int numWays(char **words, int words_size, char *target) {
  int t_len = strlen(target), w_len = strlen(words[0]);
  long *ans = (long *)calloc(t_len + 1, sizeof(long));
  ans[0] = 1;
  for (int i = 0; i < w_len; i++) {
    int cnt[26] = {0};
    for (int j = 0; j < words_size; j++)
      cnt[words[i][j] - 'a']++;
    for (int j = t_len - 1; j >= 0; j--)
      ans[j + 1] += ans[j] * cnt[target[j] - 'a'] % MOD;
  }
  return ans[t_len] % MOD;
}

int main() {
  char w1[][] = {{"acca"}, {"bbbb"}, {"caca"}}, t1[] = {"aba"};
  char w2[][] = {{"abba"}, {"baab"}}, t2[] = {"bab"};
  printf("%d\n", numWays(w1, 3, t1)); // expect: 6
  printf("%d\n", numWays(w2, 2, t2)); // expect: 6
}
