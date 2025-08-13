# 326. Power of Three

"""
given an integer 'n', return true if it is a power of three. otherwise,
return false. an integer 'n' is a power of three, if there exists an integer
'x' such that 'n == 3^x'
"""


class Solution(object):
    def isPowerOfThree(self, n):
        """
        the positive divisors of 3^19 are exactly the powers of 3
        from 3^0 to 3^19. that's all powers of 3 in the possible range
        here (signed 32-bit integer). so check whether the number is
        positive and whether it divides 3^19
        """
        return n > 0 == 3**19 % n


if __name__ == "__main__":
    obj = Solution()
    print(obj.isPowerOfThree(27))
    print(obj.isPowerOfThree(0))
    print(obj.isPowerOfThree(-1))
