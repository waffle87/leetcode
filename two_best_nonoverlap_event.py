# 2054. Two Best Non-Overlapping Events

"""
you are given a 0-indexed 2d integer array of 'events' where 'events[i] =
[start_time, end_time, value]'. the i'th event starts at 'start_time' and
ends at 'end_time', and if you attend this event, you will receive a value of
'value'. you can choose at most two non-overlapping events to ttend such that
the sum of their values is maximise. return this maximum sum. note that the
start time and end time is inclusive: that is, you cannot attend two events
where one of them starts and the other ends at the same time. more
specifically, if you attend an event with end time 't', the next event must
start or after 't + 1'
"""


class Solution(object):
    def maxTwoEvents(self, events):
        """
        :type events: List[List[int]]
        :rtype: int
        """
        proc, ans, m = [], 0, 0
        for s, e, v in events:
            proc.append((s, True, v))
            proc.append((e + 1, False, v))
        proc.sort()
        for time, start, val in proc:
            if start:
                ans = max(ans, m + val)
            else:
                m = max(m, val)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxTwoEvents(events=[[1, 3, 2], [4, 5, 2], [2, 4, 3]]))
    print(obj.maxTwoEvents(events=[[1, 3, 2], [4, 5, 2], [1, 5, 5]]))
    print(obj.maxTwoEvents(events=[[1, 5, 3], [1, 5, 1], [6, 6, 5]]))
