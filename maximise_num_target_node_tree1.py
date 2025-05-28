# 3372. Maximize the Number of Target Nodes After Connecting Trees I

"""
there exists two undirected trees with 'n' and 'm' nodes with distinct labels
in ranges '[0, n - 1]' respectively. you are given two 2d integer arrays
'edges1' and 'edges2' of length 'n - 1' and 'm - 1' where 'edges[i] = [ai,
bi]' indicates that there is an edge between nodes 'ai' and 'bi' in the first
tree and 'edges2[i] = [ui, vi]' indicates that there is an edge between nodes
'ui' and 'vi' in the second tree. you are also given an integer 'k'. return
an array of 'n' integers 'answer' where 'answer[i]' is the maximum possible
number of nodes target to node 'i' of the first tree if you have to connect
one node from the first tree to another node in the second tree.
"""


class Solution(object):
    def maxTargetNodes(self, edges1, edges2, k):
        """
        :type edges1: List[List[int]]
        :type edges2: List[List[int]]
        :type k: int
        :rtype: List[int]
        """
        n, m, x = len(edges1) + 1, len(edges2) + 1, 0
        if k == 0:
            return [1] * n

        def dfs(node, level, parent, cnt=1):
            if level < k:
                for i in graph[node]:
                    if i == parent:
                        continue
                    cnt += dfs(i, level + 1, node)
            return cnt

        graph = [[] for _ in range(m)]
        for u, v in edges2:
            graph[u].append(v)
            graph[v].append(u)
        for i in range(m):
            x = max(x, dfs(i, 1, -1))
        graph = [[] for _ in range(n)]
        for u, v in edges1:
            graph[u].append(v)
            graph[v].append(u)
        return [dfs(i, 0, -1) + x for i in range(n)]


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.maxTargetNodes(
            edges1=[[0, 1], [0, 2], [2, 3], [2, 4]],
            edges2=[[0, 1], [0, 2], [0, 3], [2, 7], [1, 4], [4, 5], [4, 6]],
            k=2,
        )
    )
    print(
        obj.maxTargetNodes(
            edges1=[[0, 1], [0, 2], [0, 3], [0, 4]],
            edges2=[[0, 1], [1, 2], [2, 3]],
            k=1,
        )
    )
