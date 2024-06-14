# 877. Stone Game

"""
alice and bob play a game with piles of stones. there are an even number of
piles arranged in a row, and each pile has a positive integer number of
stones 'piles[i]'. the objective of the game is to end with the most stones.
the total number of stones across all piles isodd, so there are no ties.
alice and bob take turns, with alice starting first. each turn a player takes
the entire pile of stones either from the beginning or from the end of the
row. this continues until there are no more piles left, at which point the
person with the most stones wins. assuming alice and bob play optimally,
return 'true' if alice wins the game, or 'false' if bob wins.
"""


class Solution(object):
    def stoneGame(self, piles):
        n = len(piles)
        dp = piles[:]
        for i in range(1, n):
            for j in range(n - i):
                dp[j] = max(piles[j] - dp[j + 1], piles[j + i] - dp[j])
        return dp[0] > 0


if __name__ == "__main__":
    obj = Solution()
    print(obj.stoneGame([5, 3, 4, 5]))  # expect: True
    print(obj.stoneGame([3, 7, 2, 3]))  # expect: True
