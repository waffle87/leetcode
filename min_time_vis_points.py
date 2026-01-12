# 1266. Minimum Time Visiting All Points

"""
on a 2d plane, there are 'n' points with integer coordinate points 'points[i]
= [x_i, y_i]'. return the minimum time in seconds to visit all the points in
the order given by 'points'. you can move according to these rules: in 1
second, you can either move vertically or horizontally by one unit, or move
diagonally 'sqrt(2)' units. you have to visit the points in the same order
they appear in the array, and you are allowed to pass through points that
appear late in the order, but these do not count as visits.
"""


class Solution(object):
    def minTimeToVisitAllPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        return sum(
            max(abs(i - j) for i, j in zip(curr, prev))
            for curr, prev in zip(points, points[1:])
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.minTimeToVisitAllPoints(points=[[1, 1], [3, 4], [-1, 0]]))
    print(obj.minTimeToVisitAllPoints(points=[[3, 2], [-2, 2]]))
