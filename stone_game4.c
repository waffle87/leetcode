// 1510. Stone Game IV
#include "leetcode.h"

/*
 * alice and bob take turns playing a game with alice starting first. initially,
 * there are 'n' stones in a pile. on each player's turn, that player makes a
 * move consisting of removing any non-zero square number of stones in the pile.
 * also, if a player cannot make a move, he/she loses the game. given a positive
 * integer 'n', return true if and only if alice wins the game otherwise return
 * false assuming both players play optimally.
 */

bool winnerSquareGame(int n) {
  bool *dp = (bool *)calloc(n + 1, sizeof(bool));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j * j <= i; j++)
      if (!dp[i - j * j]) {
        dp[i] = true;
        break;
      }
  bool ans = dp[n];
  free(dp);
  return ans;
}

int main() {
  bool r1 = winnerSquareGame(1);
  bool r2 = winnerSquareGame(2);
  bool r3 = winnerSquareGame(4);
  printf("%d\n", r1);
  assert(r1 == true);
  printf("%d\n", r2);
  assert(r2 == false);
  printf("%d\n", r3);
  assert(r3 == true);
}
