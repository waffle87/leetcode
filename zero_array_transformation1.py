# 3355. Zero Array Transformation I

"""
you are given an integer array 'nums' of length 'n' and a 2d array 'queries'
where 'queries[i] = [li, ri]'. for each 'queries[i]' select a subset of
indices within the range '[li, ri]' in 'nums' and decrement the values at the
selected indices by 1. a zero array is an array where all elements are equal
to 0. return true if it is possible to transform 'nums' into a zero array
after processing all the queries sequentially, otherwise return false.
"""


class Solution(object):
    def isZeroArray(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: bool
        """
        n = len(nums)
        freq = [0] * (n + 1)
        for l, r in queries:
            freq[l] += 1
            freq[r + 1] -= 1
        cnt = 0
        for i, j in enumerate(nums):
            cnt += freq[i]
            if j > cnt:
                return False
        return True


if __name__ == "__main__":
    obj = Solution()
    print(obj.isZeroArray(nums=[1, 0, 1], queries=[[0, 2]]))
    print(obj.isZeroArray(nums=[4, 3, 2, 1], queries=[[1, 3], [0, 2]]))
