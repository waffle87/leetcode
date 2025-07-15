# 3136. Valid Word

"""
a word is considered valid if it contains a minimum of three characters, it
contains only digits (0-9), and english letters (uppercase and lowercase), it
includes at least one vowel, and it includes one consonant. you are given a
string 'word'. return true if 'word' is valid, otherwise return false.
"""


class Solution(object):
    def isValid(self, word):
        """
        :type word: str
        :rtype: bool
        """
        n, m = len(word), 0
        if n < 3:
            return False
        vowels = (
            1
            | (1 << (ord("e") - 97))
            | (1 << (ord("o") - 97))
            | (1 << (ord("i") - 97))
            | (1 << (ord("u") - 97))
        )
        for i in word:
            if not (i.isalpha() or i.isdigit()):
                return False
            if i.isalpha():
                j = ord(i) - 97 if ord(i) >= 97 else ord(i) - 65
                m |= 1 << (vowels >> j) & 1
        return m == 3


if __name__ == "__main__":
    obj = Solution()
    print(obj.isValid(word="234Adas"))
    print(obj.isValid(word="b3"))
    print(obj.isValid(word="a3$e"))
