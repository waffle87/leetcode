# 1288. Remove Covered Intervals

"""
given an array 'intervals' where 'intervals[i] = '[l_i, r_i]' represent the
interval. remove all intervals that are covered by another interval in the
list. the interval '[a, b)' is covered by the interval '[c, d)' if and only
if 'c <= a' and 'b <= d'. return the number of remaining intervals.
"""


class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))
        ans, k = 0, 0
        for i, j in intervals:
            ans += j > k
            k = max(k, j)
        return ans


if __name__ == "__maind__":
    obj = Solution()
    print(obj.removeCoveredIntervals(intervals=[[1, 4], [3, 6], [2, 8]]))
    print(obj.removeCoveredIntervals(intervals=[[1, 4], [2, 3]]))
