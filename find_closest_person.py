# 3516. Find Closest Person

"""
you are given three integers represnting the positions of three people on a
number line. 'x' is the position of person 1, 'y' is the position of person
2, and 'z' is the position of persion 3 who does not move. both person 1 and
person 2 move toward person 3 at the same speed. determine which person will
reach person 3 first. return 1 if person 1 will arrive first, return 2 if
person 2 will arrive first, and 0 if both arrive at the same time.
"""


class Solution(object):
    def findClosest(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: int
        """
        a, b = abs(x - z), abs(y - z)
        return (a != b) << (a > b)


if __name__ == "__main__":
    obj = Solution()
    print(obj.findClosest(2, 7, 4))
    print(obj.findClosest(2, 5, 6))
    print(obj.findClosest(1, 5, 3))
