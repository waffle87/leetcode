# 1922. Count Good Numbers

"""
a digit string is good if the digits (0-indexed) at even indices are even and
the digits at odd indices are prime (2,3,5,or 7). for example 2582 is good
because the digits 2 and 8 at even positions are even and the digits 5 and 2
at odd positions are prime. however, 3245 is not good because 3 is at an even
index, but is not even. given an integer 'n', return the total number of good
digit strings of length 'n'. since the answer may be large, return it modulo
1e9+7. a digit string is a string consisting of digits 0 through 9 that may
contain leading zeros.
"""


class Solution(object):
    mod = 10**9 + 7

    def mod_exp(self, n, e):
        res = 1
        n %= self.mod
        while e > 0:
            if e % 2 == 1:
                res = (res * n) % self.mod
            n = (n * n) % self.mod
            e //= 2
        return res

    def countGoodNumbers(self, n):
        """
        :type n: int
        :rtype: int
        """
        a = self.mod_exp(5, (n + 1) // 2)
        b = self.mod_exp(4, n // 2)
        return (a * b) % self.mod


if __name__ == "__main__":
    obj = Solution()
    print(obj.countGoodNumbers(1))
    print(obj.countGoodNumbers(4))
    print(obj.countGoodNumbers(50))
