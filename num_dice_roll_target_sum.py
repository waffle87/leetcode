# 1155. Number of Dice Rolls With Target Sum

"""
you have 'n' dice and die has 'k' faces numbered 1 to 'k'. given three
integers 'n', 'k', and 'target', return the number of possible ways to roll
the dice so the sum of the face up numbers equals 'target'. since the answer
may be too large, return it modulo 10e9+7
"""


class Solution(object):
    def numRollsToTarget(self, n, k, target):
        """
        :type n: int
        :type k: int
        :type target: int
        :rtype: int
        """
        mod = 10**9 + 7
        prev = [0] * (target + 1)
        curr = [0] * (target + 1)
        for i in range(1, n + 1):
            for j in range(1, target + 1):
                ans = 0
                for x in range(1, k + 1):
                    if j - x >= 0:
                        ans += prev[j - x] % mod
                curr[j] = ans
            prev = curr[:]
        return int(prev[target] % mod)


if __name__ == "__main__":
    obj = Solution()
    print(obj.numRollsToTarget(1, 6, 3))
    print(obj.numRollsToTarget(2, 6, 7))
    print(obj.numRollsToTarget(30, 30, 500))
