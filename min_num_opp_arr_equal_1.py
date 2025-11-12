# 2654. Minimum Number of Operations to Make All Array Elements Equal to 1
from math import gcd

"""
given a 0-indexed array 'nums' consisting of positive integers. you can do
the following operation on the array any number of time: select an index 'i'
such that '0 <= i < n - 1' and replace either of 'nums[i]' or 'nums[i + 1]'
with their gcd values. return the minimum number of operations to make all
elements of 'nums' equal to 1. if this is impossible, return -1. the gcd of
two integers is the greatest common divisor of the two integers.
"""


class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n, ones = len(nums), nums.count(1)
        if ones:
            return n - ones
        ans = float("inf")
        for i in range(n):
            curr = nums[i]
            for j in range(i + 1, n):
                curr = gcd(curr, nums[j])
                if curr == 1:
                    ans = min(ans, j - i)
        if ans == float("inf"):
            return -1
        return ans + n - 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.minOperations([2, 6, 3, 4]))
    print(obj.minOperations([2, 10, 6, 14]))
