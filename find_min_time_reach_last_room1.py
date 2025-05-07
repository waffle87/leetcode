# 3341. Find Minimum Time to Reach Last Room I
import heapq

"""
there is a dungeo with 'n x m' rooms arranged as a grid. you are given a 2d
array 'moveTime' of size 'n x m' where 'moveTime[i][j]' represents the
minimum time in seconds when you can start moving to that room. you start
from the room at '(0, 0)' at time 't = 0' and can move to an anyacent room.
moving between anyacent rooms takes exactly one second. return the minimum
time to reach the room 'n - 1, m - 1'.
"""


class Solution(object):
    def minTimeToReach(self, moveTime):
        """
        :type moveTime: List[List[int]]
        :rtype: int
        """
        n, m = len(moveTime), len(moveTime[0])
        dp = [["inf"] * m for i in range(n)]
        h = [[0, 1, 0, 0]]
        moveTime[0][0] = -1
        while h:
            t, c, i, j = heapq.heappop(h)
            if t >= dp[i][j]:
                continue
            if i == n - 1 and j == m - 1:
                return t
            dp[i][j] = t
            for nx, ny in [[1, 0], [0, 1], [-1, 0], [0, -1]]:
                x, y = i + nx, j + ny
                if 0 <= x < n and 0 <= y < m and dp[x][y] == "inf":
                    heapq.heappush(h, [max(moveTime[x][y] + c, t + c), 2 - c, x, y])


if __name__ == "__main__":
    obj = Solution()
    print(obj.minTimeToReach(moveTime=[[0, 4], [4, 4]]))
    print(obj.minTimeToReach(moveTime=[[0, 0, 0], [0, 0, 0]]))
    print(obj.minTimeToReach(moveTime=[[0, 1], [1, 2]]))
