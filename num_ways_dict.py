# 1639. Number of Ways to Form a Target String Given a Dictionary
from collections import Counter

"""
you are given a list of strings of the same length 'words' and a string
'target'. your task is to form 'target' using the given 'words'. notice that
you can use multiple characters from the same string in 'words' provided the
conditions above are met. return the number of ways to from 'target' from
'words'. since the answer may be too large, return it modulo 10^9+7
"""


class Solution(object):
    def numWays(self, words, target):
        """
        :type words: List[str]
        :type target: str
        :rtype: int
        """
        n, mod = len(target), 10**9 + 7
        ans = [1] + [0] * n
        for i in range(len(words[0])):
            cnt = Counter(w[i] for w in words)
            for j in range(n - 1, -1, -1):
                ans[j + 1] += ans[j] * cnt[target[j]] % mod
        return ans[n] % mod


if __name__ == "__main__":
    obj = Solution()
    print(obj.numWays(words=["acca", "bbbb", "caca"], target="aba"))
    print(obj.numWays(words=["abba", "baab"], target="bab"))
