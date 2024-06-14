# 204. Count Primes

"""
given an integer 'n', return the number of prime numbers that are strictly
less than 'n'.
"""


class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 3:
            return 0
        primes = [True] * n
        primes[0] = primes[1] = False
        for i in range(2, int(n**0.5) + 1):
            if primes[i]:
                primes[i * i : n : i] = [False] * len(primes[i * i : n : i])
        return sum(primes)


if __name__ == "__main__":
    obj = Solution()
    print(obj.countPrimes(10))
    print(obj.countPrimes(1))
    print(obj.countPrimes(0))
