# 931. Minimum Falling Path Sum

"""
given an 'n  n' array of integers 'matrix', return the minimum sum of any
falling path through 'matrix'. a falling path starts at any element in the
first row and choose the element in the next row that is either directly
below or diagonally left/right. specifically, the next element from position
'(row, col)' will be '(row + 1, col - 1), (row + 1, col), or (row + 1, col +
1)'.
"""


class Solution(object):
    def minFallingPathSum(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        grid = matrix
        for i in range(1, len(grid)):
            for j in range(len(grid[i])):
                if i - 1 >= 0 and j - 1 >= 0:
                    p1 = grid[i - 1][j - 1]
                else:
                    p1 = float("inf")
                if i - 1 >= 0:
                    p2 = grid[i - 1][j]
                else:
                    p2 = float("inf")
                if i - 1 >= 0 and j + 1 <= len(grid[0]) - 1:
                    p3 = grid[i - 1][j + 1]
                else:
                    p3 = float("inf")
                grid[i][j] += min(p1, p2, p3)
        return min(grid[len(grid) - 1])


if __name__ == "__main__":
    obj = Solution()
    print(obj.minFallingPathSum(matrix=[[2, 1, 3], [6, 5, 4], [7, 8, 9]]))
    print(obj.minFallingPathSum(matrix=[[-19, 57], [-40, -5]]))
