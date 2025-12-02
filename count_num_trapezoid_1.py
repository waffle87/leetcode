# 3623. Count Number of Trapezoids I
from collections import defaultdict

"""
you are given a 2d integer array 'points' where 'points[i] = [x_i, y_i]'
represents the coordinates of the i'th point on the cartesian plane. a
horizontal trapezoid is a convex quadrilateral with at least one pair of
horizontal sides. two lines are parallel if and only if they have the same
slope. return the number of unique horizontal trapezoids that can be formed
by choosing any four distinct points from 'points'. since the answer may very
large, return it modulo 1e9 + 7.
"""


class Solution(object):
    def countTrapezoids(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        groups, mod = defaultdict(int), 10**9 + 7
        for _, y in points:
            groups[y] += 1
        ans, total = 0, 0
        for y, cnt in groups.items():
            lines = cnt * (cnt - 1) // 2
            ans = (ans + total * lines) % mod
            total = (total + lines) % mod
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countTrapezoids(points=[[1, 0], [2, 0], [3, 0], [2, 2], [3, 2]]))
    print(obj.countTrapezoids(points=[[0, 0], [1, 0], [0, 1], [2, 1]]))
