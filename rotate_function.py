# 396. Rotate Function
from typing import List

"""
you are given an integer array 'nums' of length 'n'. assume 'arr_k' to be an
array obtained by rotating 'nums' by 'k' positions clockwise. we define the
rotation function 'F' on 'nums' as follows: 'F(k) = 0  arr_k[0] + 1
arr_k[1] + ... + (n - 1)  arr_k[n - 1]'. return the maximum value of 'F(0),
F(1), ..., F(n - 1)'. the test cases are generated such that the answer fits
in a 32-bit integer.
"""


class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        f, n, total = 0, len(nums), sum(nums)
        for i, j in enumerate(nums):
            f += i * j
        ans = f
        for i in range(n - 1, 0, -1):
            f += total - n * nums[i]
            ans = max(ans, f)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxRotateFunction(nums=[4, 3, 2, 6]))
    print(obj.maxRotateFunction(nums=[100]))
