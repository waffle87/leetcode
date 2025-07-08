# 1751. Maximum Number of Events That Can Be Attended II
from bisect import bisect

"""
you are given an array of 'events' where 'events[i] = [startday_i, endday_i,
value_i]'. the i'th event starts at 'startday_i' and ends at 'endday_i', and
if you attend this event, you will receive a value of 'value_i'. you are also
given an integer 'k', which represents the maximum number of events you can
attend. you can only attend one event at a time. if you choose to attend an
event, you must attend the entire event. note that the end day is inclusive:
that is, you cannot attend two events where one of them starts and the other
ends on the same day. return the maximum sum of the values that you can
receive by attending events
"""


class Solution(object):
    def maxValue(self, events, k):
        """
        :type events: List[List[int]]
        :type k: int
        :rtype: int
        """
        events.sort(key=lambda x: x[1])
        dp1, dp2 = [[0, 0]], [[0, 0]]
        for i in range(k):
            for s, e, v in events:
                j = bisect(dp1, [s]) - 1
                if dp1[j][1] + v > dp2[-1][1]:
                    dp2.append([e, dp1[j][1] + v])
            dp1, dp2 = dp2, [[0, 0]]
        return dp1[-1][-1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxValue(events=[[1, 2, 4], [3, 4, 3], [2, 3, 1]], k=2))
    print(obj.maxValue(events=[[1, 2, 4], [3, 4, 3], [2, 3, 10]], k=2))
    print(obj.maxValue(events=[[1, 1, 1], [2, 2, 2], [3, 3, 3], [4, 4, 4]], k=3))
