# 3867. Sum of GCD of Formed Pairs

"""
you are given an integer array 'nums' of length 'n'. construct an array
'prefixGcd' where for each index 'i', let 'mx_i = max(nums[0], nums[1], ...,
nums[i])', and 'prefixGcd[i] = gcd(nums[i], mx_i)'. after constructing
'prefixGcd', sort 'prefixGcd' in non-decreasing order, form pairs by taking
the smallest unpaired element and the largest unpaired element, repeat this
process until no more pairs can be formed. for each formed pair, compuute the
'gcd' of the two elemets. if 'n' is odd, the middle element in the
'prefixGcd' array remains unpaired and should be ignored. return an integer
denoting the sum of the gcd values of all formed pairs. the term 'gcd(a, b)'
denotes the greatest common divisor of 'a' and 'b'.
"""

from itertools import accumulate
from math import gcd


class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        prefix = sorted(map(gcd, nums, accumulate(nums, max)))
        return sum(map(gcd, prefix[: len(prefix) // 2], prefix[::-1]))


if __name__ == "__main__":
    obj = Solution()
    print(obj.gcdSum(nums=[2, 6, 4]))
    print(obj.gcdSum(nums=[3, 6, 2, 8]))
