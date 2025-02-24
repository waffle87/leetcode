# 2467. Most Profitable Path in a Tree

"""
there is an undirected tree with 'n' nodes labeled from 0 to 'n - 1', rooted
at node 0. you are given a 2d integer array 'edges' of length 'n - 1' where
'edges[i] = [a_i, b_i]' indicates that there is an edge between nodes 'a_i'
and 'b_i' in the tree. at every node 'i', there is a gate. you are also given
an array of even integers 'amount', where 'amount[i]' represents the price
needed to open the gate at node 'i', if 'amount[i]' is negative, or the case
reward obtained on oening the gate at node 'i' otherwise. return the maximum
net income alice can have if she travels towards the optimal leaf node.
"""


class Solution(object):
    def mostProfitablePath(self, edges, bob, amount):
        """
        :type edges: List[List[int]]
        :type bob: int
        :type amount: List[int]
        :rtype: int
        """
        n = len(edges) + 1
        graph = [[] for i in range(n)]
        vis = [0] * n
        for i, j in edges:
            graph[i].append(j)
            graph[j].append(i)

        def dfs(i, v):
            vis[i] = 1
            res = -float("inf")
            db = 0 if i == bob else n
            for j in graph[i]:
                if vis[j]:
                    continue
                cur, kk = dfs(j, v + 1)
                res = max(res, cur)
                db = min(db, kk)
            if res == -float("inf"):
                res = 0
            if v == db:
                res += amount[i] // 2
            if v < db:
                res += amount[i]
            return res, db + 1

        return dfs(0, 0)[0]


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.mostProfitablePath(
            edges=[[0, 1], [1, 2], [1, 3], [3, 4]], bob=3, amount=[-2, 4, 2, -4, 6]
        )
    )
    print(obj.mostProfitablePath(edges=[[0, 1]], bob=1, amount=[-7280, 2350]))
