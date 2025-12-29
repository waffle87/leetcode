// 756. Pyramid Transition Matrix
#include "leetcode.h"

/*
 * you are stacking blocks to form a pyramid. each block has a colour which is
 * represented by a single letter. each row of blocks contains one less block
 * than the row beneat it and is centered on top. to make the pyramid
 * aesthetically pleasing, there are only specific triangular patterns that are
 * allowed. a triangular pattern consists of a single block stacked on top of
 * two blocks. the patterns are given as a list of three letter strings
 * 'allowed', where the first two characters of a pattern represent the third
 * character is the top block. you start with a bottom row of blocks 'bottom',
 * given as a string, that you must use as the base of the pyramid. given
 * 'bottom' and 'allowed', return 'true' if you can build the pyramid all the
 * way to the top such that every triangular pattern in the pyramid is in
 * 'allowed', or false otherwise.
 */

bool pyramidTransition(char *bottom, char **allowed, int allowedSize) {
  int dp[128][128], n = strlen(bottom);
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < allowedSize; i++) {
    char *triple = allowed[i];
    int u = 1 << (triple[0] - 'A');
    int v = 1 << (triple[1] - 'A');
    int w = 1 << (triple[2] - 'A');
    for (int j = 0; j < 128; j++)
      if (u & j)
        for (int k = 0; k < 128; k++)
          if (v & k)
            dp[j][k] |= w;
  }
  int *state = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    state[i] = 1 << (bottom[i] - 'A');
  while (n > 1) {
    for (int i = 0; i < n - 1; i++)
      state[i] = dp[state[i]][state[i + 1]];
    n--;
  }
  bool ans = (bool)state[0];
  free(state);
  return ans;
}

int main() {
  char *b1 = "BCD", *a1[] = {"BCC", "CDE", "CEA", "FFF"};
  char *b2 = "AAAA", *a2[] = {"AAB", "AAC", "BCD", "BBE", "DEF"};
  printf("%d\n", pyramidTransition(b1, a1, ARRAY_SIZE(a1))); // expect: 1
  printf("%d\n", pyramidTransition(b2, a2, ARRAY_SIZE(a2))); // expect: 0
}
