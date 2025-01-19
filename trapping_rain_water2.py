# 407. Trapping Rain Water II
import heapq

"""
given an 'm x n' integer matrix 'heightMap' representing the height of each
unit cell in a 2d elevation map, return the volume of water it can trap after
raining
"""


class Solution(object):
    def trapRainWater(self, heightMap):
        """
        :type heightMap: List[List[int]]
        :rtype: int
        """
        m, n = len(heightMap), len(heightMap[0])
        if m < 3 or n < 3:
            return 0
        heap = []
        for i in range(m):
            for j in range(n):
                if i == 0 or i == m - 1 or j == 0 or j == n - 1:
                    heapq.heappush(heap, (heightMap[i][j], i, j))
                    heightMap[i][j] = -1
        level, ans = 0, 0
        while heap:
            h, x, y = heapq.heappop(heap)
            level = max(h, level)
            for i, j in [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)]:
                if 0 <= i < m and 0 <= j < n and heightMap[i][j] != -1:
                    heapq.heappush(heap, (heightMap[i][j], i, j))
                    if heightMap[i][j] < level:
                        ans += level - heightMap[i][j]
                    heightMap[i][j] = -1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.trapRainWater(
            heightMap=[[1, 4, 3, 1, 3, 2], [3, 2, 1, 3, 2, 4], [2, 3, 3, 2, 3, 1]]
        )
    )
    print(
        obj.trapRainWater(
            heightMap=[
                [3, 3, 3, 3, 3],
                [3, 2, 2, 2, 3],
                [3, 2, 1, 2, 3],
                [3, 2, 2, 2, 3],
                [3, 3, 3, 3, 3],
            ]
        )
    )
