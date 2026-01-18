# 1895. Largest Magic Square

"""
a 'k x k' magic square is 'k x k' grid filled with integers such that every
row sum, every column sum, and both diagonal sums are all equal. the integers
in the magic square do not have to be distinct. every '1 x 1' grid is
trivally a magic square. given an 'm x n' integer 'grid', return the size
(ie. the side length 'k') of the largest magic square that can be found
within this grid.
"""


class Solution(object):
    def largestMagicSquare(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n, m, ans = len(grid), len(grid[0]), 1

        def valid(i, j, k):
            s = None
            for x in range(i, i + k):
                row = sum(grid[x][j : j + k])
                if s is None:
                    s = row
                elif s != row:
                    return False
            for y in range(j, j + k):
                if sum(grid[x][y] for x in range(i, i + k)) != s:
                    return False
            if sum(grid[i + d][j + d] for d in range(k)) != s:
                return False
            if sum(grid[i + d][j + k - 1 - d] for d in range(k)) != s:
                return False
            return True

        for k in range(2, min(n, m) + 1):
            for i in range(n - k + 1):
                for j in range(m - k + 1):
                    if valid(i, j, k):
                        ans = k
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.largestMagicSquare(
            grid=[[7, 1, 4, 5, 6], [2, 5, 1, 6, 4], [1, 5, 4, 3, 2], [1, 2, 7, 3, 4]]
        )
    )
    print(obj.largestMagicSquare(grid=[[5, 1, 3, 1], [9, 3, 3, 1], [1, 3, 3, 8]]))
