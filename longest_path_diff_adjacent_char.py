# 2246. Longest Path With Different Adjacent Characters

"""
you are given a tree (ie. a connected undirected graph that has no cycles)
rooted at node '0' consisting of 'n' nodes numbered from '0' to 'n - 1'. the
tree is represented by a 0-indexed array 'parent' of size 'n' where
'parent[i]' is the parent of node 'i'. since node 0 is the root, 'parent[0] =
-1'. you are also given a string 's' of length 'n', where 's[i]' is the
character assigned to node 'i'. return the legnth of the longest path in the
tree such that no pair of adjacnet nodes on the path have the same character
assigned to them.
"""


class Solution(object):
    def longestPath(self, parent, s):
        """
        :type parent: List[int]
        :type s: str
        :rtype: int
        """
        ans, n = 0, len(parent)
        g = [[] for _ in range(n)]
        for i in range(n):
            if parent[i] != -1:
                g[parent[i]].append(i)

        def dfs(x):
            nonlocal ans
            l1, l2 = 0, 0
            for i in g[x]:
                val = dfs(i)
                if s[x] != s[i]:
                    if val > l2:
                        l2 = val
                    if l2 > l1:
                        l1, l2 = l2, l1
            ans = max(ans, l1 + l2 + 1)
            return l1 + 1

        dfs(0)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestPath(parent=[-1, 0, 0, 1, 1, 2], s="abacbe"))
    print(obj.longestPath(parent=[-1, 0, 0, 0], s="aabc"))
