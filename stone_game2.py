# 1140. Stone Game II

"""
alice and bob continue their games with piles of stones. there are a number
of piles arranged in a row, and each pile has a positive integer number of
stones 'piles[i]'. the objective of the game is to end with the most stones.
alice and bob take turns, with alice starting first. initiall, 'M = 1'. on
each player's turn, that player can take all the stones on the 'X' remaining
piles, where '1 <= X <= 2M'. then, we set 'M = max(M, X)'. the game continues
until all the stones have been take. assuming alice and bob play optimally,
return maximum stones alice can get.
"""


class Solution(object):
    def stoneGameII(self, piles):
        """
        :type piles: List[int]
        :rtype: int
        """

        def dp(x, y, z):
            if y == len(piles):
                return 0
            if x == 0:
                curr, res = 0, float("-inf")
                for i in range(1, min(z * 2, len(piles) - y) + 1):
                    curr += piles[y + i - 1]
                    res = max(res, curr + dp(1, y + i, max(i, z)))
            else:
                res = float("inf")
                for i in range(1, min(z * 2, len(piles) - y) + 1):
                    res = min(res, dp(0, y + i, max(i, z)))
            return res

        return dp(0, 0, 1)


if __name__ == "__main__":
    obj = Solution()
    print(obj.stoneGameII(piles=[2, 7, 9, 4, 4]))
    print(obj.stoneGameII(piles=[1, 2, 3, 4, 5, 100]))
