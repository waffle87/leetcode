# 76. Minimum Window Substring
from collections import defaultdict

"""
given two strings 's' and 't' of length 'n' and 'm' respectively, return the
minimum window substring of 's' such that every character in 't' (including
duplicates) is included in the window. if there is no such substring, return
the empty string. the testcases will be generated such that the answer is
unique.
"""


class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        if not s or not t:
            return ""
        dict_t = defaultdict(int)
        for c in t:
            dict_t[c] += 1
        required = len(dict_t)
        l, r = 0, 0
        formed = 0
        windowCounts = defaultdict(int)
        ans = [-1, 0, 0]
        while r < len(s):
            c = s[r]
            windowCounts[c] += 1
            if c in dict_t and windowCounts[c] == dict_t[c]:
                formed += 1
            while l <= r and formed == required:
                c = s[l]
                if ans[0] == -1 or r - l + 1 < ans[0]:
                    ans[0] = r - l + 1
                    ans[1] = l
                    ans[2] = r
                windowCounts[c] -= 1
                if c in dict_t and windowCounts[c] < dict_t[c]:
                    formed -= 1
                l += 1
            r += 1
        return "" if ans[0] == -1 else s[ans[1] : ans[2] + 1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.minWindow(s="ADOBECODEBANC", t="ABC"))
    print(obj.minWindow(s="a", t="a"))
    print(obj.minWindow(s="a", t="aa"))
