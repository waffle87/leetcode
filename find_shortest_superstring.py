# 943. Find the Shortest Superstring
from functools import lru_cache
from itertools import permutations

"""
given an array of strings 'words', return the smallest string that contains
each string in 'words' as a substring. if there multiple valid strings of the
smallest length, return any of them. you may assume that no string in 'words'
is a substring of another string in 'words'.
"""


class Solution(object):
    def shortestSuperstring(self, words):
        """
        :type words: List[str]
        :rtype: str
        """

        @lru_cache(None)
        def connect(w1, w2):
            return [
                (w2[i:], len(w2) - i)
                for i in range(len(w1) + 1)
                if w1[-i:] == w2[:i] or not i
            ][-1]

        n = len(words)
        dp = [[(float("inf"), -1)] * n for _ in range(1 << n)]
        for i in range(n):
            dp[1 << i][i] = (len(words[i]), -1)
        for mask in range(1 << n):
            bits = [j for j in range(n) if mask & 1 << j]
            for j, k in permutations(bits, 2):
                dp[mask][j] = min(
                    dp[mask][j],
                    (dp[mask ^ 1 << j][k][0] + connect(words[k], words[j])[1], k),
                )
        mask = (1 << n) - 1
        prev = min(dp[mask])
        last = dp[mask].index(prev)
        prev = prev[1]
        ans = ""
        while prev != -1:
            ans = connect(words[prev], words[last])[0] + ans
            mask -= 1 << last
            prev, last = dp[mask][prev][1], prev
        return words[last] + ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.shortestSuperstring(words=["alex", "loves", "leetcode"]))
    print(obj.shortestSuperstring(words=["catg", "ctaagt", "gcta", "ttca", "atgcatc"]))
