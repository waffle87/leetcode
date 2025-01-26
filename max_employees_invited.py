# 2127. Maximum Employees to Be Invited to a Meeting
from collections import defaultdict, deque

"""
a company is organising a meeting and has a list of 'n' employees, waiting to
be invited. they have arrange for a large circular table, capable of seating
any number of employees. the employees are numbered from 0 to 'n - 1'. each
employee has a favourite person and they will attend the meeting only if they
can sit next to their favourite person. the favourite person of an employee
is not themselves. given a 0 indexed integer array 'favorite' where
'favorite[i]' denotes the favourite person of the i'th employee, return the
maximum number of employees that can be invited.
"""


class Solution(object):
    def maximumInvitations(self, favorite):
        """
        :type favorite: List[int]
        :rtype: int
        """
        indegrees = defaultdict(list)
        for idx, fav in enumerate(favorite):
            indegrees[fav].append(idx)

        def bfs(start, seen):
            q, res = deque([(start, 0)]), 0
            while q:
                pos, dist = q.popleft()
                for i in indegrees[pos]:
                    if i in seen:
                        continue
                    seen.add(i)
                    q.append((i, dist + 1))
                    res = max(res, dist + 1)
            return res

        n = len(favorite)
        cycle_largest, cycle_sum = 0, 0
        for i in range(n):
            if favorite[i] != -1:
                dist = {i: 0}
                while favorite[i] != -1:
                    next = favorite[i]
                    favorite[i] = -1
                    if next in dist:
                        cycle_len = len(dist) - dist[next]
                        cycle_largest = max(cycle_largest, cycle_len)
                        if cycle_len == 2:
                            cycle_sum += 2 + bfs(next, {i, next}) + bfs(i, {i, next})
                    else:
                        i = next
                        dist[next] = len(dist)
        return max(cycle_largest, cycle_sum)


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumInvitations(favorite=[2, 2, 1, 2]))
    print(obj.maximumInvitations(favorite=[1, 2, 0]))
    print(obj.maximumInvitations(favorite=[3, 0, 1, 4, 1]))
