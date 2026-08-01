# 486. Predict the Winner

"""
given an integer array 'nums'. two players are playing a game with this
array: player 1 and player 2. player 1 and player 2 take turns, with player 1
starting first. both players start the game with a score of zero. at each
turn, the player takes one of the numbers from either end of the array (ie.
'nums[0]', or 'nums[nums.len - 1]') which reduces the size of the array by
one. the player adds the chosen number to their score. the game ends when
there are no more elements in the array. return 'true' if player 1 can win
the game. if the scores of both players are equal, then player 1 is still the
winner, and you should also return 'true'. you may assume that both players
are playing optimally.
"""


class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        def max_diff(i, j):
            if i == j:
                return nums[i]
            return max(nums[i] - max_diff(i + 1, j), nums[j] - max_diff(i, j - 1))

        return max_diff(0, len(nums) - 1) >= 0


if __name__ == "__main__":
    obj = Solution()
    print(obj.predictTheWinner(nums=[1, 5, 2]))
    print(obj.predictTheWinner(nums=[1, 5, 233, 7]))
