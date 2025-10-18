# 611. Valid Triangle Number

"""
given an integer array 'nums', return the number of triplets chosen from the
array that can make triangles if we take them as side lengths of a triangle
"""


class Solution(object):
    def maxDistinctElements(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        ans, prev = 0, float("-inf")
        for i in nums:
            if max(i - k, prev + 1) <= i + k:
                prev = max(i - k, prev + 1)
                ans += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxDistinctElements(nums=[1, 2, 2, 3, 3, 4], k=2))
    print(obj.maxDistinctElements(nums=[4, 4, 4, 4], k=1))
