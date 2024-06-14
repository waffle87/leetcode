# 343. Integer Break

"""
given an integer 'n', break it into the sum of 'k' positive integers, where
'k >= 2' and maximise the product of those integers. return the maximum
product you can get
"""


class Solution(object):
    def integerBreak(self, n):
        case = [0, 0, 1, 2, 4, 6, 9]
        if n < 7:
            return case[n]
        dp = case + [0] * (n - 6)
        for i in range(7, n + 1):
            dp[i] = 3 * dp[i - 3]
        return dp[-1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.integerBreak(2))  # expect: 1
    print(obj.integerBreak(10))  # expect: 36
