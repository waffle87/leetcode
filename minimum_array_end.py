# 3133. Minimum Array End

"""
you are given two integers 'n' and 'x'. you have to construct an array of
positive integers 'nums'. of size 'n' where for every '0 <= i < n - 1',
'nums[i + 1]' is greater than 'nums[i]', and the result of the bitwise and
operation between all elements of 'nums' is 'x'. return the minimum possible
value of 'nums[n - 1]'
"""


class Solution(object):
    def minEnd(self, n, x):
        """
        :type n: int
        :type x: int
        :rtype: int
        """
        n -= 1
        b = 1
        for i in range(64):
            if b & x == 0:
                x |= (n & 1) * b
                n >>= 1
            b <<= 1
        return x


if __name__ == "__main__":
    obj = Solution()
    print(obj.minEnd(3, 4))
    print(obj.minEnd(2, 7))
