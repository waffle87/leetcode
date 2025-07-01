# 3330. Find the Original Typed String I
from itertools import groupby

"""
alice is attmpting to type a specific string on her computer. however, she
tends to be clumsy and may press a key for too long, resulting a character
being typed multiple times. although alice tried to focus on her typing, she
is aware that she may still have done this at least once. you are given a
string 'word', which represents the final output displayed on alices screen.
return the total number of possible original strings that alice might have
intended to type.
"""


class Solution(object):
    def possibleStringCount(self, word):
        """
        :type word: str
        :rtype: int
        """
        return len(word) - len(list(groupby(word))) + 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.possibleStringCount(word="abbcccc"))
    print(obj.possibleStringCount(word="abcd"))
    print(obj.possibleStringCount(word="aaaa"))
