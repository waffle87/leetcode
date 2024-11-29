# 174. Dungeon Game

"""
the demons had captured the princess and imprisoned her in the bottom right
corner of a dungeon. the 'dungeon' consists of 'm x n' rooms laid out in a 2d
grid. our valiant knight was initially positioned in the top left room and
must fight his way through the 'dungeon' to rescue the princess. return the
knight's minimum initial health so that he can rescue the princess. note that
any romm can contain threats or power ups even the first room the knight
enters and the bottom right room where the princess is imprisoned
"""


class Solution(object):
    def calculateMinimumHP(self, dungeon):
        """
        :type dungeon: List[List[int]]
        :rtype: int
        """
        m, n = len(dungeon), len(dungeon[0])
        dp = [[float("inf")] * (n + 1) for _ in range(m + 1)]
        dp[m - 1][n], dp[m][n - 1] = 1, 1
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1)
        return dp[0][0]


if __name__ == "__main__":
    obj = Solution()
    print(obj.calculateMinimumHP(dungeon=[[-2, -3, 3], [-5, -10, 1], [10, 30, -5]]))
    print(obj.calculateMinimumHP(dungeon=[[0]]))
