# 3411. Maximum Subarray With Equal Products

from math import gcd


class Solution:
    def maxLength(self, nums: list[int]) -> int:
        best, left, prod = 2, 0, 1
        for right, x in enumerate(nums):
            while gcd(prod, x) > 1:
                prod //= nums[left]
                left += 1
            prod *= x
            best = max(best, right - left + 1)
        return best


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxLength(nums=[1, 2, 1, 2, 1, 1, 1]))
    print(obj.maxLength(nums=[2, 3, 4, 5, 6]))
    print(obj.maxLength(nums=[1, 2, 3, 1, 4, 5, 1]))
