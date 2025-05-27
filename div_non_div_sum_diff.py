# 2894. Divisible and Non-divisible Sums Difference

"""
you are given a positive integers 'n' and 'm'. define two integers as
follows: 'num1': the sum of all integers in the range '[1, n]' that are not
divisible by 'm'. 'num2': the sum of all integers in the range '[1, n]' that
are divisible by 'm'. return the integer 'num1 - num2'
"""


class Solution(object):
    def differenceOfSums(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        return (1 + n) * n // 2 - (1 + n // m) * (n // m) * m


if __name__ == "__main__":
    obj = Solution()
    print(obj.differenceOfSums(n=10, m=3))
    print(obj.differenceOfSums(n=5, m=6))
    print(obj.differenceOfSums(n=5, m=1))
