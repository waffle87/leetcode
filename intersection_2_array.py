# 349. Intersection of Two Arrays

"""
given two integer arrays 'nums1' and 'nums2' return an array of their
intersection. each element in the result must be unique and you may return
the result in any order.
"""


class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        return list(set(nums1).intersection(set(nums2)))


if __name__ == "__main__":
    obj = Solution()
    print(obj.intersection(nums1=[1, 2, 2, 1], nums2=[2, 2]))
    print(obj.intersection(nums1=[4, 9, 5], nums2=[9, 4, 9, 8, 4]))
