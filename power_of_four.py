# 342. Power of Four

"""
given an integer 'n', return 'true' if it is a power of four, otherwise,
return 'false'. an integer 'n' is a power of four if there exists an integer
'x' such that 'n == 4^x'
"""


class Solution(object):
    def isPowerOfFour(self, n):
        return n > 0 and n.bit_count() == 1 and (n - 1) % 3 == 0


if __name__ == "__main__":
    obj = Solution()
    print(obj.isPowerOfFour(16))  # expect: True
    print(obj.isPowerOfFour(5))  # expect: False
    print(obj.isPowerOfFour(1))  # expect: True
