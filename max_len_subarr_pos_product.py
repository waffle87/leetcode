# 1567. Maximum Length of Subarray With Positive Product

"""
given an array of integers 'nums', find the maximum length of subarray where
the product of all its elements is positive. a subarray of anarray is a
consecutive sequence of zero or more values taken out of that array. return
the maximum length of a subarray with positive product.
"""


class Solution(object):
    def getMaxLen(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n, pos, neg = len(nums), 0, 0
        if nums[0] > 0:
            pos = 1
        if nums[0] < 0:
            neg = 1
        ans = pos
        for i in range(1, n):
            if nums[i] > 0:
                pos += 1
                neg += 1 if neg > 0 else 0
            elif nums[i] < 0:
                pos, neg = 1 + neg if neg > 0 else 0, 1 + pos
            else:
                pos, neg = 0, 0
            ans = max(ans, pos)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.getMaxLen(nums=[1, -2, -3, 4]))
    print(obj.getMaxLen(nums=[0, 1, -2, -3, -4]))
    print(obj.getMaxLen(nums=[-1, -2, -3, 0, 1]))
