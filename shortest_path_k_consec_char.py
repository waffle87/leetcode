# 3970. Shortest Path With At Most K Consecutive Identical Characters

"""
you are given an integer 'n' representing the nubmer of nodes in a directed
weighted graph, numbered from 0 to 'n - 1'. this is represented by a 2d
integer array 'edges' where 'edges[i] = [ui, vi, wi]' represents a directed
edge from node 'ui' to 'vi' with weight 'wi'. you are also given a string
'labels' of length 'n' where 'labels[i]' is the character assigned to node
'i' and integer 'k'. return the minimum total edge weight of a path from node
0 to 'n - 1' such that the concatenation of the labels of the nodes along the
path contains at most 'k' consecutive identical characters. if no valid path
exists, return -1.
"""

from heapq import heappop, heappush


class Solution:
    def shortestPath(self, n: int, edges: List[List[int]], labels: str, k: int) -> int:
        graph = [[] for _ in range(n)]
        for u, v, w in edges:
            graph[u].append((v, w))
        best = [k + 1] * n
        heap = [(0, 1, 0)]
        while heap:
            d, run, x = heappop(heap)
            if run >= best[x]:
                continue
            if x == n - 1:
                return d
            best[x] = run
            for y, w in graph[x]:
                r = run + 1 if labels[y] == labels[x] else 1
                if r < best[y]:
                    heappush(heap, (d + w, r, y))
        return -1


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.shortestPath(
            n=3, edges=[[0, 1, 1], [1, 2, 1], [0, 2, 3]], labels="aab", k=1
        )
    )
    print(
        obj.shortestPath(
            n=3, edges=[[0, 1, 1], [1, 2, 1], [0, 2, 3]], labels="aab", k=2
        )
    )
    print(obj.shortestPath(n=3, edges=[[0, 1, 1], [1, 2, 1]], labels="aaa", k=2))
