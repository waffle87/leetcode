# 1637. Widest Vertical Area Between Two Points Containing No Points

"""
given 'n' points on a 2d plane where 'points [i] = [x[i], y[i]]', return the
widest veritcal area between two points such that no points are inside the
area. a vertical area is an area of fixed width extending infinitely along
the y-axis. the widest vertical area is the one with the maximum width. note
that the points on the edge of a vertical area are not considred included in
the area.
"""


class Solution(object):
    def maxWidthOfVerticalArea(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        area = sorted({x for x, y in points})
        return max([b - a for a, b in zip(area, area[1:])] + [0])


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.maxWidthOfVerticalArea(points=[[8, 7], [9, 9], [7, 4], [9, 7]])
    )  # expect: 1
    print(
        obj.maxWidthOfVerticalArea(
            points=[[3, 1], [9, 0], [1, 0], [1, 4], [5, 3], [8, 8]]
        )
    )  # expect: 3
