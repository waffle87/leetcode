# 3408. Design Task Manager
import heapq


class TaskManager(object):
    def __init__(self, tasks):
        """
        :type tasks: List[List[int]]
        """
        self.heap = []
        self.task_priority = {}
        self.task_owner = {}
        for i in tasks:
            self.add(i[0], i[1], i[2])

    def add(self, userId, taskId, priority):
        """
        :type userId: int
        :type taskId: int
        :type priority: int
        :rtype: None
        """
        heapq.heappush(self.heap, (-priority, -taskId))
        self.task_priority[taskId] = priority
        self.task_owner[taskId] = userId

    def edit(self, taskId, newPriority):
        """
        :type taskId: int
        :type newPriority: int
        :rtype: None
        """
        heapq.heappush(self.heap, (-newPriority, -taskId))
        self.task_priority[taskId] = newPriority

    def rmv(self, taskId):
        """
        :type taskId: int
        :rtype: None
        """
        self.task_priority[taskId] = -1

    def execTop(self):
        """
        :rtype: int
        """
        while self.heap:
            neg_priority, neg_task_id = heapq.heappop(self.heap)
            priority = -neg_priority
            task_id = -neg_task_id
            if self.task_priority.get(task_id, -2) == priority:
                self.task_priority[task_id] = -1
                return self.task_owner.get(task_id, -1)
        return -1


if __name__ == "__main__":
    obj = TaskManager(tasks=[[1, 101, 10], [2, 102, 20], [3, 103, 15]])
    obj.add(4, 104, 5)
    obj.edit(102, 8)
    print(obj.execTop())
    obj.rmv(101)
    obj.add(5, 105, 15)
    print(obj.execTop())
