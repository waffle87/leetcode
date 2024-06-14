# 1611. Minimum One Bit Operations to Make Integers Zero

"""
given an integer 'n', you must transform it into '0' using the following
operations: change the rightmost (LSB) bit in the binary representation of
'n', or change the i'th bit in the binary representation of 'n' if the '(i -
1)'th bit is set to 1 and the '(i - 2)'th through the 0th bits are set to 0.
return the minimum number of operations to transform 'n' into '0'.
"""


class Solution(object):
    def minimumOneBitOperations(self, n):
        """
        :type n: int
        :rtype: int
        """
        cnt = 0
        while n:
            cnt = -cnt - (n ^ (n - 1))
            n &= n - 1
        return abs(cnt)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumOneBitOperations(3))  # expect: 2
    print(obj.minimumOneBitOperations(6))  # expect: 4
