# 1913. Maximum Product Difference Between Two Pairs

"""
the product difference between two pairs '(a, b)' and '(c, d)' is defined as
'(a  b) - (c  d)'. given an integer array 'nums', choose four distinct
indices 'w', 'x', 'y' and 'z' such that the product difference between pairs
'(nums[w], nums[x])' and '(nums[y], nums[y])' is maximised. return the
maximum such product difference
"""


class Solution(object):
    def maxProductDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return (
            sorted(nums)[len(nums) - 2] * sorted(nums)[len(nums) - 1]
            - sorted(nums)[0] * sorted(nums)[1]
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxProductDifference(nums=[5, 6, 2, 7, 4]))
    print(obj.maxProductDifference(nums=[4, 2, 5, 9, 7, 4, 8]))
