# 3197. Find the Minimum Area to Cover All Ones II

"""
you are giiven a 2d binary array 'grid'. you need to find 3 non-overlapping
rectangles having non-zero areas with horizontal and vertical sides such that
all the 1's in the 'grid' lie inside these rectangles. return the minimum
possible sum of the area of these rectangles. note that the rectangles are
allowed to touch.
"""


class Solution(object):
    def min_area(self, grid):
        if not grid or not grid[0]:
            return 0
        n, m = len(grid), len(grid[0])
        left, top, right, bottom = float("inf"), float("inf"), -1, -1
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    left = min(left, j)
                    top = min(top, i)
                    right = max(right, j)
                    bottom = max(bottom, i)
        if right == -1:
            return 0
        return (right - left + 1) * (bottom - top + 1)

    def rotate(self, grid):
        n, m = len(grid), len(grid[0])
        return [[grid[i][j] for i in range(n - 1, -1, -1)] for j in range(m)]

    def minimumSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        ans = float("inf")
        for _ in range(4):
            n, m = len(grid), len(grid[0])
            for i in range(1, n):
                a1 = self.min_area(grid[:i])
                for j in range(1, m):
                    p2 = [row[:j] for row in grid[i:]]
                    p3 = [row[j:] for row in grid[i:]]
                    a2 = self.min_area(p2)
                    a3 = self.min_area(p3)
                    ans = min(ans, a1 + a2 + a3)
                for i2 in range(i + 1, n):
                    p2 = grid[i:i2]
                    p3 = grid[i2:]
                    a2 = self.min_area(p2)
                    a3 = self.min_area(p3)
                    ans = min(ans, a1 + a2 + a3)
            grid = self.rotate(grid)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumSum(grid=[[1, 0, 1], [1, 1, 1]]))
    print(obj.minimumSum(grid=[[1, 0, 1, 0], [0, 1, 0, 1]]))
