# 3727. Maximum Alternating Sum of Squares

"""
you are given an integer array 'nums'. you may rearrange the elements in any
order. return an integer denoting the maximum possible alternating score of
'nums' after rearranging its elements.
"""


class Solution:
    def maxAlternatingSum(self, nums: list[int]) -> int:
        n = len(nums)
        squares = sorted([i * i for i in nums])
        small_sum = sum(squares[: n // 2])
        large_sum = sum(squares[n // 2 :])
        return large_sum - small_sum


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxAlternatingSum(nums=[1, 2, 3]))
    print(obj.maxAlternatingSum(nums=[1, -1, 2, -2, 3, -3]))
