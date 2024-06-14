# 4. Median of Two Sorted Arrays

"""
given two sorted arrays 'nums1' and 'nums2' of size 'm' and 'n', respectively
return the median of the two sorted arrays. the overall run time complexity
should be 'O(log(m + n))'
"""


class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        l = len(nums1) + len(nums2)
        if l % 2 == 1:
            return self.kth(nums1, nums2, l // 2)
        else:
            return (
                self.kth(nums1, nums2, l // 2) + self.kth(nums1, nums2, l // 2 - 1)
            ) / 2.0

    def kth(self, a, b, k):
        if not a:
            return b[k]
        if not b:
            return a[k]
        ia, ib = len(a) // 2, len(b) // 2
        ma, mb = a[ia], b[ib]
        if ia + ib < k:
            if ma > mb:
                return self.kth(a, b[ib + 1 :], k - ib - 1)
            else:
                return self.kth(a[i + 1 :], b, k - ia - 1)
        else:
            if ma > mb:
                return self.kth(a[:ia], b, k)
            else:
                return self.kth(a, b[:ib], k)


if __name__ == "__main__":
    obj = Solution()
    print(obj.findMedianSortedArrays([1, 3], [2]))  # expect: 2.00000
    print(obj.findMedianSortedArrays([1, 2], [3, 4]))  # expect: 2.50000
