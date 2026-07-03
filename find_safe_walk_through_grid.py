# 3286. Find a Safe Walk Through a Grid
from functools import lru_cache
from itertools import product

"""
you are given an 'm x n' binary matrix 'grid' and an integer 'health'. you
start on the upper left corner and would like to get to the lower right
corner. you can move up, down, left, or right from one cell to another
adjacent cell as long as your health remains positive. cells '(i, j)' with
grid 'grid[i][j] == 1' are considered unsafe and reduce your health by 1.
return true if you can reach the final cell with a health of value 1 or more,
and false otherwise.
"""


class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        @lru_cache(None)
        def dp(x, y, health_used):
            if health_used == health or (x, y) not in eligible:
                return float("inf")
            cnt = health_used + grid[x][y]
            if (x, y) == (m - 1, n - 1):
                return cnt
            eligible.discard((x, y))
            res = min(
                dp(x + 1, y, cnt),
                dp(x, y + 1, cnt),
                dp(x - 1, y, cnt),
                dp(x, y - 1, cnt),
            )
            eligible.add((x, y))
            return res

        m, n = len(grid), len(grid[0])
        eligible = set(product(range(m), range(n)))
        return dp(0, 0, 0) < health


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.findSafeWalk(
            grid=[[0, 1, 0, 0, 0], [0, 1, 0, 1, 0], [0, 0, 0, 1, 0]], health=1
        )
    )
    print(
        obj.findSafeWalk(
            grid=[
                [0, 1, 1, 0, 0, 0],
                [1, 0, 1, 0, 0, 0],
                [0, 1, 1, 1, 0, 1],
                [0, 0, 1, 0, 1, 0],
            ],
            health=3,
        )
    )
    print(obj.findSafeWalk(grid=[[1, 1, 1], [1, 0, 1], [1, 1, 1]], health=5))
