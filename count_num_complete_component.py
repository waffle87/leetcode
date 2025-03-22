# 2685. Count the Number of Complete Components

"""
you are given an integer 'n'. there is an undirected graph with 'n' vertices,
numbered from 0 to 'n - 1'. you are given a 2d integer array 'edges' where
'edges[i] = [a_i, b_i]' denotes that there exists an undirected edge
connecting vertices 'a_i' and 'b_i'. return the number of complete connected
components of the graph. a connected component is a subgraph of a graph in
which there exists a path between any two vertices and no vertex of the
subgraph shares an edge with a vertex outside of the subgraph. a connected
component is said to be complete if there exists an edge between every pair
of its vertices
"""


class Solution(object):
    def countCompleteComponents(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        graph = [[] for _ in range(n)]
        for i, j in edges:
            graph[i].append(j)
            graph[j].append(i)
        vis, ans = [False] * n, 0
        for i in range(n):
            if vis[i]:
                continue
            bfs = [i]
            vis[i] = True
            for j in bfs:
                for k in graph[j]:
                    if not vis[k]:
                        bfs.append(k)
                        vis[k] = True
            if all(len(graph[j]) == len(bfs) - 1 for j in bfs):
                ans += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countCompleteComponents(n=6, edges=[[0, 1], [0, 2], [1, 2], [3, 4]]))
    print(
        obj.countCompleteComponents(n=6, edges=[[0, 1], [0, 2], [1, 2], [3, 4], [3, 5]])
    )
