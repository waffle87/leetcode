// 691. Stickers to Spell Word
#include "leetcode.h"

/*
 * we are given 'n' different types of 'stickers'. each sticker has a lowercase
 * english word on it. you would like to spell out the given 'target' by cutting
 * individual letters from your collection of stickers and rearranging them. you
 * can use each sticker more than once if you want, and you have infinite
 * quantities of each sticker. return the minimum number of stickers that you
 * need to spell out 'target'. if the task is impossible, return -1. note in all
 * test cases, all words were chose random from the 1000 most common us english
 * words, and 'target' was chosen as a concatenation of two random words
 */

int find_next_state(int state, char *s, char *target, int n) {
  for (int i = 0; s[i] != '\0'; i++) {
    char curr = s[i];
    for (int j = 0; j < n; j++)
      if (!((state >> j) & 1) && target[j] == curr) {
        state |= (1 << j);
        break;
      }
  }
  return state;
}

int minStickers(char **stickers, int stickersSize, char *target) {
  int n = strlen(target), m = 1 << n;
  int *dp = (int *)malloc(m * sizeof(int));
  for (int i = 0; i < m; i++)
    dp[i] = INT_MAX;
  dp[0] = 0;
  for (int state = 0; state < m; state++) {
    if (dp[state] == INT_MAX)
      continue;
    for (int i = 0; i < stickersSize; i++) {
      int new = find_next_state(state, stickers[i], target, n);
      if (dp[state] + 1 < dp[new])
        dp[new] = dp[state] + 1;
    }
  }
  int ans = dp[m - 1];
  if (ans == INT_MAX)
    ans = -1;
  free(dp);
  return ans;
}

int main() {
  char *s1[] = {"with", "example", "science"}, *t1 = "thehat";
  char *s2[] = {"notice", "possible"}, *t2 = "basicbasic";
  printf("%d\n", minStickers((char **)s1, ARRAY_SIZE(s1), t1)); // expect: 3
  printf("%d\n", minStickers((char **)s2, ARRAY_SIZE(s2), t2)); // expect: -1
}
