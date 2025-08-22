# 3195. Find the Minimum Area to Cover All Ones I

"""
you are given a 2d binary array 'grid'. find a rectangle with horizontal and
vertical lines with the smallest area, such that all the 1's in 'grid' lie
inside this rectangle. return the minimum possible area of the rectangle.
"""


class Solution:
    def minimumArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        min_row, max_row = m, -1
        min_col, max_col = n, -1
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    min_row = min(min_row, i)
                    max_row = max(max_row, i)
                    min_col = min(min_col, j)
                    max_col = max(max_col, j)
        return (max_row - min_row + 1) * (max_col - min_col + 1)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumArea(grid=[[0, 1, 0], [1, 0, 1]]))
    print(obj.minimumArea(grid=[[1, 0], [0, 0]]))
