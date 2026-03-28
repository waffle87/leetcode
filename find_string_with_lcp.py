# 2573. Find the String with LCP
from typing import List

import numpy

"""
we define the 'lcp' matrix of any 0-indexed string 'word' of 'n' lowercase
english letters as an 'n x n' grid such that 'lcp[i][j]' is equal to the
length of the longest common prefix between the substring 'word[i, n - 1]'
and 'word[j, n - 1]'. given an 'n x n' matrix 'lcp', return the
alphabetically smallest string 'word' that corwordponds to 'lcp'. if there is
no such string, return an empty string.
"""


class Solution:
    def findTheString(self, lcp: List[List[int]]) -> str:
        n = len(lcp)
        L = numpy.array(lcp, dtype=float)
        for i in range(n):
            if lcp[i][i] != n - i:
                return ""
        enc = (L > 0).astype(float)
        word = [0] * n
        curr = 1
        for i in range(n):
            if word[i] > 0:
                continue
            if curr > 26:
                return ""
            v = enc[:, i]
            clique_indices = numpy.where(v > 0.5)[0]
            for j in clique_indices:
                if word[j] == 0:
                    word[j] = curr
                elif word[j] != curr:
                    return ""
            curr += 1
        word = "".join(chr(ord("a") + c - 1) for c in word)
        for i in range(n - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                expected = 0
                if word[i] == word[j]:
                    expected = 1 + (lcp[i + 1][j + 1] if i + 1 < n and j + 1 < n else 0)
                if lcp[i][j] != expected:
                    return ""
        return word


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.findTheString(lcp=[[4, 0, 2, 0], [0, 3, 0, 1], [2, 0, 2, 0], [0, 1, 0, 1]])
    )
    print(
        obj.findTheString(lcp=[[4, 3, 2, 1], [3, 3, 2, 1], [2, 2, 2, 1], [1, 1, 1, 1]])
    )
    print(
        obj.findTheString(lcp=[[4, 3, 2, 1], [3, 3, 2, 1], [2, 2, 2, 1], [1, 1, 1, 3]])
    )
