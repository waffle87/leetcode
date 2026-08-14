# 3090. Maximum Length Substring With Two Occurrences

"""
given a string 's', return the maximum length of a substring such that it
contains at most two occurences of each character.
"""

from collections import defaultdict


class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        ans, l = 0, 0
        freq = defaultdict(int)
        for r, c in enumerate(s):
            freq[c] += 1
            while freq[c] > 2:
                freq[s[l]] -= 1
                l += 1
            ans = max(ans, r - l + 1)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumLengthSubstring(s="bcbbbcba"))
    print(obj.maximumLengthSubstring(s="aaaa"))
