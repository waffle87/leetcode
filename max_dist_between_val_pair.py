# 1855. Maximum Distance Between a Pair of Values

"""
you are given two non-increasing 0-indexed integer arrays 'nums1' and
'nums2'. a pair of indices '(i, j)' where '0 <= i < nums1.lenth' and '0 <= j
< nums2.lenth' is valid if both 'i <= j' and 'nums1[i] <= nums2[j]'. the
distance of the pair is 'j - i'. return the maximum distance of any valid
pair '(i, j)'. if there are no valid pairs, return 0.
"""


class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        i, j, ans = 0, 0, 0
        while i < len(nums1) and j < len(nums2):
            if nums1[i] > nums2[j]:
                i += 1
            else:
                ans = max(ans, j - i)
                j += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxDistance(nums1=[55, 30, 5, 4, 2], nums2=[100, 20, 10, 10, 5]))
    print(obj.maxDistance(nums1=[2, 2, 2], nums2=[10, 10, 1]))
    print(obj.maxDistance(nums1=[30, 29, 19, 5], nums2=[25, 25, 25, 25, 25]))
