# 2742. Painting the Walls

"""
you are given two 0-indexed integer arrays, cost and time of size n
representing the costs and the time taken to paint n walls respectively.
there are two painters available:
- a paid painter that paints the i'th wall in 'time[i]' units of time and
takes 'cost[i]' units of money
- a free painter that paints any wall in 1 unit of time at a cost of 0. but
the free painter can only be used if the paid painter is already occupied
return the minimum amount of money required to paint the 'n' walls.
"""


class Solution(object):
    def paintWalls(self, cost, time):
        n = len(cost)
        dp = [[0x3F3F3F3F3F3F for i in range(n + 1)] for j in range(n + 1)]
        dp[0][0] = 0
        for i in range(n):
            for j in range(n + 1):
                t = min(n, j + time[i] + 1)
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j])
                dp[i + 1][t] = min(dp[i + 1][t], dp[i][j] + cost[i])
        return dp[n][n]


if __name__ == "__main__":
    obj = Solution()
    print(obj.paintWalls([1, 2, 3, 2], [1, 2, 3, 2]))  # expect: 3
    print(obj.paintWalls([2, 3, 4, 2], [1, 1, 1, 1]))  # expect: 4
