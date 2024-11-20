# 2516. Take K of Each Character From Left and Right

"""
you are given a string 's' consisting of the characters 'a', 'b', and 'c' and
a non-negative integer 'k'. each minute you may take either the leftmost
character of 's' or the rightmost character of 's'. return the minimum number
of minutes needed for you to take at least 'k' of each character, or return
-1 if it is not possible t to take 'k' of each character.
"""


class Solution(object):
    def takeCharacters(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        lim = {c: s.count(c) - k for c in "abc"}
        if any(x < 0 for x in lim.values()):
            return -1
        cnts = {c: 0 for c in "abc"}
        ans, l = 0, 0
        for r, c in enumerate(s):
            cnts[c] += 1
            while cnts[c] > lim[c]:
                cnts[s[l]] -= 1
                l += 1
            ans = max(ans, r - l + 1)
        return len(s) - ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.takeCharacters(s="aabaaaacaabc", k=2))
    print(obj.takeCharacters(s="a", k=1))
