# 2913. Subarrays Distinct Element Sum of Squares 1

"""
you are given a 0-indexed integer array 'nums'. the distinct count of a
subarray of 'nums' is defined as: let 'nums[i .. j]' be a subarray of 'nums'
consisting of all the indices fom 'i' to 'j' such that '0 <= i <= j <
nums.length'. then the number of distinct values in 'nums[i .. j]' is called
the distinct count of 'nums[i .. j]'. return the sum of the squares of
distinct counts of all subarrays of 'nums'.
"""


class Solution:
    def sumCounts(self, nums: list[int]) -> int:
        ans, n = [], len(nums)
        for i in range(n):
            for j in range(i, n + 1):
                ans.append(len(set(nums[i:j])) ** 2)
        return sum(ans)


if __name__ == "__main__":
    obj = Solution()
    print(obj.sumCounts(nums=[1, 2, 1]))
    print(obj.sumCounts(nums=[1, 1]))
