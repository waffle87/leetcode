# 2065. Maximum Path Quality of a Graph
from collections import defaultdict

"""
there is an undirected graph with 'n' nodes numbered from 0 to 'n - 1'. you
are given a 0-indexed integer array 'values' where 'values[i]' is the value
of the i'th node. you are also given a 0-indexed 2d integer array 'edges',
where each 'edges[j] = [uj, vj, timej]' indicates that there is an undirected
edge between the nodes 'uj' and 'vj', and it takes 'timej' seconds to travel
between the two nodes. finally, you are given an integer 'maxTime'. a valid
path in the graph is any path that starts at node 0, ends at node 0, and
takes at most 'maxTime' seconds to complete. you may visit the same node
multiple times. the quality of a valid path is the sum of the value of the
unique nodes visited in the path (each node's value is added at most once to
the sum). return the maximum quality of a valid path.
"""


class Solution(object):
    def maximalPathQuality(self, values, edges, maxTime):
        """
        :type values: List[int]
        :type edges: List[List[int]]
        :type maxTime: int
        :rtype: int
        """
        graph = defaultdict(list)
        for u, v, t in edges:
            graph[u].append((v, t))
            graph[v].append((u, t))

        def dfs(node, vis, gain, cost):
            if node == 0:
                self.ans = max(self.ans, gain)
            for i, t in graph[node]:
                if t <= cost:
                    dfs(i, vis | set([i]), gain + (i not in vis) * values[i], cost - t)

        self.ans = 0
        dfs(0, set([0]), values[0], maxTime)
        return self.ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.maximalPathQuality(
            values=[0, 32, 10, 43],
            edges=[[0, 1, 10], [1, 2, 15], [0, 3, 10]],
            maxTime=49,
        )
    )
    print(
        obj.maximalPathQuality(
            values=[5, 10, 15, 20],
            edges=[[0, 1, 10], [1, 2, 10], [0, 3, 10]],
            maxTime=30,
        )
    )
    print(
        obj.maximalPathQuality(
            values=[1, 2, 3, 4],
            edges=[[0, 1, 10], [1, 2, 11], [2, 3, 12], [1, 3, 13]],
            maxTime=50,
        )
    )
