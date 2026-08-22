# 3622. Check Divisibility by Digit Sum and Product

"""
you are given a positive integer 'n'. determine whether 'n' is divisible by
the sum of the following two values: the digit sum of 'n' (the sum of its
digits), or the digit product of 'n' (the product of its digits). return true
if 'n' is divisible by this sum, otherwise return false.
"""

from math import prod


class Solution:
    def checkDivisibility(self, n: int) -> bool:
        return n % (sum(i := [*map(int, str(n))]) + prod(i)) == 0


if __name__ == "__main__":
    obj = Solution()
    print(obj.checkDivisibility(n=99))
    print(obj.checkDivisibility(n=23))
