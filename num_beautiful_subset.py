# 2597. The Number of Beautiful Subsets
import collections

"""
given an array 'nums' of positive integers and a positive integer 'k'. a
subset of 'nums' is beautiful if it does not contain integers with an
absolute difference equal to 'k'. return the number of non empty beautiful
subsets of the array 'nums'. a subset of 'nums' is an array that can be
obtained by deleting some elements from 'nums'. two subsets are different iff
the chosen indices to delete are different.
"""


class Solution(object):
    def beautifulSubsets(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        ans = 1
        freq = collections.defaultdict(collections.Counter)
        for i in nums:
            freq[i % k][i] += 1
        for i in freq.values():
            prev_num, curr, prev1, prev2 = -k, 1, 1, 0
            for n in sorted(i):
                skip = prev1
                take = (2 ** i[n] - 1) * (prev2 if n - prev_num == k else prev1)
                curr = skip + take
                prev2, prev1 = prev1, curr
                prev_num = n
            ans *= curr
        return ans - 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.beautifulSubsets(nums=[2, 4, 6], k=2))
    print(obj.beautifulSubsets(nums=[1], k=1))
