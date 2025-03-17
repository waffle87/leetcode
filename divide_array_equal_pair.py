# 2206. Divide Array Into Equal Pairs

"""
you are given an integer array 'nums' consisting of '2  n' integers. you
need to divide 'nums' into 'n' pairs such that: each element belongs to
exactly one pair, and the elements present in a pair are equal. return true
if 'nums' can be divided into 'n' pairs, otherwise return false.
"""


class Solution(object):
    def divideArray(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        vis = set()
        for i in nums:
            vis ^= {i}
        return not vis


if __name__ == "__main__":
    obj = Solution()
    print(obj.divideArray(nums=[3, 2, 3, 2, 2, 2]))
    print(obj.divideArray(nums=[1, 2, 3, 4]))
