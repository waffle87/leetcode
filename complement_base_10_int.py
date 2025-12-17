# 1009. Complement of Base 10 Integer

"""
the complement of an integer is the integer you get when you flip all the 0's
to 1's and all the 1's to 0's in its binary representation. given an integer
'n', return its complement.
"""


class Solution(object):
    def bitwiseComplement(self, n):
        """
        :type n: int
        :rtype: int
        """
        c = 1
        while n > c:
            c = c * 2 + 1
        return c - n


if __name__ == "__main__":
    obj = Solution()
    print(obj.bitwiseComplement(n=5))
    print(obj.bitwiseComplement(n=7))
    print(obj.bitwiseComplement(n=10))
