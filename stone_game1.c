// 877. Stone Game
#include "leetcode.h"

/*
 * alice and bob play a game with piles of stones. there are even number of
 * piles arranged in a row, and each pile has a positive integer number of
 * stones 'piles[i]'. the objective of the game is to end with with most stones.
 * the total number of stones across all piles is odd, so there are no ties.
 * alice and bob take turns, with alice  starting first.  each turn, a player
 * takes the entire pile of stones until  there are no more  piles left, at
 * which point the person with the most stones wins. assuming alice and bob play
 * optimally, return true if alice wins the game.
 */

bool stoneGame(int *piles, int pilesSize) { return true; }

int main() {
  int p1[] = {5, 4, 3, 4}, p2[] = {3, 7, 2, 3};
  bool r1 = stoneGame(p1, ARRAY_SIZE(p1));
  bool r2 = stoneGame(p2, ARRAY_SIZE(p2));
  printf("%d\n", r1);
  assert(r1 == true);
  printf("%d\n", r2);
  assert(r2 == true);
}
