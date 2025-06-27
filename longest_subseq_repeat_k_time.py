# 2014. Longest Subsequence Repeated k Times
from collections import Counter
from itertools import combinations, permutations

"""
you are given a string 's' of length 'n', and an integer 'k. you are tasked
to find the longest subsequence repeated 'k' times in 's'. a subsequence is a
string that can be derived from another string by deleting some or no
characters without changing the order of the remaining characters. a
subsequence 'seq' is repeated 'k' times in a sting 's' if 'seq  k' is a
subsequence of 's' where 'seq  k' represents a string constructed by
concatenating 'seq' 'k' times. return the longest subsequence repeated 'k'
times in string 's'. if multiple subsequences are found, return the
lexicographically largest one.
"""


class Solution(object):
    def is_subseq(self, s, t):
        t = iter(t)
        return all(i in t for i in s)

    def longestSubsequenceRepeatedK(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        freq = "".join(i * (j // k) for i, j in Counter(s).items())
        combs = set()
        for i in range(len(freq) + 1):
            for j in combinations(freq, i):
                for l in permutations(j):
                    combs.add("".join(l))
        combs = sorted(combs, key=lambda x: (len(x), x), reverse=True)
        for i in combs:
            if self.is_subseq(i * k, s):
                return i


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestSubsequenceRepeatedK(s="letsleetcode", k=2))
    print(obj.longestSubsequenceRepeatedK(s="bb", k=2))
    print(obj.longestSubsequenceRepeatedK(s="ab", k=2))
