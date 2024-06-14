# 1897. Redistribute Characters to Make All Strings Equal
from collections import defaultdict

"""
given an array of strings 'words' in one operation, pick two distinct indices
'i' and 'j' where 'words[i]' is a non empty string and ove any character from
words[i] to any position in 'words[j]'. return 1 if you can make every string
in 'words' equal using any number of operations, and 0 otherwise.
"""


class Solution(object):
    def makeEqual(self, words):
        """
        :type words: List[str]
        :rtype: bool
        """
        cnt = defaultdict(int)
        for w in words:
            for c in w:
                cnt[c] += 1
        n = len(words)
        for val in cnt.values():
            if val % n != 0:
                return False
        return True


if __name__ == "__main__":
    obj = Solution()
    print(obj.makeEqual(words=["abc", "aabc", "bc"]))
    print(obj.makeEqual(words=["ab", "a"]))
