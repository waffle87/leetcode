# 3373. Maximize the Number of Target Nodes After Connecting Trees II
from collections import deque

"""
there exists two undirect trees with 'n' and 'm' nodes, labeled from '[0, n -
1]' andc '[0, m - 1]' respectively. you are given two 2d integer arrays
'edges1' and 'edges2' of lengths 'n - 1' and 'm - 1' respectively. node 'u'
is target to node 'v' if the number of edges on the path from 'u' to 'v' is
even. note that a node is always target to itself. return an array of
integers where 'ans[i]' is the maximum possible number of nodes that are
target to node 'i' of the first tree if you had to connect one node from the
first tree to another node in the second tree. note that queries are
independent from each other. that is, for every query, you will remove the
added edge before proceeding to the next query.
"""


class Solution(object):
    def maxTargetNodes(self, edges1, edges2):
        """
        :type edges1: List[List[int]]
        :type edges2: List[List[int]]
        :rtype: List[int]
        """

        def find_even(edges, n):
            graph = [[] for _ in range(n)]
            queue = deque([(0, -1, True)])
            evens = [False] * n

            for u, v in edges:
                graph[u].append(v)
                graph[v].append(u)

            while queue:
                node, parent, curr = queue.popleft()
                evens[node] = curr
                for child in graph[node]:
                    if child == parent:
                        continue
                    queue.append((child, node, not curr))
            return evens

        n, m = len(edges1) + 1, len(edges2) + 1
        e1, e2 = find_even(edges1, n), find_even(edges2, m)
        s1, s2 = sum(e1), sum(e2)
        x = max(s2, m - s2)
        return [x + (s1 if even else n - s1) for even in e1]


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.maxTargetNodes(
            edges1=[[0, 1], [0, 2], [2, 3], [2, 4]],
            edges2=[[0, 1], [0, 2], [0, 3], [2, 7], [1, 4], [4, 5], [4, 6]],
        )
    )
    print(
        obj.maxTargetNodes(
            edges1=[[0, 1], [0, 2], [0, 3], [0, 4]], edges2=[[0, 1], [1, 2], [2, 3]]
        )
    )
