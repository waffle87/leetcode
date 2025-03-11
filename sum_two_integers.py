# 371. Sum of Two Integers

"""
given two integers 'a' and 'b', return the sum of the two integers without
using the operators '+' and '-'.
"""


class Solution(object):
    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        ab = [a, b]
        return sum(ab)


if __name__ == "__main__":
    obj = Solution()
    print(obj.getSum(a=1, b=2))
    print(obj.getSum(a=2, b=3))
