# 1808. Maximize Number of Nice Divisors

"""
you are given a positive integer 'prime_factors'. you are asked to construct
a positive integer 'n' that satisfies the following conditions.
- the number of prime factors of 'n' (not necessarily distinct) is at most
'prime_factors'
- the number of nice divisors of 'n' is maximised. note that a divisor of 'n'
nice if it is divisible by every prime factor of 'n'. for example if 'n =
12', then its prime factors are '[2,2,3]', then '6' and '12' are nice
divisors, while '3' and '4' are not. return the number of nice divisors of
'n'. since that number can be too large, return it modulo 10e9+7. note that a
prime number is a natural number greater than 1 that is not a product of two
smaller natural numbers. the prime factors of a number 'n' is a list of prime
numbers such that their product equals 'n'
"""


class Solution(object):
    def maxNiceDivisors(self, n):
        m = 10*9 + 7
        if n <= 3:
            return n
        if n % 3 == 0:
            return pow(3, n // 3, m)
        if n % 3 == 1:
            return (pow(3, (n - 4) // 3, m) * 4) % m
        return (2 * pow(3, n // 3)) % m


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxNiceDivisors(5))  # expect: 6
    print(obj.maxNiceDivisors(8))  # expect: 18
