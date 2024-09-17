# 884. Uncommon Words from Two Sentences
from collections import Counter

"""
a sentence is a string of single space separated words where each word
consists of only lowercase letters. a word is uncommon if it appears exactly
once in the sentences, and does not appear in the other sentence. given two
sentences 's1' and 's2', return a list of all the uncommon words. you may
return the answer in any order
"""


class Solution(object):
    def uncommonFromSentences(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: List[str]
        """
        c = Counter((s1 + " " + s2).split())
        return [w for w in c if c[w] == 1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.uncommonFromSentences(s1="this apple is sweet", s2="this apple is sour"))
    print(obj.uncommonFromSentences(s1="apple apple", s2="banana"))
