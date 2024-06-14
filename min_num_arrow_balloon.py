# 452. Minimum Number of Arrows to Burst Balloons

"""
there are some spherical balloons taped onto a flat wall that represents the
xy plane. the ballooons are represented as a 2d integer array 'points' where
'points[i] = [x_start, x_end]'. you do not know the exact y coordinates of
the balloons. arrows can be shot up directly vertically in the positive y
direction. from different points along the x axis. given the array points,
return the minimum number of arrows that must be shot to burst all balloons.
"""


class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        points.sort(key=lambda p: p[1])
        ans, arrow = 0, 0
        for [start, end] in points:
            if ans == 0 or start > arrow:
                ans, arrow = ans + 1, end
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.findMinArrowShots(points=[[10, 16], [2, 8], [1, 6], [7, 12]]))
    print(obj.findMinArrowShots(points=[[1, 2], [3, 4], [5, 6], [7, 8]]))
    print(obj.findMinArrowShots(points=[[1, 2], [2, 3], [3, 4], [4, 5]]))
