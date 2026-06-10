# 3689. Maximum Total Subarray Value I

"""
you are given an integer array 'nums' of length 'n' and an integer 'k'. you
need to choose exactly 'k' non-empty subarrays 'nums[l ... r]' of 'nums'.
subarrays may overlap, and the exact same subarray can be chosen more than
once. the value of a subarray 'nums[l ... r]' is defined as 'max(nums[l ...
r]) - min(nums[l ... r])'. the total value is the sum of the values of all
chosen subarrays. return the maximum possible total value you can achieve.
"""


class Solution:
    def maxTotalValue(self, nums: List[int], k: int) -> int:
        mn = mx = nums[0]
        for i in nums:
            mn = min(mn, i)
            mx = max(mx, i)
        return (mx - mn) * k


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxTotalValue(nums=[1, 3, 2], k=2))
    print(obj.maxTotalValue(nums=[4, 2, 5, 1], k=3))
