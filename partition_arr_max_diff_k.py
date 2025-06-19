# 2294. Partition Array Such That Maximum Difference Is K

"""
you are given an integer array 'nums' and an integer 'k'. you may partition
'nums' into one or more subsequences such that each element in 'nums' appears
in exactly one of the subsequences. return the minimum number of subsequences
needed such that the difference between the maximum and minimum values in
each subsequence is at most 'k'. a subsequence is a sequence that can be
derived from another sequence by deleting some or no elements without
changing the order of the remaining elements.
"""


class Solution(object):
    def partitionArray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        ans, j = 1, 0
        for i in range(len(nums)):
            if nums[i] - nums[j] > k:
                ans += 1
                j = i
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.partitionArray(nums=[3, 6, 1, 2, 5], k=2))
    print(obj.partitionArray(nums=[1, 2, 3], k=1))
    print(obj.partitionArray(nums=[2, 2, 4, 5], k=0))
