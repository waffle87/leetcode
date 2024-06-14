# 2540. Minimum Common Value

"""
given two integer arrays 'nums1' and 'nums2', sorted in non-decreasing order.
return the minimum integer common to both arrays. if there is no common
integer amongst 'nums1' and 'nums2', return -1. note that an integer is said
to be common to 'nums1' and 'nums2' if both arrays have at least one
occurence of that integer.
"""


class Solution(object):
    def getCommon(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        st = set(nums1) & set(nums2)
        return min(st) if len(st) else -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.getCommon([1, 2, 3], [2, 4]))
    print(obj.getCommon([1, 2, 3, 6], [2, 3, 4, 5]))
