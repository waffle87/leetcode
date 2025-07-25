# 3298. Count Substrings That Can Be Rearranged to Contain a String II
from collections import Counter

"""
you are given two strings 'word1' and 'word2'. a string 'x' is called valiid
if 'x' can be arranged to have 'word2' as a prefix. return the total number
of valid strings of 'word1'. note that the memory limits in this problem are
smaller than usual, so you must implement a solution with a linear runtime
complexity.
"""


class Solution(object):
    def validSubstringCount(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        cnt = Counter(word2)
        k, ans, i = len(word2), 0, 0
        for j, c in enumerate(word1):
            if cnt[c] > 0:
                k -= 1
            cnt[c] -= 1
            while k == 0 and cnt[word1[i]] < 0:
                cnt[word1[i]] += 1
                i += 1
            ans += 0 if k else i + 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.validSubstringCount(word1="bcca", word2="abc"))
    print(obj.validSubstringCount(word1="abcabc", word2="abc"))
    print(obj.validSubstringCount(word1="abcabc", word2="aaabc"))
