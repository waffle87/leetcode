# 1877. Minimize Maximum Pair Sum in Array

"""
the pair sum of pair '(a, b)' is equal to 'a + b'. the maximum pair sum is
the largest pair sum in a list of pairs. given an array 'nums' of even length
'n', pair up the lements of 'nums' into 'n / 2' pairs such that each element
of 'nums' is in exactly one pair and the maximum pair sum is minimised.
return the minimised maximium pair sum after optimally pairing up the
elements.
"""


class Solution(object):
    def minPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return max(a + b for a, b in zip(sorted(nums), sorted(nums)[::-1]))


if __name__ == "__main__":
    obj = Solution()
    print(obj.minPairSum([3, 5, 2, 3]))  # expect: 7
    print(obj.minPairSum([3, 5, 4, 2, 4, 6]))  # expect: 8
