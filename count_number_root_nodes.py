# 2581. Count Number of Possible Root Nodes
from collections import defaultdict


class Solution(object):
    def rootCount(self, edges, guesses, k):
        """
        :type edges: List[List[int]]
        :type guesses: List[List[int]]
        :type k: int
        :rtype: int
        """
        adj = defaultdict(set)
        for u, v in edges:
            adj[u].add(v)
            adj[v].add(u)
        child = defaultdict(set)
        for u, v in guesses:
            child[u].add(v)
        parents, total_guess = {}, 0

        def fill_parent(node, par):
            nonlocal total_guess
            parents[node] = par
            for i in adj[node]:
                if i != par:
                    if i in child[node]:
                        total_guess += 1
                    fill_parent(i, node)

        fill_parent(0, -1)
        res = 0

        def dfs(node, par, correct_guess):
            nonlocal res
            cur = correct_guess
            if node in child[par]:
                cur -= 1
            if par in child[node]:
                cur += 1
            if cur >= k:
                res += 1
            for i in adj[node]:
                if i != par:
                    dfs(i, node, cur)

        dfs(0, -1, total_guess)
        return res


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.rootCount(
            edges=[[0, 1], [1, 2], [1, 3], [4, 2]],
            guesses=[[1, 3], [0, 1], [1, 0], [2, 4]],
            k=3,
        )
    )
    print(
        obj.rootCount(
            edges=[[0, 1], [1, 2], [2, 3], [3, 4]],
            guesses=[[1, 0], [3, 4], [2, 1], [3, 2]],
            k=1,
        )
    )
