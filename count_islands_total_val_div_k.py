# 3619. Count Islands With Total Value Divisible by K

"""
you are given an 'm x n' matrix 'grid' and a positive integer 'k'. an island
is a group of positive integers that are 4 directionally connected. the total
value of an island is the sum of the values of all cedlls in the island.
return the number of islands with a total value divisible by 'k'.
"""

import numpy as np
from scipy.ndimage import label


class Solution:
    def countIslands(self, grid: list[list[int]], k: int) -> int:
        g = np.array(grid)
        labels, _ = label(g)
        totals = np.bincount(labels.ravel(), weights=g.ravel())[1:].astype(np.int64)
        return int(np.count_nonzero(totals % k == 0))


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.countIslands(
            grid=[
                [0, 2, 1, 0, 0],
                [0, 5, 0, 0, 5],
                [0, 0, 1, 0, 0],
                [0, 1, 4, 7, 0],
                [0, 2, 0, 0, 8],
            ],
            k=5,
        )
    )
    print(obj.countIslands(grid=[[3, 0, 3, 0], [0, 3, 0, 3], [3, 0, 3, 0]], k=3))
