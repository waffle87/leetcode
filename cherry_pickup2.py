# 1463. Cherry Pickup II

"""
given a row  cols matrix grid representing a field of cherries where
'grid[i][j]' represents the number of cherries that you can collect from the
'(i, j)' cell. you have two robots that can collect cherries for you located
at corner (0, 0) and (cols - 1). return the maximum number of cherries
collection using both robots by following the rulew below.
"""


class Solution(object):
    def cherryPickup(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])

        #@lru_cache(None)
        def dfs(r, c1, c2):
            if r == m:
                return 0
            cherries = grid[r][c1] if c1 == c2 else grid[r][c1] + grid[r][c2]
            ans = 0
            for nc1 in range(c1 - 1, c1 + 2):
                for nc2 in range(c2 - 1, c2 + 2):
                    if 0 <= nc1 < n and 0 <= nc2 < n:
                        ans = max(ans, dfs(r + 1, nc1, nc2))
            return ans + cherries

        return dfs(0, 0, n - 1)


if __name__ == "__main__":
    obj = Solution()
    print(obj.cherryPickup(grid=[[3, 1, 1], [2, 5, 1], [1, 5, 5], [2, 1, 1]]))
    print(
        obj.cherryPickup(
            grid=[
                [1, 0, 0, 0, 0, 0, 1],
                [2, 0, 0, 0, 0, 3, 0],
                [2, 0, 9, 0, 0, 0, 0],
                [0, 3, 0, 5, 4, 0, 0],
                [1, 0, 2, 3, 0, 0, 6],
            ]
        )
    )
