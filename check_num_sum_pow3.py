# 1780. Check if Number is a Sum of Powers of Three

"""
given an integer 'n', return true if it is possible to represent 'n' as the
sum of distinct powers of three. otherwise, return false. an integer 'y' is a
power of three if there exists an integer 'x' such that 'y == 3^x'
"""


class Solution(object):
    def checkPowersOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        pow3 = [3**i for i in reversed(range(15))]
        for i in pow3:
            if n >= 2 * i:
                return False
            elif n >= i:
                n -= i
        return True


if __name__ == "__main__":
    obj = Solution()
    print(obj.checkPowersOfThree(12))
    print(obj.checkPowersOfThree(91))
    print(obj.checkPowersOfThree(21))
