# 3342. Find Minimum Time to Reach Last Room II
import heapq

"""
there is a dungeon with 'n x m' rooms arranged as a grid. you are given a 2d
array 'moveTime' of size 'n x m' where 'moveTime[i][j]' represents the
minimum time in seconds when you can start moving to that room. you start
from the room '(0, 0)' at time 't = 0' and can move to an adjacent room.
moving between adjacent rooms takes one second for one move and two seconds
for the next, alternating between the two. return the minimum time to reach
the room '(n - 1, m - 1)'.
"""


class Solution(object):
    def minTimeToReach(self, moveTime):
        """
        :type moveTime: List[List[int]]
        :rtype: int
        """
        n, m = len(moveTime), len(moveTime[0])
        dp = [["inf"] * m for i in range(n)]
        heap = [[0, 0, 0]]
        moveTime[0][0] = -1
        while heap:
            t, i, j = heapq.heappop(heap)
            if t >= dp[i][j]:
                continue
            if i == n - 1 and j == m - 1:
                return t
            dp[i][j] = t
            for di, dj in [[1, 0], [0, 1], [-1, 0], [0, -1]]:
                x, y = i + di, j + dj
                c = (i + j) % 2 + 1
                if 0 <= x < n and 0 <= y < m and dp[x][y] == "inf":
                    heapq.heappush(heap, [max(moveTime[x][y], t) + c, x, y])


if __name__ == "__main__":
    obj = Solution()
    print(obj.minTimeToReach(moveTime=[[0, 4], [4, 4]]))
    print(obj.minTimeToReach(moveTime=[[0, 0, 0, 0], [0, 0, 0, 0]]))
    print(obj.minTimeToReach(moveTime=[[0, 1], [1, 2]]))
