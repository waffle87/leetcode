# 2179. Count Good Triplets in an Array
import bisect

"""
you are given two 0-indexed arrays 'nums1' and 'nums2' of length 'n', both of
which are permutations of '[0, 1, ..., n - 1]'. a good triplet is a set of
three distinct values which are present in increasing order by position in
both 'nums1' and 'nums2'. in other words, if we consider 'pos1v' as the index
of the value 'v' in 'nums1' and 'pos2v' as the index of the value 'v' in
'nums2', then a good triplet will be a set '(x, y, z)'. return the total
number of good triplets.
"""


class Solution(object):
    def goodTriplets(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        arr, n = {}, len(nums1)
        for i, j in enumerate(nums1):
            arr[j] = i
        ans, stk = 0, []
        for i in nums2:
            idx = arr[i]
            left = bisect.bisect_left(stk, idx)
            right = (n - 1 - idx) - (len(stk) - left)
            ans += left * right
            bisect.insort(stk, idx)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.goodTriplets(nums1=[2, 0, 1, 3], nums2=[0, 1, 2, 3]))
    print(obj.goodTriplets(nums1=[4, 0, 1, 3, 2], nums2=[4, 1, 0, 2, 3]))
