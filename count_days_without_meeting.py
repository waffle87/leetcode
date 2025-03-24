# 3169. Count Days Without Meetings

"""
you are given a positive integer 'days' representing the total number of days
an employee is available for work (starting from day 1). you are given a 2d
integer array 'meetings' of size 'n' where 'meetings[i] = [start_i, end_i]'
represents the starting and ending days of meeting 'i' (inclusive). return
the count of days when the employee is available for work, but no meetings
are scheduled.
"""


class Solution(object):
    def countDays(self, days, meetings):
        """
        :type days: int
        :type meetings: List[List[int]]
        :rtype: int
        """
        meetings.sort(key=lambda x: x[0])
        cnt, n = abs(meetings[0][0] - 1), len(meetings)
        for i in range(1, n):
            if meetings[i][0] <= meetings[i - 1][1]:
                if meetings[i][1] < meetings[i - 1][1]:
                    meetings[i][1] = meetings[i - 1][1]
            else:
                day = meetings[i][0] - meetings[i - 1][1]
                cnt += day - 1
        cnt += abs(meetings[n - 1][1] - days)
        return cnt


if __name__ == "__main__":
    obj = Solution()
    print(obj.countDays(days=10, meetings=[[5, 7], [1, 3], [9, 10]]))
    print(obj.countDays(days=5, meetings=[[2, 4], [1, 3]]))
    print(obj.countDays(days=6, meetings=[[1, 6]]))
