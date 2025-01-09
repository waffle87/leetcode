# 2185. Counting Words With a Given Prefix

"""
you are given an array of strings 'words' and a string 'pref'. return the
number of strings in 'words' that contain 'pref' as a prefix. a prefix of a
string 's' is any leading contiguous substring of 's'.
"""


class Solution(object):
    def prefixCount(self, words, pref):
        """
        :type words: List[str]
        :type pref: str
        :rtype: int
        """
        cnt = 0
        for i in words:
            if i.startswith(pref):
                cnt += 1
        return cnt


if __name__ == "__main__":
    obj = Solution()
    print(obj.prefixCount(words=["pay", "attention", "practice", "attend"], pref="at"))
    print(obj.prefixCount(words=["leetcode", "win", "loops", "success"], pref="code"))
