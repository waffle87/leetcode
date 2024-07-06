# 2582. Pass the Pillow

"""
there are 'n' people standing in a line labeled from 1 to 'n'. the first
person in the line is holding a pillow initially. every second, the person
holding the pillow passe it to the next person standing in the line. once the
pillow reaching the end of the line, the direction changes and people
continue passing the pillow in the opposite direction. given the two positive
integers 'n' and 'time', return the index of the peson holding the pillow
after 'time' seconds.
"""


class Solution(object):
    def passThePillow(self, n, time):
        """
        :type n: int
        :type time: int
        :rtype: int
        """
        return n - abs(n - 1 - time % (n * 2 - 2))


if __name__ == "__main__":
    obj = Solution()
    print(obj.passThePillow(4, 5))
    print(obj.passThePillow(3, 2))
