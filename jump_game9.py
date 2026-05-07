# 3660. Jump Game IX
from typing import List

"""
you are given an integer array 'nums'. from any index 'i', you can jump to
another index 'j' under the following rules: jump to index 'j' where 'j > i'
is allowed only if 'nums[j] < nums[i]', and vice versa. for each index 'i',
find the maximum value in 'nums' that can be reached by following any
sequence of valid jumps starting at 'i'. return an array 'ans' where 'ans[i]'
is the maximum value reachable starting from index 'i'.
"""


class Solution:
    def maxValue(self, nums: List[int]) -> List[int]:
        n = len(nums)
        if n == 0:
            return []
        prefix = [0] * n
        suffix = [0] * n
        ans = [0] * n
        prefix[0] = nums[0]
        for i in range(1, n):
            prefix[i] = max(nums[i], prefix[i - 1])
        suffix[n - 1] = nums[n - 1]
        for i in range(n - 2, -1, -1):
            suffix[i] = min(nums[i], suffix[i + 1])
        ans[n - 1] = prefix[n - 1]
        for i in range(n - 2, -1, -1):
            ans[i] = prefix[i]
            if prefix[i] > suffix[i + 1]:
                ans[i] = ans[i + 1]
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxValue(nums=[2, 1, 3]))
    print(obj.maxValue(nums=[2, 3, 1]))
