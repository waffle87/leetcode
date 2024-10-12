# 2406. Divide Intervals Into Minimum Number of Groups

"""
you are given a 2d integer array 'intervals' where 'intervals[i] = [left,
right]' represents the inclusive interval '[left, right]'. you have to divide
the intervals into one or more groups such that each interval is in exactly
one group, and no two intervals that are in the same group intersect each
other. return the minimum number of groups you need to make. two intervals
intersect if there is at least one common number between them.
"""


class Solution(object):
    def minGroups(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        arr = []
        for i, j in intervals:
            arr.append([i, 1])
            arr.append([j + 1, -1])
        ans, curr = 0, 0
        for i, j in sorted(arr):
            curr += j
            ans = max(ans, curr)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minGroups(intervals=[[5, 10], [6, 8], [1, 5], [2, 3], [1, 10]]))
    print(obj.minGroups(intervals=[[1, 3], [5, 6], [8, 10], [11, 13]]))
