# 2874. Maximum Value of an Ordered Triplet II

"""
you are given a 0-indexed integer array 'nums'. return the maximum value over
all triplets of indices '(i, j, k)' such that 'i < j < k'. if all such
triplets have a negative value, return 0. the value of a triplet of indices
'(i, j, k)' is equal to '(nums[i] - nums[j])  nums[k]'
"""


class Solution(object):
    def maximumTripletValue(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n < 3:
            return 0
        ans, curr, diff = 0, nums[0], 0
        for i in range(1, n):
            ans = max(ans, diff * nums[i])
            diff = max(diff, curr - nums[i])
            curr = max(curr, nums[i])
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumTripletValue(nums=[12, 6, 1, 2, 7]))
    print(obj.maximumTripletValue(nums=[1, 10, 3, 4, 19]))
    print(obj.maximumTripletValue(nums=[1, 2, 3]))
