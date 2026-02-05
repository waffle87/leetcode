# 3379. Transformed Array

"""
you are given an integer array 'nms' that represents a circular array. your
task is to create a new array 'res' of the same size, following these rules.
for each index 'i', perform the following independent actions. if 'nums[i] >
0' start at index 'i' and move 'nums[i]' steps to the right in the circular
array. set 'ans[i]' to the value of the index where you land. if 'nums[i] <
0', start at index 'i' and move 'abs(nums[i])' steps to the left in the
circular array. set 'ans[i]' to the value of the index where you land. return
new array 'ans'.
"""


class Solution(object):
    def constructTransformedArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        ans = [0] * n
        for i, j in enumerate(nums):
            ans[i] = nums[(i + j) % n]
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.constructTransformedArray(nums=[3, -2, 1, 1]))
    print(obj.constructTransformedArray(nums=[-1, 4, -1]))
