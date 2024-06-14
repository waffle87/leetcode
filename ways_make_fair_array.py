# 1664. Ways to Make a Fair Array

"""
you are given an integer array 'nums'. you can choose exactly one index and
remove the element. notice that the index of the elements may change after
the removal. for example, if 'nums = [6,1,7,4,1]' choosing to remove index 1
results in 'nums = [6,7,4,1]'. an array is fair is the sum of the odd indexed
values equals the sume of the even indexed values. return the number of
indices that you could choose such that after the removal, 'nums' is fair.
"""


class Solution(object):
    def waysToMakeFair(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        s1, s2 = [0, 0], [sum(nums[0::2]), sum(nums[1::2])]
        ans = 0
        for i, j in enumerate(nums):
            s2[i % 2] -= j
            ans += s1[0] + s2[1] == s1[1] + s2[0]
            s1[i % 2] += j
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.waysToMakeFair(nums=[2, 1, 6, 4]))
    print(obj.waysToMakeFair(nums=[1, 1, 1]))
    print(obj.waysToMakeFair(nums=[1, 2, 3]))
