# 1984. Minimum Difference Between Highest and Lowest of K Scores

"""
you are given a 0 indexed integer array 'nums' where 'nums[i]' represents the
score of the i'th student. you are also given an integer 'k'. pick the scores
of any 'k' students from the array so that the difference betweenn the
highest and the lowest of the 'k' scores is minimised. return the minimum
possible difference.
"""


class Solution(object):
    def minimumDifference(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        return nums.sort() or min(r - l for l, r in zip(nums, nums[k - 1 :]))


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumDifference(nums=[90], k=1))
    print(obj.minimumDifference(nums=[9, 4, 1, 7], k=2))
