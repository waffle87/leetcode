# 3439. Reschedule Meetings for Maximum Free Time I

"""
you are given an integer 'eventTime' denoting the duration of an event, where
the event occurs from time 't = 0' to time 't = eventTime'. you are also
given two integer arrays 'startTime' and 'endTime' each of length 'n'. these
represent the start and end time of 'n' non-overlapping meetings where the
i'th meeting occurs during the time '[startTime[i], endTime[i]]'. you can
reschedule at most 'k' meetings by moving their start time while maintaining
the same duration, to maximise the longest continuous period of free time
during the event. the relative order of all the meetings should stay the same
and they should remain non-overlapping. return the maximum amount of free
time possible after rearranging the meetings. note that the meetings can not
be rescheduled to a time outside of the event.
"""


class Solution(object):
    def maxFreeTime(self, eventTime, k, startTime, endTime):
        """
        :type eventTime: int
        :type k: int
        :type startTime: List[int]
        :type endTime: List[int]
        :rtype: int
        """
        ans, n = 0, len(startTime)
        gaps = [0] * (n + 1)
        pre = [0] * (n + 2)
        gaps[0] = startTime[0]
        gaps[n] = eventTime - endTime[-1]
        for i in range(1, n):
            gaps[i] = startTime[i] - endTime[i - 1]
        for i in range(1, n + 2):
            pre[i] = pre[i - 1] + gaps[i - 1]
        for i in range(k + 1, n + 2):
            ans = max(ans, pre[i] - pre[i - k - 1])
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxFreeTime(eventTime=5, k=1, startTime=[1, 3], endTime=[2, 5]))
    print(obj.maxFreeTime(eventTime=10, k=1, startTime=[0, 2, 9], endTime=[1, 4, 10]))
    print(
        obj.maxFreeTime(
            eventTime=5, k=2, startTime=[0, 1, 2, 3, 4], endTime=[1, 2, 3, 4, 5]
        )
    )
