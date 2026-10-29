# 3841. Palindromic Path Queries in a Tree

"""
you are given an undirected tree with 'n' nodes labeled 0 to 'n - 1'. this is
represented by a 2d array 'edges' of length 'n - 1' where 'edges[i] = [ui,
vi]' indicates an undirected edge between nodes 'ui' and 'vi'. you are also
given a string 's' of length 'n' consisting of lowercase english letters,
where 's[i]' represents the character assigned to node 'i'. you are also
given a string 'queries' where each 'queries[i]' is either 'update ui c':
change the character at node 'ui' to 'c', or 'query ui vi': determine whether
the string formed by the characters on the unique path from 'ui' to 'vi' can
be rearranged into a palindrome. return a boolean array 'answer' where
'answer[j]' is true if the 'j'th query of type query can be arranged into a
palindrome and false otherwise.
"""


class Solution:
    def palindromePath(
        self, n: int, edges: list[list[int]], s: str, queries: list[str]
    ) -> list[bool]:
        graph = [[] for _ in range(n)]
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        log = 17
        parent = [[-1] * n for _ in range(log)]
        depth = [0] * n
        tin = [0] * n
        tout = [0] * n
        timer = 0

        def dfs(node: int, par: int):
            nonlocal timer
            tin[node] = timer
            timer += 1
            parent[0][node] = par
            for nei in graph[node]:
                if nei == par:
                    continue
                depth[nei] = depth[node] + 1
                dfs(nei, node)
            tout[node] = timer - 1

        dfs(0, -1)
        for k in range(1, log):
            for i in range(n):
                p = parent[k - 1][i]
                if p != -1:
                    parent[k][i] = parent[k - 1][p]

        def lca(u: int, v: int) -> int:
            if depth[u] < depth[v]:
                u, v = v, u
            diff = depth[u] - depth[v]
            for k in range(log):
                if diff & (1 << k):
                    u = parent[k][u]
            if u == v:
                return u
            for k in reversed(range(log)):
                if parent[k][u] != parent[k][v]:
                    u = parent[k][u]
                    v = parent[k][v]
            return parent[0][u]

        size = n
        fenwick = [0] * (n + 1)

        def fenwick_add(i: int, val: int):
            i += 1
            while i <= size:
                fenwick[i] ^= val
                i += i & -i

        def fenwick_prefix(i: int) -> int:
            res = 0
            i += 1
            while i > 0:
                res ^= fenwick[i]
                i -= i & -i
            return res

        def char_mask(c: str) -> int:
            return 1 << (ord(c) - ord("a"))

        labels = list(s)
        for u, c in enumerate(labels):
            m = char_mask(c)
            fenwick_add(tin[u], m)
            fenwick_add(tout[u] + 1, m)

        ans = []

        for q in queries:
            parts = q.split()

            if parts[0] == "update":
                u = int(parts[1])
                new_char = parts[2]

                delta = char_mask(labels[u]) ^ char_mask(new_char)
                labels[u] = new_char

                fenwick_add(tin[u], delta)
                fenwick_add(tout[u] + 1, delta)

            else:
                u, v = int(parts[1]), int(parts[2])
                w = lca(u, v)
                path_mask = (
                    fenwick_prefix(tin[u])
                    ^ fenwick_prefix(tin[v])
                    ^ char_mask(labels[w])
                )
                ans.append(path_mask == 0 or (path_mask & (path_mask - 1)) == 0)

        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.palindromePath(
            n=3,
            edges=[[0, 1], [1, 2]],
            s="aac",
            queries=["query 0 2", "update 1 b", "query 0 2"],
        )
    )
    print(
        obj.palindromePath(
            n=4,
            edges=[[0, 1], [0, 2], [0, 3]],
            s="abca",
            queries=["query 1 2", "update 0 b", "query 2 3", "update 3 a", "query 1 3"],
        )
    )
