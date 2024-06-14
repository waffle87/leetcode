# 1770. Maximum Score from Performing Multiplication Operations

"""
given two 0 indexed integer arrays 'nums' and multipliers of size n and m
respectively, where n >= m. you begin with a score of 0. you want to perform
exactly m operations. on the i'th operation, you will choose one integer x
from either the start or the end of the array 'nums'. add 'multipliers[i] 
x' to your score. note that 'multipliers[0]' correspons to the first
operation, 'multipliers[1]' to the second operation and so on. return the
maximum score after performing m operations.
"""


class Solution(object):
    def maximumScore(self, nums, multipliers):
        """
        :type nums: List[int]
        :type multipliers: List[int]
        :rtype: int
        """
        n, m = len(nums), len(multipliers)
        dp = [[0] * (m + 1) for _ in range(m + 1)]
        for l in range(m - 1, -1, -1):
            for i in range(m - 1, -1, -1):
                r = n - (i - l) - 1
                if r < 0 or r >= n:
                    break
                leftPick = dp[l + 1][i + 1] + nums[l] * multipliers[i]
                rightPick = dp[l][i + 1] + nums[r] * multipliers[i]
                dp[l][i] = max(leftPick, rightPick)
        return dp[0][0]


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumScore(nums=[1, 2, 3], multipliers=[3, 2, 1]))
    print(obj.maximumScore(nums=[-5, -3, -3, -2, 7, 1], multipliers=[-10, -5, 3, 4, 6]))
