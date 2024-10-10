# 962. Maximum Width Ramp

"""
a ramp in an integer array 'nums' is a pair '(i, j)' for which 'i < j' and
'nums[i] <= nums[j]'. the width of such ramp is 'j - i'. given an integer
array 'nums', return the maximum width of a ramp in 'nums' if there is no
ramp in 'nums', return 0
"""


class Solution(object):
    def maxWidthRamp(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        stack, ans = [], 0
        for i, j in enumerate(nums):
            if not stack or nums[stack[-1]] > j:
                stack.append(i)
        for i in range(len(nums))[::-1]:
            while stack and nums[stack[-1]] <= nums[i]:
                ans = max(ans, i - stack.pop())
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxWidthRamp(nums=[6, 0, 8, 2, 1, 5]))
    print(obj.maxWidthRamp(nums=[9, 8, 1, 0, 1, 9, 4, 0, 4, 1]))
