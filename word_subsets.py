# 916. Word Subsets
from collections import Counter
from functools import reduce
import operator

"""
you are given two string arrays 'words1' and 'words2'. a string 'b' is a
subset of string 'a' if every letter in 'b' occurs in 'a' including
multiplicity. a string 'a' from 'words1' is universal if for every string 'b'
in 'words2', 'b' is a subset of 'a'. return an array of all the universal
strins in 'words1'. you may return the answer in any order.
"""


class Solution(object):
    def wordSubsets(self, words1, words2):
        """
        :type words1: List[str]
        :type words2: List[str]
        :rtype: List[str]
        """
        c_b = reduce(operator.or_, (Counter(w) for w in words2))
        return [a for a in words1 if c_b & Counter(a) == c_b]


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.wordSubsets(
            words1=["amazon", "apple", "facebook", "google", "leetcode"],
            words2=["e", "o"],
        )
    )
    print(
        obj.wordSubsets(
            words1=["amazon", "apple", "facebook", "google", "leetcode"],
            words2=["l", "e"],
        )
    )
