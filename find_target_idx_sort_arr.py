# 2089. Find Target Indices After Sorting Array

"""
you are given a 0-indexed integer array 'nums' and a target element 'target'.
a target index is an index 'i' such that 'nums[i] == target'. return a list
of target indices of 'nums' after sorting 'nums' in non-decreasing order.
"""


class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        less, equal = 0, 0
        for i in nums:
            if i < target:
                less += 1
            elif i == target:
                equal += 1
        return list(range(less, less + equal))


if __name__ == "__main__":
    obj = Solution()
    print(obj.targetIndices(nums=[1, 2, 5, 2, 3], target=2))
    print(obj.targetIndices(nums=[1, 2, 5, 2, 3], target=3))
    print(obj.targetIndices(nums=[1, 2, 5, 2, 3], target=5))
