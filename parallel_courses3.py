# 2050. Parallel Courses III
from collections import defaultdict, deque

"""
given an integer 'n' which indicates that there are n courses labeled from 1
to n. you are also given a 2d integer array rleations where relations[j] =
pre_course[j], denotes that course pre_course has to be completed before
next_course. furthermore, you are given a 0-indexed integer array 'time'
where 'time[i]' denotes how many months it takes to complete the '(i + 1)'th
course. you must find the minimum number of months needed to complete all the
courses following these rules. you may start taking courses at any time if
the prerequisites have been met, and any number of courses can be taken at
the same time. return the minimum number of monthsneeded to omplete all the
courses.
"""


class Solution(object):
    def minimumTime(self, n, relations, time):
        graph = defaultdict(list)
        inDegree = [0] * n
        for prv, nxt in relations:
            prv, nxt = prv - 1, nxt - 1
            graph[prv].append(nxt)
            inDegree[nxt] += 1

        q = deque([])
        dist = [0] * n
        for u in range(n):
            if inDegree[u] == 0:
                q.append(u)
                dist[u] = time[u]

        while q:
            u = q.popleft()
            for v in graph[u]:
                dist[v] = max(dist[u] + time[v], dist[v])
                inDegree[v] -= 1
                if inDegree[v] == 0:
                    q.append(v)
        return max(dist)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumTime(n=3, relations=[[1, 3], [2, 3]], time=[3, 2, 5]))  # expect: 8
    print(
        obj.minimumTime(
            n=5,
            relations=[[1, 5], [2, 5], [3, 5], [3, 4], [4, 5]],
            time=[1, 2, 3, 4, 5],
        )
    )  # expect: 12
