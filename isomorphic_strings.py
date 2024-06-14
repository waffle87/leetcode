# 205. Isomorphic Strings

"""
given two strings 's' and 't', determine if they are isomorphic. two strings
's' and 't' are isomorphic if the characters in 's' can be replaced to get
't'. all occurences of a character must be replaced with another character
while presevering the order of characters. no two characters may map to the
same character, but a character may map to itself.
"""


class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        s1, t1 = [0 for _ in range(256)], [0 for _ in range(256)]
        for i in range(len(s)):
            if s1[ord(s[i])] != t1[ord(t[i])]:
                return False
            s1[ord(s[i])] = i + 1
            t1[ord(t[i])] = i + 1
        return True


if __name__ == "__main__":
    obj = Solution()
    print(obj.isIsomorphic("egg", "add"))
    print(obj.isIsomorphic("foo", "bar"))
    print(obj.isIsomorphic("paper", "title"))
