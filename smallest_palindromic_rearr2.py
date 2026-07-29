# 3518. Smallest Palindromic Rearrangement II
from collections import Counter
from math import factorial
from string import ascii_lowercase

"""
you are given a palindromic string 's' and an integer 'k'. return the k-th
lexicographically smallest palindromic permutation of 's'. if there are fewer
than 'k' distinct palindromic permutations, return an empty string.
"""


class Solution:
    def smallestPalindrome(self, s: str, k: int) -> str:
        m = len(s) >> 1
        freq = Counter(s[:m])
        perm = factorial(m)
        for v in freq.values():
            perm //= factorial(v)
        if k > perm:
            return ""
        half = ""
        for i in range(m):
            for c in ascii_lowercase:
                if not freq[c]:
                    continue
                t = perm * freq[c] // (m - i)
                if k <= t:
                    freq[c] -= 1
                    half += c
                    perm = t
                    break
                k -= t
        mid = s[m] if len(s) & 1 else ""
        return half + mid + half[::-1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.smallestPalindrome(s="abba", k=2))
    print(obj.smallestPalindrome(s="aa", k=2))
    print(obj.smallestPalindrome(s="bacab", k=1))
