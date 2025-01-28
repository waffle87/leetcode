# 2658. Maximum Number of Fish in a Grid

"""
you are given a 0-indexed 2d matrix 'grid' of size 'm x n' where '(r, c)'
represents a land cell if 'grid[r][c] = 0', or a water cell containing
'grid[r][c]' fish, if 'grid[r][c] > 0'. afisher can start at any water cell
and can do the following operations any number of times: catch all the fish
at the current cell, or move to any adjacent water cell. return the maximum
number of fish the fisher can catch if he chooses his starting cell
optimally, or 0 if no water cells exist.
"""


class Solution(object):
    def dfs(self, grid, r, c, n, m):
        dir = [0, 1, 0, -1, 0]
        cnt = grid[r][c]
        grid[r][c] = 0
        for i in range(4):
            nr = r + dir[i]
            nc = c + dir[i + 1]
            if nr >= 0 and nr < n and nc >= 0 and nc < m and grid[nr][nc] > 0:
                cnt += self.dfs(grid, nr, nc, n, m)
        return cnt

    def findMaxFish(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n, m, ans = len(grid), len(grid[0]), 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] > 0:
                    ans = max(ans, self.dfs(grid, i, j, n, m))
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.findMaxFish(grid=[[0, 2, 1, 0], [4, 0, 0, 3], [1, 0, 0, 4], [0, 3, 2, 0]])
    )
    print(
        obj.findMaxFish(grid=[[1, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 1]])
    )
