# 2016. Maximum Difference Between Increasing Elements

"""
given a 0-indexed integer array 'nums' of size 'n', find the maximum
difference between 'nums[i]' and 'nums[j]' (ie. 'nums[j] - nums[i]') such
that '0 <= i < j < n' and 'nums[i] < nums[j]'. return the maximum difference.
if no such 'i' and 'j' exist, return -1
"""


class Solution(object):
    def maximumDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        minn, ans = nums[0], -1
        for i in range(len(nums)):
            ans = max(ans, nums[i] - minn)
            minn = min(minn, nums[i])
        return ans if ans != 0 else -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumDifference(nums=[7, 1, 5, 4]))
    print(obj.maximumDifference(nums=[9, 4, 3, 2]))
    print(obj.maximumDifference(nums=[1, 5, 2, 10]))
