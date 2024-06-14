# 368. Largest Divisible Subset

"""
given a set of distinct positive integers 'nums', return the largest subset
'answer' such that every pair '(ans[i], ans[j])' of elements in this subset
satifies 'ans[i] % ans[j] == 0' or 'ans[j] % ans[i] == 0'. if there are
multiple solutions, return any of them.
"""


class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if len(nums) == 0:
            return []
        nums.sort()
        ans = [[i] for i in nums]
        for i in range(len(nums)):
            for j in range(i):
                if nums[i] % nums[j] == 0 and len(ans[i]) < len(ans[j]) + 1:
                    ans[i] = ans[j] + [nums[i]]
        return max(ans, key=len)


if __name__ == "__main__":
    obj = Solution()
    print(obj.largestDivisibleSubset([1, 2, 3]))
    print(obj.largestDivisibleSubset([1, 2, 4, 8]))
