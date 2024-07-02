# 350. Intersection of Two Arrays II
from collections import Counter

"""
given two integer arrays 'nums1' and 'nums2' return an array of their
intersection. each element in the result must appear as many times as it
shows in both arrays and you may return the result in any order.
"""


class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        if len(nums1) > len(nums2):
            return self.intersect(nums2, nums1)
        cnt = Counter(nums1)
        ans = []
        for i in nums2:
            if cnt[i] > 0:
                ans.append(i)
                cnt[i] -= 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.intersect(nums1=[1, 2, 2, 1], nums2=[2, 2]))
    print(obj.intersect(nums1=[4, 9, 5], nums2=[9, 4, 9, 8, 4]))
