# 1910. Remove All Occurrences of a Substring

"""
given two strings 's' and 'part', perform the following operation on 's'
until all occurrences of the substring 'part' are removed; find the leftmost
occurrence of the substring 'part' and remove it from 's'. return 's' after
removing all occurrences of 'part'. a substring is a contiguous sequence of
characters in a string
"""


class Solution(object):
    def removeOccurrences(self, s, part):
        """
        :type s: str
        :type part: str
        :rtype: str
        """
        while part in s:
            s = s.replace(part, "", 1)
        return s


if __name__ == "__main__":
    obj = Solution()
    print(obj.removeOccurrences(s="daabcbaabcbc", part="abc"))
    print(obj.removeOccurrences(s="axxxxyyyyb", part="xy"))
