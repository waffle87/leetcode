# 762. Prime Number of Set Bits in Binary Representation

"""
given two integers 'left' and 'right', return the count of numbers in the
inclusive range '[left, right]' having a prime number of set bits in their
binary representation. recall that the number of set bits an integer has is
the number of 1's present when written in binary.
"""


class Solution(object):
    def countPrimeSetBits(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: int
        """
        return sum(665772 >> bin(i).count("1") & 1 for i in range(left, right + 1))


if __name__ == "__main__":
    obj = Solution()
    print(obj.countPrimeSetBits(left=6, right=10))
    print(obj.countPrimeSetBits(left=10, right=15))
