# 1878. Get Biggest Three Rhombus Sums in a Grid
import heapq
from typing import List

"""
you are given an 'm x n' integer matrix 'grid'. a rhombus sum is the sum of
the elements that form the border of regular rhombus shape in 'grid'. the
rhombus must have the shape of a square rotated 45 degrees with each of the
corners centered in a grid cell.
"""


class Solution:
    def getBiggestThree(self, grid: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0])
        max_length = min((m - 1) // 2, (n - 1) // 2)
        best = []
        heapq.heapify(best)

        def rhombus_sum(r, c, k):
            result = grid[r][c]
            for s in range(k):
                r += 1
                result += grid[r][c + s + 1]
                result += grid[r][c - s - 1]
            for s in range(k - 1, -1, -1):
                r += 1
                result += grid[r][c + s]
                if s > 0:
                    result += grid[r][c - s]
            return result

        for r in range(m):
            for c in range(n):
                for k in range(max_length + 1):
                    if c >= k and c + k < n and r + 2 * k < m:
                        candidate = rhombus_sum(r, c, k)
                        if candidate not in set(best):
                            heapq.heappush(best, candidate)
                        if len(best) > 3:
                            heapq.heappop(best)
        return sorted(best, reverse=True)


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.getBiggestThree(
            grid=[
                [3, 4, 5, 1, 3],
                [3, 3, 4, 2, 3],
                [20, 30, 200, 40, 10],
                [1, 5, 5, 4, 1],
                [4, 3, 2, 2, 5],
            ]
        )
    )
    print(obj.getBiggestThree(grid=[[1, 2, 3], [4, 5, 6], [7, 8, 9]]))
    print(obj.getBiggestThree(grid=[[7, 7, 7]]))
