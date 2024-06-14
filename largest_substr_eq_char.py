# 1624. Largest Substring Between Two Equal Characters

"""
given a string 's', return the length of the longest substring between two
equal characters excluding the two characters if there is no such substring
return -1. a substring is a contiguous sequence of characters within a
string.
"""


class Solution(object):
    def maxLengthBetweenEqualCharacters(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans = -1
        for left in range(len(s)):
            for right in range(left + 1, len(s)):
                if s[left] == s[right]:
                    ans = max(ans, right - left - 1)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxLengthBetweenEqualCharacters("aa"))  # expect: 0
    print(obj.maxLengthBetweenEqualCharacters("abca"))  # expect: 2
    print(obj.maxLengthBetweenEqualCharacters("cbzxy"))  # expect: -1
