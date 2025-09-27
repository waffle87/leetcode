# 812. Largest Triangle Area
from itertools import combinations

"""
given an array of points on the x-y plane 'points' where 'points[i] = [x_i,
y_i]' return the area of the largest triangle that can be formed by any three
different points. answers within 10^-5 will be accepted.
"""


class Solution(object):
    def largestTriangleArea(self, points):
        """
        :type points: List[List[int]]
        :rtype: float
        """
        return max(
            0.5
            * abs(
                i[0] * j[1]
                + j[0] * k[1]
                + k[0] * i[1]
                - j[0] * i[1]
                - k[0] * j[1]
                - i[0] * k[1]
            )
            for i, j, k in combinations(points, 3)
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.largestTriangleArea(points=[[0, 0], [0, 1], [1, 0], [0, 2], [2, 0]]))
    print(obj.largestTriangleArea(points=[[1, 0], [0, 0], [0, 1]]))
