# 802. Find Eventual Safe States
from collections import defaultdict

"""
there is a directed graph of 'n' nodes with each node labeled from 0 to n
- 1. the graph is represented by a 0-indexed 2d integer array 'graph' where
'graph[i]' is an integer array of nodes adjacent to node 'i', meaning there
is an edge from node 'i' to each node in 'graph[i]'. a node is a terminal
node if there are no outgoing edges. a node is a safe node if every possible
path starting from that node leads to a terminal node ( or another safe
node). return an array containing all the safe nodes of the graph. the answer
should be sorted in ascending order.
"""


class Solution(object):
    def eventualSafeNodes(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[int]
        """
        n = len(graph)
        g = defaultdict(list)
        dp = [0] * n
        for i, v in enumerate(graph):
            dp[i] = len(v)
            for e in v:
                g[e].append(i)
        q = [i for i in range(n) if dp[i] == 0]
        while q:
            x = q.pop()
            for e in g[x]:
                dp[e] -= 1
                if dp[e] == 0:
                    q.append(e)
        ans = [i for i in range(n) if dp[i] == 0]
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.eventualSafeNodes(graph=[[1, 2], [2, 3], [5], [0], [5], [], []]))
    print(obj.eventualSafeNodes(graph=[[1, 2, 3, 4], [1, 2], [3, 4], [0, 4], []]))
