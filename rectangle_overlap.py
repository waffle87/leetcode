# 836. Rectangle Overlap

"""
an axis-aligned rectangle is represented as a list '[x1, y1, x2, y2]' where
'(x1, y1)' is the coordinate of its bottom left corner, and '(x2, y2)' is the
coordinate of its top right corner. its top and bottom edges are parallel to
the x-axis and its left and right edges are paralled to the y-axis. two
rectangles overlap if the area of their intersection is positive. given two
axis-aligned rectangles, return true if they overlap, otherwise return false.
"""


class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        return (
            rec1[0] < rec2[2]
            and rec2[0] < rec1[2]
            and rec1[1] < rec2[3]
            and rec2[1] < rec1[3]
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.isRectangleOverlap(rec1=[0, 0, 2, 2], rec2=[1, 1, 3, 3]))
    print(obj.isRectangleOverlap(rec1=[0, 0, 1, 1], rec2=[1, 0, 2, 1]))
    print(obj.isRectangleOverlap(rec1=[0, 0, 1, 1], rec2=[2, 2, 3, 3]))
