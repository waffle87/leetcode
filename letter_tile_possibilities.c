// 1079. Letter Tile Possibilities
#include "leetcode.h"

/*
 * given 'n' tiles where each tile has one letter ('tiles[i]') printed on it.
 * return the number of possible non-empty letters printed on those tiles.
 */

void dfs(int *alpha, int *sum) {
  for (int i = 0; i < 26; i++) {
    if (!alpha[i])
      continue;
    (*sum)++;
    alpha[i]--;
    dfs(alpha, sum);
    alpha[i]++;
  }
}

int numTilePossibilities(char *tiles) {
  int *alpha = calloc(26, sizeof(int));
  for (int i = 0; i < strlen(tiles); i++)
    alpha[tiles[i] - 'A']++;
  int ans = 0;
  dfs(alpha, &ans);
  free(alpha);
  return ans;
}

int main() {
  char *t1 = "AAB", *t2 = "AAABBC", *t3 = "V";
  printf("%d\n", numTilePossibilities(t1)); // expect: 8
  printf("%d\n", numTilePossibilities(t2)); // expect: 188
  printf("%d\n", numTilePossibilities(t3)); // expect: 1
}
