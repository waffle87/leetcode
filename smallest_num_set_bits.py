# 3370. Smallest Number With All Set Bits

"""
you are given a positive number 'n'. return the smallest number 'x' greater
than or equal to 'n' such that the binary represeentation of 'x' contains
only set bits.
"""


class Solution(object):
    def smallestNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        return (1 << n.bit_length()) - 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.smallestNumber(n=5))
    print(obj.smallestNumber(n=10))
