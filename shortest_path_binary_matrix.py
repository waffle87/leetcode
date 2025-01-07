# 1091. Shortest Path in Binary Matrix

"""
given an n x n binary matrix 'grid', return the length of the shortest clear
path in the matrix. if there is no clear path, return -1. a clear path in a
binary matrix is a path from the top-left cell (ie. 0,0) to the bottom-right
cell (ie. n - 1, n - 1) such thatyt
- all the visited cells are of the path 0
- all the adjacent cells of the path are 8-directionally connected (ie. they
are different and they share an edge of a corner) the length of a clear path
is the number of visited cells of this path
"""


class Solution(object):
    def shortestPathBinaryMatrix(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        if grid[0][0] or grid[n - 1][n - 1]:
            return -1
        q = [(0, 0, 1)]
        grid[0][0] = 1
        for i, j, d in q:
            if i == n - 1 and j == n - 1:
                return d
            for x, y in (
                (i - 1, j - 1),
                (i - 1, j),
                (i - 1, j + 1),
                (i, j - 1),
                (i, j + 1),
                (i + 1, j - 1),
                (i + 1, j),
                (i + 1, j + 1),
            ):
                if 0 <= x < n and 0 <= y < n and not grid[x][y]:
                    grid[x][y] = 1
                    q.append((x, y, d + 1))
        return -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.shortestPathBinaryMatrix(grid=[[0, 1], [1, 0]]))
    print(obj.shortestPathBinaryMatrix(grid=[[0, 0, 0], [1, 1, 0], [1, 1, 0]]))
    print(obj.shortestPathBinaryMatrix(grid=[[1, 0, 0], [1, 1, 0], [1, 1, 0]]))
