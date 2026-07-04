# 3620. Network Recovery Pathways

from collections import deque

"""
you are given a directed acyclic graph of 'n' nodes numbered from 0 to 'n -
1'.this is represented by a 2d array 'edges' of length 'm', where 'edges[i] =
[ui, vi, costi]' indicates a one-way communication from node 'ui' to node
'vi' with a recovery of 'costi'. some nodes may be offline. you are given a
boolean array where 'online[i] = true' means node 'i' is online. a path from
to 0 to 'n - 1' is valid if all intermediate nodes on the path are online,
and the total recovery cost of all edges on the path does not exceed 'k'.
return the maximum path score among all valid paths. if no valid path exists,
return -1.
"""


class Solution:
    def findMaxPathScore(
        self, edges: List[List[int]], online: List[bool], k: int
    ) -> int:
        n = len(online)
        graph = [[] for _ in range(n)]
        indegree = [0] * n
        for u, v, w in edges:
            graph[u].append((v, w))
            indegree[v] += 1
        q = deque()
        for i in range(n):
            if indegree[i] == 0:
                q.append(i)
        topo = []
        while q:
            u = q.popleft()
            topo.append(u)
            for v, _ in graph[u]:
                indegree[v] -= 1
                if indegree[v] == 0:
                    q.append(v)

        def check(limit):
            big = 10**30
            dp = [big] * n
            dp[0] = 0
            for u in topo:
                if dp[u] == big:
                    continue
                if u != 0 and u != n - 1 and not online[u]:
                    continue
                for v, w in graph[u]:
                    if w < limit:
                        continue
                    if v != n - 1 and not online[v]:
                        continue
                    if dp[u] + w < dp[v]:
                        dp[v] = dp[u] + w
            return dp[-1] <= k

        left = 0
        right = 10**9
        ans = -1
        while left <= right:
            mid = (left + right) // 2
            if check(mid):
                ans = mid
                left = mid + 1
            else:
                right = mid - 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.findMaxPathScore(
            edges=[[0, 1, 5], [1, 3, 10], [0, 2, 3], [2, 3, 4]],
            online=[true, true, true, true],
            k=10,
        )
    )
    print(
        obj.findMaxPathScore(
            edges=[[0, 1, 7], [1, 4, 5], [0, 2, 6], [2, 3, 6], [3, 4, 2], [2, 4, 6]],
            online=[true, true, true, false, true],
            k=12,
        )
    )
