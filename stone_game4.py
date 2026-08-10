# 1510. Stone Game IV
from functools import cache
from math import isqrt

"""
alice and bob take turns playing a game with alice starting first. initially,
there are 'n' stones in a pile. on each player's turn, that player makes a
move consisting of removing any non-zero square number of stones in the pile.
also, if a player cannot make a move, he/she loses the game. given a positive
integer 'n', return true if and only if alice wins the game otherwise return
false assuming both players play optimally.
"""


class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        @cache
        def dfs(i):
            if i == 0:
                return False
            for j in range(1, isqrt(i) + 1):
                if not dfs(i - j**2):
                    return True
            return False

        return dfs(n)


if __name__ == "__main__":
    obj = Solution()
    print(obj.winnerSquareGame(n=1))
    print(obj.winnerSquareGame(n=2))
    print(obj.winnerSquareGame(n=4))
