# 1353. Maximum Number of Events That Can Be Attended
import heapq

"""
you are given an array of 'events' where 'events[i] = [startday_i,
endday_i]'. every event 'i' starts at 'startday_i' and ends at 'endday_i'.
you can attend an event 'i' at any day 'd' where 'starttime_i <= d <=
endtime_i'. you can only attend one event at any time 'd'. return the maximum
number of events you can attend.
"""


class Solution(object):
    def maxEvents(self, events):
        """
        :type events: List[List[int]]
        :rtype: int
        """
        events.sort(reverse=True)
        heap, ans, d = [], 0, 0
        while events or heap:
            if not heap:
                d = events[-1][0]
                while events and events[-1][0] <= d:
                    heapq.heappush(heap, events.pop()[1])
                heapq.heappop(heap)
                ans += 1
                d += 1
                while heap and heap[0] < d:
                    heapq.heappop(heap)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxEvents(events=[[1, 2], [2, 3], [3, 4]]))
    print(obj.maxEvents(events=[[1, 2], [2, 3], [3, 4], [1, 2]]))
