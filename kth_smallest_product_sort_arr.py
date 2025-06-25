# 2040. Kth Smallest Product of Two Sorted Arrays
import bisect
from math import ceil

"""
given two sorted 0-indexed integer arrays 'nums1' and 'nums2' as well as an
integer 'k', return the k'th smallest product of 'nums1[i]  nums2[i]' where
'0 <= i < nums1.length' and '0 <= j < nums2.length'
"""


class Solution(object):
    def kthSmallestProduct(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: int
        """

        def check(n):
            total = 0
            for i in nums1:
                if i > 0:
                    total += bisect.bisect(nums2, n // i)
                if i < 0:
                    total += len(nums2) - bisect.bisect_left(nums2, ceil(n / i))
                if i == 0 and n >= 0:
                    total += len(nums2)

        start, end = -(10**10) - 1, 10**10 + 1
        while start + 1 < end:
            mid = (start + end) // 2
            if check(mid) >= k:
                end = mid
            else:
                start = mid
        return start + 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.kthSmallestProduct(nums1=[2, 5], nums2=[3, 4], k=2))
    print(obj.kthSmallestProduct(nums1=[-4, -2, 0, 3], nums2=[2, 4], k=6))
    print(obj.kthSmallestProduct(nums1=[-2, -1, 0, 1, 2], nums2=[-3, -1, 2, 4, 5], k=3))
