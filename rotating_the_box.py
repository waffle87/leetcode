# 1861. Rotating the Box

"""
you are given an 'm x n' matrix of characters 'box' representing a side-view
of a box. each cell of the box is one of the following: a stone '#', a
stationary obstacle '', or empty '.'. the box is rotated 90 degrees
clockwise, causing some of the stones to fall due to gravity. each stone
falls down until it lands on an obstacle, another stone, or the bottom of the
box. gravity does not affect the obstacles' positions and the inertia from
the box's rotation does not affect the stones' horizontal positions. return
an 'm x n' matrix representing the box after the rotation.
"""


class Solution(object):
    def rotateTheBox(self, box):
        """
        :type box: List[List[str]]
        :rtype: List[List[str]]
        """
        for row in box:
            mov_pos = len(row) - 1
            for j in range(len(row) - 1, -1, -1):
                if row[j] == "*":
                    mov_pos = j - 1
                elif row[j] == "#":
                    row[mov_pos], row[j] = row[j], row[mov_pos]
                    mov_pos -= 1
        return zip(*box[::-1])


if __name__ == "__main__":
    obj = Solution()
    print(obj.rotateTheBox(box=[["#", ".", "#"]]))
    print(obj.rotateTheBox(box=[["#", ".", "*", "."], ["#", "#", "*", "."]]))
    print(
        obj.rotateTheBox(
            box=[
                ["#", "#", "*", ".", "*", "."],
                ["#", "#", "#", "*", ".", "."],
                ["#", "#", "#", ".", "#", "."],
            ]
        )
    )
