# 1857. Largest Color Value in a Directed Graph
from collections import deque

"""
there is a directed graph of 'n' coloured nodes and 'm' edges. the nodes are
numbered from 0 to 'n - 1'. you are given a tring 'colours' where
'colours[i]' is a lowercase english letter representing the colour of the
i'th node in this graph (0-indexed). you are also given a 2d integer array
'edges' where 'edges[i] = [ai, bi]' indicates that there is a directed edge
from node 'ai' to 'bi'. a valid path in the graph is a sequence of nodes such
that there is a directed edge for every ' 1 <= i < k'. the collour value of
the path is the number of nodes that coloured the most frequently occuring
along the path. return the largest colour value of any valid path in the
given graph, or -1 if the graph contains a cycle.
"""


class Solution(object):
    def largestPathValue(self, colors, edges):
        """
        :type colors: str
        :type edges: List[List[int]]
        :rtype: int
        """
        n = len(colors)
        indeg = [0] * n
        graph = [[] for _ in range(n)]
        for i in edges:
            graph[i[0]].append(i[1])
            indeg[i[1]] += 1
        zero_indeg = deque()
        for i in range(n):
            if indeg[i] == 0:
                zero_indeg.append(i)
        cnt = [[0] * 26 for _ in range(n)]
        for i in range(n):
            cnt[i][ord(colors[i]) - ord("a")] += 1
        max_cnt, vis = 0, 0
        while zero_indeg:
            u = zero_indeg.popleft()
            vis += 1
            for v in graph[u]:
                for i in range(26):
                    cnt[v][i] = max(
                        cnt[v][i], cnt[u][i] + (ord(colors[v]) - ord("a") == i)
                    )
                indeg[v] -= 1
                if indeg[v] == 0:
                    zero_indeg.append(v)
            max_cnt = max(max_cnt, max(cnt[u]))
        return max_cnt if vis == n else -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.largestPathValue(colors="abaca", edges=[[0, 1], [0, 2], [2, 3], [3, 4]]))
    print(obj.largestPathValue(colors="a", edges=[[0, 0]]))
