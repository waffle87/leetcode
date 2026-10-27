# 3963. Create Grid With Exactly One Path

"""
you are given two integers 'n' and 'm' representing the number of rows and
columns of a grid. construct any 'm x n' grid consisting of the characters
'.' and '#' where '.' represents a free cell, and '#' represents an obstacle
cell. a valid path is a sequence of free cells that starts at the top left
cell and ends att the bottom right cell. return any grid such that there is
exactly one valid path from the top left cell to the bottom right cell.
"""


class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        return ["." * n] + [".".rjust(n, "#")] * (m - 1)


if __name__ == "__main__":
    obj = Solution()
    print(obj.createGrid(m=2, n=3))
    print(obj.createGrid(m=3, n=3))
    print(obj.createGrid(m=1, n=4))
