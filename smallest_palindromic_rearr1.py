# 3517. Smallest Palindromic Rearrangement I

"""
you are given a palindromic string 's'. return the lexicographically smallest
palindromic permutation of 's'.
"""

from collections import Counter
from string import ascii_lowercase


class Solution:
    def smallestPalindrome(self, s: str) -> str:
        n = len(s)
        freq = Counter(s[: n >> 1])
        half = "".join(c * freq[c] for c in ascii_lowercase)
        mid = s[n >> 1] if n & 1 else ""
        return half + mid + half[::-1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.smallestPalindrome(s="z"))
    print(obj.smallestPalindrome(s="babab"))
    print(obj.smallestPalindrome(s="daccad"))
