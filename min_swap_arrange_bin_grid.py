# 1536. Minimum Swaps to Arrange a Binary Grid
from typing import List

"""
given an 'n x n' binary 'grid', in one step you can choose two adjacent rows
of the grid and swap them. a grid is said to be valid if all the cells above
the main diagonal are zeros. return the minimum number of steps needed to
make the grid valid, or -1 if the grid cannot be made valid. the main
diagonal of a grid is the diagonal that starts at cell '(1, 1)' and ends at
'(n, n)'.
"""


class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        n, ans = len(grid), 0
        pos = [-1] * n
        for i in range(n):
            for j in range(n - 1, -1, -1):
                if grid[i][j] == 1:
                    pos[i] = j
                    break
        for i in range(n):
            k = -1
            for j in range(i, n):
                if pos[j] <= i:
                    ans += j - i
                    k = j
                    break
            if k != -1:
                for j in range(k, i, -1):
                    pos[j], pos[j - 1] = pos[j - 1], pos[j]
            else:
                return -1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minSwaps(grid=[[0, 0, 1], [1, 1, 0], [1, 0, 0]]))
    print(obj.minSwaps(grid=[[0, 1, 1, 0], [0, 1, 1, 0], [0, 1, 1, 0], [0, 1, 1, 0]]))
    print(obj.minSwaps(grid=[[1, 0, 0], [1, 1, 0], [1, 1, 1]]))
