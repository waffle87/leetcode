# 840. Magic Squares In Grid

"""
a 3  3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9
such that each row, column, and both diagonals all have the same sum. given a
row x col 'grid' of integers, how many 3 x 3 contiguous magic square subgrids
are there? note, while a magic square can only contain numbers from 1 to 9,
'grid' may contain numbers up to 15.
"""


class Solution(object):
    def numMagicSquaresInside(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        def isMagic(i, j):
            s = "".join(
                str(grid[i + x / 3][j + x % 3]) for x in [0, 1, 2, 5, 8, 7, 6, 3]
            )
            return grid[i][j] % 2 == 0 and (
                s in "43816729" * 2 or s in "43816729"[::-1] * 2
            )

        return sum(
            isMagic(i, j)
            for i in range(len(grid) - 2)
            for j in range(len(grid[0]) - 2)
            if grid[i + 1][j + 1] == 5
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.numMagicSquaresInside(grid=[[4, 3, 8, 4], [9, 5, 1, 9], [2, 7, 6, 2]]))
    print(obj.numMagicSquaresInside(grid=[[8]]))
