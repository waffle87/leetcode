# 1061. Lexicographically Smallest Equivalent String

"""
you are given two strings of the same length 's1' and 's2' and a string
'baseStr'. we say 's1[i]' and 's2[i]' are equivalent characters. equivalent
characters follow the usual rules of any equivalence relation: reflexivity,
symmetry, and transitivity. return the lexicographically smallest equivalent
string of 'baseStr' by using the equivalency information from 's1' and 's2'.
"""


class Solution(object):
    def smallestEquivalentString(self, s1, s2, baseStr):
        """
        :type s1: str
        :type s2: str
        :type baseStr: str
        :rtype: str
        """
        uf = {}

        def find(x):
            uf.setdefault(x, x)
            if x != uf[x]:
                uf[x] = find(uf[x])
            return uf[x]

        def union(x, y):
            rx, ry = find(x), find(y)
            if rx > ry:
                uf[rx] = ry
            else:
                uf[ry] = rx

        for i in range(len(s1)):
            union(s1[i], s2[i])
        ans = []
        for i in baseStr:
            ans.append(find(i))
        return "".join(ans)


if __name__ == "__main__":
    obj = Solution()
    print(obj.smallestEquivalentString(s1="parker", s2="morris", baseStr="parser"))
    print(obj.smallestEquivalentString(s1="hello", s2="world", baseStr="hold"))
    print(
        obj.smallestEquivalentString(s1="leetcode", s2="programs", baseStr="sourcecode")
    )
