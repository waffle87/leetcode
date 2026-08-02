# 877. Stone Game

"""
alice and bob play a game with piles of stones. there are even number of
piles arranged in a row, and each pile has a positive integer number of
stones 'piles[i]'. the objective of the game is to end with with most stones.
the total number of stones across all piles is odd, so there are no ties.
alice and bob take turns, with alice  starting first.  each turn, a player
takes the entire pile of stones until  there are no more  piles left, at
which point the person with the most stones wins. assuming alice and bob play
optimally, return true if alice wins the game.
"""


class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        return True


if __name__ == "__main__":
    obj = Solution()
    print(obj.stoneGame(piles=[5, 4, 3, 4]))
    print(obj.stoneGame(piles=[3, 7, 2, 3]))
