# 2493. Divide Nodes Into the Maximum Number of Groups
from collections import deque

"""
you are given a positive integer 'n' representing the number of nodes in an
undirected graph. the nodes are labeled from 1 to 'n'. you are also given a
2d integer array 'edges', where 'edges[i] = [a_i, b_i]' indicates that there
is a bidirectional edge between nodes 'a_i' and 'b_i'. divide the nodes of
the graph into 'm' groups such that each node in the graph belongs to exactly
one group, and for every pair of nodes in the graph that are connected by an
edge '[a_i, b_i]', then '|y - x| = 1'. return the maximum number of groups
into which you can divide the nodes. return -1 if it is impossible.
"""


class Solution(object):
    def magnificentSets(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        graph = [[] for _ in range(n)]
        for u, v in edges:
            graph[u - 1].append(v - 1)
            graph[v - 1].append(u - 1)
        vis, group = [0] * n, []
        for i in range(n):
            if not vis[i]:
                vis[i] = True
                stack = [i]
                group.append([i])
                while stack:
                    u = stack.pop()
                    for v in graph[u]:
                        if not vis[v]:
                            vis[v] = vis[u] + 1
                            stack.append(v)
                            group[-1].append(v)
                        elif vis[u] & 1 == vis[v] & 1:
                            return -1

        def bfs(x):
            res, vis, q = 0, {x}, deque([x])
            while q:
                res += 1
                for _ in range(len(q)):
                    u = q.popleft()
                    for v in graph[u]:
                        if v not in vis:
                            vis.add(v)
                            q.append(v)
            return res

        ans = 0
        for g in group:
            ans += max(bfs(x) for x in g)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.magnificentSets(n=6, edges=[[1, 2], [1, 4], [1, 5], [2, 6], [2, 3], [4, 6]])
    )
    print(obj.magnificentSets(n=3, edges=[[1, 2], [2, 3], [3, 1]]))
