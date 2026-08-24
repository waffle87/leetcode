// 1872. Stone Game VIII
#include "leetcode.h"

/*
 * alice and bob take turns playing a game, with alice starting first. there are
 * 'n' stones arranged in a row. on each player's turn, while the number of
 * stones is more than 1, they will do the following: chosen an integer 'x > 1'
 * and remove the leftmost 'x' stones from the row. add the sum of the removed
 * stones values to the player's score, and place a new stone whose value is
 * equal to the that sum on the left side of the row. the game stops when only
 * one stone is left in the row. the score difference between alice and bob is
 * 'alice - bob'. alice's goal is to maximise the score difference, and bob's
 * goal is to minimise the score difference. given an integer array 'stones' of
 * length 'n' where 'stones[i]' represents the value of the i'th stone from the
 * left, return the score difference.
 */

int stoneGameVIII(int *stones, int stonesSize) {
  for (int i = 1; i < stonesSize; i++)
    stones[i] += stones[i - 1];
  int best = stones[stonesSize - 1];
  for (int i = stonesSize - 2; i >= 1; i--) {
    int val = stones[i] - best;
    best = fmax(best, val);
  }
  return best;
}

int main() {
  int s1[] = {-1, 2, -3, 4, -5};
  int s2[] = {7, -6, 5, 10, 5, -2, -6};
  int s3[] = {-10, -12};
  int r1 = stoneGameVIII(s1, ARRAY_SIZE(s1));
  int r2 = stoneGameVIII(s2, ARRAY_SIZE(s2));
  int r3 = stoneGameVIII(s3, ARRAY_SIZE(s3));
  printf("%d\n", r1);
  assert(r1 == 5);
  printf("%d\n", r2);
  assert(r2 == 13);
  printf("%d\n", r3);
  assert(r3 == -22);
}
