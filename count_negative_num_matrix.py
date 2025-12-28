# 1351. Count Negative Numbers in a Sorted Matrix

"""
given an 'm x n' matrix 'grid' which is sorted in non-increasing order both
row-wise and column-wise, return the number of negative numbers in 'grid'
"""


class Solution(object):
    def countNegatives(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        r, c, cnt = n - 1, 0, 0
        while r >= 0 and c < m:
            if grid[r][c] < 0:
                cnt += m - c
                r -= 1
            else:
                c += 1
        return cnt


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.countNegatives(
            grid=[[4, 3, 2, -1], [3, 2, 1, -1], [1, 1, -1, -2], [-1, -1, -2, -3]]
        )
    )
    print(obj.countNegatives(grid=[[3, 2], [1, 0]]))
