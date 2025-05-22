# 3362. Zero Array Transformation III
from sortedcontainers import SortedList

"""
you are given an integer array 'nums' of length 'n' and a 2d array 'queries'
where 'queries[i] = [li, ri]'. each 'queries[i]' represents the following
action on 'nums': decrement the value at each index in the range '[li, ri]'
in 'nums' by at most 1. the amount by which the value is decremented can be
chosen independently for each index. a zero array is an array with all its
elements equal to 0. return the maximum number of elements that can be
removed from 'queries' such that 'nums' can still be converted to a zero
array using the remaining queries. if it is not possible to convert 'nums' to
a zero array, return -1.
"""


class Solution(object):
    def maxRemoval(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: int
        """
        queries = sorted(queries)[::-1]
        end, curr = SortedList(), SortedList()
        for i in range(len(nums)):
            while queries and queries[-1][0] <= i:
                end.add(queries.pop()[1])
            while curr and curr[0] < i:
                curr.pop(0)
            while nums[i] > len(curr):
                if not end or end[-1] < i:
                    return -1
                curr.add(end.pop())
        return len(end)


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxRemoval(nums=[2, 0, 2], queries=[[0, 2], [0, 2], [1, 1]]))
    print(obj.maxRemoval(nums=[1, 1, 1, 1], queries=[[1, 3], [0, 2], [1, 3], [1, 2]]))
