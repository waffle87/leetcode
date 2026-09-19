# 1401. Circle and Rectangle Overlapping

"""
you are given a circle represented as '(radius, xcenter, ycenter)' and an
axis-aligned rectangle represented as '(x1, y1, x2, y2)' where '(x1, y1)' are
the coordinates of the bottom left corner, and '(x2, y2)' are the coordinates
of the top right corner of the rectangle. return true if the circle and
rectangle are overlapped otherwise return 'false'. in other words, check if
there is any point '(xi, yi)' that belongs to the circle and the rectangle at
the same time.
"""


class Solution:
    def checkOverlap(
        self,
        radius: int,
        xCenter: int,
        yCenter: int,
        x1: int,
        y1: int,
        x2: int,
        y2: int,
    ) -> bool:
        x = max(x1, min(xCenter, x2)) - xCenter
        y = max(y1, min(yCenter, y2)) - yCenter
        return x * x + y * y <= radius * radius


if __name__ == "__main__":
    obj = Solution()
    print(obj.checkOverlap(1, 0, 0, 1, -1, 3, 1))
    print(obj.checkOverlap(1, 1, 1, 1, -3, 2, -1))
    print(obj.checkOverlap(1, 0, 0, -1, 0, 0, 1))
