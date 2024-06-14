# 387. First Unique Character in a String

"""
given a string 's', find the first non-repeating character in it and return
its index. if it does not exist, return -1
"""


class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        m = {}
        for c in s:
            m[c] = m.get(c, 0) + 1
        for i in range(len(s)):
            if m[s[i]] == 1:
                return i
        return -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.firstUniqChar("leetcode"))
    print(obj.firstUniqChar("loveleetcode"))
    print(obj.firstUniqChar("aabb"))
