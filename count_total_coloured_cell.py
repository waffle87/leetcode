# 2579. Count Total Number of Colored Cells

"""
there exists an infinitely large two-dimensional grid of uncoloured unit
cells. you are given a positive integer 'n', indicating that you must do the
following routine for 'n' minutes: at the first minute, colour any arbitrary
unit cell blue, and every minute thereafter, colour blue every uncoloured
cell that touches a blue cell.
"""


class Solution(object):
    def coloredCells(self, n):
        """
        :type n: int
        :rtype: int
        """
        return 1 + 4 * sum(range(n))


if __name__ == "__main__":
    obj = Solution()
    print(obj.coloredCells(n=1))
    print(obj.coloredCells(n=2))
