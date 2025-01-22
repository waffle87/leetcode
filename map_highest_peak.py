# 1765. Map of Highest Peak
from collections import deque

"""
you are given an integer matrix 'isWater' of size 'm x n' that represents a
map of land and water cells. if 'isWater[i][j] == 0' cell '(i, j)' is a land
cell. if 'isWater[i][j] == 1', cell '(i, j)' is a water cell. you must assign
each cell a height in a way that follows the given rules. find an assignment
of heights such that the maximum height in the matrix is maximised.
"""


class Solution(object):
    def highestPeak(self, isWater):
        """
        :type isWater: List[List[int]]
        :rtype: List[List[int]]
        """
        m, n = len(isWater), len(isWater[0])
        height = [[-1] * n for _ in range(m)]
        bfs = deque([])
        for r in range(m):
            for c in range(n):
                if isWater[r][c] == 1:
                    bfs.append((r, c))
                    height[r][c] = 0
        dir = [0, 1, 0, -1, 0]
        while bfs:
            r, c = bfs.popleft()
            for i in range(4):
                nr, nc = r + dir[i], c + dir[i + 1]
                if nr < 0 or nr == m or nc < 0 or nc == n or height[nr][nc] != -1:
                    continue
                height[nr][nc] = height[r][c] + 1
                bfs.append((nr, nc))
        return height


if __name__ == "__main__":
    obj = Solution()
    print(obj.highestPeak(isWater=[[0, 1], [0, 0]]))
    print(obj.highestPeak(isWater=[[0, 0, 1], [1, 0, 0], [0, 0, 0]]))
