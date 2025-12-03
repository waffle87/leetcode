# 625. Count Number of Trapezoids II
from collections import Counter
from itertools import combinations
from math import comb, gcd

"""
you are given a 2d integer array 'points' where 'points[i] = [x_i, y_i]'
represents the coordinates of the i'th point on the cartesian plane. return
the number of unique trapezoids that can be formed by choosing any four
distinct points from 'points'. a trapezoid is a convex quadrilateral with at
least one pair of parallel sides. two lines are parallel if and only if they
have the same slope.
"""


class Solution(object):
    def countTrapezoids(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        slopes = Counter()
        lines = Counter()
        mids = Counter()
        midlines = Counter()
        for (x1, y1), (x2, y2) in combinations(points, 2):
            dx, dy = x2 - x1, y2 - y1
            g = gcd(dx, dy)
            dx, dy = dx // g, dy // g
            if dx < 0 or (dx == 0 and dy < 0):
                dx, dy = -dx, -dy
                inter = dx * y1 - dy * x1
                slopes[dx, dy] += 1
                lines[dx, dy, inter] += 1
                mids[x1 + x2, y1 + y2] += 1
                midlines[x1 + x2, y1 + y2, dx, dy, inter] += 1
        ans = sum(comb(i, 2) for i in slopes.values())
        ans -= sum(comb(i, 2) for i in lines.values())
        ans -= sum(comb(i, 2) for i in mids.values())
        ans += sum(comb(i, 2) for i in midlines.values())
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countTrapezoids(points=[[-3, 2], [3, 0], [2, 3], [3, 2], [2, -3]]))
    print(obj.countTrapezoids(points=[[0, 0], [1, 0], [0, 1], [2, 1]]))
