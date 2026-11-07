# 1882. Process Tasks Using Servers

"""
You are given two 0-indexed integer arrays 'servers' and 'tasks' of lengths
'n' and 'm' respectively. 'servers[i]' is the weight of the i'th server, and
'tasks[j]' is the time needed to process the j'th task in seconds. tasks are
assigned to the servers using a task queue. initially, all servers are free,
and the queue is empty. at second 'j', the j'th task is inserted into the
queue (starting with the 0'th task being inserted at second 0). as long as
there are free servers and the queue is not empyt, the task in the front of
the queue will be assigned to a free server with the smallest weight, and
incase of a tie, it is assigned to a free server with the smallest index. a
server that is assigned task 'j' at second 't' will be free again at second
't + tasks[j]'. build an array 'ans' of length 'm' where 'ans[j]' is the
index of the server the j'th task will be assigned to.
"""

from heapq import heapify, heappop, heappush


class Solution:
    def assignTasks(self, servers: list[int], tasks: list[int]) -> list[int]:
        free = [(i, j) for j, i in enumerate(servers)]
        heapify(free)
        ans, busy = [], []
        for s, t in enumerate(tasks):
            while busy and busy[0][0] <= s:
                heappush(free, heappop(busy)[1:])
            start, w, i = (s, *heappop(free)) if free else heappop(busy)
            heappush(busy, (start + t, w, i))
            ans.append(i)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.assignTasks(servers=[3, 3, 2], tasks=[1, 2, 3, 2, 1, 2]))
    print(obj.assignTasks(servers=[5, 1, 4, 3, 2], tasks=[2, 1, 2, 4, 5, 2, 1]))
