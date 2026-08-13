# 2213. Longest Substring of One Repeating Character

"""
you are given a 0-indexed string 's'. you are also given a 0-indexed string
'queryCharacters' of length 'k' and a 0-indexed array of integer indices
'queryIndices' of length 'k', both of which are used to describe 'k' queries.
the i'th query updates the character in 's' at index 'queryIndices[i]' to the
character 'queryCharacters[i]'. return an array 'lengths' of length 'k' where
'lengths[i]' is the length of the longest substring of 's' consisting of only
one repeating character after the i'th query is performed.
"""


class Solution:
    def longestRepeating(
        self, s: str, queryCharacters: str, queryIndices: List[int]
    ) -> List[int]:
        n = len(s)
        tree = [None] * 4 * n

        def merge(left, right):
            if left is None:
                return right
            if right is None:
                return left
            lc, lrc, llen, lp, ls, lb = left
            rlc, rc, rlen, rp, rs, rb = right
            length = llen + rlen
            prefix = lp
            if lrc == rlc and lp == llen:
                prefix = llen + rp
            suffix = rs
            if lrc == rlc and rs == rlen:
                suffix = rlen + ls
            best = max(lb, rb)
            if lrc == rlc:
                best = max(best, ls + rp)
            return [lc, rc, length, prefix, suffix, best]

        def build(node, start, end):
            if start == end:
                tree[node] = [s[start], s[start], 1, 1, 1, 1]
                return
            mid = (start + end) // 2
            build(node * 2, start, mid)
            build(node * 2 + 1, mid + 1, end)
            tree[node] = merge(tree[node * 2], tree[node * 2 + 1])

        def update(node, start, end, idx, c):
            if start == end:
                tree[node] = [c, c, 1, 1, 1, 1]
                return
            mid = (start + end) // 2
            if idx <= mid:
                update(node * 2, start, mid, idx, c)
            else:
                update(node * 2 + 1, mid + 1, end, idx, c)
            tree[node] = merge(tree[node * 2], tree[node * 2 + 1])

        build(1, 0, n - 1)
        ans = []
        for char, idx in zip(queryCharacters, queryIndices):
            update(1, 0, n - 1, idx, char)
            ans.append(tree[1][5])
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.longestRepeating(s="babacc", queryCharacters="bcb", queryIndices=[1, 3, 3])
    )
    print(obj.longestRepeating(s="abyzz", queryCharacters="aa", queryIndices=[2, 1]))
