# 3394. Check if Grid can be Cut into Sections

"""
you are given an integer 'n' representing the dimensions of an 'n  n' grid
with the origin at the bottom-left corner of the grid. you are also given a
2d array of coordinates 'rectangles', where 'rectangles[i]' is in the form
'[start_x, start_y, end_x, end_y]' representing a rectangle on the grid. note
that the rectangles do not overlap. your task is to determine if it is
possible to make either two horizontal or two vertical cuts on the grid such
that each of the three resulting formed by the cuts contains at least one
rectangle. every rectangle belongs to exactly one section. return 'true' if
such cuts can be made. otherwise, return 'false'.
"""


class Solution(object):
    def checkValidCuts(self, n, rectangles):
        """
        :type n: int
        :type rectangles: List[List[int]]
        :rtype: bool
        """

        def check(rectangles):
            rectangles.sort()
            res, pre = 0, rectangles[0][1]
            for i, j in rectangles:
                res += pre <= i
                pre = max(pre, j)
            return res > 1

        return check([i[::2] for i in rectangles]) or check(
            [i[1::2] for i in rectangles]
        )


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.checkValidCuts(
            n=5, rectangles=[[1, 0, 5, 2], [0, 2, 2, 4], [3, 2, 5, 3], [0, 4, 4, 5]]
        )
    )
    print(
        obj.checkValidCuts(
            n=4, rectangles=[[0, 0, 1, 1], [2, 0, 3, 4], [0, 2, 2, 3], [3, 0, 4, 3]]
        )
    )
    print(
        obj.checkValidCuts(
            n=4,
            rectangles=[
                [0, 2, 2, 4],
                [1, 0, 3, 2],
                [2, 2, 3, 4],
                [3, 0, 4, 2],
                [3, 2, 4, 4],
            ],
        )
    )
