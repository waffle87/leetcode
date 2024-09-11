// 514. Freedom Trail
#include "leetcode.h"

/*
 * in the video game fallout 4, the quest "road to freeom" requires players to
 * reach a metal dial call the "freedom trail ring" and use the dial to spell a
 * specific keyword to open the door. given a string 'rint' that represents the
 * code engraved on the outer ring and another string 'key' that represents the
 * keyword that needs to be spelled, return the minimum number of steps to spell
 * all of the characters in the keyword. initially, the first character of the
 * ring is aligned at "12:00" diretion. you should spell all the characters in
 * 'key' one by rotating 'ring' clockwise or anticlockwise to make each
 * character of the string aligned at the "12:00" direction and then by pressing
 * the center button. at the stage of rotating the ring to spell the key
 * character 'key[i]' you can rotate the ring clockwise or anticlockwise by one
 * place, which counts as one step. the final purpose of the rotation is to
 * align one of 'ring's characters at "12:00" direction, where this character
 * must equal 'key[i]'
 */

int dp[101][101];

int dfs(char *ring, char *key, int ring_size, int key_size, int ring_idx,
        int key_idx) {
  if (key_idx == key_size)
    return 0;
  if (dp[key_idx][ring_idx] != -1)
    return dp[key_idx][ring_idx];
  int min_step = 1e9;
  for (int i = 0; i < ring_size; i++)
    if (ring[i] == key[key_idx]) {
      int cw = (ring_idx + ring_size - i) % ring_size;
      int ccw = (i + ring_size - ring_idx) % ring_size;
      int step = fmin(cw, ccw) + 1 +
                 dfs(ring, key, ring_size, key_size, i, key_idx + 1);
      min_step = fmin(min_step, step);
    }
  dp[key_idx][ring_idx] = min_step;
  return min_step;
}

int findRotateSteps(char *ring, char *key) {
  int ring_size = strlen(ring);
  int key_size = strlen(key);
  memset(dp, -1, sizeof(dp));
  return dfs(ring, key, ring_size, key_size, 0, 0);
}

int main() {
  char *r1 = "godding", *k1 = "gd", *r2 = "godding", *k2 = "godding";
  printf("%d\n", findRotateSteps(r1, k1)); // expect: 4
  printf("%d\n", findRotateSteps(r2, k2)); // expect: 13
}
