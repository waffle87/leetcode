# 2918. Minimum Equal Sum of Two Arrays After Replacing Zeros

"""
you are given two arrays 'nums1' and 'nums2' consisting of positive integers.
you have to replace all the 0's in both arrays with strictly positive
integers such that the sum of elements of both arrays becomes equal. return
the minimum equal sum you can obtain, or -1 if it is impossible.
"""


class Solution(object):
    def minSum(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        sum1 = sum(max(i, 1) for i in nums1)
        sum2 = sum(max(i, 1) for i in nums2)
        if sum1 < sum2 and nums1.count(0) == 0:
            return -1
        if sum1 > sum2 and nums2.count(0) == 0:
            return -1
        return max(sum1, sum2)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minSum(nums1=[3, 2, 0, 1, 0], nums2=[6, 5, 0]))
    print(obj.minSum(nums1=[2, 0, 2, 0], nums2=[1, 4]))
