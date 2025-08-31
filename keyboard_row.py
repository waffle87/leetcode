# 500. Keyboard Row

"""
given an array of strings 'words', return the words that can be typed using
letters of the alphabet on only one row of american keyboard like the image
below. note that the strings are case insensitive, both lowercased and
uppercased of the same letter are treated as if they are at the same row.
"""


class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        l1 = set("qwertyuiop")
        l2 = set("asdfghjkl")
        l3 = set("zxcvbnm")
        ans = []
        for i in words:
            curr = set(i.lower())
            if curr <= l1 or curr <= l2 or curr <= l3:
                ans.append(i)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.findWords(words=["Hello", "Alaska", "Dad", "Peace"]))
    print(obj.findWords(words=["omk"]))
    print(obj.findWords(words=["adsdf", "sfd"]))
