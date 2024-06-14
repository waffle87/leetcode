// 486. Predict the Winner
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

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

int get_score(int *nums, int left, int right) {
  if (left == right)
    return nums[left];
  return fmax(nums[left] - get_score(nums, left + 1, right),
              nums[right] - get_score(nums, left, right - 1));
}

bool PredictTheWinner(int *nums, int nums_size) {
  if (get_score(nums, 0, nums_size - 1) >= 0)
    return true;
  else
    return false;
}

int main() {
  int n1[] = {1, 5, 2}, n2[] = {1, 5, 233, 7};
  printf("%d\n", PredictTheWinner(n1, 3)); // expect: 0
  printf("%d\n", PredictTheWinner(n2, 4)); // expect: 1
}
