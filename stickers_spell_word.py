# 691. Stickers to Spell Word
from collections import Counter

"""
we are given 'n' different types of 'stickers'. each sticker has a lowercase
english word on it. you would like to spell out the given 'target' by cutting
individual letters from your collection of stickers and rearranging them. you
can use each sticker more than once if you want, and you have infinite
quantities of each sticker. return the minimum number of stickers that you
need to spell out 'target'. if the task is impossible, return -1. note in all
test cases, all words were chose random from the 1000 most common us english
words, and 'target' was chosen as a concatenation of two random words
"""


class Solution(object):
    def minStickers(self, stickers, target):
        """
        :type stickers: List[str]
        :type target: str
        :rtype: int
        """
        cnt = Counter(target)
        dp = [Counter(i) & cnt for i in stickers]
        for i in range(len(dp) - 1, -1, -1):
            if any(dp[i] == dp[i] & dp[j] for j in range(len(dp)) if i != j):
                dp.pop(i)
        stickers = ["".join(i.elements()) for i in dp]

        def dp(i, t):
            if t == (1 << len(target)) - 1:
                return 0
            if i == len(stickers):
                return float("inf")
            res = dp(i + 1, t)
            tmp = t
            for l in stickers[i]:
                for j, k in enumerate(target):
                    if tmp & (1 << j):
                        continue
                    if k == l:
                        tmp |= 1 << j
                        break
            if tmp != t:
                res = min(res, 1 + dp(i, tmp))
            return res

        ans = dp(0, 0)
        return ans if ans != float("inf") else -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.minStickers(stickers=["with", "example", "science"], target="thehat"))
    print(obj.minStickers(stickers=["notice", "possible"], target="basicbasic"))
