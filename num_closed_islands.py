# 1254. Number of Closed Islands

"""
given 2d 'grid' consists of 0's (land) and 1's (water). an island is a
maximal four directionally connected group of 0's and a closed island is an
island totally (all left, top, right, bottom) surrouned by 1's. return the
number of closed islands.
"""


class Solution:
    def closedIsland(self, grid: list[list[int]]) -> int:
        m, n = len(grid), len(grid[0])

        def dfs(r, c):
            grid[r][c] = 1
            if r > 0 and not grid[r - 1][c]:
                dfs(r - 1, c)
            if r + 1 < m and not grid[r + 1][c]:
                dfs(r + 1, c)
            if c > 0 and not grid[r][c - 1]:
                dfs(r, c - 1)
            if c + 1 < n and not grid[r][c + 1]:
                dfs(r, c + 1)

        for i in range(m):
            if not grid[i][0]:
                dfs(i, 0)
            if not grid[i][n - 1]:
                dfs(i, n - 1)
        for i in range(n):
            if not grid[0][i]:
                dfs(0, i)
            if not grid[m - 1][i]:
                dfs(m - 1, i)
        cnt = 0
        for i in range(1, m - 1):
            r = grid[i]
            for j in range(1, n - 1):
                if not r[j]:
                    cnt += 1
                    dfs(i, j)
        return cnt


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.closedIsland(
            grid=[
                [1, 1, 1, 1, 1, 1, 1, 0],
                [1, 0, 0, 0, 0, 1, 1, 0],
                [1, 0, 1, 0, 1, 1, 1, 0],
                [1, 0, 0, 0, 0, 1, 0, 1],
                [1, 1, 1, 1, 1, 1, 1, 0],
            ]
        )
    )
    print(obj.closedIsland(grid=[[0, 0, 1, 0, 0], [0, 1, 0, 1, 0], [0, 1, 1, 1, 0]]))
    print(
        obj.closedIsland(
            grid=[
                [1, 1, 1, 1, 1, 1, 1],
                [1, 0, 0, 0, 0, 0, 1],
                [1, 0, 1, 1, 1, 0, 1],
                [1, 0, 1, 0, 1, 0, 1],
                [1, 0, 1, 1, 1, 0, 1],
                [1, 0, 0, 0, 0, 0, 1],
                [1, 1, 1, 1, 1, 1, 1],
            ]
        )
    )
