# 1219. Path with Maximum Gold

"""
in a gold mine 'grid' of size 'm  n' each cell in this mine has an integer
representing the amount of gold in that cell, 0 if it is empty. return the
maximum amount of gold you can collect under the conditions: every time you
are located in a cell, you will collect all the gold in that cell. from your
position, you can walk one step to the left, right, up, or down. you cannot
visit thesame cell more than once. never visit a cell with 0 gold. you can
start and stop collecting gold from any position in the grid that has some
gold.
"""


class Solution(object):
    def dfs(self, grid, r, c, m, n):
        if r < 0 or r == m or c < 0 or c == n or grid[r][c] == 0:
            return 0
        res, start_pos = 0, grid[r][c]
        dir = [0, 1, 0, -1, 0]
        grid[r][c] = 0
        for i in range(4):
            res = max(res, self.dfs(grid, r + dir[i], c + dir[i + 1], m, n))
        grid[r][c] = start_pos
        return res + grid[r][c]

    def getMaximumGold(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        ans, m, n = 0, len(grid), len(grid[0])
        for r in range(m):
            for c in range(n):
                ans = max(ans, self.dfs(grid, r, c, m, n))
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.getMaximumGold(grid=[[0, 6, 0], [5, 8, 7], [0, 9, 0]]))
    print(
        obj.getMaximumGold(
            grid=[[1, 0, 7], [2, 0, 6], [3, 4, 5], [0, 3, 0], [9, 0, 20]]
        )
    )
