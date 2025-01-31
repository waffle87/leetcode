# 827. Making A Large Island

"""
you are given an 'm x n' binary matrix 'grid'. you are allowed to change at
most one 0 to be 1. return size of the largest island in 'grid' after
applying this operation. an island is a 4-directionally connected group of
1's.
"""


class Solution(object):
    def largestIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)

        def move(x, y):
            for i, j in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                if 0 <= x + i < n and 0 <= y + j < n:
                    yield x + i, y + j

        def dfs(x, y, idx):
            res = 0
            grid[x][y] = idx
            for i, j in move(x, y):
                if grid[i][j] == 1:
                    res += dfs(i, j, idx)
            return res + 1

        idx, areas = 2, {0: 0}
        for x in range(n):
            for y in range(n):
                if grid[x][y] == 1:
                    areas[idx] = dfs(x, y, idx)
                    idx += 1
        ans = max(areas.values())
        for x in range(n):
            for y in range(n):
                if grid[x][y] == 0:
                    valid = set(grid[i][j] for i, j in move(x, y))
                    ans = max(ans, sum(areas[idx] for idx in valid) + 1)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.largestIsland(grid=[[1, 0], [0, 1]]))
    print(obj.largestIsland(grid=[[1, 1], [1, 0]]))
    print(obj.largestIsland(grid=[[1, 1], [1, 1]]))
