# 1400. Construct K Palindrome Strings
from collections import Counter

"""
given a string 's' and an integer 'k', return true if you can use all the
characters in 's' to constuct 'k' palindrome strings or false otherwise.
"""


class Solution(object):
    def canConstruct(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: bool
        """
        return sum(i & 1 for i in Counter(s).values()) <= k <= len(s)


if __name__ == "__main__":
    obj = Solution()
    print(obj.canConstruct("annabelle", 2))
    print(obj.canConstruct("leetcode", 3))
    print(obj.canConstruct("true", 4))
