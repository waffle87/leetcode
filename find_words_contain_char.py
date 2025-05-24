# 2942. Find Words Containing Character

"""
you are given a 0-indexed array of strings 'words' and a character 'x'.
return an array of indices representing the words that contain the character
'x'. note that the returned array may be in any order.
"""


class Solution(object):
    def findWordsContaining(self, words, x):
        """
        :type words: List[str]
        :type x: str
        :rtype: List[int]
        """
        return [i for i in range(len(words)) if x in words[i]]


if __name__ == "__main__":
    obj = Solution()
    print(obj.findWordsContaining(words=["leet", "code"], x="e"))
    print(obj.findWordsContaining(words=["abc", "bcd", "aaaa", "cbc"], x="a"))
    print(obj.findWordsContaining(words=["abc", "bcd", "aaaa", "cbc"], x="z"))
