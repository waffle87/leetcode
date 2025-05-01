# 2071. Maximum Number of Tasks You Can Assign
from bisect import bisect_left

"""
you have 'n' tasks and 'm' workers. each task has a strength requirement
stored in a 0-indexed integer array 'tasks', with the i'th task requiring
'tasks[i]' strength to complete. the strength of each worker is stored in a
0-indexed array 'workers' with the j'th worker having 'workers[j]' strength.
each worker can only be assigned to a single task and must have a strength
greather than or equal to the task's strength requirement. additionally, you
have 'pills' magic pills that will increase a workers strength by 'strength'.
you can decide which workers receive the pills, however, you may only give
each worker at most one magical pill. given the 0-indexed integer arrays
'tasks' and 'workers' and the integers 'pills' and 'strength', return the
maximum number of tasks that can be completed.
"""


class Solution(object):
    def maxTaskAssign(self, tasks, workers, pills, strength):
        """
        :type tasks: List[int]
        :type workers: List[int]
        :type pills: int
        :type strength: int
        :rtype: int
        """

        def check(k):
            w, tries = workers[-k:], pills
            for i in tasks[:k][::-1]:
                idx = bisect_left(w, i)
                if idx < len(w):
                    w.pop(idx)
                elif tries > 0:
                    idx = bisect_left(w, i - strength)
                    if idx < len(w):
                        w.pop(idx)
                        tries -= 1
                else:
                    return False
            return len(w) == 0

        tasks = sorted(tasks)
        workers = sorted(workers)
        l, r = 0, min(len(workers), len(tasks)) + 1
        while l + 1 < r:
            m = l + (r - l) // 2
            if check(m):
                l = m
            else:
                r = m
        return l


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxTaskAssign(tasks=[3, 2, 1], workers=[0, 3, 3], pills=1, strength=1))
    print(obj.maxTaskAssign(tasks=[5, 4], workers=[0, 0, 0], pills=1, strength=5))
    print(
        obj.maxTaskAssign(
            tasks=[10, 15, 30], workers=[0, 10, 10, 10, 10], pills=3, strength=10
        )
    )
