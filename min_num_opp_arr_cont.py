# 2009. Minimum Number of Operations to Make Array Continuous
from bisect import bisect

"""
you are given an integer array 'nums'. in one operation, you can replace any
element in 'nums' with any integer. 'nums' is considered continuous if both
of the following conditions are fulfilled:
- all elements in 'nums' are unique
- the difference between the maximum element and the minimum element in
'nums' equals 'nums.len - 1' return the minimum number of operations to make
'nums' continuous.
"""


class Solution(object):
    def minOperations(self, nums):
        n = len(nums)
        nums = sorted(set(nums))
        ans = n
        for i, start in enumerate(nums):
            end = start + n - 1
            idx = bisect_right(nums, end)
            unique_len = idx - i
            ans = min(ans, n - unique_len)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minOperations([4, 2, 5, 3]))  # expect: 0
    print(obj.minOperations([1, 2, 3, 5, 6]))  # expect: 1
    print(obj.minOperations([1, 10, 100, 1000]))  # expect: 3
