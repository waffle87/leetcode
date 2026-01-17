# 3047. Find the Largest Area of Square Inside Two Rectangles

"""
there exists 'n' rectangles in a 2d plane with edges parallel to the x and y
axis. you are given two 2d integer arrays 'bottomLeft' and 'topRight' where
'bottomLeft[i] = [ai, bi]' and 'topRight[i] = [ci, di]' represent the bottom
left and top right coordinates of the i'th rectangle respectively. you need
to find the maximum area of a square that can fit inside the intersection
region of at least two rectangles. return 0 if such a square does not exist.
"""


class Solution(object):
    def largestSquareArea(self, bottomLeft, topRight):
        """
        :type bottomLeft: List[List[int]]
        :type topRight: List[List[int]]
        :rtype: int
        """
        coordinates = sorted(zip(bottomLeft, topRight))
        max_side = 0
        for i in range(len(coordinates)):
            for j in range(i + 1, len(coordinates)):
                ax1, ay1 = coordinates[i][0]
                ax2, ay2 = coordinates[i][1]
                bx1, by1 = coordinates[j][0]
                bx2, by2 = coordinates[j][1]
                overlap_x = min(ax2, bx2) - max(ax1, bx1)
                overlap_y = min(ay2, by2) - max(ay1, by1)
                if overlap_x > 0 and overlap_y > 0:
                    max_side = max(max_side, min(overlap_x, overlap_y))
        return max_side * max_side


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.largestSquareArea(
            bottomLeft=[[1, 1], [2, 2], [3, 1]], topRight=[[3, 3], [4, 4], [6, 6]]
        )
    )
    print(
        obj.largestSquareArea(
            bottomLeft=[[1, 1], [1, 3], [1, 5]], topRight=[[5, 5], [5, 7], [5, 9]]
        )
    )
    print(
        obj.largestSquareArea(
            bottomLeft=[[1, 1], [2, 2], [1, 2]], topRight=[[3, 3], [4, 4], [3, 4]]
        )
    )
    print(
        obj.largestSquareArea(
            bottomLeft=[[1, 1], [3, 3], [3, 1]], topRight=[[2, 2], [4, 4], [4, 2]]
        )
    )
