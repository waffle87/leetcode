# 2956. Find Common Elements Between Two Arrays

"""
given two integer arrays 'nums1' and 'nums2' of sizes 'n' and 'm'
respectively. calculate the following values: 'answer1' is the number of
indices 'i' such that 'nums1[i]' exists in 'nums2' and 'answer2' is the
number of indices 'i' such that 'nums2[i]' exist in 'nums1'
"""


class Solution(object):
    def findIntersectionValues(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        cnt1, cnt2 = 0, 0
        for i in nums1:
            if i in nums2:
                cnt1 += 1
        for i in nums2:
            if i in nums1:
                cnt2 += 1
        return cnt1, cnt2


if __name__ == "__main__":
    obj = Solution()
    print(obj.findIntersectionValues(nums1=[2, 3, 2], nums2=[1, 2]))
    print(obj.findIntersectionValues(nums1=[4, 3, 2, 3, 1], nums2=[2, 2, 5, 2, 3, 6]))
    print(obj.findIntersectionValues(nums1=[3, 4, 2, 3], nums2=[1, 5]))
