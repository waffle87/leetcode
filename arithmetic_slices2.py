# 446. Arithmetic Slices II - Subsequence
from collections import defaultdict

"""
given an integer array 'nums', return the number of all the arithmetic
subsequences of 'nums'. a sequence of numbers is called arithmetic if it
consists of at least three elements and if the difference between any two
consecutive elements is the same. the test cases are generated such that the
answer fits in a 32-bit integer.
"""


class Solution(object):
    def numberOfArithmeticSlices(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        total_cnt = 0
        dp = [defaultdict(int) for _ in range(n)]
        for i in range(1, n):
            for j in range(i):
                diff = nums[i] - nums[j]
                dp[i][diff] += 1
                if diff in dp[j]:
                    dp[i][diff] += dp[j][diff]
                    total_cnt += dp[j][diff]
        return total_cnt


if __name__ == "__main__":
    obj = Solution()
    print(obj.numberOfArithmeticSlices(nums=[2, 4, 6, 8, 10]))  # expect: 7
    print(obj.numberOfArithmeticSlices(nums=[7, 7, 7, 7, 7]))  # expect: 16
