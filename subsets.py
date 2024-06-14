# 78. Subsets

"""
given an integer array 'nums' of unique elements return all possible subsets
(the power set). the solution set must not contain duplicate subsets. return
the solution in any order.
"""


class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ans = []
        nums.sort()
        for i in range(1 << len(nums)):
            tmp = []
            for j in range(len(nums)):
                if i & 1 << j:
                    tmp.append(nums[j])
            ans.append(tmp)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.subsets(nums=[1, 2, 3]))
    print(obj.subsets(nums=[0]))
