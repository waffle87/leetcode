# 2602. Minimum Operations to Make All Array Elements Equal
from itertools import accumulate
from bisect import bisect_left

"""
given an array 'nums' consisting of positive integers. you are also given an
integer array 'queries' of size 'm'. for the i'th query, you want to make all
of the elements of 'nums' equal to 'queries[i]'. you can perform the
following operation on the array any number of times: increase or decrease an
element of the array by 1. return an array 'ans' of size 'm' where 'ans[i]'
is the minimum number of operations to make all elements of 'nums' equal to
'queries[i]'. note that after each query the array is reset to its original
state
"""


class Solution(object):
    def minOperations(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[int]
        :rtype: List[int]
        """
        nums.sort()
        ans, n, prefix = [], len(nums), [0] + list(accumulate(nums))
        for i in queries:
            j = bisect_left(nums, i)
            ans.append(i * (2 * j - n) + prefix[n] - 2 * prefix[j])
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minOperations(nums=[3, 1, 6, 8], queries=[1, 5]))
    print(obj.minOperations(nums=[2, 9, 6, 3], queries=[10]))
