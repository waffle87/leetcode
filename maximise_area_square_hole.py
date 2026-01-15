# 2943. Maximize Area of Square Hole in Grid
from itertools import pairwise

"""
you are given the two integers 'n' and 'm' and two integer arrays 'hBars' and
'vBars'. the grid has 'n + 2' horizontal and 'm + 2' vertical bars, creating
a 1x1 unit cells. the bars are indexed starting from 1. you can remove some
of the bars in 'hBars' from horizontal bars and some of the bars in 'vBars'
from vertical bars. note that other bars are fixed and cannot be removed.
return an integer denoting the maximum area of a square shaped hole in the
grid, after removing some bars.
"""


class Solution(object):
    def maximizeSquareHoleArea(self, n, m, hBars, vBars):
        """
        :type n: int
        :type m: int
        :type hBars: List[int]
        :type vBars: List[int]
        :rtype: int
        """

        def find_max(bars):
            bars.sort()
            s = "".join([str(int(y - x == 1)) for x, y in pairwise(bars)])
            return max(map(len, s.split("0"))) + 2

        return pow(min(find_max(hBars), find_max(vBars)), 2)


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximizeSquareHoleArea(n=2, m=1, hBars=[2, 3], vBars=[2]))
    print(obj.maximizeSquareHoleArea(n=1, m=1, hBars=[2], vBars=[2]))
    print(obj.maximizeSquareHoleArea(n=2, m=3, hBars=[2, 3], vBars=[2, 4]))
