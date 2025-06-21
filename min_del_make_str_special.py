# 3085. Minimum Deletions to Make String K-Special
from collections import Counter

"""
you are given a string 'word' and an integer 'k'. we consider 'word' to be
k-special if '|freq(word[i]) - freq(word[j])| <= k' for all indices 'i' and
'j' in the string. here, 'freq(x)' denotes the frequency of the character 'x'
in the 'word'. and '|y|' denotes the absolute value of 'y'. return the
minimum number of characters you need to delete to make 'word' k-special.
"""


class Solution(object):
    def minimumDeletions(self, word, k):
        """
        :type word: str
        :type k: int
        :rtype: int
        """
        freq, ans = Counter(word).values(), float("inf")
        for i in freq:
            curr = 0
            for j in freq:
                curr += j if j < i else max(0, j - (i + k))
            ans = min(ans, curr)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumDeletions(word="aabcaba", k=0))
    print(obj.minimumDeletions(word="dabdcbdcdcd", k=2))
    print(obj.minimumDeletions(word="aaabaaa", k=2))
