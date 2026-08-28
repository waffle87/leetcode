# 3720. Lexicographically Smallest Permutation Greater Than Target

"""
you are given two strings 's' and 'target', both having legnth 'n',
consisting of lowercase english letters. return the lexicographically
smallest permutation of 's' that is strictly greater than 'target'. if no
permutation of 's' is lexicographically strictly greater than 'target',
return an empty string.
"""

from collections import Counter


class Solution:
    def lexPalindromicPermutation(self, s: str, target: str) -> str:
        n = len(s)
        cnt = Counter()
        odds = "".join(i for i in cnt if cnt[i] & 1)
        if len(odds) != n & 1:
            return ""
        for i in cnt:
            cnt[i] //= 2

        def check(left):
            nonlocal ans
            candidate = left + odds + left[::-1]
            if candidate > target and (ans == "" or candidate < ans):
                ans = candidate

        ans = ""
        for i, j in enumerate(target):
            if i >= n // 2:
                check(target[:i])
                break
            for k in sorted(cnt):
                if k > j and cnt[k]:
                    cnt[k] -= 1
                    left = target[:i] + c + "".join(x * cnt[x] for x in sorted(cnt))
                    check(left)
                    cnt[k] += 1
                    break
            cnt[j] -= 1
            if cnt[j] < 0:
                break
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.lexPalindromicPermutation(s="baba", target="abba"))
    print(obj.lexPalindromicPermutation(s="baba", target="bbaa"))
    print(obj.lexPalindromicPermutation(s="abc", target="abb"))
    print(obj.lexPalindromicPermutation(s="aac", target="abb"))
