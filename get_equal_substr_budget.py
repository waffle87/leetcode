# 1208. Get Equal Substrings Within Budget

"""
you are given two strings 's' and 't' of the same length and an integer
'maxCost'. you want to change 's' to 't'. changing the i'th character of 's'
to the i'th character of 't' costs '|s[i] - t[i]|'. return the maximum length
of a substring of 's' that can be changed to be the same as the corresponding
substring of 't' with a cost less than or equal to 'maxCost'. if there is no
substring from 's' that can be changed to its corresponding substring from
't', return 0
"""


class Solution(object):
    def equalSubstring(self, s, t, maxCost):
        """
        :type s: str
        :type t: str
        :type maxCost: int
        :rtype: int
        """
        i = 0
        for j in range(len(s)):
            maxCost -= abs(ord(s[j]) - ord(t[j]))
            if maxCost < 0:
                maxCost += abs(ord(s[i]) - ord(t[i]))
                i += 1
        return j - i + 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.equalSubstring(s="abcd", t="bcdf", maxCost=3))
    print(obj.equalSubstring(s="abcd", t="cdef", maxCost=3))
    print(obj.equalSubstring(s="abcd", t="acde", maxCost=0))
