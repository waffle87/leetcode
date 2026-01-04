# 1390. Four Divisors

"""
given an integer array 'nums', return the sum of divisors of the integers in
that array that have exactly four divisors. if there is no such integer in
the array, return 0.
"""


class Solution(object):
    def sum_one(self, n):
        p = round(n ** (1 / 3))
        if p**3 == n and self.prime(p):
            return 1 + p + p * p + p * p * p
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0:
                a, b = i, n // i
                if a != b and self.prime(a) and self.prime(b):
                    return 1 + a + b + n
                return -1
        return -1

    def prime(self, n):
        if n < 2:
            return False
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0:
                return False
        return True

    def sumFourDivisors(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 0
        for i in nums:
            val = self.sum_one(i)
            if val != -1:
                ans += val
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.sumFourDivisors(nums=[21, 4, 7]))
    print(obj.sumFourDivisors(nums=[21, 21]))
    print(obj.sumFourDivisors(nums=[1, 2, 3, 4, 5]))
