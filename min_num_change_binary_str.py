# 2914. Minimum Number of Changes to Make Binary String Beautiful

"""
you are given a 0-indexed binary string 's' having an even length. a string
is beautiful if it's possible to partition it into one or more substrings
such that each substring has an even length and each substring contains only
1's or only 0's. you can change any character in 's' to a 0 or 1. return the
minimum number of changes required to make the string 's' beautiful.
"""


class Solution(object):
    def minChanges(self, s):
        """
        :type s: str
        :rtype: int
        """
        n, changes = len(s), 0
        for i in range(0, n, 2):
            if s[i] != s[i + 1]:
                changes += 1
        return changes


if __name__ == "__main__":
    obj = Solution()
    print(obj.minChanges(s="1001"))
    print(obj.minChanges(s="10"))
    print(obj.minChanges(s="0000"))
