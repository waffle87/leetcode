# 1930. Unique Length-3 Palindromic Subsequences
import string

"""
given a string 's', return the number of unique palindromes of length three
that that are a subsequence of 's'. note that even if there are multiple ways
to obtain the same subsequence, it is still only counted once. a palindrome
is a string that reads the same forwards and backwards. a subsequence of a
string is a new string generated from the original string with some
characters (can be none) deleted without changing the relative order of thhe
remaining characters. for example: "ace" is a subsequence of "abcde"
"""


class Solution(object):
    def countPalindromicSubsequence(self, s):
        ans = 0
        for c in string.ascii_lowercase:
            i, j = s.find(c), s.rfind(c)
            if i > -1:
                ans += len(set(s[i + 1 : j]))
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countPalindromicSubsequence("aabca"))  # expect: 3
    print(obj.countPalindromicSubsequence("adc"))  # expect: 0
    print(obj.countPalindromicSubsequence("bbcbaba"))  # expect: 4
