# 593. Valid Square

"""
given the coordinates of four points in a 2d space 'p1 .. p4', return true if
the four points oncstruct a square. the coordinate of a point 'p_i' is
represented as '[x_i, y_i]'. the input is not given in any order. a valid
square has four equal sides with positive length and four equal angles
(90-degree angles)
"""


class Solution(object):
    def validSquare(self, p1, p2, p3, p4):
        """
        :type p1: List[int]
        :type p2: List[int]
        :type p3: List[int]
        :type p4: List[int]
        :rtype: bool
        """

        def dist(p, q):
            return (p[0] - q[0]) ** 2 + (p[1] - q[1]) ** 2

        def check(p1, p2, p3, p4):
            if p1[0] + p2[0] != p3[0] + p4[0] or p1[1] + p2[1] != p3[1] + p4[1]:
                return False
            if dist(p1, p2) != dist(p3, p4) or dist(p1, p4) != dist(p2, p4):
                return False
            if p1 == p2:
                return False
            return True

        return check(p1, p2, p3, p4) or check(p1, p3, p2, p4) or check(p1, p4, p2, p3)


if __name__ == "__main__":
    obj = Solution()
    print(obj.validSquare(p1=[0, 0], p2=[1, 1], p3=[1, 0], p4=[0, 1]))
    print(obj.validSquare(p1=[0, 0], p2=[1, 1], p3=[1, 0], p4=[0, 12]))
    print(obj.validSquare(p1=[1, 0], p2=[-1, 0], p3=[0, 1], p4=[0, -1]))
