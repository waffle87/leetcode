# 1920. Build Array from Permutation

"""
given a 0-based permutation 'nums', build an array 'ans' of the same length
where 'ans[i] = nums[nums[i]]' for each '0 <= i < nums.len' and return it. a
0-based permutation 'nums' is an array of distinct integers from 0 to
'nums.len - 1'.
"""


class Solution(object):
    def buildArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        return [nums[i] for i in nums]


if __name__ == "__main__":
    obj = Solution()
    print(obj.buildArray(nums=[0, 2, 1, 5, 3, 4]))
    print(obj.buildArray(nums=[5, 0, 1, 2, 3, 4]))
