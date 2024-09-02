# 3132. Find the Integer Added to Array II

"""
you are given two integer arrays 'nums1' and 'nums2'. from 'nums1', two
elements have been removed, and all other elements have been increased or
decreased in the case of negative by an integer, represented by the variable
'x'. as a result, 'nums1' becomes equal to 'nums2'. two arrays are considered
equal when they contain the same integers with the same frequencies. return
the minimum possible integer 'x' that achieves this equivalence.
"""


class Solution(object):
    def minimumAddedInteger(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        m, ans = len(nums1), float("-inf")
        nums1.sort()
        nums2.sort()

        def check(diff):
            idx = 0
            for n2 in nums2:
                n1 = n2 + diff
                while idx < m and nums1[idx] != n1:
                    idx += 1
                if idx >= m:
                    return False
                idx += 1
            return True

        for diff in [nums1[0] - nums2[0], nums1[1] - nums2[0], nums1[2] - nums2[0]]:
            if check(diff):
                ans = max(ans, diff)
        return -ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumAddedInteger(nums1=[4, 20, 16, 12, 8], nums2=[14, 18, 10]))
    print(obj.minimumAddedInteger(nums1=[3, 5, 5, 3], nums2=[7, 7]))
