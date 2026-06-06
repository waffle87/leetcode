# 2574. Left and Right Sum Differences

"""
you are given a 0-indexed integer array 'nums' of size 'n'. define two arrays
'leftSum' and 'rightSum' where 'leftSum[i]' is the sum of elements to the
left of index 'i' in the array 'nums'. if there is no such element,
'leftSum[i] = 0'. and vice-versa for 'rightSum'. return an integer array
'answer' of size 'n' where 'answer[i] = |leftSum[i] - rightSum[i]|'.
"""


class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        n = len(nums)
        left_sum = [0] * n
        right_sum = [0] * n
        ans = [0] * n
        for i in range(1, n):
            left_sum[i] = left_sum[i - 1] + nums[i - 1]
        for j in range(n - 2, -1, -1):
            right_sum[j] = right_sum[j + 1] + nums[j + 1]
        for k in range(n):
            ans[k] = abs(left_sum[k] - right_sum[k])
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.leftRightDifference(nums=[10, 4, 8, 3]))
    print(obj.leftRightDifference(nums=[1]))
