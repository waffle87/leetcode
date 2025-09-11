# 1397. Find All Good Strings
from string import ascii_lowercase

"""
given the strings 's1' and 's2' of size 'n' and the string 'evil', return the
number of good strings. a good string has size 'n', it is alphabetically
greater than or equal to 's1', it is alphabetically smaller or less than
's2', and it does not contain the string 'evil' as a substring. since the
answer can be a huge number, return this modulo 10^9+7.
"""


class Solution(object):
    def prefix(self, s):
        res = [0] * len(s)
        for i in range(1, len(s)):
            k = res[i - 1]
            while k > 0 and s[k] != s[i]:
                k = res[k - 1]
            if s[k] == s[i]:
                k += 1
            res[i] = k
        return res[-1]

    def crete_connections(self, evil, t):
        k = len(evil)
        connections = [[-1] * t for _ in range(k)]
        conn = [[] for _ in range(k)]
        for i in range(k):
            for letter in self.alphabet:
                curr = self.prefix(evil + "#" + evil[0:i] + letter)
                if curr != k:
                    connections[i][ord(letter) - ord("a")] = curr
                    if curr != 0:
                        conn[i].append([ord(letter) - ord("a"), curr])
        cnt = [[0] for _ in range(k)]
        for i in range(k):
            for j in range(1, t + 1):
                cnt[i] += [cnt[i][-1] + (connections[i][j - 1] == 0)]
        return cnt, conn

    def find_lesser_good(self, n, k, string, m, evil):
        dp_bord = [[0] * k for _ in range(n)]
        dp_notd = [[0] * k for _ in range(n)]
        dp_bord[0][0] = 1
        for it_n in range(n - 1):
            for it_k in range(k):
                ord_num = ord(string[it_n + 1]) - ord("a")
                for letter, s in self.con[it_k]:
                    dp_notd[it_n + 1][s] += dp_notd[it_n][it_k]
                    if letter < ord_num:
                        dp_notd[it_n + 1][s] += dp_bord[it_n][it_k]
                dp_notd[it_n + 1][0] += self.con_numzero[it_k][-1] * dp_notd[it_n][it_k]
                dp_notd[it_n + 1][0] += (
                    self.con_numzero[it_k][ord_num] * dp_bord[it_n][it_k]
                )
                dp_notd[it_n + 1] %= m
            idx = self.prefix(evil + "#" + string[0 : it_n + 2])
            if idx != k and sum(dp_bord[it_n]) != 0:
                dp_bord[it_n + 1][idx] = 1
        return sum(dp_bord[-1]) + sum(dp_notd[-1])

    def findGoodStrings(self, n, s1, s2, evil):
        """
        :type n: int
        :type s1: str
        :type s2: str
        :type evil: str
        :rtype: int
        """
        self.alphabet = ascii_lowercase
        m, k = 10**9 + 7, len(evil)
        self.con_numzero, self.con = self.crete_connections(evil, len(self.alphabet))
        ans1 = self.find_lesser_good(n + 1, k, "#" + s2, m, evil)
        ans2 = self.find_lesser_good(n + 1, k, "#" + s1, m, evil)
        return (ans1 - ans2 + 1 - (evil in s1)) % m


if __name__ == "__main__":
    obj = Solution()
    print(obj.findGoodStrings(n=2, s1="aa", s2="da", evil="b"))
    print(obj.findGoodStrings(n=8, s1="leetcode", s2="leetgoes", evil="leet"))
    print(obj.findGoodStrings(n=2, s1="gx", s2="gz", evil="x"))
