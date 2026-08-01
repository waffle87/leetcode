// 486. Predict the Winner
#include "leetcode.h"

/*
 * given an integer array 'nums'. two players are playing a game with this
 * array: player 1 and player 2. player 1 and player 2 take turns, with player 1
 * starting first. both players start the game with a score of zero. at each
 * turn, the player takes one of the numbers from either end of the array (ie.
 * 'nums[0]', or 'nums[nums.len - 1]') which reduces the size of the array by
 * one. the player adds the chosen number to their score. the game ends when
 * there are no more elements in the array. return 'true' if player 1 can win
 * the game. if the scores of both players are equal, then player 1 is still the
 * winner, and you should also return 'true'. you may assume that both players
 * are playing optimally.
 */

bool predictTheWinner(int *nums, int numsSize) {
  int *dp = (int *)malloc(numsSize * sizeof(int));
  for (int i = numsSize - 1; i >= 0; i--) {
    dp[i] = nums[i];
    for (int j = i + 1; j < numsSize; j++)
      dp[j] = fmax(nums[i] - dp[j], nums[j] - dp[j - 1]);
  }
  bool ans = dp[numsSize - 1] >= 0;
  free(dp);
  return ans;
}

int main() {
  int n1[] = {1, 5, 2}, n2[] = {1, 5, 233, 7};
  bool r1 = predictTheWinner(n1, ARRAY_SIZE(n1));
  bool r2 = predictTheWinner(n2, ARRAY_SIZE(n2));
  printf("%d\n", r1);
  assert(r1 == false);
  printf("%d\n", r2);
  assert(r2 == true);
}
