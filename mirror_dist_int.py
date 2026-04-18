# 3783. Mirror Distance of an Integer

"""
you are given an integer 'n'. define its mirror distance as 'abs(n -
reverse(n))' where 'reverse(n)' is the integer formed by reversing the digits
of 'n'. return an integer denoting the mirror distance of 'n'. 'abs(x)'
denotes the absolute value of 'x'.
"""


class Solution:
    def mirrorDistance(self, n: int) -> int:
        return abs(n - int(str(n)[::-1]))


if __name__ == "__main__":
    obj = Solution()
    print(obj.mirrorDistance(n=25))
    print(obj.mirrorDistance(n=10))
    print(obj.mirrorDistance(n=7))
