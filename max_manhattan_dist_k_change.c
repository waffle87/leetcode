// 3443. Maximum Manhattan Distance After K Changes
#include "leetcode.h"

/*
 * you are given a sing 's' consisting of the characters 'N', 'S', 'E', and
 * 'W', where 's[i]' indicates movements in an infinite grid, where each letter
 * is a move of 1 unit in that cardinal direction. initially, you are at the
 * origin '(0, 0)'. you can change at most 'k' characters to any of the four
 * directions. find the maximum manhattan distance from the origin that can be
 * achieved at any time while performing the movements in order.
 */

int maxDistance(char *s, int k) {
  const char dir[4][2] = {{'N', 'E'}, {'N', 'W'}, {'S', 'E'}, {'S', 'W'}};
  int ans = 0;
  for (int i = 0; i < 4; i++) {
    bool set[1 << (CHAR_BIT - 1)] = {0};
    set[dir[i][0]] = set[dir[i][1]] = true;
    int curr_dist = 0, curr_k = k;
    for (int j = 0; s[j] != '\0'; j++) {
      if (!set[s[j]] && !(curr_k >= 1)) {
        curr_dist--;
        continue;
      }
      if (!set[s[j]])
        curr_k--;
      curr_dist++;
      if (curr_dist > ans)
        ans = curr_dist;
    }
  }
  return ans;
}

int main() {
  char *s1 = "NWSE", *s2 = "NSWWEW";
  printf("%d\n", maxDistance(s1, 1)); // expect: 3
  printf("%d\n", maxDistance(s2, 3)); // expect: 6
}
