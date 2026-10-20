# 3886. Sum of Sortable Integers

"""
you are given an integer array 'nums' of length 'n'. an integer 'k' is called
sortable if 'k' divides 'n' and you can sort 'nums' in non-decreasing order
by sequentially performing the following operations: partition 'nums' into
consectutive subarrays of length 'k', cyclically rotate each subarray
independently any number of times to the left or to the right. return an
integer denoting the sum of all possible sortable integers 'k'.
"""

from itertools import accumulate, pairwise


class Solution:
    def sortableIntegers(self, nums: list[int]) -> int:
        n = len(nums)
        desc = [0, *accumulate(a > b for a, b in pairwise(nums))]
        max_prefix = list(accumulate(nums, max))
        min_suffix = list(accumulate(reversed(nums), min))[::-1]
        cut = [True] + [max_prefix[i - 1] <= min_suffix[i] for i in range(1, n)]

        def rotatable(l, r):
            return desc[r] - desc[l] + (nums[r] > nums[l]) <= 1

        def sortable(k):
            return all(cut[l] and rotatable(l, l + k - 1) for l in range(0, n, k))

        divisors = [i for i in range(1, n + 1) if n % i == 0]
        return sum(filter(sortable, divisors))


if __name__ == "__main__":
    obj = Solution()
    print(obj.sortableIntegers(nums=[3, 1, 2]))
    print(obj.sortableIntegers(nums=[7, 6, 5]))
    print(obj.sortableIntegers(nums=[5, 8]))
