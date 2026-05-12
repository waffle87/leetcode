# 1665. Minimum Initial Energy to Finish Tasks

"""
you are given an array 'tasks' where 'tasks[i] = [actual_i, minimum_i]'.
'actual_i' is the actual amount of energy you spen to finish the i'th task,
and 'minimum_i' is the minimum amount of energy you require to begin the i'th
task. return the minimum initial amount of energy you will need to finish all
the tasks
"""


class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        tasks.sort(key=lambda x: x[1] - x[0], reverse=True)
        need = 0
        for actual, minimum in reversed(tasks):
            need = max(minimum, need + actual)
        return need


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumEffort(tasks=[[1, 2], [2, 4], [4, 8]]))
    print(obj.minimumEffort(tasks=[[1, 3], [2, 4], [10, 11], [10, 12], [8, 9]]))
    print(obj.minimumEffort(tasks=[[1, 7], [2, 8], [3, 9], [4, 10], [5, 11], [6, 12]]))
