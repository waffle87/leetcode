# 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence

"""
given a 'sentence' that consists of some words separated by a single space,
and a 'searchWord', check if 'searchWord' is a prefix of any word in
'sentence'. return the index of the word in 'sentence' (1-indexed) where
'searchWord' is a prefix of the word. if 'searchWord' is a prefix of more
than one word, return the index of the first word (minimum index). if there
is no such word, return -1. a prefix of a string 's' is any leading
contiguous substring of 's'.
"""


class Solution(object):
    def isPrefixOfWord(self, sentence, searchWord):
        """
        :type sentence: str
        :type searchWord: str
        :rtype: int
        """
        for i, w in enumerate(sentence.split(" "), 1):
            if w.startswith(searchWord):
                return i
        return -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.isPrefixOfWord(sentence="i love eating burger", searchWord="burg"))
    print(
        obj.isPrefixOfWord(sentence="this problem is an easy problem", searchWord="pro")
    )
    print(obj.isPrefixOfWord(sentence="i am tired", searchWord="you"))
