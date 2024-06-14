# 1971. Find if Path Exists in Graph
from collections import defaultdict

"""
there is a bidirectional graph with 'n' vertices where each vertex is labeled
from 0 to 'n - 1' inclusive. the edges in the graph are rpresented as a 2d
integer array 'edges', where each 'edgies[i] = [ui, vi]', denotes a
bidirectional edge between vertex 'ui' and vertex 'vi'. every vertex pair is
connected by at most one edge, and no vertex has an edge to itself.
"""


class Solution(object):
    def validPath(self, n, edges, source, destination):
        """
        :type n: int
        :type edges: List[List[int]]
        :type source: int
        :type destination: int
        :rtype: bool
        """
        neighbors = defaultdict(list)
        for n1, n2 in edges:
            neighbors[n1].append(n2)
            neighbors[n2].append(n1)

        def dfs(node, destination, seen):
            if node == destination:
                return True
            if node in seen:
                return False
            seen.add(node)
            for n in neighbors[node]:
                if dfs(n, destination, seen):
                    return True
            return False

        seen = set()
        return dfs(source, destination, seen)


if __name__ == "__main__":
    obj = Solution()
    print(obj.validPath(n=3, edges=[[0, 1], [1, 2], [2, 0]], source=0, destination=2))
    print(
        obj.validPath(
            n=6, edges=[[0, 1], [0, 2], [3, 5], [5, 4], [4, 3]], source=0, destination=5
        )
    )
