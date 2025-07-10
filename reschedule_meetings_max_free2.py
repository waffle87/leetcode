# 3440. Reschedule Meetings for Maximum Free Time II

"""
you are given an integer 'eventTime' denoting the duration of an event. you
are also given two integer arrays 'startTime' and 'endTime', each of length
'n'. these represent the start and end times of 'n' non-overlapping meetings
that occur during the event between time 't = 0' and time 't = eventTime'
where the i't meeting occurs during the time '[startTime[i], endTime[i]]'.
you can reschedule at most one meeting by moving its start time while
maintaining the same duration such that the meetings remain non-overlapping,
to maximise the longest continuous period of free time during the event.
return the maximum amount of free time possible after rearranging the
meetings.
"""


class Solution(object):
    def maxFreeTime(self, eventTime, startTime, endTime):
        """
        :type eventTime: int
        :type startTime: List[int]
        :type endTime: List[int]
        :rtype: int
        """
        ans, left = 0, 0
        gap = [startTime[0]]
        largest = [0] * len(gap)
        for i in range(1, len(startTime)):
            gap.append(startTime[i] - endTime[i - 1])
        gap.append(eventTime - endTime[-1])
        for i in range(len(gap) - 2, -1, -1):
            largest[i] = max(largest[i + 1], gap[i + 1])
        for i in range(1, len(gap)):
            curr = endTime[i - 1] - startTime[i - 1]
            if curr <= max(left, largest[i]):
                ans = max(ans, gap[i - 1] + gap[i] + curr)
            ans = max(ans, gap[i - 1] + gap[i])
            left = max(left, gap[i - 1])
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxFreeTime(eventTime=5, startTime=[1, 3], endTime=[2, 5]))
    print(obj.maxFreeTime(eventTime=10, startTime=[0, 7, 9], endTime=[1, 8, 10]))
    print(obj.maxFreeTime(eventTime=10, startTime=[0, 3, 7, 9], endTime=[1, 4, 8, 10]))
