# 1406. Stone Game III
from typing import List

"""
alice and bob continue their games with piles of stones. there are several
stones arranged in a row, and each stone has an associated value which is an
integer given in the array 'stoneValue'. alice and bob take turns with alice
starting first. on each player's turn, that player can take 1,2, or 3 stones
from the first remaining stones in row. the score of each player is the sum
of the values of the stones taken the score of each player is initially zero.
the objective of the game is to end with the highest score, and the winner is
the player with the highest score and there could be a tie. the game
continues until all the stones have been taken. assume alice and bob play
optimally. return "Alice", "Bob", or "Tie" accordingly
"""

from functools import cache


class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        ans, n = ["Bob", "Tie", "Alice"], len(stoneValue)

        @cache
        def max_diff(i):
            if i == n:
                return 0
            a, b, c = float("-inf"), float("-inf"), float("-inf")
            if i < n:
                a = stoneValue[i] - max_diff(i + 1)
            if i + 1 < n:
                b = stoneValue[i] + stoneValue[i + 1] - max_diff(i + 2)
            if i + 2 < n:
                c = stoneValue + stoneValue[i + 1] + stoneValue[i + 2] - max_diff(i + 3)
            return max(a, b, c)

        diff = max_diff(0)
        return ans[(diff > 0) - (diff < 0) + 1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.stoneGameIII(stoneValue=[1, 2, 3, 7]))
    print(obj.stoneGameIII(stoneValue=[1, 2, 3, -9]))
    print(obj.stoneGameIII(stoneValue=[1, 2, 3, 6]))
