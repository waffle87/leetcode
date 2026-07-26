# 628. Maximum Product of Three Numbers

"""
given an integer array 'nums', find three numbers whose product is maximum
and return the maximum product
"""


class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(2):
            k = i
            for j in range(i + 1, n):
                if nums[j] < nums[k]:
                    k = j
            nums[i], nums[k] = nums[k], nums[i]
        for i in range(n - 1, max(-1, n - 4), -1):
            k = i
            for j in range(i):
                if nums[j] > nums[k]:
                    k = j
            nums[i], nums[k] = nums[k], nums[i]
        return max(nums[-1] * nums[-2] * nums[-3], nums[-1] * nums[0] * nums[1])


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumProduct(nums=[1, 2, 3]))
    print(obj.maximumProduct(nums=[1, 2, 3, 4]))
    print(obj.maximumProduct(nums=[-1, -2, -3]))
