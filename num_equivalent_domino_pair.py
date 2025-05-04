# 1128. Number of Equivalent Domino Pairs
from collections import Counter

"""
given a list of 'dominoes', 'dominoes[i] = [a, b]' is equivalent to
'dominoes[j] = [c, d]' if and only if either 'a == c' and 'b == d' or 'a ==
d' and 'b == c'. return the number of pairs '(i, j)' for which '0 <= i < j <
dominoes.length' and 'dominoes[i]' is equivalent to 'dominoes[j]'.
"""


class Solution(object):
    def numEquivDominoPairs(self, dominoes):
        """
        :type dominoes: List[List[int]]
        :rtype: int
        """
        return sum(
            v * (v - 1) / 2
            for v in Counter(tuple(sorted(u)) for u in dominoes).values()
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.numEquivDominoPairs(dominoes=[[1, 2], [2, 1], [3, 4], [5, 6]]))
    print(obj.numEquivDominoPairs(dominoes=[[1, 2], [1, 2], [1, 1], [1, 2], [2, 2]]))
