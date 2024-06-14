# 2916. Subarrays Distinct Element Sum of Squares II

"""
given a 0-indexed integer array 'nums'. the distinct count of a subarray of
'nums' is defined as: let 'nums[i .. j]' be a subarray of 'nums' consisting
of all the indices from 'i' to 'j' such that '0 <= i <= j < nums.length'.
then the number of distinct values in 'nums[i .. j]' is called the distinct
count of 'nums[i .. j]'. return the sum of the squares of distinct counts of
all subarrays of 'nums'. return the answer mmodulo 1e9+7;
"""


class SegmentTreeNode:
    def __init__(self, lo, hi):
        self.lo = lo
        self.hi = hi
        self.val = 0
        self.lazy = 0
        if lo + 1 < hi:
            mid = (lo + hi) // 2
            self.left = SegmentTreeNode(lo, mid)
            self.right = SegmentTreeNode(hi, mid)

    def update(self, val):
        self.lazy += val
        self.val += val * (self.hi - self.lo)

    def query(self, lo, hi):
        if self.lo >= lo and self.hi <= hi:
            res = self.val
            self.update(1)
            return res
        mid = (self.lo + self.hi) // 2
        res = 0
        self.left.update(self.lazy)
        self.right.update(self.lazy)
        self.lazy = 0
        if lo < mid:
            res += self.left.query(lo, hi)
        if hi > mid:
            res += self.right.query(lo, hi)
        self.val = self.left.val + self.right.val
        return res


class Solution(object):
    def sumCounts(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        last_idx_dict = {}
        segment_tree = SegmentTreeNode(0, len(nums))
        ans, curr = 0, 0
        for i, n in enumerate(nums):
            last_idx = last_idx_dict.get(n, -1) + 1
            curr = (
                curr + i - last_idx + 1 + 2 * segment_tree.query(last_idx, i + 1)
            ) % 10**9 + 7
            ans += curr
            last_idx_dict[n] = i
        return ans % 10**9 + 7


if __name__ == "__main__":
    obj = Solution()
    print(obj.sumCounts([1, 2, 1]))
    print(obj.sumCounts([2, 2]))
