# 1986. Minimum Number of Work Sessions to Finish the Tasks

"""
there are 'n' tasks assigned to you. the task times are represented as an
integer array 'tasks' of length 'n' where the i'th task takes 'tasks[i]'
hours to finish. a work session is when you work for at most 'sessionTime'
consecutive hours, and then take a break. given 'tasks' and 'sessionTime',
return the minimum number of work sessions needed to finish all the tasks
following the conditions. the tests are generated such that 'sessionTime' is
greater or equal to the maximum element in 'tasks[i]'.
"""


class Solution(object):
    def minSessions(self, tasks, sessionTime):
        """
        :type tasks: List[int]
        :type sessionTime: int
        :rtype: int
        """
        n = len(tasks)

        def dp(mask):
            if mask == 0:
                return (1, 0)
            res = (float("inf"), float("inf"))
            for i in range(n):
                if mask & (1 << i):
                    pieces, prev = dp(mask - (1 << i))
                    full = prev + tasks[i] > sessionTime
                    res = min(res, (pieces + full, tasks[i] + (1 - full) * prev))
            return res

        return dp((1 << n) - 1)[0]


if __name__ == "__main__":
    obj = Solution()
    print(obj.minSessions(tasks=[1, 2, 3], sessionTime=3))
    print(obj.minSessions(tasks=[3, 1, 3, 1, 1], sessionTime=8))
    print(obj.minSessions(tasks=[1, 2, 3, 4, 5], sessionTime=15))
