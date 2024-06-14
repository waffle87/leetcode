# 456. 132 Pattern
import sys

"""
given an array of 'n' integers 'nums', a 132 pattern is a subsequence of
three integers 'nums[i], nums[j], nums[k]' such that 'i < j < k' and 'nums[i]
< nums[k] < nums[j]'. return true if there is a 132 pattern in 'nums', and
false otherwise
"""


class Solution(object):
    def find132pattern(self, nums):
        stack = []
        s3 = -sys.maxint
        for n in nums[::-1]:
            if n < s3:
                return True
            while stack and stack[-1] < n:
                s3 = stack.pop()
            stack.append(n)
        return False


if __name__ == "__main__":
    obj = Solution()
    print(obj.find132pattern([1, 2, 3, 4]))  # expect: False
    print(obj.find132pattern([3, 1, 4, 2]))  # expect: True
    print(obj.find132pattern([-1, 3, 2, 0]))  # expect: True
