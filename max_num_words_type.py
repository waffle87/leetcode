# 1935. Maximum Number of Words You Can Type

"""
there is a malfunctioning keyboard where some letter keys do not work. all
other keys on the keyboard work properly. given a string of words 'text'
separated by a single space, and a string 'brokenLetters' of all distinct
letter keys that are broken, return the number of words in 'text' you can
fully type using this keyboard.
"""


class Solution(object):
    def canBeTypedWords(self, text, brokenLetters):
        """
        :type text: str
        :type brokenLetters: str
        :rtype: int
        """
        text = text.split()
        n = len(text)
        brokenLetters = list(brokenLetters)
        for i in text:
            tmp = 0
            for j in i:
                if j in brokenLetters:
                    tmp -= 1
                    break
            if tmp < 0:
                n -= 1
        return n


if __name__ == "__main__":
    obj = Solution()
    print(obj.canBeTypedWords(text="hello world", brokenLetters="ad"))
    print(obj.canBeTypedWords(text="leet code", brokenLetters="lt"))
    print(obj.canBeTypedWords(text="leet code", brokenLetters="e"))
