# 242. Valid Anagram

"""
given two strings 's' and 't', return 'true' if 't' is an anagram of 's', and
false otherwise. an anagram is a word or phrase formed by rearranging the
letters of a different word or phrase, typically using all the original
letters exactly once.
"""


class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        sorted_s = sorted(s)
        sorted_t = sorted(t)
        return sorted_s == sorted_t


if __name__ == "__main__":
    obj = Solution()
    print(obj.isAnagram(s="anagram", t="nagaram"))
    print(obj.isAnagram(s="rat", t="car"))
