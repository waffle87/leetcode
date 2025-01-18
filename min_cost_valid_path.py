# 1368. Minimum Cost to Make at Least One Valid Path in a Grid

"""
given an 'm x n' grid. each cell of the grid has a sign pointing to the next
cell you shhould visit if you are currently in this cell. notice that there
could be some signs on the cells of the grid that point outside the grid. you
will initially start at the upper left cell '(0, 0)'. a valid path in the
grid is a path that starts from the uppper left cell '(0, 0)' and ends at the
bbbottom right cell '(m - 1, n - 1)' following the signs on the grid. the
valid path does not have to bbe the shortest. return the minimum cost to make
the grid have at least one valid path
"""


class Solution(object):
    def minCost(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n, m, inf, k = len(grid), len(grid[0]), 10**9, 0
        dp, bfs = [[inf] * m for i in range(n)], []
        dir = [[0, 1], [0, -1], [1, 0], [-1, 0]]

        def dfs(x, y):
            if not (0 <= x < n and 0 <= y < m and dp[x][y] == inf):
                return
            dp[x][y] = k
            bfs.append([x, y])
            dfs(x + dir[grid[x][y] - 1][0], y + dir[grid[x][y] - 1][1])

        dfs(0, 0)
        while bfs:
            k += 1
            bfs, bfs2 = [], bfs
            [dfs(x + i, y + j) for x, y in bfs2 for i, j in dir]
        return dp[-1][-1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.minCost(grid=[[1, 1, 1, 1], [2, 2, 2, 2], [1, 1, 1, 1], [2, 2, 2, 2]]))
    print(obj.minCost(grid=[[1, 1, 3], [3, 2, 2], [1, 1, 4]]))
    print(obj.minCost(grid=[[1, 2], [4, 3]]))
