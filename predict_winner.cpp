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

class Solution {
  bool check_win(int ans, int total) { return ans >= total - ans; }
  int max_score(vector<int> &nums, int total, int i, int j) {
    if (i > j)
      return 0;
    return total - min(max_score(nums, total - nums[i], i + 1, j),
                       max_score(nums, total - nums[j], i, j - 1));
  }

public:
  bool PredictTheWinner(vector<int> &nums) {
    int total = 0;
    for (auto i : nums)
      total += i;
    return check_win(max_score(nums, total, 0, nums.size() - 1), total);
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {1, 5, 2}, n2 = {1, 5, 233, 7};
  printf("%d\n", obj.PredictTheWinner(n1)); // expect: 0
  printf("%d\n", obj.PredictTheWinner(n2)); // expect: 1
}
