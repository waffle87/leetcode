# 2365. Task Scheduler II
from collections import Counter

"""
given a 0-indexed array of positive integers 'tasks', representing tasks that
need to be completed in order, where 'tasks[i]' represents the type of the
i'th task. you are also given a positve integer 'space' which represents the
minimum number of days that must pass after the completion of a task before
another task of the same type can be performed. each day until all tasks have
been completed, you must either
- complete the next task from 'tasks' or
- take a break
return the minimum number of days needed to complete all tasks.
"""


class Solution(object):
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        task_cnt = Counter(tasks).values()
        m = max(task_cnt)
        mct = task_cnt.count(m)
        return max(len(tasks), (m - 1) * (n + 1) + mct)


if __name__ == "__main__":
    obj = Solution()
    print(obj.leastInterval(tasks=["A", "A", "A", "B", "B", "B"], n=2))
    print(obj.leastInterval(tasks=["A", "C", "A", "B", "D", "B"], n=1))
    print(obj.leastInterval(tasks=["A", "A", "A", "B", "B", "B"], n=3))
