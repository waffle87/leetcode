# 313. Super Ugly Number

"""
a super ugly number is a positive integer whose prime factors are in the
array 'primes'. given an integer 'n' and an array of integers 'primes',
return the n'th super ugly number. the n'th super ugly number is guaranteed
to fit in a 32-bit integer (signed)
"""


class Solution(object):
    def nthSuperUglyNumber(self, n, primes):
        size = len(primes)
        ugly, dp, idx, nums = 1, [1], [0] * size, [1]
        for i in range(1, n):
            for j in range(0, size):
                if nums[j] == ugly:
                    nums[j] = dp[idx[j]] * primes[j]
                    idx[j] += 1
            ugly = min(nums)
            dp.append(ugly)
        return dp[-1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.nthSuperUglyNumber(n=12, primes=[2, 7, 13, 19]))  # expect: 32
    print(obj.nthSuperUglyNumber(n=1, primes=[2, 3, 5]))  # expect: 1
