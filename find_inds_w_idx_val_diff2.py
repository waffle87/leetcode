# 2905. Find Indices With Index and Value Difference II


"""
you are given a 0 indexed integer array 'nums' having length 'n', an integer
'indexDifference', and an integer 'valueDifference'. your task is to find two
indices 'i' and 'j', both in the range '[0, n - 1]' that satisfy the
following conditions: 'abs(i - j) >= indexDifference' and 'abs(nums[i] -
nums[j]) >= valueDifference'. return an integer array 'answer' where 'answer
= [i, j]' if there are two such indces, and 'answer = [-1, -1]' otherwise. if
there are multiple choices for the two indices, returnany of them.
"""


class Solution(object):
    def findIndices(self, nums, indexDifference, valueDifference):
        """
        :type nums: List[int]
        :type indexDifference: int
        :type valueDifference: int
        :rtype: List[int]
        """
        mini, maxi = 0, 0
        for i in range(indexDifference, len(nums)):
            if nums[i - indexDifference] < nums[mini]:
                mini = i - indexDifference
            if nums[i - indexDifference] > nums[maxi]:
                maxi = i - indexDifference
            if nums[i] - nums[mini] >= valueDifference:
                return [mini, i]
            if nums[maxi] - nums[i] >= valueDifference:
                return [maxi, i]
        return [-1, -1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.findIndices(nums=[5, 1, 4, 1], indexDifference=2, valueDifference=4))
    print(obj.findIndices(nums=[2, 1], indexDifference=0, valueDifference=0))
    print(obj.findIndices(nums=[1, 2, 3], indexDifference=2, valueDifference=4))
