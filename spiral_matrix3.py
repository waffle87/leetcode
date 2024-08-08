# 885. Spiral Matrix III

"""
you start at the cell '(rStart, cStart)' of an 'rows  cols' grid facing
east. the northwest corner is at the first row and column in the grid, and
the southeast corner is at the last row and column. you will walk in a
clockwise spiral shape to visit every position in this gid. whenever you move
outside the grid's boundary, we continue our walk outside the grid (but may
return to the gid boundary later). eventually we reach all 'rows  cols'
spaces of the grid. return an array of coordinates representing the positions
of the grid in the order visited.
"""


class Solution(object):
    def spiralMatrixIII(self, rows, cols, rStart, cStart):
        """
        :type rows: int
        :type cols: int
        :type rStart: int
        :type cStart: int
        :rtype: List[List[int]]
        """
        ans = []
        dx, dy, n = 0, 1, 0
        while len(ans) < rows * cols:
            for i in range(n / 2 + 1):
                if 0 <= x < rows and 0 <= y < cols:
                    ans.append([x, y])
                x, y = x + dx, y + dy
            dx, dy, n = dy, -dx, n + 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.spiralMatrixIII(rows=1, cols=4, rStart=0, cStart=0))
    print(obj.spiralMatrixIII(rows=5, cols=6, rStart=1, cStart=4))
