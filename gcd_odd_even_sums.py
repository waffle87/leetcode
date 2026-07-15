# 3658. GCD of Odd and Even Sums

"""
you are given an integer 'n'. your task is to compute the gcd of two values:
'sumodd': the sum of the smallest 'n' positive odd numbers, and 'sumeven':
the sum of the smallest 'n' positive even numbers. return the gcd of 'sumodd'
and 'sumeven'
"""


class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        return n


if __name__ == "__main__":
    obj = Solution()
    print(obj.gcdOfOddEvenSums(n=4))
    print(obj.gcdOfOddEvenSums(n=5))
