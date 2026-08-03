// 1406. Stone Game III
#include "leetcode.h"

/*
 * alice and bob continue their games with piles of stones. there are several
 * stones arranged in a row, and each stone has an associated value which is an
 * integer given in the array 'stoneValue'. alice and bob take turns with alice
 * starting first. on each player's turn, that player can take 1,2, or 3 stones
 * from the first remaining stones in row. the score of each player is the sum
 * of the values of the stones taken the score of each player is initially zero.
 * the objective of the game is to end with the highest score, and the winner is
 * the player with the highest score and there could be a tie. the game
 * continues until all the stones have been taken. assume alice and bob play
 * optimally. return "Alice", "Bob", or "Tie" accordingly
 */

char *stoneGameIII(int *stoneValue, int stoneValueSize) {
  char *ans[] = {"Bob", "Tie", "Alice"};
  int dp[4] = {0, 0, 0, 0};
  for (int i = stoneValueSize - 1; i >= 0; i--) {
    int j = i & 3;
    dp[j] = stoneValue[i] - dp[(i + 1) & 3];
    if (i + 2 <= stoneValueSize)
      dp[j] = fmax(dp[j], stoneValue[i] + stoneValue[i + 1] - dp[(i + 2) & 3]);
    if (i + 3 <= stoneValueSize)
      dp[j] = fmax(dp[j], stoneValue[i] + stoneValue[i + 1] +
                              stoneValue[i + 2] - dp[(i + 3) & 3]);
  }
  return ans[(dp[0] > 0) - (dp[0] < 0) + 1];
}

int main() {
  int sv1[] = {1, 2, 3, 7};
  int sv2[] = {1, 2, 3, -9};
  int sv3[] = {1, 2, 3, 6};
  char *r1 = "Bob", *r2 = "Alice", *r3 = "Tie";
  char *st1 = stoneGameIII(sv1, ARRAY_SIZE(sv1));
  char *st2 = stoneGameIII(sv2, ARRAY_SIZE(sv2));
  char *st3 = stoneGameIII(sv3, ARRAY_SIZE(sv3));
  printf("%s\n", st1);
  assert(!strcmp(st1, r1));
  printf("%s\n", st2);
  assert(!strcmp(st2, r2));
  printf("%s\n", st3);
  assert(!strcmp(st3, r3));
}
