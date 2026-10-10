# 2333. Minimum Sum of Squared Difference

"""
you are given two positive 0-indexed integer arrays 'nums1' and 'nums2', both
of length 'n'. the sum of square difference of arrays is defined as the sum
of '(nums1[i] - nums2[i])^2' for each '0 <= i < n'. you are also given two
positive integers 'k1' and 'k2'. you can modify any of the lements of 'nums1'
by +1 or -1 at most 'k1' times. Similarly such for 'k2' and 'nums2'. return
the minimum sum o squared difference after modifiying array 'nums1' at most
'k1' times and modifying array 'nums2' at most 'k2' times.
"""

from heapq import heapify, heappop, heappush


class Solution:
    def minSumSquareDiff(
        self, nums1: list[int], nums2: list[int], k1: int, k2: int
    ) -> int:
        heap = [-abs(x - y) for x, y in zip(nums1, nums2)]
        s = -sum(heap)
        if k1 + k2 >= s:
            return 0
        delta = k1 + k2
        heapify(heap)
        n = len(nums1)
        while delta > 0:
            d = -heappop(heap)
            gap = max(delta // n, 1) if heap else delta
            d -= gap
            heappush(heap, -d)
            delta -= gap
        return sum(pow(e, 2) for e in heap)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minSumSquareDiff(nums1=[1, 2, 3, 4], nums2=[2, 10, 20, 19], k1=0, k2=0))
    print(obj.minSumSquareDiff(nums1=[1, 4, 10, 12], nums2=[5, 8, 6, 9], k1=1, k2=1))
