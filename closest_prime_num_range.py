# 2523. Closest Prime Numbers in Range

"""
given two positive integers 'left' and 'right', find the two integers 'num1'
and 'num2' such that 'left <= num1 < num2 <= right', both 'num1' and 'num2'
are prime numbers, and 'num2 - num1' is the minimum amongst all other pairs
satisfying the above conditions. return the positive integer array 'ans =
[nums1, nums2]'. if there are multiple pairs satisfying these conditions,
return the one with the smallest 'num1' value. if no such numbers exist,
return '[-1, -1]'.
"""


class Solution(object):
    def closestPrimes(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        sieve = [True] * (right + 1)
        sieve[0] = sieve[1] = False
        for i in range(2, int(right**0.5) + 1):
            if sieve[i]:
                for j in range(i * i, right + 1, i):
                    sieve[j] = False
        primes = [i for i in range(left, right + 1) if sieve[i]]
        if len(primes) < 2:
            return [-1, -1]
        min = float("inf")
        ans = [-1, -1]
        for i in range(1, len(primes)):
            gap = primes[i] - primes[i - 1]
            if gap < min:
                min = gap
                ans = [primes[i - 1], primes[i]]
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.closestPrimes(left=10, right=19))
    print(obj.closestPrimes(left=4, right=6))
