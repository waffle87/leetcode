# 1002. Find Common Characters
from functools import reduce
from collections import Counter

"""
given a string array 'words' return an array of all characters that show up
in all strings within the 'words' including duplicates. you may return the
answer in any order.
"""


class Solution(object):
    def commonChars(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        ans = Counter(words[0])
        for w in words:
            ans &= Counter(w)
        return list(ans.elements())
        # return list(reduce(Counter.__and__, map(Counter, words)).elements())


if __name__ == "__main__":
    obj = Solution()
    print(obj.commonChars(["bella", "label", "roller"]))
    print(obj.commonChars(["cool", "lock", "cook"]))
