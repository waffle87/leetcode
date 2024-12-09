# 3152. Special Array II

"""
an array is considered special if every pair of its adjacent elements
contains two numbers with different parity. you are given an array of integer
'nums' and a 2d integer array 'matrix' 'queries', where for 'queries[i] =
[from_i, to_i]' your task is to check that subarray 'nums[from_i .. to_i]' is
special or not. return array of booleans 'answer' such that 'answer[i]' is
true if 'nums[from_i .. to_i]' is special
"""


class Solution(object):
    def isArraySpecial(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: List[bool]
        """
        pre, ans = [1], []
        for i in range(1, len(nums)):
            if nums[i] % 2 == nums[i - 1] % 2:
                pre.append(pre[-1])
            else:
                pre.append(pre[-1] + 1)
        for s, e in queries:
            if pre[e] - pre[s] == e - s:
                ans.append(True)
            else:
                ans.append(False)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.isArraySpecial(nums=[3, 4, 1, 2, 6], queries=[[0, 4]]))
    print(obj.isArraySpecial(nums=[4, 3, 1, 6], queries=[[0, 2], [2, 3]]))
