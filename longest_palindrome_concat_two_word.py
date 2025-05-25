# 2131. Longest Palindrome by Concatenating Two Letter Words
from collections import defaultdict

"""
you are given an array of strings 'words'. each element of 'words' consists
of two lowercase english letters. create the longest possible palindrome by
selecting some elements from 'words' and concatenating them in any order.
each element can be select at most once. return the length of the longest
palindrome you can create. if it is impossible, return 0. a palindrome is a
string that reads the same forward and backward.
"""


class Solution(object):
    def longestPalindrome(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        map = defaultdict(int)
        unpaired, ans = 0, 0
        for i in words:
            if i[0] == i[1]:
                if map[i] > 0:
                    unpaired -= 1
                    map[i] -= 1
                    ans += 4
                else:
                    map[i] += 1
                    unpaired += 1
            else:
                if map[i[::-1]] > 0:
                    ans += 4
                    map[i[::-1]] -= 1
                else:
                    map[i] += 1
        if unpaired > 0:
            ans += 2
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestPalindrome(words=["lc", "cl", "gg"]))
    print(obj.longestPalindrome(words=["ab", "ty", "yt", "lc", "cl", "ab"]))
    print(obj.longestPalindrome(words=["cc", "ll", "xx"]))
