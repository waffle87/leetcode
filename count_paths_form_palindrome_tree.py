# 2791. Count Paths That Can Form a Palindrome in a Tree
from collections import Counter

"""
you are given a tree (ie. a connected, undirected graph that has no cycles)
rooted at node 0 consisting of 'n' nodes numbered from 0 to 'n - 1'. the tree
is represented by a 0-indexed array 'parent' of size 'n' where 'parent[i]' is
the parent of node 'i'. since node 0 is the root, 'parent[0] == -1'. you are
also given a string 's' of length 'n' where 's[i]' is the character assigned
to the edge between 'i' and 'parent[i]'. 's[0]' can be ignored. return the
number of pairs of nodes '(u, v)' such that 'u < v' and the characters
assigned to edges on the path from 'u' to 'v' can rearranged to form a
palindrome
"""


class Solution(object):
    def countPalindromePaths(self, parent, s):
        """
        :type parent: List[int]
        :type s: str
        :rtype: int
        """

        def f(i):
            return f(parent[i]) ^ (1 << (ord(s[i]) - ord("a"))) if i else 0

        cnt, ans = Counter(), 0
        for i in range(len(parent)):
            mask = f(i)
            ans += cnt[mask] + sum(cnt[mask ^ (1 << j)] for j in range(26))
            cnt[mask] += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countPalindromePaths(parent=[-1, 0, 0, 1, 1, 2], s="acaabc"))
    print(obj.countPalindromePaths(parent=[-1, 0, 0, 0, 0], s="aaaaa"))
