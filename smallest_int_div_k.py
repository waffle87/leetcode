# 1015. Smallest Integer Divisible by K

"""
given a positive integer 'k', you need to find the length of the smallest
positive intger 'n' such that 'n' is divisible by 'k' and 'n' only contains
the digit 1. return the length of 'n'. if there is no such 'n', return -1.
note 'n' may not fit in a 64-bit signed integer.
"""


class Solution(object):
    def smallestRepunitDivByK(self, k):
        """
        :type k: int
        :rtype: int
        """
        if k % 2 == 0 or k % 5 == 0:
            return -1
        i = 0
        for j in range(1, k + 1):
            i = (i * 10 + 1) % k
            if not i:
                return j


if __name__ == "__main__":
    obj = Solution()
    print(obj.smallestRepunitDivByK(k=1))
    print(obj.smallestRepunitDivByK(k=2))
    print(obj.smallestRepunitDivByK(k=3))
